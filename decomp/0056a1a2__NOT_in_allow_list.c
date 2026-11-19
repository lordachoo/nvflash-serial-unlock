// anchor string: "NOT in allow-list" @ 00d47c9d
// function entry: 0056a1a2  name: FUN_0056a1a2


/* WARNING: Removing unreachable block (ram,0x0056a2a0) */
/* WARNING: Removing unreachable block (ram,0x0056a2b6) */
/* WARNING: Removing unreachable block (ram,0x0056a39b) */
/* WARNING: Removing unreachable block (ram,0x0056a3ad) */

ulong FUN_0056a1a2(long param_1,long *param_2,long param_3)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  long lVar4;
  char cVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  long lVar8;
  long *plVar9;
  ulong uVar10;
  ulong uVar11;
  char *pcVar12;
  char *pcVar13;
  byte bVar14;
  undefined8 uStack_120;
  char local_118 [32];
  undefined1 *local_f8 [2];
  undefined1 local_e8 [16];
  long *local_d8;
  long local_d0;
  long local_c8;
  long local_c0;
  undefined1 *local_b8;
  long local_b0;
  undefined1 local_a8 [16];
  long *local_98;
  long local_90;
  long local_88;
  long local_80;
  long *local_78;
  long local_70;
  long local_68;
  long local_60;
  long local_58;
  long *local_50;
  long *local_48;
  long *local_40;
  
  bVar14 = 0;
  if ((long *)*param_2 != (long *)0x0) {
    uStack_120 = (undefined1 *)0x56a1d4;
    (**(code **)(*(long *)*param_2 + 400))(&local_58);
    if (local_58 != 0) {
      if (local_50 != (long *)0x0) {
        bVar3 = false;
        goto LAB_0056a20d;
      }
LAB_0056a1e8:
                    /* try { // try from 0056a1f3 to 0056a1f8 has its CatchHandler @ 0056a737 */
      uStack_120 = (undefined1 *)0x56a1f9;
      (**(code **)(*(long *)*param_2 + 400))(&local_48);
                    /* try { // try from 0056a2f9 to 0056a2fe has its CatchHandler @ 0056a6e3 */
      uStack_120 = (undefined1 *)0x56a2ff;
      uVar6 = (**(code **)(*local_48 + 0x1c8))();
      if (local_40 != (long *)0x0) {
        LOCK();
        plVar9 = local_40 + 1;
        lVar4 = *plVar9;
        *(int *)plVar9 = (int)*plVar9 + -1;
        UNLOCK();
        if ((int)lVar4 == 1) {
          uStack_120 = (undefined1 *)0x56a7d4;
          (**(code **)(*local_40 + 0x10))(local_40);
          LOCK();
          piVar1 = (int *)((long)local_40 + 0xc);
          iVar2 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (iVar2 == 1) {
            uStack_120 = (undefined1 *)0x56a7f3;
            (**(code **)(*local_40 + 0x18))(local_40);
          }
        }
      }
      uStack_120 = (undefined1 *)0x56a356;
      snprintf(local_118,0x11,"%08X%08X",(uint)((ulong)uVar6 >> 0x20),(uint)uVar6);
      local_f8[0] = local_e8;
      uVar10 = 0xffffffffffffffff;
      pcVar12 = local_118;
      do {
        if (uVar10 == 0) break;
        uVar10 = uVar10 - 1;
        cVar5 = *pcVar12;
        pcVar12 = pcVar12 + (ulong)bVar14 * -2 + 1;
      } while (cVar5 != '\0');
                    /* try { // try from 0056a394 to 0056a398 has its CatchHandler @ 0056a737 */
      FUN_0040eb78(local_f8,local_118,local_118 + (~uVar10 - 1));
                    /* try { // try from 0056a3d4 to 0056a423 has its CatchHandler @ 0056a72c */
      uStack_120 = (undefined1 *)0x56a3d7;
      puVar7 = (undefined8 *)(**(code **)(**(long **)(param_1 + 8) + 0x60))();
      lVar4 = puVar7[1];
      lVar8 = FUN_0056d9f9(*puVar7,lVar4,local_f8);
      uVar10 = CONCAT71((int7)((ulong)local_118 >> 8),lVar4 != lVar8);
      pcVar12 = "ALLOWED";
      if (lVar4 == lVar8) {
        pcVar12 = "NOT in allow-list";
      }
      uStack_120 = (undefined1 *)0x56a424;
      FUN_004541f7(&local_b8,"INFO: UpdaterConfigMatcher: PDI=",local_f8);
      if (local_b0 == 0x7fffffffffffffff) {
                    /* WARNING: Subroutine does not return */
        uStack_120 = &LAB_0056a459;
        FUN_00c84c40("basic_string::append");
      }
                    /* try { // try from 0056a448 to 0056a458 has its CatchHandler @ 0056a459 */
      uStack_120 = (undefined1 *)0x56a44d;
      plVar9 = (long *)FUN_00c8f910(&local_b8,&DAT_00cd9ef7,1);
      local_98 = &local_88;
      if ((long *)*plVar9 == plVar9 + 2) {
        local_88 = plVar9[2];
        local_80 = plVar9[3];
      }
      else {
        local_88 = plVar9[2];
        local_98 = (long *)*plVar9;
      }
      local_90 = plVar9[1];
      *plVar9 = (long)(plVar9 + 2);
      plVar9[1] = 0;
      *(undefined1 *)(plVar9 + 2) = 0;
      uVar11 = 0xffffffffffffffff;
      pcVar13 = pcVar12;
      do {
        if (uVar11 == 0) break;
        uVar11 = uVar11 - 1;
        cVar5 = *pcVar13;
        pcVar13 = pcVar13 + (ulong)bVar14 * -2 + 1;
      } while (cVar5 != '\0');
      if (0x7fffffffffffffffU - local_90 < ~uVar11 - 1) {
                    /* WARNING: Subroutine does not return */
        uStack_120 = &LAB_0056a502;
        FUN_00c84c40("basic_string::append");
      }
                    /* try { // try from 0056a4df to 0056a501 has its CatchHandler @ 0056a502 */
      uStack_120 = (undefined1 *)0x56a4e4;
      plVar9 = (long *)FUN_00c8f910(&local_98,pcVar12);
      local_78 = &local_68;
      if ((long *)*plVar9 == plVar9 + 2) {
        local_68 = plVar9[2];
        local_60 = plVar9[3];
      }
      else {
        local_68 = plVar9[2];
        local_78 = (long *)*plVar9;
      }
      local_70 = plVar9[1];
      *plVar9 = (long)(plVar9 + 2);
      plVar9[1] = 0;
      *(undefined1 *)(plVar9 + 2) = 0;
      if (local_70 == 0x7fffffffffffffff) {
                    /* WARNING: Subroutine does not return */
        uStack_120 = &LAB_0056a588;
        FUN_00c84c40("basic_string::append");
      }
                    /* try { // try from 0056a562 to 0056a587 has its CatchHandler @ 0056a588 */
      uStack_120 = (undefined1 *)0x56a567;
      plVar9 = (long *)FUN_00c8f910(&local_78,&DAT_00dabe28,1);
      local_d8 = &local_c8;
      if ((long *)*plVar9 == plVar9 + 2) {
        local_c8 = plVar9[2];
        local_c0 = plVar9[3];
      }
      else {
        local_c8 = plVar9[2];
        local_d8 = (long *)*plVar9;
      }
      local_d0 = plVar9[1];
      *plVar9 = (long)(plVar9 + 2);
      plVar9[1] = 0;
      *(undefined1 *)(plVar9 + 2) = 0;
      if (local_78 != &local_68) {
        uStack_120 = (undefined1 *)0x56a649;
        free(local_78);
      }
      if (local_98 != &local_88) {
        uStack_120 = (undefined1 *)0x56a65e;
        free(local_98);
      }
      if (local_b8 != local_a8) {
        uStack_120 = (undefined1 *)0x56a676;
        free(local_b8);
      }
                    /* try { // try from 0056a688 to 0056a68c has its CatchHandler @ 0056a705 */
      uStack_120 = (undefined1 *)0x56a68d;
      FUN_00c440d0(param_3 + 0x10,local_d8,local_d0);
      if (local_d8 != &local_c8) {
        uStack_120 = (undefined1 *)0x56a6c2;
        free(local_d8);
      }
      if (local_f8[0] != local_e8) {
        uStack_120 = (undefined1 *)0x56a6de;
        free(local_f8[0]);
      }
      goto LAB_0056a283;
    }
    if (local_50 != (long *)0x0) {
      bVar3 = true;
LAB_0056a20d:
      LOCK();
      plVar9 = local_50 + 1;
      lVar4 = *plVar9;
      *(int *)plVar9 = (int)*plVar9 + -1;
      UNLOCK();
      if ((int)lVar4 == 1) {
        uStack_120 = (undefined1 *)0x56a7a6;
        (**(code **)(*local_50 + 0x10))(local_50);
        LOCK();
        piVar1 = (int *)((long)local_50 + 0xc);
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar2 == 1) {
          uStack_120 = (undefined1 *)0x56a7c5;
          (**(code **)(*local_50 + 0x18))(local_50);
        }
      }
      if (!bVar3) goto LAB_0056a1e8;
    }
  }
  uStack_120 = (undefined1 *)0x56a24b;
  FUN_00c440d0(param_3 + 0x10,"UpdaterConfigMatcher: display adapter not available for PDI check",
               0x41);
  plVar9 = *(long **)(param_3 + 0x100 + *(long *)(*(long *)(param_3 + 0x10) + -0x18));
  if (plVar9 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
    uStack_120 = (undefined1 *)0x56a2d7;
    FUN_00c84aa0();
  }
  if ((char)plVar9[7] == '\0') {
    uStack_120 = (undefined1 *)0x56a2df;
    FUN_00c7a0e0(plVar9);
    uStack_120 = (undefined1 *)0x56a2ed;
    cVar5 = (**(code **)(*plVar9 + 0x30))(plVar9,10);
  }
  else {
    cVar5 = *(char *)((long)plVar9 + 0x43);
  }
  uStack_120 = (undefined1 *)0x56a275;
  uVar6 = FUN_00c43cf0(param_3 + 0x10,(int)cVar5);
  uStack_120 = (undefined1 *)0x56a27d;
  FUN_00c433a0(uVar6);
  uVar10 = 0;
LAB_0056a283:
  return uVar10 & 0xffffffff;
}

