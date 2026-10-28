extern char B_003DD490[];
extern "C" char *PpoSwFocusBase(char *);
extern "C" int FIsBasicDerivedFrom(void *, int);
extern "C" char *func_002026F8(void *);
extern "C" char *func_00202730(void *);
extern "C" char *strcpy(char *, const char *);

void func_00211148(char *dest, int n)
{
    char *focus = PpoSwFocusBase(B_003DD490);
    if (focus == 0 || FIsBasicDerivedFrom(focus, 0x34) == 0)
        return;
    const char *name = 0;
    void *gadget = *(void **)(focus + 0xF38);
    if (gadget != 0) {
        if (n != 0) {
            if (n == 1)
                name = func_002026F8(gadget);
        } else
            name = func_00202730(gadget);
    }
    if (name != 0)
        strcpy(dest, name);
}
