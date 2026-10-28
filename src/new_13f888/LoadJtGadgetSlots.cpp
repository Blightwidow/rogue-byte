struct CRef { int tagk; int n; int p2; int p3; };
extern "C" const char RO_002A4D50[];
extern "C" const char RO_002A4D58[];
extern "C" int sprintf(char *, const char *, ...);
extern "C" void func_001D8A38(CRef *, const char *, const char *, const char *, int);
extern "C" void CRef_Destruct(CRef *);
typedef const char *(*PFNROOT)(void *);
typedef void (*PFNVOID)(void *);
struct VT { char pad0[0x338]; short d338; short i338; PFNROOT f33C; char pad1[0x348 - 0x340]; short d348; short i348; PFNVOID f34C; };
struct SLOT { int gadget; int state; float t; };
struct JT { char pad0[0xC]; VT *vt; char pad1[0x1180 - 0x10]; SLOT aslot[3]; };

void LoadJtGadgetSlots(JT *jt)
{
    SLOT *aslot = jt->aslot;
    for (int index = 0; index < 3; index++) {
        char name[16];
        sprintf(name, RO_002A4D50, index);
        CRef ref;
        VT *vt = jt->vt;
        func_001D8A38(&ref, vt->f33C((char *)jt + vt->d338), RO_002A4D58, name, 0);
        aslot[index].gadget = ref.n;
        CRef_Destruct(&ref);
    }
    VT *vt = jt->vt;
    vt->f34C((char *)jt + vt->d348);
}
