struct Blot { char pad0[0x7C]; int state; char pad80[0x110 - 0x80]; int fHandsOff; };
struct SW;
extern "C" {
void Blot_Show(Blot *, int);
void SetHandsOff(SW *, int);
int func_00213B00(Blot *, int);
extern SW B_003DD490;

void PromptBlot_Show(Blot *pblot, int labelStart) {
    if (pblot->state == -1) {
        Blot_Show(pblot, labelStart);
        SetHandsOff(&B_003DD490, 0);
        pblot->fHandsOff = 1;
        func_00213B00(pblot, 0x33A);
    }
}
}
