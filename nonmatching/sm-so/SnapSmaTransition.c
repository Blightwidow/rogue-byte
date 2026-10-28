#include "m2c_macros.h"

M2C_UNK EndSmaTransition(void *);                   /* extern */
M2C_UNK RetractAsega(void *);                       /* extern */
M2C_UNK SeekAsega(void *, M2C_UNK, M2C_UNK, f32);   /* extern */

void SnapSmaTransition(void *arg0) {
    f32 temp_f13;
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, void **, 0x30);
    if (temp_s0 != NULL) {
        M2C_FIELD(arg0, void **, 0x30) = NULL;
        temp_f13 = M2C_FIELD(temp_s0, f32 *, 0x40);
        if (temp_f13 < 0.0f) {
            SeekAsega(temp_s0, 0, 0, temp_f13);
        } else {
            SeekAsega(temp_s0, 2, 0, temp_f13);
        }
        RetractAsega(temp_s0);
        EndSmaTransition(arg0);
    }
}
