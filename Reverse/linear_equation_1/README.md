# Linear Equation 1 (easy)

## Challenge
A simple flag checker, can you guess the flag?

## Inputs
- Binary: [lineq1](./lineq1)

## Analysis
Throwing it at `Ghidra` gives us a decent decompiled version of the `main`:

```c
undefined4 FUN_001010a0(void)

{
  int iVar1;
  ssize_t sVar2;
  size_t sVar3;
  char *pcVar4;
  undefined4 uVar5;
  long in_FS_OFFSET;
  undefined local_148 [16];
  undefined local_138 [16];
  undefined local_128 [16];
  undefined local_118 [16];
  undefined local_108 [16];
  undefined local_f8 [16];
  undefined local_e8 [16];
  undefined local_d8 [16];
  undefined local_c8 [16];
  undefined local_b8 [16];
  undefined local_a8 [16];
  undefined local_98 [16];
  undefined local_88 [16];
  undefined local_78 [16];
  undefined local_68 [16];
  undefined local_58 [16];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_148 = (undefined  [16])0x0;
  local_138 = (undefined  [16])0x0;
  local_128 = (undefined  [16])0x0;
  local_118 = (undefined  [16])0x0;
  local_108 = (undefined  [16])0x0;
  local_f8 = (undefined  [16])0x0;
  local_e8 = (undefined  [16])0x0;
  local_d8 = (undefined  [16])0x0;
  local_c8 = (undefined  [16])0x0;
  local_b8 = (undefined  [16])0x0;
  local_a8 = (undefined  [16])0x0;
  local_98 = (undefined  [16])0x0;
  local_88 = (undefined  [16])0x0;
  local_78 = (undefined  [16])0x0;
  local_68 = (undefined  [16])0x0;
  local_58 = (undefined  [16])0x0;
  sVar2 = read(0,local_148,0xff);
  if (0 < sVar2) {
    strtok(local_148,"\n");
    sVar3 = strlen(local_148);
    if (((sVar3 == 0x20) && (iVar1 = strncmp(local_148,"ECW{",4), iVar1 == 0)) &&
       (local_138[15] == '}')) {
      pcVar4 = local_148 + 4;
      do {
        if (0x5e < (byte)(*pcVar4 - 0x21U)) goto LAB_0010116c;
        pcVar4 = pcVar4 + 1;
      } while (local_138 + 0xf != pcVar4);
      if ((uint)(local_138[4] ^ 0x40) * 0xec + (uint)(local_138[5] ^ 0x40) * -0x84 +
          (uint)(local_148[14] ^ 0x40) * -0x79 + (uint)(local_138[6] ^ 0x40) * -0x1a +
          (uint)(local_138[5] ^ 0x40) * -0x40 == -0xca9) {
        if ((uint)(local_148[5] ^ 0x6b) * 0xc + (uint)(local_148[6] ^ 0x6b) * 0x59 +
            (uint)(local_148[8] ^ 0x6b) * 0xdc + (uint)(local_138[1] ^ 0x6b) * -0x4a +
            (uint)(local_148[15] ^ 0x6b) * 0xa2 == 0x5ae1) {
          if ((uint)(local_148[9] ^ 0xf7) * -0x60 + (uint)(local_138[14] ^ 0xf7) * -0xc1 +
              (uint)(local_148[5] ^ 0xf7) * -0xea + (uint)(local_148[14] ^ 0xf7) * 199 +
              (uint)(local_138[11] ^ 0xf7) * 0xbf == -0x5912) {
            if ((uint)(local_148[12] ^ 0x6e) * 0x25 + (uint)(local_148[11] ^ 0x6e) * -0x80 +
                (uint)(local_148[5] ^ 0x6e) * 0x88 + (uint)(local_148[7] ^ 0x6e) * 0x6a == 0x5010) {
              if ((uint)(local_148[4] ^ 0x24) * -0x7b +
                  (uint)(local_138[12] ^ 0x24) * 0xd7 + (uint)(local_148[12] ^ 0x24) * -0xfa +
                  (uint)(local_148[11] ^ 0x24) * 0xf7 + (uint)(local_148[13] ^ 0x24) * -4 == 0x3909)
              {
                if ((uint)(local_138[0] ^ 0x54) * 0x20 + (uint)(local_138[8] ^ 0x54) * -0x86 +
                    (uint)(local_148[11] ^ 0x54) * -0x94 + (uint)(local_148[8] ^ 0x54) * -0x24 +
                    (uint)(local_138[10] ^ 0x54) * 0x85 == -0x2439) {
                  if (((((((uint)(local_138[6] ^ 1) * 0x139 + (uint)(local_138[1] ^ 1) * -0xd4 +
                           (uint)(local_148[7] ^ 1) * -5 + (uint)(local_148[13] ^ 1) * -0xa4 ==
                           0x1374) &&
                         ((uint)(local_148[15] ^ 0xa7) * -0xd8 + (uint)(local_138[3] ^ 0xa7) * 0xd2
                          + (uint)(local_148[4] ^ 0xa7) * 0x81 +
                          (uint)(local_138[11] ^ 0xa7) * -0xde == -0x2733)) &&
                        (((uint)(local_148[11] ^ 0x27) * 0xb9 +
                          (uint)(local_138[10] ^ 0x27) * -0xb6 + (uint)(local_138[5] ^ 0x27) * -0x36
                          + (uint)(local_138[5] ^ 0x27) * 0x4f + (uint)(local_148[10] ^ 0x27) * 0x8e
                          == 0x3746 &&
                         (((uint)(local_138[6] ^ 0x8d) * 0xc6 +
                           (uint)(local_138[5] ^ 0x8d) * -0x15 + (uint)(local_148[11] ^ 0x8d) * 0x26
                           + (uint)(local_148[11] ^ 0x8d) * 0x71 +
                           (uint)(local_138[8] ^ 0x8d) * -0xb6 == 0x578c &&
                          ((uint)(local_138[2] ^ 200) * -0x3a +
                           (uint)(local_148[13] ^ 200) * -0x5b + (uint)(local_138[11] ^ 200) * -0xca
                           + (uint)(local_138[4] ^ 200) * 0x16e == 0x35e4)))))) &&
                       ((uint)(local_138[11] ^ 0x6d) * 0xcc + (uint)(local_148[13] ^ 0x6d) * -0x7c +
                        (uint)(local_148[5] ^ 0x6d) * -0x55 +
                        (uint)(local_138[5] ^ 0x6d) + (uint)(local_138[5] ^ 0x6d) * 2 +
                        (uint)(local_138[8] ^ 0x6d) * 0xf6 == 0x3a3a)) &&
                      ((((((uint)(local_138[13] ^ 0x66) * -0xe7 +
                           (uint)(local_148[6] ^ 0x66) * 0xc4 + (uint)(local_138[0] ^ 0x66) * 0xf3 +
                           (uint)(local_138[10] ^ 0x66) * -0x4b +
                           (uint)(local_138[4] ^ 0x66) * -0x5d == -0x4997 &&
                          ((uint)(local_138[6] ^ 0x1f) * 0xcc + (uint)(local_138[5] ^ 0x1f) * -0xfd
                           + (uint)(local_138[9] ^ 0x1f) * -0x6a +
                           (uint)(local_148[14] ^ 0x1f) * -0x3d +
                           (uint)(local_148[13] ^ 0x1f) * 0x7d == 0x517)) &&
                         ((uint)(local_148[15] ^ 0x2b) * -0xcf + (uint)(local_148[13] ^ 0x2b) * 0x93
                          + (uint)(local_138[1] ^ 0x2b) * 0x8f + (uint)(local_148[9] ^ 0x2b) * 0xb2
                          + (uint)(local_138[14] ^ 0x2b) * 0x1e == 0x45fd)) &&
                        (((uint)(local_138[8] ^ 0xd) * -0x5a +
                          (uint)(local_138[14] ^ 0xd) * -100 + (uint)(local_138[3] ^ 0xd) * -0x24 +
                          (uint)(local_138[5] ^ 0xd) * -0x6a == -0x7f12 &&
                         ((uint)(local_138[5] ^ 0x1e) * 0xe +
                          (uint)(local_148[9] ^ 0x1e) * 0x24 + (uint)(local_148[12] ^ 0x1e) * 0xf6 +
                          (uint)(local_138[10] ^ 0x1e) * -0x35 + (uint)(local_138[7] ^ 0x1e) * -0x1f
                          == 0x2b33)))) &&
                       (((uint)(local_148[7] ^ 0x1f) * 0x8a +
                         (uint)(local_148[8] ^ 0x1f) * 0x71 + (uint)(local_138[13] ^ 0x1f) * 0x7c +
                         (uint)(local_138[1] ^ 0x1f) * 6 + (uint)(local_148[10] ^ 0x1f) * 0x95 ==
                         0x654d &&
                        (((uint)(local_148[6] ^ 0x23) * -0x49 +
                          (uint)(local_138[11] ^ 0x23) * -0x32 + (uint)(local_138[8] ^ 0x23) * -0x1a
                          + (uint)(local_138[3] ^ 0x23) * 0xe8 + (uint)(local_148[4] ^ 0x23) * -0xa6
                          == -0x17e1 &&
                         ((uint)(local_138[12] ^ 0x87) * -0x46 +
                          (uint)(local_138[2] ^ 0x87) + (uint)(local_138[2] ^ 0x87) * 8 +
                          (uint)(local_138[14] ^ 0x87) * 0xd4 + (uint)(local_138[7] ^ 0x87) * -0x7c
                          + (uint)(local_138[8] ^ 0x87) * 0x1e == 0x6dce)))))))) &&
                     ((((uint)(local_138[8] ^ 0xe9) * 0x20 + (uint)(local_138[1] ^ 0xe9) * -99 +
                        (uint)(local_138[10] ^ 0xe9) * -0xae + (uint)(local_148[9] ^ 0xe9) * -0x92 +
                        (uint)(local_148[8] ^ 0xe9) * 0xd7 == -0x5c96 &&
                       (((((uint)(local_138[7] ^ 0x3e) * -0xd8 +
                           (uint)(local_138[10] ^ 0x3e) * 10 + (uint)(local_138[3] ^ 0x3e) * -9 +
                           (uint)(local_148[11] ^ 0x3e) * -0x10 + (uint)(local_148[8] ^ 0x3e) * 0xdc
                           == -0x6ae &&
                          ((uint)(local_138[9] ^ 0xdf) * 0x5f +
                           (uint)(local_138[11] ^ 0xdf) * 0x43 + (uint)(local_148[4] ^ 0xdf) * -0x94
                           + (uint)(local_148[11] ^ 0xdf) * 0x50 == 0x5e9c)) &&
                         ((uint)(local_138[3] ^ 0x6a) * 0x45 +
                          (uint)(local_148[4] ^ 0x6a) * 0x52 +
                          (uint)(local_138[1] ^ 0x6a) * -0xa9 + (uint)(local_138[7] ^ 0x6a) * 0x6e +
                          (uint)(local_148[14] ^ 0x6a) * -0xdb == -0x280d)) &&
                        (((uint)(local_138[11] ^ 0x1b) * 0xd7 + (uint)(local_138[13] ^ 0x1b) * -0x98
                          + (uint)(local_148[11] ^ 0x1b) * 0x20 + (uint)(local_138[7] ^ 0x1b) * 0x4c
                          + (uint)(local_148[4] ^ 0x1b) * 0x6e == 0x525e &&
                         ((uint)(local_148[4] ^ 1) * -0x11 + (uint)(local_138[7] ^ 1) * -0x9e +
                          (uint)(local_148[7] ^ 1) * -0x87 + (uint)(local_138[1] ^ 1) * -0xcd +
                          (uint)(local_138[2] ^ 1) * 0x93 == -0x5132)))))) &&
                      ((uint)(local_148[5] ^ 0xd) * 0x2f +
                       (uint)(local_148[9] ^ 0xd) * 0x51 +
                       (uint)(local_138[0] ^ 0xd) * -0xf1 + (uint)(local_148[8] ^ 0xd) * 0xff +
                       (uint)(local_138[5] ^ 0xd) * -0x12 == -0xf85)))) {
                    puts("Success!");
                    uVar5 = 0;
                    goto LAB_00101171;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_0010116c:
  uVar5 = 1;
LAB_00101171:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}
```

So we have a long list of linear equations on the input bytes, that we need to revert.

## Z3 to the rescue
The `SMT solver Z3` comes to the rescue. We simply feed it with all the constraints as follow:

```python
from z3 import *

v1 = [BitVec("v1_%i" % i, 16) for i in range(16)]
v2 = [BitVec("v2_%i" % i, 16) for i in range(16)]

# Create the SMT solver instance and feed it with constraints
s = Solver()
s.add(v1[0] == ord('E'))
s.add(v1[1] == ord('C'))
s.add(v1[2] == ord('W'))
s.add(v1[3] == ord('{'))
s.add(v2[15] == ord('}'))
s.add( [v1[i] <= 128 for i in range(16)] )
s.add( [v2[i] <= 128 for i in range(16)] )
s.add((v2[4] ^ 0x40) * 0xec + (v2[5] ^ 0x40) * (-0x84) + (v1[14] ^ 0x40) * (-0x79) + (v2[6] ^ 0x40) * (-0x1a) + (v2[5] ^ 0x40) * (-0x40) == -0xca9)
s.add((v1[5] ^ 0x6b) * 0xc + (v1[6] ^ 0x6b) * 0x59 + (v1[8] ^ 0x6b) * 0xdc + (v2[1] ^ 0x6b) * (-0x4a) + (v1[15] ^  0x6b) * 0xa2 == 0x5ae1)
s.add((v1[9] ^ 0xf7) * (-0x60) + (v2[14] ^ 0xf7) * (-0xc1) + (v1[5] ^ 0xf7) * (-0xea) + (v1[14] ^ 0xf7) * 199 + (v2[11] ^ 0xf7) * 0xbf == -0x5912)
s.add((v1[12] ^ 0x6e) * 0x25 + (v1[11] ^ 0x6e) * (-0x80) + (v1[5] ^ 0x6e) * 0x88 + (v1[7] ^ 0x6e) * 0x6a == 0x5010)
s.add((v1[4] ^ 0x24) * (-0x7b) + (v2[12] ^ 0x24) * 0xd7 + (v1[12] ^ 0x24) * (-0xfa) + (v1[11] ^ 0x24) * 0xf7 + (v1[13] ^ 0x24) * (-4) == 0x3909)
s.add((v2[0] ^ 0x54) * 0x20 + (v2[8] ^ 0x54) * (-0x86) + (v1[11] ^ 0x54) * (-0x94) + (v1[8] ^ 0x54) * (-0x24) + (v2[10] ^ 0x54) * 0x85 == -0x2439)
s.add((v2[6] ^ 1) * 0x139 + (v2[1] ^ 1) * (-0xd4) + (v1[7] ^ 1) * (-5) + (v1[13] ^ 1) * (-0xa4) == 0x1374)
s.add((v1[15] ^ 0xa7) * (-0xd8) + (v2[3] ^ 0xa7) * 0xd2 + (v1[4] ^ 0xa7) * 0x81 + (v2[11] ^ 0xa7) * (-0xde) == -0x2733)
s.add((v1[11] ^ 0x27) * 0xb9 + (v2[10] ^ 0x27) * (-0xb6) + (v2[5] ^ 0x27) * (-0x36) + (v2[5] ^ 0x27) * 0x4f + (v1[10] ^ 0x27) * 0x8e == 0x3746)
s.add((v2[6] ^ 0x8d) * 0xc6 + (v2[5] ^ 0x8d) * (-0x15) + (v1[11] ^ 0x8d) * 0x26 + (v1[11] ^ 0x8d) * 0x71 + (v2[8] ^ 0x8d) * (-0xb6) == 0x578c)
s.add((v2[2] ^ 200) * (-0x3a) + (v1[13] ^ 200) * (-0x5b) + (v2[11] ^ 200) * (-0xca) + (v2[4] ^ 200) * 0x16e == 0x35e4)
s.add((v2[11] ^ 0x6d) * 0xcc + (v1[13] ^ 0x6d) * (-0x7c) + (v1[5] ^ 0x6d) * (-0x55) + (v2[5] ^ 0x6d) + (v2[5] ^ 0x6d) * 2 + (v2[8] ^ 0x6d) * 0xf6 == 0x3a3a)
s.add((v2[13] ^ 0x66) * (-0xe7) + (v1[6] ^ 0x66) * 0xc4 + (v2[0] ^ 0x66) * 0xf3 + (v2[10] ^ 0x66) * (-0x4b) + (v2[4] ^ 0x66) * (-0x5d) == -0x4997)
s.add((v2[6] ^ 0x1f) * 0xcc + (v2[5] ^ 0x1f) * (-0xfd) + (v2[9] ^ 0x1f) * (-0x6a) + (v1[14] ^ 0x1f) * (-0x3d) + (v1[13] ^ 0x1f) * 0x7d == 0x517)
s.add((v1[15] ^ 0x2b) * (-0xcf) + (v1[13] ^ 0x2b) * 0x93 + (v2[1] ^ 0x2b) * 0x8f + (v1[9] ^ 0x2b) * 0xb2 + (v2[14] ^ 0x2b) * 0x1e == 0x45fd)
s.add((v2[8] ^ 0xd) * (-0x5a) + (v2[14] ^ 0xd) * (-100) + (v2[3] ^ 0xd) * (-0x24) + (v2[5] ^ 0xd) * (-0x6a) == -0x7f12)
s.add((v2[5] ^ 0x1e) * 0xe + (v1[9] ^ 0x1e) * 0x24 + (v1[12] ^ 0x1e) * 0xf6 + (v2[10] ^ 0x1e) * (-0x35) + (v2[7] ^ 0x1e) * (-0x1f) == 0x2b33)
s.add((v1[7] ^ 0x1f) * 0x8a + (v1[8] ^ 0x1f) * 0x71 + (v2[13] ^ 0x1f) * 0x7c + (v2[1] ^ 0x1f) * 6 + (v1[10] ^ 0x1f) * 0x95 == 0x654d)
s.add((v1[6] ^ 0x23) * (-0x49) + (v2[11] ^ 0x23) * (-0x32) + (v2[8] ^ 0x23) * (-0x1a) + (v2[3] ^ 0x23) * 0xe8 + (v1[4] ^ 0x23) * (-0xa6) == -0x17e1)
s.add((v2[12] ^ 0x87) * (-0x46) + (v2[2] ^ 0x87) + (v2[2] ^ 0x87) * 8 + (v2[14] ^ 0x87) * 0xd4 + (v2[7] ^ 0x87) * (-0x7c) + (v2[8] ^ 0x87) * 0x1e == 0x6dce)
s.add((v2[8] ^ 0xe9) * 0x20 + (v2[1] ^ 0xe9) * (-99) + (v2[10] ^ 0xe9) * (-0xae) + (v1[9] ^ 0xe9) * (-0x92) + (v1[8] ^ 0xe9) * 0xd7 == -0x5c96)
s.add((v2[7] ^ 0x3e) * (-0xd8) + (v2[10] ^ 0x3e) * 10 + (v2[3] ^ 0x3e) * (-9) + (v1[11] ^ 0x3e) * (-0x10) + (v1[8] ^ 0x3e) * 0xdc == -0x6ae)
s.add((v2[9] ^ 0xdf) * 0x5f + (v2[11] ^ 0xdf) * 0x43 + (v1[4] ^ 0xdf) * (-0x94) + (v1[11] ^ 0xdf) * 0x50 == 0x5e9c)
s.add((v2[3] ^ 0x6a) * 0x45 + (v1[4] ^ 0x6a) * 0x52 + (v2[1] ^ 0x6a) * (-0xa9) + (v2[7] ^ 0x6a) * 0x6e + (v1[14] ^ 0x6a) * (-0xdb) == -0x280d)
s.add((v2[11] ^ 0x1b) * 0xd7 + (v2[13] ^ 0x1b) * (-0x98) + (v1[11] ^ 0x1b) * 0x20 + (v2[7] ^ 0x1b) * 0x4c + (v1[4] ^ 0x1b) * 0x6e == 0x525e)
s.add((v1[4] ^ 1) * (-0x11) + (v2[7] ^ 1) * (-0x9e) + (v1[7] ^ 1) * (-0x87) + (v2[1] ^ 1) * (-0xcd) + (v2[2] ^ 1) * 0x93 == -0x5132)
s.add((v1[5] ^ 0xd) * 0x2f + (v1[9] ^ 0xd) * 0x51 + (v2[0] ^ 0xd) * (-0xf1) + (v1[8] ^ 0xd) * 0xff + (v2[5] ^ 0xd) * (-0x12) == -0xf85)

# Solve the problem
assert s.check() == sat

# We have a solution !
print('solved')
m = s.model()
f1 = [m.evaluate(v1[i]) for i in range(16)]
f2 = [m.evaluate(v2[i]) for i in range(16)]
flag = ''.join([chr(i.as_long()%128) for i in f1]) + ''.join([chr(i.as_long()%128) for i in f2])
print(flag)
```

The `SMT solver` finds a solution, and we get the flag, which we can verify using the binary:

```console
$ python3 sol.py
solved
ECW{l1N34r_C0Nstr41n15_4r3_345y}
$
$ ./lineq1
ECW{l1N34r_C0Nstr41n15_4r3_345y}
Success!
```

## Python code
Complete solution in [sol.py](./sol.py)

## Flag
> ECW{l1N34r_C0Nstr41n15_4r3_345y}
