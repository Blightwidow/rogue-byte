struct ALLOCREQ_1DE518 { int cb; int cbAlign; };
struct LASER_1DE518 { char pad0[0x198]; int count; void *items; };
extern "C" void CSo_Clone(LASER_1DE518 *);
extern "C" void *PvAllocSwCopyImpl__FiPv(ALLOCREQ_1DE518 *, void *);
extern "C" void CloneLaser(LASER_1DE518 *laser)
{
    CSo_Clone(laser);
    void *src = laser->items;
    ALLOCREQ_1DE518 req;
    req.cb = laser->count * 0x150;
    req.cbAlign = 0x10;
    laser->items = PvAllocSwCopyImpl__FiPv(&req, src);
}
