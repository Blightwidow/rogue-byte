extern "C" void AddHubEntry(char *hub, int a, int b, int c)
{
    unsigned count = *(unsigned *)(hub + 0x18C);
    if (count < 12) {
        *(unsigned *)(hub + 0x18C) = count + 1;
        int *entry = (int *)(hub + (count * 12 + 0x190));
        entry[0] = a;
        entry[1] = b;
        entry[2] = c;
    }
}
