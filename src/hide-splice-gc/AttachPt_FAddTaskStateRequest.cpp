#include "sly2.h"
extern char B_002DEB30[];
extern "C" void func_00161F10(void *, void *, int, void *, int, int);
extern "C" void AttachPt_FAddTaskStateRequest(char *pattach, int arg1, int arg2)
{
    func_00161F10(B_002DEB30, pattach + 0x160, 4, pattach + 0x15C, arg1, arg2);
}
