#include "m2c_macros.h"
extern "C" {

s32 func_001FD080(void *arg0, s32 arg1) {
    void *node;

    node = M2C_FIELD(arg0, void **, 0xF0);
    while (node != NULL) {
        if ((s32)node == arg1) {
            return 1;
        }
        node = M2C_FIELD(node, void **, 0x44);
    }
    return ((M2C_FIELD(arg0, s32 *, 0xF4) ^ arg1) == 0) ? 0 : 2;
}
}
