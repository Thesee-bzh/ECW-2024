# Linear Equation 2 (medium)

## Challenge
We've "optimized" our flag checker with array lookups, can you still get the flag?

## Inputs
- Binary

## Note
Solved after the competition: I had a bug in my code somewhere, leading to erroneous equations that z3 couldn' satisfy.

## Ghidra decompilation
Throwing it at Ghidra, we get this decompiled `main`: [main.c](./main.c)

We see lots of statements as follow that should all be true:

```c
    if (((uint)(byte)(&DAT_00103020)
                     [(ushort)((((*(short *)(&DAT_00113020 +
                                            (ulong)(byte)(&DAT_00113420)[uVar32] * 2) +
                                 *(short *)(&DAT_002bdc20 + (ulong)(byte)(&DAT_00113420)[uVar36] * 2
                                           )) -
                                *(short *)(&DAT_00113220 + (ulong)(byte)(&DAT_00113420)[uVar13] * 2)
                                ) - *(short *)(&DAT_001b6c20 +
                                              (ulong)(byte)(&DAT_00113420)[uVar32] * 2)) -
                              *(short *)(&DAT_0023a820 + (ulong)(byte)(&DAT_00113420)[uVar27] * 2))]
```

Those statements are based on multiple `arrays` where either `bytes` or `short int(s)` are read. We can simplify them a bit by doing following in Ghidra:
- Chose the correct data type for the arrays, to get rid of the `casts`
- Replace the `uVarxx` with the corresponding `flag index`
- Notice that the first array in each statement is almost empty, except at one single index, meaning we should satisfy the rest of the statement being equal to that index

After doing so, we get those less hostile statements, where the `byte arrays` have been prefixed with `B_` and the `short int(s)` arrays have been prefixed with `S_`:

```python
S_113020[B_113420[flag[16]]] + S_2bdc20[B_113420[flag[27]]] - S_113220[B_113420[flag[33]]] - S_1b6c20[B_113420[flag[16]]] - S_23a820[B_113420[flag[28]]] == 36535
S_123520[B_1f8f20[flag[32]]] + S_123920[B_1f8f20[flag[14]]] - S_123720[B_1f8f20[flag[12]]] - S_342620[B_1f8f20[flag[43]]] - S_353320[B_1f8f20[flag[37]]] == 16049
S_133b20[B_133f20[flag[33]]] -(S_133d20[B_133f20[flag[33]]] + S_374920[B_133f20[flag[32]]])- S_219620[B_133f20[flag[35]]] - S_363c20[B_133f20[flag[08]]] == 58168
S_144020[B_144620[flag[36]]] -(S_321620[B_144620[flag[26]]] + S_144420[B_144620[flag[22]]])- S_144220[B_144620[flag[39]]] - S_1e8320[B_144620[flag[34]]] == 45318
S_385020[B_154920[flag[22]]] + S_26b920[B_154920[flag[05]]] - S_1e8920[B_154920[flag[26]]] - S_374520[B_154920[flag[28]]] - S_154720[B_154920[flag[07]]] == 53564
S_164a20[B_165220[flag[27]]] + S_164e20[B_165220[flag[34]]] - S_165020[B_165220[flag[27]]] - S_22a520[B_165220[flag[43]]] - S_164c20[B_165220[flag[22]]] == 65169
S_1a6220[B_175920[flag[43]]] + S_175720[B_175920[flag[21]]] + S_175320[B_175920[flag[34]]] - S_175520[B_175920[flag[41]]] - S_374720[B_175920[flag[25]]] == 22584
S_342c20[B_185e20[flag[17]]] + S_185c20[B_185e20[flag[06]]] + S_185a20[B_185e20[flag[25]]] - S_2ef720[B_185e20[flag[23]]] - S_374520[B_185e20[flag[14]]] == 48796
S_195f20[B_196120[flag[23]]] + S_321a20[B_196120[flag[07]]] - S_385220[B_196120[flag[39]]] - S_2df020[B_196120[flag[32]]] - S_363c20[B_196120[flag[23]]] ==  7066
S_1a6420[B_2eff20[flag[17]]] + S_1a6a20[B_2eff20[flag[35]]] - S_1a6820[B_2eff20[flag[34]]] - S_1a6620[B_2eff20[flag[06]]] - S_1a6220[B_2eff20[flag[20]]] == 33224
S_1b7220[B_1b7420[flag[42]]] + S_1b6e20[B_1b7420[flag[41]]] - S_2ad120[B_1b7420[flag[11]]] - S_1b7020[B_1b7420[flag[42]]] - S_1b6c20[B_1b7420[flag[40]]] == 41467
S_1c7920[B_1c7b20[flag[35]]] + S_352f20[B_1c7b20[flag[29]]] + S_29ce20[B_1c7b20[flag[43]]] - S_1c7720[B_1c7b20[flag[28]]] - S_1c7520[B_1c7b20[flag[18]]] == 30174
S_332120[B_1d8220[flag[16]]] + S_2ce520[B_1d8220[flag[41]]] + S_1d7e20[B_1d8220[flag[21]]] - S_1d8020[B_1d8220[flag[28]]] - S_1d7c20[B_1d8220[flag[11]]] == 17838
S_1e8720[B_2be220[flag[39]]] + S_321a20[B_2be220[flag[15]]] + S_1e8320[B_2be220[flag[31]]] - S_1e8920[B_2be220[flag[43]]] - S_1e8520[B_2be220[flag[23]]] ==  7602
S_311120[B_1f8f20[flag[08]]] + S_310b20[B_1f8f20[flag[15]]] + S_1f8d20[B_1f8f20[flag[21]]] - S_352f20[B_1f8f20[flag[16]]] - S_1f8b20[B_1f8f20[flag[10]]] ==  3405
S_209020[B_332520[flag[35]]] + S_209420[B_332520[flag[36]]] - S_209220[B_332520[flag[18]]] - S_395f20[B_332520[flag[21]]] - S_209420[B_332520[flag[37]]] ==  3299
S_219820[B_21a020[flag[26]]] + S_219e20[B_21a020[flag[28]]] + S_219620[B_21a020[flag[26]]] - S_219c20[B_21a020[flag[28]]] - S_219a20[B_21a020[flag[28]]] ==  5468
S_22a120[B_22a720[flag[30]]] + S_22a520[B_22a720[flag[36]]] - S_22a320[B_22a720[flag[36]]] - S_385020[B_22a720[flag[30]]] - S_28c520[B_22a720[flag[06]]] == 58512
S_23ac20[B_23ae20[flag[19]]] -(S_23aa20[B_23ae20[flag[24]]] + S_2ce520[B_23ae20[flag[22]]])- S_300020[B_23ae20[flag[36]]] - S_23a820[B_23ae20[flag[36]]] == 44688
S_24b120[B_24b320[flag[25]]] + S_353520[B_24b320[flag[23]]] + S_2df220[B_24b320[flag[22]]] - S_24af20[B_24b320[flag[14]]] - S_300020[B_24b320[flag[16]]] ==  2412
S_28c320[B_25b620[flag[26]]] + S_25b420[B_25b620[flag[25]]] - S_2efb20[B_25b620[flag[11]]] - S_310d20[B_25b620[flag[09]]] - S_2ef720[B_25b620[flag[38]]] ==  6099
S_321a20[B_26bd20[flag[20]]] + S_26bb20[B_26bd20[flag[22]]] + S_26b720[B_26bd20[flag[13]]] - S_26b920[B_26bd20[flag[43]]] - S_26bb20[B_26bd20[flag[26]]] == 64742
S_395f20[B_27c220[flag[43]]] + S_27be20[B_27c220[flag[24]]] - S_27c020[B_27c220[flag[25]]] - S_2efb20[B_27c220[flag[22]]] - S_353520[B_27c220[flag[09]]] == 49469
S_2efb20[B_28c720[flag[42]]] + S_29cc20[B_28c720[flag[30]]] + S_28c320[B_28c720[flag[32]]] - S_28c520[B_28c720[flag[35]]] - S_2efd20[B_28c720[flag[42]]] == 60811
S_29c820[B_29d020[flag[27]]] + S_29ca20[B_29d020[flag[14]]] - S_29ce20[B_29d020[flag[37]]] - S_29cc20[B_29d020[flag[26]]] - S_2ce720[B_29d020[flag[30]]] == 64376
S_385620[B_2ad920[flag[14]]] -(S_2ad520[B_2ad920[flag[31]]] + S_2ad720[B_2ad920[flag[13]]])- S_2ad320[B_2ad920[flag[42]]] - S_2ad120[B_2ad920[flag[33]]] == 33510
S_2ef720[B_2be220[flag[26]]] + S_2be020[B_2be220[flag[43]]] - S_2bde20[B_2be220[flag[39]]] - S_2bdc20[B_2be220[flag[05]]] - S_2bda20[B_2be220[flag[30]]] == 64157
S_2ce320[B_2ce920[flag[31]]] + S_2ce520[B_2ce920[flag[25]]] - S_374b20[B_2ce920[flag[13]]] - S_2ce720[B_2ce920[flag[37]]] - S_374320[B_2ce920[flag[37]]] == 36020
S_2dee20[B_2df420[flag[05]]] + S_2df220[B_2df420[flag[14]]] + S_2dec20[B_2df420[flag[19]]] + S_2dea20[B_2df420[flag[21]]] - S_2df020[B_2df420[flag[25]]] ==  8361
S_2ef920[B_2eff20[flag[20]]] + S_2efd20[B_2eff20[flag[42]]] + S_2ef520[B_2eff20[flag[36]]] - S_2efb20[B_2eff20[flag[34]]] - S_2ef720[B_2eff20[flag[11]]] == 28772
S_300220[B_300820[flag[36]]] + S_300620[B_300820[flag[18]]] + S_300020[B_300820[flag[39]]] - S_300420[B_300820[flag[05]]] - S_321420[B_300820[flag[11]]] ==   624
S_310b20[B_311320[flag[09]]] + S_311120[B_311320[flag[42]]] - S_310f20[B_311320[flag[11]]] - S_310d20[B_311320[flag[32]]] - S_310920[B_311320[flag[20]]] == 55737
S_321a20[B_321c20[flag[10]]] + S_385420[B_321c20[flag[15]]] + S_321820[B_321c20[flag[05]]] + S_321420[B_321c20[flag[31]]] - S_321620[B_321c20[flag[35]]] == 18574
S_331f20[B_332520[flag[40]]] + S_332320[B_332520[flag[07]]] - S_332120[B_332520[flag[20]]] - S_331d20[B_332520[flag[35]]] - S_385020[B_332520[flag[24]]] == 46120
S_352f20[B_342e20[flag[34]]] + S_342c20[B_342e20[flag[36]]] + S_342620[B_342e20[flag[24]]] - S_342a20[B_342e20[flag[26]]] - S_342820[B_342e20[flag[32]]] ==  8825
S_353120[B_353920[flag[13]]] + S_353720[B_353920[flag[13]]] - S_353520[B_353920[flag[33]]] - S_353320[B_353920[flag[21]]] - S_352f20[B_353920[flag[25]]] == 38330
S_364020[B_364220[flag[42]]] -(S_374b20[B_364220[flag[42]]] + S_363e20[B_364220[flag[16]]])- S_363c20[B_364220[flag[32]]] - S_363a20[B_364220[flag[04]]] == 36038
S_374520[B_374d20[flag[19]]] -(S_374920[B_374d20[flag[26]]] + S_374b20[B_374d20[flag[34]]])- S_374720[B_374d20[flag[20]]] - S_374320[B_374d20[flag[32]]] == 53701
S_385220[B_385820[flag[38]]] + S_385620[B_385820[flag[20]]] - S_385420[B_385820[flag[14]]] - S_385020[B_385820[flag[11]]] - S_384e20[B_385820[flag[09]]] == 48859
S_395f20[B_396320[flag[12]]] + S_396120[B_396320[flag[22]]] + S_395d20[B_396320[flag[27]]] - S_395b20[B_396320[flag[26]]] - S_395920[B_396320[flag[43]]] == 19697
```

Also store them in file `equations.txt`.

## List those byte arrays and short int arrays
Simple `regexp` allows to list both type of arrays:

```python
pb = re.compile('B_[0-9a-f]*'); ps = re.compile('S_[0-9a-f]*')
lb = []; ls = []
for e in eqs:
    b = pb.findall(e); s = ps.findall(e)
    for x in b:
        if x not in lb: lb.append(x)
    for x in s:
        if x not in ls: ls.append(x)
```

```python
lb = ['B_113420', 'B_1f8f20', 'B_133f20', 'B_144620', 'B_154920', 'B_165220', 'B_175920', 'B_185e20', 'B_196120', 'B_2eff20', 'B_1b7420', 'B_1c7b20', 'B_1d8220', 'B_2be220', 'B_332520', 'B_21a020', 'B_22a720', 'B_23ae20', 'B_24b320', 'B_25b620', 'B_26bd20', 'B_27c220', 'B_28c720', 'B_29d020', 'B_2ad920', 'B_2ce920', 'B_2df420', 'B_300820', 'B_311320', 'B_321c20', 'B_342e20', 'B_353920', 'B_364220', 'B_374d20', 'B_385820', 'B_396320']

ls = ['S_113020', 'S_2bdc20', 'S_113220', 'S_1b6c20', 'S_23a820', 'S_123520', 'S_123920', 'S_123720', 'S_342620', 'S_353320', 'S_133b20', 'S_133d20', 'S_374920', 'S_219620', 'S_363c20', 'S_144020', 'S_321620', 'S_144420', 'S_144220', 'S_1e8320', 'S_385020', 'S_26b920', 'S_1e8920', 'S_374520', 'S_154720', 'S_164a20', 'S_164e20', 'S_165020', 'S_22a520', 'S_164c20', 'S_1a6220', 'S_175720', 'S_175320', 'S_175520', 'S_374720', 'S_342c20', 'S_185c20', 'S_185a20', 'S_2ef720', 'S_195f20', 'S_321a20', 'S_385220', 'S_2df020', 'S_1a6420', 'S_1a6a20', 'S_1a6820', 'S_1a6620', 'S_1b7220', 'S_1b6e20', 'S_2ad120', 'S_1b7020', 'S_1c7920', 'S_352f20', 'S_29ce20', 'S_1c7720', 'S_1c7520', 'S_332120', 'S_2ce520', 'S_1d7e20', 'S_1d8020', 'S_1d7c20', 'S_1e8720', 'S_1e8520', 'S_311120', 'S_310b20', 'S_1f8d20', 'S_1f8b20', 'S_209020', 'S_209420', 'S_209220', 'S_395f20', 'S_219820', 'S_219e20', 'S_219c20', 'S_219a20', 'S_22a120', 'S_22a320', 'S_28c520', 'S_23ac20', 'S_23aa20', 'S_300020', 'S_24b120', 'S_353520', 'S_2df220', 'S_24af20', 'S_28c320', 'S_25b420', 'S_2efb20', 'S_310d20', 'S_26bb20', 'S_26b720', 'S_27be20', 'S_27c020', 'S_29cc20', 'S_2efd20', 'S_29c820', 'S_29ca20', 'S_2ce720', 'S_385620', 'S_2ad520', 'S_2ad720', 'S_2ad320', 'S_2be020', 'S_2bde20', 'S_2bda20', 'S_2ce320', 'S_374b20', 'S_374320', 'S_2dee20', 'S_2dec20', 'S_2dea20', 'S_2ef920', 'S_2ef520', 'S_300220', 'S_300620', 'S_300420', 'S_321420', 'S_310f20', 'S_310920', 'S_385420', 'S_321820', 'S_331f20', 'S_332320', 'S_331d20', 'S_342a20', 'S_342820', 'S_353120', 'S_353720', 'S_364020', 'S_363e20', 'S_363a20', 'S_384e20', 'S_396120', 'S_395d20', 'S_395b20', 'S_395920']
```

## Get table addresses and sizes
The way I did it was to order the tables by their address and deduce their size by simply making the difference with the previous table. Sounds a bit odd, but that works...

```console
$ grep -e '[SB]_[0-9a-f]*' -o equations.txt | awk -F'_' '{print $2}' | sort | uniq > offsets.txt
```

```python
def get_tables():
    addrs = []; sizes = []
    count = 0
    with open('offsets.txt') as f:
        for line in f:
            addr = int(line, 16)
            addr -= 0x100000
            addrs.append(addr)
            if count != 0:
                size = addr - addrs[count-1]
                sizes.append(size)
            count += 1
        # Last one: 396320 => size = 256
        sizes.append(256)
    return addrs, sizes

addrs, sizes = get_tables()
assert len(addrs) == len(sizes)
```

## Load tables from ELF and store them dynamically in global variables
Of course, we need to read bytes for the `byte arrays` and words for the `short int(s) arrays`. We use `pwntools ELF api` to read the data.

Then we build a python expression, like for instance:
- B_113420=[19,18,17,(...),239,238,237,236]

That expression is then evaluated (well, executed in fact) by means of pythons builtin `exec()`, so that we `dynamically generate` the corresponding global variables (like the list `B_113420`).

```python
def load_tables():
    statements = []
    elf  = ELF('lineq2')
    for addr, size in zip(addrs, sizes):
        if 'B_' + str(hex(addr + 0x100000)[2:]) in lb:
            # Byte array
            data = list(elf.read(addr, size))
            s = 'B_'
        elif 'S_' + str(hex(addr + 0x100000)[2:]) in ls:
            # Short array
            data = elf.read(addr, size)
            data = [int(data[i:i+2][::-1].hex(),16) for i in range(0, len(data), 2)]
            s = 'S_'
        else:
            continue
        # Evaluate (/execute) statement: B_113420=[19,18,17,(...),239,238,237,236]
        addr = str(hex(addr + 0x100000))[2:]
        statements.append(s + str(addr) + '=' + str(data))
    return statements

statements = load_tables()
for statement in statements:
    exec(statement)
```

After that, we have data loaded in lists of ints in appropriate global variables, one for each byte or short int array.

## Finding xor and multiply operations in the data
Looking at the data we loaded, we notice that:
- `short int arrays` seem to implement some `multiply operation`
- `byte arrays` seem to implement some `xor operation`

```python
S_113020=[0,23,46,69,92,115,138,161,184,207,230,253,276,299,322,345,368,391,414,437,460,483,506,529,552,575,598,621,644,667,690,713,736,759,782,805,828,851,874,897,920,943,966,989,1012,1035,1058,1081,1104,1127,1150,1173,1196,1219,1242,1265,1288,1311,1334,1357,1380,1403,1426,1449,1472,1495,1518,1541,1564,1587,1610,1633,1656,1679,1702,1725,1748,1771,1794,1817,1840,1863,1886,1909,1932,1955,1978,2001,2024,2047,2070,2093,2116,2139,2162,2185,2208,2231,2254,2277,2300,2323,2346,2369,2392,2415,2438,2461,2484,2507,2530,2553,2576,2599,2622,2645,2668,2691,2714,2737,2760,2783,2806,2829,2852,2875,2898,2921,2944,2967,2990,3013,3036,3059,3082,3105,3128,3151,3174,3197,3220,3243,3266,3289,3312,3335,3358,3381,3404,3427,3450,3473,3496,3519,3542,3565,3588,3611,3634,3657,3680,3703,3726,3749,3772,3795,3818,3841,3864,3887,3910,3933,3956,3979,4002,4025,4048,4071,4094,4117,4140,4163,4186,4209,4232,4255,4278,4301,4324,4347,4370,4393,4416,4439,4462,4485,4508,4531,4554,4577,4600,4623,4646,4669,4692,4715,4738,4761,4784,4807,4830,4853,4876,4899,4922,4945,4968,4991,5014,5037,5060,5083,5106,5129,5152,5175,5198,5221,5244,5267,5290,5313,5336,5359,5382,5405,5428,5451,5474,5497,5520,5543,5566,5589,5612,5635,5658,5681,5704,5727,5750,5773,5796,5819,5842,5865]

B_113420=[19,18,17,16,23,22,21,20,27,26,25,24,31,30,29,28,3,2,1,0,7,6,5,4,11,10,9,8,15,14,13,12,51,50,49,48,55,54,53,52,59,58,57,56,63,62,61,60,35,34,33,32,39,38,37,36,43,42,41,40,47,46,45,44,83,82,81,80,87,86,85,84,91,90,89,88,95,94,93,92,67,66,65,64,71,70,69,68,75,74,73,72,79,78,77,76,115,114,113,112,119,118,117,116,123,122,121,120,127,126,125,124,99,98,97,96,103,102,101,100,107,106,105,104,111,110,109,108,147,146,145,144,151,150,149,148,155,154,153,152,159,158,157,156,131,130,129,128,135,134,133,132,139,138,137,136,143,142,141,140,179,178,177,176,183,182,181,180,187,186,185,184,191,190,189,188,163,162,161,160,167,166,165,164,171,170,169,168,175,174,173,172,211,210,209,208,215,214,213,212,219,218,217,216,223,222,221,220,195,194,193,192,199,198,197,196,203,202,201,200,207,206,205,204,243,242,241,240,247,246,245,244,251,250,249,248,255,254,253,252,227,226,225,224,231,230,229,228,235,234,233,232,239,238,237,236]
```

Let's check that and identify the `xor value` / `multiply value`:

```python
def get_xors(ll):
    xors = []
    for l_ in lb:
        # xoring value with index for each element in the list should reduce to a unique value
        l = eval(l_)
        assert len(set([ i ^ l[i] for i in range(len(l))])) == 1
        xors.append(str(l[0]))
    return xors

def get_mults(ll):
    mults = []
    for l_ in ll:
        # Dividing value with index for each element in the list should reduce to a unique value
        l = eval(l_)
        assert len(set([ l[i] / i for i in range(1, len(l))])) == 1
        mults.append(str(l[1]))
    return mults

xors  = get_xors(lb)
mults = get_mults(ls)
```

```python
xors = ['19', '242', '243', '70', '106', '80', '167', '166', '113', '183', '1', '236', '193', '109', '227', '94', '116', '115', '39', '36', '157', '158', '235', '62', '20', '179', '66', '6', '110', '118', '81', '230', '52', '121', '117', '5']

mults = ['23', '171', '151', '200', '247', '253', '248', '189', '161', '96', '208', '13', '30', '222', '72', '55', '197', '234', '139', '217', '228', '133', '254', '184', '10', '206', '252', '229', '125', '119', '76', '154', '3', '88', '45', '86', '83', '38', '148', '207', '26', '84', '194', '69', '18', '52', '134', '120', '33', '39', '113', '223', '196', '34', '111', '149', '105', '44', '141', '61', '123', '172', '74', '118', '179', '16', '85', '245', '127', '173', '58', '37', '150', '138', '29', '100', '89', '202', '68', '244', '31', '73', '220', '15', '93', '132', '8', '107', '43', '178', '129', '204', '7', '163', '210', '240', '236', '64', '19', '250', '140', '146', '145', '54', '131', '224', '242', '212', '48', '167', '101', '124', '25', '180', '185', '195', '232', '116', '110', '175', '94', '159', '104', '82', '219', '218', '136', '186', '9', '209', '203', '213', '233', '102', '40', '122']
```

So we indeed identified one `xor value` for each `byte array` and one `multiply value` for each `short int array`. We store them in separate lists, indexed exactly as the list of `byte array` (resp. `short int array`).

## Simplify the equations
Now we can simplify our equations / statements by making use of these `xor values` / `multiply values`, like so for instance:
- S_113020[B_113420[flag[16]]] => 23 * (flag[16]^19)

We use some `regexp` to achieve this:

```python
def simplify_eq(eqs):
    simple_eqs = []
    for e in eqs:
        start = 0
        for _ in range(5):
            try:
                start = e[start:].index('S')
                # Grab name of arrays as well as flag indexes
                # S_113020[B_113420[flag[16]]] => => (S_113020, B_113420, 16)
                res = re.search('(S_[0-9a-z]*)\[(B_[0-9a-z]*)\[flag\[([0-9][0-9])\]\]\]', e[start:])
                blk = res.group(0); arr1 = res.group(1); arr2 = res.group(2); idx = res.group(3)
                # Replace with the XOR value for byte array and the MULT value for the short array
                new = mults[ls.index(arr1)] + str('*(flag[' + str(int(idx)) + ']^' + xors[lb.index(arr2)]) + ')'
                e = e.replace(blk, new)
            except:
                break
        simple_eqs.append(e)
    return simple_eqs

simple_eqs = simplify_eq(eqs)
for e in simple_eqs: print(e)
```

And here are the set of equations we obtain:

```python
 23*(flag[16]^19)  + 171*(flag[27]^19)  - 151*(flag[33]^19)  - 200*(flag[16]^19)  - 247*(flag[28]^19)  == 36535
253*(flag[32]^242) + 248*(flag[14]^242) - 189*(flag[12]^242) - 161*(flag[43]^242) -  96*(flag[37]^242) == 16049
208*(flag[33]^243) -( 13*(flag[33]^243) +  30*(flag[32]^243))- 222*(flag[35]^243) -  72*(flag[8]^243)  == 58168
 55*(flag[36]^70)  -(197*(flag[26]^70)  + 234*(flag[22]^70)) - 139*(flag[39]^70)  - 217*(flag[34]^70)  == 45318
228*(flag[22]^106) + 133*(flag[5]^106)  - 254*(flag[26]^106) - 184*(flag[28]^106) -  10*(flag[7]^106)  == 53564
206*(flag[27]^80)  + 252*(flag[34]^80)  - 229*(flag[27]^80)  - 125*(flag[43]^80)  - 119*(flag[22]^80)  == 65169
 76*(flag[43]^167) + 154*(flag[21]^167) +   3*(flag[34]^167) -  88*(flag[41]^167) -  45*(flag[25]^167) == 22584
 86*(flag[17]^166) +  83*(flag[6]^166)  +  38*(flag[25]^166) - 148*(flag[23]^166) - 184*(flag[14]^166) == 48796
207*(flag[23]^113) +  26*(flag[7]^113)  -  84*(flag[39]^113) - 194*(flag[32]^113) -  72*(flag[23]^113) ==  7066
 69*(flag[17]^183) +  18*(flag[35]^183) -  52*(flag[34]^183) - 134*(flag[6]^183)  -  76*(flag[20]^183) == 33224
120*(flag[42]^1)   +  33*(flag[41]^1)   -  39*(flag[11]^1)   - 113*(flag[42]^1)   - 200*(flag[40]^1)   == 41467
223*(flag[35]^236) + 196*(flag[29]^236) +  34*(flag[43]^236) - 111*(flag[28]^236) - 149*(flag[18]^236) == 30174
105*(flag[16]^193) +  44*(flag[41]^193) + 141*(flag[21]^193) -  61*(flag[28]^193) - 123*(flag[11]^193) == 17838
172*(flag[39]^109) +  26*(flag[15]^109) + 217*(flag[31]^109) - 254*(flag[43]^109) -  74*(flag[23]^109) ==  7602
118*(flag[8]^242)  + 179*(flag[15]^242) +  16*(flag[21]^242) - 196*(flag[16]^242) -  85*(flag[10]^242) ==  3405
245*(flag[35]^227) + 127*(flag[36]^227) - 173*(flag[18]^227) -  58*(flag[21]^227) - 127*(flag[37]^227) ==  3299
 37*(flag[26]^94)  + 150*(flag[28]^94)  + 222*(flag[26]^94)  - 138*(flag[28]^94)  -  29*(flag[28]^94)  ==  5468
100*(flag[30]^116) + 125*(flag[36]^116) -  89*(flag[36]^116) - 228*(flag[30]^116) - 202*(flag[6]^116)  == 58512
 68*(flag[19]^115) -(244*(flag[24]^115) +  44*(flag[22]^115))-  31*(flag[36]^115) - 247*(flag[36]^115) == 44688
 73*(flag[25]^39)  + 220*(flag[23]^39)  +  15*(flag[22]^39)  -  93*(flag[14]^39)  -  31*(flag[16]^39)  ==  2412
132*(flag[26]^36)  +   8*(flag[25]^36)  - 107*(flag[11]^36)  -  43*(flag[9]^36)   - 148*(flag[38]^36)  ==  6099
 26*(flag[20]^157) + 178*(flag[22]^157) + 129*(flag[13]^157) - 133*(flag[43]^157) - 178*(flag[26]^157) == 64742
 58*(flag[43]^158) + 204*(flag[24]^158) -   7*(flag[25]^158) - 107*(flag[22]^158) - 220*(flag[9]^158)  == 49469
107*(flag[42]^235) + 163*(flag[30]^235) + 132*(flag[32]^235) - 202*(flag[35]^235) - 210*(flag[42]^235) == 60811
240*(flag[27]^62)  + 236*(flag[14]^62)  -  34*(flag[37]^62)  - 163*(flag[26]^62)  -  64*(flag[30]^62)  == 64376
 19*(flag[14]^20)  -(250*(flag[31]^20)  + 140*(flag[13]^20)) - 146*(flag[42]^20)  -  39*(flag[33]^20)  == 33510
148*(flag[26]^109) + 145*(flag[43]^109) -  54*(flag[39]^109) - 171*(flag[5]^109)  - 131*(flag[30]^109) == 64157
224*(flag[31]^179) +  44*(flag[25]^179) - 242*(flag[13]^179) -  64*(flag[37]^179) - 212*(flag[37]^179) == 36020
 48*(flag[5]^66)   +  15*(flag[14]^66)  + 167*(flag[19]^66)  + 101*(flag[21]^66)  - 194*(flag[25]^66)  ==  8361
124*(flag[20]^183) + 210*(flag[42]^183) +  25*(flag[36]^183) - 107*(flag[34]^183) - 148*(flag[11]^183) == 28772
180*(flag[36]^6)   + 185*(flag[18]^6)   +  31*(flag[39]^6)   - 195*(flag[5]^6)    - 232*(flag[11]^6)   ==   624
179*(flag[9]^110)  + 118*(flag[42]^110) - 116*(flag[11]^110) -  43*(flag[32]^110) - 110*(flag[20]^110) == 55737
 26*(flag[10]^118) + 175*(flag[15]^118) +  94*(flag[5]^118)  + 232*(flag[31]^118) - 197*(flag[35]^118) == 18574
159*(flag[40]^227) + 104*(flag[7]^227)  - 105*(flag[20]^227) -  82*(flag[35]^227) - 228*(flag[24]^227) == 46120
196*(flag[34]^81)  +  86*(flag[36]^81)  + 161*(flag[24]^81)  - 219*(flag[26]^81)  - 218*(flag[32]^81)  ==  8825
136*(flag[13]^230) + 186*(flag[13]^230) - 220*(flag[33]^230) -  96*(flag[21]^230) - 196*(flag[25]^230) == 38330
  9*(flag[42]^52)  -(242*(flag[42]^52)  + 209*(flag[16]^52)) -  72*(flag[32]^52)  - 203*(flag[4]^52)   == 36038
184*(flag[19]^121) -( 30*(flag[26]^121) + 242*(flag[34]^121))-  45*(flag[20]^121) - 212*(flag[32]^121) == 53701
 84*(flag[38]^117) +  19*(flag[20]^117) - 175*(flag[14]^117) - 228*(flag[11]^117) - 213*(flag[9]^117)  == 48859
 58*(flag[12]^5)   + 233*(flag[22]^5)   + 102*(flag[27]^5)   -  40*(flag[26]^5)   - 122*(flag[43]^5)   == 19697
```

## Z3 at the rescue
Now we have a `set of linear equations` that we can solve using `Z3`. In those equations, the maximum flag index is 43, meaning the flag length is 44, plus the trailing '}', which makes 45. Because of the `xor` operations, we'll use `Z3 BitVec` object, meaning we specify the flag to look for as `a list of 45 BitVec, each size 8`.

The constraints are obvious:
- flag begins with 'ECW{'
- flag ends with '}'
- flag bytes are printable ascii charachers
- flag bytes satisfy the set of equations above

```python
from z3 import *

SIZE = 45 # Max flag index + trailing '}'
flag = [BitVec(f"x_{i:02}", 8) for i in range(SIZE)]
s = Solver()

# Add constraints
s.add(flag[0] == ord('E'))
s.add(flag[1] == ord('C'))
s.add(flag[2] == ord('W'))
s.add(flag[3] == ord('{'))
s.add(flag[-1] == ord('}'))
s.add([ flag[i] >= 0x20 for i in range(SIZE) ])
s.add([ flag[i] <= 0x7F for i in range(SIZE) ])
s.add([ eval(e) for e in simple_eqs ])

if s.check() == sat:
    m = s.model()
    f = [m.evaluate(flag[i]) for i in range(SIZE)]
    flag = ''.join([chr(i.as_long()) for i in f])
    print(flag)
```

And it works ! We get the flag, which can be verified using the `ELF binary`:

```console
$ python3 sol.py
ECW{4rR4Ys_4r3_N0_Pr0bl3m_F0r_sUp3er_h4Xx0Rs}
$
$ ./lineq2
ECW{4rR4Ys_4r3_N0_Pr0bl3m_F0r_sUp3er_h4Xx0Rs}
Success!
```

## Flag
> ECW{4rR4Ys_4r3_N0_Pr0bl3m_F0r_sUp3er_h4Xx0Rs}
