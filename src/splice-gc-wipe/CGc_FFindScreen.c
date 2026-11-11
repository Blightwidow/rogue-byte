#include "types.h"

s32 FFindDlEntry(s32 *, s32);
extern s32 B_003D9E70;

void CGc_FFindScreen(s32 screen) {
    FFindDlEntry(&B_003D9E70, screen);
}
