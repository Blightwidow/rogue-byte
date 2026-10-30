#include "sly2.h"
struct UL { long v; } __attribute__((packed));
struct VT {
    char pad0[0x108];
    short d108; short p108; QW (*f10C)(void *);
    char pad110[0x118 - 0x110];
    short d118; short p118; void (*f11C)(void *, QW);
    short d120; short p120; void (*f124)(void *, QW);
    char pad128[0x258 - 0x128];
    short d258; short p258; int (*f25C)(void *, char *);
    short d260; short p260; int (*f264)(void *, int);
    char pad268[0x2C0 - 0x268];
    short d2C0; short p2C0; void (*f2C4)(void *, int);
};
struct OBJ { char pad[0xC]; VT *vt; };
struct DMG { char *source; char pad4[0xC - 4]; int type; int amount; char pad14[0x60 - 0x14]; } __attribute__((aligned(16)));
extern "C" {
void ApplyAsegToHandle(int, char *, int, char *, float, float);
int CidGetBasic(char *);
void DropJtLoot(char *);
int FIsBasicDerivedFrom(char *, int);
int NewEmitter(int);
int PhitfxSpawn(int, QW, char *);
QW PosLoWorld(char *);
int SFromCrvlU__FP4CRVLf(void *, int);
void SetEmitterUnpositioned(int, char *);
void SetJtZapState(char *, int);
int SetZapContinuation(char *, long);
void ZapKnockback(char *);
void bevy_camera_follow_activity(void *, int, char *);
int func_001A2358();
extern char B_002DE578[];
extern char B_002DEB30[];
extern char B_003DD490[];
extern QW D_002BFB10;
extern const UL RO_002A6768;
extern const UL RO_002A6770;
extern const UL RO_002A6778;
extern const UL RO_002A6780;
extern const UL RO_002A6788;
extern QW g_2a2dd0;
extern float g_2dded0;
int ZapTakeDamage(char *zap, DMG *damage) {
    DMG local;
    int amount;
    OBJ *jt;
    if (func_001A2358() != 0) {
        if ((unsigned)(*(int *)(zap + 4) - 8) < 5U) {
            return 0;
        }
        amount = -0x8000;
    } else {
        jt = *(OBJ **)zap;
        if (jt->vt->f264((char *)jt + jt->vt->d260, damage->type) != 0) {
            return 0;
        }
        jt = *(OBJ **)zap;
        if (*(int *)((char *)jt + 0x4C8) == 1) {
            OBJ *other = *(OBJ **)((char *)jt + 0x4D4);
            return other->vt->f25C((char *)other + other->vt->d258, (char *)damage);
        }
        amount = 0;
        if (*(int *)((char *)jt + 0x29C) == 0) {
            if (*(int *)(zap + 0x90) != 1) {
                amount = SFromCrvlU__FP4CRVLf(B_002DE578, damage->amount);
            }
        }
        if (damage->type == 0x100000) {
            if (**(int **)(zap + 0x10) + amount > 0) {
                if (*(int *)(zap + 0x90) != 1) {
                    *(int *)(zap + 0x90) = 0;
                    *(float *)(zap + 0x94) = g_2dded0;
                    *(float *)(zap + 0x98) = g_2dded0;
                }
                **(int **)(zap + 0x10) += amount;
                int handle = *(int *)(zap + 0x108);
                if (handle != 0) {
                    ApplyAsegToHandle(handle, *(char **)zap, 1, zap + 0x10C, 0.0f, 1.0f);
                }
                goto spawn;
            }
            local = *damage;
            damage = &local;
            local.type = 0x200;
            ((float *)((char *)&local + 0x30))[0] = 0;
            ((float *)((char *)&local + 0x30))[1] = 0;
            ((float *)((char *)&local + 0x30))[2] = 0;
        }
        if (damage->source != 0) {
            if (FIsBasicDerivedFrom(damage->source, 0x38) != 0) {
                int kind = *(int *)(damage->source + 0xFBC);
                if (kind == 8 || kind == 0xD) {
                    amount = amount / 2;
                }
            }
        }
    }
    jt = *(OBJ **)zap;
    jt->vt->f2C4((char *)jt + jt->vt->d2C0, 3);
    {
        char *player = *(char **)zap;
        char *carried = *(char **)(player + 0x11A8);
        if (carried != 0) {
            if (*(int *)(*(char **)(carried + 0x158) + 8) != 0 || **(int **)(zap + 0x10) + amount <= 0) {
                DropJtLoot(player);
            }
        }
    }
    bevy_camera_follow_activity(B_002DEB30, 0xF, damage->source);
    *(DMG *)(zap + 0x30) = *damage;
    *(int *)(zap + 0x40) = amount;
    SetZapContinuation(zap, RO_002A6768.v);
    {
        int *health = *(int **)(zap + 0x10);
        int total = *health + *(int *)(zap + 0x40);
        *health = total <= -1 ? 0 : total;
    }
    if (**(int **)(zap + 0x10) > 0) {
        *(int *)(zap + 0x90) = 1;
        *(float *)(zap + 0x94) = g_2dded0;
    }
    switch (damage->type) {
    case 0x400:
        jt = *(OBJ **)zap;
        jt->vt->f11C((char *)jt + jt->vt->d118, D_002BFB10);
        if (**(int **)(zap + 0x10) > 0) {
            SetJtZapState(zap, 4);
        } else {
            SetJtZapState(zap, 0xC);
        }
        break;
    case 0x100:
    case 0x200: {
        ZapKnockback(zap);
        jt = *(OBJ **)zap;
        QW velocity = jt->vt->f10C((char *)jt + jt->vt->d108);
        int bits;
        asm("pextuw %0, $0, %1" : "=r"(bits) : "r"(velocity));
        if (*(float *)&bits > 400.0f) {
            int effect = -1;
            switch (CidGetBasic(*(char **)zap)) {
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
            char *target = *(char **)zap;
            SetEmitterUnpositioned(NewEmitter(effect), target);
        }
        SetZapContinuation(zap, RO_002A6770.v);
        break;
    }
    case 0x8000:
        SetJtZapState(zap, 7);
        SetZapContinuation(zap, RO_002A6778.v);
        break;
    case 0x800:
    case 0x1000:
        jt = *(OBJ **)zap;
        jt->vt->f11C((char *)jt + jt->vt->d118, g_2a2dd0);
        jt = *(OBJ **)zap;
        jt->vt->f124((char *)jt + jt->vt->d120, g_2a2dd0);
        SetJtZapState(zap, (damage->type ^ 0x800) != 0 ? 2 : 1);
        SetZapContinuation(zap, RO_002A6780.v);
        break;
    case 0x2000:
        if (**(int **)(zap + 0x10) > 0) {
            SetJtZapState(zap, 3);
            SetZapContinuation(zap, RO_002A6788.v);
        } else {
            SetJtZapState(zap, 0xA);
        }
        break;
    case 0x4000:
        if (**(int **)(zap + 0x10) > 0) {
            SetJtZapState(zap, 5);
            SetZapContinuation(zap, RO_002A6788.v);
        } else {
            SetJtZapState(zap, 0xB);
        }
        break;
    case 0x40:
        ZapKnockback(zap);
        SetZapContinuation(zap, RO_002A6770.v);
        break;
    }
spawn:
    PhitfxSpawn(*(int *)(B_003DD490 + 0x4038), PosLoWorld(*(char **)zap), *(char **)zap);
    return 1;
}
}
