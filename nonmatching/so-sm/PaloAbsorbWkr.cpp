typedef int s128 __attribute__((mode(TI)));
extern "C" {
struct VT_1F7598 { char pad[0x18]; short delta18; short u18; void (*fn18)(char *, int, int, int); short delta20; short u20; void (*fn24)(char *, int, void *, char *); char pad2[0x230]; short delta258; short u258; int (*fn25c)(char *, char **, char *); };
struct OBJ_1F7598 { char pad[0xC]; VT_1F7598 *vt; };
struct Node_1F7598 { char *self; int f4; int f8; int fC; char pad[0x34]; int f44; char *f48; int f4c; char *next; };
int AppendDlEntry(void *, void *);
void ClearDle__FP3DLE(void *, float *, s128, s128);
int GrficFromAlo(char *, int);
void *PvAllocSlotheapImpl(void *);
char *func_001A5BF0(int);
extern char B_003E15A8;
extern Node_1F7598 *B_003E15C0;
extern float g_2dded0;
char *PaloAbsorbWkr(char **arg0) {
    struct { char dead[0x10]; char *a10[3]; int pad1c; char *a20[2]; char pad28[8]; char *sp30; } l;
    l.sp30 = func_001A5BF0(*(int *)((char *)arg0 + 8));
    while (l.sp30 != 0) {
        Node_1F7598 *node = B_003E15C0;
        while (node != 0) {
            if (node->self == arg0[0] && node->f4 == *(int *)((char *)arg0 + 4) && node->fC == *(int *)((char *)arg0 + 0xC) && node->f48 == l.sp30)
                return 0;
            node = (Node_1F7598 *)node->next;
        }
        *(int *)((char *)arg0 + 0x44) = GrficFromAlo(l.sp30, *(int *)((char *)arg0 + 0xC));
        if (((OBJ_1F7598 *)l.sp30)->vt->fn25c(l.sp30 + ((OBJ_1F7598 *)l.sp30)->vt->delta258, arg0, l.sp30) != 0) {
            *(char **)((char *)arg0 + 0x48) = l.sp30;
            char *copy = (char *)PvAllocSlotheapImpl(&B_003E15A8);
            s128 first;
            s128 second;
            char *source = (char *)arg0;
            char *dest = copy;
            do {
                first = *(s128 *)source;
                second = *(s128 *)(source + 0x10);
                *(s128 *)dest = first;
                *(s128 *)(dest + 0x10) = second;
                source += 0x20;
                dest += 0x20;
            } while (source != (char *)arg0 + 0x60);
            *(float *)(copy + 0x4C) = g_2dded0;
            ClearDle__FP3DLE(copy + 0x50, &g_2dded0, first, second);
            AppendDlEntry(&B_003E15C0, copy);
            if (*(int *)((char *)arg0 + 0x44) & 0xF8) {
                l.a10[0] = l.sp30;
                l.a10[1] = arg0[0];
                l.a10[2] = (char *)arg0;
                OBJ_1F7598 *vtobj = (OBJ_1F7598 *)l.sp30;
                vtobj->vt->fn24(l.sp30 + vtobj->vt->delta20, 0xB, l.a10, l.sp30);
                OBJ_1F7598 *other = (OBJ_1F7598 *)arg0[0];
                other->vt->fn24((char *)other + other->vt->delta20, 0xB, l.a10, (char *)other);
                l.a20[0] = (char *)&l.sp30;
                l.a20[1] = (char *)arg0 + 0xC;
                OBJ_1F7598 *third = (OBJ_1F7598 *)arg0[0];
                third->vt->fn18((char *)third + third->vt->delta18, 0xA, 1, 2);
                l.a20[0] = (char *)arg0;
                OBJ_1F7598 *fourth = (OBJ_1F7598 *)l.sp30;
                fourth->vt->fn18(l.sp30 + fourth->vt->delta18, 0xB, 1, 2);
            }
            return l.sp30;
        }
        l.sp30 = *(char **)(l.sp30 + 0x10);
    }
    return 0;
}
}
