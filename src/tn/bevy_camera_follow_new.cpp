extern "C" {
void CPLCY_Destruct(char *);
extern float D_002C41A8[2];

void bevy_camera_follow_new(char *arg0) {
    CPLCY_Destruct(arg0);
    D_002C41A8[0] = -3.4028235e38f;
    D_002C41A8[1] = 3.4028235e38f;
    *(int *)(arg0 + 0x10) = 0;
    *(int *)(arg0 + 0x14) = 0;
}
}
