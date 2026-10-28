extern "C" void func_001F5078(void *);
struct Owner { int unk0x0; int unk0x4; int unk0x8; void *target; };
void func_00209790(Owner *owner)
{
    owner->unk0x0 = 0;
    char *target = (char *)owner->target;
    owner->unk0x4 = 0;
    int *tail = (int *)(target + 0x190);
    tail[2] = 0;
    tail[1] = 0;
    *(int *)(target + 0x190) = 0;
    func_001F5078(owner->target);
}
