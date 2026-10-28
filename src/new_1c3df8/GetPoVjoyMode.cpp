// 0x1C4080 GetPoVjoyMode
extern "C" int GetPoVjoyMode(void* arg0)
{
    int v1 = *(int*)((char*)arg0 + 0x150);
    int v0 = -1;
    if (v1 != 0)
        v0 = *(int*)(v1 + 0x80);
    return v0;
}
