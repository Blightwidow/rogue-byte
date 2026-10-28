extern "C" {
extern char B_003DD490[];
void *PpoSwFocusBase(void *);
int FIsBasicDerivedFrom(void *, int);
void *PloFindSwObject_thunk(void *, int, int, void *);
}

static inline void *Redirect(void *focus)
{
    if (focus != 0) {
        if (FIsBasicDerivedFrom(focus, 0x34) != 0)
            return *(void **)((char *)focus + 0xF40);
    }
    return focus;
}

void func_001BEED8(int oid)
{
    switch (oid) {
    case 0x2AE: {
        void *focus = PpoSwFocusBase(B_003DD490);
        void *target = Redirect(focus);
        PloFindSwObject_thunk(B_003DD490, 1, oid, target);
        break;
    }
    case 0x2AF:
        PloFindSwObject_thunk(B_003DD490, 1, 0x2AF, PpoSwFocusBase(B_003DD490));
        break;
    default:
        PloFindSwObject_thunk(B_003DD490, 0x405, oid, 0);
    }
}
