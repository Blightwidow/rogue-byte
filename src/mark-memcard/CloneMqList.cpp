struct MQ { char pad[0xAC]; MQ *next; char pad2[0x10]; } __attribute__((aligned(16)));
struct SW { char pad[0x3D40]; char slotheap[1]; };
extern "C" void *PvAllocSlotheapImpl(char *);
MQ *CloneMqList(SW *psw, MQ *src)
{
    if (src == 0) return 0;
    MQ *head = 0;
    MQ **link = &head;
    char *heap = psw->slotheap;
    do {
        MQ *clone = (MQ *)PvAllocSlotheapImpl(heap);
        *clone = *src;
        *link = clone;
        src = src->next;
        link = &clone->next;
    } while (src != 0);
    return head;
}
