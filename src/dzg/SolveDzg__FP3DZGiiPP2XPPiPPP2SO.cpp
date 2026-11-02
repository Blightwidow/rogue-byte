typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct DzgFrame { s8 *list; s8 **cursor; s32 link; DzgFrame *prev; };
void AppendDlEntry(s8 *, s8 *);
void EnforceDzgDz__FP3DZGP2DZ(s8 *, s8 *);
M2C_UNK FillDzgDz(s8 *, s32, s8 *, s32);
void RemoveDlEntry(s8 *, s8 *);
s32 func_00158958(s8 *, s8 *);
extern DzgFrame *g_2dd2fc;
void SolveDzg__FP3DZGiiPP2XPPiPPP2SO(s8 *arg0, s32 arg1) {
    DzgFrame frame;
    s32 scratch[4];
    (void)scratch;
    s32 list = (s32)arg0 + 0x30;
    frame.cursor = (s8 **)list;
    frame.list = (s8 *)list;
    DzgFrame *old = g_2dd2fc;
    s32 link = *(s32 *)(list + 8);
    g_2dd2fc = &frame;
    frame.prev = old;
    s8 *head = *(s8 **)list;
    frame.link = link;
    frame.cursor = (s8 **)(head + link);
    s8 *node = head;
    while (node != NULL) {
        if (*(s32 *)node == 1) {
            if (*(s32 *)(node + 0x18) == 0) {
                FillDzgDz(arg0, arg1, node, func_00158958(arg0, node));
            }
            RemoveDlEntry(arg0 + 0x30, node);
            AppendDlEntry(arg0 + 0xC, node);
            *(s32 *)(arg0 + 0x3C) = *(s32 *)(arg0 + 0x3C) + 1;
        }
        s8 *next = *frame.cursor;
        frame.cursor = (s8 **)(next + frame.link);
        node = next;
    }
    EnforceDzgDz__FP3DZGP2DZ(arg0, NULL);
    g_2dd2fc = frame.prev;
    for (;;) {
        f32 best = -0.01f;
        s8 *sel = NULL;
        for (s8 *p = *(s8 **)(arg0 + 0x30); p != NULL; p = *(s8 **)(p + 0x20)) {
            f32 value = *(f32 *)(p + 0x10);
            if (value < best) { best = value; sel = p; }
        }
        if (sel == NULL) break;
        if (*(s32 *)(sel + 0x18) == 0) {
            FillDzgDz(arg0, arg1, sel, func_00158958(arg0, sel));
        }
        EnforceDzgDz__FP3DZGP2DZ(arg0, sel);
    }
}
}
