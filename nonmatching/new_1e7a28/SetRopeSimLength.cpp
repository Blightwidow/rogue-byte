typedef int QW __attribute__((mode(TI)));
struct Sim_1E95B0 { char pad[0xE8]; int count; char pad2[4]; float *lengths; QW *vectors; };
struct Rope_1E95B0 {
    char pad[0x48]; Sim_1E95B0 *sim; int cursor; char pad2[0x54 - 0x50]; QW *positions; QW *previous; float *times;
    char pad3[0x84 - 0x60]; int limit; float spacing;
};
extern "C" void InvalidateCrvCache(Sim_1E95B0 *);
extern float g_2c3678;
extern "C" void SetRopeSimLength(Rope_1E95B0 *rope, float length) {
    char sp[0x10] __attribute__((aligned(16)));
    Sim_1E95B0 *sim = rope->sim;
    int count = sim->count;
    float *times = rope->times;
    if (length < times[count - 1]) {
        int index = count - 1;
        while (index >= 0) {
            if (rope->times[index] < length) {
                break;
            }
            index -= 1;
        }
        index += 1;
        sim->count = index + 1;
        rope->times[index] = length;
    } else {
        int next = count;
        if (length < times[count - 2] + g_2c3678 * rope->spacing) {
            times[count - 1] = length;
        } else {
            for (;;) {
                if (next >= rope->limit) {
                    rope->cursor = 0;
                    break;
                }
                next += 1;
                float one = 1.0f;
                rope->positions[next - 1] = rope->positions[next - 2];
                rope->previous[next - 1] = rope->previous[next - 2];
                rope->times[next - 1] = length;
                rope->sim->vectors[next - 1] = rope->sim->vectors[next - 2];
                rope->sim->lengths[next - 1] = rope->sim->lengths[next - 2];
                rope->times[next - 2] = rope->times[next - 3] + rope->spacing;
                float *slot = rope->times + next;
                float base = slot[-3];
                QW *positionBase = rope->positions + next;
                float t = (slot[-2] - base) / (slot[-1] - base);
                float inverse = one - t;
                asm volatile("qmtc2.ni %0, vf4" : : "r"(t));
                asm volatile("qmtc2.ni %0, vf3" : : "r"(inverse));
                asm volatile("sqc2 vf3, (%0)" : : "r"(sp));
                asm volatile("lqc2 vf2, -0x30(%0)" : : "r"(positionBase));
                asm volatile("sqc2 vf4, (%0)" : : "r"(sp));
                asm volatile("lqc2 vf1, -0x10(%0)" : : "r"(positionBase));
                asm volatile("vmulax.xyzw ACC, vf2, vf3x");
                asm volatile("vmaddx.xyzw vf2, vf1, vf4x");
                asm volatile("sqc2 vf2, -0x20(%0)" : : "r"(positionBase));
                asm volatile("sqc2 vf3, (%0)" : : "r"(sp));
                QW *previousBase = rope->previous + next;
                asm volatile("lqc2 vf2, -0x30(%0)" : : "r"(previousBase));
                asm volatile("sqc2 vf4, (%0)" : : "r"(sp));
                asm volatile("lqc2 vf1, -0x10(%0)" : : "r"(previousBase));
                asm volatile("vmulax.xyzw ACC, vf2, vf3x");
                asm volatile("vmaddx.xyzw vf2, vf1, vf4x");
                asm volatile("sqc2 vf2, -0x20(%0)" : : "r"(previousBase));
                asm volatile("sqc2 vf3, (%0)" : : "r"(sp));
                QW *vectorBase = rope->sim->vectors + next;
                asm volatile("lqc2 vf2, -0x30(%0)" : : "r"(vectorBase));
                asm volatile("sqc2 vf4, (%0)" : : "r"(sp));
                asm volatile("lqc2 vf1, -0x10(%0)" : : "r"(vectorBase));
                asm volatile("vmulax.xyzw ACC, vf2, vf3x");
                asm volatile("vmaddx.xyzw vf3, vf1, vf4x");
                asm volatile("sqc2 vf3, -0x20(%0)" : : "r"(vectorBase));
                float *lengthBase = rope->sim->lengths + next;
                lengthBase[-2] = inverse * lengthBase[-3] + t * lengthBase[-1];
                float *timeBase = rope->times + next;
                if (length < timeBase[-2] + g_2c3678 * rope->spacing) {
                    timeBase[-1] = length;
                    break;
                }
            }
        }
        rope->sim->count = next;
    }
    InvalidateCrvCache(rope->sim);
}
