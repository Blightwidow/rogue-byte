extern "C" {
int GoalFollowCrv_FAtEnd(char *);
int GoalGotoPos_FArrived(char *self) {
    int result = 0;
    char *crv = *(char **)(self + 0x18);
    if (GoalFollowCrv_FAtEnd(crv) || *(int *)(crv + 0x4C) == 2) result = 1;
    return result;
}
}
