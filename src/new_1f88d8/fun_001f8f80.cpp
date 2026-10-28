struct XF { char pad[0x98]; short kind; };
struct PHYS { char pad[0xA0]; int ctTorque; char pad2[0xC0 - 0xA4]; int ctForce; };
struct SO { char pad[0x58]; XF *pxfLinear; XF *pxfAngular; char pad1[0xE8 - 0x60]; PHYS *pphys; char pad2[0x148 - 0xEC]; unsigned long grfso; };
struct NODE { char pad[0x40]; NODE *pnext; char pad1[0x60 - 0x44]; SO *pso; };
struct SW { char pad[0x3D1C]; NODE *plist; };
int FXfKindStatic(int);
void func_001F8E90(SW *, SO *, int *, SO **);
void func_001F9240(SW *, unsigned, int, SO **);
void func_001F8F80(SW *psw, unsigned grf)
{
    struct { SO *apso[769]; int cso; } l;
    NODE *pnode;
    SO *pso;
    for (pnode = psw->plist; pnode != 0; pnode = pnode->pnext) {
        pso = pnode->pso;
        PHYS *pphys = pso->pphys;
        if (pphys == 0) continue;
        if ((pso->grfso & 0x8000000UL) != 0) continue;
        if (pphys->ctForce == 3 && pphys->ctTorque == 3) continue;
        if ((grf & 1) != 0) {
            if (FXfKindStatic(pso->pxfLinear->kind) != 0 && FXfKindStatic(pso->pxfAngular->kind) != 0) continue;
        }
        l.cso = 0;
        func_001F8E90(psw, pso, &l.cso, l.apso);
        func_001F9240(psw, grf, l.cso, l.apso);
    }
    for (pnode = psw->plist; pnode != 0; pnode = pnode->pnext) {
        pso = pnode->pso;
        pso->grfso &= ~0x8000000UL;
        pso->grfso &= ~0x10000000UL;
    }
}
