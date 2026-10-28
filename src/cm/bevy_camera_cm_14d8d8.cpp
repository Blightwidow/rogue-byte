struct Cam { char pad[0x300]; int count; float a; float b; };
extern "C" void bevy_camera_cm_14d8d8(Cam *self, float a, float b)
{
    int count = self->count;
    self->b = b;
    self->a = a;
    int m = 2;
    if (count > m)
        m = count;
    self->count = m;
}
