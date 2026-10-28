struct EMITTER { char pad[0xE4]; char *pemitb; };
extern "C" void SetSuvSuvs(EMITTER *, int);
int * func_00259560(EMITTER *pemitter, int ensk)
{
    if (ensk == 1)
        SetSuvSuvs(pemitter, 0);
    return (int *)(pemitter->pemitb + 0x10);
}
