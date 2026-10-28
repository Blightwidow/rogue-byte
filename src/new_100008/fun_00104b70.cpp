struct CRef { int tagk; int n; int pad[2]; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef*, int, CRef*, int*, ...);
extern "C" CRef* CRef_Destruct(CRef*);
extern "C" void SetTag__4CRef4TAGK(CRef*, int);
extern "C" void CRef_CopyConstruct(CRef*, CRef*);
extern "C" void SnapSmaToGoal(void*, int);
extern "C" CRef* func_00104B70(CRef* result, void* self, int count, CRef* args)
{
    int types[1];
    int value;
    CRef ref;
    types[0] = 6;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 1, args, types, &value);
    CRef_Destruct(&ref);
    SetTag__4CRef4TAGK(&ref, 0x24);
    SnapSmaToGoal(self, value);
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
