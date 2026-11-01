#include "sly2.h"
struct Rows3 { QW row[3]; };
struct Xf_1F8AD8 { char pad[0xA0]; int field; };
struct Obj_1F8AD8 { char pad[0x24]; Xf_1F8AD8 *xf; };
extern "C" {
Rows3 ConvertXfMat(int, int);
QW DecomposeRotateMatrixEuler(Rows3 *);
void func_001F89E0(void *, int, int, QW);
}
extern "C" void func_001F8AD8(Obj_1F8AD8 *obj, int a, int b)
{
    Rows3 copy;
    Rows3 matrix = ConvertXfMat(0, obj->xf->field);
    copy = matrix;
    QW euler = DecomposeRotateMatrixEuler(&copy);
    func_001F89E0(obj, a, b, euler);
}
