struct Group_182AB8 { int id; int a; int b; char pad0C[0x10]; int extra; float rate; char pad24[8]; float timer; };
struct Swarm_182AB8 { char pad[0x1C8]; unsigned count; Group_182AB8 groups[4]; };
extern "C" {
extern int D_002BE8AC;
void Swarm_AddGroup(Swarm_182AB8 *self, int arg1, int arg2, int arg3, float rate) {
    unsigned index = self->count;
    if (index < 4) {
        self->count = index + 1;
        Group_182AB8 *group = &self->groups[index];
        group->extra = D_002BE8AC;
        group->id = arg1;
        group->a = arg2;
        group->b = arg3;
        group->rate = rate;
        group->timer = -1.0f;
    }
}
}
