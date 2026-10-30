extern "C" {
int FIsBasicDerivedFrom(int, int);
extern int D_002C3D10[];
int FIsGuardSpecialClass(int arg0) {
    for (unsigned i = 0; i < 5; i++) {
        if (FIsBasicDerivedFrom(arg0, D_002C3D10[i]) != 0)
            return 1;
    }
    return 0;
}
}
