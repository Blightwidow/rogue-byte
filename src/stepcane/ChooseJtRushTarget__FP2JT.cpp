struct JOY { char pad0[0x18]; float rad; float mag; };
struct TARGET;
struct JT { char pad0[0x150]; JOY *pjoy; char pad154[0x1A8 - 0x154]; float heading; char pad1AC[0x18C0 - 0x1AC]; TARGET *target; };
struct VECTOR { float x, y, z, w; } __attribute__((aligned(16)));
extern char D_002BF4D0[];
extern "C" float atan2f(float, float);
extern "C" void SetStepRadTarget(JT *, float);
extern "C" void FixStepAngularVelocity__FP4STEP(JT *);
extern "C" void CJ(JT *, float, float, float, int, VECTOR *, TARGET **, VECTOR *) asm("ChooseJtAttackTarget__FP2JTiP6VECTORffPP6TARGETT2");

void ChooseJtRushTarget__FP2JT(JT *jt)
{
    JOY *joy = jt->pjoy;
    float heading;
    if (joy != 0) {
        float mag = joy->mag;
        float half;
        asm volatile(".set noat\n\tlui $1, 0x3F00\n\tmtc1 $1, %0\n\tnop\n\t.set at" : "=f" (half) : "f" (mag));
        if (half < mag)
            heading = joy->rad;
        else
            heading = jt->heading;
    } else
        heading = jt->heading;
    TARGET *target;
    VECTOR dir;
    CJ(jt, heading, 0.25f, 1.0f, 8, (VECTOR *)D_002BF4D0, &target, &dir);
    jt->target = target;
    if (target != 0)
        heading = atan2f(dir.y, dir.x);
    SetStepRadTarget(jt, heading);
    FixStepAngularVelocity__FP4STEP(jt);
}
