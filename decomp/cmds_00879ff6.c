// cmd registration; entry 00879ff6 (seed 879ff6)


/* WARNING: Removing unreachable block (ram,0x0087a381) */
/* WARNING: Removing unreachable block (ram,0x0087a422) */

void FUN_00879ff6(long param_1)

{
  long lVar1;
  code *pcVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined *puVar5;
  undefined8 *puVar6;
  long *plVar7;
  long lVar8;
  char cVar9;
  undefined2 uVar10;
  long lVar11;
  long *plVar12;
  undefined8 uVar13;
  long *plVar14;
  undefined ***pppuVar16;
  undefined ***pppuVar15;
  long *local_398;
  long local_390;
  undefined8 *local_388;
  undefined8 *local_380;
  undefined8 local_378;
  long *local_368;
  long *local_360;
  long *local_358;
  undefined **local_348;
  long local_340;
  undefined *local_338 [2];
  long local_328;
  long local_320;
  undefined **local_308 [8];
  undefined1 local_2c8 [8];
  undefined4 local_2c0;
  undefined1 *local_2b8;
  undefined8 local_2b0;
  undefined1 local_2a8 [16];
  undefined **local_298 [27];
  undefined8 local_1c0;
  undefined1 local_1b8;
  undefined1 local_1b7;
  undefined8 local_1b0;
  undefined8 local_1a8;
  undefined8 local_1a0;
  undefined8 local_198;
  undefined8 local_188;
  long local_180;
  undefined8 local_178;
  long local_170;
  undefined8 local_168;
  long local_160;
  undefined8 local_158;
  long local_150;
  undefined8 *local_148;
  undefined8 *local_140;
  undefined8 *local_128;
  undefined8 *local_120;
  undefined8 *local_108;
  undefined8 *local_100;
  undefined8 *local_e8;
  undefined8 *local_e0;
  undefined8 *local_c8;
  undefined8 *local_c0;
  undefined8 *local_a8;
  undefined8 *local_a0;
  undefined8 *local_88;
  undefined8 *local_80;
  undefined8 *local_68;
  undefined8 *local_60;
  undefined8 *local_48;
  undefined8 *local_40;
  
  if (DAT_01767f90 == 0) {
    return;
  }
  lVar11 = FUN_0040e271();
  lVar11 = lVar11 + 0x10;
  FUN_00c440d0(lVar11,"JSON config blob found (",0x18);
  plVar12 = (long *)FUN_00c44830(lVar11,DAT_01767f90);
  FUN_00c440d0(plVar12," bytes), loading.",0x11);
  plVar14 = *(long **)((long)plVar12 + *(long *)(*plVar12 + -0x18) + 0xf0);
  if (plVar14 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_00c84aa0();
  }
  if ((char)plVar14[7] == '\0') {
    FUN_00c7a0e0(plVar14);
    cVar9 = (**(code **)(*plVar14 + 0x30))(plVar14,10);
  }
  else {
    cVar9 = *(char *)((long)plVar14 + 0x43);
  }
  uVar13 = FUN_00c43cf0(plVar12,(int)cVar9);
  FUN_00c433a0(uVar13);
                    /* try { // try from 0087a0a0 to 0087a0a4 has its CatchHandler @ 0087b2b8 */
  FUN_00565af8(&local_188,s____version___1___restricted_mode_01767f94,DAT_01767f90,&DAT_01767f70);
  lVar8 = local_180;
  uVar13 = local_188;
  local_180 = 0;
  local_188 = 0;
  *(undefined8 *)(param_1 + 0x50) = uVar13;
  lVar1 = *(long *)(param_1 + 0x58);
  *(long *)(param_1 + 0x58) = lVar8;
  if ((lVar1 != 0) && (FUN_0042fcbe(), local_180 != 0)) {
    FUN_0042fcbe();
  }
                    /* try { // try from 0087a117 to 0087a11b has its CatchHandler @ 0087b2b8 */
  FUN_0056966c(&local_398);
                    /* try { // try from 0087a12a to 0087a12c has its CatchHandler @ 0087b2ad */
  (**(code **)(*local_398 + 0x10))(local_398,*(undefined8 *)(param_1 + 0x50));
  FUN_00c64d80(local_298);
  puVar5 = PTR_DAT_01228390;
  local_298[0] = &PTR_LAB_0122c740;
  local_1c0 = 0;
  local_1b8 = 0;
  local_1b7 = 0;
  local_1b0 = 0;
  local_1a8 = 0;
  local_1a0 = 0;
  local_198 = 0;
  local_308[0] = (undefined **)PTR_DAT_01228388;
  *(undefined **)((long)local_308 + *(long *)(PTR_DAT_01228388 + -0x18)) = PTR_DAT_01228390;
                    /* try { // try from 0087a1c5 to 0087a1c9 has its CatchHandler @ 0087a2fb */
  FUN_00cbf5f0((undefined *)((long)local_308 + (long)local_308[0][-3]),0);
  local_308[0] = &PTR_FUN_012283b8;
  local_298[0] = &PTR_LAB_012283e0;
  local_308[1] = &PTR_LAB_0122c610;
  local_308[2] = (undefined **)0x0;
  local_308[3] = (undefined **)0x0;
  local_308[4] = (undefined **)0x0;
  local_308[5] = (undefined **)0x0;
  local_308[6] = (undefined **)0x0;
  local_308[7] = (undefined **)0x0;
  FUN_00c3bbb0(local_2c8);
  local_308[1] = &PTR_FUN_01228200;
  local_2c0 = 0x10;
  local_2b8 = local_2a8;
  local_2b0 = 0;
  local_2a8[0] = 0;
                    /* try { // try from 0087a285 to 0087a289 has its CatchHandler @ 0087a28c */
  FUN_00cbf5f0(local_298,local_308 + 1);
                    /* try { // try from 0087a318 to 0087a32d has its CatchHandler @ 0087b2a2 */
  (**(code **)(*local_398 + 0x18))(local_398,*(undefined8 *)(param_1 + 0x50),local_308);
  FUN_00c59d00(&local_348,local_308 + 1);
                    /* try { // try from 0087a33f to 0087a343 has its CatchHandler @ 0087b01e */
  FUN_00c440d0(lVar11,local_348,local_340);
  if (local_348 != local_338) {
    free(local_348);
  }
  local_168 = *(undefined8 *)(param_1 + 0x50);
  local_160 = *(long *)(param_1 + 0x58);
  if (local_160 != 0) {
    LOCK();
    *(int *)(local_160 + 8) = *(int *)(local_160 + 8) + 1;
    UNLOCK();
  }
                    /* try { // try from 0087a393 to 0087a397 has its CatchHandler @ 0087b04d */
  FUN_0056a042(&local_178,&local_168);
  lVar1 = local_170;
  uVar13 = local_178;
  local_170 = 0;
  local_178 = 0;
  *(undefined8 *)(param_1 + 0x60) = uVar13;
  lVar11 = *(long *)(param_1 + 0x68);
  *(long *)(param_1 + 0x68) = lVar1;
  if ((lVar11 != 0) && (FUN_0042fcbe(), local_170 != 0)) {
    FUN_0042fcbe();
  }
  if (local_160 != 0) {
    FUN_0042fcbe();
  }
  local_158 = *(undefined8 *)(param_1 + 0x60);
  local_150 = *(long *)(param_1 + 0x68);
  if (local_150 != 0) {
    LOCK();
    *(int *)(local_150 + 8) = *(int *)(local_150 + 8) + 1;
    UNLOCK();
  }
                    /* try { // try from 0087a42d to 0087a431 has its CatchHandler @ 0087b066 */
  FUN_00553c72(&local_158);
  if (local_150 != 0) {
    FUN_0042fcbe();
  }
  local_388 = (undefined8 *)0x0;
  local_380 = (undefined8 *)0x0;
  local_378 = 0;
                    /* try { // try from 0087a474 to 0087a4ab has its CatchHandler @ 0087b297 */
  cVar9 = (**(code **)(**(long **)(param_1 + 0x50) + 0x20))();
  if (cVar9 != '\0') {
    plVar14 = *(long **)(param_1 + 8);
    pcVar2 = *(code **)(*plVar14 + 0xa0);
    FUN_0086eb06(&local_148,&local_388);
    local_348 = local_338;
                    /* try { // try from 0087a4d5 to 0087a4d9 has its CatchHandler @ 0087b0ae */
    FUN_0040eb78(&local_348,"silence","");
                    /* try { // try from 0087a4ef to 0087a4f1 has its CatchHandler @ 0087b07f */
    (*pcVar2)(plVar14,&local_348,&local_148);
    puVar3 = local_148;
    if (local_348 != local_338) {
      free(local_348);
      puVar3 = local_148;
    }
    for (; local_140 != puVar3; puVar3 = puVar3 + 4) {
      if ((undefined8 *)*puVar3 != puVar3 + 2) {
        free((undefined8 *)*puVar3);
      }
    }
    if (local_148 != (undefined8 *)0x0) {
      free(local_148);
    }
  }
  cVar9 = (**(code **)(**(long **)(param_1 + 0x50) + 0x28))();
  if (cVar9 != '\0') {
    plVar14 = *(long **)(param_1 + 8);
    pcVar2 = *(code **)(*plVar14 + 0xa0);
    FUN_0086eb06(&local_128,&local_388);
    local_348 = local_338;
                    /* try { // try from 0087a5b2 to 0087a5b6 has its CatchHandler @ 0087b0e5 */
    FUN_0040eb78(&local_348,"noconfirm","");
                    /* try { // try from 0087a5cc to 0087a5ce has its CatchHandler @ 0087b0b6 */
    (*pcVar2)(plVar14,&local_348,&local_128);
    puVar3 = local_128;
    if (local_348 != local_338) {
      free(local_348);
      puVar3 = local_128;
    }
    for (; local_120 != puVar3; puVar3 = puVar3 + 4) {
      if ((undefined8 *)*puVar3 != puVar3 + 2) {
        free((undefined8 *)*puVar3);
      }
    }
    if (local_128 != (undefined8 *)0x0) {
      free(local_128);
    }
  }
                    /* try { // try from 0087a55f to 0087a588 has its CatchHandler @ 0087b297 */
  cVar9 = (**(code **)(**(long **)(param_1 + 0x50) + 0x30))();
  if (cVar9 != '\0') {
    plVar14 = *(long **)(param_1 + 8);
    pcVar2 = *(code **)(*plVar14 + 0xa0);
    FUN_0086eb06(&local_108,&local_388);
    local_348 = local_338;
                    /* try { // try from 0087a68f to 0087a693 has its CatchHandler @ 0087b11c */
    FUN_0040eb78(&local_348,"upgradeonly","");
                    /* try { // try from 0087a6a9 to 0087a6ab has its CatchHandler @ 0087b0ed */
    (*pcVar2)(plVar14,&local_348,&local_108);
    puVar3 = local_108;
    if (local_348 != local_338) {
      free(local_348);
      puVar3 = local_108;
    }
    for (; local_100 != puVar3; puVar3 = puVar3 + 4) {
      if ((undefined8 *)*puVar3 != puVar3 + 2) {
        free((undefined8 *)*puVar3);
      }
    }
    if (local_108 != (undefined8 *)0x0) {
      free(local_108);
    }
  }
                    /* try { // try from 0087a63c to 0087a665 has its CatchHandler @ 0087b297 */
  cVar9 = (**(code **)(**(long **)(param_1 + 0x50) + 0x38))();
  if (cVar9 != '\0') {
    plVar14 = *(long **)(param_1 + 8);
    pcVar2 = *(code **)(*plVar14 + 0xa0);
    FUN_0086eb06(&local_e8,&local_388);
    local_348 = local_338;
                    /* try { // try from 0087a76c to 0087a770 has its CatchHandler @ 0087b153 */
    FUN_0040eb78(&local_348,"nodowngrade","");
                    /* try { // try from 0087a786 to 0087a788 has its CatchHandler @ 0087b124 */
    (*pcVar2)(plVar14,&local_348,&local_e8);
    puVar3 = local_e8;
    if (local_348 != local_338) {
      free(local_348);
      puVar3 = local_e8;
    }
    for (; local_e0 != puVar3; puVar3 = puVar3 + 4) {
      if ((undefined8 *)*puVar3 != puVar3 + 2) {
        free((undefined8 *)*puVar3);
      }
    }
    if (local_e8 != (undefined8 *)0x0) {
      free(local_e8);
    }
  }
                    /* try { // try from 0087a719 to 0087a742 has its CatchHandler @ 0087b297 */
  cVar9 = (**(code **)(**(long **)(param_1 + 0x50) + 0x40))();
  if (cVar9 != '\0') {
    plVar14 = *(long **)(param_1 + 8);
    pcVar2 = *(code **)(*plVar14 + 0xa0);
    FUN_0086eb06(&local_c8,&local_388);
    local_348 = local_338;
                    /* try { // try from 0087a849 to 0087a84d has its CatchHandler @ 0087b18a */
    FUN_0040eb78(&local_348,"reboot","");
                    /* try { // try from 0087a863 to 0087a865 has its CatchHandler @ 0087b15b */
    (*pcVar2)(plVar14,&local_348,&local_c8);
    puVar3 = local_c8;
    if (local_348 != local_338) {
      free(local_348);
      puVar3 = local_c8;
    }
    for (; local_c0 != puVar3; puVar3 = puVar3 + 4) {
      if ((undefined8 *)*puVar3 != puVar3 + 2) {
        free((undefined8 *)*puVar3);
      }
    }
    if (local_c8 != (undefined8 *)0x0) {
      free(local_c8);
    }
  }
                    /* try { // try from 0087a7f6 to 0087a81f has its CatchHandler @ 0087b297 */
  cVar9 = (**(code **)(**(long **)(param_1 + 0x50) + 0x48))();
  if (cVar9 != '\0') {
    plVar14 = *(long **)(param_1 + 8);
    pcVar2 = *(code **)(*plVar14 + 0xa0);
    FUN_0086eb06(&local_a8,&local_388);
    local_348 = local_338;
                    /* try { // try from 0087a929 to 0087a92d has its CatchHandler @ 0087b1c1 */
    FUN_0040eb78(&local_348,"reset_after_update","");
                    /* try { // try from 0087a943 to 0087a945 has its CatchHandler @ 0087b192 */
    (*pcVar2)(plVar14,&local_348,&local_a8);
    puVar3 = local_a8;
    if (local_348 != local_338) {
      free(local_348);
      puVar3 = local_a8;
    }
    for (; local_a0 != puVar3; puVar3 = puVar3 + 4) {
      if ((undefined8 *)*puVar3 != puVar3 + 2) {
        free((undefined8 *)*puVar3);
      }
    }
    if (local_a8 != (undefined8 *)0x0) {
      free(local_a8);
    }
  }
                    /* try { // try from 0087a8d3 to 0087a8ff has its CatchHandler @ 0087b297 */
  cVar9 = (**(code **)(**(long **)(param_1 + 0x50) + 0x80))();
  if (cVar9 != '\0') {
    plVar14 = *(long **)(param_1 + 8);
    pcVar2 = *(code **)(*plVar14 + 0xa0);
    FUN_0086eb06(&local_88,&local_388);
    local_348 = local_338;
                    /* try { // try from 0087aa06 to 0087aa0a has its CatchHandler @ 0087b1f5 */
    FUN_0040eb78(&local_348,"overridesub","");
                    /* try { // try from 0087aa1d to 0087aa1f has its CatchHandler @ 0087b1c9 */
    (*pcVar2)(plVar14,&local_348,&local_88);
    puVar3 = local_88;
    if (local_348 != local_338) {
      free(local_348);
      puVar3 = local_88;
    }
    for (; local_80 != puVar3; puVar3 = puVar3 + 4) {
      if ((undefined8 *)*puVar3 != puVar3 + 2) {
        free((undefined8 *)*puVar3);
      }
    }
    if (local_88 != (undefined8 *)0x0) {
      free(local_88);
    }
  }
                    /* try { // try from 0087a9b3 to 0087a9dc has its CatchHandler @ 0087b297 */
  cVar9 = (**(code **)(**(long **)(param_1 + 0x50) + 0x88))();
  if (cVar9 != '\0') {
                    /* try { // try from 0087aa88 to 0087aaa1 has its CatchHandler @ 0087b297 */
    uVar10 = (**(code **)(**(long **)(param_1 + 0x50) + 0x90))();
    FUN_0040ec0b(&local_348,uVar10,4);
    local_368 = (long *)0x0;
    local_360 = (long *)0x0;
    local_358 = (long *)0x0;
                    /* try { // try from 0087aac8 to 0087aacc has its CatchHandler @ 0087ab9f */
    local_368 = (long *)FUN_00c37a70(0x20);
    plVar14 = local_368 + 4;
    local_358 = plVar14;
    if (local_368 != (long *)0x0) {
      *local_368 = (long)(local_368 + 2);
                    /* try { // try from 0087ab05 to 0087ab09 has its CatchHandler @ 0087ab4e */
      FUN_0040ecb6(local_368,local_348,(long)local_348 + local_340);
    }
    local_360 = plVar14;
    if (local_348 != local_338) {
      free(local_348);
    }
    plVar14 = *(long **)(param_1 + 8);
    pcVar2 = *(code **)(*plVar14 + 0xa0);
                    /* try { // try from 0087ab47 to 0087ab4b has its CatchHandler @ 0087b247 */
    FUN_0086eb06(&local_68,&local_368);
    local_348 = local_338;
                    /* try { // try from 0087abd0 to 0087abd4 has its CatchHandler @ 0087b23f */
    FUN_0040eb78(&local_348,"forceboard","");
                    /* try { // try from 0087abe7 to 0087abe9 has its CatchHandler @ 0087b207 */
    (*pcVar2)(plVar14,&local_348,&local_68);
    puVar3 = local_68;
    if (local_348 != local_338) {
      free(local_348);
      puVar3 = local_68;
    }
    for (; local_60 != puVar3; puVar3 = puVar3 + 4) {
      if ((undefined8 *)*puVar3 != puVar3 + 2) {
        free((undefined8 *)*puVar3);
      }
    }
    plVar14 = local_368;
    plVar12 = local_360;
    if (local_68 != (undefined8 *)0x0) {
      free(local_68);
      plVar14 = local_368;
      plVar12 = local_360;
    }
    for (; plVar7 = local_360, local_360 != plVar14; plVar14 = plVar14 + 4) {
      local_360 = plVar12;
      if ((long *)*plVar14 != plVar14 + 2) {
        free((long *)*plVar14);
      }
      plVar12 = local_360;
      local_360 = plVar7;
    }
    local_360 = plVar12;
    if (local_368 != (long *)0x0) {
      free(local_368);
    }
  }
                    /* try { // try from 0087ac48 to 0087acca has its CatchHandler @ 0087b297 */
  cVar9 = (**(code **)(**(long **)(param_1 + 0x50) + 0x68))();
  puVar3 = local_388;
  puVar4 = local_380;
  if (cVar9 == '\0') goto joined_r0x0087af00;
  uVar10 = (**(code **)(**(long **)(param_1 + 0x50) + 0x70))();
  FUN_0040ec0b(&local_348,uVar10,4);
  uVar10 = (**(code **)(**(long **)(param_1 + 0x50) + 0x78))();
  FUN_0040ec0b(&local_328,uVar10,4);
  local_368 = (long *)0x0;
  local_360 = (long *)0x0;
  local_358 = (long *)0x0;
                    /* try { // try from 0087acf1 to 0087acf5 has its CatchHandler @ 0087ae0a */
  plVar14 = (long *)FUN_00c37a70(0x40);
  local_358 = plVar14 + 8;
  local_368 = plVar14;
  if (plVar14 == (long *)0x0) {
LAB_0087ad48:
    plVar14[4] = (long)(plVar14 + 6);
                    /* try { // try from 0087ad69 to 0087ad6d has its CatchHandler @ 0087adb8 */
    FUN_0040ecb6(plVar14 + 4,local_328,local_328 + local_320);
  }
  else {
    *plVar14 = (long)(plVar14 + 2);
                    /* try { // try from 0087ad36 to 0087ad3a has its CatchHandler @ 0087ad90 */
    FUN_0040ecb6(plVar14,local_348,(long)local_348 + local_340);
    if (plVar14 != (long *)0xffffffffffffffe0) goto LAB_0087ad48;
  }
  local_360 = plVar14 + 8;
  pppuVar15 = local_308;
  do {
    pppuVar16 = pppuVar15 + -4;
    if ((undefined ***)*pppuVar16 != pppuVar15 + -2) {
      free(*pppuVar16);
    }
    pppuVar15 = pppuVar16;
  } while (pppuVar16 != &local_348);
  plVar14 = *(long **)(param_1 + 8);
  pcVar2 = *(code **)(*plVar14 + 0xa0);
                    /* try { // try from 0087ae48 to 0087ae4c has its CatchHandler @ 0087b28f */
  FUN_0086eb06(&local_48,&local_368);
  local_348 = local_338;
                    /* try { // try from 0087ae76 to 0087ae7a has its CatchHandler @ 0087b287 */
  FUN_0040eb78(&local_348,"forcesub","");
                    /* try { // try from 0087ae8d to 0087ae8f has its CatchHandler @ 0087b24f */
  (*pcVar2)(plVar14,&local_348,&local_48);
  puVar3 = local_48;
  if (local_348 != local_338) {
    free(local_348);
    puVar3 = local_48;
  }
  for (; local_40 != puVar3; puVar3 = puVar3 + 4) {
    if ((undefined8 *)*puVar3 != puVar3 + 2) {
      free((undefined8 *)*puVar3);
    }
  }
  plVar14 = local_368;
  plVar12 = local_360;
  if (local_48 != (undefined8 *)0x0) {
    free(local_48);
    plVar14 = local_368;
    plVar12 = local_360;
  }
  for (; plVar7 = local_360, local_360 != plVar14; plVar14 = plVar14 + 4) {
    local_360 = plVar12;
    if ((long *)*plVar14 != plVar14 + 2) {
      free((long *)*plVar14);
    }
    plVar12 = local_360;
    local_360 = plVar7;
  }
  puVar3 = local_388;
  puVar4 = local_380;
  local_360 = plVar12;
  if (local_368 != (long *)0x0) {
    free(local_368);
    puVar3 = local_388;
    puVar4 = local_380;
  }
joined_r0x0087af00:
  for (; puVar6 = local_380, local_380 != puVar3; puVar3 = puVar3 + 4) {
    local_380 = puVar4;
    if ((undefined8 *)*puVar3 != puVar3 + 2) {
      free((undefined8 *)*puVar3);
    }
    puVar4 = local_380;
    local_380 = puVar6;
  }
  local_380 = puVar4;
  if (local_388 != (undefined8 *)0x0) {
    free(local_388);
  }
  local_308[0] = &PTR_FUN_012283b8;
  local_298[0] = &PTR_LAB_012283e0;
  local_308[1] = &PTR_FUN_01228200;
  if (local_2b8 != local_2a8) {
    free(local_2b8);
  }
  local_308[1] = &PTR_LAB_0122c610;
  FUN_00c3f070(local_2c8);
  local_308[0] = (undefined **)PTR_DAT_01228388;
  *(undefined **)((long)local_308 + *(long *)(PTR_DAT_01228388 + -0x18)) = puVar5;
  local_298[0] = &PTR_LAB_0122c740;
  FUN_00c65110(local_298);
  if (local_390 != 0) {
    FUN_0042fcbe();
  }
  return;
}

