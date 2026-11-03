typedef int QW __attribute__((mode(TI)));
struct Continuation { long value; } __attribute__((packed));
struct VT_1A19A0 {
    char pad0[0x108];
    short d108; short i108; QW (*GetVelocity)(void *);
    char pad110[0x118 - 0x110];
    short d118; short i118; void (*SetVelocity)(void *, QW);
    short d120; short i120; void (*SetVelocityGoal)(void *, QW);
    char pad128[0x258 - 0x128];
    short d258; short i258; int (*TakeDamage)(void *, void *);
    short d260; short i260; int (*FIgnoreDamage)(void *, int);
    char pad268[0x2C0 - 0x268];
    short d2C0; short i2C0; void (*SetJtState)(void *, int);
};
struct CARRY_1A19A0 { char pad0[8]; int fActive; };
struct ITEM_1A19A0 { char pad0[0x158]; CARRY_1A19A0 *pcarry; };
struct JT_1A19A0 {
    char pad0[0xC];
    VT_1A19A0 *vt;
    char pad10[0x29C - 0x10];
    int fInvulnerable;
    char pad2A0[0x4C8 - 0x2A0];
    int mode;
    char pad4CC[0x4D4 - 0x4CC];
    JT_1A19A0 *pjtOther;
    char pad4D8[0x11A8 - 0x4D8];
    ITEM_1A19A0 *pitemCarried;
};
struct SRC_1A19A0 { char pad0[0xFBC]; int kind; };
struct VEC3_1A19A0 {
    float x, y, z;
    void Clear() { x = y = z = 0; }
};
struct ZPD_1A19A0 {
    SRC_1A19A0 *source;
    int pad4;
    int pad8;
    int type;
    int amount;
    char pad14[0x30 - 0x14];
    VEC3_1A19A0 vec;
    char pad3C[0x60 - 0x3C];
} __attribute__((aligned(16)));
struct ZAP_1A19A0 {
    JT_1A19A0 *pjt;
    int state;
    char pad8[0x10 - 0x8];
    int *phealth;
    char pad14[0x30 - 0x14];
    ZPD_1A19A0 zpd;
    char pad90_[0x90 - 0x90];
    int fRecover;
    float tRecover;
    float tRecover2;
    char pad9C[0x108 - 0x9C];
    int hasega;
    char asega[4];
};
struct SW_1A19A0 { char pad0[0x4038]; int phitfx; };
extern "C" {
int func_001A2358(void);
int SFromCrvlU__FP4CRVLf(void *, int);
void ApplyAsegToHandle(int, JT_1A19A0 *, int, void *, float, float);
int FIsBasicDerivedFrom(SRC_1A19A0 *, int);
void DropJtLoot(JT_1A19A0 *);
void bevy_camera_follow_activity(void *, int, SRC_1A19A0 *);
void SetZapContinuation(ZAP_1A19A0 *, long);
void SetJtZapState(ZAP_1A19A0 *, int);
void ZapKnockback(ZAP_1A19A0 *);
int CidGetBasic(JT_1A19A0 *);
int NewEmitter(int);
void SetEmitterUnpositioned(int, JT_1A19A0 *);
QW PosLoWorld(JT_1A19A0 *);
void PhitfxSpawn(int, QW, JT_1A19A0 *);
extern char B_002DE578[];
extern char B_002DEB30[];
extern SW_1A19A0 B_003DD490;
extern QW D_002BFB10;
extern QW g_2a2dd0;
struct CLOCK_1A19A0 { float t; };
extern CLOCK_1A19A0 g_2dded0;
extern const Continuation RO_002A6768;
extern const Continuation RO_002A6770;
extern const Continuation RO_002A6778;
extern const Continuation RO_002A6780;
extern const Continuation RO_002A6788;
}

static inline void ClearVector(float *vec)
{
    vec[0] = 0;
    vec[1] = 0;
    vec[2] = 0;
}

// Lane 2 of a vector held in a general register.
static inline float Lane2(QW vec)
{
    float lane;
    asm("pextuw %0, $0, %1" : "=r"(lane) : "r"(vec));
    return lane;
}

extern "C" int ZapTakeDamage(ZAP_1A19A0 *zap, ZPD_1A19A0 *pzpd)
{
    ZPD_1A19A0 zpd;
    int amount;
    if (func_001A2358()) {
        if ((unsigned)(zap->state - 8) < 5)
            return 0;
        amount = -0x8000;
    } else {
        JT_1A19A0 *jt = zap->pjt;
        if (jt->vt->FIgnoreDamage((char *)jt + jt->vt->d260, pzpd->type))
            return 0;
        if (zap->pjt->mode == 1) {
            JT_1A19A0 *other = zap->pjt->pjtOther;
            return other->vt->TakeDamage((char *)other + other->vt->d258, pzpd);
        }
        if (zap->pjt->fInvulnerable)
            amount = 0;
        else if (zap->fRecover == 1)
            amount = 0;
        else
            amount = SFromCrvlU__FP4CRVLf(B_002DE578, pzpd->amount);
        if (pzpd->type == 0x100000) {
            if (*zap->phealth + amount > 0) {
                if (zap->fRecover != 1) {
                    zap->fRecover = 0;
                    zap->tRecover = zap->tRecover2 = g_2dded0.t;
                }
                *zap->phealth += amount;
                if (zap->hasega)
                    ApplyAsegToHandle(zap->hasega, zap->pjt, 1, zap->asega, 0.0f, 1.0f);
                goto spawn;
            }
            zpd = *pzpd;
            pzpd = &zpd;
            pzpd->vec.Clear();
            pzpd->type = 0x200;
        }
        if (pzpd->source && FIsBasicDerivedFrom(pzpd->source, 0x38)) {
            int kind = pzpd->source->kind;
            if (kind == 8 || kind == 0xD)
                amount /= 2;
        }
    }
    {
        JT_1A19A0 *jt = zap->pjt;
        jt->vt->SetJtState((char *)jt + jt->vt->d2C0, 3);
    }
    {
        JT_1A19A0 *jt = zap->pjt;
        ITEM_1A19A0 *carried = jt->pitemCarried;
        if (carried && (carried->pcarry->fActive || *zap->phealth + amount <= 0))
            DropJtLoot(jt);
    }
    bevy_camera_follow_activity(B_002DEB30, 0xF, pzpd->source);
    zap->zpd = *pzpd;
    zap->zpd.amount = amount;
    SetZapContinuation(zap, RO_002A6768.value);
    {
        int health = *zap->phealth + zap->zpd.amount;
        *zap->phealth = health < 0 ? 0 : health;
    }
    if (*zap->phealth > 0) {
        zap->fRecover = 1;
        zap->tRecover = g_2dded0.t;
    }
    switch (pzpd->type) {
    case 0x100:
    case 0x200: {
        ZapKnockback(zap);
        JT_1A19A0 *jt = zap->pjt;
        if (Lane2(jt->vt->GetVelocity((char *)jt + jt->vt->d108)) > 400.0f) {
            int effect = -1;
            switch (CidGetBasic(zap->pjt)) {
            case 0x35:
                effect = 0x69;
                break;
            case 0x37:
                effect = 0x83;
                break;
            case 0x36:
                effect = 0x84;
                break;
            }
            JT_1A19A0 *target = zap->pjt;
            SetEmitterUnpositioned(NewEmitter(effect), target);
        }
        SetZapContinuation(zap, RO_002A6770.value);
        break;
    }
    case 0x8000:
        SetJtZapState(zap, 7);
        SetZapContinuation(zap, RO_002A6778.value);
        break;
    case 0x800:
    case 0x1000: {
        JT_1A19A0 *jt = zap->pjt;
        jt->vt->SetVelocity((char *)jt + jt->vt->d118, g_2a2dd0);
        jt = zap->pjt;
        jt->vt->SetVelocityGoal((char *)jt + jt->vt->d120, g_2a2dd0);
        SetJtZapState(zap, pzpd->type == 0x800 ? 1 : 2);
        SetZapContinuation(zap, RO_002A6780.value);
        break;
    }
    case 0x2000:
        if (*zap->phealth > 0) {
            SetJtZapState(zap, 3);
            SetZapContinuation(zap, RO_002A6788.value);
        } else {
            SetJtZapState(zap, 0xA);
        }
        break;
    case 0x400: {
        JT_1A19A0 *jt = zap->pjt;
        jt->vt->SetVelocity((char *)jt + jt->vt->d118, D_002BFB10);
        if (*zap->phealth > 0)
            SetJtZapState(zap, 4);
        else
            SetJtZapState(zap, 0xC);
        break;
    }
    case 0x4000:
        if (*zap->phealth > 0) {
            SetJtZapState(zap, 5);
            SetZapContinuation(zap, RO_002A6788.value);
        } else {
            SetJtZapState(zap, 0xB);
        }
        break;
    case 0x40:
        ZapKnockback(zap);
        SetZapContinuation(zap, RO_002A6770.value);
        break;
    }
spawn:
    PhitfxSpawn(B_003DD490.phitfx, PosLoWorld(zap->pjt), zap->pjt);
    return 1;
}
