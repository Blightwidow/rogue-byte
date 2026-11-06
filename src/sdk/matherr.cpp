extern "C" {
struct MathError {
    char pad0[8];
    long argument;
};
double dpcmp(long, long);
int matherr(MathError *error) {
    dpcmp(error->argument, error->argument);
    return 0;
}
}
