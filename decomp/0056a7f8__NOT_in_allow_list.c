// anchor string: "NOT in allow-list" @ 00d47c9d
// function entry: 0056a7f8  name: FUN_0056a7f8


/* WARNING: Removing unreachable block (ram,0x0056af5b) */
/* WARNING: Removing unreachable block (ram,0x0056af69) */
/* WARNING: Removing unreachable block (ram,0x0056b731) */
/* WARNING: Removing unreachable block (ram,0x0056b741) */

ulong FUN_0056a7f8(long param_1,long *param_2,long param_3)

{
  code *pcVar1;
  byte *pbVar2;
  ushort uVar3;
  uint uVar4;
  undefined4 *puVar5;
  char cVar6;
  short sVar7;
  uint uVar8;
  int iVar9;
  undefined8 *puVar10;
  long *plVar11;
  undefined8 *puVar12;
  ulong uVar13;
  undefined1 *puVar14;
  undefined8 uVar15;
  long lVar16;
  long *plVar17;
  ulong uVar18;
  int *piVar19;
  undefined4 *puVar20;
  undefined1 *puVar21;
  ulong uVar22;
  char *pcVar23;
  char *pcVar24;
  long lVar25;
  ushort *puVar26;
  ushort *puVar27;
  ulong *puVar28;
  uint uVar29;
  undefined1 uVar30;
  bool bVar31;
  byte bVar32;
  ulong local_140;
  ulong local_130;
  ushort *local_128;
  ushort *local_120;
  undefined4 *local_108;
  undefined4 *local_100;
  undefined4 *local_f8;
  undefined1 *local_e8;
  long local_e0;
  undefined1 local_d8 [16];
  long *local_c8;
  long local_c0;
  long local_b8;
  long local_b0;
  undefined1 *local_a8;
  long local_a0;
  undefined1 local_98 [16];
  undefined8 local_88;
  long local_80;
  long local_78;
  long local_70;
  undefined8 local_68;
  ulong local_60;
  undefined8 local_58;
  ulong local_50;
  undefined1 local_39 [9];
  
  bVar32 = 0;
  param_2 = (long *)*param_2;
  if (param_2 == (long *)0x0) {
    FUN_00c440d0(param_3 + 0x10,"UpdaterConfigMatcher: ROM image not available for SN check",0x3a);
    plVar11 = *(long **)(param_3 + 0x100 + *(long *)(*(long *)(param_3 + 0x10) + -0x18));
    if (plVar11 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_00c84aa0();
    }
    if ((char)plVar11[7] == '\0') {
      FUN_00c7a0e0(plVar11);
      cVar6 = (**(code **)(*plVar11 + 0x30))(plVar11,10);
    }
    else {
      cVar6 = *(char *)((long)plVar11 + 0x43);
    }
    uVar15 = FUN_00c43cf0(param_3 + 0x10,(int)cVar6);
    FUN_00c433a0(uVar15);
    uVar18 = 0;
    goto LAB_0056b719;
  }
  pcVar1 = *(code **)(*param_2 + 0xb90);
  local_68 = &local_58;
                    /* try { // try from 0056a84c to 0056a850 has its CatchHandler @ 0056b7bd */
  FUN_0040eb78(&local_68,&DAT_00ce7fb8,&DAT_00ce7fbb);
                    /* try { // try from 0056a8df to 0056a8e1 has its CatchHandler @ 0056b75a */
  (*pcVar1)(&local_128,param_2,&local_68,0);
  if (local_68 != &local_58) {
    free(local_68);
  }
                    /* try { // try from 0056a8f9 to 0056a8fd has its CatchHandler @ 0056b7b2 */
  puVar10 = (undefined8 *)FUN_00c37a70(0x3b0);
  if (puVar10 != (undefined8 *)0x0) {
    *(undefined4 *)(puVar10 + 1) = 0;
    puVar10[2] = 0;
    puVar10[3] = 0;
    *puVar10 = &PTR_FUN_00ce00f0;
    puVar10[8] = 0;
    puVar10[9] = 0;
    puVar10[10] = 0;
    local_68 = (undefined8 *)0x0;
    local_60 = 0;
    local_58 = 0;
    local_50 = local_50 & 0xffffffff00000000;
    puVar10[4] = 0;
    puVar10[5] = 0;
    puVar10[6] = 0;
    *(undefined4 *)(puVar10 + 7) = 0;
    uVar18 = (long)local_120 - (long)local_128;
    if (local_120 == local_128) {
      uVar22 = 0;
LAB_0056aa26:
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 0056aa30 to 0056ad3e has its CatchHandler @ 0056aa35 */
      FUN_00c84d00("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",
                   uVar22);
    }
    local_88 = (long *)CONCAT71(local_88._1_7_,(byte)*local_128);
    uVar22 = 1;
    do {
      if (uVar22 == uVar18) goto LAB_0056aa26;
      local_98[uVar22 + 0x10] = *(byte *)((long)local_128 + uVar22);
      uVar8 = (int)uVar22 + 1;
      uVar22 = uVar22 + 1;
    } while (uVar22 != 8);
    puVar28 = &local_68;
    puVar27 = (ushort *)&local_88;
    cVar6 = '3';
    pcVar23 = "s2bwb";
    do {
      if ((byte)(cVar6 - 0x30U) < 10) {
        sVar7 = 0;
        do {
          sVar7 = cVar6 + -0x30 + sVar7 * 10;
          pcVar24 = pcVar23 + 1;
          cVar6 = *pcVar23;
          pcVar23 = pcVar24;
        } while ((byte)(cVar6 - 0x30U) < 10);
        if (sVar7 == 0) {
          sVar7 = 1;
        }
      }
      else {
        sVar7 = 1;
        pcVar24 = pcVar23;
      }
      for (; sVar7 != 0; sVar7 = sVar7 + -1) {
        switch(cVar6) {
        case 'b':
          *(uint *)puVar28 = (uint)(byte)*puVar27;
          puVar28 = (ulong *)((long)puVar28 + 4);
          puVar27 = (ushort *)((long)puVar27 + 1);
          break;
        default:
          goto switchD_0056aafb_caseD_63;
        case 'd':
          lVar25 = 0;
          uVar29 = 0;
          do {
            uVar29 = uVar29 | (uint)*(byte *)((long)puVar27 + lVar25) <<
                              ((char)lVar25 * '\b' & 0x1fU);
            lVar25 = lVar25 + 1;
          } while (lVar25 != 4);
          puVar27 = puVar27 + 2;
          *(uint *)puVar28 = uVar29;
          puVar28 = (ulong *)((long)puVar28 + 4);
          break;
        case 'q':
          iVar9 = 0;
          uVar22 = 0;
          puVar26 = puVar27;
          do {
            uVar22 = uVar22 | (ulong)(byte)*puVar26 << ((byte)iVar9 & 0x3f);
            puVar26 = (ushort *)((long)puVar26 + 1);
            iVar9 = iVar9 + 8;
          } while (iVar9 != 0x40);
          puVar27 = puVar27 + 4;
          *puVar28 = uVar22;
          puVar28 = puVar28 + 1;
          break;
        case 's':
          *(uint *)puVar28 =
               (uint)CONCAT71((int7)((long)(char)(byte)*puVar27 >> 0x3f),(byte)*puVar27);
          puVar28 = (ulong *)((long)puVar28 + 4);
          puVar27 = (ushort *)((long)puVar27 + 1);
          break;
        case 'w':
          uVar3 = *puVar27;
          puVar27 = puVar27 + 1;
          *(uint *)puVar28 = (uint)uVar3;
          puVar28 = (ulong *)((long)puVar28 + 4);
        }
      }
      pcVar23 = pcVar24 + 1;
      cVar6 = *pcVar24;
    } while (cVar6 != '\0');
    if ((((DAT_067dd355 == (char)local_68) && (DAT_067dd356 == local_68._4_1_)) &&
        (DAT_067dd357 == (char)local_60)) &&
       ((local_58._4_4_ < 0x20000 && (local_58._4_4_ <= uVar18)))) {
      puVar10[4] = local_68;
      puVar10[5] = local_60;
      puVar10[6] = local_58;
      *(undefined4 *)(puVar10 + 7) = (undefined4)local_50;
      if (uVar8 < local_58._4_4_) {
        uVar22 = (ulong)uVar8;
        if (uVar22 < uVar18) {
          do {
            pbVar2 = (byte *)puVar10[9];
            if (pbVar2 == (byte *)puVar10[10]) {
              FUN_004542aa(puVar10 + 8);
            }
            else {
              if (pbVar2 != (byte *)0x0) {
                *pbVar2 = *(byte *)((long)local_128 + uVar22);
              }
              puVar10[9] = puVar10[9] + 1;
            }
            uVar8 = uVar8 + 1;
            if (*(uint *)((long)puVar10 + 0x34) <= uVar8) goto switchD_0056aafb_caseD_63;
            uVar22 = (ulong)uVar8;
          } while (uVar22 < (ulong)((long)local_120 - (long)local_128));
        }
                    /* WARNING: Subroutine does not return */
        FUN_00c84d00("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)");
      }
    }
switchD_0056aafb_caseD_63:
    *puVar10 = &PTR_FUN_00d481e0;
    puVar10[0xb] = 0;
    if (puVar10[9] != puVar10[8]) {
      bVar31 = *(char *)((long)puVar10 + 0x2c) != '\x02';
      if (((char)*(undefined4 *)(puVar10 + 6) != '\x01') || (bVar31)) {
        if (((char)*(undefined4 *)(puVar10 + 6) != '\0') || (bVar31)) {
          puVar10[0xb] = "3s2bwbd116b";
        }
        else {
          puVar10[0xb] = &DAT_00d47cb8;
        }
      }
      else {
        puVar10[0xb] = &DAT_00d47cb8;
      }
      puVar28 = puVar10 + 0xc;
      if (puVar28 != (ulong *)0x0) {
        pcVar23 = (char *)puVar10[0xb];
        puVar27 = local_128;
        while( true ) {
          cVar6 = *pcVar23;
          if (cVar6 == '\0') break;
          if ((byte)(cVar6 - 0x30U) < 10) {
            sVar7 = 0;
            pcVar24 = pcVar23 + 1;
            do {
              sVar7 = cVar6 + -0x30 + sVar7 * 10;
              pcVar23 = pcVar24 + 1;
              cVar6 = *pcVar24;
              pcVar24 = pcVar23;
            } while ((byte)(cVar6 - 0x30U) < 10);
            if (sVar7 == 0) {
              sVar7 = 1;
            }
          }
          else {
            sVar7 = 1;
            pcVar23 = pcVar23 + 1;
          }
          for (; sVar7 != 0; sVar7 = sVar7 + -1) {
            switch(cVar6) {
            case 'b':
              *(uint *)puVar28 = (uint)(byte)*puVar27;
              puVar28 = (ulong *)((long)puVar28 + 4);
              puVar27 = (ushort *)((long)puVar27 + 1);
              break;
            default:
              goto switchD_0056adbc_caseD_63;
            case 'd':
              lVar25 = 0;
              uVar8 = 0;
              do {
                uVar8 = uVar8 | (uint)*(byte *)((long)puVar27 + lVar25) <<
                                ((char)lVar25 * '\b' & 0x1fU);
                lVar25 = lVar25 + 1;
              } while (lVar25 != 4);
              puVar27 = puVar27 + 2;
              *(uint *)puVar28 = uVar8;
              puVar28 = (ulong *)((long)puVar28 + 4);
              break;
            case 'q':
              iVar9 = 0;
              uVar18 = 0;
              puVar26 = puVar27;
              do {
                uVar18 = uVar18 | (ulong)(byte)*puVar26 << ((byte)iVar9 & 0x3f);
                puVar26 = (ushort *)((long)puVar26 + 1);
                iVar9 = iVar9 + 8;
              } while (iVar9 != 0x40);
              puVar27 = puVar27 + 4;
              *puVar28 = uVar18;
              puVar28 = puVar28 + 1;
              break;
            case 's':
              *(uint *)puVar28 =
                   (uint)CONCAT71((int7)((long)(char)(byte)*puVar27 >> 0x3f),(byte)*puVar27);
              puVar28 = (ulong *)((long)puVar28 + 4);
              puVar27 = (ushort *)((long)puVar27 + 1);
              break;
            case 'w':
              uVar3 = *puVar27;
              puVar27 = puVar27 + 1;
              *(uint *)puVar28 = (uint)uVar3;
              puVar28 = (ulong *)((long)puVar28 + 4);
            }
          }
        }
      }
    }
  }
switchD_0056adbc_caseD_63:
                    /* try { // try from 0056ae68 to 0056ae6c has its CatchHandler @ 0056af28 */
  plVar11 = (long *)FUN_00c37a70(0x20);
  if (plVar11 != (long *)0x0) {
    *(undefined4 *)(plVar11 + 1) = 1;
    *(undefined4 *)((long)plVar11 + 0xc) = 1;
    *plVar11 = (long)&PTR_LAB_00d482b0;
    plVar11[3] = (long)puVar10;
  }
  if (puVar10 == (undefined8 *)0x0) {
                    /* try { // try from 0056b868 to 0056b86c has its CatchHandler @ 0056afdd */
    FUN_00c440d0(param_3 + 0x10,"UpdaterConfigMatcher: OBD InfoROM object not present",0x34);
    plVar17 = *(long **)(param_3 + 0x100 + *(long *)(*(long *)(param_3 + 0x10) + -0x18));
    if (plVar17 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_00c84aa0(0);
    }
    if ((char)plVar17[7] == '\0') {
      FUN_00c7a0e0();
      cVar6 = (**(code **)(*plVar17 + 0x30))(plVar17,10);
    }
    else {
      cVar6 = *(char *)((long)plVar17 + 0x43);
    }
                    /* try { // try from 0056afd1 to 0056b007 has its CatchHandler @ 0056afdd */
    uVar15 = FUN_00c43cf0(param_3 + 0x10,(int)cVar6);
    FUN_00c433a0(uVar15);
    uVar18 = 0;
  }
  else {
    if ((puVar10 != (undefined8 *)0xfffffffffffffff0) &&
       ((puVar10[3] == 0 || (*(int *)(puVar10[3] + 8) == 0)))) {
      puVar10[2] = puVar10;
      if (plVar11 == (long *)0x0) {
        plVar17 = (long *)puVar10[3];
        if (plVar17 != (long *)0x0) goto LAB_0056aedb;
      }
      else {
        LOCK();
        *(int *)((long)plVar11 + 0xc) = *(int *)((long)plVar11 + 0xc) + 1;
        UNLOCK();
        plVar17 = (long *)puVar10[3];
        if (plVar17 != (long *)0x0) {
LAB_0056aedb:
          piVar19 = (int *)((long)plVar17 + 0xc);
          LOCK();
          iVar9 = *piVar19;
          *piVar19 = *piVar19 + -1;
          UNLOCK();
          if (iVar9 == 1) {
            (**(code **)(*plVar17 + 0x18))();
          }
        }
      }
      puVar10[3] = plVar11;
    }
    local_108 = (undefined4 *)0x0;
    local_100 = (undefined4 *)0x0;
    local_f8 = (undefined4 *)0x0;
    puVar12 = puVar10 + 0x1c;
    do {
      if (local_100 == local_f8) {
                    /* try { // try from 0056b04a to 0056b04e has its CatchHandler @ 0056b7a7 */
        FUN_00417078(&local_108,local_100,puVar12);
      }
      else {
        if (local_100 != (undefined4 *)0x0) {
          *local_100 = *(undefined4 *)puVar12;
        }
        local_100 = local_100 + 1;
      }
      puVar5 = local_100;
      puVar12 = (undefined8 *)((long)puVar12 + 4);
    } while (puVar12 != puVar10 + 0x24);
    local_68 = &local_58;
    local_60 = 0;
    local_58 = local_58 & 0xffffffffffffff00;
    if (local_108 == local_100) {
LAB_0056b1aa:
      local_e8 = local_d8;
                    /* try { // try from 0056b1d0 to 0056b2a1 has its CatchHandler @ 0056b2a2 */
      FUN_0040ecb6(&local_e8,local_68,local_68);
    }
    else {
      uVar30 = *(undefined1 *)local_108;
      puVar20 = local_108 + 1;
      local_130 = 1;
      uVar22 = 0;
      uVar18 = local_130;
      while( true ) {
        local_130 = uVar18;
        puVar10 = local_68;
        *(undefined1 *)((long)local_68 + uVar22) = uVar30;
        local_60 = local_130;
        *(undefined1 *)((long)local_68 + local_130) = 0;
        if (puVar20 == puVar5) break;
        uVar30 = *(undefined1 *)puVar20;
        uVar18 = local_130 + 1;
        if (local_68 == &local_58) {
          uVar13 = 0xf;
        }
        else {
          uVar13 = local_58;
        }
        puVar20 = puVar20 + 1;
        uVar22 = local_130;
        if (uVar13 < uVar18) {
                    /* try { // try from 0056b103 to 0056b107 has its CatchHandler @ 0056b111 */
          FUN_00c8e390(&local_68,local_130,0,0,1);
        }
      }
      if (local_130 == 0) goto LAB_0056b1aa;
      uVar18 = 0;
      uVar8 = 0;
      do {
        iVar9 = isspace((int)*(char *)((long)puVar10 + uVar18));
        if (iVar9 == 0) {
          local_140 = (ulong)uVar8;
          if (local_140 < local_130) goto LAB_0056b1f1;
          uVar29 = 0;
          goto LAB_0056b230;
        }
        uVar8 = uVar8 + 1;
        uVar18 = (ulong)uVar8;
      } while (uVar18 < local_130);
      local_140 = 0;
      uVar8 = 0;
      if (local_130 == 0) {
        local_140 = local_130;
        uVar18 = 0;
      }
      else {
LAB_0056b1f1:
        uVar29 = 0;
        uVar18 = local_140;
        uVar4 = uVar8;
        do {
          uVar4 = uVar4 + 1;
          iVar9 = isspace((int)*(char *)((long)puVar10 + uVar18));
          if (iVar9 == 0) {
            uVar29 = uVar4;
          }
          uVar18 = (ulong)uVar4;
        } while (uVar18 < local_130);
LAB_0056b230:
        uVar18 = (ulong)(uVar29 - uVar8);
        if (local_130 < local_140) {
                    /* WARNING: Subroutine does not return */
          FUN_00c84d00("%s: __pos (which is %zu) > this->size() (which is %zu)",
                       "basic_string::substr",local_140,local_130);
        }
      }
      local_e8 = local_d8;
      if (local_130 - local_140 <= uVar18) {
        uVar18 = local_130 - local_140;
      }
      FUN_0040eb78(&local_e8,(long)puVar10 + local_140,(long)puVar10 + local_140 + uVar18);
    }
    if (local_68 != &local_58) {
      free(local_68);
    }
    puVar21 = local_e8 + local_e0;
    local_39[0] = 0;
    puVar14 = (undefined1 *)FUN_0056d919(local_e8,puVar21,local_39);
    if (puVar21 == local_e8 + local_e0) {
      *puVar14 = 0;
      local_e0 = (long)puVar14 - (long)local_e8;
    }
    else {
                    /* try { // try from 0056b320 to 0056b426 has its CatchHandler @ 0056b3a2 */
      FUN_00c8e4e0(&local_e8,(long)puVar14 - (long)local_e8,(long)puVar21 - (long)puVar14);
    }
    if (local_e0 == 0) {
      FUN_00c440d0(param_3 + 0x10,"UpdaterConfigMatcher: device serial number is empty",0x33);
      plVar17 = *(long **)(param_3 + 0x100 + *(long *)(*(long *)(param_3 + 0x10) + -0x18));
      if (plVar17 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_00c84aa0();
      }
      if ((char)plVar17[7] == '\0') {
        FUN_00c7a0e0(plVar17);
        cVar6 = (**(code **)(*plVar17 + 0x30))(plVar17,10);
      }
      else {
        cVar6 = *(char *)((long)plVar17 + 0x43);
      }
      uVar15 = FUN_00c43cf0(param_3 + 0x10,(int)cVar6);
      FUN_00c433a0(uVar15);
      uVar18 = 0;
    }
    else {
      puVar10 = (undefined8 *)(**(code **)(**(long **)(param_1 + 8) + 0x58))();
      lVar25 = puVar10[1];
      lVar16 = FUN_0056d9f9(*puVar10,lVar25,&local_e8);
      uVar18 = CONCAT71((int7)((ulong)lVar25 >> 8),lVar16 != lVar25);
      pcVar23 = "NOT in allow-list";
      if (lVar25 != lVar16) {
        pcVar23 = "ALLOWED";
      }
      FUN_004541f7(&local_a8,"INFO: UpdaterConfigMatcher: SN=",&local_e8);
      if (local_a0 == 0x7fffffffffffffff) {
                    /* WARNING: Subroutine does not return */
        FUN_00c84c40("basic_string::append");
      }
                    /* try { // try from 0056b44b to 0056b45b has its CatchHandler @ 0056b45c */
      plVar17 = (long *)FUN_00c8f910(&local_a8,&DAT_00cd9ef7,1);
      local_88 = &local_78;
      if ((long *)*plVar17 == plVar17 + 2) {
        local_78 = plVar17[2];
        local_70 = plVar17[3];
      }
      else {
        local_78 = plVar17[2];
        local_88 = (long *)*plVar17;
      }
      local_80 = plVar17[1];
      *plVar17 = (long)(plVar17 + 2);
      plVar17[1] = 0;
      *(undefined1 *)(plVar17 + 2) = 0;
      uVar22 = 0xffffffffffffffff;
      pcVar24 = pcVar23;
      do {
        if (uVar22 == 0) break;
        uVar22 = uVar22 - 1;
        cVar6 = *pcVar24;
        pcVar24 = pcVar24 + (ulong)bVar32 * -2 + 1;
      } while (cVar6 != '\0');
      if (0x7fffffffffffffffU - local_80 < ~uVar22 - 1) {
                    /* WARNING: Subroutine does not return */
        FUN_00c84c40("basic_string::append");
      }
                    /* try { // try from 0056b4d3 to 0056b4f5 has its CatchHandler @ 0056b4f6 */
      plVar17 = (long *)FUN_00c8f910(&local_88,pcVar23);
      local_68 = &local_58;
      if ((undefined8 *)*plVar17 == plVar17 + 2) {
        local_58 = plVar17[2];
        local_50 = plVar17[3];
      }
      else {
        local_58 = plVar17[2];
        local_68 = (undefined8 *)*plVar17;
      }
      local_60 = plVar17[1];
      *plVar17 = (long)(plVar17 + 2);
      plVar17[1] = 0;
      *(undefined1 *)(plVar17 + 2) = 0;
      if (local_60 == 0x7fffffffffffffff) {
                    /* WARNING: Subroutine does not return */
        FUN_00c84c40("basic_string::append");
      }
                    /* try { // try from 0056b556 to 0056b578 has its CatchHandler @ 0056b579 */
      plVar17 = (long *)FUN_00c8f910(&local_68,&DAT_00dabe28,1);
      local_c8 = &local_b8;
      if ((long *)*plVar17 == plVar17 + 2) {
        local_b8 = plVar17[2];
        local_b0 = plVar17[3];
      }
      else {
        local_b8 = plVar17[2];
        local_c8 = (long *)*plVar17;
      }
      local_c0 = plVar17[1];
      *plVar17 = (long)(plVar17 + 2);
      plVar17[1] = 0;
      *(undefined1 *)(plVar17 + 2) = 0;
      if (local_68 != &local_58) {
        free(local_68);
      }
      if (local_88 != &local_78) {
        free(local_88);
      }
      if (local_a8 != local_98) {
        free(local_a8);
      }
                    /* try { // try from 0056b67b to 0056b67f has its CatchHandler @ 0056b780 */
      FUN_00c440d0(param_3 + 0x10,local_c8,local_c0);
      if (local_c8 != &local_b8) {
        free(local_c8);
      }
    }
    if (local_e8 != local_d8) {
      free(local_e8);
    }
    if (local_108 != (undefined4 *)0x0) {
      free(local_108);
    }
  }
  if (plVar11 != (long *)0x0) {
    LOCK();
    plVar17 = plVar11 + 1;
    lVar25 = *plVar17;
    *(int *)plVar17 = (int)*plVar17 + -1;
    UNLOCK();
    if ((int)lVar25 == 1) {
      (**(code **)(*plVar11 + 0x10))(plVar11);
      LOCK();
      piVar19 = (int *)((long)plVar11 + 0xc);
      iVar9 = *piVar19;
      *piVar19 = *piVar19 + -1;
      UNLOCK();
      if (iVar9 == 1) {
        (**(code **)(*plVar11 + 0x18))(plVar11);
      }
    }
  }
  if (local_128 != (ushort *)0x0) {
    free(local_128);
  }
LAB_0056b719:
  return uVar18 & 0xffffffff;
}

