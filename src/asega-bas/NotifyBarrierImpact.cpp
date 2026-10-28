struct SIDE { int pad0[2]; int pso; char pad[0x34]; };
struct XP { SIDE side[2]; char pad[0xAC - 0x80]; XP *pxpNext; };
struct NODE { XP *pxpChain; NODE *pnodeNext; };
struct OXA { char pad[0x64]; NODE *pnode; };
struct BARRIERVT { char pad[0x18]; short delta; short idx; void (*fn)(void *, int, int, int, int, int); };
struct BARRIER { char pad0[0xC]; BARRIERVT *vt; char pad1[0xDC]; OXA *poxa; char pad2[0x8C]; int psoToucher; };

extern "C" void NotifyBarrierImpact(BARRIER *pbarrier)
{
    int apso[16];
    int cpso = 0;
    int ipso;
    for (NODE *pnode = pbarrier->poxa->pnode; pnode != 0; pnode = pnode->pnodeNext) {
        for (XP *pxp = pnode->pxpChain; pxp != 0; pxp = pxp->pxpNext) {
            int fNotSelf = pxp->side[0].pso != (int)pbarrier;
            int pso = pxp->side[1 - fNotSelf].pso;
            for (ipso = 0; ipso < cpso; ipso++) {
                if (pso == apso[ipso])
                    break;
            }
            if (ipso < cpso)
                continue;
            apso[cpso++] = pso;
            if ((unsigned)cpso >= 16)
                goto done;
        }
    }
done:
    for (ipso = 0; ipso < cpso; ipso++) {
        pbarrier->psoToucher = apso[ipso];
        pbarrier->vt->fn((char *)pbarrier + pbarrier->vt->delta, 5, 0, 0, 0, 0);
    }
}
