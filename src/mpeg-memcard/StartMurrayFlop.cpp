struct M { char pad[0x13E8]; int v; };
void SetMurrayState(M *, int);
void StartMurrayFlop(M *self) {
    self->v = 0;
    SetMurrayState(self, 3);
}
