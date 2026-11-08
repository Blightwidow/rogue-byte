typedef long s64;
typedef unsigned int u32;
typedef struct Slot { struct Slot* next; int field4; u32 id; u32 flags; s64 time; s64 field18; s64 field20; int callback; int field2c; int field30; int pad[3]; } Slot;
typedef struct { s64 timeHigh; int field8; int generation; int count; Slot* freeList; int field18; volatile u32 current; } KernelState;  // volatile-ok: current is set and cleared by the alarm interrupt handler func_00239F28 (sw at 0x23A02C, 0x23A0E0)
extern KernelState D_002C5A30;
extern s64 func_0023A1D0(void);
extern void func_00239E68(Slot*);
extern void func_00239CD8(s64);
int func_0023A2F0(u32 handle) {
    Slot* slot = (Slot*)((handle >> 10) << 6);
    s64 now;
    if ((int)handle < 0 || (handle & 0x3FF) != slot->id) return 0x80008002;
    if ((&D_002C5A30)->current == handle) return 0x80000010;
    if (slot->flags & 1) return 1;
    now = func_0023A1D0();
    slot->time = now;
    slot->flags |= 1;
    if (slot->flags & 2) {
        func_00239E68(slot);
        func_00239CD8(now);
    }
    return 0;
}
