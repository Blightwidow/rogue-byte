typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
struct Node { char pad0[0x28]; struct Owner *owner; char pad1[0xB8]; Node *next; };
struct Owner { char pad[0x10]; s32 key; };
struct Holder { char pad[0x5C]; Node *head; };
extern "C" {
Node *PseqnodeFind(Holder *holder, s32 key, Node *skip) {
    s8 frame[0x10];  // a dead local: retail has a 16-byte frame with no stores
    for (Node *node = holder->head; node != NULL; node = node->next) {
        if (node == skip) continue;
        if (node->owner->key == key) return node;
    }
    return NULL;
}
}
