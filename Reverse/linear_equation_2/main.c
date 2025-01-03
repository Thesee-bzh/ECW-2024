har *pcVar1;
  ssize_t sVar2;
  byte *pbVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  undefined8 uVar7;
  char cVar8;
  long lVar9;
  ulong uVar10;
  char *pcVar11;
  ulong uVar12;
  ulong uVar13;
  ulong uVar14;
  ulong uVar15;
  ulong uVar16;
  ulong uVar17;
  ulong uVar18;
  ulong uVar19;
  ulong uVar20;
  ulong uVar21;
  undefined8 *puVar22;
  ulong uVar23;
  ulong uVar24;
  ulong uVar25;
  ulong uVar26;
  ulong uVar27;
  ulong uVar28;
  ulong uVar29;
  ulong uVar30;
  ulong uVar31;
  ulong uVar32;
  ulong uVar33;
  ulong uVar34;
  ulong uVar35;
  ulong uVar36;
  ulong uVar37;
  ulong uVar38;
  ulong uVar39;
  ulong uVar40;
  ulong uVar41;
  long in_FS_OFFSET;
  byte bVar42;
  uint local_95c;
  undefined8 local_958 [22];
  undefined4 local_8a4;
  undefined4 local_14d;
  undefined local_149;
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
  
  bVar42 = 0;
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
    local_95c = 0;
    puVar22 = local_958;
    for (lVar9 = 0x100; lVar9 != 0; lVar9 = lVar9 + -1) {
      *puVar22 = 0;
      puVar22 = puVar22 + (ulong)bVar42 * -2 + 1;
    }
    lVar9 = 0;
    local_8a4 = 1;
    do {
      if (local_148[lVar9] == '\0') {
        local_95c = *(uint *)((long)local_958 + (long)(int)lVar9 * 4);
        break;
      }
      lVar9 = lVar9 + 1;
    } while (lVar9 != 0x100);
    local_149 = 0;
    local_14d = 0x7b574345;
    if (local_148[0] != '\0') {
      pcVar11 = local_148;
      cVar8 = local_148[0];
      do {
        pcVar1 = pcVar11 + ((long)&local_14d - (long)local_148);
        pcVar11 = pcVar11 + 1;
        local_95c = *pcVar1 == cVar8 & local_95c;
        cVar8 = *pcVar11;
        if (local_148 + 4 <= pcVar11) break;
      } while (cVar8 != '\0');
    }
    pbVar3 = local_148 + 4;
    local_95c = local_128[12] == '}' & local_95c;
    do {
      bVar42 = *pbVar3;
      pbVar3 = pbVar3 + 1;
      local_95c = bVar42 - 0x20 < 0x60 & local_95c;
    } while (pbVar3 != local_128 + 0xc);
    uVar21 = (ulong)local_138[6];
    uVar19 = (ulong)local_148[14];
    uVar36 = (ulong)local_138[11];
    uVar37 = (ulong)local_138[4];
    uVar12 = (ulong)local_138[10];
    uVar10 = (ulong)local_128[11];
    uVar41 = (ulong)local_148[11];
    uVar38 = (ulong)local_148[9];
    uVar20 = (ulong)local_128[0];
    uVar39 = (ulong)local_128[2];
    uVar23 = (ulong)local_138[3];
    uVar32 = (ulong)local_138[0];
    uVar24 = (ulong)local_128[10];
    uVar13 = (ulong)local_128[1];
    uVar28 = (ulong)local_148[13];
    uVar33 = (ulong)local_138[5];
    uVar25 = (ulong)local_138[9];
    uVar4 = (ulong)local_128[4];
    uVar40 = (ulong)local_138[8];
    uVar5 = (ulong)local_148[7];
    uVar34 = (ulong)local_128[3];
    uVar14 = (ulong)local_148[15];
    uVar15 = (ulong)local_148[5];
    uVar16 = (ulong)local_138[15];
    uVar6 = (ulong)local_138[2];
    uVar17 = (ulong)local_128[7];
    uVar30 = (ulong)local_128[5];
    uVar26 = (ulong)local_138[14];
    uVar29 = (ulong)local_138[7];
    uVar18 = (ulong)local_148[6];
    uVar27 = (ulong)local_138[12];
    uVar31 = (ulong)(byte)(&DAT_0021a020)[uVar27];
    uVar35 = (ulong)local_128[9];
    if (((uint)(byte)(&DAT_00103020)
                     [(ushort)((((*(short *)(&DAT_00113020 +
                                            (ulong)(byte)(&DAT_00113420)[uVar32] * 2) +
                                 *(short *)(&DAT_002bdc20 + (ulong)(byte)(&DAT_00113420)[uVar36] * 2
                                           )) -
                                *(short *)(&DAT_00113220 + (ulong)(byte)(&DAT_00113420)[uVar13] * 2)
                                ) - *(short *)(&DAT_001b6c20 +
                                              (ulong)(byte)(&DAT_00113420)[uVar32] * 2)) -
                              *(short *)(&DAT_0023a820 + (ulong)(byte)(&DAT_00113420)[uVar27] * 2))]
        & (uint)(byte)(&DAT_00113520)
                      [(ushort)((((*(short *)(&DAT_00123520 +
                                             (ulong)(byte)(&DAT_001f8f20)[uVar20] * 2) +
                                  *(short *)(&DAT_00123920 +
                                            (ulong)(byte)(&DAT_001f8f20)[uVar19] * 2)) -
                                 *(short *)(&DAT_00123720 +
                                           (ulong)(byte)(&DAT_001f8f20)[local_148[12]] * 2)) -
                                *(short *)(&DAT_00342620 + (ulong)(byte)(&DAT_001f8f20)[uVar10] * 2)
                                ) - *(short *)(&DAT_00353320 +
                                              (ulong)(byte)(&DAT_001f8f20)[uVar30] * 2))] &
          (uint)(byte)(&DAT_00123b20)
                      [(ushort)(((*(short *)(&DAT_00133b20 +
                                            (ulong)(byte)(&DAT_00133f20)[uVar13] * 2) -
                                 (*(short *)(&DAT_00133d20 +
                                            (ulong)(byte)(&DAT_00133f20)[uVar13] * 2) +
                                 *(short *)(&DAT_00374920 + (ulong)(byte)(&DAT_00133f20)[uVar20] * 2
                                           ))) -
                                *(short *)(&DAT_00219620 + (ulong)(byte)(&DAT_00133f20)[uVar34] * 2)
                                ) - *(short *)(&DAT_00363c20 +
                                              (ulong)(byte)(&DAT_00133f20)[local_148[8]] * 2))] &
          (uint)(byte)(&DAT_00134020)
                      [(ushort)(((*(short *)(&DAT_00144020 + (ulong)(byte)(&DAT_00144620)[uVar4] * 2
                                            ) -
                                 (*(short *)(&DAT_00321620 +
                                            (ulong)(byte)(&DAT_00144620)[uVar12] * 2) +
                                 *(short *)(&DAT_00144420 + (ulong)(byte)(&DAT_00144620)[uVar21] * 2
                                           ))) -
                                *(short *)(&DAT_00144220 + (ulong)(byte)(&DAT_00144620)[uVar17] * 2)
                                ) - *(short *)(&DAT_001e8320 +
                                              (ulong)(byte)(&DAT_00144620)[uVar39] * 2))] &
          (uint)(byte)(&DAT_00144720)
                      [(ushort)((((*(short *)(&DAT_00385020 +
                                             (ulong)(byte)(&DAT_00154920)[uVar21] * 2) +
                                  *(short *)(&DAT_0026b920 +
                                            (ulong)(byte)(&DAT_00154920)[uVar15] * 2)) -
                                 *(short *)(&DAT_001e8920 + (ulong)(byte)(&DAT_00154920)[uVar12] * 2
                                           )) -
                                *(short *)(&DAT_00374520 + (ulong)(byte)(&DAT_00154920)[uVar27] * 2)
                                ) - *(short *)(&DAT_00154720 +
                                              (ulong)(byte)(&DAT_00154920)[uVar5] * 2))] &
          (uint)(byte)(&DAT_00154a20)
                      [(ushort)((((*(short *)(&DAT_00164a20 +
                                             (ulong)(byte)(&DAT_00165220)[uVar36] * 2) +
                                  *(short *)(&DAT_00164e20 +
                                            (ulong)(byte)(&DAT_00165220)[uVar39] * 2)) -
                                 *(short *)(&DAT_00165020 + (ulong)(byte)(&DAT_00165220)[uVar36] * 2
                                           )) -
                                *(short *)(&DAT_0022a520 + (ulong)(byte)(&DAT_00165220)[uVar10] * 2)
                                ) - *(short *)(&DAT_00164c20 +
                                              (ulong)(byte)(&DAT_00165220)[uVar21] * 2))] &
          (uint)(byte)(&DAT_00165320)
                      [(ushort)(((*(short *)(&DAT_001a6220 +
                                            (ulong)(byte)(&DAT_00175920)[uVar10] * 2) +
                                  *(short *)(&DAT_00175720 +
                                            (ulong)(byte)(&DAT_00175920)[uVar33] * 2) +
                                 *(short *)(&DAT_00175320 + (ulong)(byte)(&DAT_00175920)[uVar39] * 2
                                           )) -
                                *(short *)(&DAT_00175520 + (ulong)(byte)(&DAT_00175920)[uVar35] * 2)
                                ) - *(short *)(&DAT_00374720 +
                                              (ulong)(byte)(&DAT_00175920)[uVar25] * 2))] &
          (uint)(byte)(&DAT_00175a20)
                      [(ushort)(((*(short *)(&DAT_00342c20 +
                                            (ulong)(byte)(&DAT_00185e20)[local_138[1]] * 2) +
                                  *(short *)(&DAT_00185c20 +
                                            (ulong)(byte)(&DAT_00185e20)[uVar18] * 2) +
                                 *(short *)(&DAT_00185a20 + (ulong)(byte)(&DAT_00185e20)[uVar25] * 2
                                           )) -
                                *(short *)(&DAT_002ef720 + (ulong)(byte)(&DAT_00185e20)[uVar29] * 2)
                                ) - *(short *)(&DAT_00374520 +
                                              (ulong)(byte)(&DAT_00185e20)[uVar19] * 2))] &
          (uint)(byte)(&DAT_00185f20)
                      [(ushort)((((*(short *)(&DAT_00195f20 +
                                             (ulong)(byte)(&DAT_00196120)[uVar29] * 2) +
                                  *(short *)(&DAT_00321a20 + (ulong)(byte)(&DAT_00196120)[uVar5] * 2
                                            )) -
                                 *(short *)(&DAT_00385220 + (ulong)(byte)(&DAT_00196120)[uVar17] * 2
                                           )) -
                                *(short *)(&DAT_002df020 + (ulong)(byte)(&DAT_00196120)[uVar20] * 2)
                                ) - *(short *)(&DAT_00363c20 +
                                              (ulong)(byte)(&DAT_00196120)[uVar29] * 2))] &
          (uint)(byte)(&DAT_00196220)
                      [(ushort)((((*(short *)(&DAT_001a6420 +
                                             (ulong)(byte)(&DAT_002eff20)[local_138[1]] * 2) +
                                  *(short *)(&DAT_001a6a20 +
                                            (ulong)(byte)(&DAT_002eff20)[uVar34] * 2)) -
                                 *(short *)(&DAT_001a6820 + (ulong)(byte)(&DAT_002eff20)[uVar39] * 2
                                           )) -
                                *(short *)(&DAT_001a6620 + (ulong)(byte)(&DAT_002eff20)[uVar18] * 2)
                                ) - *(short *)(&DAT_001a6220 +
                                              (ulong)(byte)(&DAT_002eff20)[uVar37] * 2))] &
          (uint)(byte)(&DAT_001a6c20)
                      [(ushort)((((*(short *)(&DAT_001b7220 +
                                             (ulong)(byte)(&DAT_001b7420)[uVar24] * 2) +
                                  *(short *)(&DAT_001b6e20 +
                                            (ulong)(byte)(&DAT_001b7420)[uVar35] * 2)) -
                                 *(short *)(&DAT_002ad120 + (ulong)(byte)(&DAT_001b7420)[uVar41] * 2
                                           )) -
                                *(short *)(&DAT_001b7020 + (ulong)(byte)(&DAT_001b7420)[uVar24] * 2)
                                ) - *(short *)(&DAT_001b6c20 +
                                              (ulong)(byte)(&DAT_001b7420)[local_128[8]] * 2))] &
          (uint)(byte)(&DAT_001b7520)
                      [(ushort)(((*(short *)(&DAT_001c7920 +
                                            (ulong)(byte)(&DAT_001c7b20)[uVar34] * 2) +
                                  *(short *)(&DAT_00352f20 +
                                            (ulong)(byte)(&DAT_001c7b20)[local_138[13]] * 2) +
                                 *(short *)(&DAT_0029ce20 + (ulong)(byte)(&DAT_001c7b20)[uVar10] * 2
                                           )) -
                                *(short *)(&DAT_001c7720 + (ulong)(byte)(&DAT_001c7b20)[uVar27] * 2)
                                ) - *(short *)(&DAT_001c7520 +
                                              (ulong)(byte)(&DAT_001c7b20)[uVar6] * 2))] &
          (uint)(byte)(&DAT_001c7c20)
                      [(ushort)(((*(short *)(&DAT_00332120 +
                                            (ulong)(byte)(&DAT_001d8220)[uVar32] * 2) +
                                  *(short *)(&DAT_002ce520 +
                                            (ulong)(byte)(&DAT_001d8220)[uVar35] * 2) +
                                 *(short *)(&DAT_001d7e20 + (ulong)(byte)(&DAT_001d8220)[uVar33] * 2
                                           )) -
                                *(short *)(&DAT_001d8020 + (ulong)(byte)(&DAT_001d8220)[uVar27] * 2)
                                ) - *(short *)(&DAT_001d7c20 +
                                              (ulong)(byte)(&DAT_001d8220)[uVar41] * 2))] &
          (uint)(byte)(&DAT_001d8320)
                      [(ushort)(((*(short *)(&DAT_001e8720 +
                                            (ulong)(byte)(&DAT_002be220)[uVar17] * 2) +
                                  *(short *)(&DAT_00321a20 +
                                            (ulong)(byte)(&DAT_002be220)[uVar14] * 2) +
                                 *(short *)(&DAT_001e8320 + (ulong)(byte)(&DAT_002be220)[uVar16] * 2
                                           )) -
                                *(short *)(&DAT_001e8920 + (ulong)(byte)(&DAT_002be220)[uVar10] * 2)
                                ) - *(short *)(&DAT_001e8520 +
                                              (ulong)(byte)(&DAT_002be220)[uVar29] * 2))] &
          (uint)(byte)(&DAT_001e8b20)
                      [(ushort)(((*(short *)(&DAT_00311120 +
                                            (ulong)(byte)(&DAT_001f8f20)[local_148[8]] * 2) +
                                  *(short *)(&DAT_00310b20 +
                                            (ulong)(byte)(&DAT_001f8f20)[uVar14] * 2) +
                                 *(short *)(&DAT_001f8d20 + (ulong)(byte)(&DAT_001f8f20)[uVar33] * 2
                                           )) -
                                *(short *)(&DAT_00352f20 + (ulong)(byte)(&DAT_001f8f20)[uVar32] * 2)
                                ) - *(short *)(&DAT_001f8b20 +
                                              (ulong)(byte)(&DAT_001f8f20)[local_148[10]] * 2))] &
          (uint)(byte)(&DAT_001f9020)
                      [(ushort)((((*(short *)(&DAT_00209020 +
                                             (ulong)(byte)(&DAT_00332520)[uVar34] * 2) +
                                  *(short *)(&DAT_00209420 + (ulong)(byte)(&DAT_00332520)[uVar4] * 2
                                            )) -
                                 *(short *)(&DAT_00209220 + (ulong)(byte)(&DAT_00332520)[uVar6] * 2)
                                 ) - *(short *)(&DAT_00395f20 +
                                               (ulong)(byte)(&DAT_00332520)[uVar33] * 2)) -
                               *(short *)(&DAT_00209420 + (ulong)(byte)(&DAT_00332520)[uVar30] * 2))
                      ] &
          (uint)(byte)(&DAT_00209620)
                      [(ushort)(((*(short *)(&DAT_00219820 +
                                            (ulong)(byte)(&DAT_0021a020)[uVar12] * 2) +
                                  *(short *)(&DAT_00219e20 + uVar31 * 2) +
                                 *(short *)(&DAT_00219620 + (ulong)(byte)(&DAT_0021a020)[uVar12] * 2
                                           )) - *(short *)(&DAT_00219c20 + uVar31 * 2)) -
                               *(short *)(&DAT_00219a20 + uVar31 * 2))] &
          (uint)(byte)(&DAT_0021a120)
                      [(ushort)((((*(short *)(&DAT_0022a120 +
                                             (ulong)(byte)(&DAT_0022a720)[uVar26] * 2) +
                                  *(short *)(&DAT_0022a520 + (ulong)(byte)(&DAT_0022a720)[uVar4] * 2
                                            )) -
                                 *(short *)(&DAT_0022a320 + (ulong)(byte)(&DAT_0022a720)[uVar4] * 2)
                                 ) - *(short *)(&DAT_00385020 +
                                               (ulong)(byte)(&DAT_0022a720)[uVar26] * 2)) -
                               *(short *)(&DAT_0028c520 + (ulong)(byte)(&DAT_0022a720)[uVar18] * 2))
                      ] &
          (uint)(byte)(&DAT_0022a820)
                      [(ushort)(((*(short *)(&DAT_0023ac20 +
                                            (ulong)(byte)(&DAT_0023ae20)[uVar23] * 2) -
                                 (*(short *)(&DAT_0023aa20 +
                                            (ulong)(byte)(&DAT_0023ae20)[uVar40] * 2) +
                                 *(short *)(&DAT_002ce520 + (ulong)(byte)(&DAT_0023ae20)[uVar21] * 2
                                           ))) -
                                *(short *)(&DAT_00300020 + (ulong)(byte)(&DAT_0023ae20)[uVar4] * 2))
                               - *(short *)(&DAT_0023a820 + (ulong)(byte)(&DAT_0023ae20)[uVar4] * 2)
                               )] &
          (uint)(byte)(&DAT_0023af20)
                      [(ushort)(((*(short *)(&DAT_0024b120 +
                                            (ulong)(byte)(&DAT_0024b320)[uVar25] * 2) +
                                  *(short *)(&DAT_00353520 +
                                            (ulong)(byte)(&DAT_0024b320)[uVar29] * 2) +
                                 *(short *)(&DAT_002df220 + (ulong)(byte)(&DAT_0024b320)[uVar21] * 2
                                           )) -
                                *(short *)(&DAT_0024af20 + (ulong)(byte)(&DAT_0024b320)[uVar19] * 2)
                                ) - *(short *)(&DAT_00300020 +
                                              (ulong)(byte)(&DAT_0024b320)[uVar32] * 2))] &
          (uint)(byte)(&DAT_0024b420)
                      [(ushort)((((*(short *)(&DAT_0028c320 +
                                             (ulong)(byte)(&DAT_0025b620)[uVar12] * 2) +
                                  *(short *)(&DAT_0025b420 +
                                            (ulong)(byte)(&DAT_0025b620)[uVar25] * 2)) -
                                 *(short *)(&DAT_002efb20 + (ulong)(byte)(&DAT_0025b620)[uVar41] * 2
                                           )) -
                                *(short *)(&DAT_00310d20 + (ulong)(byte)(&DAT_0025b620)[uVar38] * 2)
                                ) - *(short *)(&DAT_002ef720 +
                                              (ulong)(byte)(&DAT_0025b620)[local_128[6]] * 2))] &
          (uint)(byte)(&DAT_0025b720)
                      [(ushort)(((*(short *)(&DAT_00321a20 +
                                            (ulong)(byte)(&DAT_0026bd20)[uVar37] * 2) +
                                  *(short *)(&DAT_0026bb20 +
                                            (ulong)(byte)(&DAT_0026bd20)[uVar21] * 2) +
                                 *(short *)(&DAT_0026b720 + (ulong)(byte)(&DAT_0026bd20)[uVar28] * 2
                                           )) -
                                *(short *)(&DAT_0026b920 + (ulong)(byte)(&DAT_0026bd20)[uVar10] * 2)
                                ) - *(short *)(&DAT_0026bb20 +
                                              (ulong)(byte)(&DAT_0026bd20)[uVar12] * 2))] &
          (uint)(byte)(&DAT_0026be20)
                      [(ushort)((((*(short *)(&DAT_00395f20 +
                                             (ulong)(byte)(&DAT_0027c220)[uVar10] * 2) +
                                  *(short *)(&DAT_0027be20 +
                                            (ulong)(byte)(&DAT_0027c220)[uVar40] * 2)) -
                                 *(short *)(&DAT_0027c020 + (ulong)(byte)(&DAT_0027c220)[uVar25] * 2
                                           )) -
                                *(short *)(&DAT_002efb20 + (ulong)(byte)(&DAT_0027c220)[uVar21] * 2)
                                ) - *(short *)(&DAT_00353520 +
                                              (ulong)(byte)(&DAT_0027c220)[uVar38] * 2))] &
          (uint)(byte)(&DAT_0027c320)
                      [(ushort)(((*(short *)(&DAT_002efb20 +
                                            (ulong)(byte)(&DAT_0028c720)[uVar24] * 2) +
                                  *(short *)(&DAT_0029cc20 +
                                            (ulong)(byte)(&DAT_0028c720)[uVar26] * 2) +
                                 *(short *)(&DAT_0028c320 + (ulong)(byte)(&DAT_0028c720)[uVar20] * 2
                                           )) -
                                *(short *)(&DAT_0028c520 + (ulong)(byte)(&DAT_0028c720)[uVar34] * 2)
                                ) - *(short *)(&DAT_002efd20 +
                                              (ulong)(byte)(&DAT_0028c720)[uVar24] * 2))] &
          (uint)(byte)(&DAT_0028c820)
                      [(ushort)((((*(short *)(&DAT_0029c820 +
                                             (ulong)(byte)(&DAT_0029d020)[uVar36] * 2) +
                                  *(short *)(&DAT_0029ca20 +
                                            (ulong)(byte)(&DAT_0029d020)[uVar19] * 2)) -
                                 *(short *)(&DAT_0029ce20 + (ulong)(byte)(&DAT_0029d020)[uVar30] * 2
                                           )) -
                                *(short *)(&DAT_0029cc20 + (ulong)(byte)(&DAT_0029d020)[uVar12] * 2)
                                ) - *(short *)(&DAT_002ce720 +
                                              (ulong)(byte)(&DAT_0029d020)[uVar26] * 2))] &
          (uint)(byte)(&DAT_0029d120)
                      [(ushort)(((*(short *)(&DAT_00385620 +
                                            (ulong)(byte)(&DAT_002ad920)[uVar19] * 2) -
                                 (*(short *)(&DAT_002ad520 +
                                            (ulong)(byte)(&DAT_002ad920)[uVar16] * 2) +
                                 *(short *)(&DAT_002ad720 + (ulong)(byte)(&DAT_002ad920)[uVar28] * 2
                                           ))) -
                                *(short *)(&DAT_002ad320 + (ulong)(byte)(&DAT_002ad920)[uVar24] * 2)
                                ) - *(short *)(&DAT_002ad120 +
                                              (ulong)(byte)(&DAT_002ad920)[uVar13] * 2))] &
          (uint)(byte)(&DAT_002ada20)
                      [(ushort)((((*(short *)(&DAT_002ef720 +
                                             (ulong)(byte)(&DAT_002be220)[uVar12] * 2) +
                                  *(short *)(&DAT_002be020 +
                                            (ulong)(byte)(&DAT_002be220)[uVar10] * 2)) -
                                 *(short *)(&DAT_002bde20 + (ulong)(byte)(&DAT_002be220)[uVar17] * 2
                                           )) -
                                *(short *)(&DAT_002bdc20 + (ulong)(byte)(&DAT_002be220)[uVar15] * 2)
                                ) - *(short *)(&DAT_002bda20 +
                                              (ulong)(byte)(&DAT_002be220)[uVar26] * 2))] &
          (uint)(byte)(&DAT_002be320)
                      [(ushort)((((*(short *)(&DAT_002ce320 +
                                             (ulong)(byte)(&DAT_002ce920)[uVar16] * 2) +
                                  *(short *)(&DAT_002ce520 +
                                            (ulong)(byte)(&DAT_002ce920)[uVar25] * 2)) -
                                 *(short *)(&DAT_00374b20 + (ulong)(byte)(&DAT_002ce920)[uVar28] * 2
                                           )) -
                                *(short *)(&DAT_002ce720 + (ulong)(byte)(&DAT_002ce920)[uVar30] * 2)
                                ) - *(short *)(&DAT_00374320 +
                                              (ulong)(byte)(&DAT_002ce920)[uVar30] * 2))] &
          (uint)(byte)(&DAT_002cea20)
                      [(ushort)((*(short *)(&DAT_002dee20 + (ulong)(byte)(&DAT_002df420)[uVar15] * 2
                                           ) +
                                 *(short *)(&DAT_002df220 + (ulong)(byte)(&DAT_002df420)[uVar19] * 2
                                           ) +
                                 *(short *)(&DAT_002dec20 + (ulong)(byte)(&DAT_002df420)[uVar23] * 2
                                           ) +
                                *(short *)(&DAT_002dea20 + (ulong)(byte)(&DAT_002df420)[uVar33] * 2)
                                ) - *(short *)(&DAT_002df020 +
                                              (ulong)(byte)(&DAT_002df420)[uVar25] * 2))] &
          (uint)(byte)(&DAT_002df520)
                      [(ushort)(((*(short *)(&DAT_002ef920 +
                                            (ulong)(byte)(&DAT_002eff20)[uVar37] * 2) +
                                  *(short *)(&DAT_002efd20 +
                                            (ulong)(byte)(&DAT_002eff20)[uVar24] * 2) +
                                 *(short *)(&DAT_002ef520 + (ulong)(byte)(&DAT_002eff20)[uVar4] * 2)
                                 ) - *(short *)(&DAT_002efb20 +
                                               (ulong)(byte)(&DAT_002eff20)[uVar39] * 2)) -
                               *(short *)(&DAT_002ef720 + (ulong)(byte)(&DAT_002eff20)[uVar41] * 2))
                      ] &
          (uint)(byte)(&DAT_002f0020)
                      [(ushort)(((*(short *)(&DAT_00300220 + (ulong)(byte)(&DAT_00300820)[uVar4] * 2
                                            ) +
                                  *(short *)(&DAT_00300620 + (ulong)(byte)(&DAT_00300820)[uVar6] * 2
                                            ) +
                                 *(short *)(&DAT_00300020 + (ulong)(byte)(&DAT_00300820)[uVar17] * 2
                                           )) -
                                *(short *)(&DAT_00300420 + (ulong)(byte)(&DAT_00300820)[uVar15] * 2)
                                ) - *(short *)(&DAT_00321420 +
                                              (ulong)(byte)(&DAT_00300820)[uVar41] * 2))] &
          (uint)(byte)(&DAT_00300920)
                      [(ushort)((((*(short *)(&DAT_00310b20 +
                                             (ulong)(byte)(&DAT_00311320)[uVar38] * 2) +
                                  *(short *)(&DAT_00311120 +
                                            (ulong)(byte)(&DAT_00311320)[uVar24] * 2)) -
                                 *(short *)(&DAT_00310f20 + (ulong)(byte)(&DAT_00311320)[uVar41] * 2
                                           )) -
                                *(short *)(&DAT_00310d20 + (ulong)(byte)(&DAT_00311320)[uVar20] * 2)
                                ) - *(short *)(&DAT_00310920 +
                                              (ulong)(byte)(&DAT_00311320)[uVar37] * 2))] &
          (uint)(byte)(&DAT_00311420)
                      [(ushort)((*(short *)(&DAT_00321a20 +
                                           (ulong)(byte)(&DAT_00321c20)[local_148[10]] * 2) +
                                 *(short *)(&DAT_00385420 + (ulong)(byte)(&DAT_00321c20)[uVar14] * 2
                                           ) +
                                 *(short *)(&DAT_00321820 + (ulong)(byte)(&DAT_00321c20)[uVar15] * 2
                                           ) +
                                *(short *)(&DAT_00321420 + (ulong)(byte)(&DAT_00321c20)[uVar16] * 2)
                                ) - *(short *)(&DAT_00321620 +
                                              (ulong)(byte)(&DAT_00321c20)[uVar34] * 2))] &
          (uint)(byte)(&DAT_00321d20)
                      [(ushort)((((*(short *)(&DAT_00331f20 +
                                             (ulong)(byte)(&DAT_00332520)[local_128[8]] * 2) +
                                  *(short *)(&DAT_00332320 + (ulong)(byte)(&DAT_00332520)[uVar5] * 2
                                            )) -
                                 *(short *)(&DAT_00332120 + (ulong)(byte)(&DAT_00332520)[uVar37] * 2
                                           )) -
                                *(short *)(&DAT_00331d20 + (ulong)(byte)(&DAT_00332520)[uVar34] * 2)
                                ) - *(short *)(&DAT_00385020 +
                                              (ulong)(byte)(&DAT_00332520)[uVar40] * 2))] &
          (uint)(byte)(&DAT_00332620)
                      [(ushort)(((*(short *)(&DAT_00352f20 +
                                            (ulong)(byte)(&DAT_00342e20)[uVar39] * 2) +
                                  *(short *)(&DAT_00342c20 + (ulong)(byte)(&DAT_00342e20)[uVar4] * 2
                                            ) +
                                 *(short *)(&DAT_00342620 + (ulong)(byte)(&DAT_00342e20)[uVar40] * 2
                                           )) -
                                *(short *)(&DAT_00342a20 + (ulong)(byte)(&DAT_00342e20)[uVar12] * 2)
                                ) - *(short *)(&DAT_00342820 +
                                              (ulong)(byte)(&DAT_00342e20)[uVar20] * 2))] &
          (uint)(byte)(&DAT_00342f20)
                      [(ushort)((((*(short *)(&DAT_00353120 +
                                             (ulong)(byte)(&DAT_00353920)[uVar28] * 2) +
                                  *(short *)(&DAT_00353720 +
                                            (ulong)(byte)(&DAT_00353920)[uVar28] * 2)) -
                                 *(short *)(&DAT_00353520 + (ulong)(byte)(&DAT_00353920)[uVar13] * 2
                                           )) -
                                *(short *)(&DAT_00353320 + (ulong)(byte)(&DAT_00353920)[uVar33] * 2)
                                ) - *(short *)(&DAT_00352f20 +
                                              (ulong)(byte)(&DAT_00353920)[uVar25] * 2))] &
          (uint)(byte)(&DAT_00353a20)
                      [(ushort)(((*(short *)(&DAT_00364020 +
                                            (ulong)(byte)(&DAT_00364220)[uVar24] * 2) -
                                 (*(short *)(&DAT_00374b20 +
                                            (ulong)(byte)(&DAT_00364220)[uVar24] * 2) +
                                 *(short *)(&DAT_00363e20 + (ulong)(byte)(&DAT_00364220)[uVar32] * 2
                                           ))) -
                                *(short *)(&DAT_00363c20 + (ulong)(byte)(&DAT_00364220)[uVar20] * 2)
                                ) - *(short *)(&DAT_00363a20 +
                                              (ulong)(byte)(&DAT_00364220)[local_148[4]] * 2))] &
          (uint)(byte)(&DAT_00364320)
                      [(ushort)(((*(short *)(&DAT_00374520 +
                                            (ulong)(byte)(&DAT_00374d20)[uVar23] * 2) -
                                 (*(short *)(&DAT_00374920 +
                                            (ulong)(byte)(&DAT_00374d20)[uVar12] * 2) +
                                 *(short *)(&DAT_00374b20 + (ulong)(byte)(&DAT_00374d20)[uVar39] * 2
                                           ))) -
                                *(short *)(&DAT_00374720 + (ulong)(byte)(&DAT_00374d20)[uVar37] * 2)
                                ) - *(short *)(&DAT_00374320 +
                                              (ulong)(byte)(&DAT_00374d20)[uVar20] * 2))] &
          (uint)(byte)(&DAT_00374e20)
                      [(ushort)((((*(short *)(&DAT_00385220 +
                                             (ulong)(byte)(&DAT_00385820)[local_128[6]] * 2) +
                                  *(short *)(&DAT_00385620 +
                                            (ulong)(byte)(&DAT_00385820)[uVar37] * 2)) -
                                 *(short *)(&DAT_00385420 + (ulong)(byte)(&DAT_00385820)[uVar19] * 2
                                           )) -
                                *(short *)(&DAT_00385020 + (ulong)(byte)(&DAT_00385820)[uVar41] * 2)
                                ) - *(short *)(&DAT_00384e20 +
                                              (ulong)(byte)(&DAT_00385820)[uVar38] * 2))] &
          (byte)(&DAT_00385920)
                [(ushort)(((*(short *)(&DAT_00395f20 +
                                      (ulong)(byte)(&DAT_00396320)[local_148[12]] * 2) +
                            *(short *)(&DAT_00396120 + (ulong)(byte)(&DAT_00396320)[uVar21] * 2) +
                           *(short *)(&DAT_00395d20 + (ulong)(byte)(&DAT_00396320)[uVar36] * 2)) -
                          *(short *)(&DAT_00395b20 + (ulong)(byte)(&DAT_00396320)[uVar12] * 2)) -
                         *(short *)(&DAT_00395920 + (ulong)(byte)(&DAT_00396320)[uVar10] * 2))] &
          local_95c) != 0) {
      puts("Success!");
      uVar7 = 0;
      goto LAB_0010291c;
    }
  }
  uVar7 = 1;
LAB_0010291c:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar7;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

