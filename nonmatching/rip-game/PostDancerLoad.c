#include "m2c_macros.h"

M2C_UNK PostStepLoad();                             /* extern */
M2C_UNK ResolveDancerMoves(void *);                 /* extern */

void PostDancerLoad(void *arg0) {
    void *temp_v0;

    PostStepLoad();
    ResolveDancerMoves(arg0);
    temp_v0 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK), 0x27C)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x278), 0);
}
