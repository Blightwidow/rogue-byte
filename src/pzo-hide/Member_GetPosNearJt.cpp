struct VSlotA { short delta; short index; void (*fn)(void *, void *, float *); };
struct VSlotB { short delta; short index; void (*fn)(void *, float, void *, void *, float *); };
struct VTable { char pad[0x10]; VSlotA slotParam; VSlotA slotPos; };
struct Member { char pad[0x20]; VTable *vtbl; };

extern "C" void Member_GetPosNearJt(Member *member, void *joint, float *paramOut, void *position, float *heading)
{
    float param;
    VSlotA *slotParam = &member->vtbl->slotParam;
    slotParam->fn((char *)member + slotParam->delta, joint, &param);
    VSlotB *slotPos = (VSlotB *)&member->vtbl->slotPos;
    slotPos->fn((char *)member + slotPos->delta, param, joint, position, heading);
    if (paramOut != 0)
        *paramOut = param;
}
