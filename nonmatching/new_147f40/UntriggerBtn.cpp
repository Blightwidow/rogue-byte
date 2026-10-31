struct OBJ_148860;
struct VT1_148860 { char pad[0x18]; short delta; short unused; void (*fn)(void *, int, int, int, int, int); };
struct VT2_148860 { char pad[0x20]; short delta; short unused; void (*fn)(void *, int, void *); };
struct OBJ_148860 { char pad[0xC]; void *vt; };
extern "C" {
void RunBtnAsegs(OBJ_148860 **, int);
void UntriggerBtn(OBJ_148860 **arg0) {
    OBJ_148860 *obj = *arg0;
    VT1_148860 *vt = (VT1_148860 *)obj->vt;
    vt->fn((char *)obj + vt->delta, 6, 0, 0, 0, 0);
    RunBtnAsegs(arg0, 1);
    obj = *arg0;
    VT2_148860 *vt2 = (VT2_148860 *)obj->vt;
    vt2->fn((char *)obj + vt2->delta, 7, arg0);
}
}
