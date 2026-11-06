struct ALO;
struct VECTOR { float x, y, z, w; } __attribute__((aligned(16)));
struct ASEGA { int pad0[6]; ALO* alo; int pad1[4]; ASEGA* next; };
struct ASEG { int pad[20]; ASEGA* firstAsega; };
extern "C" ASEGA* PasegaFindAseg__FP4ASEGP3ALO(ASEG* aseg, ALO* alo) {
    VECTOR local;
    for (ASEGA* asega = aseg->firstAsega; asega; asega = asega->next)
        if (asega->alo == alo) return asega;
    return 0;
}
