#include "sly2.h"
extern "C" {
QW ConvertXfPos__Fiii(int, int, QW);
void func_001F89E0__FPviii(void *, int, int, QW);
struct OBJ_1F8A78 { char pad[0x24]; char *xf; };
void func_001F8A78__FPvii(OBJ_1F8A78 *arg0, int arg1, int arg2, QW arg3) {
    QW result = ConvertXfPos__Fiii(0, *(int *)(arg0->xf + 0xA0), arg3);
    func_001F89E0__FPviii(arg0, arg1, arg2, result);
}
}
