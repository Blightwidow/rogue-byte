struct VIFS;
extern char RO_0025A0C0[], RO_0025AF90[];
void EnsureVu1Code(VIFS *, void *, void *);
void EnsureBlipVu1Code(VIFS *pvifs)
{
    EnsureVu1Code(pvifs, RO_0025A0C0, RO_0025AF90);
}
