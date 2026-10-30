extern "C" char *PjsgeAllocJsg(void *, int);
extern "C" void func_001E0C08(void *jsg, int a, int unused, int b, int c, float x, float y)
{
    char *node = PjsgeAllocJsg(jsg, 0x24);
    *(int *)(node + 0x10) = a;
    *(float *)(node + 0x14) = x;
    *(float *)(node + 0x18) = y;
    *(int *)(node + 0x1C) = b;
    *(int *)(node + 0x20) = c;
    *(int *)(node + 0x24) = 0;
}
