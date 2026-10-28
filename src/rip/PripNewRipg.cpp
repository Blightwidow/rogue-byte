struct RIPG { char pad[0x15C]; int dl; };
struct RIP { int pad0, pad1; RIPG *pripg; };
struct SW { char pad[0x4054]; int slotheap; };
void AddRipRef(RIP *);
extern "C" {
RIPG *PripgNew(void *, int);
void *PvAllocSlotheapImpl(void *);
RIP *ConstructRipOfType(void *, int);
void AppendDlEntry(void *, void *);
extern char B_003DD490[];
}

RIP *PripNewRipg(SW *psw, int ript, RIPG *pripg)
{
    if (pripg == 0) {
        pripg = PripgNew(B_003DD490, 0);
        if (pripg == 0)
            return 0;
    }
    void *pvSlot = PvAllocSlotheapImpl(&psw->slotheap);
    if (pvSlot != 0) {
        RIP *prip = ConstructRipOfType(pvSlot, ript);
        prip->pripg = pripg;
        AppendDlEntry(&pripg->dl, prip);
        AddRipRef(prip);
        return prip;
    }
    return 0;
}
