struct REC { char pad[0x40]; int id; REC *next; };
struct MGR { char pad[0xEC]; REC *first; };
extern "C" REC *func_001FCFA0(MGR *pmgr, int id)
{
    for (REC *rec = pmgr->first; rec != 0; rec = rec->next) {
        if (rec->id == id) return rec;
    }
    return 0;
}
