struct SM {
    char pad[0x40];
    unsigned flags;
};
extern "C" void InitLo(SM *);
extern "C" void InitSm(SM *sm)
{
    InitLo(sm);
    sm->flags |= 0x40;
}
