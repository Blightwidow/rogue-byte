extern "C" int PleaseFindBest(int, int);
int FCanLease(int arg) {
    return PleaseFindBest(arg, 2) != 0;
}
