#include "m2c_macros.h"

s32 FActiveCplcy(M2C_UNK *);                        /* extern */
extern M2C_UNK B_002DE2E0;

s32 func_0018D500(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0xF04) != 1) {
        return (FActiveCplcy(&B_002DE2E0) != 0) ? 0 : 1;
    }
    return 0;
}
