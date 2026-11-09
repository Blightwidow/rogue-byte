#include "sly2.h"
struct Rows3 { QW row[3]; };
struct M4 { QW row[4]; };
#include "so.h"
#include "xf.h"
struct CARRY { char pad0[0x84]; SO *last; char pad1[0x94 - 0x88]; void *act94; void *act98; void *act9C; SO *attached; };
extern "C" {
void Carry_SetState(CARRY *, int);
void func_0012E460(void *);
void func_001A58D0(SO *, int, int);
QW PosLoWorld(LO *);
QW ConvertXfPos(int, XF *, QW);
void *func_0012DE58(float, SO *, XF *, int, QW, QW);
Rows3 *PmatLoWorld(LO *);
Rows3 ConvertXfMat(int, XF *, Rows3 *);
QW DecomposeRotateMatrixEuler(Rows3);
void *func_0012DC18(SO *, XF *, int, int, int, QW);
extern float g_2dded0;
extern float g_2c1ef4;
extern QW g_2a2dd0;
}

void func_001CD308(CARRY *carry, LO *target)
{
    if (!carry->attached) return;
    Carry_SetState(carry, -1);
    func_0012E460(&carry->act94);
    func_0012E460(&carry->act98);
    func_0012E460(&carry->act9C);
    if (target->psoParent) {
        M4 buffer;
        void *xf = target->Slot32(&buffer);
        SO *attached = carry->attached;
        attached->SetParent(target->psoParent, xf, 0xF);
    } else {
        func_001A58D0(carry->attached, 0, 0xF);
    }
    XF *xfNode = carry->attached->pxfLinear;
    QW local = ConvertXfPos(0, xfNode->pxfParent, PosLoWorld(target));
    carry->act94 = func_0012DE58(g_2dded0 + g_2c1ef4, carry->attached, xfNode, 5, local, g_2a2dd0);
    xfNode = carry->attached->pxfAngular;
    Rows3 matLocal;
    matLocal = ConvertXfMat(0, xfNode->pxfParent, PmatLoWorld(target));
    QW euler = DecomposeRotateMatrixEuler(matLocal);
    carry->act9C = func_0012DC18(carry->attached, xfNode, 5, 7, 2, euler);
    SO *placed = carry->attached;
    carry->last = placed;
    Carry_SetState(carry, 1);
    carry->attached = 0;
}
