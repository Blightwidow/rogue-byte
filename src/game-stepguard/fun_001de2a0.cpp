#include "so.h"
extern "C" void InitSo(SO *);
extern "C" void func_001DE2A0(SO *so)
{
    InitSo(so);
    so->grfso |= 0x400000000UL;
}
