typedef float f32;
struct SMPA_11D340;
extern "C" {
f32 GSmoothA__FffffP4SMPAPf(f32, f32, f32, f32, SMPA_11D340 *, f32 *);
f32 RadNormalize__Ff(f32);
void RadSmoothA__FffffP4SMPAPf(f32 radCurrent, f32 gVelocity, f32 radTarget, f32 dt, SMPA_11D340 *psmpa, f32 *pgVelocity) {
    RadNormalize__Ff(radCurrent + GSmoothA__FffffP4SMPAPf(0.0f, gVelocity, RadNormalize__Ff(radTarget - radCurrent), dt, psmpa, pgVelocity));
}
}
