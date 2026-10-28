struct Owner {
    char pad0[0xE94];
    unsigned count;
    int items[8];
};
void func_0020A518(Owner *owner, int value)
{
    unsigned count = owner->count;
    if (count < 8) {
        owner->items[count] = value;
        owner->count = count + 1;
    }
}
