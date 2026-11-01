struct OBJ;
struct VT0 { short delta; short index; void (*fn)(void *, OBJ *); };
struct VT1 { short delta; short index; void (*fn)(void *, int, int, int, int, int); };
struct OBJ { char pad[0xC]; char *vt; };
extern "C" OBJ *PpoSwFocusBase(void *);
extern "C" char B_003DD490[];
extern "C" void func_00228170(OBJ *pobj)
{
    OBJ *pfocus = PpoSwFocusBase(B_003DD490);
    if (pfocus != 0) {
        VT0 *slot0 = (VT0 *)(pfocus->vt + 0x130);
        slot0->fn((char *)pfocus + slot0->delta, pobj);
        VT1 *slot1 = (VT1 *)(pobj->vt + 0x18);
        slot1->fn((char *)pobj + slot1->delta, 5, 0, 0, 0, 0);
    }
}
