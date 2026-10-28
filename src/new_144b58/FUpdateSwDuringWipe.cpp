struct SW { char pad[0x150]; int state; };
int FUpdateSwDuringWipe(SW *psw)
{
    int state = psw->state;
    if (state < 4) {
        if (state >= 2)
            return 0;
    }
    return 1;
}
