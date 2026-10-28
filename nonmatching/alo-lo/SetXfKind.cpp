typedef int QW __attribute__((mode(TI)));
struct MATRIX4 { QW q[4]; };
struct XF {
    char pad0[0x94];
    int dof;
    short kind;
    char pad9a[0xB0 - 0x9A];
    union { QW velq; float vel[4]; };
    char padc0[0xF0 - 0xC0];
    float ax, ay, az;
};
struct ALO { int x; };
extern "C" int FXfKindDynamic(int);
extern "C" int FXfKindHasVelocity(int);
extern "C" int FXfKindStatic(int);
extern "C" MATRIX4 GetXfLocalRateMatrix(XF *);
extern "C" void InvertMatrix4Affine(MATRIX4 *, XF *);
MATRIX4 operator*(const MATRIX4 &, const MATRIX4 &);
extern "C" void func_0022C818(ALO *, XF *);
struct VT { char pad[0x178]; short delta; short index; void (*fn)(void *, int); };
struct Obj { char pad[0xC]; VT *vt; };
void SetXfKind(ALO *palo, XF *pxf, int kind)
{
    if (kind == pxf->kind) return;
    if (FXfKindHasVelocity(kind) && !FXfKindHasVelocity(pxf->kind)) {
        MATRIX4 rate;
        MATRIX4 inv;
        rate = GetXfLocalRateMatrix(pxf);
        switch (pxf->dof) {
        case 1: case 4: case 5: case 9: case 10:
            pxf->velq = rate.q[3];
            break;
        case 11: {
            float *v = pxf->vel;
            float v0 = ((float*)&rate.q[1])[0];
            float v1 = ((float*)&rate.q[2])[0];
            float v2 = ((float*)&rate.q[2])[1];
            v[0] = v0; v[1] = v1; v[2] = v2;
            break;
        }
        case 12: {
            float *v = pxf->vel;
            float v0 = ((float*)&rate.q[0])[0];
            float v1 = ((float*)&rate.q[1])[1];
            float v2 = ((float*)&rate.q[2])[2];
            v[0] = v0; v[1] = v1; v[2] = v2;
            break;
        }
        case 6: case 7: {
            InvertMatrix4Affine(&inv, pxf);
            rate = rate * inv;
            float *v = pxf->vel;
            float v0 = ((float*)&rate.q[1])[2];
            float v1 = ((float*)&rate.q[2])[0];
            float v2 = ((float*)&rate.q[0])[1];
            v[0] = v0; v[1] = v1; v[2] = v2;
            break;
        }
        }
    }
    switch (kind) {
    case 0: case 13: case 14: case 15: case 16: case 17: case 20: case 21:
        func_0022C818(palo, pxf);
        pxf->kind = kind;
        break;
    case 1: case 2: case 3:
        if (!FXfKindDynamic(pxf->kind)) {
            float *acc = &pxf->ax; acc[2] = 0; acc[1] = 0; pxf->ax = 0;
        }
        func_0022C818(palo, pxf);
        pxf->kind = kind;
        break;
    default:
        pxf->kind = kind;
        break;
    }
    if (!FXfKindStatic(kind)) {
        VT *vt = ((Obj *)palo)->vt;
        vt->fn((char *)palo + vt->delta, 4);
    }
}
