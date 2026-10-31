extern "C" {
void func_001F3C70(char *);
extern float g_2dded0;
struct Group_21C340 { int count; char *emitters; };
struct Block_21C340 { char pad0[4]; int count; char *entries; Block_21C340 *next; };
void func_0021C340(char *self) {
    char frame[0x10] __attribute__((aligned(16))); /* retail's frame holds the two sqc2 scratch stores */
    Block_21C340 *block;
    for (block = *(Block_21C340 **)(self + 0xDC); block != 0; block = block->next) {
        int index;
        for (index = 0; index < block->count; index++) {
            char *entry = block->entries + (index << 5);
            char *particle = *(char **)(entry + 0x1C);
            char *positions = *(char **)(entry + 0xC);
            char *alphas = *(char **)(entry + 0x14);
            char *angles = *(char **)(entry + 0x10);
            int slot;
            for (slot = 0; slot < *(int *)entry; slot++) {
                int count = *(int *)(self + 0x158);
                char *frames = *(char **)(self + 0x15C);
                float scaled = *(float *)(particle + 0x10) * (float)(count - 2);
                asm volatile("lqc2 vf8, (%0)" : : "r"(particle));
                int whole = (int)scaled;
                int older = (*(int *)(self + 0x160) + count - whole - 1) % count;
                float fraction = scaled - (float)whole;
                asm volatile("qmtc2.ni %0, vf7" : : "r"(fraction));
                asm volatile("qmtc2.ni %0, vf6" : : "r"(1.0f - fraction));
                asm volatile("sqc2 vf6, (%0)" : : "r"(frame));
                char *newer = frames + older * 0x50;
                char *newerRows = newer + 0x10;
                asm volatile("lqc2 vf5, 0x10(%0)" : : "r"(newer));
                asm volatile("lqc2 vf3, 0x30(%0)" : : "r"(newerRows));
                asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(newerRows));
                asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(newerRows));
                asm volatile("sqc2 vf7, (%0)" : : "r"(frame));
                asm volatile("vmulax.xyz ACC, vf5, vf8x");
                asm volatile("vmadday.xyz ACC, vf2, vf8y");
                asm volatile("vmaddaz.xyz ACC, vf1, vf8z");
                asm volatile("vmaddw.xyz vf5, vf3, vf0w");
                char *prior = frames + ((older + count - 1) % count) * 0x50;
                char *priorRows = prior + 0x10;
                asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(prior));
                asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(priorRows));
                asm volatile("lqc2 vf4, 0x30(%0)" : : "r"(priorRows));
                asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(priorRows));
                asm volatile("vmulax.xyz ACC, vf2, vf8x");
                asm volatile("vmadday.xyz ACC, vf3, vf8y");
                asm volatile("vmaddaz.xyz ACC, vf1, vf8z");
                asm volatile("vmaddw.xyz vf2, vf4, vf0w");
                asm volatile("vmulax.xyzw ACC, vf5, vf6x");
                asm volatile("vmaddx.xyzw vf1, vf2, vf7x");
                int bits;
                int zBits, yBits;
                asm volatile("qmfc2.ni %0, vf1" : "=r"(bits));
                asm("pextuw %0, %1, %2" : "=r"(zBits) : "r"(0), "r"(bits));
                *(int *)positions = bits;
                asm("prot3w %0, %1" : "=r"(yBits) : "r"(bits));
                *(int *)(positions + 4) = yBits;
                *(int *)(positions + 8) = zBits;
                positions += 0x10;
                if (alphas != 0) {
                    float life = 1.0f - ((g_2dded0 - *(float *)newer) / *(float *)(self + 0x150));
                    if (life < 0.0f) {
                        life = 0.0f;
                    } else if (life > 1.0f) {
                        life = 1.0f;
                    }
                    alphas[3] = (char)(int)(*(float *)(newer + 4) * life * (float)*(unsigned char *)(particle + 0x1B));
                    alphas += 4;
                }
                if (angles != 0 && *(int *)(self + 0x180) != 0) {
                    int packed = (int)((((1.0f - fraction) * *(float *)(newer + 8)) + (fraction * *(float *)(prior + 8))) * 4096.0f);
                    angles[0] = (char)packed;
                    angles[1] = (char)(packed >> 8);
                    angles += 6;
                }
                particle += 0x20;
            }
        }
    }
    float saved = *(float *)(self + 0x12C);
    *(float *)(self + 0x12C) = 1.0f;
    func_001F3C70(self);
    *(float *)(self + 0x12C) = saved;
}
}
