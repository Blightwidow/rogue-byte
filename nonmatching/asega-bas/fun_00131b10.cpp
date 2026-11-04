struct XFACT_131B10 { int zero; int pad4[2]; int field_C; XFACT_131B10 *next; int pad14[4]; int key; };
struct Owner_131B10 { char pad[0x90]; XFACT_131B10 *list; };
extern "C" void ResortXfActList(int, Owner_131B10 *);
extern "C" void func_00131B10(int key, int arg1, Owner_131B10 *owner)
{
    XFACT_131B10 *act = owner->list;
    while (act != 0) {
        if (act->zero == 0 && act->key == key) {
            act->field_C = -1;
            ResortXfActList(arg1, owner);
            break;
        }
        act = act->next;
    }
}
