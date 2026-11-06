extern float D_002C44F0[];
void *memset(void *, int, int);
float *func_001A6B30(int unused, float *matrix) {
    if (matrix != 0) {
        memset(matrix, 0, 0x40);
        matrix[15] = 1.0f;
        matrix[10] = 1.0f;
        matrix[5] = 1.0f;
        matrix[0] = 1.0f;
    }
    return D_002C44F0;
}
