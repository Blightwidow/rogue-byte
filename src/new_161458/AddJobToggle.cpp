struct Toggle_1626C0 { int word0; int word4; int word8; int wordC; };
struct Owner_1626C0 { char pad0[0x50]; int blocked; char pad1[0x8C - 0x54]; int count; Toggle_1626C0 *toggles; };
extern "C" {
int GrfOfState(int);
void AddJobToggle(Owner_1626C0 *owner, int arg1, int arg2, int arg3, int arg4) {
    if (owner->blocked == 0) {
        int index = owner->count;
        if (index < 0x20) {
            Toggle_1626C0 *toggle = owner->toggles + index;
            owner->count = index + 1;
            toggle->word0 = arg1;
            toggle->word4 = arg3;
            toggle->word8 = GrfOfState(arg2);
            toggle->wordC = arg4;
        }
    }
}
}
