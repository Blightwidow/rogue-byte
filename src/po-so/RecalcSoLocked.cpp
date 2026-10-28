struct SO;
struct SOX { char pad[0x60]; SO *owner; };
struct SOVT { char pad[0x1A8]; short delta; short index; SOX *(*alloc)(void *); };
struct SO {
    char pad0[0xC]; SOVT *vptr;
    char pad1[0x18]; unsigned long grfo;
    char pad2[0xEC - 0x30]; SOX *poxa;
};
extern "C" {
extern char B_003DD490;
SO *func_001F2798(SO *);
int CploFindSwObjectsByClass(void *, int, int, SO *, int, SO **);
void RemoveSoGeomsFromOxa(SO *);
void AddSoGeomsToOxa(SO *);
void RecalcSwOxfFilterForObject(void *, SO *);
void func_001F5078(SO *);
}
void RecalcSoLocked(SO *pso)
{
    if (((pso->grfo >> 60) & 1) == 0) return;
    SO *apso[64];
    if ((SOX *)func_001F2798(pso) != (SOX *)pso->poxa->owner) {
        int count = CploFindSwObjectsByClass(&B_003DD490, 1, 0x30, pso, 0x40, apso);
        for (int index = 0; index < count; index++) {
            SO *member = apso[index];
            if (member->poxa == 0) continue;
            SO *root = func_001F2798(member);
            if (root == member->poxa->owner) continue;
            RemoveSoGeomsFromOxa(member);
            if (root->poxa == 0) {
                root->poxa = root->vptr->alloc((char *)root + root->vptr->delta);
                RecalcSwOxfFilterForObject(&B_003DD490, root);
            }
            member->poxa = root->poxa;
            AddSoGeomsToOxa(member);
        }
    }
    RecalcSwOxfFilterForObject(&B_003DD490, pso);
    func_001F5078(pso);
}
