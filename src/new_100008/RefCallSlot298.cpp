typedef short s16;
struct CRef { int tagk; int pad[3]; };
struct VT_10FC80 { char pad[0x298]; s16 delta; s16 p; void (*fn)(char *); };
struct Obj_10FC80 { int pad[3]; VT_10FC80 *vt; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, int, int);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" CRef *CRef_CopyConstruct(CRef *, CRef *);
extern "C" CRef *RefCallSlot298(CRef *result, Obj_10FC80 *obj, int arg2, int arg3)
{
    CRef ref;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 0, arg3, 0);
    CRef_Destruct(&ref);
    SetTag__4CRef4TAGK(&ref, 0x24);
    obj->vt->fn((char *)obj + obj->vt->delta);
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
