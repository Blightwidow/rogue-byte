#include "sly2.h"
struct Mat3 { QW row[3]; };
struct VT { char pad[0x118]; short delta; short index; void (*fn)(char *, QW); };
struct Chaser { char pad0[0xC]; VT *vt; char pad1[0x194 - 0x10]; int owner; struct Sub *psub; char pad2[0x1C8 - 0x19C]; int flagA; int flagB; char pad3[0x204 - 0x1D0]; float angle; char pad4[0x210 - 0x208]; QW world; };
struct Sub { char pad[0x30]; int id; };
struct Msg { int sender; float value; int kind; };
extern "C" {
void HandlePoMessage(Chaser *, int, Msg *);
void LoadRotateMatrixRad(Mat3 *, QW, float);
QW func_00204E38(Chaser *, int, float);
}
extern QW g_2a2dc0;
void Chaser_HandleMessage(Chaser *chaser, int msg, Msg *pmsg)
{
    HandlePoMessage(chaser, msg, pmsg);
    if (msg == 9) {
        int sender = pmsg->sender;
        if (sender == chaser->owner || (chaser->psub != 0 && sender == chaser->psub->id)) {
            switch (pmsg->kind) {
            case 0x15E: {
                Mat3 rot;
                Mat3 mat;
                LoadRotateMatrixRad(&mat, g_2a2dc0, chaser->angle);
                rot = mat;
                QW vel = func_00204E38(chaser, pmsg->sender, pmsg->value);
                QW world;
                int chain;
                asm("lqc2 vf4, %1\n\tlqc2 vf2, %2\n\tlqc2 vf1, %3\n\tqmtc2.ni %4, vf5" : "=r" (chain) : "m" (rot.row[0]), "m" (rot.row[1]), "m" (rot.row[2]), "r" (vel));
                VT *vt = chaser->vt;
                asm("vmulax.xyz ACC, vf4, vf5x\n\tvmadday.xyz ACC, vf2, vf5y\n\tvmaddz.xyz vf3, vf1, vf5z\n\tsqc2 vf3, %1\n\tqmfc2.ni %0, vf3" : "=r" (world), "=m" (chaser->world) : "r" (chain));
                vt->fn((char *)chaser + vt->delta, world);
                break;
            }
            case 0x25:
                chaser->flagA = 1;
                break;
            case 0x26:
                chaser->flagA = 0;
                break;
            case 0x27:
                chaser->flagB = 1;
                break;
            case 0x28:
                chaser->flagB = 0;
                break;
            }
        }
    }
}
