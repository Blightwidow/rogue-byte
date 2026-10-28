struct ITEM { char pad[0x10]; int value; };
struct JSG;
extern "C" ITEM *PjsgeAllocJsg(JSG *, int, int);
extern "C" void AddSeqRecordUntriggerSequence(JSG *jsg, int value)
{
    ITEM *item = PjsgeAllocJsg(jsg, 6, 1);
    item->value = value;
}
