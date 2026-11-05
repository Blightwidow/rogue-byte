void ClearVjoyPresses(char *pvjoy, int grfjoy)
{
    if (grfjoy != 0) {
        float *pgValue = (float *)(pvjoy + 0x88);
        do {
            if (grfjoy & 1)
                *pgValue = -3.402823466e+38f;
            grfjoy >>= 1;
            pgValue++;
        } while (grfjoy != 0);
    }
}
