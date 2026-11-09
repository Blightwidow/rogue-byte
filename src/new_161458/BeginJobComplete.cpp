#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK AdvanceAfterJobEnd(s8 *);                 /* extern */
M2C_UNK PublishJobEnd(s8 *);                      /* extern */
M2C_UNK SetJobEndSequence(s8 *, M2C_UNK);                 /* extern */

void BeginJobComplete(s8 *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0xB8) != 0) {
        SetJobEndSequence(arg0, 1);
        return;
    }
    PublishJobEnd(arg0);
    AdvanceAfterJobEnd(arg0);
}

}
