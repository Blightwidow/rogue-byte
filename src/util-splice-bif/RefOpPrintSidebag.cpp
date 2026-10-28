enum TAGK { kTagkVoid = 0x24, kTagkNil = -1 };
struct CRef { int tagk; int n; void SetTag(TAGK); };
extern "C" void CRef_Destruct(CRef *);
CRef *RefOpPrintSidebag(CRef *prefReturn)
{
    CRef refUnused;
    refUnused.tagk = kTagkNil;
    prefReturn->SetTag(kTagkVoid);
    CRef_Destruct(&refUnused);
    return prefReturn;
}
