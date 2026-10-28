#include "m2c_macros.h"

M2C_UNK StartBootQueue(M2C_UNK *);                  /* extern */
extern M2C_UNK B_002E1E88;

void RestartBootQueue(void) {
    StartBootQueue(&B_002E1E88);
}
