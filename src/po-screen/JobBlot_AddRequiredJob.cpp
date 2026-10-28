struct JobEntry { int job; int unk0x4; };
struct Blot {
    char pad0[0x194];
    unsigned count;
    JobEntry jobs[16];
};
void JobBlot_AddRequiredJob(Blot *blot, int job)
{
    unsigned count = blot->count;
    if (count < 16) {
        blot->jobs[count].job = job;
        blot->count = count + 1;
    }
}
