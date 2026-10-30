#include "sly2.h"
struct XFSO { char pad[0x148]; long grfso; };
extern "C" {
int FCheckJtEdgeGrab__FP2JTP2SOP6VECTOR3XPKPvT2(char *, char *, QW, int, void *, QW *);
int PcgtPointInCbspQuick__FP4CBSPP6VECTOR(int, int, int);
void RecalcSwXpMovement(void *, int, char **);
int bevy_player_p4_144068(char *);
extern char B_003DD490[];
extern int D_002BF8A8;
extern float D_FLT_002BF8A4;
extern float D_FLT_002C3C60[];
extern char g_2a2dc0[];
}
static inline int KindOf(char *node) {
    return ((int)((((long)((XFSO *)node)->grfso << 32) >> 32)) << 12) >> 28;
}
extern "C" char *PxpFindJtBestEdge__FP2JTPiP6VECTOR(char *jt, int *outFlag, QW *outEdge);
char *PxpFindJtBestEdge__FP2JTPiP6VECTOR(char *jt, int *outFlag, QW *outEdge) {
    struct Locals {
        QW edge;
        QW work1;
        QW work2;
        char *contact;
        int *flagOut;
    } locals;
    float bestDistance;
    char *best;
    char **list;
    locals.flagOut = outFlag;
    if (bevy_player_p4_144068(*(char **)jt) != 0) {
        return 0;
    }
    int kind = *(int *)(jt + 0x1C);
    if (kind != 1) {
        if (kind > 0) {
            if (kind < 6) {
                if (kind < 3) {
                    return 0;
                }
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    }
    int part = *(int *)(jt + 4);
    if (part < 0x11) {
        if (part >= 0xF) {
            return 0;
        }
    }
    list = *(char ***)(*(char **)(*(char **)jt + 0xEC) + 0x64);
    best = 0;
    if (list != 0) {
        do {
            locals.contact = *list;
            while (locals.contact != 0) {
                int flag = *(char **)jt != *(char **)(locals.contact + 8);
                char *other = *(char **)(locals.contact + ((1 - flag) << 6));
                char *node = *(char **)(other + 4);
                if (node != 0) {
                    while (node != 0 && KindOf(node) != 2) {
                        node = *(char **)(node + 0x10);
                    }
                    if (node != 0) {
                        goto next;
                    }
                }
                {
                    void *edgeData;
                    switch (*(int *)(locals.contact + 0x9C)) {
                    case 1:
                        if (flag == 0) {
                            goto next;
                        }
                        edgeData = *(void **)(locals.contact + 0xA0);
                        break;
                    case 3:
                        if (flag == 0) {
                            edgeData = *(void **)(locals.contact + 0xA4);
                        } else {
                            edgeData = *(void **)(locals.contact + 0xA0);
                        }
                        break;
                    case 2:
                        if (flag == 1) {
                            goto next;
                        }
                        edgeData = *(void **)(locals.contact + 0xA4);
                        break;
                    default:
                        goto next;
                    }
                    if (FCheckJtEdgeGrab__FP2JTP2SOP6VECTOR3XPKPvT2(jt, other, *(QW *)(locals.contact + ((1 - flag) << 6) + 0x10), *(int *)(locals.contact + 0x9C), edgeData, &locals.edge) == 0) {
                        goto next;
                    }
                    if ((*(long *)(*(char **)(*(char **)jt + 0xEC) + 0x70) & 2) || (*(long *)(*(char **)(*(char **)(other + 4) + 0xEC) + 0x70) & 2)) {
                        RecalcSwXpMovement(B_003DD490, 1, &locals.contact);
                    }
                    if (D_FLT_002C3C60[flag] * *(float *)(locals.contact + 0xB8) > 0.0f) {
                        goto next;
                    }
                    {
                        int offset = (1 - flag) << 6;
                        int bits;
                        asm volatile("qmtc2.ni %0, vf4" : : "r"(D_002BF8A8));
                        asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(locals.contact + offset));
                        asm volatile("lqc2 vf5, %0" : : "m"(locals.edge));
                        asm volatile("lqc2 vf1, (%0)" : : "r"(g_2a2dc0));
                        float negated = -D_FLT_002BF8A4;
                        asm volatile("qmtc2.ni %0, vf3" : : "r"(*(int *)&negated));
                        asm volatile("vadda.xyzw ACC, vf0, vf2");
                        asm volatile("vmaddax.xyzw ACC, vf5, vf3x");
                        asm volatile("vmaddx.xyzw vf2, vf1, vf4x");
                        asm volatile("sqc2 vf3, %0" : "=m"(locals.work2));
                        asm volatile("sqc2 vf2, %0" : "=m"(locals.work1));
                        asm volatile("sqc2 vf4, %0" : "=m"(locals.work2));
                        asm volatile("qmfc2.ni %0, vf2" : "=r"(bits));
                        if (PcgtPointInCbspQuick__FP4CBSPP6VECTOR(*(int *)(other + 0x74), 0x7FFFFFFF, bits) == 0 && (best == 0 || !(*(float *)(locals.contact + offset + 0x18) < bestDistance))) {
                            best = locals.contact;
                            bestDistance = *(float *)(best + offset + 0x18);
                            *locals.flagOut = flag;
                            *outEdge = locals.edge;
                        }
                    }
                }
            next:
                locals.contact = *(char **)(locals.contact + 0xAC);
            }
            list = *(char ***)(list + 1);
        } while (list != 0);
    }
    return best;
}
