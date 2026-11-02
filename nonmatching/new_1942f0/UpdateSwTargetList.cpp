#include "sly2.h"
struct P20 { char pad0[0x14]; int f14; char pad18[8]; };
struct P12 { char pad[12]; };
struct OBJ : P20 {
    virtual int range(float *);
    virtual void o1();
    virtual void place(void *, QW *, int, float);
};
struct IND : P12 {
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual void i3();
    virtual void i4();
    virtual void i5();
    virtual void i6();
    virtual void i7();
    virtual void i8();
    virtual void i9();
    virtual void i10();
    virtual void i11();
    virtual void i12();
    virtual void i13();
    virtual void i14();
    virtual void i15();
    virtual void i16();
    virtual void i17();
    virtual void i18();
    virtual void i19();
    virtual void i20();
    virtual void i21();
    virtual void i22();
    virtual void i23();
    virtual void i24();
    virtual void i25();
    virtual void i26();
    virtual void i27();
    virtual void apply(QW);
};
struct TGT {
    int oid; OBJ *pobj; float f8; int fC; IND *pind; int f14; float pos; float vel; QW pad20;
} __attribute__((aligned(16)));
struct SW { char pad[0x4678]; int count; int pad467C; TGT tgts[4]; };
struct CAM { char pad[0x9C4]; int f9C4; };
extern "C" {
extern char B_002DEB30;
extern int B_002E1E50;
extern char D_002BF718;
extern float RO_002BF710;
extern float RO_002BF714;
extern float g_2dded0[];
int func_00194F48(const void *, const void *);
void FadeAloOut(IND *, float);
float GSmooth__FfffP3SMPPf(char *, float *, float, float, float);
IND *PloSpawnTargetIndicator(SW *, int, TGT *);
void bevy_camera_follow_activity(char *, int, int, int);
void *memmove(void *, const void *, unsigned);
void qsort(void *, int, int, int (*)(const void *, const void *));
}
extern "C" void UpdateSwTargetList(SW *self, CAM *cam, int count, TGT *src)
{
    float range[2];
    QW out;
    float width;
    int hold;
    if (count > 0) {
        qsort(src, count, 0x30, func_00194F48);
        if (src->pobj->f14 != -1)
            src->fC = 1;
    }
    int index = self->count - 1;
    TGT *list = self->tgts;
    if (index >= 0) {
        do {
            int search = count;
            TGT *cur = &self->tgts[index];
            for (;;) {
                search -= 1;
                if (search < 0) {
                    if (cur->pind != 0)
                        FadeAloOut(cur->pind, 0.5f);
                    memmove(cur, cur + 1, (3 - index) * 0x30);
                    self->count -= 1;
                    break;
                }
                TGT *found = &src[search];
                if (cur->oid != found->oid)
                    continue;
                cur->f8 = found->f8;
                if (cur->pind == 0) {
                    cur->vel = 0.0f;
                    cur->pos = found->pos;
                } else {
                    hold = found->pobj->range(range);
                    if (hold != 0) {
                        width = range[1] - range[0];
                        float base = cur->pos;
                        float diff = found->pos - base;
                        if (width * 0.5f < diff) {
                            diff -= width;
                            goto store;
                        }
                        if (diff < width * -0.5f) {
                            diff += width;
store:
                            found->pos = base + diff;
                        } else {
                            hold = 0;
                        }
                    }
                    if (B_002E1E50 != 0) {
                        float dt = g_2dded0[1];
                        float vel = cur->vel;
                        float pos = cur->pos;
                        float accel = vel + dt * ((found->pos - pos) * RO_002BF710 + (found->vel - vel) * RO_002BF714);
                        cur->vel = accel;
                        cur->pos = pos + dt * ((vel + accel) * 0.5f);
                    } else {
                        cur->pos = GSmooth__FfffP3SMPPf(&D_002BF718, &cur->vel, cur->pos, found->pos, g_2dded0[1]);
                    }
                    if (hold != 0) {
                        float pos = cur->pos;
                        if (range[1] < pos) {
                            pos -= width;
                            goto update;
                        }
                        if (pos < range[0]) {
                            pos += width;
update:
                            cur->pos = pos;
                        }
                    }
                    cur->pobj->place(cam, &out, 0, cur->pos);
                    cur->pind->apply(out);
                }
                memmove(found, found + 1, (count - search) * 0x30 - 0x30);
                count -= 1;
                break;
            }
            index -= 1;
        } while (index >= 0);
    }
    TGT *psrc = src;
    int taken = 0;
    while (taken < count) {
        int target = cam->f9C4;
        if (target != 0 && psrc->fC == 1) {
            IND *pind = PloSpawnTargetIndicator(self, target, psrc);
            if (pind == 0)
                break;
            psrc->pind = pind;
        }
        int slot = self->count;
        taken += 1;
        self->tgts[slot] = *psrc;
        self->count = slot + 1;
        int oid = psrc->oid;
        psrc += 1;
        bevy_camera_follow_activity(&B_002DEB30, 0x3D, oid, slot + 1);
    }
    qsort(list, self->count, 0x30, func_00194F48);
}
