typedef int QW __attribute__((mode(TI)));
extern "C" {
extern QW g_2a2dd0;
struct Vt_19AAB8 { char pad0[0x18]; short delta; short pad1; void (*fn)(void *, int, QW *, int); };
struct Alo_19AAB8 { char pad0[0xE0]; };
struct Alo2_19AAB8 { char pad0[0x100]; Vt_19AAB8 *vt; };
struct Jt_19AAB8 { int first; };
struct Goal_19AAB8 { Jt_19AAB8 *jt; Alo2_19AAB8 *alo; int pad[2]; QW target; };
void MeasureJtJumpToTarget__FP2JTP6VECTORP3ALOT1T1PfT5T1T1(Jt_19AAB8 *, QW, Alo2_19AAB8 *, QW, QW, float *, float *, int, int);
float GMeasureJumpHpnt(Goal_19AAB8 *goal) {
    QW point;
    float distance;
    char *base = (char *)goal->alo + 0xE0;
    Vt_19AAB8 *vt = goal->alo->vt;
    vt->fn(base + vt->delta, goal->jt->first, &point, 0);
    MeasureJtJumpToTarget__FP2JTP6VECTORP3ALOT1T1PfT5T1T1(goal->jt, goal->target, goal->alo, point, g_2a2dd0, 0, &distance, 0, 0);
    return distance;
}
}
