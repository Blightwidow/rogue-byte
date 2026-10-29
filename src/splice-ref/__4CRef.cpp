// Constructor-style helper: stores -1 at +0x4C and returns this.
void *__4CRef(void *arg0)
{
    int *ref = (int *)arg0;
    ref[0x4C / 4] = -1;
    return arg0;
}
