struct SO { char pad[0x300]; };
struct MATRIX3;
struct SMP;
void AccelSoTowardMatSmooth(SO *, float, MATRIX3 *, SMP *);
void AccelSlotSoRotation(SO *self, float deltaTime)
{
    AccelSoTowardMatSmooth(self, deltaTime, (MATRIX3 *)((char *)self + 0x1E0), (SMP *)((char *)self + 0x210));
}
