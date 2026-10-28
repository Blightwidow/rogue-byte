struct Entry { int a, b, c; };
struct Gun { char pad[0x10]; Entry *slots; char pad2[0x58]; int index; int need; };
int FVehicleGunHasAmmo(Gun *gun) {
    Entry *entry = gun->slots + gun->index;
    return !(*(int *)((char *)entry + 0x574) < gun->need);
}
