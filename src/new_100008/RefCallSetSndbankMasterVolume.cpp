struct CRef { int tagk; int n; int pad[2]; };
extern "C" void *RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef*, int, CRef*, int*, ...);
extern "C" void CRef_Destruct(CRef*);
extern "C" void SetTag__4CRef4TAGK(CRef*, int);
extern "C" void CRef_CopyConstruct(CRef*, CRef*);
extern "C" void SetSndbankMasterVolume(void*, float);
extern "C" CRef* RefCallSetSndbankMasterVolume(CRef* result, void* self, int count, CRef* args)
{
    int types[1];
    float value;
    CRef ref;
    types[0] = 0x1;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 1, args, types, &value);
    CRef_Destruct(&ref);
    SetTag__4CRef4TAGK(&ref, 0x24);
    SetSndbankMasterVolume(self, value);
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
