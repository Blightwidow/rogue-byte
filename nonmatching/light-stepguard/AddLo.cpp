extern "C" void func_001A5448(void *, void *, void *);
extern "C" void RemoveDlEntry(void *, void *);
extern "C" void InsertDlEntryBefore(void *, void *, void *);
extern "C" void ReinsertSwRoot(void *, void *);
extern "C" int FIsLoInWorld(void *);
extern "C" void func_00148300(void *, void *);
extern "C" char B_003DD490[];

void AddLo(char *arg0)
{
    unsigned long flags;
    void *sp0;
    void **sp4;
    char *temp_v0;
    char *temp_v0_2;
    char *temp_v0_5;
    char *temp_v1_2;
    char *temp_v1_3;
    void *temp_a2;
    void (*temp_a1)(void *, void *, void *);
    int temp_v0_3;
    int var_s0;
    int sp8;

    flags = *(unsigned long *)(arg0 + 0x28);
    if (flags & (0x8000UL << 41)) {
        *(unsigned long *)(arg0 + 0x28) = flags & 0xFEFFFFFFFFFFFFFFUL;
        func_001A5448(*(void **)(arg0 + 0x10), &sp0, &sp4);
        if (arg0 == (char *)*sp4) {
            *sp4 = *(void **)(arg0 + 0x24);
        } else {
            RemoveDlEntry(sp0, arg0);
            InsertDlEntryBefore(sp0, *sp4, arg0);
        }
        temp_v0 = *(char **)(arg0 + 0x10);
        if (temp_v0 == 0 || (((*(unsigned long *)(temp_v0 + 0x28)) >> 0x3C) & 1)) {
            temp_v0_2 = *(char **)(arg0 + 0xC);
            ((void (*)(void *))(*(void **)(temp_v0_2 + 0x5C)))(arg0 + *(short *)(temp_v0_2 + 0x58));
        }
        if (*(void **)(arg0 + 0x10) == 0 && ((*(long *)(arg0 + 0x28) << 8) >> 0x3C) != 2) {
            ReinsertSwRoot(B_003DD490, *(void **)(arg0 + 0x14));
        }
        temp_v1_2 = *(char **)(arg0 + 0xC);
        var_s0 = 0;
        temp_v0_3 = ((int (*)(void *, int *))(*(void **)(temp_v1_2 + 0xE4)))(arg0 + *(short *)(temp_v1_2 + 0xE0), &sp8);
        if (temp_v0_3 > 0) {
            do {
                temp_a2 = ((void **)sp8)[var_s0];
                var_s0 += 1;
                temp_v1_3 = *(char **)((char *)temp_a2 + 0xC);
                temp_a1 = (void (*)(void *, void *, void *))(*(void **)(temp_v1_3 + 0x44));
                temp_a1((char *)temp_a2 + *(short *)(temp_v1_3 + 0x40), temp_a1, temp_a2);
            } while (var_s0 < temp_v0_3);
        }
        if (FIsLoInWorld(arg0) == 0) {
            if (*(void **)(arg0 + 0x10) == 0)
                func_00148300(B_003DD490, arg0);
        } else {
            temp_v0_5 = *(char **)(arg0 + 0xC);
            ((void (*)(void *))(*(void **)(temp_v0_5 + 0xBC)))(arg0 + *(short *)(temp_v0_5 + 0xB8));
        }
    }
}
