extern "C" void CRef_Destruct(void *);

struct CRef {
    char pad[0x18];
    int n;
    int tagk;
};

void *CRef_SetBool(void *pref, int n)
{
    CRef_Destruct(pref);
    int *p = (int *)((char *)pref + 4);
    int *q = (int *)((char *)pref);
    p[0] = n;
    q[0] = 0x17;
    return pref;
}