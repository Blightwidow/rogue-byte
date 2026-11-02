extern "C" {
float fabsf(float);
void CroutDecomp__FiPfT1(int n, float *source, float *lu) {
    int k, row, column, term;
    float sum;
    if (n == 0) return;
    for (term = 0; term < n; term++) lu[term] = source[term];
    if (fabsf(lu[0]) < 1e-8f) {
        for (row = 0; row < n; row++) lu[row * n] = 0.0f;
    } else {
        for (row = 1; row < n; row++) lu[row * n] = source[row * n] / lu[0];
    }
    for (k = 1; k < n - 1; k++) {
        for (column = k; column < n; column++) {
            sum = 0.0f;
            for (term = 0; term < k; term++) sum += lu[term * n + column] * lu[k * n + term];
            lu[k * n + column] = source[k * n + column] - sum;
        }
        float *pivot = &lu[k * n + k];
        if (fabsf(*pivot) < 1e-8f) {
            for (row = k; row < n; row++) lu[row * n + k] = 0.0f;
        } else {
            for (row = k + 1; row < n; row++) {
                sum = 0.0f;
                for (term = 0; term < k; term++) sum += lu[term * n + k] * lu[row * n + term];
                lu[row * n + k] = (source[row * n + k] - sum) / *pivot;
            }
        }
    }
    sum = 0.0f;
    for (term = 0; term < n - 1; term++) sum += lu[term * n + n - 1] * lu[(n - 1) * n + term];
    float corner = source[(n - 1) * n + n - 1] - sum;
    lu[(n - 1) * n + n - 1] = corner;
    if (fabsf(corner) < 1e-8f) lu[(n - 1) * n + n - 1] = 0.0f;
}
}
