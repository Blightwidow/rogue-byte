struct CRef_154A90 { int type; int value; int pad[2]; };
struct Tune_154A90 { float f0; float f4; float f8; float fC; };
struct Diff_154A90 { char pad0[8]; void *path8; void *pathC; void *path10; Tune_154A90 *tune; };
struct Event_154A90 { char pad0[0x54]; int f54; char pad1[0x68 - 0x58]; int f68; char pad2[0x7C - 0x6C]; int f7C; char pad3[0xA8 - 0x80]; float *fA8; };
extern "C" {
void AddSuck(Diff_154A90 *, float);
void CRef_CopyConstruct(CRef_154A90 *, CRef_154A90 *);
void CRef_Destruct(CRef_154A90 *);
void *PsavepathNew(const char *, const char *, int);
void RefGetSaveValue(CRef_154A90 *, void *, void *, void *);
void RefSetGameSaveValue(CRef_154A90 *, void *, CRef_154A90 *, void *);
extern char B_003D4A60[];
extern char B_003E0EA8[];
extern int B_003E0F9C;
extern Tune_154A90 D_002BDC00;
void OnDifficultyEvent(Diff_154A90 *self, int message, Event_154A90 *event) {
    CRef_154A90 value;
    CRef_154A90 result;
    CRef_154A90 result2;
    CRef_154A90 level;
    CRef_154A90 copy;
    CRef_154A90 result3;
    switch (message) {
    case 3: {
        const char *group = "suck_history";
        self->tune = &D_002BDC00;
        self->path8 = PsavepathNew(group, "mission_0", 0);
        self->pathC = PsavepathNew(group, "mission_1", 0);
        self->path10 = PsavepathNew(group, "mission_2", 0);
    }
    default:
        break;
    case 34:
        RefGetSaveValue(&value, B_003E0EA8, self->pathC, B_003D4A60);
        RefSetGameSaveValue(&result, self->path8, &value, B_003D4A60);
        CRef_Destruct(&result);
        CRef_Destruct(&value);
        RefGetSaveValue(&value, B_003E0EA8, self->path10, B_003D4A60);
        RefSetGameSaveValue(&result2, self->pathC, &value, B_003D4A60);
        CRef_Destruct(&result2);
        CRef_Destruct(&value);
        {
            void *last = self->path10;
            level.type = 0x16;
            *(float *)&level.value = *event->fA8;
            CRef_CopyConstruct(&copy, &level);
            RefSetGameSaveValue(&result3, last, &copy, B_003D4A60);
            CRef_Destruct(&result3);
            CRef_Destruct(&copy);
            CRef_Destruct(&level);
        }
        break;
    case 37:
        if (B_003E0F9C == event->f7C) {
            if (event->f54 == 2) {
                if (event->f68 == 1) {
                    AddSuck(self, self->tune->fC);
                }
            }
        }
        break;
    case 16:
    case 29:
        AddSuck(self, self->tune->f8);
        break;
    }
}
}
