#include "sly2.h"
struct B8 { char b[8]; };
struct V12 { B8 a; int b; };
struct Vec4 { V12 xyz; float w; };
struct DrawPass { void (*begin)(void *, long, long); void (*end)(void *, long, long); };
extern "C" {
extern char g_2dea28[];
extern char *g_2dea4c;
extern char B_003DD490[];
extern char B_003B3980[];
extern char *B_003D4A50;
extern char B_002DF800[];
extern char B_002DF940[];
extern char B_002DFA80[];
extern char B_002DEA50[];
extern char B_002DEDC0[];
extern char B_002DDF40[];
extern const V12 D_002C1F00;
extern const V12 D_002C1F10;
extern int B_002DE5A4;
extern int D_002BDD20[];
extern DrawPass D_002BDD88[];
extern char B_002DEA00[];
int SortRenderRecords(int, void *, unsigned *, int *, int *);
void AddDmaCall__4DMASP2QW(void *, void *);
void AddDmaCnt__4DMAS(void *);
void EndDmaCnt__4DMAS(void *);
void AddVifDirect__4VIFSiP2QWi(void *, int, void *, int);
void AddVifFlush__4VIFS(void *);
void AddVifBaseOffset__4VIFSii(void *, int, int);
void AddVifUnpack__4VIFS3UPKiPvi(void *, int, int, void *, int);
void bevy_camera_cm_14f768(void *, int, int, void *, void *);
void func_001574A0(void *);
void func_001EA9F0(void *, int);
void FlushRenderRecords(char *pswParam)
{
    QW matWorldToClip[4];
    QW matEye[4];
    unsigned apqwSorted[8192];
    int aiStart[28];
    int aiEnd[28];
    Vec4 avecExtra[2];
    char *volatile psw = pswParam;
    char *pvifs = g_2dea28;
    char **ppcurrent = &g_2dea4c;
    char *psw0 = B_003DD490;
    char *pcm = B_002DDF40;
    int crec = SortRenderRecords((B_003D4A50 - B_003B3980) >> 4, B_003B3980, apqwSorted, aiStart, aiEnd);
    *(int *)(*ppcurrent + 0x24) = *(int *)(pvifs + 0xC);
    AddDmaCall__4DMASP2QW(pvifs, B_002DF800);
    *(int *)(pvifs + 0x20) = 1;
    AddDmaCnt__4DMAS(pvifs);
    if (*(int *)(psw + 0x3E3C) != 0 || aiStart[1] == aiEnd[1])
        AddVifDirect__4VIFSiP2QWi(pvifs, 0x25, B_002DEDC0, 0);
    if (*(int *)(psw0 + 0x3E38) != 0) {
        AddVifFlush__4VIFS(pvifs);
        if (*ppcurrent == B_002DEA50)
            AddDmaCall__4DMASP2QW(pvifs, B_002DF940);
        else
            AddDmaCall__4DMASP2QW(pvifs, B_002DFA80);
    }
    AddVifBaseOffset__4VIFSii(pvifs, 0, 0);
    {
        float sNear = *(float *)(pcm + 0x4C);
        float sFar = *(float *)(pcm + 0x50);
        float gRatio = (sNear + sFar) / (sNear - sFar);
        float gDenominator = sNear * (1.0f - gRatio);
        avecExtra[0].xyz = D_002C1F00;
        avecExtra[0].w = 1.0f / gDenominator;
        avecExtra[1].xyz = D_002C1F10;
        avecExtra[1].w = -gRatio / gDenominator;
        AddVifUnpack__4VIFS3UPKiPvi(pvifs, 0xC, 2, avecExtra, 0);
    }
    AddVifUnpack__4VIFS3UPKiPvi(pvifs, 0, 1, &B_002DE5A4, 0xD);
    B_002DE5A4 = 0;
    if (*(int *)(psw0 + 0x3E38) == 0) {
        QW *pcm = (QW *)(pcm + 0x140);
        matWorldToClip[0] = pcm[0];
        matWorldToClip[1] = pcm[1];
        matWorldToClip[2] = pcm[2];
        matWorldToClip[3] = pcm[3];
        QW *peye = (QW *)(pcm + 0x60);
        matEye[0] = peye[0];
        matEye[1] = peye[1];
        matEye[2] = peye[2];
        matEye[3] = peye[3];
    } else {
        bevy_camera_cm_14f768(pcm, *ppcurrent == B_002DEA50 ? 1 : 2, 0, matWorldToClip, matEye);
    }
    AddVifUnpack__4VIFS3UPKiPvi(pvifs, 0xC, 4, matWorldToClip, 2);
    AddVifUnpack__4VIFS3UPKiPvi(pvifs, 0xC, 4, matEye, 6);
    AddVifUnpack__4VIFS3UPKiPvi(pvifs, 0xC, 1, psw + 0x3E28, 10);
    AddVifBaseOffset__4VIFSii(pvifs, 0x32, 0x1E7);
    EndDmaCnt__4DMAS(pvifs);
    int ipassCurrent = -1;
    int typeStart = -1;
    unsigned *ppqw = apqwSorted;
    for (int irec = 0; irec < crec; irec++, ppqw++) {
        int *prec = (int *)*ppqw;
        int type = prec[0];
        int ipass = D_002BDD20[type];
        if (ipass != ipassCurrent) {
            if (ipassCurrent != -1)
                D_002BDD88[ipassCurrent].end(pvifs, typeStart, type);
            D_002BDD88[ipass].begin(pvifs, type, typeStart);
            ipassCurrent = ipass;
            typeStart = type;
        }
        if (prec[2] != 0) {
            *(unsigned long *)*(char **)(pvifs + 0xC) = ((unsigned long)(unsigned)prec[2] << 32) | 0x50000000UL;
            *(char **)(pvifs + 0xC) += 0x10;
        }
        if (prec[3] != 0) {
            *(unsigned long *)*(char **)(pvifs + 0xC) = ((unsigned long)(unsigned)prec[3] << 32) | 0x50000000UL;
            *(char **)(pvifs + 0xC) += 0x10;
        }
    }
    if (ipassCurrent != -1)
        D_002BDD88[ipassCurrent].end(pvifs, typeStart, -1);
    B_003D4A50 = 0;
    func_001574A0(B_002DEA00);
    func_001574A0(pvifs);
    if (*(int *)(psw + 0x3EA8) != 0) {
        *(int *)(psw + 0x3EA8) = 0;
        func_001EA9F0(psw, 0);
    }
}
}
