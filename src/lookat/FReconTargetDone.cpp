struct TARGET { char pad[0xEC]; void *ptask; int done; };
extern "C" int FTaskComplete(void *);
extern "C" int FReconTargetDone(TARGET *ptarget)
{
    if (ptarget->ptask != 0) return FTaskComplete(ptarget->ptask);
    return ptarget->done;
}
