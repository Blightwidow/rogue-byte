extern "C" {
int JT_FPosing(void *arg0);

void JT_EndPose(char *arg0) {
    char *temp_v0;
    void (*temp_v1)(char *, int);

    if (JT_FPosing(arg0) != 0) {
        temp_v0 = *(char **)(arg0 + 0xC);
        temp_v1 = *(void (**)(char *, int))(temp_v0 + 0x2C4);
        temp_v1(arg0 + *(short *)(temp_v0 + 0x2C0), 0);
    }
}
}
