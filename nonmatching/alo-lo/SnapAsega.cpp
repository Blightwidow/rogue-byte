typedef int QW __attribute__((mode(TI)));
struct Mat4_230CF0 { QW row[4]; };
struct VtA_230CF0 { char pad0[0x90]; short delta; short unused; void (*fn)(void *, void *); };
struct ObjA_230CF0 { char pad0[0xC]; VtA_230CF0 *vt; };
struct VtB_230CF0 { char pad0[0x10]; short delta; short unused; void (*fn)(void *, int, int, void *, float, float); };
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
extern char B_003DD490[];
extern QW g_2a2dd0;
void SnapAsega(Asega_230CF0 *self, int snap) {
    ObjA_230CF0 *acts[16];
    Mat4_230CF0 matrix;
    QW bezier;
    int count;
    if (FAsegaGone(self) == 0) {
        count = 0;
        for (Node_230CF0 *node = self->nodes; node != 0; node = node->next) {
            if (FActDrivesXf(node) != 0) {
                char *xf = node->xf;
                ObjA_230CF0 *act = node->act;
                RefreshXfActSegment(act, xf);
                switch (*(short *)(xf + 0x98)) {
                case 7:
                case 8:
                case 9:
                case 11:
                    if (snap == 0) break;
                case 0:
                case 13:
                default: {
                    int index;
                    int found = 0;
                    for (index = 0; index < count; index++) {
                        if (act == acts[index]) {
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        if ((unsigned)count < 16U) {
                            acts[count++] = act;
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
                            *(QW *)(xf + 0xC0), *(QW *)(xf + 0xD0), *(QW *)(xf + 0xE0), *(QW *)(xf + 0xF0), &bezier, 0, 0);
                        value = bezier;
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
                    BuildXfLocalMatrix(&matrix, xf, value);
                    *(Mat4_230CF0 *)xf = matrix;
                    *(QW *)(xf + 0xB0) = g_2a2dd0;
                    int generation = *(int *)(B_003DD490 + 0x3D58) + 1;
                    *(int *)(B_003DD490 + 0x3D58) = generation;
                    *(int *)(xf + 0xA4) = generation;
                    break;
                }
                }
            }
        }
        for (int slot = 0; slot < count; slot++) {
            ObjA_230CF0 *act = acts[slot];
            act->vt->fn((char *)act + act->vt->delta, act);
        }
        for (Link_230CF0 *link = self->links; link != 0; link = link->next) {
            ObjB_230CF0 *object = link->object;
            object->vt->fn((char *)object + object->vt->delta, link->arg, 0, object, self->timeA, self->timeB);
        }
    }
}
}
