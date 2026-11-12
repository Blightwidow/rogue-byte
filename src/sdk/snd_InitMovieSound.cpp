typedef struct SndMovieParams {
    int a0;
    int a1;
    int a2;
    int a3;
    int t0;
} SndMovieParams;

extern "C" void func_002325E0(unsigned, unsigned, SndMovieParams *);

extern "C" void snd_InitMovieSound(int a0, int a1, int a2, int a3, int t0)
{
    SndMovieParams params;
    params.a0 = a0;
    params.a1 = a1;
    params.a2 = a2;
    params.a3 = a3;
    params.t0 = t0;
    func_002325E0(0x3E, 0x14, &params);
}
