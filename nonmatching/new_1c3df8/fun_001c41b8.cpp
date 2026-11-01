struct CRef;
extern "C" void CRef_Destruct(CRef *);
struct CRef { int tagk; int n; int p2; int p3; ~CRef() { CRef_Destruct(this); } };
struct VT_1C41B8 { char pad0[0x18]; short delta; short index; void (*fn)(void *, int, int, int, int, CRef *); };
struct OBJ_1C41B8 { char pad0[0xC]; VT_1C41B8 *vt; };
int func_001C41B8(OBJ_1C41B8 *self)
{
    CRef ref;
    ref.n = 1;
    ref.tagk = 0x17;
    self->vt->fn((char *)self + self->vt->delta, 0xD, 0, 0, 0, &ref);
    return ref.tagk == 0x17 ? ref.n : 1;
}
