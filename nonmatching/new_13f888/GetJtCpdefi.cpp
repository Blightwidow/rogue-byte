#include "sly2.h"
struct VtJt_141640 { char pad0[0x110]; short d110; short i110; QW (*f114)(void *); char pad1[0x308 - 0x118]; short d308; short i308; void (*f30C)(void *, float *); };
struct Jt_141640 {
    char pad0[0xC]; VtJt_141640 *vt; char pad1[0x2C0 - 0x10]; char a2C0[0x1C]; int f2DC; char pad2[0x434 - 0x2E0]; int f434; char pad3[0x4C0 - 0x438];
    char a4C0[0xC]; int f4CC; char pad4[0xDF0 - 0x4CC - 4]; char aDF0[4]; int fDF4; char pad5[0x1044 - 0xDF8]; int f1044; char pad6[0x104C - 0x1048];
    float f104C; float f1050; char pad7[0x1060 - 0x1054]; QW f1060; QW f1070;
};
struct Out_141640 { char pad0[0x10]; float x; float y; float z; char pad1[0x34 - 0x1C]; float f34; };
struct Out2_141640 { char pad0[0x10]; QW pos; float f18; };
struct Cam_141640 { char pad0[0x260]; Jt_141640 *f260; char pad1[0x300 - 0x264]; int f300; };
struct Time_141640 { float a; float dt; };
struct Lim_141640 { float lo; float hi; };
struct Poly_141640 { float c0; float c1; float c2; };
extern "C" {
void GetSoCpdefi__FP2SOfP6CPDEFI(void *, void *);
QW PosLoWorld(void *);
float GSmooth__FfffP3SMPPf(void *, int, float, float, float);
QW PosSmooth(QW, QW, void *, int, float);
void GetAttachCpdefi(void *, void *);
int func_0019C8B0(void *, void *);
int bevy_player_p7_damage_1a2160(void *, void *);
extern Cam_141640 B_002DDF40;
extern char D_002BCCB8[];
extern char D_002BCCC8[];
extern char D_002BCCD8[];
extern float RO_002BCC98;
extern float RO_002BCC9C;
extern float RO_002BCCA0;
extern float RO_002BCCA4;
extern float RO_002BCCA8;
extern float RO_002BCCAC;
extern float RO_002BCCB0;
extern float RO_002BCCB4;
extern Poly_141640 D_002BCCF0;
extern QW g_2a2dd0;
extern Lim_141640 g_2bbb60;
extern Time_141640 g_2dded0;
void GetJtCpdefi(Jt_141640 *jt, Out_141640 *out) {
    float sp[4];
    GetSoCpdefi__FP2SOfP6CPDEFI(jt, out);
    if (jt->f1044 != 0) {
        ((Out2_141640 *)out)->pos = jt->f1060;
        jt->f104C = *(float *)((char *)jt + 0x1068);
    } else {
        QW pos = PosLoWorld(jt);
        int zBits;
        asm("pextuw %0, $0, %1" : "=r"(zBits) : "r"(pos));
        float z = *(float *)&zBits;
        jt->vt->f30C((char *)jt + jt->vt->d308, sp);
        float lo, hi;
        if (jt->f434 != 0) {
            lo = RO_002BCCA0;
            hi = RO_002BCCA4;
        } else if (jt->f2DC == 0x16) {
            lo = RO_002BCCB0;
            hi = RO_002BCCB4;
        } else {
            lo = RO_002BCCA8;
            hi = RO_002BCCAC;
        }
        float low = z + lo;
        float value = sp[2];
        if (value < low) {
            value = low;
        } else if (z + hi < value) {
            value = z + hi;
        }
        jt->f104C = value;
        if (B_002DDF40.f300 != 0) {
            out->z = value;
        } else if (B_002DDF40.f260 == jt) {
            void *table = jt->f434 != 0 ? (void *)D_002BCCC8 : (void *)D_002BCCB8;
            float smoothed = GSmooth__FfffP3SMPPf(table, 0, jt->f1050, jt->f104C, g_2dded0.dt);
            out->z = smoothed;
            if (smoothed < z + RO_002BCC98) {
                smoothed = z + RO_002BCC98;
            } else if (z + RO_002BCC9C < smoothed) {
                smoothed = z + RO_002BCC9C;
            }
            out->z = smoothed;
        } else {
            out->z = value;
        }
        out->x = sp[0];
        out->y = sp[1];
    }
    {
        int token0, token1, token2;
        QW smoothed = PosSmooth(jt->f1070, g_2a2dd0, D_002BCCD8, 0, g_2dded0.dt);
        asm("qmtc2.ni %1, vf2\n\tsqc2 vf2, 0x1070(%2)" : "=r"(token0) : "r"(smoothed), "r"(jt));
        asm("lqc2 vf1, 0x10(%1)\n\tvadd.xyzw vf1, vf1, vf2\n\tsqc2 vf1, 0x10(%1)\n\tsqc2 vf1, 0x1060(%2)" : "=r"(token1) : "r"(out), "r"(jt), "r"(token0) : "memory");
    }
    jt->f1050 = ((Out2_141640 *)out)->f18;
    if (jt->f2DC != -1) func_0019C8B0(jt->a2C0, out);
    if (jt->f4CC != -1) GetAttachCpdefi(jt->a4C0, out);
    if (jt->fDF4 != -1) bevy_player_p7_damage_1a2160(jt->aDF0, out);
    {
        QW vec = jt->vt->f114((char *)jt + jt->vt->d110);
        int token0, token1, token2, bits;
        asm("qmtc2.ni %1, vf3" : "=r"(token0) : "r"(vec));
        asm("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : "=r"(token1) : "r"(token0));
        asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "=r"(token2) : "r"(token1));
        asm("qmfc2.ni %0, vf1" : "=r"(bits) : "r"(token2));
        float length = *(float *)&bits;
        float t = D_002BCCF0.c0 + length * (D_002BCCF0.c1 + length * D_002BCCF0.c2);
        if (t < g_2bbb60.lo) {
            t = g_2bbb60.lo;
        } else if (g_2bbb60.hi < t) {
            t = g_2bbb60.hi;
        }
        out->f34 = out->f34 * t;
    }
}
}
