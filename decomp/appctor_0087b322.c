// app/parser ctor; entry 0087b322


/* WARNING: Removing unreachable block (ram,0x0087b54c) */
/* WARNING: Removing unreachable block (ram,0x0087b555) */
/* WARNING: Removing unreachable block (ram,0x0087b563) */
/* WARNING: Removing unreachable block (ram,0x0087b568) */
/* WARNING: Removing unreachable block (ram,0x0087b74b) */

void FUN_0087b322(undefined8 *param_1,undefined4 param_2,undefined8 param_3)

{
  char *pcVar1;
  ushort uVar2;
  code *pcVar3;
  long *plVar4;
  undefined8 *puVar5;
  long *plVar6;
  char cVar7;
  undefined8 *puVar8;
  long lVar9;
  undefined8 **ppuVar10;
  long lVar11;
  long *plVar12;
  undefined8 ***pppuVar13;
  char cVar14;
  ulong uVar15;
  char *pcVar16;
  uint uVar17;
  int iVar18;
  long lVar19;
  undefined8 ***pppuVar20;
  byte bVar21;
  char acStack_2aa [8];
  undefined1 local_2a2;
  char acStack_2a1 [8];
  undefined1 local_299;
  undefined8 *local_298;
  undefined8 *local_290;
  undefined8 local_288;
  undefined8 local_278;
  long *local_270;
  long *local_268;
  undefined8 **local_258;
  undefined *local_250;
  undefined8 *local_248;
  undefined8 ****local_240;
  undefined8 ****local_238;
  long local_230;
  undefined4 local_228 [2];
  long *local_220;
  undefined8 **local_218;
  undefined8 **local_210;
  undefined8 *local_1f8;
  undefined8 *local_1f0;
  undefined8 *local_1d8;
  undefined8 *local_1d0;
  undefined8 *local_1b8;
  undefined8 *local_1b0;
  undefined8 *local_198;
  undefined8 *local_190;
  undefined8 *local_178;
  undefined8 *local_170;
  undefined8 *local_158;
  undefined8 *local_150;
  undefined8 *local_138;
  undefined8 *local_130;
  undefined8 *local_118;
  undefined8 *local_110;
  undefined8 *local_f8;
  undefined8 *local_f0;
  undefined8 *local_d8;
  undefined8 *local_d0;
  undefined8 *local_b8;
  undefined8 *local_b0;
  undefined8 *local_98;
  undefined8 *local_90;
  undefined8 *local_78;
  undefined8 *local_70;
  undefined8 *local_58;
  undefined8 *local_50;
  
  bVar21 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  *(undefined4 *)(param_1 + 7) = 0;
  *(undefined4 *)((long)param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined1 *)((long)param_1 + 0x49) = 0;
  *(undefined1 *)((long)param_1 + 0x4a) = 0;
  *(undefined1 *)((long)param_1 + 0x4c) = 1;
  *(undefined1 *)((long)param_1 + 0x4d) = 0;
  *(undefined4 *)((long)param_1 + 0x44) = 3;
  *(undefined1 *)(param_1 + 9) = 1;
  *(undefined1 *)((long)param_1 + 0x4b) = 1;
  *(undefined1 *)((long)param_1 + 0x4e) = 1;
  *param_1 = &PTR_FUN_00db0ac8;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
                    /* try { // try from 0087b466 to 0087b4c1 has its CatchHandler @ 0087cda8 */
  puVar8 = (undefined8 *)FUN_0057b778(0xb,&PTR_s_help_00da0f2a_0x10_06778680,param_2,param_3,0);
  if ((long *)param_1[1] != (long *)0x0) {
    (**(code **)(*(long *)param_1[1] + 8))();
    param_1[1] = 0;
  }
  if (puVar8 != (undefined8 *)0x0) {
    (**(code **)*puVar8)(puVar8);
  }
  param_1[1] = puVar8;
  puVar8 = (undefined8 *)FUN_0058ca5a();
  if ((long *)param_1[2] != (long *)0x0) {
    (**(code **)(*(long *)param_1[2] + 8))();
    param_1[2] = 0;
  }
  if (puVar8 != (undefined8 *)0x0) {
    (**(code **)*puVar8)(puVar8);
  }
  param_1[2] = puVar8;
  DAT_067c1ee0 = 1;
  lVar9 = param_1[0xe];
  lVar11 = param_1[0xf];
  if (lVar9 != lVar11) {
    lVar19 = lVar9;
    do {
      if (*(long **)(lVar19 + 0x38) != (long *)0x0) {
        (**(code **)(**(long **)(lVar19 + 0x38) + 8))();
      }
      *(undefined8 **)(lVar19 + 0x10) = &DAT_00d43b90;
      FUN_0052b0c0(lVar19 + 0x18);
      lVar19 = lVar19 + 0x40;
    } while (lVar19 != lVar11);
  }
  param_1[0xf] = lVar9;
  *(undefined1 *)(param_1 + 0x1a) = 0;
  if (0 < DAT_01777f94) {
    iVar18 = 0;
    do {
      lVar9 = (long)iVar18 * 0x1400094;
      ppuVar10 = (undefined8 **)(&DAT_01777fa0 + lVar9);
      if (((((&DAT_01777fff)[lVar9] != '\0') || ((&DAT_01778000)[(long)iVar18 * 0x500025] != -1)) ||
          (*(int *)(&DAT_01778008 + lVar9) != 0)) || (*(int *)(&DAT_01778004 + lVar9) == 0)) {
        local_248 = &DAT_00d43b90;
        local_230 = 0;
        local_240 = &local_240;
        local_220 = (long *)0x0;
        local_250 = &DAT_01778034 + lVar9;
        puVar8 = (undefined8 *)param_1[0xf];
        local_258 = ppuVar10;
        local_238 = local_240;
        if (puVar8 == (undefined8 *)param_1[0x10]) {
                    /* try { // try from 0087b76a to 0087b76e has its CatchHandler @ 0087b774 */
          FUN_008615a6(param_1 + 0xe,puVar8,&local_258);
        }
        else {
          if (puVar8 != (undefined8 *)0x0) {
            *puVar8 = ppuVar10;
            puVar8[1] = local_250;
            puVar8[2] = &DAT_00d43b90;
            puVar8[5] = 0;
            puVar8[3] = puVar8 + 3;
            puVar8[4] = puVar8 + 3;
            *(undefined4 *)(puVar8 + 6) = local_228[0];
            puVar8[7] = 0;
          }
          local_220 = (long *)0x0;
          local_230 = 0;
          local_248 = &DAT_00d43b90;
          param_1[0xf] = param_1[0xf] + 0x40;
        }
        if (local_220 != (long *)0x0) {
          (**(code **)(*local_220 + 8))();
        }
        local_248 = &DAT_00d43b90;
        FUN_0052b0c0(&local_240);
      }
      iVar18 = iVar18 + 1;
    } while (iVar18 < DAT_01777f94);
  }
  local_298 = (undefined8 *)0x0;
  local_290 = (undefined8 *)0x0;
  local_288 = 0;
  if ((DAT_01777fb6 & 8) != 0) {
    plVar12 = (long *)param_1[1];
    pcVar3 = *(code **)(*plVar12 + 0xa0);
    FUN_0086eb06(&local_218,&local_298);
    local_258 = &local_248;
                    /* try { // try from 0087b823 to 0087b827 has its CatchHandler @ 0087ca83 */
    FUN_0040eb78(&local_258,"overridesub","");
                    /* try { // try from 0087b83d to 0087b83f has its CatchHandler @ 0087ca51 */
    (*pcVar3)(plVar12,&local_258,&local_218);
    ppuVar10 = local_218;
    if (local_258 != &local_248) {
      free(local_258);
      ppuVar10 = local_218;
    }
    for (; local_210 != ppuVar10; ppuVar10 = ppuVar10 + 4) {
      if ((undefined8 **)*ppuVar10 != ppuVar10 + 2) {
        free(*ppuVar10);
      }
    }
    if (local_218 != (undefined8 **)0x0) {
      free(local_218);
    }
  }
  if ((DAT_01777fb6 & 0x20) == 0) {
    plVar12 = (long *)param_1[1];
    pcVar3 = *(code **)(*plVar12 + 0x28);
    local_258 = &local_248;
                    /* try { // try from 0087b8e1 to 0087b8e5 has its CatchHandler @ 0087cda0 */
    FUN_0040eb78(&local_258,"noconsolechk","");
                    /* try { // try from 0087b8f4 to 0087b8f6 has its CatchHandler @ 0087ca88 */
    cVar7 = (*pcVar3)(plVar12,&local_258);
    if (local_258 != &local_248) {
      free(local_258);
    }
    if (cVar7 != '\0') goto LAB_0087b7b3;
  }
  else {
LAB_0087b7b3:
    plVar12 = (long *)param_1[1];
    pcVar3 = *(code **)(*plVar12 + 0xa0);
                    /* try { // try from 0087b7cf to 0087b7f9 has its CatchHandler @ 0087cda0 */
    FUN_0086eb06(&local_1f8,&local_298);
    local_258 = &local_248;
                    /* try { // try from 0087b9fb to 0087b9ff has its CatchHandler @ 0087cad7 */
    FUN_0040eb78(&local_258,"noconfirm","");
                    /* try { // try from 0087ba15 to 0087ba17 has its CatchHandler @ 0087caab */
    (*pcVar3)(plVar12,&local_258,&local_1f8);
    puVar8 = local_1f8;
    if (local_258 != &local_248) {
      free(local_258);
      puVar8 = local_1f8;
    }
    for (; local_1f0 != puVar8; puVar8 = puVar8 + 4) {
      if ((undefined8 *)*puVar8 != puVar8 + 2) {
        free((undefined8 *)*puVar8);
      }
    }
    if (local_1f8 != (undefined8 *)0x0) {
      free(local_1f8);
    }
    plVar12 = (long *)param_1[1];
    pcVar3 = *(code **)(*plVar12 + 0xa0);
                    /* try { // try from 0087ba73 to 0087ba77 has its CatchHandler @ 0087cda0 */
    FUN_0086eb06(&local_1d8,&local_298);
    local_258 = &local_248;
                    /* try { // try from 0087bac8 to 0087bacc has its CatchHandler @ 0087cb0b */
    FUN_0040eb78(&local_258,&DAT_00d492c3,&DAT_00d492c7);
                    /* try { // try from 0087bae2 to 0087bae4 has its CatchHandler @ 0087cadc */
    (*pcVar3)(plVar12,&local_258,&local_1d8);
    puVar8 = local_1d8;
    if (local_258 != &local_248) {
      free(local_258);
      puVar8 = local_1d8;
    }
    for (; local_1d0 != puVar8; puVar8 = puVar8 + 4) {
      if ((undefined8 *)*puVar8 != puVar8 + 2) {
        free((undefined8 *)*puVar8);
      }
    }
    if (local_1d8 != (undefined8 *)0x0) {
      free(local_1d8);
    }
  }
  if ((DAT_01777fb6 & 0x80) != 0) {
    plVar12 = (long *)param_1[1];
    pcVar3 = *(code **)(*plVar12 + 0xa0);
                    /* try { // try from 0087bb6e to 0087bb72 has its CatchHandler @ 0087cda0 */
    FUN_0086eb06(&local_1b8,&local_298);
    local_258 = &local_248;
                    /* try { // try from 0087bb9c to 0087bba0 has its CatchHandler @ 0087cb3c */
    FUN_0040eb78(&local_258,"upgradeonly","");
                    /* try { // try from 0087bbb6 to 0087bbb8 has its CatchHandler @ 0087cb10 */
    (*pcVar3)(plVar12,&local_258,&local_1b8);
    puVar8 = local_1b8;
    if (local_258 != &local_248) {
      free(local_258);
      puVar8 = local_1b8;
    }
    for (; local_1b0 != puVar8; puVar8 = puVar8 + 4) {
      if ((undefined8 *)*puVar8 != puVar8 + 2) {
        free((undefined8 *)*puVar8);
      }
    }
    if (local_1b8 != (undefined8 *)0x0) {
      free(local_1b8);
    }
  }
  if ((DAT_01777fb8 & 1) != 0) {
    plVar12 = (long *)param_1[1];
    pcVar3 = *(code **)(*plVar12 + 0xa0);
                    /* try { // try from 0087bc42 to 0087bc46 has its CatchHandler @ 0087cda0 */
    FUN_0086eb06(&local_198,&local_298);
    local_258 = &local_248;
                    /* try { // try from 0087bc70 to 0087bc74 has its CatchHandler @ 0087cb70 */
    FUN_0040eb78(&local_258,"offrfwupdate","");
                    /* try { // try from 0087bc8a to 0087bc8c has its CatchHandler @ 0087cb41 */
    (*pcVar3)(plVar12,&local_258,&local_198);
    puVar8 = local_198;
    if (local_258 != &local_248) {
      free(local_258);
      puVar8 = local_198;
    }
    for (; local_190 != puVar8; puVar8 = puVar8 + 4) {
      if ((undefined8 *)*puVar8 != puVar8 + 2) {
        free((undefined8 *)*puVar8);
      }
    }
    if (local_198 != (undefined8 *)0x0) {
      free(local_198);
    }
  }
  if ((DAT_01777fb7 & 0x20) != 0) {
    plVar12 = (long *)param_1[1];
    pcVar3 = *(code **)(*plVar12 + 0xa0);
                    /* try { // try from 0087bd16 to 0087bd1a has its CatchHandler @ 0087cda0 */
    FUN_0086eb06(&local_178,&local_298);
    local_258 = &local_248;
                    /* try { // try from 0087bd44 to 0087bd48 has its CatchHandler @ 0087cba1 */
    FUN_0040eb78(&local_258,"nodowngrade","");
                    /* try { // try from 0087bd5e to 0087bd60 has its CatchHandler @ 0087cb75 */
    (*pcVar3)(plVar12,&local_258,&local_178);
    puVar8 = local_178;
    if (local_258 != &local_248) {
      free(local_258);
      puVar8 = local_178;
    }
    for (; local_170 != puVar8; puVar8 = puVar8 + 4) {
      if ((undefined8 *)*puVar8 != puVar8 + 2) {
        free((undefined8 *)*puVar8);
      }
    }
    if (local_178 != (undefined8 *)0x0) {
      free(local_178);
    }
  }
  if ((DAT_01777fb7 & 0x80) != 0) {
    plVar12 = (long *)param_1[1];
    pcVar3 = *(code **)(*plVar12 + 0xa0);
                    /* try { // try from 0087bdea to 0087bdee has its CatchHandler @ 0087cda0 */
    FUN_0086eb06(&local_158,&local_298);
    local_258 = &local_248;
                    /* try { // try from 0087be18 to 0087be1c has its CatchHandler @ 0087cbd5 */
    FUN_0040eb78(&local_258,"updatexusb","");
                    /* try { // try from 0087be32 to 0087be34 has its CatchHandler @ 0087cba6 */
    (*pcVar3)(plVar12,&local_258,&local_158);
    puVar8 = local_158;
    if (local_258 != &local_248) {
      free(local_258);
      puVar8 = local_158;
    }
    for (; local_150 != puVar8; puVar8 = puVar8 + 4) {
      if ((undefined8 *)*puVar8 != puVar8 + 2) {
        free((undefined8 *)*puVar8);
      }
    }
    if (local_158 != (undefined8 *)0x0) {
      free(local_158);
    }
  }
  if ((DAT_01777fb6 & 0x10) != 0) {
    plVar12 = (long *)param_1[1];
    pcVar3 = *(code **)(*plVar12 + 0xa0);
                    /* try { // try from 0087bebe to 0087bec2 has its CatchHandler @ 0087cda0 */
    FUN_0086eb06(&local_138,&local_298);
    local_258 = &local_248;
                    /* try { // try from 0087beec to 0087bef0 has its CatchHandler @ 0087cc06 */
    FUN_0040eb78(&local_258,"silence","");
                    /* try { // try from 0087bf06 to 0087bf08 has its CatchHandler @ 0087cbda */
    (*pcVar3)(plVar12,&local_258,&local_138);
    puVar8 = local_138;
    if (local_258 != &local_248) {
      free(local_258);
      puVar8 = local_138;
    }
    for (; local_130 != puVar8; puVar8 = puVar8 + 4) {
      if ((undefined8 *)*puVar8 != puVar8 + 2) {
        free((undefined8 *)*puVar8);
      }
    }
    if (local_138 != (undefined8 *)0x0) {
      free(local_138);
    }
  }
  if ((DAT_01777fb7 & 4) != 0) {
    plVar12 = (long *)param_1[1];
    pcVar3 = *(code **)(*plVar12 + 0xa0);
                    /* try { // try from 0087bf92 to 0087bf96 has its CatchHandler @ 0087cda0 */
    FUN_0086eb06(&local_118,&local_298);
    local_258 = &local_248;
                    /* try { // try from 0087bfc0 to 0087bfc4 has its CatchHandler @ 0087cc3a */
    FUN_0040eb78(&local_258,"reboot","");
                    /* try { // try from 0087bfda to 0087bfdc has its CatchHandler @ 0087cc0b */
    (*pcVar3)(plVar12,&local_258,&local_118);
    puVar8 = local_118;
    if (local_258 != &local_248) {
      free(local_258);
      puVar8 = local_118;
    }
    for (; local_110 != puVar8; puVar8 = puVar8 + 4) {
      if ((undefined8 *)*puVar8 != puVar8 + 2) {
        free((undefined8 *)*puVar8);
      }
    }
    if (local_118 != (undefined8 *)0x0) {
      free(local_118);
    }
  }
  if ((DAT_01777fb7 & 8) != 0) {
    plVar12 = (long *)param_1[1];
    pcVar3 = *(code **)(*plVar12 + 0xa0);
                    /* try { // try from 0087c066 to 0087c06a has its CatchHandler @ 0087cda0 */
    FUN_0086eb06(&local_f8,&local_298);
    local_258 = &local_248;
                    /* try { // try from 0087c094 to 0087c098 has its CatchHandler @ 0087cc6b */
    FUN_0040eb78(&local_258,"vercmp5part","");
                    /* try { // try from 0087c0ae to 0087c0b0 has its CatchHandler @ 0087cc3f */
    (*pcVar3)(plVar12,&local_258,&local_f8);
    puVar8 = local_f8;
    if (local_258 != &local_248) {
      free(local_258);
      puVar8 = local_f8;
    }
    for (; local_f0 != puVar8; puVar8 = puVar8 + 4) {
      if ((undefined8 *)*puVar8 != puVar8 + 2) {
        free((undefined8 *)*puVar8);
      }
    }
    if (local_f8 != (undefined8 *)0x0) {
      free(local_f8);
    }
  }
  if ((DAT_01777fb6 & 0x40) != 0) {
    plVar12 = (long *)param_1[1];
    pcVar3 = *(code **)(*plVar12 + 0xa0);
                    /* try { // try from 0087c13a to 0087c13e has its CatchHandler @ 0087cda0 */
    FUN_0086eb06(&local_d8,&local_298);
    local_258 = &local_248;
                    /* try { // try from 0087c168 to 0087c16c has its CatchHandler @ 0087cc9f */
    FUN_0040eb78(&local_258,"protectoff","");
                    /* try { // try from 0087c182 to 0087c184 has its CatchHandler @ 0087cc70 */
    (*pcVar3)(plVar12,&local_258,&local_d8);
    puVar8 = local_d8;
    if (local_258 != &local_248) {
      free(local_258);
      puVar8 = local_d8;
    }
    for (; local_d0 != puVar8; puVar8 = puVar8 + 4) {
      if ((undefined8 *)*puVar8 != puVar8 + 2) {
        free((undefined8 *)*puVar8);
      }
    }
    if (local_d8 != (undefined8 *)0x0) {
      free(local_d8);
    }
  }
  if ((DAT_01777fb8 & 8) != 0) {
    plVar12 = (long *)param_1[1];
    pcVar3 = *(code **)(*plVar12 + 0xa0);
                    /* try { // try from 0087c20e to 0087c212 has its CatchHandler @ 0087cda0 */
    FUN_0086eb06(&local_b8,&local_298);
    local_258 = &local_248;
                    /* try { // try from 0087c23c to 0087c240 has its CatchHandler @ 0087ccd0 */
    FUN_0040eb78(&local_258,"reset_after_update","");
                    /* try { // try from 0087c256 to 0087c258 has its CatchHandler @ 0087cca4 */
    (*pcVar3)(plVar12,&local_258,&local_b8);
    puVar8 = local_b8;
    if (local_258 != &local_248) {
      free(local_258);
      puVar8 = local_b8;
    }
    for (; local_b0 != puVar8; puVar8 = puVar8 + 4) {
      if ((undefined8 *)*puVar8 != puVar8 + 2) {
        free((undefined8 *)*puVar8);
      }
    }
    if (local_b8 != (undefined8 *)0x0) {
      free(local_b8);
    }
  }
  if ((DAT_01777fb8 & 0x10) != 0) {
    plVar12 = (long *)param_1[1];
    pcVar3 = *(code **)(*plVar12 + 0xa0);
                    /* try { // try from 0087c2e2 to 0087c2e6 has its CatchHandler @ 0087cda0 */
    FUN_0086eb06(&local_98,&local_298);
    local_258 = &local_248;
                    /* try { // try from 0087c310 to 0087c314 has its CatchHandler @ 0087cd04 */
    FUN_0040eb78(&local_258,"unload_preos","");
                    /* try { // try from 0087c32a to 0087c32c has its CatchHandler @ 0087ccd5 */
    (*pcVar3)(plVar12,&local_258,&local_98);
    puVar8 = local_98;
    if (local_258 != &local_248) {
      free(local_258);
      puVar8 = local_98;
    }
    for (; local_90 != puVar8; puVar8 = puVar8 + 4) {
      if ((undefined8 *)*puVar8 != puVar8 + 2) {
        free((undefined8 *)*puVar8);
      }
    }
    if (local_98 != (undefined8 *)0x0) {
      free(local_98);
    }
  }
  if ((long *)param_1[0xe] == (long *)param_1[0xf]) goto LAB_0087b9c5;
  uVar2 = *(ushort *)(*(long *)param_1[0xe] + 0x1b);
  if (uVar2 != 0xffff) {
    uVar17 = (uint)uVar2;
    local_2a2 = 0;
    iVar18 = 4;
    lVar9 = 6;
    do {
      lVar11 = lVar9;
      cVar7 = (char)(uVar17 & 0xf);
      cVar14 = cVar7 + '0';
      if (9 < (uVar17 & 0xf)) {
        cVar14 = cVar7 + '7';
      }
      acStack_2aa[lVar11 + 1] = cVar14;
      iVar18 = iVar18 + -1;
      uVar17 = uVar17 >> 4;
      lVar9 = lVar11 + -1;
    } while ((0 < iVar18) || (uVar17 != 0));
    lVar9 = (long)(int)lVar11;
    pcVar1 = acStack_2aa + lVar9 + 1;
    local_258 = &local_248;
    if (pcVar1 == (char *)0x0) {
      pcVar16 = acStack_2aa + lVar9;
    }
    else {
      uVar15 = 0xffffffffffffffff;
      pcVar16 = pcVar1;
      do {
        if (uVar15 == 0) break;
        uVar15 = uVar15 - 1;
        cVar7 = *pcVar16;
        pcVar16 = pcVar16 + (ulong)bVar21 * -2 + 1;
      } while (cVar7 != '\0');
      pcVar16 = acStack_2aa + ~uVar15 + lVar9;
    }
                    /* try { // try from 0087c423 to 0087c427 has its CatchHandler @ 0087cda0 */
    FUN_0040eb78(&local_258,pcVar1,pcVar16);
    local_278 = (long *)0x0;
    local_270 = (long *)0x0;
    local_268 = (long *)0x0;
                    /* try { // try from 0087c45e to 0087c462 has its CatchHandler @ 0087c537 */
    local_278 = (long *)FUN_00c37a70(0x20);
    plVar12 = local_278 + 4;
    local_268 = plVar12;
    if (local_278 != (long *)0x0) {
      *local_278 = (long)(local_278 + 2);
                    /* try { // try from 0087c49e to 0087c4a2 has its CatchHandler @ 0087c4e6 */
      FUN_0040ecb6(local_278,local_258,(undefined *)((long)local_258 + (long)local_250));
    }
    local_270 = plVar12;
    if (local_258 != &local_248) {
      free(local_258);
    }
    plVar12 = (long *)param_1[1];
    pcVar3 = *(code **)(*plVar12 + 0xa0);
                    /* try { // try from 0087c4df to 0087c4e3 has its CatchHandler @ 0087cd53 */
    FUN_0086eb06(&local_78,&local_278);
    local_258 = &local_248;
                    /* try { // try from 0087c565 to 0087c569 has its CatchHandler @ 0087cd4e */
    FUN_0040eb78(&local_258,"forceboard","");
                    /* try { // try from 0087c57c to 0087c57e has its CatchHandler @ 0087cd13 */
    (*pcVar3)(plVar12,&local_258,&local_78);
    puVar8 = local_78;
    if (local_258 != &local_248) {
      free(local_258);
      puVar8 = local_78;
    }
    for (; local_70 != puVar8; puVar8 = puVar8 + 4) {
      if ((undefined8 *)*puVar8 != puVar8 + 2) {
        free((undefined8 *)*puVar8);
      }
    }
    plVar12 = local_278;
    plVar4 = local_270;
    if (local_78 != (undefined8 *)0x0) {
      free(local_78);
      plVar12 = local_278;
      plVar4 = local_270;
    }
    for (; plVar6 = local_270, local_270 != plVar12; plVar12 = plVar12 + 4) {
      local_270 = plVar4;
      if ((long *)*plVar12 != plVar12 + 2) {
        free((long *)*plVar12);
      }
      plVar4 = local_270;
      local_270 = plVar6;
    }
    local_270 = plVar4;
    if (local_278 != (long *)0x0) {
      free(local_278);
    }
  }
  if ((DAT_01777fb8 & 2) == 0) goto LAB_0087b9c5;
  uVar2 = *(ushort *)(*(long *)param_1[0xe] + 0x14);
  uVar17 = (uint)*(ushort *)(*(long *)param_1[0xe] + 0x12);
  local_299 = 0;
  iVar18 = 4;
  lVar9 = 6;
  do {
    lVar11 = lVar9;
    cVar7 = (char)(uVar17 & 0xf);
    cVar14 = cVar7 + '0';
    if (9 < (uVar17 & 0xf)) {
      cVar14 = cVar7 + '7';
    }
    acStack_2a1[lVar11 + 1] = cVar14;
    iVar18 = iVar18 + -1;
    uVar17 = uVar17 >> 4;
    lVar9 = lVar11 + -1;
  } while ((0 < iVar18) || (uVar17 != 0));
  lVar9 = (long)(int)lVar11;
  pcVar1 = acStack_2a1 + lVar9 + 1;
  local_258 = &local_248;
  if (pcVar1 == (char *)0x0) {
    pcVar16 = acStack_2a1 + lVar9;
  }
  else {
    uVar15 = 0xffffffffffffffff;
    pcVar16 = pcVar1;
    do {
      if (uVar15 == 0) break;
      uVar15 = uVar15 - 1;
      cVar7 = *pcVar16;
      pcVar16 = pcVar16 + (ulong)bVar21 * -2 + 1;
    } while (cVar7 != '\0');
    pcVar16 = acStack_2a1 + ~uVar15 + lVar9;
  }
                    /* try { // try from 0087c6c7 to 0087c76a has its CatchHandler @ 0087cda0 */
  FUN_0040eb78(&local_258,pcVar1,pcVar16);
  uVar17 = (uint)uVar2;
  local_270 = (long *)((ulong)local_270 & 0xffffffffffffff00);
  iVar18 = 4;
  lVar9 = 6;
  do {
    lVar11 = lVar9;
    cVar7 = (char)(uVar17 & 0xf);
    cVar14 = cVar7 + '0';
    if (9 < (uVar17 & 0xf)) {
      cVar14 = cVar7 + '7';
    }
    *(char *)((long)local_228 + lVar11 + -0x4f) = cVar14;
    iVar18 = iVar18 + -1;
    uVar17 = uVar17 >> 4;
    lVar9 = lVar11 + -1;
  } while ((0 < iVar18) || (uVar17 != 0));
  lVar9 = (long)(int)lVar11;
  pcVar1 = (char *)((long)local_228 + lVar9 + -0x4f);
  local_238 = (undefined8 ****)local_228;
  if (pcVar1 == (char *)0x0) {
    lVar9 = (long)local_228 + lVar9 + -0x50;
  }
  else {
    uVar15 = 0xffffffffffffffff;
    pcVar16 = pcVar1;
    do {
      if (uVar15 == 0) break;
      uVar15 = uVar15 - 1;
      cVar7 = *pcVar16;
      pcVar16 = pcVar16 + (ulong)bVar21 * -2 + 1;
    } while (cVar7 != '\0');
    lVar9 = (long)local_228 + ~uVar15 + lVar9 + -0x50;
  }
  FUN_0040eb78(&local_238,pcVar1,lVar9);
  local_278 = (long *)0x0;
  local_270 = (long *)0x0;
  local_268 = (long *)0x0;
                    /* try { // try from 0087c7a1 to 0087c7a5 has its CatchHandler @ 0087c8c7 */
  plVar12 = (long *)FUN_00c37a70(0x40);
  local_268 = plVar12 + 8;
  local_278 = plVar12;
  if (plVar12 == (long *)0x0) {
LAB_0087c7fa:
    plVar12[4] = (long)(plVar12 + 6);
                    /* try { // try from 0087c81d to 0087c821 has its CatchHandler @ 0087c878 */
    FUN_0040ecb6(plVar12 + 4,local_238,(long)local_238 + local_230);
  }
  else {
    *plVar12 = (long)(plVar12 + 2);
                    /* try { // try from 0087c7eb to 0087c7ef has its CatchHandler @ 0087c848 */
    FUN_0040ecb6(plVar12,local_258,(undefined *)((long)local_258 + (long)local_250));
    if (plVar12 != (long *)0xffffffffffffffe0) goto LAB_0087c7fa;
  }
  local_270 = plVar12 + 8;
  pppuVar20 = &local_218;
  do {
    pppuVar13 = pppuVar20 + -4;
    if ((undefined8 ***)*pppuVar13 != pppuVar20 + -2) {
      free(*pppuVar13);
    }
    pppuVar20 = pppuVar13;
  } while (pppuVar13 != &local_258);
  plVar12 = (long *)param_1[1];
  pcVar3 = *(code **)(*plVar12 + 0xa0);
                    /* try { // try from 0087c907 to 0087c90b has its CatchHandler @ 0087cd9b */
  FUN_0086eb06(&local_58,&local_278);
  local_258 = &local_248;
                    /* try { // try from 0087c935 to 0087c939 has its CatchHandler @ 0087cd96 */
  FUN_0040eb78(&local_258,"forcesub","");
                    /* try { // try from 0087c94c to 0087c94e has its CatchHandler @ 0087cd58 */
  (*pcVar3)(plVar12,&local_258,&local_58);
  puVar8 = local_58;
  if (local_258 != &local_248) {
    free(local_258);
    puVar8 = local_58;
  }
  for (; local_50 != puVar8; puVar8 = puVar8 + 4) {
    if ((undefined8 *)*puVar8 != puVar8 + 2) {
      free((undefined8 *)*puVar8);
    }
  }
  plVar12 = local_278;
  plVar4 = local_270;
  if (local_58 != (undefined8 *)0x0) {
    free(local_58);
    plVar12 = local_278;
    plVar4 = local_270;
  }
  for (; plVar6 = local_270, local_270 != plVar12; plVar12 = plVar12 + 4) {
    local_270 = plVar4;
    if ((long *)*plVar12 != plVar12 + 2) {
      free((long *)*plVar12);
    }
    plVar4 = local_270;
    local_270 = plVar6;
  }
  local_270 = plVar4;
  if (local_278 != (long *)0x0) {
    free(local_278);
  }
LAB_0087b9c5:
                    /* try { // try from 0087b9c8 to 0087b9cc has its CatchHandler @ 0087cda0 */
  FUN_00879ff6(param_1);
  puVar5 = local_290;
  for (puVar8 = local_298; puVar5 != puVar8; puVar8 = puVar8 + 4) {
    if ((undefined8 *)*puVar8 != puVar8 + 2) {
      free((undefined8 *)*puVar8);
    }
  }
  if (local_298 != (undefined8 *)0x0) {
    free(local_298);
  }
  return;
}

