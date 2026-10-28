// 0x129518 CRef_SetS32
extern "C" void CRef_Destruct(void *);

struct CRef {
    char pad[0x18];
    int n;
    int tagk;
};

void *CRef_SetS32(void *pref, int n)
{
    CRef_Destruct(pref);
    int *p = (int *)((char *)pref + 4);
    int *q = (int *)((char *)pref);
    p[0] = n;
    q[0] = 0x15;
    return pref;
}