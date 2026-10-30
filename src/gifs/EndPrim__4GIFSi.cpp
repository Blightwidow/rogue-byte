struct Gifs_1669E0 { char pad0[0xC]; unsigned long *cursor; char pad10[0xC]; unsigned *tag; unsigned divisor; unsigned dividend; };
extern "C" {
void EndPrim__4GIFSi(Gifs_1669E0 *self, int eop) {
    if (self->tag != 0) {
        unsigned count = self->dividend / self->divisor;
        unsigned long *cursor = self->cursor;
        if (((unsigned)cursor & 0xF) != 0) {
            self->cursor = cursor + 1;
            *cursor = 0;
        }
        unsigned *tag = self->tag;
        unsigned value;
        if (eop != 0) {
            value = *tag | 0x8000;
        } else {
            value = *tag;
        }
        *tag = value | count;
        self->tag = 0;
    }
}
}
