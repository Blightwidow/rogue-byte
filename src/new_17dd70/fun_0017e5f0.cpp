#include "sly2.h"
extern "C" void func_001C1FA0(void *, int, float);
struct ENT { char b[32]; };
struct HDR { char h[0x60]; ENT e[1]; };
struct GOAL { char pad[0x10]; int p10; char pad2[0x1C]; HDR *base; int index; };
void func_0017E5F0(GOAL *pgoal){ func_001C1FA0((char*)pgoal->base + 0x60 + (pgoal->index << 5), pgoal->p10, 25.0f); }
