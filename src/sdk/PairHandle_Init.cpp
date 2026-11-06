extern "C" void PairHandle_Init(int **handle, int *pair) {
    if (pair != 0) {
        *pair += 1;
    }
    *handle = pair;
}
