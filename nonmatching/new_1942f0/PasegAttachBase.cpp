struct Attach { char pad[8]; int kind; int sub; char pad2[0x44]; void *a54; void *a58; void *a5c; void *a60; void *a64; };

extern "C" void *PasegAttachBase(Attach *attach, int *secondary)
{
    int isSecondary = 0;
    void *paseg;
    switch (attach->kind) {
    case 0:
        if (attach->sub == 5) paseg = attach->a60; else paseg = attach->a54;
        break;
    case 1:
        paseg = attach->a58;
        break;
    case 8: {
        int sub = attach->sub;
        paseg = 0;
        if (sub < 11) { if (sub > 8) { paseg = attach->a64; isSecondary = 1; } }
        break; }
    default:
        paseg = 0;
    }
    *secondary = isSecondary;
    return paseg;
}
