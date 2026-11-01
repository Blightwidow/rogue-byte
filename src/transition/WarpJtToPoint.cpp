typedef int QW __attribute__((mode(TI)));
struct Safe { char pad[0x10]; QW pos; };
void *memset(void *, int, unsigned int);
extern "C" void WarpJtToSafePoint(void *, Safe *);
extern "C" void WarpJtToPoint(void *jt, QW pos)
{
    Safe safe;
    memset(&safe, 0, 0x20);
    safe.pos = pos;
    WarpJtToSafePoint(jt, &safe);
}
