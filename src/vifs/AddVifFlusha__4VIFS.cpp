// 0x226D28 VIFS::AddVifFlusha
typedef struct { char pad[0xC]; int unk0xC; } VIFS;

extern "C" int AddVifFlusha__4VIFS(void* a0)
{
    int v1 = *(int*)((char*)a0 + 0xC);
    int v0 = v1 + 4;
    *(int*)((char*)a0 + 0xC) = v0;
    *(int*)v1 = 0x13000000;
    return v0;
}
