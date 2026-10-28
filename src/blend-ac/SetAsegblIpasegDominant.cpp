struct XF { char pad0[0x80]; float unk80; float unk84; const void *unk88; const void *unk8C; char pad90[0xA]; short unk9A; };
struct ACTN { char pad0[8]; XF *xf; char pad0C[0x10]; int unk1C; char pad20[8]; ACTN *next; };
struct GRP { char pad0[0x2C]; GRP *next; char pad30[4]; ACTN *first; };
struct ASEGBL { char pad0[0x50]; GRP *grp; char pad54[0x80]; int dominant; };
extern "C" int FActDrivesXf(ACTN *);
extern "C" const float g_2a4af0;
extern "C" char D_002C44E0[];

void SetAsegblIpasegDominant(ASEGBL *asegbl, int dominant)
{
    if (dominant == asegbl->dominant) return;
    GRP *grp = asegbl->grp;
    asegbl->dominant = dominant;
    if (!grp) return;
    do {
        ACTN *actn = grp->first;
        if (actn) {
            float low = g_2a4af0;
            do {
                if (actn->unk1C && FActDrivesXf(actn)) {
                    XF *xf = actn->xf;
                    xf->unk84 = low;
                    xf->unk80 = low;
                    xf->unk8C = D_002C44E0;
                    xf->unk88 = D_002C44E0;
                    xf->unk9A = 0;
                }
                actn = actn->next;
            } while (actn);
        }
        grp = grp->next;
    } while (grp);
}
