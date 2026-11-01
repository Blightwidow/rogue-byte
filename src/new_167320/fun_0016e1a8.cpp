struct VIFS_16E1A8;
extern "C" {
extern char RO_0025E680[];
extern char RO_00262320[];
extern char VU1_START_0[];
void EnsureVu1Code__FP4VIFSPvT1(VIFS_16E1A8 *, void *, void *);
void AddDmaCnt__4DMAS(VIFS_16E1A8 *);
void UnpackHelper__4VIFS3UPKiiPiPPUi(VIFS_16E1A8 *, int, int, int, int *, unsigned **);
void *memset(void *, int, unsigned);
void AddVifMscal__4VIFSPv(VIFS_16E1A8 *, void *);
void EndDmaCnt__4DMAS(VIFS_16E1A8 *);
void func_0016E1A8(VIFS_16E1A8 *arg0) {
    unsigned *buffer;
    EnsureVu1Code__FP4VIFSPvT1(arg0, RO_0025E680, RO_00262320);
    AddDmaCnt__4DMAS(arg0);
    UnpackHelper__4VIFS3UPKiiPiPPUi(arg0, 0xD, 0xB, 0xA, 0, &buffer);
    memset(buffer, 0, 0x58);
    AddVifMscal__4VIFSPv(arg0, VU1_START_0);
    EndDmaCnt__4DMAS(arg0);
}
}
