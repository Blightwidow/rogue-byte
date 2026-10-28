#include "sly2.h"

extern "C" int FFilterOxaBasic(void* pvSensor, void* pgeom);
extern "C" int CidGetBasic(int);
extern "C" int FFilterSensorBasic(void* pvSensor, void* pgeom);

int FFilterSensorBasic(void* pvSensor, void* pgeom)
{
    if (!FFilterOxaBasic(pvSensor, pgeom))
        return 0;
    return CidGetBasic(*(int*)((char*)pgeom + 4)) == 0x31;
}