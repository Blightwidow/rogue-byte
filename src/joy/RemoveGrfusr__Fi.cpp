extern int B_002DFBC4;
void UpdateGrfjoytFromGrfusr__Fv();
void RemoveGrfusr__Fi(int mask)
{
    B_002DFBC4 &= ~mask;
    UpdateGrfjoytFromGrfusr__Fv();
}
