extern "C" int scePadSetActDirect(int, int, char *);
extern "C" void StopRumbleActuators__FP6RUMBLE(int *rumble)
{
    char actuators[2];
    actuators[0] = 0;
    actuators[1] = 0;
    scePadSetActDirect(rumble[0], rumble[1], actuators);
}
