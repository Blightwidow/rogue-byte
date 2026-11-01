typedef int QW __attribute__((mode(TI)));
extern "C" {
struct Obj179328 { char pad0[0x1A8]; float yaw; };
struct Link179328 { int kind; char *next; char *target; };
struct Hit179328 {
    char pad0[0x10];
    char *owner;
    char pad14[0x1C];
    int notFlag30;
    char pad34[0xC];
    Link179328 *link;
    char pad44[0xC];
    int field50;
    char pad54[8];
    int flags;
    char pad60[0x50];
    float limitX;
    float limitY;
};
void func_00174950(Hit179328 *);
float *PmatLoWorld(char *);
QW PosLoWorld(char *);
float atan2f(float, float);
void func_00209818(char *, float);
float RadNormalize__Ff(float);
QW SetVectorCylind__FP6VECTORfff(float, float, float);
void SetJumperTarget(char *, int);
void func_0020AB68(char *, int, int, QW);
void func_001EEFC0(Hit179328 *);
void ReplaceSwHitFx(char *, int, QW, char *, char *);
int PpoSwFocusBase(char *);
int func_001A6AF8(int, int);
void TriggerJoyRumbleRumk__FP3JOY4RUMKf(char *, int, float);
extern char B_003DD490[];
extern char B_002DFC00[];
extern QW g_2a2dd0;
extern float g_2dded0;
extern int g_2f7900;
void GoalHit_Activate(Hit179328 *self) {
    func_00174950(self);
    asm volatile("lqc2 vf1, 0x80(%0)" : : "r"(self));
    int moving = 0;
    asm volatile("vmul.xyz vf1, vf1, vf1");
    asm volatile("vaddw.x vf2, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf2, vf1z");
    asm volatile("vsqrt Q, vf1x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, Q");
    float length;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(length));
    if (0.0001f < length)
        moving = self->flags != 0x40000;
    float heading;
    if (moving) {
        heading = atan2f(-((float *)self)[0x84 / 4], -((float *)self)[0x80 / 4]);
    } else {
        float *mat = PmatLoWorld(self->owner);
        heading = atan2f(mat[1], *PmatLoWorld(self->owner));
    }
    func_00209818(self->owner + 0xFD0, heading);
    if (self->link) {
        if (self->link->kind == 2) {
            QW cylinder = SetVectorCylind__FP6VECTORfff(
                RadNormalize__Ff(((Obj179328 *)self->owner)->yaw + 3.1415927f),
                *(float *)(self->link->next + 0x1C), 0.0f);
            QW position = PosLoWorld(self->owner);
            Link179328 *link = self->link;
            asm volatile("qmtc2.ni %0, vf1" : : "r"(position));
            asm volatile("lqc2 vf2, %0" : : "m"(cylinder));
            asm volatile("vadd.xyzw vf1, vf1, vf2");
            int target;
            asm("qmfc2.ni %0, vf1" : "=r"(target));
            SetJumperTarget(link->target, target);
        }
    }
    func_0020AB68(self->owner, 0, 0, g_2a2dd0);
    if (self->notFlag30 == 0)
        func_001EEFC0(self);
    ReplaceSwHitFx(B_003DD490, 1, PosLoWorld(self->owner), self->owner, self->owner + 0x35C);
    self->limitY = 3.4028235e38f;
    self->limitX = 3.4028235e38f;
    *(int *)(self->owner + 0xF04) = 0;
    if (*(int *)(self->owner + 0x334) != 0) {
        int focus = PpoSwFocusBase(B_003DD490);
        if (focus != 0) {
            if (func_001A6AF8(self->field50, focus) != 0) {
                if (focus == g_2f7900 || (self->flags & 0x40000) != 0) {
                    TriggerJoyRumbleRumk__FP3JOY4RUMKf(B_002DFC00, 3, 0.15f);
                    self->limitX = g_2dded0 + 0.050000004f;
                }
            }
        }
        self->limitY = g_2dded0 + 0.13333334f;
    }
}
}
