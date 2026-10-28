#include "sly2.h"
struct SWX { char pad[1]; };
extern SWX B_003DD490;
extern "C" const char RO_0025E090[];
extern "C" const char RO_0025E668[];
extern "C" void EnsureVu1Code__FP4VIFSPvT1(void *, const void *, const void *);
extern "C" void AddDmaCnt__4DMAS(void *);
extern "C" void AddVifFlusha__4VIFS(void *);
extern "C" void AddVifBaseOffset__4VIFSii(void *, int, int);
extern "C" void UnpackHelper__4VIFS3UPKiiPiPPUi(void *, int, int, int, int *, void *);
extern "C" void EndDmaCnt__4DMAS(void *);
extern "C" void CopyAb__FPvT0Ui(void *, const void *, unsigned);
extern "C" int CploFindSwObjectsByClass(SWX *, int, int, int, int, void **);
extern "C" void UploadRelightLights(void *vifs)
{
    void *lights[0x180];
    int *header;
    int *dest;
    int staticCount = 0;
    char *light;
    int index;
    EnsureVu1Code__FP4VIFSPvT1(vifs, RO_0025E090, RO_0025E668);
    AddDmaCnt__4DMAS(vifs);
    AddVifFlusha__4VIFS(vifs);
    AddVifBaseOffset__4VIFSii(vifs, 0x32, 0);
    int count = CploFindSwObjectsByClass(&B_003DD490, 0x505, 4, 0, 0x180, lights);
    for (index = 0; index < count; index++) {
        light = (char *)lights[index];
        if (*(int *)(light + 0x160) == 0)
            staticCount++;
    }
    if (staticCount > 0x100)
        staticCount = 0x100;
    UnpackHelper__4VIFS3UPKiiPiPPUi(vifs, 0xC, 1, 0, 0, &header);
    header[0] = 1;
    header[1] = staticCount * 3 + 1;
    int written = 0;
    int address = 1;
    int chunkEnd = 0;
    dest = 0;
    for (index = 0; index < count; index++) {
        light = (char *)lights[index];
        if (*(int *)(light + 0x160) != 0)
            continue;
        if (chunkEnd <= written) {
            int chunk = 0x20;
            int rest = staticCount - written;
            if (rest < chunk)
                chunk = rest;
            chunkEnd = written + chunk;
            UnpackHelper__4VIFS3UPKiiPiPPUi(vifs, 0xC, (chunkEnd - written) * 3, address, 0, &dest);
        }
        written++;
        CopyAb__FPvT0Ui(dest, light + 0x120, 0x30);
        address += 3;
        dest += 12;
        if (written > 0xff)
            break;
    }
    EndDmaCnt__4DMAS(vifs);
}
