struct Toggle_163838 { int word0; int word4; int word8; int wordC; };
struct Owner_163838 { char pad0[0x50]; int blocked; char pad1[0xA8 - 0x54]; int count; Toggle_163838 *toggles; };
extern "C" {
int func_00162050(int);
void AddTaskToggle(Owner_163838 *owner, int arg1, int arg2, int arg3, int arg4) {
    if (owner->blocked == 0) {
        int index = owner->count;
        if (index < 0x20) {
            Toggle_163838 *toggle = owner->toggles + index;
            owner->count = index + 1;
            toggle->word0 = arg1;
            toggle->word4 = arg3;
            toggle->word8 = func_00162050(arg2);
            toggle->wordC = arg4;
        }
    }
}
}
