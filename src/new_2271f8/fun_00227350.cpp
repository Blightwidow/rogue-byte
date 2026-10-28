struct Xfm { char pad[0x110]; int value; };
extern "C" void InitXfm(Xfm *);
void func_00227350(Xfm *xfm)
{
    InitXfm(xfm);
    xfm->value = -1;
}
