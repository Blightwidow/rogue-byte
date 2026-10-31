#include "sly2.h"
struct ROWS3 { QW r0; QW r1; QW r2; };
struct PLAYER { char pad0[0x2C0]; long flags; char pad1[0xF80 - 0x2C8]; int mode; int ref84; };
struct JUMPER { char pad[0x58]; void *target; int closed; int reverse; };
struct HOLDER { char pad[8]; JUMPER *jumper; };
struct TARGETOBJ { char pad[0x124]; int kind; };
struct GOAL {
    char pad0[0x10]; PLAYER *player; char pad1[0x40 - 0x14]; HOLDER *holder; char pad2[0x50 - 0x44]; QW pos; TARGETOBJ *target; int reverse;
    int mode68; int active; char pad3[0x70 - 0x70]; QW m0; QW m1; QW m2;
};
extern "C" {
void BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(void *, QW, QW);
int FFindSurfaceAlongUp(QW *, int, int, float, float);
int FIsBasicDerivedFrom(void *, int);
void FindCrvClosestPointAll(void *, QW, void *, QW *, void *, void *, void *);
void GetJtPipeGoalMat__FP2JTP4PIPEfP7MATRIX3(void *, int, void *, float);
unsigned long GrfsgsFromSgs(int);
void LoadRotateMatrixRad(void *, QW, float);
float *PmatLoWorld(void *);
QW PosLoWorld(void *);
float RadNormalize__Ff(float);
void SetJumperTarget(void *, QW);
float atan2f(float, float);
void func_00174950(GOAL *);
void func_0017A468(GOAL *, QW);
void func_001EEFC0(GOAL *);
void func_00209818(void *, float);
void func_00209840(void *, void *);
extern QW g_2a2dc0;
extern float g_2be6b8[2];
extern unsigned long g_2dfb70;
extern int g_2dfb78;
void GoalJump_Activate(GOAL *self) {
    char sp[0x80] __attribute__((aligned(16)));
    float sp40;
    QW world;
    if (g_2dfb78 == 0) {
        unsigned long a = GrfsgsFromSgs(0x1B);
        unsigned long b = GrfsgsFromSgs(0x27);
        unsigned long c = GrfsgsFromSgs(0x28);
        unsigned long d = GrfsgsFromSgs(0x29);
        g_2dfb78 = 1;
        g_2dfb70 = a | b | c | d;
    }
    PLAYER *player = self->player;
    long old = player->flags;
    long kept = old & g_2dfb70;
    player->flags = old & ~g_2dfb70;
    long taken = 0;
    TARGETOBJ *target = self->target;
    if (target != 0) {
        float y;
        float x;
        if (FIsBasicDerivedFrom(target, 0xA) != 0) {
            TARGETOBJ *curve = self->target;
            FindCrvClosestPointAll(curve, PosLoWorld(self->player), 0, &self->pos, sp, 0, 0);
            y = ((float *)sp)[1];
            x = ((float *)sp)[0];
        } else {
            self->pos = PosLoWorld(self->target);
            float *rows = PmatLoWorld(self->target);
            y = rows[1];
            x = *PmatLoWorld(self->target);
        }
        float angle = atan2f(y, x);
        if (FIsBasicDerivedFrom(self->target, 0xD) == 0) {
            if (FIsBasicDerivedFrom(self->target, 0x27) == 0) {
                if (FIsBasicDerivedFrom(self->target, 0xB) == 0) {
                    if (FIsBasicDerivedFrom(self->target, 0x13) != 0) {
                        if (self->target->kind == 3) {
                            unsigned long grf = GrfsgsFromSgs(0x28);
                            self->active = 1;
                            taken = 0 | grf;
                            BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(sp, *(QW *)PmatLoWorld(self->target), g_2a2dc0);
                            self->m0 = *(QW *)sp;
                            self->m1 = *(QW *)(sp + 0x10);
                            self->m2 = *(QW *)(sp + 0x20);
                            func_0017A468(self, *(QW *)sp);
                        } else {
                            goto noSurface;
                        }
                    } else {
noSurface:
                        FFindSurfaceAlongUp(&self->pos, 1, 0, g_2be6b8[1], g_2be6b8[0]);
                        self->target = 0;
                    }
                } else {
                    taken = 0 | GrfsgsFromSgs(0x27);
                    self->active = 1;
                    GetJtPipeGoalMat__FP2JTP4PIPEfP7MATRIX3(self->target, self->reverse, &self->m0, sp40);
                    func_0017A468(self, *(QW *)sp);
                }
            } else {
                taken = 0 | GrfsgsFromSgs(0x29);
            }
        } else {
            taken = 0 | GrfsgsFromSgs(0x1B);
            if (self->reverse == 0) angle = RadNormalize__Ff(angle + 3.1415927f);
            self->m2 = *(QW *)(sp + 0x30);
            LoadRotateMatrixRad(sp + 0x10, g_2a2dc0, angle);
            self->m0 = *(QW *)(sp + 0x10);
            self->m1 = *(QW *)(sp + 0x20);
            self->active = 1;
        }
    }
    player = self->player;
    player->flags = player->flags | taken;
    func_00174950(self);
    player = self->player;
    player->flags = player->flags & ~taken;
    player = self->player;
    player->flags = player->flags | kept;
    if (self->holder != 0) {
        player = self->player;
        int mode = player->mode;
        switch (mode) {
        case 3:
        default: {
            *(QW *)(sp + 0x50) = self->pos;
            world = PosLoWorld(player);
            int chain;
            asm volatile("qmtc2.ni %1, vf2" : "=r" (chain) : "r" (world));
            asm volatile("lqc2 vf1, 0x50(%1)" : "=r" (chain) : "r" (sp), "r" (chain));
            asm volatile("vsub.xyzw vf1, vf1, vf2" : "=r" (chain) : "r" (chain));
            char *base = (char *)self->player + 0xFD0;
            QW vec;
            asm volatile("qmfc2.ni %0, vf1" : "=r" (vec) : "r" (chain));
            QW rot;
            asm volatile("prot3w %0, %1" : "=r" (rot) : "r" (vec));
            float fx;
            float fy;
            asm volatile("mtc1 %1, %0" : "=f" (fx) : "r" (vec));
            asm volatile("mtc1 %1, %0" : "=f" (fy) : "r" (rot));
            func_00209818(base, atan2f(fy, fx));
            break;
        }
        case 2: {
            *(QW *)(sp + 0x60) = self->pos;
            int chain;
            asm volatile("lqc2 vf1, 0x60(%1)" : "=r" (chain) : "r" (sp));
            world = PosLoWorld(player);
            asm volatile("qmtc2.ni %1, vf2" : "=r" (chain) : "r" (world), "r" (chain));
            asm volatile("vsub.xyzw vf2, vf1, vf2" : "=r" (chain) : "r" (chain));
            asm volatile("sqc2 vf2, 0x70(%1)" : "=r" (chain) : "r" (sp), "r" (chain));
            BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(sp, *(QW *)PmatLoWorld((void *)self->player->ref84), *(QW *)(sp + 0x70));
            func_00209840((char *)self->player + 0xFD0, sp);
            break;
        }
        }
        self->holder->jumper->closed = self->mode68;
        self->holder->jumper->target = self->target;
        self->holder->jumper->reverse = self->reverse;
        SetJumperTarget(self->holder->jumper, self->pos);
    }
    func_001EEFC0(self);
}
}
