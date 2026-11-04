struct PINGPONG_1EDF28 { char pad[0x1C]; int half; char pad2[0x40]; float velocity; float position; float extra; };
extern "C" float UCompletePingpong__FP8PINGPONG(PINGPONG_1EDF28 *pingpong)
{
    float speed = pingpong->velocity;
    float distance;
    if (speed < 0.0f) {
        speed = -speed;
        distance = (float)(pingpong->half * 2) - pingpong->position;
    } else {
        distance = pingpong->position;
    }
    return (distance / speed) / ((float)(pingpong->half * 2) / speed + pingpong->extra);
}
