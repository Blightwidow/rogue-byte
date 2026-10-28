struct Blot { char pad[0x7C]; int handle; };
extern "C" int FBlotObscured(Blot *);
int FDrawBlotMovie(Blot *blot)
{
    if (blot->handle == -1) return 0;
    return FBlotObscured(blot) == 0;
}
