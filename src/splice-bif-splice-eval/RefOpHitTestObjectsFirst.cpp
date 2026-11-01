struct CREF_124F80 { int tagk; int n; };
extern "C" {
CREF_124F80 *RefOpHitTestObjectsImpl(CREF_124F80 *, int, int, int, int);
int __as__4CRefRC4CRef(CREF_124F80 *, CREF_124F80 *);
void CRef_CopyConstruct(CREF_124F80 *, CREF_124F80 *);
void CRef_Destruct(CREF_124F80 *);
}
extern "C" CREF_124F80 *RefOpHitTestObjectsFirst(CREF_124F80 *pref, int carg, int aref, int pframe)
{
    CREF_124F80 result;
    CREF_124F80 temp;
    result.tagk = -1;
    RefOpHitTestObjectsImpl(&temp, 0x7C, carg, aref, pframe);
    __as__4CRefRC4CRef(&result, &temp);
    CRef_Destruct(&temp);
    CRef_CopyConstruct(pref, &result);
    CRef_Destruct(&result);
    return pref;
}
