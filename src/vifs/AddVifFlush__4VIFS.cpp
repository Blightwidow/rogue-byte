typedef struct { char pad[0xC]; int unk0xC; } VIFS;

extern "C" int AddVifFlush__4VIFS(void* a0)
{
    int v1 = *(int*)((char*)a0 + 0xC);
    int v0 = v1 + 4;
    *(int*)((char*)a0 + 0xC) = v0;
    *(int*)v1 = 0x11000000;
    return v0;
}
