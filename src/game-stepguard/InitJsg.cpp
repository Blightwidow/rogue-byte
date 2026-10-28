struct JSG { char pad[0x58]; int field58; char dl[4]; };
extern "C" void InitLo(JSG *);
extern "C" void InitDl__FP2DLi(void *, int);
extern "C" void InitJsg(JSG *jsg)
{
    InitLo(jsg);
    jsg->field58 = -1;
    InitDl__FP2DLi(jsg->dl, 0xE4);
}
