struct Quad { int first; int second; int third; int fourth; };
extern "C" void func_0024B8F8(Quad *quad, int value, int other) {
 quad->first = value;
 quad->third = value;
 quad->second = other;
 quad->fourth = value;
}
