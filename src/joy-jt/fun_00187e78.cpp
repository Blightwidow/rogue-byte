// 0x187E78 ResetJoyNav
void func_00187E78(void *p)
{
    *(int *)((char *)p + 0x1024) = 0;
    *(int *)((char *)p + 0x1028) = 0;
    return;
}