extern "C" long GrfsgsFromSgs(int);
int FIsSgsInGrfsgs(long grfsgs, int sgs)
{
    int result = (grfsgs & GrfsgsFromSgs(sgs)) != 0;
    return result;
}
