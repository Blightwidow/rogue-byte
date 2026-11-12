#include "sly2.h"
#include "vu0inline.h"
struct GIFS { char pad[0x30]; };
struct M4 { QW row[4]; };
extern "C" {
void DrawWipeSetup(void *);
void SetWipeState(void *, int);
void EndDmaCnt__4DMAS(GIFS *);
void AddDmaRefs__4DMASiP2QW(GIFS *, int, QW *);
void AddDmaCnt__4DMAS(GIFS *);
void AddPrimPack__4GIFSiiUl(GIFS *, int, int, unsigned long);
void PackAD__4GIFSll(GIFS *, long, long);
void PackSTQ__4GIFSfff(GIFS *, float, float, float);
void PackRGBA__4GIFSUi(GIFS *, unsigned);
void PackXYZ__4GIFSiii(GIFS *, int, int, int);
M4 ConvertXfMatrix4(void *, void *, void *);
QW __ml__FRC7MATRIX4G10VU_VECTOR4(const M4 *, QW);
void Force__FPv(void *);
extern char g_2dea4c[], g_2dea34[];
extern GIFS B_002DEA00;
extern QW B_002DF4B0;
struct Regs { unsigned long tex0; unsigned long pad; unsigned long page; };
extern Regs g_2decd0;
extern QW D_002BD3B0[];
extern M4 D_002BD410;
extern float D_002BD398[];
extern float D_002BD39C[];
extern float D_002BD3F0[];
}
static inline float ScreenCoordinate(float coordinate, float extent)
{
    return (coordinate + 0.5f) * extent + 0.5f;
}

void UpdateWipe(char *wipe)
{
    int state = *(int *)(wipe + 0x150);
    if (state != 1) {
        if (state <= 0)
            return;
        if (state >= 4)
            return;
    } else {
        DrawWipeSetup(wipe);
        SetWipeState(wipe, 2);
    }
    char *stream = *(char **)g_2dea4c;
    *(int *)(stream + 0x30) &= -2;
    if (*(int *)(stream + 0x24) == 0)
        *(int *)(stream + 0x24) = *(int *)g_2dea34;
    Regs *pregs = &g_2decd0;
    EndDmaCnt__4DMAS(&B_002DEA00);
    char **nodes = (char **)(wipe + 0x158);
    unsigned node = 0;
    AddDmaRefs__4DMASiP2QW(&B_002DEA00, 0x25, &B_002DF4B0);
    AddDmaCnt__4DMAS(&B_002DEA00);
    AddPrimPack__4GIFSiiUl(&B_002DEA00, 0, 1, 0xE);
    PackAD__4GIFSll(&B_002DEA00, 0x47, 0x31001);
    PackAD__4GIFSll(&B_002DEA00, 6, (pregs->page & 0x1FF) << 5 | (pregs->tex0 >> 16 & 0x3F) << 14 | 0x6A8000000UL);
    PackAD__4GIFSll(&B_002DEA00, 0x14, 0x61);
    PackAD__4GIFSll(&B_002DEA00, 0x3F, 0);
    PackAD__4GIFSll(&B_002DEA00, 8, 0x3800080000AL);
    M4 matrices[2];
    M4 *slot = matrices;
    do {
        *slot = ConvertXfMatrix4(0, *(void **)(wipe + 0x60), *nodes + 0x40);
        node++;
        nodes++;
        slot++;
    } while (node < 2);
    int quad = 0;
    do {
        switch (quad) {
        case 0:
            if (!*(int *)(wipe + 0x164) || !*(int *)(wipe + 0x16C))
                continue;
            break;
        case 1:
            if (!*(int *)(wipe + 0x168))
                continue;
            break;
        case 2:
            if (!*(int *)(wipe + 0x164) || *(int *)(wipe + 0x16C))
                continue;
            break;
        }
        int which = quad & 1;
        AddPrimPack__4GIFSiiUl(&B_002DEA00, 0x14, 3, 0x512);
        float *offsets0 = D_002BD398 + which * 2;
        float *offsets1 = D_002BD39C + which * 2;
        for (unsigned corner = 0; corner < 4; corner++) {
            unsigned off = corner * sizeof(QW);
            QW posLocal = __ml__FRC7MATRIX4G10VU_VECTOR4(&matrices[which], *(QW *)((char *)D_002BD3B0 + off));
            QW clipValue = __ml__FRC7MATRIX4G10VU_VECTOR4(&D_002BD410, posLocal);
            union { QW q; float f[4]; } clip;
            clip.q = clipValue;
            Force__FPv(&clip);
            float invW = 1.0f / clip.f[3];
            union { QW q; float f[4]; } scale;
            scale.q = VectorFromFloat(invW);
            clip.q = VectorScaleX(clip.q, scale.q);
            Force__FPv(&invW);
            Force__FPv(&clip);
            clip.f[0] = ScreenCoordinate(clip.f[0], 512.0f);
            clip.f[1] = ScreenCoordinate(clip.f[1], 224.0f);
            Force__FPv(&clip);
            PackSTQ__4GIFSfff(&B_002DEA00, invW * (D_002BD3F0[corner * 2] + *offsets0), invW * (D_002BD3F0[corner * 2 + 1] + *offsets1), invW);
            PackRGBA__4GIFSUi(&B_002DEA00, 0x80808080);
            PackXYZ__4GIFSiii(&B_002DEA00, ((int)clip.f[0] + 0x700) << 4, ((int)clip.f[1] + 0x790) << 4, 0);
        }
    } while (++quad < 3);
}
