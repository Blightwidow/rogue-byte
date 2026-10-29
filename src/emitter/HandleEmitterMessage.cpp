extern "C" void UnsubscribeLoObject(void *, void *);

void HandleEmitterMessage(char *arg0, int arg1, void *arg2) {
    if (arg1 == 1) {
        if (arg2 == *(void **)(arg0 + 0x14C)) {
            UnsubscribeLoObject(arg2, arg0);
            *(void **)(arg0 + 0x14C) = 0;
        } else if (arg2 == *(void **)(arg0 + 0x150)) {
            UnsubscribeLoObject(arg2, arg0);
            *(void **)(arg0 + 0x150) = 0;
        }
    }
}
