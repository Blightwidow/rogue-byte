struct Dancer_1533B0 { char pad[0x150]; int pad150; };
struct Entry_1533B0 { Dancer_1533B0 *target; int f4; int f8; float fC; char pad10[0xC]; int f1C; int f20; };
struct Cell_1533B0 { float f0; char pad4[0x1C]; int f20; char pad24[0xC]; };
struct Rhythm_1533B0 {
    char pad0[0x58]; float f58; char pad5C[4]; int cellCount; char pad64[0xC]; Cell_1533B0 cells[1];
};
struct RhythmFull_1533B0 {
    char pad0[0x58]; float f58; char pad5C[4]; int cellCount; char pad64[0xC]; char cells[0x1C0 - 0x70];
    int entryCount; Entry_1533B0 entries[1]; char pad[0x230 - 0x1C4 - 0x24]; int f230;
    char pad234[0x298 - 0x234]; float f298; float f29C; float f2A0;
};
extern "C" {
void AddRhythmScore(void *, float);
int FFloatsNear__Ffff(float, float, float);
int FVjoyButtonPressed(int, Dancer_1533B0 *);
float GAccuracyRhythmCue(void *, void *);
int GrfbtnVjoyPressedWithin(int, int, float);
float MarkClockTickRealOnly__FP5CLOCK(void *);
void PlayDancerMove(Dancer_1533B0 *, int, int, int);
void bevy_camera_follow_activity(void *, int, void *);
float func_00153638(void *, float);
extern char B_002DEB30[];
extern char B_003DD040[];
void JudgeRhythmPress(RhythmFull_1533B0 *self, Dancer_1533B0 *dancer) {
    int pad = dancer->pad150;
    int pressed = GrfbtnVjoyPressedWithin(pad, 0xF0, 0.0f);
    self->f230 = pressed;
    if (pressed != 0) {
        int count = self->entryCount;
        int index = 0;
        if (count > 0) {
            Entry_1533B0 *entry = self->entries;
            do {
                index++;
                if (entry->target == dancer) {
                    if (entry->f20 == 0) {
                        bevy_camera_follow_activity(B_002DEB30, 0x35, self);
                        if (MarkClockTickRealOnly__FP5CLOCK(B_003DD040) < entry->fC - self->f58) {
                            PlayDancerMove(dancer, -1, -1, 1);
                            AddRhythmScore(self, self->f298);
                            return;
                        }
                        if (entry->f1C != 0) {
                            PlayDancerMove(dancer, -1, -1, 1);
                            AddRhythmScore(self, self->f2A0);
                            return;
                        }
                        entry->f1C = 1;
                        if (FVjoyButtonPressed(pad, dancer) != 0) {
                            int cellIndex = 0;
                            PlayDancerMove(dancer, entry->f4, entry->f8, 0);
                            Cell_1533B0 *cell = (Cell_1533B0 *)(self->cells);
                            AddRhythmScore(self, func_00153638(self, GAccuracyRhythmCue(self, entry)));
                            while (cellIndex < self->cellCount) {
                                if (FFloatsNear__Ffff(cell->f0, entry->fC, 0.1f) != 0) {
                                    cell->f20 = 1;
                                    break;
                                }
                                cell++;
                                cellIndex++;
                            }
                        } else {
                            PlayDancerMove(dancer, -1, -1, 1);
                            AddRhythmScore(self, self->f29C);
                        }
                        return;
                    }
                }
                entry++;
            } while (index < count);
        }
    }
}
}
