struct EMITTER { char pad[0xE4]; char *pemitb; };
extern "C" void SetSuvSuvs(EMITTER *, int);
int * func_002595D0(EMITTER *pemitter, int ensk)
{
    if (ensk == 1)
        SetSuvSuvs(pemitter, 2);
    return (int *)(pemitter->pemitb + 0x10);
}
