#include "types.h"

extern "C" {
s32 sceSifCheckStatRpc(void *);
void FlushCache(s32);
void func_00231F38(s32, s32, s32 *);
void printf(char *);
s32 sceSifCallRpc(void *, s32, s32, s32 *, s32, s32, s32, s32, s32);
extern char B_00443800[];
extern s32 *D_002C4660[];
extern s32 D_002C4668[];
extern s32 D_002C4678[];
extern s32 D_002C4680;
extern s32 D_002C46B8;
extern char RO_002AA1C8[];

void snd_SendCurrentBatch__Fv(void) {
    s32 index;
    s32 value;

    index = D_002C4680;
    func_00231F38(D_002C4678[index], *D_002C4660[index], D_002C4660[index]);
    while (sceSifCheckStatRpc(B_00443800) != 0) {
        if (D_002C46B8 == 0) {
            printf(RO_002AA1C8);
        }
        FlushCache(0);
    }
    index = D_002C4680;
    sceSifCallRpc(B_00443800, 0x4D, 1, D_002C4660[index], 0x1000 - D_002C4668[index], D_002C4678[index], (*D_002C4660[index] * 4) + 8, 0, 0);
    value = D_002C4680 != 1;
    D_002C4680 = value;
    *D_002C4660[value] = 0;
    D_002C4668[value] = 0xFFC;
}
}
