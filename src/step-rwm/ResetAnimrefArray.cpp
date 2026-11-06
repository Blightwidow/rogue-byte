struct Animref { int field0; int field4; int field8; int fieldC; };
extern "C" void ResetAnimref(Animref* animref, void* owner);
extern "C" void ResetAnimrefArray(void* owner, Animref* animrefs) {
    for (int index = 0; index < 26; index++) {
        ResetAnimref(&animrefs[index], owner);
    }
}
