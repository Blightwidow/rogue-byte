struct Owner { char pad0[0x28]; unsigned long flags; };
struct Geom { char pad0[0x10]; long flags; };
extern "C" void AddSoGeomToOxa(Owner *, Geom *);
extern "C" void func_001F2A60(Owner *owner, Geom *geom) {
    long flags = geom->flags;
    if (flags & (0x8000L << 35)) {
        geom->flags = flags & ~(0x8000L << 35);
        if ((int)(owner->flags >> 0x3C) & 1) {
            AddSoGeomToOxa(owner, geom);
        }
    }
}
