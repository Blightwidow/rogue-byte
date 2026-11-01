void *memmove(void *, const void *, unsigned int);
#define COUNT(g) (*(int *)((char *)(g) + 0x84))
extern "C" void func_001E0070(char *self, int target)
{
    int index = 0;
    int *dst = (int *)(self + 0x88);
    int *src = (int *)(self + 0x8C);
    while (index < COUNT(self)) {
        if (*dst == target) {
            memmove(dst, src, (COUNT(self) - index) * 4 - 4);
            COUNT(self) -= 1;
            return;
        }
        index++;
        src++;
        dst++;
    }
}
