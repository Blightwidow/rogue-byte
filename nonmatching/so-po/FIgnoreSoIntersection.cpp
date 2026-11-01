struct VT_1F4FC8 { char pad[0x1F0]; short delta; short index; int (*fn)(void *); };
struct SO_1F4FC8 { char pad0[0xC]; VT_1F4FC8 *vt; char pad1[0x148 - 0x10]; unsigned long grf; };
#define PROBE_1F4FC8(p) ((p)->vt->fn((char *)(p) + (p)->vt->delta))
extern "C" int FIgnoreSoIntersection(SO_1F4FC8 *a, SO_1F4FC8 *b)
{
    if (((a->grf & 0x4000000) == 0 && PROBE_1F4FC8(a) == 0) || PROBE_1F4FC8(b) == 0)
        return 0;
    return 1;
}
