#define FIELD(type, offset) (*(type *)((char *)self + (offset)))
extern "C" {
struct Player_136338;
int FButtonPressedWithin(int, int, float);
int IsmsFindSmOptional__FP2SM3OID(int, int);
void SeekSma(int, int);
void SetBentleyAimState(Player_136338 *, int);
void ThrowBentleyBomb(Player_136338 *, int);
void UpdateLookRig(char *, int);
int bevy_player_p15_binoc_active(Player_136338 *);
extern float RO_002BC994;
extern float g_2dded0;
void UpdateBentleyAim(Player_136338 *self) {
    int state;
    do {
        state = FIELD(int, 0x16BC);
        if (state != -1) {
            if (state >= -1) if (state < 2) {
                if (bevy_player_p15_binoc_active(self) == 0) {
                    SetBentleyAimState(self, -1);
                } else {
                    if (FIELD(int, 0x16BC) == 1) {
                        if (RO_002BC994 < g_2dded0 - FIELD(float, 0x1700)) {
                            SetBentleyAimState(self, 0);
                        }
                    } else if (FButtonPressedWithin(FIELD(int, 0x150), 8, 0.25f) != 0) {
                        ThrowBentleyBomb(self, 0x80000);
                    }
                }
            }
        } else {
            if (bevy_player_p15_binoc_active(self) != 0 && FIELD(int, 0xF20) != 2) {
                if (RO_002BC994 < g_2dded0 - FIELD(float, 0x1700)) {
                    SetBentleyAimState(self, 0);
                } else {
                    SetBentleyAimState(self, 1);
                }
            }
            switch (FIELD(unsigned int, 0x13D0)) {
            case 0:
                UpdateLookRig((char *)self + 0x1710, 0);
                if (FIELD(int, 0x181C) != 0 && FIELD(int, 0x1714) != -1 && FIELD(int, 0x1034) != 0 &&
                    IsmsFindSmOptional__FP2SM3OID(FIELD(int, 0x1028), 0x17B) >= 0) {
                    SeekSma(FIELD(int, 0x1034), 0x17B);
                }
                break;
            case 1: case 2: case 3: case 7:
                UpdateLookRig((char *)self + 0x1710, 1);
                break;
            case 5:
                UpdateLookRig((char *)self + 0x1710, 2);
                break;
            default:
                UpdateLookRig((char *)self + 0x1710, -1);
                break;
            }
        }
    } while (state != FIELD(int, 0x16BC));
}
}
