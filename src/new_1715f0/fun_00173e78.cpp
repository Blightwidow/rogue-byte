struct SLOT_173E78 { void *actor; float tSpawn; float tFree; int pad[9]; };
struct SPAWNER_173E78 { char pad[0x5C]; int count; SLOT_173E78 *slots; };
extern float g_2dded0;
extern float D_002BE5E0;
extern "C" SLOT_173E78 *func_00173E78(SPAWNER_173E78 *spawner, void *exclude)
{
    float now = g_2dded0;
    float tOldest = now - D_002BE5E0;
    float tFreeBest = now;
    SLOT_173E78 *best = 0;
    for (int index = 0; index < spawner->count; index++) {
        SLOT_173E78 *slot = &spawner->slots[index];
        if (slot->actor) { if (slot->actor != exclude) { if (best && !best->actor) continue; if (slot->tSpawn >= tOldest) continue; tOldest = slot->tSpawn; best = slot; } } else { if (slot->tFree >= tFreeBest) continue; tFreeBest = slot->tFree; best = slot; } }
    return best;
}
