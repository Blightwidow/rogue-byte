struct VT_1FF188 { char pad[0x10]; short delta; short unused; void (*fn)(char *); };
struct OBJ_1FF188 { char pad[0xC]; VT_1FF188 *vt; };
extern "C" {
void BASIC_Destruct(void *, int);
void CreateSlotheapSwAlign(void *, int, int, int);
void func_001FCD38(void *);
extern int B_002DD2E0, B_002DD2E4, B_002DD2E8, B_002DD2EC, B_002DD2F0, B_002DD2F4;
extern char B_004520A8[], B_004520D0[], B_004520F8[], B_00452120[], B_00452148[], B_00452170[];
}
struct Ref_1FF188 {
    OBJ_1FF188 *object;
    ~Ref_1FF188() {
        if (object != 0) object->vt->fn((char *)object + object->vt->delta);
    }
};
struct Basic_1FF188 {
    char pad[0x200];
    ~Basic_1FF188() { BASIC_Destruct(this, 2); }
};
struct SND_1FF188 : Basic_1FF188 {
    Ref_1FF188 obj200;
    char pad204[4];
    Ref_1FF188 array[8];
    Ref_1FF188 obj228;
    ~SND_1FF188() {}
};
extern SND_1FF188 B_003DD040;
extern "C" void StaticInitDestroySndbank(int arg0, int arg1) {
    if (arg1 == 0xFFFF) {
        if (arg0 != 0) {
            func_001FCD38(&B_003DD040);
            if (++B_002DD2E0 == 1) CreateSlotheapSwAlign(B_004520A8, 0x14, 0x2000, 0x10);
            if (++B_002DD2E4 == 1) CreateSlotheapSwAlign(B_004520D0, 0x18, 0x800, 0x10);
            if (++B_002DD2E8 == 1) CreateSlotheapSwAlign(B_004520F8, 0x28, 0x200, 0x10);
            if (++B_002DD2EC == 1) CreateSlotheapSwAlign(B_00452120, 0x1C, 0x800, 0x10);
            if (++B_002DD2F0 == 1) CreateSlotheapSwAlign(B_00452148, 0xC, 0xC8, 0x10);
            if (++B_002DD2F4 == 1) CreateSlotheapSwAlign(B_00452170, 0x14, 0x100, 0x10);
        } else {
            B_003DD040.~SND_1FF188();
        }
    }
}
