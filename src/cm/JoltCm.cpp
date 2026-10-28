extern float g_2dded0;

void JoltCm(int *pcm, int nJolt)
{
    *(float *)((char *)pcm + 0x618) = g_2dded0;
    *(int *)((char *)pcm + 0x61c) = nJolt;
}
