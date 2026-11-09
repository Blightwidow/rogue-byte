#include "types.h"
struct Mat4_230CF0 { QW row[4]; };
struct VtA_230CF0 { char pad0[0x90]; short delta; short unused; void (*fn)(void *); };
struct ObjA_230CF0 { char pad0[0xC]; VtA_230CF0 *vt; };
struct VtB_230CF0 { char pad0[0x10]; short delta; short unused; void (*fn)(void *, int, int, float, float); };
struct ObjB_230CF0 { VtB_230CF0 *vt; };
struct Link_230CF0 { ObjB_230CF0 *object; int arg; char pad8[8]; Link_230CF0 *next; };
struct Node_230CF0 { char pad0[4]; ObjA_230CF0 *act; char *xf; char pad0C[0x1C]; Node_230CF0 *next; };
struct Asega_230CF0 { char pad0[0x1C]; float timeA; char pad20[0x14]; Node_230CF0 *nodes; Link_230CF0 *links; char pad3C[4]; float timeB; };
extern "C" {
void BuildXfLocalMatrix(Mat4_230CF0 *, char *, QW);
QW DecomposeRotateMatrixEuler(char *);
void EvaluateBezierPos__FfffP6VECTORN63(float, float, float, QW, QW, QW, QW, QW *, QW *, QW *);
int FActDrivesXf(Node_230CF0 *);
int FAsegaGone(Asega_230CF0 *);
QW GetXfDofValue(char *, char *);
void RefreshXfActSegment(ObjA_230CF0 *, char *);
struct G_230CF0 { char pad[0x3D58]; int counter; };
extern G_230CF0 B_003DD490;
extern QW g_2a2dd0;
static inline int Bump(G_230CF0 *pg) { int next = pg->counter + 1; pg->counter = next; return next; }
static inline void CallAct(ObjA_230CF0 *object) { object->vt->fn((char *)object + object->vt->delta) ; }
static inline void CallLink(ObjB_230CF0 *object, int arg, float timeA, float timeB) { object->vt->fn((char *)object + object->vt->delta, arg, 0, timeA, timeB); }
// Retail's first jump table (0x2AA0A0) sends kinds 0 and 13 straight to the next node, kinds 7, 8, 9 and 11 through the
// `snap` test and every other kind to the update, so 0 and 13 are their own empty case. The link loop's virtual call
// passes a0 (adjusted object), a1, a2 = 0, f12 and f13 only: retail's $a3 merely holds the object pseudo (a free
// argument register), so the method takes (int, int, float, float) and no fourth integer argument.
void SnapAsega(Asega_230CF0 *self, int snap) {
    struct L { ObjA_230CF0 *acts[16]; QW bezier; Mat4_230CF0 matrix; } l;
    int count;
    int index;
    if (FAsegaGone(self) == 0) {
        count = 0;
        for (Node_230CF0 *node = self->nodes; node != 0; node = node->next) {
            if (FActDrivesXf(node) != 0) {
                char *xf = node->xf;
                ObjA_230CF0 *act = node->act;
                RefreshXfActSegment(act, xf);
                switch (*(short *)(xf + 0x98)) {
                case 0:
                case 13:
                    break;
                case 7:
                case 8:
                case 9:
                case 11:
                    if (snap == 0) break;
                default: {
                    for (index = 0; index < count; index++) {
                        if (act == l.acts[index]) break;
                    }
                    if (index >= count) {
                        if ((unsigned)count < 16U) {
                            l.acts[count++] = act;
                        }
                    }
                    QW value;
                    switch (*(short *)(xf + 0x9A)) {
                    case 0:
                        value = GetXfDofValue(xf, xf);
                        break;
                    case 1: {
                        float start = *(float *)(xf + 0x80);
                        EvaluateBezierPos__FfffP6VECTORN63(*(float *)(xf + 0x84) - start, **(float **)(xf + 0x88) - start, **(float **)(xf + 0x8C),
                            *(QW *)(xf + 0xC0), *(QW *)(xf + 0xD0), *(QW *)(xf + 0xE0), *(QW *)(xf + 0xF0), &l.bezier, 0, 0);
                        value = l.bezier;
                        break;
                    }
                    case 2:
                    case 3:
                    case 4:
                        value = *(QW *)(xf + 0xC0);
                        break;
                    case 5:
                        value = DecomposeRotateMatrixEuler(xf + 0xC0);
                        break;
                    default:
                        value = g_2a2dd0;
                        break;
                    }
                    BuildXfLocalMatrix(&l.matrix, xf, value);
                    *(Mat4_230CF0 *)xf = l.matrix;
                    *(QW *)(xf + 0xB0) = g_2a2dd0;
                    *(int *)(xf + 0xA4) = Bump(&B_003DD490);
                    break;
                }
                }
            }
        }
        for (index = 0; index < count; index++) {
            ObjA_230CF0 *act = l.acts[index];
            CallAct(act);
        }
        for (Link_230CF0 *link = self->links; link != 0; link = link->next) {
            CallLink(link->object, link->arg, self->timeA, self->timeB);
        }
    }
}
}
