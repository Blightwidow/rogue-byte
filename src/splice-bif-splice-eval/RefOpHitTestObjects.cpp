struct CREF_124F00 { int tagk; int n; };
extern "C" {
CREF_124F00 *RefOpHitTestObjectsImpl(CREF_124F00 *, int, int, int, int);
int __as__4CRefRC4CRef(CREF_124F00 *, CREF_124F00 *);
void CRef_CopyConstruct(CREF_124F00 *, CREF_124F00 *);
void CRef_Destruct(CREF_124F00 *);
}
extern "C" CREF_124F00 *RefOpHitTestObjects(CREF_124F00 *pref, int carg, int aref, int pframe)
{
    CREF_124F00 result;
    CREF_124F00 temp;
    result.tagk = -1;
    RefOpHitTestObjectsImpl(&temp, 0x7B, carg, aref, pframe);
    __as__4CRefRC4CRef(&result, &temp);
    CRef_Destruct(&temp);
    CRef_CopyConstruct(pref, &result);
    CRef_Destruct(&result);
    return pref;
}
