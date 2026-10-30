struct Entry_132B10 { int pad0; int pad4; int limit; int pad0C; int pad10; };
struct Object_132B10;
struct Vtable_132B10 { short pad[0x18]; short offset; void *(*method)(void *, short); };
extern "C" Entry_132B10 D_002BAAE8[];
extern "C" int FIsBasicDerivedFrom(char *self, int index)
{
    char *vtable = *(char **)(self + 0xC);
    short offset = *(short *)(vtable + 0x30);
    char *info = (char *)(*(void *(**)(char *, short))(vtable + 0x34))(self + offset, offset);
    int result = 0;
    int value = *(int *)(info + 4);
    if (value >= index) {
        Entry_132B10 *entry = &D_002BAAE8[index];
        result = value < entry->limit;
    }
    return result;
}
