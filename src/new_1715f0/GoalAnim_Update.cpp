struct GOAL { char pad[0x30]; int state; char pad2[0xc]; int anim; };
extern "C" void func_001EEF98();
extern "C" int FDoneAnimref(int);
extern "C" void GoalAnim_SetState(GOAL *, int);
extern "C" void GoalAnim_Update(GOAL *goal)
{
    func_001EEF98();
    int state; do { state = goal->state; if (state == 0 && FDoneAnimref(goal->anim)) GoalAnim_SetState(goal, 1); } while (state != goal->state);
}
