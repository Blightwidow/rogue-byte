typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64;
#define NULL 0
struct Inner_2127C8 { char pad[0x58]; s32 state; s32 pad2; s32 start; s32 value; };
struct Node_2127C8 { char pad[0x40]; Inner_2127C8 *inner; char pad2[0x8]; Node_2127C8 *next; };
extern "C" {
extern Node_2127C8 *B_003E106C;
extern s32 g_2be538;
s32 func_002127C8(void) {
    Node_2127C8 *node;
    s32 value;
    for (node = B_003E106C; node != 0; node = node->next) {
        Inner_2127C8 *inner = node->inner;
        if (inner->state == 0) continue;
        if (inner->state == 1) {
            value = g_2be538 - inner->start;
        } else {
            value = inner->value;
        }
        if (value < 2) return 0;
    }
    return 1;
}
}
