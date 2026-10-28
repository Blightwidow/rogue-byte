struct EMITTER { char pad[0xE4]; char *pemitb; };
extern "C" void SetSuvSuvs(EMITTER *, int);
int func_00259598(EMITTER *pemitter, int ensk)
{
    if (ensk == 1)
        SetSuvSuvs(pemitter, 1);
    return *(int *)(pemitter->pemitb + 0x30);
}
