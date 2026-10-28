struct Job { char pad[0x5C]; int count; int *events; };
void AddJobCompleteEvent(Job *job, int event)
{
    int n = job->count;
    if (n < 0x20) {
        job->events[n] = event;
        job->count = n + 1;
    }
}
