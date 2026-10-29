extern "C" {
int McSync(int, int, int, int);
int sceMcWrite(int, int, int);

void McWrite(int arg0, int arg1, int arg2, int arg3, int arg4) {
    McSync(arg0 + 0xFD5C, sceMcWrite(arg1, arg2, arg3), 6, arg4);
}

}
