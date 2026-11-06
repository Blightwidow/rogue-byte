struct Animref { int field0; int field4; int field8; int fieldC; };
extern "C" void BindAnimref(Animref* animref, void* owner);
extern "C" void BindAnimrefArray(void* owner, Animref* animrefs) {
    for (int index = 0; index < 26; index++) {
        BindAnimref(&animrefs[index], owner);
    }
}
