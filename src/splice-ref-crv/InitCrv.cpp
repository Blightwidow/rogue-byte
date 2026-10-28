extern "C" void InitXfm(void *);
extern "C" void InitCrv(void *crv)
{
    InitXfm(crv);
    *(int *)((char *)crv + 0x148) = -1;
    *(int *)((char *)crv + 0x178) = 1;
}
