struct Job { char pad[0x18]; int id; };
struct World { char pad[0x3B0C]; Job *job; };
extern "C" int B_002DEB40;
extern "C" void SetSwCurrentJob(World *world, Job *job)
{
    world->job = job;
    if (job)
        B_002DEB40 = job->id;
    else
        B_002DEB40 = -1;
}
