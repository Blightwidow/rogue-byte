struct Menu { char pad[0x24]; int v; };
extern "C" void Menu_ResetState(Menu *);
void Menu_Reset(Menu *self) {
    self->v = 0;
    Menu_ResetState(self);
}
