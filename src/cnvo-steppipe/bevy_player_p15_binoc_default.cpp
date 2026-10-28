extern "C" void InitBinocHud(char *, char *);
void bevy_player_p15_binoc_default(char *self, int value)
{
    *(int *)self = value;
    *(int *)(self + 4) = -1;
    *(int *)(self + 0x20) = -1;
    InitBinocHud(self + 0x24, self);
}
