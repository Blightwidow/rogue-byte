struct BENTLEY_135FF0 { char pad[0x13D0]; int state; };
extern "C" int func_00135FF0(BENTLEY_135FF0 *pbentley)
{
    switch (pbentley->state) {
    case 0:
    case 1:
    case 5:
    case 7:
        return 1;
    }
    return 0;
}