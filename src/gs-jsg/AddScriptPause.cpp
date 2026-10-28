struct Cmd { int pad0; int pad4; float value; };
extern "C" Cmd *PcmdAllocScript(void *self, int type, int arg);
void AddScriptPause(void *self, float seconds)
{
    PcmdAllocScript(self, 5, -1)->value = seconds;
}
