struct JT { char pad0[0x4CC]; int f4CC; char pad4D0[0xF50 - 0x4D0]; int f0F50; int f0F54; char padF58[0x18C8 - 0xF58]; int jts; char pad18CC[0x1AA4 - 0x18CC]; float f1AA4; };
extern float g_2dded0;
extern "C" void GetJtCpdefi(JT *, int *);
extern "C" void func_0019EA00(void *, int *);

void func_0018A428(JT *jt, int *cpdefi)
{
    if (jt->jts != 0 && jt->jts != 0x12 && jt->f4CC != 0 && jt->f0F54 != 1)
        jt->f1AA4 = g_2dded0;
    GetJtCpdefi(jt, cpdefi);
    switch (jt->jts) {
    case 8:
        func_0019EA00(&jt->f0F50, cpdefi);
        break;
    case 3: case 5: case 6:
        *cpdefi |= 1;
        break;
    }
}
