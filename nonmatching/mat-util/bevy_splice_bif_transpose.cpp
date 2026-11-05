extern "C" {
void bevy_splice_bif_transpose(int stride, int count, float *source, float *dest) {
    for (int row = 0; row < count; row++) {
        for (int column = 0; column < count; column++) {
            dest[row + column * stride] = source[row * stride + column];
        }
    }
}
}
