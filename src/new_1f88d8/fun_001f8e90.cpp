struct SW;
struct PHYS { char pad0[0xA0]; int ctTorque; char pad1[0x1C]; int ctForce; };
struct SO;
struct NODE { void *pxp; NODE *next; int unk8; SO *pso; };
struct OXA { char pad[0x64]; NODE *first; };
struct SO { char pad0[0xE8]; PHYS *pphys; OXA *poxa; char pad1[0x58]; unsigned long grfso; };
extern "C" void func_001F8E90(SW *psw, SO *pso, int *pcso, SO **apso)
{
    pso->grfso |= 0x8000000UL;
    apso[*pcso] = pso;
    *pcso = *pcso + 1;
    for (NODE *pnode = pso->poxa->first; pnode != 0; pnode = pnode->next) {
        if (pnode->pxp == 0)
            continue;
        SO *psoOther = pnode->pso;
        if ((psoOther->grfso & 0x8000000UL) != 0)
            continue;
        PHYS *pphys = psoOther->pphys;
        if (pphys == 0)
            continue;
        if (pphys->ctForce == 3 && pphys->ctTorque == pphys->ctForce)
            continue;
        func_001F8E90(psw, psoOther, pcso, apso);
    }
}
