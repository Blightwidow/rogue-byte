typedef int QW __attribute__((mode(TI)));
struct CRef_225BA0 { int tagk; union { float g; int n; }; };
struct Rows3_225BA0 { QW row[3]; };
struct Stick_225BA0 { char pad0[0x10]; float x; char pad14[0]; };
struct Tank_225BA0 {
    char pad0[0x150]; char *input; char pad154[0x180 - 0x154]; char *target; int hasTarget; char pad188[4];
    float pan; float tilt; float panRate; float tiltRate; char tiltLimit[8]; char panLimit[8]; char pad1AC[0x1BC - 0x1AC];
    float skill; char pad1C0[0x1CC - 0x1C0]; int visible; char pad1D0[8]; void *act;
};
extern "C" {
extern char B_003D4A60[];
extern int B_003E0FE0;
extern char D_002C4408[];
extern float g_2dded0[];
void CRef_Destruct(CRef_225BA0 *);
void DecomposeRotateMatrixPanTilt__FP7MATRIX3PfT1(Rows3_225BA0 *, float *, float *);
float GLimitAbs__Fff(float, float);
float GLimitLm__FP2LMf(void *, float);
float GSmooth__FfffP3SMPPf(float, float, float, void *, float *);
void LoadLookAtMatrix(Rows3_225BA0 *, QW);
QW PosLoWorld(void *);
void RefGetGameSaveValue(CRef_225BA0 *, int, void *);
void func_0012D108(void *, QW);
void UpdateTankAim(Tank_225BA0 *self) {
    if (self->target != 0 && self->hasTarget != 0) {
        QW targetPosition;
        Rows3_225BA0 rotation;
        Rows3_225BA0 lookAt;
        float pan, tilt;
        targetPosition = PosLoWorld(self->target);
        asm("qmtc2.ni %0, vf2" : : "r"(PosLoWorld(self)));
        asm("lqc2 vf1, %0" : : "m"(targetPosition));
        asm("vsub.xyzw vf1, vf1, vf2");
        QW direction;
        asm("qmfc2.ni %0, vf1" : "=r"(direction));
        LoadLookAtMatrix(&lookAt, direction);
        rotation = lookAt;
        DecomposeRotateMatrixPanTilt__FP7MATRIX3PfT1(&rotation, &pan, &tilt);
        float panDelta = pan - self->pan;
        self->pan = pan;
        float tiltDelta = tilt - self->tilt;
        self->tilt = tilt;
        self->panRate = panDelta;
        self->tiltRate = tiltDelta;
    } else {
    if (self->input != 0) {
            float stickX = GLimitAbs__Fff(*(float *)(self->input + 0x10) + *(float *)(self->input + 0x20), 1.0f);
            float stickY = GLimitAbs__Fff(*(float *)(self->input + 0x14), 1.0f);
            float skill = self->skill;
            float scale = (((1.0f - skill) * 0.5f) + skill) * 10.0f;
            float panAccel = -stickX * stickX * stickX * scale;
            float limit = skill * 1.3f;
            CRef_225BA0 ref;
            if (panAccel * self->panRate <= 0.0f) {
                self->panRate = 0.0f;
            }
            float tiltAccel = stickY * stickY * stickY * scale;
            RefGetGameSaveValue(&ref, B_003E0FE0, B_003D4A60);
            int invert = ref.n;
            CRef_Destruct(&ref);
            if (invert == 0) {
                tiltAccel = -tiltAccel;
            }
            if (tiltAccel * self->tiltRate <= 0.0f) {
                self->tiltRate = 0.0f;
            }
            self->panRate = GSmooth__FfffP3SMPPf(self->panRate, 0.0f, g_2dded0[1], D_002C4408, 0);
            self->tiltRate = GSmooth__FfffP3SMPPf(self->tiltRate, 0.0f, g_2dded0[1], D_002C4408, 0);
            self->panRate = GLimitAbs__Fff(self->panRate + panAccel * g_2dded0[1], limit * 0.9f);
            float newTilt = GLimitAbs__Fff(self->tiltRate + tiltAccel * g_2dded0[1], limit * 0.8f);
            self->tiltRate = newTilt;
            self->pan = self->pan + self->panRate * g_2dded0[1];
            self->tilt = self->tilt + newTilt * g_2dded0[1];
        }
    }
    self->pan = GLimitLm__FP2LMf(self->panLimit, self->pan);
    float tilt = GLimitLm__FP2LMf(self->tiltLimit, self->tilt);
    self->tilt = tilt;
    if (self->visible != 0) {
        float negatedTilt = -tilt;
        int tiltBits, panBits;
        QW low, vector;
        asm("mfc1 %0, %1" : "=r"(tiltBits) : "f"(negatedTilt));
        asm("pextlw %0, %1, %2" : "=r"(low) : "r"(tiltBits), "r"(0));
        asm("mfc1 %0, %1" : "=r"(panBits) : "f"(self->pan));
        asm("pcpyld %0, %1, %2" : "=r"(vector) : "r"(panBits), "r"(low));
        func_0012D108(self->act, vector);
    }
}
}
