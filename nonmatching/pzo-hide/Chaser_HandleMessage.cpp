#include "sly2.h"
struct MAT44 { QW rows[3]; };
struct VT { char pad[0x118]; short delta; short index; void (*fn)(char *, QW); };
extern "C" {
void HandlePoMessage(char *, int, int *);
void LoadRotateMatrixRad(MAT44 *, QW, float);
QW func_00204E38(char *, int, float, QW, QW, QW);
extern QW g_2a2dc0;
}

extern "C" void Chaser_HandleMessage(char *chaser, int msg, int *pmsg)
{
    HandlePoMessage(chaser, msg, pmsg);
    if (msg != 9)
        return;
    int sender = pmsg[0];
    if (sender != *(int *)(chaser + 0x194)) {
        char *owner = *(char **)(chaser + 0x198);
        if (owner == 0)
            return;
        if (sender != *(int *)(owner + 0x30))
            return;
    }
    int kind = pmsg[2];
    if (kind == 0x27) {
        *(int *)(chaser + 0x1CC) = 1;
    } else if (kind < 0x28) {
        if (kind == 0x25) {
            *(int *)(chaser + 0x1C8) = 1;
        } else if (kind == 0x26) {
            *(int *)(chaser + 0x1C8) = 0;
        }
    } else {
        if (kind == 0x28) {
            *(int *)(chaser + 0x1CC) = 0;
        } else if (kind == 0x15E) {
            QW mat[3];
            LoadRotateMatrixRad((MAT44 *)mat, g_2a2dc0, *(float *)(chaser + 0x204));
            QW rowA = mat[0];
            QW rowB = mat[1];
            QW rowC = mat[2];
            QW vel = func_00204E38(chaser, pmsg[0], *(float *)(pmsg + 1), rowA, rowB, rowC);
            QW out;
            asm("qmtc2.ni %0, vf5" : : "r"(vel));
            asm("lqc2 vf4, %0" : : "m"(rowA));
            asm("lqc2 vf2, %0" : : "m"(rowB));
            asm("lqc2 vf1, %0" : : "m"(rowC));
            asm("vmulax.xyz ACC, vf4, vf5x\n\tvmadday.xyz ACC, vf2, vf5y\n\tvmaddz.xyz vf3, vf1, vf5z");
            asm("sqc2 vf3, %0" : "=m"(*(QW *)(chaser + 0x210)));
            asm("qmfc2.ni %0, vf3" : "=r"(out));
            VT *vtable = *(VT **)(chaser + 0xC);
            vtable->fn(chaser + vtable->delta, out);
        }
    }
}
