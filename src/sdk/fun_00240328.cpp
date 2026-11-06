extern "C" void exit_thunk(int) __attribute__((noreturn));
extern "C" void func_00240328() {
    exit_thunk(1);
}
