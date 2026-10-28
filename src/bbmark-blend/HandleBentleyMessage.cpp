struct VT { char pad[0x260]; short delta; short idx; void (*fn)(void *, int); };
struct GOBJ { char pad0[0xC]; VT *vt; char pad1[0x14C]; int gadget; };
struct POOL { int pad; int *ppool; };
struct SLOT { int plo; int pad; int unk8; };
struct BENTLEY {
    char pad0[0x1030]; int idOwn;
};
extern "C" {
void HandleJtMessage(void *, int, int *);
void *PloLeaseCloneObject(int, int);
void LockLeaseOfPlo(int, void *);
void ThrowBentleyBomb(void *, int);
void HandleLookRigMessage(void *, int, int *);
void func_0018D698(void *, void *, int);
}
#define PI(off) (*(int *)((char *)pbentley + (off)))
extern "C" void HandleBentleyMessage(char *pbentley, int msgid, int *pv)
{
    HandleJtMessage(pbentley, msgid, pv);
    if (msgid != 1) {
        if (msgid == 9) {
            if (pv[0] == PI(0x1030)) {
                if (pv[2] == 0x216) {
                    void *plo = PloLeaseCloneObject(((int *)PI(0x16B4))[1], 0);
                    PI(0x186C) = (int)plo;
                    LockLeaseOfPlo(((int *)PI(0x16B4))[1], plo);
                    *(int *)(PI(0x186C) + 0x15C) = *(int *)PI(0x16B4);
                    GOBJ *pgadget = *(GOBJ **)(pbentley + 0x186C);
                    pgadget->vt->fn((char *)pgadget + pgadget->vt->delta, 0);
                }
            } else if (pv[0] == PI(0x16CC)) {
                if (pv[2] == 0x243)
                    ThrowBentleyBomb(pbentley, 0x80000);
            } else {
                HandleLookRigMessage(pbentley + 0x1710, 9, pv);
            }
        }
    } else {
        int islot;
        char *pslot = pbentley + 0x1824;
        for (islot = 5; islot >= 0; islot--, pslot += 0xC) {
            if (*(int **)(pslot + 8) == pv)
                func_0018D698(pbentley, pslot, 0);
        }
    }
}
