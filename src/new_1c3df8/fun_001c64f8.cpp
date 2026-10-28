// 0x1C64F8 SetDprizeGlintOids
void func_001C64F8(void* arg0, int arg1, int arg2, int arg3)
{
    void** p2 = (void**)((char*)arg0 + 0x1A4);
    *p2 = (void*)arg1;
    void** p3 = (void**)((char*)arg0 + 0x1AC);
    *p3 = (void*)arg2;
    void** p = (void**)((char*)arg0 + 0x1B4);
    *p = (void*)arg3;
}
