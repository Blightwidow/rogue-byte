extern "C" {
typedef int s32;
void EnsureAsegBlendDynamic(s32, s32, s32, void *, s32, s32, s32, void *);

void func_001959C0(s32 *arg0) {
    char *base = (char *)arg0;
    EnsureAsegBlendDynamic(*arg0, 0xC, 5, base + 0x17C, 0, 0, 0, base + 0x1B8);
}
}
