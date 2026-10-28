void SetBinocHudBlot(void* arg0, void* arg1)
{
    if (arg1 == 0) {
        *(int*)((unsigned char*)arg0 + 0x10) = *(int*)((unsigned char*)arg0 + 0xC);
        return;
    }
    *(int*)((unsigned char*)arg0 + 0x10) = (int)arg1;
}