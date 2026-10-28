typedef int QW __attribute__((mode(TI)));
struct CRef { int tagk; int n; int pad[2]; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef*, int, CRef*, int*, ...);
extern "C" CRef* CRef_Destruct(CRef*);
extern "C" CRef* CRef_SetBool(CRef*, int);
extern "C" void CRef_CopyConstruct(CRef*, CRef*);
extern "C" int func_00227C90(void*, QW);
extern "C" CRef* func_00104718(CRef* result, void* self, int count, CRef* args)
{
    struct F{QW vec; CRef ref; int types[1];} f;
    f.types[0] = 2;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&f.ref, 1, args, f.types, &f.vec);
    int inside = func_00227C90(self, f.vec);
    CRef_SetBool(&f.ref, inside != 0);
    CRef_CopyConstruct(result, &f.ref);
    CRef_Destruct(&f.ref);
    return result;
}
