#include "types.h"
#include "so.h"

union VECQW {
    s128 quadword;
    struct {
        s32 x;
        s32 y;
        s32 z;
    };
};

extern "C" {
s128 VecVelocityAtPos(SO *, s32, s32);

void func_001FADD0(SO *so, s32 posA, s32 posB, VECQW *result) {
    if (so->pphys == 0) {
        result->z = 0;
        result->y = 0;
        result->x = 0;
        return;
    }
    result->quadword = VecVelocityAtPos(so, posA, posB);
}

}
