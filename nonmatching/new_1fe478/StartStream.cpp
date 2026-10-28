struct VT { char pad[8]; short delta; short index; void (*fn)(void *); };
struct Obj { char pad[0xC]; VT *vt; };
extern "C" void StopStream(void *);
extern "C" void *func_001FCFA0(void *, int);
extern "C" void *NewStreamAmb(void *, int);
extern "C" void func_00259B48(void *, void *);
extern "C" void func_00227728(void *, int, int);
extern "C" void *PloFindSwObjectByClass(void *, int, int, int);
extern "C" int func_001FD0C0(void *, int);
extern "C" void *PsmaFindAlo(void *, int);
extern "C" char B_003DD490;
extern "C" char B_004435F0;

#define F(type, base, off) (*(type *)((char *)(base) + (off)))

void *StartStream(void *stream, int id, int noSubtitle)
{
    StopStream(stream);
    void *rec = func_001FCFA0(stream, id);
    if (rec == 0)
        return 0;
    void *amb = NewStreamAmb(rec, 0);
    func_00259B48((char *)stream + 0x200, amb);
    F(int, stream, 0x244) = 0;
    F(int, stream, 0x248) = 0;
    F(int, stream, 0x24C) = 0;
    if (noSubtitle == 0)
        func_00227728(&B_004435F0, id, F(int, rec, 0x48));
    if (F(int, rec, 0x48) != -1) {
        if (F(int, rec, 0x54) != 0) {
            void *plo = PloFindSwObjectByClass(&B_003DD490, 5, F(int, rec, 0x48), 0);
            if (plo) {
                for (int slot = 0; slot < 6; slot++) {
                    Obj **pslot = (Obj **)((char *)stream + 0x22C + slot * 4);
                    if (slot == 3)
                        F(void *, stream, 0x238) = plo;
                    else
                        *pslot = (Obj *)PsmaFindAlo(plo, func_001FD0C0(stream, slot));
                    Obj *obj = *pslot;
                    if (obj) {
                        VT *vt = obj->vt;
                        vt->fn((char *)obj + vt->delta);
                    }
                }
            }
        }
    }
    return F(void *, stream, 0x200);
}
