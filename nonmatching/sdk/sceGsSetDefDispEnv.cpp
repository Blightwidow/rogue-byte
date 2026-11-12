extern "C" {
struct DispEnv_240C38 {
    unsigned long pmode;
    unsigned long smode2;
    unsigned long dispfb;
    unsigned long display;
    unsigned long bgcolor;
};
struct Mode_240C38 {
    short field0;
    short mode;
    short field4;
};
Mode_240C38 *func_002405F0();
int checkModelVersion();
void _GetGsDxDyOffset(int, int *, int *, int *, int *);
void func_00236960(const char *, ...);
void sceGsSetDefDispEnv(DispEnv_240C38 *env, short psm, short width, short height, short dx, short dy) {
    int offset[4];
    Mode_240C38 *info = func_002405F0();
    if (!(info->mode == 2 || info->mode == 3) && checkModelVersion()) {
        _GetGsDxDyOffset(info->mode, &offset[0], &offset[1], &offset[2], &offset[3]);
    } else {
        offset[3] = 0;
        offset[2] = 0;
        offset[1] = 0;
        offset[0] = 0;
    }
    unsigned short modeValue = info->mode;
    unsigned short field0Value = info->field0;
    env->pmode = 0x66;
    if (info->field0 == 0) {
        env->smode2 = 2;
    } else if (info->field4 == 0) {
        env->smode2 = 1;
    } else {
        env->smode2 = 3;
    }
    env->dispfb = ((long)(psm & 0xF) << 15) | ((long)(((width + 0x3F) >> 6) & 0x3F) << 9);
    if ((short)modeValue == 2) {
        if ((short)field0Value == 1) {
            int magnify = (width + 0x9FF) / width;
            long positionX = ((long)offset[0] + 0x27C + dx * magnify) & 0xFFF;
            long positionY = (dy + offset[1] + 0x32) & 0xFFF;
            long rows = info->field4 != 0 ? height * 2 - 1 : height - 1;
            env->display = (((long)(magnify - 1) << 23) | ((long)(width * magnify - 1) << 32)) | (positionX | (rows << 44)) | (positionY << 12);
        } else {
            int magnify = (width + 0x9FF) / width;
            long positionX = ((long)offset[0] + 0x27C + dx * magnify) & 0xFFF;
            long positionY = (dy + offset[1] + 0x19) & 0xFFF;
            env->display = (((long)(magnify - 1) << 23) | ((long)(width * magnify - 1) << 32)) | (positionX | ((long)(height - 1) << 44)) | (positionY << 12);
        }
    } else if ((short)modeValue == 3) {
        if ((short)field0Value == 1) {
            int magnify = (width + 0x9FF) / width;
            long positionX = ((long)offset[0] + 0x290 + dx * magnify) & 0xFFF;
            long positionY = (dy + offset[1] + 0x48) & 0xFFF;
            long rows = info->field4 != 0 ? height * 2 - 1 : height - 1;
            env->display = (((long)(magnify - 1) << 23) | ((long)(width * magnify - 1) << 32)) | (positionX | (rows << 44)) | (positionY << 12);
        } else {
            int magnify = (width + 0x9FF) / width;
            long positionX = ((long)offset[0] + 0x290 + dx * magnify) & 0xFFF;
            long positionY = (dy + offset[1] + 0x24) & 0xFFF;
            env->display = (((long)(magnify - 1) << 23) | ((long)(width * magnify - 1) << 32)) | (positionX | ((long)(height - 1) << 44)) | (positionY << 12);
        }
    } else if ((short)modeValue == 0x50) {
        long positionX = ((long)offset[0] + (0x2D0 - width) / 2 * 2 + dx * 2 + 0xE8) & 0xFFF;
        long positionY = (dy + offset[1] + 0x23) & 0xFFF;
        env->display = ((long)(height - 1) << 44) | ((long)(width * 2 - 1) << 32) | (positionX | 0x800000) | (positionY << 12);
    } else {
        func_00236960("sceGsDefDispEnv:Not support displaymode for 0x%x!!\n", (short)modeValue);
    }
    env->bgcolor = 0;
}
}
