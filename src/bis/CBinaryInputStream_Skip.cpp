// 0x1179B8 FUN_001179b8
extern "C" void CBinaryInputStream_Read_thunk(void* a0, int a1, int a2);
void CBinaryInputStream_Skip(void* a0, int a1)
{
    CBinaryInputStream_Read_thunk(a0, a1, 0);
}