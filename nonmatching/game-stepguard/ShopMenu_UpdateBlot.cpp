#include "sly2.h"
struct BLOT { char pad[0x58]; int nBlots; };
struct ROW { int oid; int label; };
struct ENTRY { int type; int pad[7]; };
struct SHOPMENU {
    char pad0[0x24];
    BLOT *pblot;
    char pad1[0x30 - 0x28];
    int sel;
    char pad2[0x40 - 0x34];
    int page;
    char pad3[0x48 - 0x44];
    int cent;
    char pad4[0x4C - 0x4C];
    ROW arow[0x40];
    char pad5[0x24C - 0x4C - 0x200];
    int isel;
    int itop;
    int pad6[2];
    int labelC;
    int labelA;
    int labelB;
};
extern "C" {
void SwitchBlotLabel(BLOT *, int, void *);
int ShopMenu_IrowEnd(SHOPMENU *);
void func_00213928(BLOT *, int);
void func_00213A08(BLOT *, int, int);
void func_00213B00(BLOT *, int);
void func_00213BD8(BLOT *, int, int);
void func_00213CD8(BLOT *, int, void *);
extern int B_003DA570;
extern ENTRY D_002BCD04[];
extern int D_002C3588[];
extern float RO_002C35B0;
}
struct VEC2 { float v[8]; };
void ShopMenu_UpdateBlot(SHOPMENU *menu)
{
    if (menu->pblot->nBlots != 2) return;
    float vec[8] __attribute__((aligned(16)));
    memset(vec, 0, 0x20);
    vec[0] = 1.0f;
    vec[3] = 1.0f;
    int irowEnd = ShopMenu_IrowEnd(menu);
    if (menu->itop > 0) {
        int label = menu->page == 0 ? 0x4DA : 0x4A1;
        if (B_003DA570) {
            func_00213CD8(menu->pblot, label, vec);
            vec[5] += RO_002C35B0;
        }
        SwitchBlotLabel(menu->pblot, label, &menu->labelA);
    } else {
        SwitchBlotLabel(menu->pblot, -1, &menu->labelA);
    }
    int irow = menu->itop;
    int *plabelB = &menu->labelB;
    int *plabelC = &menu->labelC;
    if (irow < irowEnd) {
        ROW *prow = &menu->arow[irow];
        do {
            int oid = D_002C3588[irow - menu->itop];
            switch (menu->page) {
            case 1:
                if (prow->oid != -1) func_00213BD8(menu->pblot, 0x455, oid);
                else func_00213A08(menu->pblot, 0x455, oid);
                break;
            case 0:
                if (prow->oid != -1) {
                    int type = D_002BCD04[prow->oid].type;
                    if (type == 7) prow->label = 0x456;
                    else if (type == 9) prow->label = 0x458;
                    else if (type == 8) prow->label = 0x457;
                    func_00213BD8(menu->pblot, 0x455, oid);
                    func_00213BD8(menu->pblot, prow->label, oid);
                } else {
                    func_00213A08(menu->pblot, 0x455, oid);
                    func_00213A08(menu->pblot, prow->label, oid);
                    prow->label = -1;
                }
                break;
            }
            irow++;
            prow++;
        } while (irow < irowEnd);
    }
    if (menu->isel >= 0) {
        func_00213B00(menu->pblot, 0x437);
        memset(vec, 0, 0x20);
        vec[5] = RO_002C35B0 * (float)(menu->isel - menu->itop);
        vec[0] = 1.0f;
        vec[3] = 1.0f;
        func_00213CD8(menu->pblot, 0x437, vec);
    } else {
        func_00213928(menu->pblot, 0x437);
    }
    if (irowEnd < menu->cent) {
        int label = menu->page == 0 ? 0x4DD : 0x4A4;
        if (B_003DA570) {
            func_00213CD8(menu->pblot, label, vec);
            vec[5] += RO_002C35B0;
        }
        SwitchBlotLabel(menu->pblot, label, plabelB);
    } else {
        SwitchBlotLabel(menu->pblot, -1, plabelB);
    }
    SwitchBlotLabel(menu->pblot, ~menu->sel == 0 ? 0x439 : 0x43B, plabelC);
}
// x
