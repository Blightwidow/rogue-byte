#include "m2c_macros.h"

M2C_UNK PhitfxSpawn(M2C_UNK, M2C_UNK, s32);         /* extern */

void SpawnSwHitFx(void *arg0, s32 arg1, s32 arg3) {
    switch (arg1) {                                 /* irregular */
    case 1:
        break;
    case 0:
        break;
    }
    PhitfxSpawn(M2C_ERROR(/* Read from unset register $t0 */), M2C_ERROR(/* unknown instruction: por $a1, $zero, $a2 */), arg3);
}
