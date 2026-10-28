extern "C" {
void UpdateStep(void *, float);
void UpdateJtGadgets(void *);
int FButtonPressedWithin(void *, int, float);
void func_00140338(void *);
void func_00144640(void *);
int func_001449C8(void *);
void UpdateSeqnodeVjoy(void *, void *);
void UpdateJtFocus(void *);
void UpdateJtWater(void *);
void func_00140750(void *);
void UpdateJtLookRig(void *);
int FAsegaGone(int);
void ReleaseAsegaHandle(void *);
int FActiveCplcy(void *);
int GrfbtnVjoyPressedWithin(void *, int, float);
void ConsumeJoyButton(void *, int);
void GadgetMenu_Open(void *);
void GoalStack_Update(void *);
extern char B_002DE2E0;
struct GJoy { char pad[0x10B4]; unsigned grf; };
extern GJoy B_002DFC00;
extern char B_003DA0F0;
}
struct VT { short pad0[0x70 / 2]; short delta; short idx; void (*fn)(void *, void *); };
struct Obj { char pad[0xC]; VT *vt; };
void UpdateJt(char *jt, float dt)
{
    UpdateStep(jt, dt);
    UpdateJtGadgets(jt);
    if (FButtonPressedWithin(*(void **)(jt + 0x150), 0x200, 0.0f))
        func_00140338(jt);
    if (*(int *)(jt + 0xDF4) == -1) {
        char *sub = jt + 0xFD0;
        func_00144640(sub);
        if (!func_001449C8(sub)) {
            int count = *(int *)(jt + 0x270);
            if (count > 0) {
                int last = count - 1;
                Obj *top = *(Obj **)(jt + (last << 2) + 0x274);
                top->vt->fn((char *)top + top->vt->delta, *(void **)(jt + 0x150));
            } else {
                void *seq = *(void **)(jt + 0x1084);
                if (seq)
                    UpdateSeqnodeVjoy(seq, *(void **)(jt + 0x150));
            }
        }
    }
    UpdateJtFocus(jt);
    UpdateJtWater(jt);
    func_00140750(jt);
    UpdateJtLookRig(jt);
    int asega = *(int *)(jt + 0xEFC);
    if (asega && FAsegaGone(asega))
        ReleaseAsegaHandle(jt + 0xEFC);
    if (!FActiveCplcy(&B_002DE2E0)) {
        char *joy = *(char **)(jt + 0x150);
        if (*(int *)(joy + 0x80) == 1 && GrfbtnVjoyPressedWithin(joy, 0x100, 0.0f)
            && (B_002DFC00.grf & 0x108) == 0x100) {
            ConsumeJoyButton(&B_002DFC00, 0x100);
            GadgetMenu_Open(&B_003DA0F0);
        }
    }
    if (!func_001449C8(jt + 0xFD0))
        GoalStack_Update(jt + 0x26C);
}
