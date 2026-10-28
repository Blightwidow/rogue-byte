extern "C" void CRef_Destruct(void *pref);

int CRef_SetSymid(void *pref, int symid)
{
    CRef_Destruct(pref);
    *(int *)((char *)pref + 4) = symid;
    *(int *)((char *)pref + 0) = 0x18;
    return (int)pref;
}
