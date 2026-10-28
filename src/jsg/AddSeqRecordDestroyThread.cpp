struct ITEM { char pad[0x10]; int value; };
struct JSG;
extern "C" ITEM *PjsgeAllocJsg(JSG *, int, int);
extern "C" void AddSeqRecordDestroyThread(JSG *jsg, int value)
{
    ITEM *item = PjsgeAllocJsg(jsg, 2, 1);
    item->value = value;
}
