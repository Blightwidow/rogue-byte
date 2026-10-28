// 0x20AB58 ClearGuardAimObjects
#include "sly2.h"

void ClearGuardAimObjects(void* pguard) {
    int* guard = (int*)pguard;
    guard[0x3FC] = 0;
}