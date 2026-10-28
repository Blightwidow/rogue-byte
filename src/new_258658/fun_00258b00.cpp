struct EMITTER { char pad[0xE4]; char *pemitb; };
extern "C" void SetEmitterEmitok(EMITTER *, int);
int func_00258B00(EMITTER *pemitter, int ensk)
{
    if (ensk == 1)
        SetEmitterEmitok(pemitter, 1);
    return *(int *)(pemitter->pemitb + 0x30);
}
