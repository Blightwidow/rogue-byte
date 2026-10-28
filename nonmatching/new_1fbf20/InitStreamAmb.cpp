#include "sly2.h"
struct AMB { char pad0[0xC]; void *vtable; char pad10[0x50]; int record; char pad64[0xC]; float vol[6]; char pada0[0x3B8 - 0x88]; int start; };
extern "C" void InitAmbBase(AMB *);
extern "C" void SetAmbGrf(AMB *, int, int);
extern "C" void PauseAmb(AMB *);
extern "C" int func_001FD080(void *, int);
extern char B_003DD040[];
extern char D_002D9BE0[];

extern "C" AMB *InitStreamAmb(AMB *amb, int record, int start)
{
    InitAmbBase(amb);
    amb->record = record;
    amb->vtable = D_002D9BE0;
    amb->start = start;
    for (int slot = 5; slot >= 0; --slot) {
        amb->vol[slot] = 1.0f;
    }
    SetAmbGrf(amb, 0x801, 0x801);
    int kind = func_001FD080(B_003DD040, amb->record);
    if (*(float *)((char *)(kind * 4 + (int)B_003DD040) + 0x15C) == 0.0f) {
        PauseAmb(amb);
    }
    if (*(int *)(B_003DD040 + 0x58)) {
        PauseAmb(amb);
    }
    return amb;
}
