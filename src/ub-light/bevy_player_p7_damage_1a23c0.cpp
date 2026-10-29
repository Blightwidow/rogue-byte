int bevy_player_p7_damage_1a23c0(char *self)
{
    if (*(int *)(self + 4) != -1) {
        return **(int **)(self + 0x10) <= 0 ? 2 : 1;
    }
    return *(int *)(self + 0x90) == 1;
}
