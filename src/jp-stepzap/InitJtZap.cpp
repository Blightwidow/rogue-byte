struct Zap { int a; int b; int pad8; int c; char pad[0x80]; int d; char p2[8]; float e; };
void InitJtZap(Zap *self, int value)
{
    self->a = value;
    self->b = -1;
    self->d = -1;
    self->e = 2.0f;
    self->c = 0x28;
}
