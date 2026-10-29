#include "m2c_macros.h"
extern "C" {
typedef struct Pdl { s32 a, b, c; } Pdl;
typedef struct Sw { char pad[0x3038]; Pdl pdls[1]; } Sw;

Pdl *PdlFromSwCid(Sw *arg0, s32 arg1) {
    return &arg0->pdls[arg1];
}
}
