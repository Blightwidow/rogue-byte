#include "m2c_macros.h"

M2C_UNK CBinaryFileStream_Close();                  /* extern */
M2C_UNK __builtin_delete(void *);                   /* extern */
extern M2C_UNK D_002D2918;

void CBinaryFileStream_Destructor(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0x30) = &D_002D2918;
    CBinaryFileStream_Close();
    if (arg1 & 1) {
        __builtin_delete(arg0);
    }
}
