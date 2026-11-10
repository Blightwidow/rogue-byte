#include "sly.h"
extern float g_2dded0;
extern "C" void GetJtCpdefi(JT *, int *);
extern "C" void func_0019EA00(void *, int *);

void func_0018A428(SLY *jt, int *cpdefi)
{
    if (jt->jts != 0 && jt->jts != 0x12 && jt->field_0x4CC != 0 && jt->field_0xF54 != 1)
        jt->field_0x1AA4 = g_2dded0;
    GetJtCpdefi(jt, cpdefi);
    switch (jt->jts) {
    case 8:
        func_0019EA00(&jt->field_0xF50, cpdefi);
        break;
    case 3: case 5: case 6:
        *cpdefi |= 1;
        break;
    }
}
