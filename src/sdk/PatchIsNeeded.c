// SPDX-License-Identifier: GPL-3.0-or-later
extern int GetOsdConfigParam(unsigned int *);
extern int SetOsdConfigParam(unsigned int *);
int PatchIsNeeded(void) {
    unsigned int original;
    unsigned int patched;
    GetOsdConfigParam(&original);
    patched = (original & 0xFFFF1FFF) | 0x2000;
    SetOsdConfigParam(&patched);
    GetOsdConfigParam(&patched);
    SetOsdConfigParam(&original);
    return ((patched >> 13) & 7) == 0;
}
