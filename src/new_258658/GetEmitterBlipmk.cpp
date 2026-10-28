#include "sly2.h"
extern "C" int *PemitblipEnsureEmitter(void *, int);
extern "C" int GetEmitterBlipmk(void *pemitter)
{
    return *PemitblipEnsureEmitter(pemitter, 0);
}
