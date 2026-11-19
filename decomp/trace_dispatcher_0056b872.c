// dispatcher  entry 0056b872  name FUN_0056b872


undefined4 FUN_0056b872(long param_1,long *param_2,long *param_3,undefined8 param_4)

{
  long *plVar1;
  undefined4 uVar2;
  int iVar3;
  long *local_38;
  long *local_30;
  
  plVar1 = *(long **)(param_1 + 8);
  if (plVar1 == (long *)0x0) {
    uVar2 = 1;
  }
  else {
    uVar2 = (**(code **)(*plVar1 + 0x10))(plVar1);
    if ((char)uVar2 == '\0') {
      uVar2 = 1;
    }
    else {
      iVar3 = (**(code **)(**(long **)(param_1 + 8) + 0x18))();
      if (iVar3 == 1) {
        local_38 = (long *)*param_2;
        if (local_38 != (long *)0x0) {
          (**(code **)*local_38)();
        }
                    /* try { // try from 0056b90e to 0056b912 has its CatchHandler @ 0056b94b */
        uVar2 = FUN_0056a7f8(param_1,&local_38,param_4);
        if (local_38 != (long *)0x0) {
          (**(code **)(*local_38 + 8))();
        }
      }
      else if (iVar3 == 2) {
        local_30 = (long *)*param_3;
        if (local_30 != (long *)0x0) {
          (**(code **)*local_30)();
        }
                    /* try { // try from 0056b8ec to 0056b8f0 has its CatchHandler @ 0056b965 */
        uVar2 = FUN_0056a1a2(param_1,&local_30,param_4);
        if (local_30 != (long *)0x0) {
          (**(code **)(*local_30 + 8))();
        }
      }
    }
  }
  return uVar2;
}

