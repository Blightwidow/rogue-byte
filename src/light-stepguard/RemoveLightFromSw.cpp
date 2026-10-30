extern "C" {
struct Light_1A3E88 { char pad0[0x118]; int index; };
struct Sw_1A3E88 { char pad0[0x4154]; int slots[0x100]; char pad1[0x4590 - 0x4154 - 0x400]; unsigned mask[8]; int pad2[0x10]; };
void RemoveLightFromSw(Sw_1A3E88 *sw, Light_1A3E88 *light) {
    int index = light->index;

    sw->mask[index / 32] |= 1 << (index % 32);
    sw->slots[light->index] = 0;
    light->index = -1;
    *(int *)((char *)sw + 0x4554) = 1;
}
}
