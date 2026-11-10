#include "types.h"

struct CLASSINFO {
    char pad[0xC];
    s32 cb;
    s32 (*pfnCreate)();
};

struct OBJVTBL {
    char pad[0x30];
    s16 delta;
    char pad2[2];
    struct CLASSINFO *(*pfnClassInfo)(char *);
};

struct OBJ {
    char pad[0xC];
    struct OBJVTBL *pvtbl;
};

s32 AppendSlEntry(s32 *, s32);              /* extern */
s32 ClearSl(s32);                               /* extern */
s32 ClearSle(s32);                              /* extern */
s32 CopyAb__FPvT0Ui(s32, void *, s32);          /* extern */
extern s32 B_003E159C;

s32 func_001ED850(struct OBJ *pobj) {
    s32 temp_v0;
    struct CLASSINFO *pclassinfo;
    struct OBJVTBL *pvtbl;

    pvtbl = pobj->pvtbl;
    pclassinfo = pvtbl->pfnClassInfo((char *)pobj + pvtbl->delta);
    temp_v0 = pclassinfo->pfnCreate();
    CopyAb__FPvT0Ui(temp_v0, pobj, pclassinfo->cb);
    ClearSl(temp_v0 + 0x34);
    ClearSle(temp_v0 + 0x40);
    AppendSlEntry(&B_003E159C, temp_v0);
    return temp_v0;
}
