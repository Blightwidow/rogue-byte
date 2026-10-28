struct XF { char pad[0x94]; int dof; };
struct ASEGCHN { unsigned grf; unsigned other; };
struct ASEG { char pad[0x5C]; int cchn; ASEGCHN *achn; };
struct ALOVT { short delta; short idx; };
struct ALO { char pad0[0xC]; char *vt; char pad1[0xC]; int oid; };
struct ALO2 { char pad0[0xC]; char **vt; };
struct VT { char pad[0x198]; short delta; short idx; XF *(*fn)(void *, int); };
struct ALOX { char pad0[0xC]; VT *vt; char pad1[8]; int oid; };

ASEGCHN *PchnFindAseg(ASEG *paseg, ALOX *palo, int dof, int fStripOnly)
{
    int ichn = 0;
    while (ichn < paseg->cchn) {
        ASEGCHN *pchn = &paseg->achn[ichn];
        if (fStripOnly == 0 || (pchn->grf & 0x40000000) != 0) {
            unsigned grf = pchn->grf;
            if (((int)(grf << 12) >> 12) == palo->oid && (grf & 0x80000000) == 0) {
                VT *vt = palo->vt;
                XF *pxf = vt->fn((char *)palo + vt->delta, (int)(grf << 2) >> 22);
                if (pxf->dof == dof)
                    return pchn;
            }
        }
        ichn++;
    }
    return 0;
}
