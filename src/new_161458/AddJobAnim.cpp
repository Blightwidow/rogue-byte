extern "C" {
/* SPDX-License-Identifier: GPL-3.0-or-later */
typedef int s32;

struct JobAnimEntry_162728 {
    s32 word0;
    s32 word1;
    s32 word2;
    s32 word3;
    s32 word4;
    s32 word5;
};

void AddJobAnim(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 count;
    struct JobAnimEntry_162728 *entries;
    struct JobAnimEntry_162728 *entry;

    if (*(s32 *)(arg0 + 0x50) == 0) {
        count = *(s32 *)(arg0 + 0x94);
        if (count < 0x20) {
            *(s32 *)(arg0 + 0x94) = count + 1;
            entries = *(struct JobAnimEntry_162728 **)(arg0 + 0x98);
            entry = (struct JobAnimEntry_162728 *)((char *)entries + count * 0x18);
            entry->word5 = arg5;
            entry->word0 = arg1;
            entry->word1 = arg2;
            entry->word2 = arg3;
            entry->word3 = arg4;
            entry->word4 = 0;
        }
    }
}

}
