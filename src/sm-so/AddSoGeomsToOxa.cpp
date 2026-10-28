struct Geom { char pad[0x10]; unsigned long flags; char pad2[0xB0 - 0x18]; };
struct Oxa { char pad[0xE0]; int count; Geom *geoms; };
extern "C" void AddSoGeomToOxa(Oxa *, Geom *);
extern "C" void AddSoGeomsToOxa(Oxa *oxa) {
    for (int index = 0; index < oxa->count; index++) {
        Geom *geom = &oxa->geoms[index];
        if (!(geom->flags & 0x8000UL << 35))
            AddSoGeomToOxa(oxa, geom);
    }
}
