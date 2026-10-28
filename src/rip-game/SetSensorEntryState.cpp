struct Entry { int pad0; int state; float tState; float tFirst; };
struct VT { char pad[0x18]; short delta; short index; void (*fn)(void *, int, int, int, void *, int); };
struct Sensor { char pad[0xC]; VT *vptr; void *parent; };
struct Event { Entry *entry; int *pstate; int *pnew; };
struct CK { float t; };
extern "C" {
extern CK g_2dded0;
extern char B_002DEB30;
int FIsBasicDerivedFrom(void *, int);
void bevy_camera_follow_activity(char *, int, void *);
void SetSensorEntryState(Sensor *psensor, Entry *pentry, int nState)
{
    if (pentry == 0 || nState == pentry->state)
        return;
    if (pentry->state == 0)
        pentry->tFirst = g_2dded0.t;
    Event event;
    event.entry = pentry;
    event.pstate = &pentry->state;
    event.pnew = &nState;
    VT *vtable = psensor->vptr;
    vtable->fn((char *)psensor + vtable->delta, 0x1C, 0, 3, &event, 0);
    pentry->state = nState;
    pentry->tState = g_2dded0.t;
    if (nState == 1) {
        void *pvParent = psensor->parent;
        if (pvParent != 0 && FIsBasicDerivedFrom(pvParent, 0x33) != 0)
            bevy_camera_follow_activity(&B_002DEB30, 0x13, pvParent);
    }
}
}
