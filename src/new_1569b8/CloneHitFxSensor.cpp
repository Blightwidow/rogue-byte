struct Bytes8 { char bytes[8]; };
extern "C" {
void CloneXfm(char *);
void CloneHitFxSensor(char *self) {
    Bytes8 saved = *(Bytes8 *)(self + 0x104);
    CloneXfm(self);
    *(Bytes8 *)(self + 0x104) = saved;
}
}
