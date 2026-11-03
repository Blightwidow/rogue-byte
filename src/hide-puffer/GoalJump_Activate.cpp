typedef int QW __attribute__((mode(TI)));
struct VECTOR { float x, y, z, w; } __attribute__((aligned(16)));
struct MATRIX3 { QW row0; QW row1; QW row2; };
struct PLAYER { char pad0[0x2C0]; long grfsgs; char pad1[0xF80 - 0x2C8]; int mode; void *palo; char pad2[0xFD0 - 0xF88]; char cam[0x10]; };
struct JUMPER { char pad[0x58]; void *ptarget; int fReverse; int fClosed; };
struct HOLDER { char pad[8]; JUMPER *pjumper; };
struct TARGET { char pad[0x124]; int kind; };
struct GOAL {
    char pad0[0x10]; PLAYER *pplayer; char pad1[0x40 - 0x14]; HOLDER *pholder; char pad2[0x50 - 0x44];
    QW pos; TARGET *ptarget; int fReverse; int fClosed; int fActive; MATRIX3 mat;
};
extern "C" {
void BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(MATRIX3 *, QW, QW);
int FFindSurfaceAlongUp(QW *, int, int, float, float);
int FIsBasicDerivedFrom(void *, int);
void FindCrvClosestPointAll(void *, QW, void *, QW *, VECTOR *, void *, float *);
void GetJtPipeGoalMat__FP2JTP4PIPEfP7MATRIX3(void *, int, MATRIX3 *, float);
unsigned long GrfsgsFromSgs(int);
void LoadRotateMatrixRad(MATRIX3 *, QW, float);
QW *PmatLoWorld(void *);
QW PosLoWorld(void *);
float RadNormalize__Ff(float);
void SetJumperTarget(JUMPER *, QW);
float atan2f(float, float);
void func_00174950(GOAL *);
void func_0017A468(GOAL *);
void func_001EEFC0(GOAL *);
void func_00209818(void *, float);
void func_00209840(void *, MATRIX3 *);
extern QW g_2a2dc0;
extern float g_2be6b8[2];
extern unsigned long g_2dfb70;
extern int g_2dfb78;
}
extern "C" void GoalJump_Activate(GOAL *self)
{
    if (g_2dfb78 == 0) {
        unsigned long grf1B = GrfsgsFromSgs(0x1B);
        unsigned long grf27 = GrfsgsFromSgs(0x27);
        unsigned long grf28 = GrfsgsFromSgs(0x28);
        unsigned long grf29 = GrfsgsFromSgs(0x29);
        g_2dfb78 = 1;
        g_2dfb70 = grf1B | grf27 | grf28 | grf29;
    }
    long grfsgsKept = self->pplayer->grfsgs & g_2dfb70;
    self->pplayer->grfsgs &= ~g_2dfb70;
    long grfsgsTaken = 0;
    if (self->ptarget != 0) {
        float u;
        float angle;
        if (FIsBasicDerivedFrom(self->ptarget, 0xA) != 0) {
            VECTOR dir;
            void *pcrv = self->ptarget;
            FindCrvClosestPointAll(pcrv, PosLoWorld(self->pplayer), 0, &self->pos, &dir, 0, &u);
            angle = atan2f(dir.y, dir.x);
        } else {
            self->pos = PosLoWorld(self->ptarget);
            angle = atan2f(((float *)PmatLoWorld(self->ptarget))[1], ((float *)PmatLoWorld(self->ptarget))[0]);
        }
        if (FIsBasicDerivedFrom(self->ptarget, 0xD) != 0) {
            grfsgsTaken |= GrfsgsFromSgs(0x1B);
            if (self->fReverse == 0)
                angle = RadNormalize__Ff(angle + 3.1415927f);
            self->fActive = 1;
            MATRIX3 mat;
            LoadRotateMatrixRad(&mat, g_2a2dc0, angle);
            self->mat = mat;
        } else if (FIsBasicDerivedFrom(self->ptarget, 0x27) != 0) {
            grfsgsTaken |= GrfsgsFromSgs(0x29);
        } else if (FIsBasicDerivedFrom(self->ptarget, 0xB) != 0) {
            grfsgsTaken |= GrfsgsFromSgs(0x27);
            self->fActive = 1;
            GetJtPipeGoalMat__FP2JTP4PIPEfP7MATRIX3(self->ptarget, self->fReverse, &self->mat, u);
            func_0017A468(self);
        } else if (FIsBasicDerivedFrom(self->ptarget, 0x13) != 0 && self->ptarget->kind == 3) {
            grfsgsTaken |= GrfsgsFromSgs(0x28);
            self->fActive = 1;
            MATRIX3 mat;
            BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(&mat, *PmatLoWorld(self->ptarget), g_2a2dc0);
            self->mat = mat;
            func_0017A468(self);
        } else {
            FFindSurfaceAlongUp(&self->pos, 1, 0, g_2be6b8[1], g_2be6b8[0]);
            self->ptarget = 0;
        }
    }
    self->pplayer->grfsgs |= grfsgsTaken;
    func_00174950(self);
    self->pplayer->grfsgs &= ~grfsgsTaken;
    self->pplayer->grfsgs |= grfsgsKept;
    if (self->pholder != 0) {
        switch (self->pplayer->mode) {
        case -1:
        case 0:
        case 3: {
            QW pos = self->pos;
            QW posPlayer = PosLoWorld(self->pplayer);
            QW delta;
            QW rot;
            int fence;
            // fence tokens: each block reads the VU registers the previous one wrote
            asm("qmtc2.ni %1, vf2" : "=r"(fence) : "r"(posPlayer));
            asm("lqc2 vf1, %1" : "=r"(fence) : "m"(pos), "r"(fence));
            asm("vsub.xyzw vf1, vf1, vf2" : "=r"(fence) : "r"(fence));
            asm("qmfc2.ni %0, vf1" : "=r"(delta) : "r"(fence));
            asm("prot3w %0, %1" : "=r"(rot) : "r"(delta));
            float x, y;
            asm("mtc1 %1, %0" : "=f"(x) : "r"(delta));
            asm("mtc1 %1, %0" : "=f"(y) : "r"(rot));
            func_00209818(self->pplayer->cam, atan2f(y, x));
            break;
        }
        case 2: {
            QW dir;
            QW pos = self->pos;
            QW posPlayer = PosLoWorld(self->pplayer);
            // fence tokens: the subtraction reads vf1 and vf2 that the two loads write
            int fence;
            asm("lqc2 vf1, %1\n\tqmtc2.ni %2, vf2" : "=r"(fence) : "m"(pos), "r"(posPlayer));
            asm("vsub.xyzw vf2, vf1, vf2" : "=r"(fence) : "r"(fence));
            asm("sqc2 vf2, %0" : "=m"(dir) : "r"(fence));
            MATRIX3 mat;
            BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(&mat, *PmatLoWorld(self->pplayer->palo), dir);
            func_00209840(self->pplayer->cam, &mat);
            break;
        }
        }
        self->pholder->pjumper->fClosed = self->fClosed;
        self->pholder->pjumper->ptarget = self->ptarget;
        self->pholder->pjumper->fReverse = self->fReverse;
        SetJumperTarget(self->pholder->pjumper, self->pos);
    }
    func_001EEFC0(self);
}
