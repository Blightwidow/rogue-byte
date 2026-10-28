extern "C" void PentryAddBootQueue(void* p, int type);
void AddBootQueueCardCheck(void* pbootq)
{
    PentryAddBootQueue(pbootq, 5);
}