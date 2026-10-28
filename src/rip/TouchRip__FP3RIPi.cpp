struct RIP;
extern "C" void RemoveRip();
void TouchRip__FP3RIPi(RIP *, int touched) {
    if (touched) RemoveRip();
}
