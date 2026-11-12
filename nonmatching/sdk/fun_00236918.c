int func_00235B08(int a0, int a1, int a2, int a3, int a4);
int func_00236820(int a0, int a1, int a2, long a3);

void func_00236918(int a0, int a1, int a2, ...)
{
    func_00235B08((int)func_00236820, (int)&a0, a1, a2, (int)&a0 + 0x68);
}
