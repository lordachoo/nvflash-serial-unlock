// cmd parser; entry 0092406e


/* WARNING: Removing unreachable block (ram,0x00925c89) */
/* WARNING: Removing unreachable block (ram,0x00925c97) */

int FUN_0092406e(long *param_1)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  char cVar4;
  byte bVar5;
  byte bVar6;
  undefined1 uVar7;
  undefined4 uVar8;
  int iVar9;
  long *plVar10;
  long lVar11;
  long *plVar12;
  undefined8 *puVar13;
  long lVar14;
  undefined8 uVar15;
  long *plVar16;
  long *plVar17;
  long *plVar18;
  long *plVar19;
  long *plVar20;
  ulong uVar21;
  undefined8 *puVar22;
  code *local_510;
  ulong local_500;
  byte local_4e1;
  long *local_4d0;
  undefined8 *local_4c8;
  undefined8 *local_4c0;
  undefined8 local_4b8 [2];
  undefined1 *local_4a8;
  long local_4a0;
  undefined1 local_498 [16];
  long *local_488;
  long local_480;
  long local_478;
  undefined8 local_470;
  int local_308 [2];
  undefined1 *local_300;
  undefined1 local_2f0 [24];
  undefined **local_2d8 [4];
  uint auStack_2b8 [8];
  undefined1 local_298 [48];
  undefined1 local_268 [136];
  undefined **local_1e0 [27];
  undefined8 local_108;
  undefined1 local_100;
  undefined1 local_ff;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  long *local_d8;
  long local_d0;
  long local_c8 [2];
  undefined1 local_b5;
  undefined1 local_b4;
  undefined1 local_b3;
  undefined1 local_b2;
  undefined1 local_b1;
  long *local_b0;
  long *local_a8;
  long *local_a0;
  long *local_98;
  long *local_90;
  long *local_88;
  long *local_80;
  long *local_78;
  undefined1 local_6b;
  undefined1 local_6a;
  undefined1 local_69;
  long *local_68;
  undefined1 local_5c;
  undefined1 local_5b [34];
  undefined1 local_39 [9];
  
  bVar5 = 0;
  if ((DAT_01777fb6 & 0x10) == 0) {
    plVar10 = (long *)param_1[1];
    pcVar3 = *(code **)(*plVar10 + 0x28);
    local_488 = &local_478;
    FUN_0040eb78(&local_488,"silence","");
                    /* try { // try from 0092413d to 0092413f has its CatchHandler @ 00925e85 */
    bVar5 = (*pcVar3)(plVar10,&local_488);
    bVar5 = bVar5 ^ 1;
    if (local_488 != &local_478) {
      free(local_488);
    }
  }
  bVar6 = 0;
  if ((DAT_01777fb6 & 0x20) == 0) {
    plVar10 = (long *)param_1[1];
    pcVar3 = *(code **)(*plVar10 + 0x28);
    local_488 = &local_478;
    FUN_0040eb78(&local_488,"noconfirm","");
                    /* try { // try from 009241ad to 009241af has its CatchHandler @ 00925ea8 */
    bVar6 = (*pcVar3)(plVar10,&local_488);
    bVar6 = bVar6 ^ 1;
    if (local_488 != &local_478) {
      free(local_488);
    }
  }
  plVar10 = (long *)param_1[1];
  pcVar3 = *(code **)(*plVar10 + 0x28);
  local_488 = &local_478;
  FUN_0040eb78(&local_488,"noconsolechk","");
                    /* try { // try from 009240ee to 009240f0 has its CatchHandler @ 00925ecb */
  cVar4 = (*pcVar3)(plVar10,&local_488);
  if (local_488 != &local_478) {
    free(local_488);
  }
  plVar10 = (long *)FUN_0042e510();
  (**(code **)(*plVar10 + 0x158))(plVar10);
  plVar10 = (long *)FUN_00671a5e();
  if (plVar10 != (long *)0x0) {
    (**(code **)*plVar10)(plVar10);
  }
                    /* try { // try from 0092422c to 0092422e has its CatchHandler @ 009266c7 */
  (**(code **)(*plVar10 + 0x70))(plVar10,bVar5 ^ 1);
  if ((bVar6 != 1) || (cVar4 != '\0')) {
                    /* try { // try from 0092427c to 00924281 has its CatchHandler @ 009266c7 */
    (**(code **)(*(long *)param_1[1] + 0xd8))();
  }
  plVar12 = (long *)param_1[1];
  pcVar3 = *(code **)(*plVar12 + 0x28);
  local_4c8 = local_4b8;
                    /* try { // try from 0092426e to 00924272 has its CatchHandler @ 00924297 */
  FUN_0040eb78(&local_4c8,"help","");
                    /* try { // try from 00924292 to 00924294 has its CatchHandler @ 00924332 */
  cVar4 = (*pcVar3)(plVar12,&local_4c8);
  if (cVar4 == '\0') {
    plVar12 = (long *)param_1[1];
    pcVar3 = *(code **)(*plVar12 + 0x28);
    local_4a8 = local_498;
                    /* try { // try from 0092437b to 0092437f has its CatchHandler @ 00924393 */
    FUN_0040eb78(&local_4a8,"licenseinfo","");
                    /* try { // try from 0092438e to 00924390 has its CatchHandler @ 009243d1 */
    cVar4 = (*pcVar3)(plVar12,&local_4a8);
    local_4e1 = 0;
    if (cVar4 == '\0') {
      plVar12 = (long *)param_1[1];
      pcVar3 = *(code **)(*plVar12 + 0x28);
                    /* try { // try from 009243ca to 009243ce has its CatchHandler @ 009243e6 */
      FUN_00c90a60(&local_488,&DAT_00daae26,&local_b5);
                    /* try { // try from 00924405 to 00924407 has its CatchHandler @ 0092444a */
      local_4e1 = (*pcVar3)(plVar12,&local_488);
      local_4e1 = local_4e1 ^ 1;
      if (local_488 != &local_478) {
        free(local_488);
      }
    }
    if (local_4a8 != local_498) {
      free(local_4a8);
    }
  }
  else {
    local_4e1 = 0;
  }
  if (local_4c8 != local_4b8) {
    free(local_4c8);
  }
                    /* try { // try from 00924328 to 0092432c has its CatchHandler @ 009266c7 */
  lVar11 = FUN_0040e271();
  plVar12 = (long *)param_1[1];
  pcVar3 = *(code **)(*plVar12 + 0x30);
  local_488 = &local_478;
                    /* try { // try from 009244ad to 009244b1 has its CatchHandler @ 009266c7 */
  FUN_0040eb78(&local_488,"log","");
                    /* try { // try from 009244d2 to 009244d4 has its CatchHandler @ 00925f05 */
  (*pcVar3)(&local_d8,plVar12,&local_488,0,0);
  if (local_488 != &local_478) {
    free(local_488);
  }
  if (local_d0 == 0) {
                    /* try { // try from 009244fb to 00924512 has its CatchHandler @ 009266bf */
    plVar12 = (long *)FUN_0042e510();
    (**(code **)(*plVar12 + 0x130))(&local_4a8,plVar12);
    if (0x7fffffffffffffffU - local_4a0 < 0xc) {
                    /* WARNING: Subroutine does not return */
      FUN_00c84c40("basic_string::append");
    }
                    /* try { // try from 0092453b to 0092454b has its CatchHandler @ 0092454c */
    puVar13 = (undefined8 *)FUN_00c8f910(&local_4a8,"/nvflash.log",0xc);
    lVar14 = local_c8[0];
    plVar12 = local_d8;
    local_488 = &local_478;
    if ((long *)*puVar13 == puVar13 + 2) {
      local_478 = puVar13[2];
      local_470 = puVar13[3];
    }
    else {
      local_478 = puVar13[2];
      local_488 = (long *)*puVar13;
    }
    local_480 = puVar13[1];
    *puVar13 = puVar13 + 2;
    puVar13[1] = 0;
    *(undefined1 *)(puVar13 + 2) = 0;
    if (local_488 == &local_478) {
      FUN_00c8e2d0(&local_d8,&local_488);
    }
    else {
      local_d0 = local_480;
      if (local_d8 != local_c8) {
        local_d8 = local_488;
        local_c8[0] = local_478;
        if (plVar12 != (long *)0x0) {
          local_488 = plVar12;
          local_478 = lVar14;
          goto LAB_00924629;
        }
      }
      local_c8[0] = local_478;
      local_d8 = local_488;
      local_488 = &local_478;
    }
LAB_00924629:
    local_480 = 0;
    *(undefined1 *)local_488 = 0;
    if (local_488 != &local_478) {
      free(local_488);
    }
    if (local_4a8 != local_498) {
      free(local_4a8);
    }
  }
  FUN_00c64d80(local_1e0);
  local_1e0[0] = &PTR_LAB_0122c740;
  local_108 = 0;
  local_100 = 0;
  local_ff = 0;
  local_f8 = 0;
  local_f0 = 0;
  local_e8 = 0;
  local_e0 = 0;
  local_2d8[0] = (undefined **)PTR_DAT_01229a30;
  *(undefined **)((long)local_2d8 + *(long *)(PTR_DAT_01229a30 + -0x18)) = PTR_DAT_01229a38;
                    /* try { // try from 00924709 to 0092470d has its CatchHandler @ 009247e4 */
  FUN_00cbf5f0((undefined *)((long)local_2d8 + (long)local_2d8[0][-3]),0);
  local_2d8[0] = &PTR_FUN_01229a60;
  local_1e0[0] = &PTR_LAB_01229a88;
                    /* try { // try from 00924760 to 00924764 has its CatchHandler @ 009247df */
  FUN_00c7bbc0(local_2d8 + 1);
                    /* try { // try from 00924777 to 0092477b has its CatchHandler @ 0092477e */
  FUN_00cbf5f0(local_1e0,local_2d8 + 1);
  plVar12 = (long *)param_1[1];
  pcVar3 = *(code **)(*plVar12 + 0x28);
  local_4a8 = local_498;
                    /* try { // try from 0092481d to 00924821 has its CatchHandler @ 00924835 */
  FUN_0040eb78(&local_4a8,"log","");
                    /* try { // try from 00924830 to 00924832 has its CatchHandler @ 009248b5 */
  cVar4 = (*pcVar3)(plVar12,&local_4a8);
  if (cVar4 == '\0') {
    cVar4 = '\0';
    if (local_4a8 != local_498) goto LAB_0092488a;
  }
  else {
    plVar12 = (long *)param_1[1];
    pcVar3 = *(code **)(*plVar12 + 0x28);
    local_488 = &local_478;
                    /* try { // try from 009248f8 to 009248fc has its CatchHandler @ 00925f29 */
    FUN_0040eb78(&local_488,"append","");
                    /* try { // try from 0092490b to 0092490d has its CatchHandler @ 00924948 */
    cVar4 = (*pcVar3)(plVar12,&local_488);
    if (local_488 != &local_478) {
      free(local_488);
    }
    if (local_4a8 != local_498) {
LAB_0092488a:
      free(local_4a8);
    }
    if (cVar4 != '\0') {
                    /* try { // try from 009248ab to 009248af has its CatchHandler @ 00924b8a */
      lVar14 = FUN_00c80170(local_2d8 + 1,local_d8,0x11);
      if (lVar14 == 0) {
        FUN_00cbee70((undefined *)((long)local_2d8 + (long)local_2d8[0][-3]),
                     *(uint *)((long)auStack_2b8 + (long)local_2d8[0][-3]) | 4);
      }
      else {
                    /* try { // try from 00924989 to 00924a90 has its CatchHandler @ 00924b8a */
        FUN_00cbee70((undefined *)((long)local_2d8 + (long)local_2d8[0][-3]),0);
      }
      goto LAB_00924a0a;
    }
  }
  lVar14 = FUN_00c80170(local_2d8 + 1,local_d8,0x30);
  if (lVar14 == 0) {
    FUN_00cbee70((undefined *)((long)local_2d8 + (long)local_2d8[0][-3]),
                 *(uint *)((long)auStack_2b8 + (long)local_2d8[0][-3]) | 4);
  }
  else {
    FUN_00cbee70((undefined *)((long)local_2d8 + (long)local_2d8[0][-3]),0);
  }
LAB_00924a0a:
  lVar14 = FUN_00c37a70(0x28);
  if (lVar14 != -0x10) {
    *(undefined1 *)(lVar14 + 0x10) = 0;
    *(undefined ****)(lVar14 + 0x18) = local_2d8;
    *(undefined4 *)(lVar14 + 0x20) = 1;
    *(undefined4 *)(lVar14 + 0x24) = 5;
  }
  FUN_00c39d80(lVar14,lVar11 + 0x88);
  *(long *)(lVar11 + 0x98) = *(long *)(lVar11 + 0x98) + 1;
  *(int *)(lVar11 + 0xa4) = *(int *)(lVar11 + 0xa4) + 1;
  plVar12 = (long *)param_1[1];
  pcVar3 = *(code **)(*plVar12 + 0x28);
  local_488 = &local_478;
  FUN_0040eb78(&local_488,"debug","");
                    /* try { // try from 00924a9f to 00924aa1 has its CatchHandler @ 00925f31 */
  cVar4 = (*pcVar3)(plVar12,&local_488);
  if (local_488 != &local_478) {
    free(local_488);
  }
  if (cVar4 != '\0') {
                    /* try { // try from 00924ac7 to 00924bbb has its CatchHandler @ 00924b8a */
    lVar14 = FUN_00c37a70(0x28);
    if (lVar14 != -0x10) {
      *(undefined1 *)(lVar14 + 0x10) = 0;
      *(undefined8 **)(lVar14 + 0x18) = &DAT_067fc9e0;
      *(undefined4 *)(lVar14 + 0x20) = 1;
      *(undefined4 *)(lVar14 + 0x24) = 5;
    }
    FUN_00c39d80(lVar14,lVar11 + 0x88);
    *(long *)(lVar11 + 0x98) = *(long *)(lVar11 + 0x98) + 1;
    *(int *)(lVar11 + 0xa4) = *(int *)(lVar11 + 0xa4) + 1;
  }
  *(undefined4 *)(lVar11 + 0xa0) = 3;
  lVar14 = lVar11 + 0x10;
  FUN_00c440d0(lVar14,"*** NVIDIA FIRMWARE UPDATE UTILITY LOG FILE ***\nVersion ",0x38);
  FUN_00c440d0(lVar14,"5.912.0",7);
  FUN_00c440d0(lVar14,&DAT_00dabe28,1);
  plVar12 = *(long **)(lVar11 + 0x100 + *(long *)(*(long *)(lVar11 + 0x10) + -0x18));
  if (plVar12 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_00c84aa0();
  }
  if ((char)plVar12[7] == '\0') {
    FUN_00c7a0e0(plVar12);
    cVar4 = (**(code **)(*plVar12 + 0x30))(plVar12,10);
  }
  else {
    cVar4 = *(char *)((long)plVar12 + 0x43);
  }
  uVar15 = FUN_00c43cf0(lVar14,(int)cVar4);
  FUN_00c433a0(uVar15);
  (**(code **)(*param_1 + 0x30))(param_1);
                    /* try { // try from 00924bbc to 00924bc0 has its CatchHandler @ 00924bcf */
  plVar12 = (long *)FUN_0042e510();
                    /* try { // try from 00924bc7 to 00924bcc has its CatchHandler @ 00924bff */
  (**(code **)(*plVar12 + 0x150))(plVar12);
                    /* try { // try from 00924c12 to 00924c14 has its CatchHandler @ 00924c24 */
  cVar4 = (**(code **)(*(long *)param_1[1] + 0x18))();
  if (cVar4 == '\0') {
                    /* try { // try from 00924cd3 to 00924cd7 has its CatchHandler @ 00924ce6 */
    plVar12 = (long *)FUN_0042e510();
                    /* try { // try from 00924cde to 00924ce3 has its CatchHandler @ 00924d03 */
    cVar4 = (**(code **)(*plVar12 + 0xd8))(plVar12);
    if (cVar4 != '\0') {
      puVar13 = (undefined8 *)FUN_00c37fd0(0x10);
                    /* try { // try from 00924d32 to 00924d36 has its CatchHandler @ 00925fc3 */
      FUN_00c90a60(&local_488,
                   "You are using a 64-bit operating system. Please use the\n64-bit version of this tool.\n"
                   ,&local_b4);
                    /* try { // try from 00924d41 to 00924d45 has its CatchHandler @ 00925f88 */
      FUN_00cb95e0(puVar13,&local_488);
      *puVar13 = &PTR_LAB_00d80cc0;
      if (local_488 != &local_478) {
        free(local_488);
      }
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00924d73 to 00924d77 has its CatchHandler @ 00924d78 */
      FUN_00c379d0(puVar13,&PTR_PTR_00d80c98,&LAB_00705c5e);
    }
                    /* try { // try from 00924cf9 to 00924cfd has its CatchHandler @ 00924d95 */
    plVar12 = (long *)FUN_0042e510();
                    /* try { // try from 00924d8d to 00924d92 has its CatchHandler @ 00924daf */
    cVar4 = (**(code **)(*plVar12 + 0x1b8))(plVar12);
    if (cVar4 != '\0') {
                    /* try { // try from 00924da8 to 00924dac has its CatchHandler @ 00924dcf */
      plVar12 = (long *)FUN_0042e510();
                    /* try { // try from 00924dc7 to 00924dcc has its CatchHandler @ 00924dde */
      (**(code **)(*plVar12 + 0xa0))(plVar12,lVar11);
    }
                    /* try { // try from 00924ded to 00924df1 has its CatchHandler @ 00924dfd */
    plVar12 = (long *)FUN_0042e510();
                    /* try { // try from 00924df8 to 00924dfa has its CatchHandler @ 00924e20 */
    cVar4 = (**(code **)(*plVar12 + 0x68))(plVar12);
    if ((cVar4 != '\x01') && (local_4e1 != 0)) {
                    /* try { // try from 00924e2f to 00924e33 has its CatchHandler @ 00924e43 */
      uVar15 = FUN_00443500();
                    /* try { // try from 00924e3c to 00924e40 has its CatchHandler @ 00924e82 */
      FUN_00443566(uVar15,0xb);
      puVar13 = (undefined8 *)FUN_00c37fd0(0x10);
                    /* try { // try from 00924eb1 to 00924eb5 has its CatchHandler @ 00926006 */
      FUN_00c90a60(&local_488,"The AC adapter must be plugged in before installing firmware.\n",
                   &local_b3);
                    /* try { // try from 00924ec0 to 00924ec4 has its CatchHandler @ 00925fcb */
      FUN_00cb95e0(puVar13,&local_488);
      *puVar13 = &PTR_LAB_00d80cc0;
      if (local_488 != &local_478) {
        free(local_488);
      }
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00924ef2 to 00924ef6 has its CatchHandler @ 00924ef7 */
      FUN_00c379d0(puVar13,&PTR_PTR_00d80c98,&LAB_00705c5e);
    }
                    /* try { // try from 00924e19 to 00924e1d has its CatchHandler @ 00924e73 */
    plVar12 = (long *)FUN_006ef174();
    if (plVar12 != (long *)0x0) {
                    /* try { // try from 00924e6c to 00924e6d has its CatchHandler @ 00924f06 */
      (**(code **)*plVar12)();
    }
                    /* try { // try from 00924f15 to 00924f19 has its CatchHandler @ 00924f34 */
    plVar16 = (long *)FUN_006d34e0();
    if (plVar16 != (long *)0x0) {
                    /* try { // try from 00924f30 to 00924f31 has its CatchHandler @ 00924f61 */
      (**(code **)*plVar16)();
    }
                    /* try { // try from 00924f73 to 00924f77 has its CatchHandler @ 00924f8a */
    plVar17 = (long *)FUN_0067b168();
    if (plVar17 != (long *)0x0) {
                    /* try { // try from 00924f86 to 00924f87 has its CatchHandler @ 00924fae */
      (**(code **)*plVar17)(plVar17);
    }
                    /* try { // try from 00924fc0 to 00924fc4 has its CatchHandler @ 00924fd7 */
    plVar18 = (long *)FUN_0058dc32();
    if (plVar18 != (long *)0x0) {
                    /* try { // try from 00924fd3 to 00924fd4 has its CatchHandler @ 00924ff7 */
      (**(code **)*plVar18)(plVar18);
    }
    pcVar3 = *(code **)(*plVar18 + 0x340);
                    /* try { // try from 0092501a to 0092501c has its CatchHandler @ 00925027 */
    uVar8 = (**(code **)(*param_1 + 0x48))(param_1);
                    /* try { // try from 00925022 to 00925024 has its CatchHandler @ 00925048 */
    (*pcVar3)(plVar18,uVar8);
    plVar20 = (long *)param_1[1];
    pcVar3 = *(code **)(*plVar20 + 0x28);
    local_488 = &local_478;
                    /* try { // try from 00925092 to 00925096 has its CatchHandler @ 009250b0 */
    FUN_0040eb78(&local_488,"help","");
                    /* try { // try from 009250ac to 009250ad has its CatchHandler @ 0092600e */
    cVar4 = (*pcVar3)(plVar20,&local_488);
    if (local_488 != &local_478) {
      free(local_488);
    }
    if (cVar4 == '\0') {
      plVar20 = (long *)param_1[1];
      pcVar3 = *(code **)(*plVar20 + 0x28);
      local_488 = &local_478;
                    /* try { // try from 00925143 to 00925147 has its CatchHandler @ 00925161 */
      FUN_0040eb78(&local_488,"licenseinfo","");
                    /* try { // try from 0092515d to 0092515e has its CatchHandler @ 0092603b */
      cVar4 = (*pcVar3)(plVar20,&local_488);
      if (local_488 != &local_478) {
        free(local_488);
      }
      if (cVar4 == '\0') {
        plVar20 = (long *)param_1[1];
        pcVar3 = *(code **)(*plVar20 + 0x28);
                    /* try { // try from 009251e2 to 009251e6 has its CatchHandler @ 009251e9 */
        FUN_00c90a60(&local_488,&DAT_00daae26,&local_b2);
                    /* try { // try from 0092520f to 00925210 has its CatchHandler @ 00926068 */
        cVar4 = (*pcVar3)(plVar20,&local_488);
        if (local_488 != &local_478) {
          free(local_488);
        }
        if (cVar4 == '\0') {
          plVar20 = (long *)param_1[1];
          pcVar3 = *(code **)(*plVar20 + 0x28);
                    /* try { // try from 0092527d to 00925281 has its CatchHandler @ 00925284 */
          FUN_00c90a60(&local_488,"version",&local_b1);
                    /* try { // try from 009252aa to 009252ab has its CatchHandler @ 00926095 */
          cVar4 = (*pcVar3)(plVar20,&local_488);
          if (local_488 != &local_478) {
            free(local_488);
          }
          if (cVar4 == '\0') {
            pcVar3 = *(code **)(*param_1 + 0x430);
            local_78 = plVar17;
            if (plVar17 != (long *)0x0) {
                    /* try { // try from 009252e9 to 009252ea has its CatchHandler @ 00925737 */
              (**(code **)*plVar17)(plVar17);
            }
                    /* try { // try from 00925753 to 00925754 has its CatchHandler @ 009261fe */
            (*pcVar3)(param_1,&local_78);
            if (local_78 != (long *)0x0) {
              (**(code **)(*local_78 + 8))();
            }
            if (param_1[0xf] == param_1[0xe]) {
                    /* try { // try from 00925796 to 0092579a has its CatchHandler @ 009257aa */
              uVar15 = FUN_00443500();
                    /* try { // try from 009257a3 to 009257a7 has its CatchHandler @ 009257bf */
              FUN_00443566(uVar15,0xc);
              puVar13 = (undefined8 *)FUN_00c37fd0(0x10);
                    /* try { // try from 009257f8 to 009257fc has its CatchHandler @ 0092625b */
              FUN_00c90a60(&local_488,
                           "The embedded firmwares are blank or empty. setrom.exe was never executed.  See nvuflash.doc for details."
                           ,&local_6b);
                    /* try { // try from 00925807 to 0092580b has its CatchHandler @ 00926222 */
              FUN_00cb95e0(puVar13,&local_488);
              *puVar13 = &PTR_LAB_00d80cc0;
              if (local_488 != &local_478) {
                free(local_488);
              }
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 0092583c to 00925840 has its CatchHandler @ 00925841 */
              FUN_00c379d0(puVar13,&PTR_PTR_00d80c98,&LAB_00705c5e);
            }
            pcVar3 = *(code **)(*plVar10 + 0x50);
                    /* try { // try from 0092578c to 00925790 has its CatchHandler @ 00925856 */
            FUN_00c90a60(&local_488,
                         "This utility will attempt to update the NVIDIA GPU firmware.\n\nIt is recommended that you save open files and close all other applications.\n\nIf power is lost while updating, the graphics card may be damaged.\nDo not turn off your PC during the update.\n\nDo you want to continue?\nPress \'y\' to continue (any other key to abort): "
                         ,&local_6a);
                    /* try { // try from 0092587e to 0092587f has its CatchHandler @ 00926263 */
            cVar4 = (*pcVar3)(plVar10,0,&local_488);
            if (local_488 != &local_478) {
              free(local_488);
            }
            if (cVar4 == '\0') {
              puVar13 = (undefined8 *)FUN_00c37fd0(0x10);
                    /* try { // try from 009258d1 to 009258d5 has its CatchHandler @ 009262c9 */
              FUN_00c90a60(&local_488,"Aborting",&local_69);
                    /* try { // try from 009258e0 to 009258e4 has its CatchHandler @ 00926290 */
              FUN_00cb95e0(puVar13,&local_488);
              *puVar13 = &PTR_LAB_00cda000;
              if (local_488 != &local_478) {
                free(local_488);
              }
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00925915 to 00925919 has its CatchHandler @ 0092591a */
              FUN_00c379d0(puVar13,&PTR_PTR_00cd9fd8,&LAB_00416ac4);
            }
                    /* try { // try from 009258a5 to 009258a7 has its CatchHandler @ 0092594b */
            lVar11 = (**(code **)(*(long *)param_1[2] + 0x40))();
            if (lVar11 == 0) {
              iVar9 = 0;
            }
            else {
                    /* try { // try from 00925946 to 00925948 has its CatchHandler @ 00925960 */
              (**(code **)(*(long *)param_1[2] + 0x38))(&local_488);
              pcVar3 = *(code **)(*param_1 + 0x108);
              local_68 = local_488;
              if (local_488 != (long *)0x0) {
                    /* try { // try from 00925992 to 00925993 has its CatchHandler @ 00926307 */
                (**(code **)*local_488)();
              }
                    /* try { // try from 0092599b to 0092599c has its CatchHandler @ 009262d1 */
              iVar9 = (*pcVar3)(param_1,&local_68);
              if (local_68 != (long *)0x0) {
                (**(code **)(*local_68 + 8))();
              }
              if (local_488 != (long *)0x0) {
                (**(code **)(*local_488 + 8))();
              }
            }
            plVar20 = (long *)param_1[1];
            pcVar3 = *(code **)(*plVar20 + 0x28);
                    /* try { // try from 009259df to 009259e3 has its CatchHandler @ 00926381 */
            FUN_00c90a60(&local_488,"reboot",&local_5c);
                    /* try { // try from 009259fc to 009259fe has its CatchHandler @ 0092630f */
            cVar4 = (*pcVar3)(plVar20,&local_488);
            if (local_488 != &local_478) {
              free(local_488);
            }
            if (cVar4 != '\0') {
                    /* try { // try from 00925a21 to 00925a44 has its CatchHandler @ 00926381 */
              plVar20 = (long *)FUN_00671a5e();
              pcVar3 = *(code **)(*plVar20 + 0x78);
              FUN_00c90a60(&local_488,"System will reset now!",local_5b);
                    /* try { // try from 00925a4f to 00925a51 has its CatchHandler @ 00926336 */
              (*pcVar3)(plVar20,&local_488);
              if (local_488 != &local_478) {
                free(local_488);
              }
                    /* try { // try from 00925a6a to 00925a7e has its CatchHandler @ 00926381 */
              plVar20 = (long *)FUN_0042e510();
              if (plVar20 != (long *)0x0) {
                (**(code **)*plVar20)(plVar20);
              }
                    /* try { // try from 00925a8a to 00925a95 has its CatchHandler @ 0092635d */
              (**(code **)(*plVar20 + 0x18))(plVar20,3000000);
              (**(code **)(*plVar20 + 0x58))(plVar20);
              if (plVar20 != (long *)0x0) {
                (**(code **)(*plVar20 + 8))(plVar20);
              }
            }
          }
          else {
                    /* try { // try from 009252fc to 00925300 has its CatchHandler @ 00925303 */
            FUN_00c5c670(&local_488,0x10);
                    /* try { // try from 00925318 to 0092531c has its CatchHandler @ 00925337 */
            plVar20 = (long *)FUN_0040fa36();
            if (plVar20 != (long *)0x0) {
                    /* try { // try from 00925333 to 00925334 has its CatchHandler @ 00925358 */
              (**(code **)*plVar20)();
            }
            local_4c8 = (undefined8 *)0x0;
            local_4c0 = (undefined8 *)0x0;
            local_4b8[0] = 0;
                    /* try { // try from 009253a4 to 009253a9 has its CatchHandler @ 009253c8 */
            iVar9 = (**(code **)(*param_1 + 0x3a0))(param_1,&local_4c8,1);
                    /* try { // try from 009253c1 to 009253c5 has its CatchHandler @ 009261f3 */
            FUN_00c440d0(&local_488,"BIOS Versions of NVIDIA display adapters present in system:",
                         0x3b);
                    /* try { // try from 00925406 to 0092540a has its CatchHandler @ 009261f3 */
            FUN_00c43ef0(&local_488);
            if (local_4c0 != local_4c8) {
              local_500 = 0;
              do {
                plVar19 = (long *)local_4c8[local_500];
                if (plVar19 == (long *)0x0) {
                  local_510 = *(code **)(*plVar18 + 0x30);
                  local_b0 = (long *)0x0;
                }
                else {
                    /* try { // try from 009256ba to 009256e2 has its CatchHandler @ 009261f3 */
                  (**(code **)*plVar19)(plVar19);
                  local_510 = *(code **)(*plVar18 + 0x30);
                    /* try { // try from 0092544c to 0092544d has its CatchHandler @ 009261a4 */
                  local_b0 = plVar19;
                  (**(code **)*plVar19)(plVar19);
                }
                    /* try { // try from 00926738 to 00926739 has its CatchHandler @ 009260c2 */
                (*local_510)(plVar18,&local_b0,lVar11,1);
                if (local_b0 != (long *)0x0) {
                  (**(code **)(*local_b0 + 8))();
                }
                if (0xf < (ulong)((long)local_4c0 - (long)local_4c8)) {
                    /* try { // try from 0092548a to 0092550c has its CatchHandler @ 009261bd */
                  FUN_00c440d0(&local_488,&DAT_00dab730,1);
                  uVar15 = FUN_00c44830(&local_488,local_500);
                  FUN_00c444f0(uVar15,"> ");
                }
                pcVar3 = *(code **)(*plVar18 + 0x230);
                uVar21 = (long)local_4c0 - (long)local_4c8;
                uVar7 = (**(code **)(*param_1 + 0x40))(param_1);
                local_a8 = plVar12;
                if (plVar12 != (long *)0x0) {
                  (**(code **)*plVar12)();
                }
                local_a0 = plVar17;
                if (plVar17 != (long *)0x0) {
                    /* try { // try from 0092551f to 00925520 has its CatchHandler @ 00926198 */
                  (**(code **)*plVar17)(plVar17);
                }
                local_98 = plVar16;
                if (plVar16 != (long *)0x0) {
                    /* try { // try from 00925537 to 00925538 has its CatchHandler @ 0092618c */
                  (**(code **)*plVar16)();
                }
                local_90 = plVar19;
                if (plVar19 != (long *)0x0) {
                    /* try { // try from 0092554c to 0092554d has its CatchHandler @ 00926180 */
                  (**(code **)*plVar19)(plVar19);
                }
                local_88 = plVar20;
                if (plVar20 != (long *)0x0) {
                    /* try { // try from 00925561 to 00925562 has its CatchHandler @ 00926174 */
                  (**(code **)*plVar20)();
                }
                local_80 = plVar10;
                if (plVar10 != (long *)0x0) {
                    /* try { // try from 00925576 to 00925577 has its CatchHandler @ 00926168 */
                  (**(code **)*plVar10)();
                }
                    /* try { // try from 009255c0 to 009255c1 has its CatchHandler @ 009260f3 */
                (*pcVar3)(plVar18,&local_80,&local_88,&local_90,&local_98,&local_a0,&local_a8,
                          &local_488,uVar7,lVar11,0xf < uVar21,0);
                if (local_80 != (long *)0x0) {
                  (**(code **)(*local_80 + 8))();
                }
                if (local_88 != (long *)0x0) {
                  (**(code **)(*local_88 + 8))();
                }
                if (local_90 != (long *)0x0) {
                  (**(code **)(*local_90 + 8))();
                }
                if (local_98 != (long *)0x0) {
                  (**(code **)(*local_98 + 8))();
                }
                if (local_a0 != (long *)0x0) {
                  (**(code **)(*local_a0 + 8))();
                }
                if (local_a8 != (long *)0x0) {
                  (**(code **)(*local_a8 + 8))();
                }
                    /* try { // try from 00925633 to 00925666 has its CatchHandler @ 009261bd */
                FUN_00c43ef0(&local_488);
                (**(code **)(*plVar18 + 0x38))
                          (plVar18,((long)local_4c0 - (long)local_4c8 >> 3) - 1U == local_500);
                if (plVar19 != (long *)0x0) {
                  (**(code **)(*plVar19 + 8))(plVar19);
                }
                local_500 = local_500 + 1;
              } while (local_500 < (ulong)((long)local_4c0 - (long)local_4c8 >> 3));
            }
            plVar19 = (long *)FUN_00671a5e();
            pcVar3 = *(code **)(*plVar19 + 0x78);
            FUN_00c59d00(&local_4a8,&local_480);
                    /* try { // try from 009256ed to 009256ef has its CatchHandler @ 009261cc */
            (*pcVar3)(plVar19,&local_4a8);
            if (local_4a8 != local_498) {
              free(local_4a8);
            }
            FUN_0085c8ec(&local_4c8);
            if (plVar20 != (long *)0x0) {
              (**(code **)(*plVar20 + 8))();
            }
            FUN_00c59440(&local_488);
          }
        }
        else {
                    /* try { // try from 00925237 to 0092523c has its CatchHandler @ 00925242 */
          (**(code **)(*param_1 + 0x428))(param_1);
          iVar9 = 0;
        }
      }
      else {
                    /* try { // try from 0092519c to 009251a1 has its CatchHandler @ 009251a7 */
        (**(code **)(*param_1 + 0x400))(param_1);
        iVar9 = 0;
      }
    }
    else {
                    /* try { // try from 009250eb to 009250f0 has its CatchHandler @ 009250f6 */
      (**(code **)(*param_1 + 0x408))(param_1);
      iVar9 = 0;
    }
    if (plVar18 != (long *)0x0) {
      (**(code **)(*plVar18 + 8))(plVar18);
    }
    if (plVar17 != (long *)0x0) {
      (**(code **)(*plVar17 + 8))(plVar17);
    }
    if (plVar16 != (long *)0x0) {
      (**(code **)(*plVar16 + 8))();
    }
    if (plVar12 != (long *)0x0) {
      (**(code **)(*plVar12 + 8))();
    }
    plVar12 = (long *)param_1[0x11];
    if (plVar12 != (long *)param_1[0x12]) {
      uVar21 = (ulong)(param_1[0x12] - ((long)plVar12 + 100)) >> 2;
      local_4d0 = plVar12;
      do {
        lVar11 = local_4d0[10];
        for (lVar14 = local_4d0[9]; lVar11 != lVar14; lVar14 = lVar14 + 0x10) {
          if (*(long **)(lVar14 + 8) != (long *)0x0) {
            (**(code **)(**(long **)(lVar14 + 8) + 8))();
          }
        }
        if ((void *)local_4d0[9] != (void *)0x0) {
          free((void *)local_4d0[9]);
        }
        puVar13 = (undefined8 *)local_4d0[7];
        for (puVar22 = (undefined8 *)local_4d0[6]; puVar13 != puVar22; puVar22 = puVar22 + 4) {
          *puVar22 = &DAT_00d43b90;
          FUN_0052b0c0(puVar22 + 1);
        }
        if ((void *)local_4d0[6] != (void *)0x0) {
          free((void *)local_4d0[6]);
        }
        plVar16 = (long *)local_4d0[5];
        if (plVar16 != (long *)0x0) {
          LOCK();
          plVar17 = plVar16 + 1;
          lVar11 = *plVar17;
          *(int *)plVar17 = (int)*plVar17 + -1;
          UNLOCK();
          if ((int)lVar11 == 1) {
            (**(code **)(*plVar16 + 0x10))(plVar16);
            LOCK();
            piVar1 = (int *)((long)plVar16 + 0xc);
            iVar2 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
            if (iVar2 == 1) {
              (**(code **)(*plVar16 + 0x18))(plVar16);
            }
          }
        }
        if ((long *)local_4d0[3] != (long *)0x0) {
          (**(code **)(*(long *)local_4d0[3] + 8))();
        }
        if ((long *)local_4d0[2] != (long *)0x0) {
          (**(code **)(*(long *)local_4d0[2] + 8))();
        }
        if ((long *)*local_4d0 != (long *)0x0) {
          (**(code **)(*(long *)*local_4d0 + 8))();
        }
        local_4d0 = (long *)((long)local_4d0 + 100);
      } while (local_4d0 !=
               (long *)((long)plVar12 +
                       ((uVar21 * 0xf5c28f5c28f5c29 & 0x3fffffffffffffff) + 5 +
                       uVar21 * 0x3d70a3d70a3d70a4) * 0x14));
    }
    param_1[0x12] = (long)plVar12;
                    /* try { // try from 00925cbc to 00925cfb has its CatchHandler @ 00924b8a */
    lVar11 = FUN_00c7f620(local_2d8 + 1);
    if (lVar11 == 0) {
      FUN_00cbee70((undefined *)((long)local_2d8 + (long)local_2d8[0][-3]),
                   *(uint *)((long)auStack_2b8 + (long)local_2d8[0][-3]) | 4);
    }
    uVar15 = FUN_00443500();
    FUN_004431be(local_308,uVar15);
    iVar2 = iVar9;
    if ((iVar9 != 0) && (iVar2 = local_308[0] + 0x100000, local_308[0] == 0)) {
      iVar2 = iVar9;
    }
    if (local_4e1 != 0) {
                    /* try { // try from 00925d40 to 00925d74 has its CatchHandler @ 009266ba */
      plVar12 = (long *)FUN_0042e510();
      (**(code **)(*plVar12 + 0x158))(plVar12);
      plVar12 = (long *)FUN_00671a5e();
      pcVar3 = *(code **)(*plVar12 + 0x50);
      FUN_00c90a60(&local_488,"\nPress any key to exit...",local_39);
                    /* try { // try from 00925d84 to 00925d86 has its CatchHandler @ 0092667e */
      (*pcVar3)(plVar12,0,&local_488);
      if (local_488 != &local_478) {
        free(local_488);
      }
    }
    if (local_300 != local_2f0) {
      free(local_300);
    }
  }
  else {
                    /* try { // try from 00924c1d to 00924c21 has its CatchHandler @ 00924c6a */
    plVar12 = (long *)FUN_00671a5e();
    pcVar3 = *(code **)(*plVar12 + 0x78);
    local_488 = &local_478;
                    /* try { // try from 00924c63 to 00924c67 has its CatchHandler @ 00924c8c */
    FUN_0040eb78(&local_488,"Unknown command\n","");
                    /* try { // try from 00924c87 to 00924c89 has its CatchHandler @ 00925f55 */
    (*pcVar3)(plVar12,&local_488);
    if (local_488 != &local_478) {
      free(local_488);
    }
                    /* try { // try from 00924cb9 to 00924cbe has its CatchHandler @ 00924cc4 */
    (**(code **)(*param_1 + 0x408))(param_1);
    iVar2 = 5;
  }
  local_2d8[0] = &PTR_FUN_01229a60;
  local_1e0[0] = &PTR_LAB_01229a88;
  local_2d8[1] = &PTR_FUN_012298a8;
  FUN_00c7f620(local_2d8 + 1);
  thunk_FUN_00c399f0(local_268);
  local_2d8[1] = &PTR_LAB_0122c610;
  FUN_00c3f070(local_298);
  local_2d8[0] = (undefined **)PTR_DAT_01229a30;
  *(undefined **)((long)local_2d8 + *(long *)(PTR_DAT_01229a30 + -0x18)) = PTR_DAT_01229a38;
  local_1e0[0] = &PTR_LAB_0122c740;
  FUN_00c65110(local_1e0);
  if (local_d8 != local_c8) {
    free(local_d8);
  }
  if (plVar10 != (long *)0x0) {
    (**(code **)(*plVar10 + 8))();
  }
  return iVar2;
}

