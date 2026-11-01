struct OBJ { char pad[4]; int index; char pad2[0xCC]; int slots[1]; };
extern int D_002BFB28[];
extern "C" int bevy_player_p7_damage_1a23f8(OBJ *obj, int *out)
{
    int result = 0;
    int index = obj->index;
    while (index != -1) { result = obj->slots[index]; if (result != 0) break; index = D_002BFB28[index]; }
    *out = 0;
    return result;
}
