// cmd registration; entry 0057b778 (seed 57b778)


long * FUN_0057b778(undefined4 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
                   undefined1 param_5)

{
  undefined8 *puVar1;
  long *plVar2;
  
  puVar1 = (undefined8 *)FUN_00c37a70(0xd0);
  *(undefined4 *)(puVar1 + 1) = 0;
  *puVar1 = &PTR_LAB_00d49aa0;
  puVar1[2] = &PTR_FUN_00d49bd0;
  puVar1[4] = puVar1 + 6;
  puVar1[5] = 0;
  *(undefined1 *)(puVar1 + 6) = 0;
  *(undefined4 *)(puVar1 + 9) = 0;
  puVar1[10] = 0;
  puVar1[0xb] = puVar1 + 9;
  puVar1[0xc] = puVar1 + 9;
  puVar1[0xd] = 0;
  puVar1[0x11] = 0;
  puVar1[0xf] = puVar1 + 0xf;
  puVar1[0x10] = puVar1 + 0xf;
  puVar1[0x14] = 0;
  puVar1[0x12] = puVar1 + 0x12;
  puVar1[0x13] = puVar1 + 0x12;
  puVar1[0x16] = puVar1 + 0x18;
  puVar1[0x17] = 0;
  *(undefined1 *)(puVar1 + 0x18) = 0;
  if (puVar1 == (undefined8 *)0x0) {
    plVar2 = (long *)0x0;
    if (DAT_0679f900 == (long *)0x0) {
      plVar2 = (long *)0x0;
      goto LAB_0057b878;
    }
LAB_0057b85a:
    (**(code **)(*DAT_0679f900 + 8))();
    DAT_0679f900 = (long *)0x0;
  }
  else {
    plVar2 = puVar1 + 2;
    if (DAT_0679f900 != (long *)0x0) goto LAB_0057b85a;
  }
  if (plVar2 != (long *)0x0) {
    (**(code **)*plVar2)(plVar2);
  }
LAB_0057b878:
  DAT_0679f900 = plVar2;
  (**(code **)(*plVar2 + 0x10))(plVar2,param_1,param_2,param_3,param_4,param_5);
  return DAT_0679f900;
}

