struct CRef { int tagk; int n; };
struct CBasic;
extern "C" void CRef_ConstructBasic(CRef *, CBasic *);
extern "C" CBasic *B_003E0F9C;
extern "C" CRef *func_00123AD0(CRef *prefReturn)
{
    CRef_ConstructBasic(prefReturn, B_003E0F9C);
    return prefReturn;
}
