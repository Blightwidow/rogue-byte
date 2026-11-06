extern "C" {
struct Inner { char pad0[0x18]; int field18; };
struct Outer { char pad0[0x20]; int field20; Inner *inner; };
void func_001F4BF8(int);
void func_00256328(Outer *outer, int value) {
    outer->inner->field18 = value;
    func_001F4BF8(outer->field20);
}
}
