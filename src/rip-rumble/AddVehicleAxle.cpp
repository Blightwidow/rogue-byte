struct Packed8 { char bytes[8]; };
struct Axle { int wheel; int pad[2]; Packed8 offset; };
struct Vehicle { char pad[0x4A4]; unsigned int axleCount; Axle axles[4]; };
extern "C" {
void AddVehicleAxle(Vehicle *vehicle, int arg1, Packed8 *arg2) {
    unsigned int count = vehicle->axleCount;
    if (count < 4) {
        vehicle->axleCount = count + 1;
        Axle *axle = &vehicle->axles[count];
        axle->wheel = arg1;
        axle->offset = *arg2;
    }
}
}
