#include "sly2.h"
extern "C" int *PemitripEnsureEmitter(void *, int);
extern "C" int GetEmitterRipt(void *pemitter)
{
    return *PemitripEnsureEmitter(pemitter, 0);
}
