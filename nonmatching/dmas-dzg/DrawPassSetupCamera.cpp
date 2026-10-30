#include "sly2.h"
struct V3_157CF0 { char xy[8]; int z; };
struct V4_157CF0 { V3_157CF0 v; float w; };
struct Cam_157CF0 { char pad0[0x4C]; float nearPlane; float farPlane; char pad1[0x60 - 0x54]; QW view[4]; char pad2[0x140 - 0xA0]; QW proj[4]; };
extern "C" {
void AddDmaCall__4DMASP2QW(void *, void *);
int AddDmaCnt__4DMAS(void *);
void AddVifBaseOffset__4VIFSii(void *, int, int);
void AddVifDirect__4VIFSiP2QWi(void *, int, void *, int);
int AddVifFlush__4VIFS(void *);
void AddVifUnpack__4VIFS3UPKiPvi(void *, int, int, void *, int);
void EndDmaCnt__4DMAS(void *);
void *bevy_camera_cm_14f768(void *, int, int, void *, void *);
void func_0016E1A8(void *, int, int);
extern Cam_157CF0 B_002DDF40;
extern char B_002DEA50[];
extern char B_002DF010[];
extern char B_002DF800[];
extern char B_002DF940[];
extern char B_002DFA80[];
extern char B_003DD490[];
extern QW B_003E12B8;
extern char D_002C1F00[];
extern char D_002C1F10[];
extern void *g_2dea4c;
void DrawPassSetupCamera(char *arg0, int arg1, int arg2) {
    V4_157CF0 params[2];
    QW mat[8];
    if (*(int *)(B_003DD490 + 0x3E38) != 0) {
        if (g_2dea4c == (void *)B_002DEA50) {
            AddDmaCall__4DMASP2QW(arg0, B_002DF940);
        } else {
            AddDmaCall__4DMASP2QW(arg0, B_002DFA80);
        }
    } else {
        AddDmaCall__4DMASP2QW(arg0, B_002DF800);
    }
    *(short *)(arg0 + 0x20) = 1;
    AddDmaCnt__4DMAS(arg0);
    AddVifFlush__4VIFS(arg0);
    AddVifDirect__4VIFSiP2QWi(arg0, 0x25, B_002DF010, 0);
    AddVifBaseOffset__4VIFSii(arg0, 0, 0);
    params[0].v = *(V3_157CF0 *)D_002C1F00;
    float ratio = (B_002DDF40.nearPlane + B_002DDF40.farPlane) / (B_002DDF40.nearPlane - B_002DDF40.farPlane);
    float scale = B_002DDF40.nearPlane * (1.0f - ratio);
    params[0].w = 1.0f / scale;
    params[1].v = *(V3_157CF0 *)D_002C1F10;
    params[1].w = -ratio / scale;
    AddVifUnpack__4VIFS3UPKiPvi(arg0, 0xC, 2, params, 0);
    QW *mat1;
    if (*(int *)(B_003DD490 + 0x3E38) != 0) {
        int mode;
        if (g_2dea4c == (void *)B_002DEA50) {
            mode = 1;
        } else {
            mode = 2;
        }
        mat1 = (QW *)bevy_camera_cm_14f768(&B_002DDF40, mode, 0, mat, mat + 4);
    } else {
        mat1 = mat + 4;
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
    AddVifUnpack__4VIFS3UPKiPvi(arg0, 0xC, 4, mat, 2);
    AddVifUnpack__4VIFS3UPKiPvi(arg0, 0xC, 4, mat1, 6);
    AddVifUnpack__4VIFS3UPKiPvi(arg0, 0xC, 1, &B_003E12B8, 0xA);
    AddVifBaseOffset__4VIFSii(arg0, 0x32, 0x1E7);
    EndDmaCnt__4DMAS(arg0);
    func_0016E1A8(arg0, arg1, arg2);
}
}
