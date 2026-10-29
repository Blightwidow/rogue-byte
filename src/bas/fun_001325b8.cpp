typedef int s32;
extern "C" {
void Close__18CBinaryAsyncStream(s32);
void __builtin_delete(s32);

void func_001325B8(s32 arg0, s32 arg1) {
    Close__18CBinaryAsyncStream(arg0);
    if (arg1 & 1) {
        __builtin_delete(arg0);
    }
}

}
