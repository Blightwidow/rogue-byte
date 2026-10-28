// 0x20AF28
void SetGuardAimOids(void* arg0, int a1, int a2, int a3)
{
    *(int*)((char*)arg0 + 0x7c) = a1;
    *(int*)((char*)arg0 + 0x80) = a2;
    *(int*)((char*)arg0 + 0x84) = a3;
}
