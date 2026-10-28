struct PART {
    char pad0[0xC];
    int alo;
    char pad1[0xA0];
};
struct SO {
    char pad0[0xE0];
    int count;
    PART *parts;
};
extern "C" PART *PpartFindAlo(SO *so, int alo)
{
    for (int index = 0; index < so->count; index++) {
        if (so->parts[index].alo == alo)
            return &so->parts[index];
    }
    return 0;
}
