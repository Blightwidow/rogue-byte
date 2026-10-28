struct Bis { int pad0; int pb; int cb; }; extern "C" void Align__18CBinaryInputStreami(Bis *s, int n) { int old = s->pb; int mask = -n; int nw = (old - 1 + n) & mask; s->pb = nw; s->cb -= nw - old; }
