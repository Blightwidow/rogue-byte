struct CRef { int tagk; int n; int pad[2]; CRef &operator=(const CRef &); };
struct GAME { char pad[0xC]; int arg; };
extern "C" {
void CRef_Destruct(CRef *);
void func_001D8B20(CRef *, CRef *, const char *, const char *, char *, int);
int sprintf(char *, const char *, ...);
void bevy_camera_follow_activity(GAME *, int, int);
extern const char RO_002A79A0[];
extern const char RO_002A79A8[];
extern const char RO_002A79B8[];
extern GAME B_002DEB30;
}

void SetGadgetAcquired(int gadget, int acquired)
{
    struct L { CRef ref; char name[0x20]; CRef result; CRef value; } l;
    l.ref.tagk = -1;
    sprintf(l.name, RO_002A79A0, gadget);
    l.value.tagk = 0x17;
    l.value.n = acquired != 0;
    func_001D8B20(&l.result, &l.value, RO_002A79A8, RO_002A79B8, l.name, 0);
    l.ref = l.result;
    CRef_Destruct(&l.result);
    CRef_Destruct(&l.value);
    if (acquired != 0) {
        B_002DEB30.arg = gadget;
        bevy_camera_follow_activity(&B_002DEB30, 0x3B, 0);
    }
    CRef_Destruct(&l.ref);
}
