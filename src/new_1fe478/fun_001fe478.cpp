struct VT { char pad[0x10]; short delta; short index; void (*fn)(void *); };
struct Amb {
    char pad0[0xC];
    VT *vt;
    char pad1[0x60 - 0x10];
    int rec;
};
struct Stream {
    char pad[0x204];
    int count;
};
#define AMB(st, i) (*(Amb **)((char *)(st) + 0x208 + (i) * 4))
extern "C" int func_001FCFF8(Stream *, int);
extern "C" void func_00259BB0(void *, void *);
extern "C" void func_00259B48(void *, void *);

void **func_001FE478(void **out, Stream *stream, int id)
{
    int rec = func_001FCFF8(stream, id);
    int index = 0;
    while (index < stream->count && AMB(stream, index)->rec != rec)
        index++;
    if (index == stream->count) {
        func_00259BB0(out, 0);
        return out;
    }
    Amb *taken;
    func_00259BB0(&taken, AMB(stream, index));
    stream->count = stream->count - 1;
    for (; index < stream->count; index++)
        func_00259B48(&AMB(stream, index), AMB(stream, index + 1));
    func_00259BB0(out, taken);
    if (taken) {
        VT *vt = taken->vt;
        vt->fn((char *)taken + vt->delta);
    }
    return out;
}
