struct Gifs_166F70 { char pad0[0xC]; unsigned long *cursor; };
union FloatBits_166F70 { float value; unsigned bits; };
extern "C" {
void CheckReg__4GIFSii(Gifs_166F70 *, int, int);
void ListRGBAQ__4GIFSUif(Gifs_166F70 *self, unsigned red_green_blue, float q) {
    CheckReg__4GIFSii(self, 0, 1);
    FloatBits_166F70 bits;
    bits.value = q;
    unsigned long *cursor = self->cursor;
    self->cursor = cursor + 1;
    *cursor = (unsigned long)red_green_blue | ((unsigned long)bits.bits << 32);
}
}
