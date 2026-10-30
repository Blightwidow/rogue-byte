extern "C" {
struct Keys_12C708 { int pad0; int count; float *keys; };
int func_0012C708(Keys_12C708 *self, float value) {
    int index = 1;
    int limit = self->count - 1;
    while (index < limit) {
        if (value < self->keys[index]) break;
        index++;
    }
    return index;
}
}
