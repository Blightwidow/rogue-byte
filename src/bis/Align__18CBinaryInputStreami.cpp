// 0x117988 CBinaryInputStream::Align
struct Bis_117988 { int pad0; int pb; int cb; };
extern "C" void Align__18CBinaryInputStreami(Bis_117988 *s, int n) {
    int old = s->pb;
    int mask = -n;
    int cb = s->cb;
    int nw = (old + (n - 1)) & mask;
    s->pb = nw;
    s->cb = cb - (nw - old);
}
