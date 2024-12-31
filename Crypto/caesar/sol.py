from collections import Counter
import binascii
import string

# English ascii frequencies from:
# > https://raw.githubusercontent.com/piersy/ascii-char-frequency-english/main/ascii_freq.txt
ascii_freq = [32, 101, 116, 97, 110, 105, 111, 115, 114, 108, 100, 104, 99, 10, 117, 109, 112, 102, 103, 46, 121, 98, 119, 44, 118, 48, 107, 49, 83, 84, 67, 50, 56, 53, 65, 57, 120, 51, 73, 45, 54, 52, 55, 77, 66, 34, 39, 80, 69, 78, 70, 82, 68, 85, 113, 76, 71, 74, 72, 79, 87, 106, 122, 47, 60, 62, 75, 41, 40, 86, 89, 58, 81, 90, 88, 59, 63, 127, 94, 38, 43, 91, 93, 36, 33, 42, 61, 126, 95, 9, 123, 64, 5, 27, 30]
# Remove not printable characters
for i in [5, 9, 10, 27, 30, 127]: ascii_freq.remove(i)
# Add missing ascii chars at the end, remove numbers
ascii_freq += [i for i in range(32,127) if i not in ascii_freq]

# Read data
with open('FileEncrypted.txt') as f: data = binascii.unhexlify(f.readline().strip())

# Split in blocks and counter occurence of each block
BLK_SIZE = 16
blocks   = [data[i*BLK_SIZE:(i+1)*BLK_SIZE] for i in range(len(data)//BLK_SIZE)]
counts   = Counter(blocks)

# Get ordered list of most frequent strings, and map it to ordered list of ascii chars by frequency
strings = [key for key, _ in counts.most_common()]
chars   = [ascii_freq[strings.index(s)] for s in blocks]
decfile = ''.join([chr(c) for c in chars])

# Using https://quipqiup.com/ on some random piece of text in the decoded output
# We're on the right track !
s1 = """Cosl wnn0 sl harmehg .ni.eried csto xnwwstly aid prnf stl ,amel a reader fag dsl.nker fu.o np toesr .oara.ter aid a hstthe np toesr osltnrgb 5urtoer sipnrfatsni cshh ahln we pnuid si toe lehe.tsni prnf toe Bed 2nn0 np 6eltfar.o toat oal ahreadg weei ,uwhsloedy uider toe tsthe np "Coe xnwwst"b Coat ltnrg cal dersked prnf toe earhser .oa,terl np toe Bed 2nn0y .nf,nled wg 2shwn osflehpy toe psrlt xnwwst tn we.nfe pafnul si toe cnrhd at harmey aid .ahhed wg osf "Coere aid 2a.0 Amasiy" lsi.e toeg tnhd np osl Gnurieg sitn toe Malt aid osl returiP ai adkeiture cos.o hater siknhked ahh toe xnwwstl si toe mreat ekeitl np toat Ame toat are oere rehated"""
s2 = """Whis boo0 is largely .on.erned with jobbitsx and from its ,ages a reader may dis.over mu.h of their .hara.ter and a little of their historyk 5urther information will also be found in the sele.tion from the Ked 2oo0 of 6estmar.h that has already been ,ublishedx under the title of "Whe jobbit"k What story was derived from the earlier .ha,ters of the Ked 2oo0x .om,osed by 2ilbo himselfx the first jobbit to be.ome famous in the world at largex and .alled by him "Where and 2a.0 Againx" sin.e they told of his Yourney into the Gast and his returnF an adventure whi.h later involved all the jobbits in the great events of that Age that are here related"""

# That's Tolkien's Fellowship of the Ring !
# Text version available here:
# => https://www.mrsmuellersworld.com/uploads/1/3/0/5/13054185/lord-of-the-rings-01-the-fellowship-of-the-ring_full_text.pdf
# => Use it to fix the decoding
s3 = """Whis book is largely concerned with Hobbits, and from its pages a reader may discover much of their character and a little of their history. Further information will also be found in the selection from the Red Book of Westmarch that has already been published, under the title of "The Hobbit". That story was derived from the earlier chapters of the Red Book, composed by Bilbo himself, the first Hobbit to become famous in the world at large, and called by him "There and Back Again," since they told of his journey into the East and his return: an adventure which later involved all the Hobbits in the great events of that Age that are here related"""
chars   = [ord(s3[s1.index(chr(c))]) if chr(c) in s1 else c for c in chars]
decfile = ''.join([chr(c) for c in chars])

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

# Now we can find the beginning of the flag !
pos  = decfile.index('ECW')
flag = ''.join([chr(c) for c in chars[pos:pos+40]])
# ECW%N&wD&nvtB?H^sty,M^st?rM?rV^d&c\\

# Unfortunately, it has some wrong characters, still...
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

# Fix v=' and that's flag !
flag = flag.replace('v', '\'')
print(flag)
# ECW{N0wD0n'tB3H4sty,M4st3rM3r14d0c}


