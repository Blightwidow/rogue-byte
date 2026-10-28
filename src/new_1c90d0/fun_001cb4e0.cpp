extern "C" void SetLoGrfzon(void *, unsigned char);
extern "C" void func_001CB4E0(char *self, char *other)
{
    if (other) {
        if (!(*(unsigned long *)(self + 0x28) & (0x8000UL << 43)))
            SetLoGrfzon(self, *(unsigned char *)(other + 0x2D));
    }
}
