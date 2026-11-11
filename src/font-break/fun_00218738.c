#include "types.h"

typedef struct INNER218738 {
    char pad0[0x10];
    s32 field_0x10;
} INNER218738;

typedef struct OUTER218738 {
    char pad0[8];
    INNER218738 *field_0x8;
} OUTER218738;

s32 func_00218738(OUTER218738 *arg0) {
    return arg0->field_0x8->field_0x10;
}
