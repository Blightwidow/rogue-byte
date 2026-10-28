#include "m2c_macros.h"

M2C_UNK CBinaryInputStream_Read_thunk(s32, s32, M2C_UNK); /* extern */
s32 U16Read__18CBinaryInputStream();                /* extern */

void Unknown1__18CBinaryInputStream(s32 arg0) {
    CBinaryInputStream_Read_thunk(arg0, U16Read__18CBinaryInputStream(), 0);
}
