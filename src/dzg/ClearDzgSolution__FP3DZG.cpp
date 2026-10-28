struct DL { int a, b, c; };
struct DLE { int a, b; };
struct DZ { int pad0[3]; float sdv; float sf; int pad1[3]; DLE dle; };
struct DZG { int pad0; int cdz; DZ *adz; DL dlPos; DL dlZero; DL dlMax; DL dlUncat; int cdzPos; };
void ClearDl(DL *);
void ClearDle(DLE *);
void AppendDlEntry(DL *, DZ *);

void ClearDzgSolution(DZG *dzg)
{
    dzg->cdzPos = 0;
    ClearDl(&dzg->dlPos);
    ClearDl(&dzg->dlZero);
    ClearDl(&dzg->dlMax);
    ClearDl(&dzg->dlUncat);
    for (int index = 0; index < dzg->cdz; index++) {
        DZ *dz = &dzg->adz[index];
        dz->sdv = dz->sf = 0.0f;
        ClearDle(&dz->dle);
        AppendDlEntry(&dzg->dlUncat, dz);
    }
}
