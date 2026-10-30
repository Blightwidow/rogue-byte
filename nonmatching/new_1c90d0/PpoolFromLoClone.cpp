struct Item_1CB658 { int value; char pad[0x4C]; };
struct Clone_1CB658 { int id; char pad[0x20]; int active; };
struct Obj_1CB658 { char pad[0x3C]; Clone_1CB658 *clone; };
struct Set_1CB658 { char pad[0xC]; int first; char pad2[0x68 - 0x10]; Item_1CB658 *items; };
extern "C" int IcloneFromCloneId(int);
extern "C" int IsetFromCloneId(int);
extern Set_1CB658 *B_003E1398;
extern "C" int PpoolFromLoClone(Obj_1CB658 *self) {
    if (self->clone != 0 && self->clone->active != 0) {
        int set_index = IsetFromCloneId(self->clone->id);
        int clone_index = IcloneFromCloneId(self->clone->id);
        Set_1CB658 *set = &B_003E1398[set_index];
        return set->items[clone_index - set->first].value;
    }
    return 0;
}
