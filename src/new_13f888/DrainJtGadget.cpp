extern "C" void DrainJtPower(float);
extern "C" const float RO_002BD260;
extern "C" const float RO_002BD264;

extern "C" void DrainJtGadget(int *unused, int *gadget)
{
    switch (*gadget) {
    case 29:
        DrainJtPower(RO_002BD260);
        return;
    case 42:
        DrainJtPower(RO_002BD264);
        break;
    }
}
