typedef int s32; typedef short s16; typedef long s64;
extern "C" {
struct VT_209970 { char pad0[0x18]; s16 d18; s16 p1a; void (*fn1c)(char *, s32, s32, s32, void *, s32); };
struct Obj_209970 { char pad[0xC]; VT_209970 *vt; char pad1[0x2C0 - 0x10]; s64 grfsgs; };
struct Args_209970 { s32 *pa; s32 *pb; };
s64 GrfsgsFromSgs(s32, s32);
void SetGuardGrfsgs(Obj_209970 *, s64);
void RemoveGuardSgs(Obj_209970 *arg0, s32 arg1) {
    Args_209970 args;
    s32 sp10;
    s32 sp14;
    sp14 = arg1;
    SetGuardGrfsgs(arg0, arg0->grfsgs & ~GrfsgsFromSgs(arg1, arg1));
    sp10 = -1;
    args.pa = &sp10;
    args.pb = &sp14;
    arg0->vt->fn1c((char *)arg0 + arg0->vt->d18, 7, 0, 2, &args, 0);
}
}
