#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
extern "C" {
void AddDirectPacket(s32, M2C_UNK, M2C_UNK *);
void func_0016E228();
extern M2C_UNK B_002DF010;
extern s32 B_003DCFA0;

void func_0016E380(s32 arg0) {
    func_0016E228();
    if (B_003DCFA0 > 0) {
        AddDirectPacket(arg0, 0x25, &B_002DF010);
    }
}

}
