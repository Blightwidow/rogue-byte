struct AttachPaseg1944C8 { char pad[8]; int kind; int sub; char pad2[0x44]; void *a54; void *a58; void *a5c; void *a60; void *a64; };

extern "C" void *PasegAttachBase(AttachPaseg1944C8 *attach, int *secondary)
{
    int isSecondary = 0;
    void *paseg;
    switch (attach->kind) {
    case 0:
        paseg = attach->a54;
        if (attach->sub == 5) paseg = attach->a60;
        break;
    case 1:
        paseg = attach->a58;
        break;
    case 8:
        paseg = 0;
        if (attach->sub < 11 && attach->sub > 8) { paseg = attach->a64; isSecondary = 1; }
        break;
    default:
        paseg = 0;
    }
    *secondary = isSecondary;
    return paseg;
}
