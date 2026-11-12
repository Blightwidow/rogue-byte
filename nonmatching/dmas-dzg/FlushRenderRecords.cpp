#include "sly2.h"
#include "sw.h"
struct V3_157FA0 { char xy[8]; int z; };
struct V4_157FA0 { V3_157FA0 v; float w; };
struct Cam_157FA0 { char pad0[0x4C]; float nearPlane; float farPlane; char pad1[0x60 - 0x54]; QW view[4]; char pad2[0x140 - 0xA0]; QW proj[4]; };
struct Vifs_157FA0 { char pad0[0xC]; QW *pqwCur; char pad1[0x20 - 0x10]; int fActive; };
struct Dmas_157FA0 { char pad0[0x24]; QW *pqwSaved; };
struct Rec_157FA0 { int type; int unk4; u32 chain0; u32 chain1; };
struct Pass_157FA0 { void (*begin)(Vifs_157FA0 *, int, int); void (*end)(Vifs_157FA0 *, int, int); };
extern "C" {
int SortRenderRecords(int, QW *, Rec_157FA0 **, int *, int *);
void AddDmaCall__4DMASP2QW(void *, void *);
int AddDmaCnt__4DMAS(void *);
void EndDmaCnt__4DMAS(void *);
void AddVifDirect__4VIFSiP2QWi(void *, int, void *, int);
int AddVifFlush__4VIFS(void *);
void AddVifBaseOffset__4VIFSii(void *, int, int);
void AddVifUnpack__4VIFS3UPKiPvi(void *, int, int, void *, int);
void *bevy_camera_cm_14f768(void *, int, int, void *, void *);
void func_001574A0(void *);
void func_001EA9F0(void *, int);
extern Vifs_157FA0 g_2dea28;
extern Dmas_157FA0 *g_2dea4c;
extern SW B_003DD490;
extern QW B_003B3980[];
extern QW *B_003D4A50;
extern Cam_157FA0 B_002DDF40;
extern char B_002DEA00[];
extern Dmas_157FA0 B_002DEA50;
extern char B_002DEDC0[];
extern char B_002DF800[];
extern char B_002DF940[];
extern char B_002DFA80[];
extern int B_002DE5A4;
extern char D_002C1F00[];
extern char D_002C1F10[];
extern int D_002BDD20[];
extern Pass_157FA0 D_002BDD88[];
void FlushRenderRecords(char *psw)
{
    QW mat[8];
    Rec_157FA0 *aprec[8192];
    int aiStart[28];
    int aiEnd[28];
    V4_157FA0 params[2];
    int crec = SortRenderRecords(B_003D4A50 - B_003B3980, B_003B3980, aprec, aiStart, aiEnd);
    g_2dea4c->pqwSaved = g_2dea28.pqwCur;
    AddDmaCall__4DMASP2QW(&g_2dea28, B_002DF800);
    g_2dea28.fActive = 1;
    AddDmaCnt__4DMAS(&g_2dea28);
    if (*(int *)(psw + 0x3E3C) != 0 || aiStart[1] == aiEnd[1]) {
        AddVifDirect__4VIFSiP2QWi(&g_2dea28, 0x25, B_002DEDC0, 0);
    }
    if (B_003DD490.field_0x3E38 != 0) {
        AddVifFlush__4VIFS(&g_2dea28);
        if (&B_002DEA50 == g_2dea4c) {
            AddDmaCall__4DMASP2QW(&g_2dea28, B_002DF940);
        } else {
            AddDmaCall__4DMASP2QW(&g_2dea28, B_002DFA80);
        }
    }
    AddVifBaseOffset__4VIFSii(&g_2dea28, 0, 0);
    params[0].v = *(V3_157FA0 *)D_002C1F00;
    float ratio = (B_002DDF40.nearPlane + B_002DDF40.farPlane) / (B_002DDF40.nearPlane - B_002DDF40.farPlane);
    float scale = B_002DDF40.nearPlane * (1.0f - ratio);
    params[0].w = 1.0f / scale;
    params[1].v = *(V3_157FA0 *)D_002C1F10;
    params[1].w = -ratio / scale;
    AddVifUnpack__4VIFS3UPKiPvi(&g_2dea28, 0xC, 2, params, 0);
    AddVifUnpack__4VIFS3UPKiPvi(&g_2dea28, 0, 1, &B_002DE5A4, 0xD);
    B_002DE5A4 = 0;
    if (B_003DD490.field_0x3E38 != 0) {
        if (g_2dea4c == &B_002DEA50) {
            bevy_camera_cm_14f768(&B_002DDF40, 1, 0, mat, mat + 4);
        } else {
            bevy_camera_cm_14f768(&B_002DDF40, 2, 0, mat, mat + 4);
        }
    } else {
        char *proj = (char *)&B_002DDF40 + 0x140;
        char *view = (char *)&B_002DDF40 + 0x60;
        mat[0] = *(QW *)((char *)&B_002DDF40 + 0x140);
        mat[1] = *(QW *)(proj + 0x10);
        mat[2] = *(QW *)(proj + 0x20);
        mat[3] = *(QW *)(proj + 0x30);
        mat[4] = *(QW *)((char *)&B_002DDF40 + 0x60);
        mat[5] = *(QW *)(view + 0x10);
        mat[6] = *(QW *)(view + 0x20);
        mat[7] = *(QW *)(view + 0x30);
    }
    AddVifUnpack__4VIFS3UPKiPvi(&g_2dea28, 0xC, 4, mat, 2);
    AddVifUnpack__4VIFS3UPKiPvi(&g_2dea28, 0xC, 4, mat + 4, 6);
    AddVifUnpack__4VIFS3UPKiPvi(&g_2dea28, 0xC, 1, psw + 0x3E28, 10);
    AddVifBaseOffset__4VIFSii(&g_2dea28, 0x32, 0x1E7);
    EndDmaCnt__4DMAS(&g_2dea28);
    int ipassCurrent = -1;
    int typeStart = -1;
    for (int irec = 0; irec < crec; irec++) {
        Rec_157FA0 *prec = aprec[irec];
        int type = prec->type;
        int ipass = D_002BDD20[type];
        if (ipass != ipassCurrent) {
            if (ipassCurrent != -1) {
                D_002BDD88[ipassCurrent].end(&g_2dea28, typeStart, type);
            }
            D_002BDD88[ipass].begin(&g_2dea28, type, typeStart);
            typeStart = type;
            ipassCurrent = ipass;
        }
        if (prec->chain0 != 0) {
            *(u64 *)g_2dea28.pqwCur = ((u64)prec->chain0 << 32) | 0x50000000;
            g_2dea28.pqwCur++;
        }
        if (prec->chain1 != 0) {
            *(u64 *)g_2dea28.pqwCur = ((u64)prec->chain1 << 32) | 0x50000000;
            g_2dea28.pqwCur++;
        }
    }
    if (ipassCurrent != -1) {
        D_002BDD88[ipassCurrent].end(&g_2dea28, typeStart, -1);
    }
    B_003D4A50 = 0;
    func_001574A0(B_002DEA00);
    func_001574A0(&g_2dea28);
    if (*(int *)(psw + 0x3EA8) != 0) {
        *(int *)(psw + 0x3EA8) = 0;
        func_001EA9F0(psw, 0);
    }
}
}
