typedef int s32;
s32 GoalFollowCrv_FBlocked(s32);
s32 GoalGoto_FBlocked(char *arg0)
{
    s32 var_v0 = 0;
    s32 temp_v1 = *(s32 *)(arg0 + 0x30);
    if (temp_v1 < 3) {
        if (temp_v1 > 0) {
            return GoalFollowCrv_FBlocked(*(s32 *)(arg0 + 0x18));
        }
        return var_v0;
    }
    return var_v0;
}
