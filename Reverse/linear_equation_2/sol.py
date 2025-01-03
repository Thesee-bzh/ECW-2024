from pwn import *
from z3 import *
import re

eqs = []
eqs.append("S_113020[B_113420[flag[16]]] + S_2bdc20[B_113420[flag[27]]] - S_113220[B_113420[flag[33]]] - S_1b6c20[B_113420[flag[16]]] - S_23a820[B_113420[flag[28]]] == 36535")
eqs.append("S_123520[B_1f8f20[flag[32]]] + S_123920[B_1f8f20[flag[14]]] - S_123720[B_1f8f20[flag[12]]] - S_342620[B_1f8f20[flag[43]]] - S_353320[B_1f8f20[flag[37]]] == 16049")
eqs.append("S_133b20[B_133f20[flag[33]]] -(S_133d20[B_133f20[flag[33]]] + S_374920[B_133f20[flag[32]]])- S_219620[B_133f20[flag[35]]] - S_363c20[B_133f20[flag[08]]] == 58168")
eqs.append("S_144020[B_144620[flag[36]]] -(S_321620[B_144620[flag[26]]] + S_144420[B_144620[flag[22]]])- S_144220[B_144620[flag[39]]] - S_1e8320[B_144620[flag[34]]] == 45318")
eqs.append("S_385020[B_154920[flag[22]]] + S_26b920[B_154920[flag[05]]] - S_1e8920[B_154920[flag[26]]] - S_374520[B_154920[flag[28]]] - S_154720[B_154920[flag[07]]] == 53564")
eqs.append("S_164a20[B_165220[flag[27]]] + S_164e20[B_165220[flag[34]]] - S_165020[B_165220[flag[27]]] - S_22a520[B_165220[flag[43]]] - S_164c20[B_165220[flag[22]]] == 65169")
eqs.append("S_1a6220[B_175920[flag[43]]] + S_175720[B_175920[flag[21]]] + S_175320[B_175920[flag[34]]] - S_175520[B_175920[flag[41]]] - S_374720[B_175920[flag[25]]] == 22584")
eqs.append("S_342c20[B_185e20[flag[17]]] + S_185c20[B_185e20[flag[06]]] + S_185a20[B_185e20[flag[25]]] - S_2ef720[B_185e20[flag[23]]] - S_374520[B_185e20[flag[14]]] == 48796")
eqs.append("S_195f20[B_196120[flag[23]]] + S_321a20[B_196120[flag[07]]] - S_385220[B_196120[flag[39]]] - S_2df020[B_196120[flag[32]]] - S_363c20[B_196120[flag[23]]] ==  7066")
eqs.append("S_1a6420[B_2eff20[flag[17]]] + S_1a6a20[B_2eff20[flag[35]]] - S_1a6820[B_2eff20[flag[34]]] - S_1a6620[B_2eff20[flag[06]]] - S_1a6220[B_2eff20[flag[20]]] == 33224")
eqs.append("S_1b7220[B_1b7420[flag[42]]] + S_1b6e20[B_1b7420[flag[41]]] - S_2ad120[B_1b7420[flag[11]]] - S_1b7020[B_1b7420[flag[42]]] - S_1b6c20[B_1b7420[flag[40]]] == 41467")
eqs.append("S_1c7920[B_1c7b20[flag[35]]] + S_352f20[B_1c7b20[flag[29]]] + S_29ce20[B_1c7b20[flag[43]]] - S_1c7720[B_1c7b20[flag[28]]] - S_1c7520[B_1c7b20[flag[18]]] == 30174")
eqs.append("S_332120[B_1d8220[flag[16]]] + S_2ce520[B_1d8220[flag[41]]] + S_1d7e20[B_1d8220[flag[21]]] - S_1d8020[B_1d8220[flag[28]]] - S_1d7c20[B_1d8220[flag[11]]] == 17838")
eqs.append("S_1e8720[B_2be220[flag[39]]] + S_321a20[B_2be220[flag[15]]] + S_1e8320[B_2be220[flag[31]]] - S_1e8920[B_2be220[flag[43]]] - S_1e8520[B_2be220[flag[23]]] ==  7602")
eqs.append("S_311120[B_1f8f20[flag[08]]] + S_310b20[B_1f8f20[flag[15]]] + S_1f8d20[B_1f8f20[flag[21]]] - S_352f20[B_1f8f20[flag[16]]] - S_1f8b20[B_1f8f20[flag[10]]] ==  3405")
eqs.append("S_209020[B_332520[flag[35]]] + S_209420[B_332520[flag[36]]] - S_209220[B_332520[flag[18]]] - S_395f20[B_332520[flag[21]]] - S_209420[B_332520[flag[37]]] ==  3299")
eqs.append("S_219820[B_21a020[flag[26]]] + S_219e20[B_21a020[flag[28]]] + S_219620[B_21a020[flag[26]]] - S_219c20[B_21a020[flag[28]]] - S_219a20[B_21a020[flag[28]]] ==  5468")
eqs.append("S_22a120[B_22a720[flag[30]]] + S_22a520[B_22a720[flag[36]]] - S_22a320[B_22a720[flag[36]]] - S_385020[B_22a720[flag[30]]] - S_28c520[B_22a720[flag[06]]] == 58512")
eqs.append("S_23ac20[B_23ae20[flag[19]]] -(S_23aa20[B_23ae20[flag[24]]] + S_2ce520[B_23ae20[flag[22]]])- S_300020[B_23ae20[flag[36]]] - S_23a820[B_23ae20[flag[36]]] == 44688")
eqs.append("S_24b120[B_24b320[flag[25]]] + S_353520[B_24b320[flag[23]]] + S_2df220[B_24b320[flag[22]]] - S_24af20[B_24b320[flag[14]]] - S_300020[B_24b320[flag[16]]] ==  2412")
eqs.append("S_28c320[B_25b620[flag[26]]] + S_25b420[B_25b620[flag[25]]] - S_2efb20[B_25b620[flag[11]]] - S_310d20[B_25b620[flag[09]]] - S_2ef720[B_25b620[flag[38]]] ==  6099")
eqs.append("S_321a20[B_26bd20[flag[20]]] + S_26bb20[B_26bd20[flag[22]]] + S_26b720[B_26bd20[flag[13]]] - S_26b920[B_26bd20[flag[43]]] - S_26bb20[B_26bd20[flag[26]]] == 64742")
eqs.append("S_395f20[B_27c220[flag[43]]] + S_27be20[B_27c220[flag[24]]] - S_27c020[B_27c220[flag[25]]] - S_2efb20[B_27c220[flag[22]]] - S_353520[B_27c220[flag[09]]] == 49469")
eqs.append("S_2efb20[B_28c720[flag[42]]] + S_29cc20[B_28c720[flag[30]]] + S_28c320[B_28c720[flag[32]]] - S_28c520[B_28c720[flag[35]]] - S_2efd20[B_28c720[flag[42]]] == 60811")
eqs.append("S_29c820[B_29d020[flag[27]]] + S_29ca20[B_29d020[flag[14]]] - S_29ce20[B_29d020[flag[37]]] - S_29cc20[B_29d020[flag[26]]] - S_2ce720[B_29d020[flag[30]]] == 64376")
eqs.append("S_385620[B_2ad920[flag[14]]] -(S_2ad520[B_2ad920[flag[31]]] + S_2ad720[B_2ad920[flag[13]]])- S_2ad320[B_2ad920[flag[42]]] - S_2ad120[B_2ad920[flag[33]]] == 33510")
eqs.append("S_2ef720[B_2be220[flag[26]]] + S_2be020[B_2be220[flag[43]]] - S_2bde20[B_2be220[flag[39]]] - S_2bdc20[B_2be220[flag[05]]] - S_2bda20[B_2be220[flag[30]]] == 64157")
eqs.append("S_2ce320[B_2ce920[flag[31]]] + S_2ce520[B_2ce920[flag[25]]] - S_374b20[B_2ce920[flag[13]]] - S_2ce720[B_2ce920[flag[37]]] - S_374320[B_2ce920[flag[37]]] == 36020")
eqs.append("S_2dee20[B_2df420[flag[05]]] + S_2df220[B_2df420[flag[14]]] + S_2dec20[B_2df420[flag[19]]] + S_2dea20[B_2df420[flag[21]]] - S_2df020[B_2df420[flag[25]]] ==  8361")
eqs.append("S_2ef920[B_2eff20[flag[20]]] + S_2efd20[B_2eff20[flag[42]]] + S_2ef520[B_2eff20[flag[36]]] - S_2efb20[B_2eff20[flag[34]]] - S_2ef720[B_2eff20[flag[11]]] == 28772")
eqs.append("S_300220[B_300820[flag[36]]] + S_300620[B_300820[flag[18]]] + S_300020[B_300820[flag[39]]] - S_300420[B_300820[flag[05]]] - S_321420[B_300820[flag[11]]] ==   624")
eqs.append("S_310b20[B_311320[flag[09]]] + S_311120[B_311320[flag[42]]] - S_310f20[B_311320[flag[11]]] - S_310d20[B_311320[flag[32]]] - S_310920[B_311320[flag[20]]] == 55737")
eqs.append("S_321a20[B_321c20[flag[10]]] + S_385420[B_321c20[flag[15]]] + S_321820[B_321c20[flag[05]]] + S_321420[B_321c20[flag[31]]] - S_321620[B_321c20[flag[35]]] == 18574")
eqs.append("S_331f20[B_332520[flag[40]]] + S_332320[B_332520[flag[07]]] - S_332120[B_332520[flag[20]]] - S_331d20[B_332520[flag[35]]] - S_385020[B_332520[flag[24]]] == 46120")
eqs.append("S_352f20[B_342e20[flag[34]]] + S_342c20[B_342e20[flag[36]]] + S_342620[B_342e20[flag[24]]] - S_342a20[B_342e20[flag[26]]] - S_342820[B_342e20[flag[32]]] ==  8825")
eqs.append("S_353120[B_353920[flag[13]]] + S_353720[B_353920[flag[13]]] - S_353520[B_353920[flag[33]]] - S_353320[B_353920[flag[21]]] - S_352f20[B_353920[flag[25]]] == 38330")
eqs.append("S_364020[B_364220[flag[42]]] -(S_374b20[B_364220[flag[42]]] + S_363e20[B_364220[flag[16]]])- S_363c20[B_364220[flag[32]]] - S_363a20[B_364220[flag[04]]] == 36038")
eqs.append("S_374520[B_374d20[flag[19]]] -(S_374920[B_374d20[flag[26]]] + S_374b20[B_374d20[flag[34]]])- S_374720[B_374d20[flag[20]]] - S_374320[B_374d20[flag[32]]] == 53701")
eqs.append("S_385220[B_385820[flag[38]]] + S_385620[B_385820[flag[20]]] - S_385420[B_385820[flag[14]]] - S_385020[B_385820[flag[11]]] - S_384e20[B_385820[flag[09]]] == 48859")
eqs.append("S_395f20[B_396320[flag[12]]] + S_396120[B_396320[flag[22]]] + S_395d20[B_396320[flag[27]]] - S_395b20[B_396320[flag[26]]] - S_395920[B_396320[flag[43]]] == 19697")

# Look for name of byte arrays and name of short arrays
pb = re.compile('B_[0-9a-f]*'); ps = re.compile('S_[0-9a-f]*')
lb = []; ls = []
for e in eqs:
    b = pb.findall(e); s = ps.findall(e)
    for x in b:
        if x not in lb: lb.append(x)
    for x in s:
        if x not in ls: ls.append(x)

# Byte arrays
# print(lb)
# ['B_113420', 'B_1f8f20', 'B_133f20', 'B_144620', 'B_154920', 'B_165220', 'B_175920', 'B_185e20', 'B_196120', 'B_2eff20', 'B_1b7420', 'B_1c7b20', 'B_1d8220', 'B_2be220', 'B_332520', 'B_21a020', 'B_22a720', 'B_23ae20', 'B_24b320', 'B_25b620', 'B_26bd20', 'B_27c220', 'B_28c720', 'B_29d020', 'B_2ad920', 'B_2ce920', 'B_2df420', 'B_300820', 'B_311320', 'B_321c20', 'B_342e20', 'B_353920', 'B_364220', 'B_374d20', 'B_385820', 'B_396320']

# Short arrays
# print(ls)
# ['S_113020', 'S_2bdc20', 'S_113220', 'S_1b6c20', 'S_23a820', 'S_123520', 'S_123920', 'S_123720', 'S_342620', 'S_353320', 'S_133b20', 'S_133d20', 'S_374920', 'S_219620', 'S_363c20', 'S_144020', 'S_321620', 'S_144420', 'S_144220', 'S_1e8320', 'S_385020', 'S_26b920', 'S_1e8920', 'S_374520', 'S_154720', 'S_164a20', 'S_164e20', 'S_165020', 'S_22a520', 'S_164c20', 'S_1a6220', 'S_175720', 'S_175320', 'S_175520', 'S_374720', 'S_342c20', 'S_185c20', 'S_185a20', 'S_2ef720', 'S_195f20', 'S_321a20', 'S_385220', 'S_2df020', 'S_1a6420', 'S_1a6a20', 'S_1a6820', 'S_1a6620', 'S_1b7220', 'S_1b6e20', 'S_2ad120', 'S_1b7020', 'S_1c7920', 'S_352f20', 'S_29ce20', 'S_1c7720', 'S_1c7520', 'S_332120', 'S_2ce520', 'S_1d7e20', 'S_1d8020', 'S_1d7c20', 'S_1e8720', 'S_1e8520', 'S_311120', 'S_310b20', 'S_1f8d20', 'S_1f8b20', 'S_209020', 'S_209420', 'S_209220', 'S_395f20', 'S_219820', 'S_219e20', 'S_219c20', 'S_219a20', 'S_22a120', 'S_22a320', 'S_28c520', 'S_23ac20', 'S_23aa20', 'S_300020', 'S_24b120', 'S_353520', 'S_2df220', 'S_24af20', 'S_28c320', 'S_25b420', 'S_2efb20', 'S_310d20', 'S_26bb20', 'S_26b720', 'S_27be20', 'S_27c020', 'S_29cc20', 'S_2efd20', 'S_29c820', 'S_29ca20', 'S_2ce720', 'S_385620', 'S_2ad520', 'S_2ad720', 'S_2ad320', 'S_2be020', 'S_2bde20', 'S_2bda20', 'S_2ce320', 'S_374b20', 'S_374320', 'S_2dee20', 'S_2dec20', 'S_2dea20', 'S_2ef920', 'S_2ef520', 'S_300220', 'S_300620', 'S_300420', 'S_321420', 'S_310f20', 'S_310920', 'S_385420', 'S_321820', 'S_331f20', 'S_332320', 'S_331d20', 'S_342a20', 'S_342820', 'S_353120', 'S_353720', 'S_364020', 'S_363e20', 'S_363a20', 'S_384e20', 'S_396120', 'S_395d20', 'S_395b20', 'S_395920']

#
# Grab table addresses and sizes (assume we ordered them correctly in order)
# $ grep -e '[SB]_[0-9a-f]*' -o equations.txt | awk -F'_' '{print $2}' | sort | uniq > offsets.txt
#
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

#
# Load tables from ELF and store them dynamically in global variables
#
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
        # Evaluate (execute to be precise) statement: B_113420=[19,18,17,(...),239,238,237,236]
        addr = str(hex(addr + 0x100000))[2:]
        statements.append(s + str(addr) + '=' + str(data))
    return statements

statements = load_tables()
for statement in statements:
    exec(statement)

#
# Looking at data, we notice the byte arrays implement a XOR, the short arrrays implement a MULT
#
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

#
# Simplify equations, for example: S_113020[B_113420[flag[16]]] => 23 * flag[16]^19
# Parse the equations to achieve the replacement
#
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
# for e in simple_eqs: print(e)

"""
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
"""

#
# Finally, z3 at the rescue to solve these simplified equations
#
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

# ECW{4rR4Ys_4r3_N0_Pr0bl3m_F0r_sUp3er_h4Xx0Rs}
