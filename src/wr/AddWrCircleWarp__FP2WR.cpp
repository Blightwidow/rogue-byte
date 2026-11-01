typedef int QW __attribute__((mode(TI)));
struct WARP { int kind; int id; char pad0[8]; QW pos; char pad1[0x60 - 0x20]; int state; char pad2[0xD0 - 0x64]; };
struct WR { char pad0[0x54]; int cwarp; int idNext; int idPending; WARP awarp[1]; };
extern "C" QW g_2a2da0;
extern "C" void AddWrCircleWarp__FP2WR(WR *pwr)
{
    WARP *pwarp = &pwr->awarp[pwr->cwarp++];
    *(int *)((char *)pwr + 0x6E0) += 1;
    pwarp->kind = 0;
    pwarp->pos = g_2a2da0;
    int pending = pwr->idPending;
    if (pending >= 0) {
        pwarp->id = pending;
        pwr->idPending = -1;
        pwarp->state = 2;
        return;
    }
    pwarp->id = pwr->idNext++;
    pwr->idPending = pwarp->id;
    pwarp->state = 0;
}
