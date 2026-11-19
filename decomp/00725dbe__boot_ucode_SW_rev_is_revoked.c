// anchor string: "boot ucode SW rev is revoked" @ 00d825f0
// function entry: 00725dbe  name: FUN_00725dbe


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong FUN_00725dbe(undefined8 param_1,long *param_2,undefined8 *param_3)

{
  long *plVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  bool bVar8;
  undefined8 extraout_RDX;
  undefined7 uVar9;
  ulong unaff_RBP;
  undefined7 uVar10;
  bool bVar11;
  
  if (DAT_0677e810 == '\0') {
    iVar3 = FUN_00c39270(&DAT_0677e810);
    if (iVar3 != 0) {
      FUN_00c64d80(&DAT_0677e8d0);
      _DAT_0677e9a8 = 0;
      DAT_0677e9b0 = 0;
      DAT_0677e9b1 = 0;
      _DAT_0677e9b8 = 0;
      _DAT_0677e9c0 = 0;
      _DAT_0677e9c8 = 0;
      _DAT_0677e9d0 = 0;
      _DAT_0677e820 = &PTR_FUN_00cd9450;
      _DAT_0677e828 = 0;
      DAT_0677e830 = (undefined **)&DAT_00cd9488;
      _DAT_0677e8d0 = (undefined **)&DAT_00cd94b0;
                    /* try { // try from 00726008 to 0072600c has its CatchHandler @ 0072612a */
      FUN_00cbf5f0(&DAT_0677e8d0,&DAT_0677e838);
      _DAT_0677e820 = &PTR_FUN_00cd9500;
      DAT_0677e830 = &PTR_LAB_00cd9538;
      _DAT_0677e8d0 = &PTR_LAB_00cd9560;
      _DAT_0677e838 = &PTR_LAB_0122c610;
      _DAT_0677e840 = 0;
      _DAT_0677e848 = 0;
      _DAT_0677e850 = 0;
      _DAT_0677e858 = 0;
      _DAT_0677e860 = 0;
      _DAT_0677e868 = 0;
      FUN_00c3bbb0(&DAT_0677e870);
      _DAT_0677e878 = 0x18;
      _DAT_0677e880 = &DAT_0677e890;
      _DAT_0677e888 = 0;
      DAT_0677e890 = 0;
      _DAT_0677e838 = &PTR_LAB_00ce16b0;
      _DAT_0677e8b8 = 0;
      _DAT_0677e8a8 = &DAT_0677e8a8;
      _DAT_0677e8b0 = &DAT_0677e8a8;
      DAT_0677e8a0 = 0;
      _DAT_0677e8c4 = 0;
      _DAT_0677e8c0 = 3;
      _DAT_0677e8c8 = 0;
      _DAT_0677e8cc = 0;
      FUN_00c393b0(&DAT_0677e810);
      __cxa_atexit(FUN_0040e500,&DAT_0677e820,&DAT_0122d728);
    }
  }
  iVar3 = (**(code **)(*param_2 + 0x130))(param_2);
  if (iVar3 != 0x14) {
    iVar3 = (**(code **)(*param_2 + 0x130))(param_2);
    if (iVar3 != 0x15) {
      iVar3 = (**(code **)(*param_2 + 0x130))(param_2);
      if (iVar3 != 0x16) {
        iVar3 = (**(code **)(*param_2 + 0x130))(param_2);
        if (iVar3 != 0x17) {
          iVar3 = (**(code **)(*param_2 + 0x130))(param_2);
          if (iVar3 != 0x18) {
            iVar3 = (**(code **)(*param_2 + 0x130))(param_2);
            if (iVar3 != 0x19) {
              iVar3 = (**(code **)(*param_2 + 0x130))(param_2);
              if (iVar3 != 0x1a) {
                iVar3 = (**(code **)(*param_2 + 0x130))(param_2);
                if (iVar3 != 0x1b) {
                  iVar3 = (**(code **)(*param_2 + 0x130))(param_2);
                  unaff_RBP = 1;
                  if (iVar3 != 0x1c) goto LAB_007261e7;
                }
              }
            }
          }
        }
      }
    }
  }
  iVar3 = (**(code **)(*param_2 + 0xd0))(param_2,0x820258);
  iVar4 = (**(code **)(*param_2 + 0x1d8))(param_2);
  uVar5 = (**(code **)(*(long *)*param_3 + 0x290))();
  uVar9 = (undefined7)((ulong)extraout_RDX >> 8);
  uVar10 = (undefined7)(unaff_RBP >> 8);
  if (iVar4 == 6) {
    bVar11 = iVar3 == 3 && uVar5 < 0x1acf3a7;
    unaff_RBP = CONCAT71(uVar10,bVar11);
    if (bVar11) {
      FUN_00c440d0(&DAT_0677e830,"boot ucode SW rev is revoked",0x1c);
      plVar1 = *(long **)(&DAT_0677e920 + (long)DAT_0677e830[-3]);
      if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_00c84aa0();
      }
      if ((char)plVar1[7] == '\0') {
        FUN_00c7a0e0(plVar1);
        cVar2 = (**(code **)(*plVar1 + 0x30))(plVar1,10);
      }
      else {
        cVar2 = *(char *)((long)plVar1 + 0x43);
      }
      uVar7 = FUN_00c43cf0(&DAT_0677e830,(int)cVar2);
      FUN_00c433a0(uVar7);
      unaff_RBP = 0;
      goto LAB_007261e7;
    }
    bVar11 = iVar3 == 2 && uVar5 < 0x1acca35;
    if (bVar11) {
      FUN_00c440d0(&DAT_0677e830,"boot ucode SW rev is revoked",0x1c);
      plVar1 = *(long **)(&DAT_0677e920 + (long)DAT_0677e830[-3]);
      if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_00c84aa0();
      }
      if ((char)plVar1[7] == '\0') {
        FUN_00c7a0e0(plVar1);
        cVar2 = (**(code **)(*plVar1 + 0x30))(plVar1,10);
      }
      else {
        cVar2 = *(char *)((long)plVar1 + 0x43);
      }
      uVar7 = FUN_00c43cf0(&DAT_0677e830,(int)cVar2);
      FUN_00c433a0(uVar7);
      goto LAB_007261e7;
    }
    bVar8 = iVar3 == 1 && uVar5 < 0x1a3410e;
    if (bVar8) {
      FUN_00c440d0(&DAT_0677e830,"boot ucode SW rev is revoked",0x1c);
      plVar1 = *(long **)(&DAT_0677e920 + (long)DAT_0677e830[-3]);
      if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_00c84aa0();
      }
      if ((char)plVar1[7] == '\0') {
        FUN_00c7a0e0(plVar1);
        cVar2 = (**(code **)(*plVar1 + 0x30))(plVar1,10);
      }
      else {
        cVar2 = *(char *)((long)plVar1 + 0x43);
      }
      uVar7 = FUN_00c43cf0(&DAT_0677e830,(int)cVar2);
      FUN_00c433a0(uVar7);
      unaff_RBP = CONCAT71(uVar9,bVar11) & 0xffffffff;
      goto LAB_007261e7;
    }
    iVar6 = (**(code **)(*param_2 + 0xd0))(param_2,&LAB_00824144);
    if ((iVar6 == 1) && (uVar5 < 0x1a76dcd)) {
      FUN_00c440d0(&DAT_0677e830,"boot ucode BROM rev revoked",0x1b);
      plVar1 = *(long **)(&DAT_0677e920 + (long)DAT_0677e830[-3]);
      if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_00c84aa0();
      }
      if ((char)plVar1[7] == '\0') {
        FUN_00c7a0e0(plVar1);
        cVar2 = (**(code **)(*plVar1 + 0x30))(plVar1,10);
      }
      else {
        cVar2 = *(char *)((long)plVar1 + 0x43);
      }
      uVar7 = FUN_00c43cf0(&DAT_0677e830,(int)cVar2);
      FUN_00c433a0(uVar7);
      unaff_RBP = CONCAT71(uVar10,bVar8);
      goto LAB_007261e7;
    }
    bVar11 = false;
LAB_007261d1:
    unaff_RBP = 1;
    if (1 < iVar4 - 0x176U) goto LAB_007261e7;
    if (iVar4 == 0x172) {
LAB_00725eff:
      if ((iVar3 == 1) && (uVar5 < 0x1b359a4)) {
        FUN_00c440d0(&DAT_0677e830,"boot ucode SW rev is revoked",0x1c);
        plVar1 = *(long **)(&DAT_0677e920 + (long)DAT_0677e830[-3]);
        if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_00c84aa0();
        }
        if ((char)plVar1[7] == '\0') {
          FUN_00c7a0e0(plVar1);
          cVar2 = (**(code **)(*plVar1 + 0x30))(plVar1,10);
        }
        else {
          cVar2 = *(char *)((long)plVar1 + 0x43);
        }
        uVar7 = FUN_00c43cf0(&DAT_0677e830,(int)cVar2);
        FUN_00c433a0(uVar7);
        unaff_RBP = 0;
        goto LAB_007261e7;
      }
    }
    if (bVar11) goto LAB_007266d4;
  }
  else {
    if (iVar4 == 0x170) {
      bVar11 = iVar3 == 3 && uVar5 < 0x1acf68e;
      if (bVar11) {
        FUN_00c440d0(&DAT_0677e830,"boot ucode SW rev is revoked",0x1c);
        plVar1 = *(long **)(&DAT_0677e920 + (long)DAT_0677e830[-3]);
        if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_00c84aa0();
        }
        if ((char)plVar1[7] == '\0') {
          FUN_00c7a0e0(plVar1);
          cVar2 = (**(code **)(*plVar1 + 0x30))(plVar1,10);
        }
        else {
          cVar2 = *(char *)((long)plVar1 + 0x43);
        }
        uVar7 = FUN_00c43cf0(&DAT_0677e830,(int)cVar2);
        FUN_00c433a0(uVar7);
        unaff_RBP = 0;
      }
      else {
        bVar8 = iVar3 == 2 && uVar5 < 0x1a9f3c3;
        if (bVar8) {
          FUN_00c440d0(&DAT_0677e830,"boot ucode SW rev is revoked",0x1c);
          plVar1 = *(long **)(&DAT_0677e920 + (long)DAT_0677e830[-3]);
          if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
            FUN_00c84aa0();
          }
          if ((char)plVar1[7] == '\0') {
            FUN_00c7a0e0(plVar1);
            cVar2 = (**(code **)(*plVar1 + 0x30))(plVar1,10);
          }
          else {
            cVar2 = *(char *)((long)plVar1 + 0x43);
          }
          uVar7 = FUN_00c43cf0(&DAT_0677e830,(int)cVar2);
          FUN_00c433a0(uVar7);
          unaff_RBP = CONCAT71(uVar10,bVar11);
        }
        else {
          bVar11 = iVar3 == 1 && uVar5 < 0x1a08344;
          if (bVar11) {
            FUN_00c440d0(&DAT_0677e830,"boot ucode SW rev is revoked",0x1c);
            plVar1 = *(long **)(&DAT_0677e920 + (long)DAT_0677e830[-3]);
            if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
              FUN_00c84aa0();
            }
            if ((char)plVar1[7] == '\0') {
              FUN_00c7a0e0(plVar1);
              cVar2 = (**(code **)(*plVar1 + 0x30))(plVar1,10);
            }
            else {
              cVar2 = *(char *)((long)plVar1 + 0x43);
            }
            uVar7 = FUN_00c43cf0(&DAT_0677e830,(int)cVar2);
            FUN_00c433a0(uVar7);
            unaff_RBP = CONCAT71(uVar9,bVar8) & 0xffffffff;
          }
          else {
            iVar3 = (**(code **)(*param_2 + 0xd0))(param_2,0x8241e0);
            if ((iVar3 == 1) && (uVar5 < 0x1a80cd7)) {
              FUN_00c440d0(&DAT_0677e830,"boot ucode BROM rev revoked",0x1b);
              plVar1 = *(long **)(&DAT_0677e920 + (long)DAT_0677e830[-3]);
              if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
                FUN_00c84aa0();
              }
              if ((char)plVar1[7] == '\0') {
                FUN_00c7a0e0(plVar1);
                cVar2 = (**(code **)(*plVar1 + 0x30))(plVar1,10);
              }
              else {
                cVar2 = *(char *)((long)plVar1 + 0x43);
              }
              uVar7 = FUN_00c43cf0(&DAT_0677e830,(int)cVar2);
              FUN_00c433a0(uVar7);
              unaff_RBP = CONCAT71(uVar10,bVar11);
            }
            else {
              unaff_RBP = 1;
            }
          }
        }
      }
      goto LAB_007261e7;
    }
    bVar11 = iVar4 == 0x174;
    if ((iVar4 - 0x172U & 0xfffffffd) != 0) goto LAB_007261d1;
    if (iVar4 == 0x172) goto LAB_00725eff;
LAB_007266d4:
    if ((iVar3 == 1) && (uVar5 < 0x1b5a11e)) {
      FUN_00c440d0(&DAT_0677e830,"boot ucode SW rev is revoked",0x1c);
      plVar1 = *(long **)(&DAT_0677e920 + (long)DAT_0677e830[-3]);
      if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_00c84aa0();
      }
      if ((char)plVar1[7] == '\0') {
        FUN_00c7a0e0(plVar1);
        cVar2 = (**(code **)(*plVar1 + 0x30))(plVar1,10);
      }
      else {
        cVar2 = *(char *)((long)plVar1 + 0x43);
      }
      uVar7 = FUN_00c43cf0(&DAT_0677e830,(int)cVar2);
      FUN_00c433a0(uVar7);
      unaff_RBP = 0;
      goto LAB_007261e7;
    }
  }
  if (iVar4 == 0x176) {
    if ((iVar3 == 1) && (uVar5 < 0x1bc8045)) {
      FUN_00c440d0(&DAT_0677e830,"boot ucode SW rev is revoked",0x1c);
      plVar1 = *(long **)(&DAT_0677e920 + (long)DAT_0677e830[-3]);
      if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_00c84aa0();
      }
      if ((char)plVar1[7] == '\0') {
        FUN_00c7a0e0(plVar1);
        cVar2 = (**(code **)(*plVar1 + 0x30))(plVar1,10);
      }
      else {
        cVar2 = *(char *)((long)plVar1 + 0x43);
      }
      uVar7 = FUN_00c43cf0(&DAT_0677e830,(int)cVar2);
      FUN_00c433a0(uVar7);
      unaff_RBP = 0;
      goto LAB_007261e7;
    }
  }
  else if (((iVar4 == 0x177) && (iVar3 == 1)) && (uVar5 < 0x1ba89ce)) {
    FUN_00c440d0(&DAT_0677e830,"boot ucode SW rev is revoked",0x1c);
    plVar1 = *(long **)(&DAT_0677e920 + (long)DAT_0677e830[-3]);
    if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_00c84aa0();
    }
    if ((char)plVar1[7] == '\0') {
      FUN_00c7a0e0(plVar1);
      cVar2 = (**(code **)(*plVar1 + 0x30))(plVar1,10);
    }
    else {
      cVar2 = *(char *)((long)plVar1 + 0x43);
    }
    uVar7 = FUN_00c43cf0(&DAT_0677e830,(int)cVar2);
    FUN_00c433a0(uVar7);
    unaff_RBP = 0;
    goto LAB_007261e7;
  }
  iVar3 = (**(code **)(*param_2 + 0xd0))(param_2,0x8241e0);
  bVar11 = iVar3 == 3 && uVar5 < 0x1b5501d;
  if (bVar11) {
    FUN_00c440d0(&DAT_0677e830,"boot ucode BROM rev revoked",0x1b);
    plVar1 = *(long **)(&DAT_0677e920 + (long)DAT_0677e830[-3]);
    if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_00c84aa0();
    }
    if ((char)plVar1[7] == '\0') {
      FUN_00c7a0e0(plVar1);
      cVar2 = (**(code **)(*plVar1 + 0x30))(plVar1,10);
    }
    else {
      cVar2 = *(char *)((long)plVar1 + 0x43);
    }
    uVar7 = FUN_00c43cf0(&DAT_0677e830,(int)cVar2);
    FUN_00c433a0(uVar7);
    unaff_RBP = 0;
  }
  else if ((iVar3 == 1) && (uVar5 < 0x1b17786)) {
    FUN_00c440d0(&DAT_0677e830,"boot ucode BROM rev revoked",0x1b);
    plVar1 = *(long **)(&DAT_0677e920 + (long)DAT_0677e830[-3]);
    if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_00c84aa0();
    }
    if ((char)plVar1[7] == '\0') {
      FUN_00c7a0e0(plVar1);
      cVar2 = (**(code **)(*plVar1 + 0x30))(plVar1,10);
    }
    else {
      cVar2 = *(char *)((long)plVar1 + 0x43);
    }
    uVar7 = FUN_00c43cf0(&DAT_0677e830,(int)cVar2);
    FUN_00c433a0(uVar7);
    unaff_RBP = CONCAT71((int7)(unaff_RBP >> 8),bVar11);
  }
  else {
    unaff_RBP = 1;
  }
LAB_007261e7:
  return unaff_RBP & 0xffffffff;
}

