extern "C" {
void PostSoLoad();
int PvAllocSwImpl__Fi(char *arg0);

void CBomb_PostLoad(char *arg0)
{
    char sp[0x10] __attribute__((aligned(16)));

    PostSoLoad();
    if (*(int *)(arg0 + 0x1F4) != 0) {
        *(int *)(sp + 0) = 0xC0;
        *(int *)(sp + 4) = 0x10;
        *(int *)(arg0 + 0x1FC) = PvAllocSwImpl__Fi(sp);
    }
}
}
