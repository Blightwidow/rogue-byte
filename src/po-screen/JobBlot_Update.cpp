struct Task211F90 { char pad[0x54]; int state; };
struct Slot211F90 { Task211F90 *task; int pad; };
struct VT211F90 { char pad[0x188]; short delta; short index; void (*fnSeek)(char *, int); short delta2; short index2; void (*fnDone)(char *); };
struct Blot211F90 {
    char pad0[0xC]; VT211F90 *vt;
    char pad10[0x100];
    int countB;
    char pad114[4];
    Slot211F90 slotsB[15];
    char pad190[4];
    int countA;
    char pad198[4];
    Slot211F90 slotsA[1];
};
extern "C" {
int FBlotLabelPlaying(void *, int);
int FTaskComplete(void *);
void UpdateBlotMovie(void *);
int sprintf(char *, const char *, ...);
extern char D_002C3EC0[];
extern const char RO_002A8AA0[];

void JobBlot_Update(Blot211F90 *blot) {
    int completeB = 0;
    int completeA = 0;
    int playing = 0;
    int index;
    UpdateBlotMovie(blot);
    for (index = 0; index < blot->countA; index++) {
        Task211F90 *task = blot->slotsA[index].task;
        if (task != 0) {
            if (task->state == 1) {
                playing++;
            } else if (FTaskComplete(task) != 0) {
                completeB++;
                completeA++;
            }
        }
    }
    for (index = 0; index < blot->countB; index++) {
        Task211F90 *task = blot->slotsB[index].task;
        if (task != 0) {
            if (task->state == 1) {
                playing++;
            } else if (FTaskComplete(task) != 0) {
                completeB++;
            }
        }
    }
    if (FBlotLabelPlaying(blot, 0x314) != 0) {
        sprintf(D_002C3EC0, RO_002A8AA0, completeA);
        sprintf(D_002C3EC0 + 0x30, RO_002A8AA0, blot->countA);
        sprintf(D_002C3EC0 + 0x60, RO_002A8AA0, blot->countA - completeA);
    }
    if (completeB == blot->countA + blot->countB || playing == 0) {
        blot->vt->fnDone((char *)blot + blot->vt->delta2);
        return;
    }
    if (playing > 0) {
        blot->vt->fnSeek((char *)blot + blot->vt->delta, -1);
    }
}
}
