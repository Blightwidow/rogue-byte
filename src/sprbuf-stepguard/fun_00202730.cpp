struct RECON { char pad[0xBC]; int sid; };
extern "C" char B_003DD490;
extern "C" const char *PchzStringFromId(void *, int);
extern "C" const char *func_00202730(RECON *precon)
{
    if (precon->sid == -1) return 0;
    return PchzStringFromId(&B_003DD490, precon->sid);
}
