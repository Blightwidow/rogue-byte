// 0x14D8C0 SetResetFlag
void SetResetFlag(void* pcm)
{
    int fCut = *(int*)((char*)pcm + 0x300);
    int v0 = 1;
    int v1 = fCut > v0;
    v0 = v1 ? fCut : v0;
    *(int*)((char*)pcm + 0x300) = v0;
}
