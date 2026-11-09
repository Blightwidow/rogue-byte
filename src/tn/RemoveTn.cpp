#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
struct UL { unsigned long v; } __attribute__((packed));
extern "C" {
void CancelSwCallbacks(M2C_UNK *, M2C_UNK, s32, long, s32);
void RemoveLoHierarchy();
extern M2C_UNK B_003DD490;
extern char RO_002A96E8[];
void RemoveTn(s32 arg0) {
    RemoveLoHierarchy();
    CancelSwCallbacks(&B_003DD490, 1, arg0, ((UL *)RO_002A96E8)->v, 0);
}
}
