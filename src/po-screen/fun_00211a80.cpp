extern "C" {
void EnsureVu1Code__FP4VIFSPvT1(void *, void *, void *);
void AddDmaCnt__4DMAS(void *);
void AddVifFlush__4VIFS(void *);
void AddDmaCall__4DMASP2QW(void *, void *);
void AddVifBaseOffset__4VIFSii(void *, int, int);
void AddVifUnpack__4VIFS3UPKiPvi(void *, int, int, void *, int);
void AddVifMscal__4VIFSPv(void *, void *);
void AddVifFlusha__4VIFS(void *);
void AddVifDirect__4VIFSiP2QWi(void *, int, void *, int);
void EndDmaCnt__4DMAS(void *);
extern char RO_0025AFA0[], RO_0025B870[], B_002DF800[], B_004421A0[], B_004424B0[], B_004424D0[], B_004424F0[], B_00442520[], B_004425A0[], B_00442560[], B_00442240[], VU1_ENTRY_C0[], VU1_ENTRY_100[];
}
void func_00211A80(void *vifs)
{
    EnsureVu1Code__FP4VIFSPvT1(vifs, RO_0025AFA0, RO_0025B870);
    AddDmaCnt__4DMAS(vifs);
    AddVifFlush__4VIFS(vifs);
    AddDmaCall__4DMASP2QW(vifs, B_002DF800);
    AddVifBaseOffset__4VIFSii(vifs, 0, 0);
    AddVifUnpack__4VIFS3UPKiPvi(vifs, 0xC, 7, B_004421A0, 0xD);
    AddVifUnpack__4VIFS3UPKiPvi(vifs, 0xC, 2, B_004424B0, 0x15);
    AddVifUnpack__4VIFS3UPKiPvi(vifs, 0xC, 2, B_004424D0, 0x17);
    AddVifUnpack__4VIFS3UPKiPvi(vifs, 0xC, 3, B_004424F0, 0x19);
    AddVifUnpack__4VIFS3UPKiPvi(vifs, 0xC, 4, B_00442520, 0x1C);
    AddVifUnpack__4VIFS3UPKiPvi(vifs, 0xC, 3, B_004425A0, 0x20);
    AddVifUnpack__4VIFS3UPKiPvi(vifs, 0xC, 4, B_00442560, 0x23);
    AddVifBaseOffset__4VIFSii(vifs, 0x32, 0x1E7);
    AddVifMscal__4VIFSPv(vifs, VU1_ENTRY_C0);
    AddVifFlusha__4VIFS(vifs);
    AddVifDirect__4VIFSiP2QWi(vifs, 0x27, B_00442240, 0);
    AddVifFlusha__4VIFS(vifs);
    AddVifMscal__4VIFSPv(vifs, VU1_ENTRY_100);
    AddVifFlusha__4VIFS(vifs);
    EndDmaCnt__4DMAS(vifs);
}
