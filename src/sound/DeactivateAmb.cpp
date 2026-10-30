typedef int s32; typedef short s16;
struct VEnt { char pad0[0x10]; s16 adj; s16 pad; void (*fn)(void *); };
struct Obj { char pad[0xC]; VEnt *vt; };
extern "C" {
s32 FFindDlEntry(void *, void *);
void RemoveDlEntry(void *, void *);
extern char B_003DD08C;
void DeactivateAmb(Obj *arg0) {
    if (FFindDlEntry(&B_003DD08C, arg0) != 0) {
        RemoveDlEntry(&B_003DD08C, arg0);
        VEnt *vt = arg0->vt;
        void (*fn)(void *) = vt->fn;
        fn((char *)arg0 + vt->adj);
    }
}
}
