struct VT_1E5370 {
    int pad[4];
    short delta;
    short pad2;
    void (*fn)(void *);
};
struct Obj_1E5370 {
    int pad[3];
    VT_1E5370 *vt;
};
extern "C" void RetractAsega(void *);
extern "C" void JT_EndPose(int);
extern "C" void ReleaseSeqnodeAnim(char *self)
{
    Obj_1E5370 *anim = *(Obj_1E5370 **)(self + 0x4C);
    if (anim != 0) {
        RetractAsega(anim);
        Obj_1E5370 *held = *(Obj_1E5370 **)(self + 0x4C);
        held->vt->fn((char *)held + held->vt->delta);
        *(int *)(self + 0x4C) = 0;
    }
    int pose = *(int *)(self + 0x54);
    if (pose != 0) {
        JT_EndPose(pose);
        *(int *)(self + 0x54) = 0;
    }
}
