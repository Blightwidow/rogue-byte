// SPDX-License-Identifier: GPL-3.0-or-later
typedef int s32;
typedef short s16;

extern "C" {
void UnsubscribeLoObject(char *subscriber, char *owner);

void ReleaseSeqnodeSma(char *arg0) {
    char *sma;
    char *object;
    char *vtable;
    s16 thisOffset;
    void (*releaseFunction)(char *);

    sma = *(char **)(arg0 + 0x58);
    if (sma != 0) {
        UnsubscribeLoObject(sma, arg0);
        object = *(char **)(arg0 + 0x58);
        vtable = *(char **)(object + 0xC);
        thisOffset = *(s16 *)(vtable + 0x10);
        releaseFunction = *(void (**)(char *))(vtable + 0x14);
        releaseFunction(object + thisOffset);
        *(char **)(arg0 + 0x58) = 0;
        *(s32 *)(arg0 + 0x5C) = 0;
    }
}
}
