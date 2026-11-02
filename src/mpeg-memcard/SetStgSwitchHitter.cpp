struct UL { unsigned long v; } __attribute__((packed));
extern const UL RO_002A7630;
extern char B_003DD490[];
void QueueSwCallbackOnce(void *, void *, unsigned long, int);

void SetStgSwitchHitter(void *arg0, int arg1, int arg2)
{
    *(int *)((char *)arg0 + 0x170) = arg2;
    *(int *)((char *)arg0 + 0x16C) = arg1;
    QueueSwCallbackOnce(B_003DD490, arg0, RO_002A7630.v, 0);
}
