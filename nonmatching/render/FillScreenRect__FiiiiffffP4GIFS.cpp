struct GIFS {
    void *AddPrimPack(int, int, unsigned long);
    void *PackAD(long, long);
    void *PackRGBA(unsigned int);
    void *PackXYZF(int, int, int, int);
};
struct RGBA { unsigned char b[4]; };

void *FillScreenRectImpl(RGBA *prgba, GIFS *pgifs, float x0, float y0, float x1, float y1)
{
    int cqwPacket = prgba->b[3] > 0xfe ? 6 : 0x46;
    pgifs->AddPrimPack(cqwPacket, 5, 0x441ee);
    prgba->b[3] = (prgba->b[3] + 1) >> 1;
    pgifs->PackAD(0x47, 0x31001);
    pgifs->PackAD(0x42, 0x44);
    pgifs->PackRGBA(*(unsigned int *)prgba);
    pgifs->PackXYZF((int)((x0 * 0.8f + 1792.0f) * 16.0f), (int)((y0 * 0.45454547f + 1936.0f) * 16.0f), 0, 0);
    return pgifs->PackXYZF((int)((x1 * 0.8f + 1792.0f) * 16.0f), (int)((y1 * 0.45454547f + 1936.0f) * 16.0f), 0, 0);
}
