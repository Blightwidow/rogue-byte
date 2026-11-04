typedef int QW __attribute__((mode(TI)));
typedef int (*GuardCallback)(char *, int);
extern "C" int bevy_player_p15_binoc_active(char *);
extern "C" QW PosLoWorld(char *);
extern "C" int PhitfxSpawn(int, QW, char *);
extern "C" int FIsGuardInSgs(char *, int);
extern "C" int FHitFxSensorReaches(char *, int);
extern "C" void HitFx_Remove(int);
extern "C" char *B_003E1444;
extern "C" char *B_003E1468;

int func_001409E8(char *self)
{
    if (bevy_player_p15_binoc_active(self) != 0)
        return 2;
    int spawned = 0;
    if (*(int *)(self + 0x10C4) != 0) {
        QW position = PosLoWorld(self);
        spawned = PhitfxSpawn(*(int *)(self + 0x10C4), position, self);
    }
    if (spawned == 0)
        return 2;
    int result = 0;
    char *node = B_003E1444;
    while (node != 0) {
        if (FIsGuardInSgs(node, 0x1D) != 0) {
            result = 2;
            break;
        }
        if (FIsGuardInSgs(node, 0xB) != 0) {
            result = 2;
            break;
        }
        char *typeInfo = *(char **)(node + 0xC);
        GuardCallback callback = *(GuardCallback *)(typeInfo + 0x2CC);
        if (callback(node + *(short *)(typeInfo + 0x2C8), spawned) != 0) {
            result = 1;
            break;
        }
        node = *(char **)(node + 0xFE0);
    }
    if (result == 0) {
        node = B_003E1468;
        while (node != 0) {
            if (FHitFxSensorReaches(node, spawned) != 0) {
                result = 1;
                break;
            }
            node = *(char **)(node + 0x104);
        }
    }
    HitFx_Remove(spawned);
    return result;
}
