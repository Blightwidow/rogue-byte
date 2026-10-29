// SPDX-License-Identifier: GPL-3.0-or-later
typedef int s32;

struct ALLOCREQ_1553F0 {
    int cb;
    int cbAlign;
};

extern "C" {
void *PvAllocSwClearImpl__Fi(ALLOCREQ_1553F0 *request);
void LoadStepFromBrx(char *owner, s32 brxIndex);

void func_001553F0(char *arg0, s32 arg1) {
    ALLOCREQ_1553F0 request;

    request.cb = 0x480;
    request.cbAlign = 0x10;
    *(void **)(arg0 + 0x1014) = PvAllocSwClearImpl__Fi(&request);
    LoadStepFromBrx(arg0, arg1);
    *(s32 *)(arg0 + 0x1018) = 0x7FFFFFFF;
}
}
