struct SAA { char pad0[0x14]; int oid; char pad1[0x30 - 0x18]; int fStop; char pad2[0x40 - 0x34]; SAA *next; };
extern "C" {
extern SAA *B_003E159C;
SAA *PsaaFromOid(int oid)
{
    char frame[0x10] __attribute__((aligned(16)));
    if (oid == -1)
        return 0;
    SAA *psaa = B_003E159C;
    while (psaa && psaa->fStop == 0) {
        if (psaa->oid == oid)
            return psaa;
        psaa = psaa->next;
    }
    return 0;
}
}
