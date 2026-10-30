typedef long long s64; typedef unsigned long long u64;
extern "C" {
void AddPrimPack__4GIFSiiUl(void *gifs, int a, int b, int c);
void PackAD__4GIFSll(void *gifs, long reg, long value);
void CleanupDraw__5CFontP8CTextBoxP4GIFS(void *font, void *textBox, void *gifs) {
    if (textBox != 0) {
        AddPrimPack__4GIFSiiUl(gifs, 0, 1, 0xE);
        PackAD__4GIFSll(gifs, 0x40, ((0xDF00L << 31) | 0xFF80) << 9);
    }
}
}
