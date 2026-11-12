struct AlarmSlot;
typedef int (*AlarmHandler)(int, int, int, int);
struct AlarmSlot {
    AlarmSlot* next;
    int alarmId;
    AlarmHandler handler;
    int handlerArgument;
};
extern "C" {
extern AlarmSlot* B_0044E700;
int func_0023A668(int alarmId, int unusedFirst, int unusedSecond, AlarmSlot* slot) {
    int result = slot->handler(((int)slot << 4) | (alarmId & 0xFE) | 1, unusedFirst, unusedSecond, slot->handlerArgument);
    if (result == 0) {
        AlarmSlot* previousHead = B_0044E700;
        B_0044E700 = slot;
        slot->next = previousHead;
        slot->alarmId = 0;
        return -1;
    }
    return result;
}
}
