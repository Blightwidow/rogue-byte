#include "sly2.h"
struct VTL { char pad[0x18]; short delta; short index; void (*fn)(void *, int, int, int, int, int); };
struct BOMB { VTL **dummy; };
extern QW g_2a2dd0;
extern "C" void func_001A58D0(void *, void *, int);
extern "C" void func_001F4898(void *, QW);
extern "C" void func_001F4930(void *, QW);
extern "C" void SetSoCnstrForce(void *, int);
extern "C" void SetSoCnstrTorque(void *, int);
void func_0013B250(char *b, char *stick)
{
    *(char **)(b + 0x1E8) = stick;
    func_001A58D0(b, *(int *)(stick + 0x18) == 1 ? 0 : stick, 3);
    func_001F4898(b, g_2a2dd0);
    func_001F4930(b, g_2a2dd0);
    SetSoCnstrForce(b, 1);
    SetSoCnstrTorque(b, 1);
    VTL *vt = *(VTL **)(b + 0xC);
    vt->fn(b + vt->delta, 0x1B, 0, 0, 0, 0);
}
