struct B8 { char b[8]; };
struct B12 { B8 lo; int hi; };
struct RIPT { int ript; char pad[0x2C]; B12 payload; };
extern "C" {
RIPT *PemitripEnsureEmitter(void *, int);
extern const B8 D_002BDE50;
extern const int g_2bde58;
extern const B12 D_002BDE60;
}
extern "C" void SetEmitterRipt(void *pemitter, int ript)
{
    RIPT *pript = PemitripEnsureEmitter(pemitter, 1);
    if (pript->ript == ript || pript->ript != -1)
        return;
    pript->ript = ript;
    switch (ript) {
    case 2:
        pript->payload.lo = D_002BDE50;
        break;
    case 3:
        *(int *)&pript->payload = g_2bde58;
        break;
    case 8:
        pript->payload = D_002BDE60;
        break;
    }
}
