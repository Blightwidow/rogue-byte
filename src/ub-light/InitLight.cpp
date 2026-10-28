struct Light {
    char pad0[0x40]; int flags;
    char pad1[0x9C]; int kind; int lastVersion;
    char pad2[0x30]; int slot;
    char pad3[0x38]; float angle; int mode;
    char pad4[8]; float falloffNear; float falloffFar;
};
extern "C" void InitXfm(Light *);
extern "C" void func_001A6CA8(Light *, int);
extern "C" void InitLight(Light *light)
{
    InitXfm(light);
    light->kind = 0;
    light->lastVersion = -1;
    light->slot = -1;
    light->falloffNear = 200.0f;
    light->falloffFar = 2000.0f;
    light->angle = 240.0f;
    light->mode = 1;
    func_001A6CA8(light, 1);
    int flags = light->flags;
    if (((flags ^ 1) & 1) != 0)
        *(int *)flags &= ~0x20;
    else
        light->flags = flags & ~0x20;
}