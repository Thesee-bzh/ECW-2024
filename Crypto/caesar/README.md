# CaesAR (medium)

## Challenge
A covert agent managed to retrieve information on site. However, the data is encrypted. The agent also retrieved what seems to be the binary executable used for encryption and a list of cryptosystems in use on the computer. IT experts managed to retrieve the source code of the binary executable, but are unable to move forward with the encrypted data. Will you do better and find the corresponding flag?

## Inputs
- Encrypted file: [FileEncrypted.txt](./FileEncrypted.txt)
- List of cryptosystems: [Terminal.txt](./Terminal.txt)
- Source code: [EncFile.c](./EncFile.c)

## Source code analysis
Here's the encryption `main`:

```c
int main(int argc, char *argv[]) {
	FILE * inf = NULL;
	FILE * ouf = NULL;
	UI8 * em = NULL;
	UI8 * lts = NULL;
	UI8 * txt = NULL;
	I64 eml, ltsl, txtl, blk;
	int f;
	inf = fopen("fk.txt", "r");
	if (inf == NULL) {goto BEnd;}
	blk = C64(128);
	ltsl = C64(32);
	txtl = C64(1);
	eml = txtl+16-(txtl%(blk/8));
	if (!(lts = PtrAlloc(ltsl))) {goto BEnd;}
	mymemset(lts, CU8(0), ltsl);
	fseek(inf, 0, SEEK_SET);		
	if (ByteSeqReadFile(inf, "lts:", C64(9), lts, ltsl) == C64(1)) {goto BEnd;}
	if (inf) {fclose(inf); inf = NULL;}
	inf = fopen("f2e.txt", "r");
	if (inf == NULL) {goto BEnd;}	
	ouf = fopen("fe.txt", "a+");
	if (ouf == NULL) {goto BEnd;}
	if (!(em = PtrAlloc(eml))) {goto BEnd;}
	mymemset(em, CU8(0), eml);
	if (!(txt = PtrAlloc(txtl))) {goto BEnd;}
	mymemset(txt, CU8(0), txtl);
	do{txt[0] = fgetc(inf);if(Encrypt(lts, ltsl, txt, txtl, em) == C64(1)){goto BEnd;}for(I64 i = C64(0); i < eml; i++){fprintf(ouf, "%02X", em[i]);}} while(txt[0] != (UI8) EOF);
	f = 0;
	goto End;
	BEnd:
	f = 1;
	goto End;
	End:
	if (inf) {fclose(inf); inf = NULL;}
	if (ouf) {fclose(ouf); ouf = NULL;}
	if (em) {PtrNullFree(em); em = NULL;}
	if (lts) {PtrNullFree(lts); lts = NULL;}
	if (txt) {PtrNullFree(txt); txt = NULL;}
	return f;
}
```

Few takeovers:
- File to encrypt is most probably `f2e.txt`; its content is read one char at a time with `fgetc(inf)`
- Another file `ft.txt` is used and contents stored in `lts` (+ size `ltsl`): not sure what this is...
- Function `Encrypt` is called as follow: `Encrypt(lts, ltsl, txt, txtl, em)`, where:
-- `txt`: one character read from the file to encrypt
-- `txtl`: size 1
-- `em`: output
- We don't have access to the code of the actual `Encrypt` function

The loop suggests that for each character to encrypt, we get a block of `eml = 16 bytes` out of the `Encrypt` function, which are written in `hexadecimal` to the output file:

```c
	do{
		txt[0] = fgetc(inf);
		if(Encrypt(lts, ltsl, txt, txtl, em) == C64(1)){
			goto BEnd;
		}
		for(I64 i = C64(0); i < eml; i++){
			fprintf(ouf, "%02X", em[i]);
		}
	} while(txt[0] != (UI8) EOF);
```

So we have a kind of substitution, where each input character is replaced by a block of 16 bytes. The title of the challenge `CaesAR`, also points at a substitution cipher.

Now, since we know nothing about the substitution, we can do a frequency analysis on the blocks of 16 bytes.

## Frequency analysis
We first read the encrypted file, `unhexlify` its contents, split it in blocks of 16 bytes, count the occurence of each and finally sort that list in order of occurence:

```python
# Read data
with open('FileEncrypted.txt') as f: data = binascii.unhexlify(f.readline().strip())

# Split in blocks and counter occurence of each block
BLK_SIZE = 16
blocks   = [data[i*BLK_SIZE:(i+1)*BLK_SIZE] for i in range(len(data)//BLK_SIZE)]
counts   = Counter(blocks)

# Get ordered list of most frequent strings
strings  = [key for key, _ in counts.most_common()]
```

Then, we need to compare this to a list of the most common letters in the english alphabet, assuming this is the language use here. We get it here from instance: https://raw.githubusercontent.com/piersy/ascii-char-frequency-english/main/ascii_freq.txt

I adjusted it a bit, so that non-printable characters are removed, as well as the numbers, which might not be correctly ordered, depending on the input file:

```python
ascii_freq = [32, 101, 116, 97, 110, 105, 111, 115, 114, 108, 100, 104, 99, 10, 117, 109, 112, 102, 103, 46, 121, 98, 119, 44, 118, 48, 107, 49, 83, 84, 67, 50, 56, 53, 65, 57, 120, 51, 73, 45, 54, 52, 55, 77, 66, 34, 39, 80, 69, 78, 70, 82, 68, 85, 113, 76, 71, 74, 72, 79, 87, 106, 122, 47, 60, 62, 75, 41, 40, 86, 89, 58, 81, 90, 88, 59, 63, 127, 94, 38, 43, 91, 93, 36, 33, 42, 61, 126, 95, 9, 123, 64, 5, 27, 30]
# Remove not printable characters
for i in [5, 9, 10, 27, 30, 127]: ascii_freq.remove(i)
# Add missing ascii chars at the end, remove numbers
ascii_freq += [i for i in range(32,127) if i not in ascii_freq]
```

Then we simply map the most frequent block with the most frequent letter (well character) in the english alphabet, and use that to decrypt the file:

```python
# Map to ordered list of ascii chars by frequency
strings = [key for key, _ in counts.most_common()]
chars   = [ascii_freq[strings.index(s)] for s in blocks]
decfile = ''.join([chr(c) for c in chars])
print(decfile)
```

Here is where we stand:
```console
$ python3 sol.py
CxM NFBR F5 CxM BTE-8 wg Yb Bb Bb CFN>TME1S1SLart VP Coe 5ehhnclos, np toe Bsim1S1SUFECMEC81S1SLBFNF(...)
```

## Quipqiup to the rescue
Then I tried to throw a random piece of text to https://quipqiup.com/, and it actually decoded something readable, meaning that we're on the right track !

Input to `quipqiup`:
```
Cosl wnn0 sl harmehg .ni.eried csto xnwwstly aid prnf stl ,amel a reader fag dsl.nker fu.o np toesr .oara.ter aid a hstthe np toesr osltnrgb 5urtoer sipnrfatsni cshh ahln we pnuid si toe lehe.tsni prnf toe Bed 2nn0 np 6eltfar.o toat oal ahreadg weei ,uwhsloedy uider toe tsthe np "Coe xnwwst"b Coat ltnrg cal dersked prnf toe earhser .oa,terl np toe Bed 2nn0y .nf,nled wg 2shwn osflehpy toe psrlt xnwwst tn we.nfe pafnul si toe cnrhd at harmey aid .ahhed wg osf "Coere aid 2a.0 Amasiy" lsi.e toeg tnhd np osl Gnurieg sitn toe Malt aid osl returiP ai adkeiture cos.o hater siknhked ahh toe xnwwstl si toe mreat ekeitl np toat Ame toat are oere rehated
```

Output from `quipqiup`:
```
Whis boo0 is largely .on.erned with jobbitsx and from its ,ages a reader may dis.over mu.h of their .hara.ter and a little of their historyk 5urther information will also be found in the sele.tion from the Ked 2oo0 of 6estmar.h that has already been ,ublishedx under the title of "Whe jobbit"k What story was derived from the earlier .ha,ters of the Ked 2oo0x .om,osed by 2ilbo himselfx the first jobbit to be.ome famous in the world at largex and .alled by him "Where and 2a.0 Againx" sin.e they told of his Yourney into the Gast and his returnF an adventure whi.h later involved all the jobbits in the great events of that Age that are here related
```

That's `Tolkien's Fellowship of the Ring` !

## Tolkien's Fellowship of the Ring
We can find the original text in `PDF` at: https://www.mrsmuellersworld.com/uploads/1/3/0/5/13054185/lord-of-the-rings-01-the-fellowship-of-the-ring_full_text.pdf

This can be converted to text using:
```console
$ pdftotext lord-of-the-rings-01-the-fellowship-of-the-ring_full_text.pdf lord.txt
```

We can use it to fix our decoding (I mean, our mapping):

```python
s1 = """Cosl wnn0 sl harmehg .ni.eried csto xnwwstly aid prnf stl ,amel a reader fag dsl.nker fu.o np toesr .oara.ter aid a hstthe np toesr osltnrgb 5urtoer sipnrfatsni cshh ahln we pnuid si toe lehe.tsni prnf toe Bed 2nn0 np 6eltfar.o toat oal ahreadg weei ,uwhsloedy uider toe tsthe np "Coe xnwwst"b Coat ltnrg cal dersked prnf toe earhser .oa,terl np toe Bed 2nn0y .nf,nled wg 2shwn osflehpy toe psrlt xnwwst tn we.nfe pafnul si toe cnrhd at harmey aid .ahhed wg osf "Coere aid 2a.0 Amasiy" lsi.e toeg tnhd np osl Gnurieg sitn toe Malt aid osl returiP ai adkeiture cos.o hater siknhked ahh toe xnwwstl si toe mreat ekeitl np toat Ame toat are oere rehated"""

s3 = """Whis book is largely concerned with Hobbits, and from its pages a reader may discover much of their character and a little of their history. Further information will also be found in the selection from the Red Book of Westmarch that has already been published, under the title of "The Hobbit". That story was derived from the earlier chapters of the Red Book, composed by Bilbo himself, the first Hobbit to become famous in the world at large, and called by him "There and Back Again," since they told of his journey into the East and his return: an adventure which later involved all the Hobbits in the great events of that Age that are here related"""

chars   = [ord(s3[s1.index(chr(c))]) if chr(c) in s1 else c for c in chars]
decfile = ''.join([chr(c) for c in chars])
print(decfile)
```

Here is where we stand:
```console
$ python3 sol.py
WHE NFRR FF WHE RTE-8 by Y. R. R. WFN>TEE1S1SLart V: Whe Fellowship of the Ring1S1SUFEWEEW81S1SLRFNF(...)
```

## Manual refining...
We have issues with capital letters, as well as numbers: we can fix them by hand, refereing to the original text:

```python
# Problem with capital letters, like in the title:
# current:  'WHE NFRR FF WHE RTE-8 by YRR WFN'
# expected: 'THE LORD OF THE RINGS by JRR TOL'
# Fix:
# current:  'WHE NFRRFTE-8byY.'
# fix:      'THE LORDFINGSbyJ.'
s = 'THE LORDFINGSbyJ.'
table = dict(zip(blocks, chars))
keys = list(table.keys())
for i in range(len(s)): table[keys[i]] = ord(s[i])

# Decode some missing numbers and capitals by hand, refereing to the original text
s1 = '349JU>X'; s2 = '-M!xCK2'
for e in table:
    c = chr(table[e])
    if c in s1: table[e] = ord(s2[s1.index(c)])

# Decode blocks with that mapping and see where we stand
chars   = [table[s] for s in blocks]
decfile = ''.join([chr(c) for c in chars])
print(decfile)
```

Here is where we stand now, much better !
```console
$ python3 sol.py
THE LORD OF THE RINGS by x. R. R. TOLKIEN1S1SLart V: The Fellowship of the Ring1S1SCONTENTS1S1SLROLO(...)
```


Now we can start looking at the flag:

```python
# Now we can find the beginning of the flag !
pos  = decfile.index('ECW')
flag = ''.join([chr(c) for c in chars[pos:pos+40]])
# ECW%N&wD&nvtB?H^sty,M^st?rM?rV^d&c\\
```

Unfortunately, it has some wrong characters, still... Fix them by hand:

```python
# Look for the missing characters in the original text
# dec: it being then the year 1341 Shire-reckoning
# txt: it being then the year V?^V Shire-reckoning
# => V=1, ?=3, ^=4
# dec: about the year V&$& of Shire-reckoning.
# tx:  about the year 1070 of Shire-reckoning.
# => &=0, $=7
s1 = 'V?^&$%\\'; s2 = '13407{}'
flag   = ''.join([s2[s1.index(c)] if c in s1 else c for c in flag])
# ECW{N0wD0nvtB3H4sty,M4st3rM3r14d0c}
```

But that doesn't flag, because of a final issue with `v`. Fix it manualy again, and that's flag !

```python
# Fix v=' and that's flag !
flag = flag.replace('v', '\'')
print(flag)
# ECW{N0wD0n'tB3H4sty,M4st3rM3r14d0c}
```

## Python code
Complete solution at [sol.py](./sol.py)

## Flag
> ECW{N0wD0n'tB3H4sty,M4st3rM3r14d0c}
