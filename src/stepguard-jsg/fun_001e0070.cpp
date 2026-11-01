void *memmove(void *, const void *, unsigned int);
#define COUNT(g) (*(int *)((char *)(g) + 0x84))
extern "C" void func_001E0070(char *self, int target)
{
    int index;
    int *dst;
    int *src;
    for (index = 0; index < COUNT(self); index++) {
        dst = (int *)(self + 0x88) + index;
        src = dst + 1;
        if (*dst == target) {
            memmove(dst, src, (COUNT(self) - index) * 4 - 4);
            COUNT(self) -= 1;
            return;
        }
    }
}
