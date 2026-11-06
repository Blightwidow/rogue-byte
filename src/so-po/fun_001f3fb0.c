struct Source { char pad0[0x60]; int field60; };
void *memset(void *, int, int);
int func_001F3FB0(struct Source *source, float *matrix) {
    if (matrix != 0) {
        memset(matrix, 0, 0x40);
        matrix[15] = 1.0f;
        matrix[10] = 1.0f;
        matrix[5] = 1.0f;
        matrix[0] = 1.0f;
    }
    return source->field60;
}
