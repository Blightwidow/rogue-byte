typedef struct Slot { struct Slot *next; volatile int id; int field8; int fieldC; } Slot;  // volatile-ok: id is written by the alarm callback func_0023A668 (interrupt context) and by the callers between interrupt disable and enable
extern Slot *B_0044E700;
extern int func_00239450(void);
extern void func_002394A0(void);
extern int func_0023A228(void);
extern void func_0023A2F0(int);
extern void func_0023A420(int, int, void (*)(void), Slot *);
extern void func_0023A668(void);
static inline Slot *SlotPop(void) {
    Slot *head = B_0044E700;
    if (head != 0) {
        B_0044E700 = head->next;
    }
    return head;
}
static inline void SlotPush(Slot *entry) {
    entry->next = B_0044E700;
    B_0044E700 = entry;
    entry->id = 0;
}
int func_0023A7F8(int arg0, int arg1, int arg2) {
    Slot *slot;
    int id;
    if (arg1 == 0) {
        return 0x80000016;
    }
    slot = SlotPop();
    if (slot == 0) {
        return 0x80008005;
    }
    id = func_0023A228();
    if (id < 0) {
        SlotPush(slot);
        return id;
    }
    slot->field8 = arg1;
    slot->fieldC = arg2;
    slot->id = id;
    func_0023A420(id, arg0, func_0023A668, slot);
    func_0023A2F0(id);
    return ((int)slot << 4) | (id & 0xFE) | 1;
}
