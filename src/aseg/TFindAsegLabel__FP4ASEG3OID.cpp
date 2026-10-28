struct ASEG; enum OID { OID_dummy };
extern "C" float *PeaFindAsegLabel(ASEG *, OID);
float TFindAsegLabel(ASEG *paseg, OID oid)
{
    float *pea = PeaFindAsegLabel(paseg, oid);
    if (pea)
        return *pea;
    return 0.0f;
}
