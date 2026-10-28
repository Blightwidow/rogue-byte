extern "C" int GrfsgsFromSgs(int);
int FIsSgsInGrfsgs(int grfsgs, int sgs)
{
    int result = (grfsgs & GrfsgsFromSgs(sgs)) != 0;
    return result;
}
