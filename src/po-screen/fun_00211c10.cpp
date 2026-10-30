extern "C" {
void AddDmaCnt__4DMAS();
void AddVifMscal__4VIFSPv(void *, void *);
void AddVifFlusha__4VIFS(void *);
void EndDmaCnt__4DMAS(void *);
extern char VU1_ENTRY_C0[];
void func_00211C10(void *vifs) {
    AddDmaCnt__4DMAS();
    AddVifMscal__4VIFSPv(vifs, VU1_ENTRY_C0);
    AddVifFlusha__4VIFS(vifs);
    EndDmaCnt__4DMAS(vifs);
}
}
