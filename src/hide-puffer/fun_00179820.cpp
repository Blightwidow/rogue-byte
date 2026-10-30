struct Target_179820;
struct TargetVt_179820 { char pad[0x48]; short delta; short pad2; void (*fn)(char *); };
struct Target_179820 { char pad[0xC]; TargetVt_179820 *vt; };
struct Owner_179820 { char pad[0xFEC]; Target_179820 *target; };
struct Goal_179820 { char pad[0x10]; Owner_179820 *owner; };
extern "C" {
void GoalHit_Deactivate();
void func_00179820(Goal_179820 *self) {
    GoalHit_Deactivate();
    Target_179820 *target = self->owner->target;
    if (target != 0) {
        target->vt->fn((char *)target + target->vt->delta);
    }
}
}
