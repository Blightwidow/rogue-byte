// SPDX-License-Identifier: GPL-3.0-or-later
struct AmbVt1FC018 {
    char pad0[0x38];
    short deltaStop;
    short indexStop;
    void (*stop)(void *);
    short deltaQuery;
    short indexQuery;
    int (*query)(void *);
};
struct Amb1FC018 {
    char pad0[0xC];
    AmbVt1FC018 *vptr;
};
extern "C" void SetAmbGrf(Amb1FC018 *amb, int grf, int arg);
extern "C" void SetAmbSilent(Amb1FC018 *amb, int silent)
{
    if (silent == 0) {
        AmbVt1FC018 *vt = amb->vptr;
        vt->stop((char *)amb + vt->deltaStop);
        return;
    }
    int grf = 0x1FF;
    AmbVt1FC018 *vt = amb->vptr;
    int result = vt->query((char *)amb + vt->deltaQuery);
    if (result != 2)
        grf = 0x3FF;
    SetAmbGrf(amb, grf, 8);
}
