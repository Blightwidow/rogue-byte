#include "m2c_macros.h"

M2C_UNK BuildLaserBeams(s32);                       /* extern */
M2C_UNK ClipLaserBeams(s32, M2C_UNK);               /* extern */
M2C_UNK PostSoLoad();                               /* extern */
M2C_UNK func_001DEDB0(s32);                         /* extern */

void PostLoadLaser(s32 arg0) {
    PostSoLoad();
    BuildLaserBeams(arg0);
    func_001DEDB0(arg0);
    ClipLaserBeams(arg0, 0);
}
