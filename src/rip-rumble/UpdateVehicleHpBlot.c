struct Vehicle { char pad0[0x55C]; int maximum; int current; int inverted; int blot; };
int SeekBlotLabel(int, int, float);
void UpdateVehicleHpBlot(struct Vehicle *vehicle) {
    int blot = vehicle->blot;
    float fraction;
    if (blot != 0) {
        fraction = (float)vehicle->current / (float)vehicle->maximum;
        if (vehicle->inverted != 0) {
            fraction = 1.0f - fraction;
        }
        SeekBlotLabel(blot, 0x34F, fraction);
    }
}
