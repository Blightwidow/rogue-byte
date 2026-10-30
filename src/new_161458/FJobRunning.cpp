struct Job_162670 { char pad[0x50]; int busy; char pad2[0x9C]; int state; };
extern "C" {
int FSwLoadBusy(void *);
extern char B_003DD490;
int FJobRunning(Job_162670 *self) { if (self->busy == 0) { int s = self->state; if (s == 2) return 0; if (s == 3) return 0; return FSwLoadBusy(&B_003DD490) == 0; } return 0; }
}
