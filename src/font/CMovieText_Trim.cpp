extern "C" {
int CMovieText_ChNext(char *);
void CMovieText_Reset(char *, int);
void CMovieText_Trim(char *arg0, int arg1) {
    CMovieText_Reset(arg0, 0);
    while (CMovieText_ChNext(arg0) != 0) {
        if (arg1 == 0) {
            break;
        }
        arg1 -= 1;
    }
    **(char **)(arg0 + 4) = 0;
}
}
