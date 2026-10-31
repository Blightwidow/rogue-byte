typedef int s32; typedef short s16;
extern "C" {
struct VT_206170 {
    char pad0[0x18];
    s16 d18;
    s16 p1a;
    void (*fn1c)(char *, s32, s32, s32, void *, s32);
    char pad1[0xD0 - 0x20];
    s16 dD0;
    s16 pD2;
    void (*fnD4)(char *, s32);
};
struct Obj_206170 { char pad[0xC]; VT_206170 *vt; };
struct Node_206170 { s32 first; s32 *last; };
void func_00206170(Obj_206170 *arg0) {
    Node_206170 node;
    arg0->vt->fnD4((char *)arg0 + arg0->vt->dD0, 0);
    node.last = &node.first;
    node.first = 0;
    arg0->vt->fn1c((char *)arg0 + arg0->vt->d18, 0xE, 1, 1, &node.last, 0);
}
}
