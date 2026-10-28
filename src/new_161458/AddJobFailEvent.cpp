struct Job { char pad[0x54]; int count; int *events; };
void AddJobFailEvent(Job *job, int event)
{
    int n = job->count;
    if (n < 0x20) {
        job->events[n] = event;
        job->count = n + 1;
    }
}
