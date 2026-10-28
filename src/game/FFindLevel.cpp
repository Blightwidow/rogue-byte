struct REC { char pad[0x50]; float dt; };
struct MGR;
extern "C" REC *func_001FCFA0(MGR *, int);
extern "C" float FFindLevel(MGR *pmgr, int id)
{
    REC *rec = func_001FCFA0(pmgr, id);
    if (rec == 0) return 0.0f;
    return rec->dt;
}
