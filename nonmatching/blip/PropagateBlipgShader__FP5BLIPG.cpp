typedef int QW __attribute__((mode(TI)));
struct SHD { char pad0[8]; unsigned flags; unsigned char color[4]; int cframe; long *apacket; };
struct BLIPG {
    char pad0[0x1A0]; int cqwTexture; char pad1[0x1B0 - 0x1A4]; QW aqw[1];
    char pad2[0x3B0 - 0x1C0]; int hasColor; unsigned char color[4]; char pad3[0x438 - 0x3B8]; char *pgifs;
};
struct PK { long packet; int six; int keep; };
extern "C" SHD *PshdframesOrFirst(int);
extern "C" char B_002DD600;
extern "C" char B_002DD5C0;
extern "C" void PropagateBlipgShader__FP5BLIPG(BLIPG *pblipg, int oidShader)
{
    SHD *pshd = PshdframesOrFirst(oidShader);
    pblipg->pgifs = (pshd->flags & 1) ? &B_002DD600 : &B_002DD5C0;
    if (pblipg->hasColor == 0) {
        pblipg->hasColor = 1;
        unsigned char *dst = pblipg->color;
        unsigned char *src = pshd->color;
        for (int ib = 0; ib < 4; ib++)
            dst[ib] = (src[ib] + 1) >> 1;
    }
    int cframe = pshd->cframe;
    int cqw = 1;
    for (int shifted = cframe >> 1; shifted != 0; shifted >>= 1)
        cqw <<= 1;
    cqw <<= (cqw < cframe) ? 1 : 0;
    while (cqw > 31)
        cqw >>= 1;
    int cduplicate = 0;
    if (cframe < cqw)
        cduplicate = cqw - cframe;
    pblipg->cqwTexture = cqw;
    QW *pqw = pblipg->aqw;
    for (int iframe = 0; iframe < cframe; iframe++) {
        long packet = pshd->apacket[iframe];
        ((PK *)pqw)->six = 6;
        ((PK *)pqw)->packet = packet;
        if (iframe < cduplicate) {
            pqw[1] = pqw[0];
            pqw++;
        }
        pqw++;
    }
}
