#include "sly2.h"
struct SHD { int oid; char pad[0x2C - 4]; };
extern "C" {
extern int B_003DCFE8;
extern SHD *B_003DCFEC;
SHD *PshdFindShader__F3OID(int oid)
{
    if (oid == -1) return 0;
    for (int i = 0; i < B_003DCFE8; i++) {
        if (B_003DCFEC[i].oid == oid) return &B_003DCFEC[i];
    }
    return 0;
}
}
