struct VT20FA50 { char pad[0x1F0]; short delta; short index; int (*fn)(char *); };
struct Obj20FA50 { char pad[0xC]; VT20FA50 *vt; };
struct Arg20FA50 { int unk0; Obj20FA50 *owner; };
extern "C" {
int FFilterOxaBasic(void *, void *);

int FFilterHitTestDefault(void *arg0, Arg20FA50 *arg1) {
    if (!FFilterOxaBasic(arg0, arg1)) return 0;
    char *owner = (char *)arg1->owner;
    VT20FA50 *vt = *(VT20FA50 **)(owner + 0xC);
    return vt->fn(owner + vt->delta);
}
}
