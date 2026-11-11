#include "types.h"

void CGc_UpdateTop(s32 *);
s32 FFindDlEntry(s32 *, s32);
void PrependDlEntry(s32 *, s32);
void RemoveDlEntry(s32 *, s32);
extern s32 B_003D9E70;

void CGc_PushScreen(s32 screen) {
    if (FFindDlEntry(&B_003D9E70, screen) != 0) {
        RemoveDlEntry(&B_003D9E70, screen);
    }
    PrependDlEntry(&B_003D9E70, screen);
    CGc_UpdateTop(&B_003D9E70);
}
