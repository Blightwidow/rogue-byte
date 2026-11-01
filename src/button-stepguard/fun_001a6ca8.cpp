extern "C" {
void ReinsertSwRoot(char *, int);
extern char B_003DD490[];
struct S6CA8 { char pad[0x10]; int field10; int field14; char pad18[0x10]; unsigned long low:52; long nib:4; unsigned long mid:4; unsigned top:4; };
void func_001A6CA8(S6CA8 *self, int arg1) {
    if (arg1 == self->nib) return;
    self->nib = arg1;
    if (self->field10 != 0) return;
    if (self->top & 1) ReinsertSwRoot(B_003DD490, self->field14);
}
}
