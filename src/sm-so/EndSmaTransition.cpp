struct SMA {
    char pad0[0x30];
    void *current;
    int stateCurrent;
    int stateNext;
};
extern "C" void NotifySmaSpliceOnEnterState(SMA *, int, int);
extern "C" void EndSmaTransition(SMA *sma)
{
    sma->current = 0;
    int next = sma->stateNext;
    int previous = sma->stateCurrent;
    sma->stateNext = -1;
    sma->stateCurrent = next;
    NotifySmaSpliceOnEnterState(sma, previous, next);
}
