struct Inst { char pad[0x30]; int f30; };
struct Animref { int kind; void *pv; Inst *pinst; int n; };
extern "C" {
int FAsegaGone(Inst *);
int FSmaRetracted(Inst *);
int FJumperDone(Inst *);
int func_0020CA98(Inst *);
}

int FDoneAnimref(Animref *ref)
{
    int r;
    switch (ref->kind) {
    case 0:
        r = 0;
        if (ref->pinst != 0) { if (!FAsegaGone(ref->pinst)) goto out; }
        r = 1;
        break;
    case 1:
        r = 0;
        if (ref->pinst != 0) {
            if (!FSmaRetracted(ref->pinst)) { if (ref->pinst->f30 != 0) goto out; }
        }
        r = 1;
        break;
    case 2:
        r = 0;
        if (ref->pinst != 0) { if (!FJumperDone(ref->pinst)) goto out; }
        r = 1;
        break;
    case 3:
        r = 0;
        if (ref->pinst != 0) { if (!func_0020CA98(ref->pinst)) goto out; }
        r = 1;
        break;
    case -1:
    default:
        r = 1;
    }
out:
    return r;
}
