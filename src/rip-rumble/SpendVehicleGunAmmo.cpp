struct VG { char pad0[0x10]; char *base; char pad1[0x58]; int index; int cost; };
extern "C" void SpendVehicleGunAmmo(VG *vg)
{
    int *slot = (int *)(vg->base + (vg->index * 12 + 0x574));
    int left = *slot - vg->cost;
    *slot = (left > -1) ? left : 0;
}
