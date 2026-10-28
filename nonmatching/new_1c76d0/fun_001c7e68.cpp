void *func_001CB518();
void func_001C7E68(void *a0)
{
    func_001CB518();
    char *s0 = (char *)a0;
    void **v0 = *(void ***)((char *)s0 + 0xC);
    void **fn = (void **)((char *)v0 + 0x264);
    ((void (*)(void *, int))(*fn))(s0 + *(short *)((char *)v0 + 0x260), 0);
}