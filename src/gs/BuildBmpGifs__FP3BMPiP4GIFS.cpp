struct GIFS;
struct BMP {
    short x0, y0;
    char pad4[4];
    unsigned short w;
    unsigned short h;
    unsigned char b0xC;
    unsigned char b0xD;
    char pad0xE[2];
    int unk0x10;
    int unk0x14;
    int count;
};
extern "C" void BuildImageGifs__FiiiiiiP4GIFS(int, int, int, int, int, int, GIFS *);
extern "C" void BuildBmpGifs__FP3BMPiP4GIFS(BMP *bmp, int block, GIFS *gifs)
{
    BuildImageGifs__FiiiiiiP4GIFS(block, bmp->b0xD, bmp->b0xC, bmp->w, bmp->h, bmp->count, gifs);
}
