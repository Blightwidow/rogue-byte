struct ELEM { char pad[0xC]; int kind; char pad10[0xB0 - 0x10]; };
struct OWNER { char pad[0xE0]; int count; ELEM *elems; };
extern "C" void func_001F2A60(OWNER *, ELEM *);

extern "C" void func_001F6AC8(OWNER *owner, int kind)
{
    for (int i = 0; i < owner->count; i++) {
        ELEM *elem = &owner->elems[i];
        if (elem->kind == kind)
            func_001F2A60(owner, elem);
    }
}
