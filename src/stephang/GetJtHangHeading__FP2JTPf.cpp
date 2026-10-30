typedef short s16;
struct Vec_190BE0 { float x, y; };
struct Obj_190BE0;
struct Vt_190BE0 { char p0[0xF8]; s16 delta; s16 pad; Vec_190BE0 *(*getVec)(void *); };
struct Obj_190BE0 { char p0[0xC]; Vt_190BE0 *vt; };
struct JT_190BE0 { char p0[0x18C4]; Obj_190BE0 *target; };
extern "C" float atan2f(float, float);
extern "C" void GetJtHangHeading__FP2JTPf(JT_190BE0 *jt, float *out) {
    Vec_190BE0 *first = jt->target->vt->getVec((char *)jt->target + jt->target->vt->delta);
    *out = atan2f(first->y, jt->target->vt->getVec((char *)jt->target + jt->target->vt->delta)->x);
}
