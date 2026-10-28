extern "C" int LootId(void* arg0)
{
    int* temp_v1 = *(int**)((char*)arg0 + 0x158);
    int var_v0 = -1;
    if (temp_v1 != 0) {
        var_v0 = *temp_v1;
    }
    return var_v0;
}