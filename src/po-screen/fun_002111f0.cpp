struct ENTRY { char pad[0xF8]; int stringId; };
struct GADGET { char pad[0x74]; int count; ENTRY *entries[1]; };
extern char B_003DD490[];
extern "C" char *PpoSwFocusBase(char *);
extern "C" int FIsBasicDerivedFrom(void *, int);
extern "C" const char *PchzStringFromId(char *, int);
extern "C" char *strcpy(char *, const char *);

void func_002111F0(char *dest, int index)
{
    char *focus = PpoSwFocusBase(B_003DD490);
    if (focus == 0 || FIsBasicDerivedFrom(focus, 0x34) == 0)
        return;
    GADGET *gadget = *(GADGET **)(focus + 0xF38);
    if (gadget == 0 || index >= gadget->count)
        return;
    strcpy(dest, PchzStringFromId(B_003DD490, gadget->entries[index]->stringId));
}
