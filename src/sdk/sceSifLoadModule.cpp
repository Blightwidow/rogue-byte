extern "C" {
struct Result { int words[4]; };
void func_00238F38(int, int, int, Result *);
void sceSifLoadModule(int path, int length, int argument) {
    Result result;
    func_00238F38(path, length, argument, &result);
}
}
