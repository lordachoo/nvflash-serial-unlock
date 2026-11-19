// main; entry 008597ed


undefined4 FUN_008597ed(undefined4 param_1,undefined8 param_2)

{
  undefined4 uVar1;
  undefined1 auStack_e8 [224];
  
  FUN_0087b322(auStack_e8,param_1,param_2);
                    /* try { // try from 00859805 to 00859809 has its CatchHandler @ 0085980c */
  uVar1 = FUN_0092406e(auStack_e8);
  FUN_0085e5ca(auStack_e8);
  return uVar1;
}

