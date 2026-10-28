#include "m2c_macros.h"

M2C_UNK ChooseSmaTransition(void *, M2C_UNK);       /* extern */
M2C_UNK EndSmaTransition(void *);                   /* extern */

void HandleSmaMessage(void *arg0, s32 arg1, s32 arg2) {
    void *sp0;
    void *temp_v0;
    void *temp_v0_2;

    if ((arg1 == 2) && (arg2 == M2C_FIELD(arg0, s32 *, 0x30))) {
        sp0 = arg0;
        temp_v0 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *), 0xC)(arg0 + M2C_FIELD(temp_v0, s16 *, 8));
        EndSmaTransition(arg0);
        ChooseSmaTransition(arg0, 0);
        temp_v0_2 = M2C_FIELD(sp0, void **, 0xC);
        M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, void *), 0x14)(sp0 + M2C_FIELD(temp_v0_2, s16 *, 0x10), sp0);
    }
}
