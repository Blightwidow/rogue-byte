struct TARGET_151648;
struct VT_151648 { char pad[8]; short delta; short pad2; void (*fn)(char *); };
struct TARGET_151648 { char pad[0xC]; VT_151648 *vt; };
struct HOLDER_151648 { char pad[0x14]; TARGET_151648 *target; };
struct POLICY_151648 { char pad[0x10]; HOLDER_151648 *holder; };
extern "C" void ActivateCplcy(POLICY_151648 *, int, HOLDER_151648 *);
extern "C" void bevy_camera_policy_activate(POLICY_151648 *self, int unused, HOLDER_151648 *holder)
{
    ActivateCplcy(self, unused, holder);
    self->holder = holder;
    TARGET_151648 *target = holder->target;
    target->vt->fn((char *)target + target->vt->delta);
}
