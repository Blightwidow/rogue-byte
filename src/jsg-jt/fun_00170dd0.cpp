struct Cmd { int pad0; int pad4; int value; };
extern "C" Cmd *PcmdAllocScript(void *self, int type, int arg);
void func_00170DD0(void *self, int arg, int value)
{
    PcmdAllocScript(self, 0xF, arg)->value = value;
}
