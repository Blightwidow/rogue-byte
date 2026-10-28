extern "C" void* g_2dded0;
extern "C" void SetAlertState(void* palert, int nState);
void SetAlertState(void* palert, int nState)
{
    float tNow = *(float*)(unsigned int)&g_2dded0;
    *(int*)(unsigned int)((unsigned int)palert + 8u) = nState;
    *(float*)(unsigned int)((unsigned int)palert + 4u) = tNow;
}
