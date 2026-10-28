enum TAGK { kTagkVoid = 0x24 };
struct CRef { int tagk; int n; void SetTag(TAGK); };
CRef *RefOpPrintFrame(CRef *prefReturn)
{
    prefReturn->SetTag(kTagkVoid);
    return prefReturn;
}
