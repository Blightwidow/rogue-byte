extern "C" void InitXfm_thunk(void *);
void InitSpire(void *pspire)
{
    InitXfm_thunk(pspire);
    *(float *)((char *)pspire + 0x108) = 3.402823466e+38f;
}
