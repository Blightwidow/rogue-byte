// Unaligned 8-byte store (ldl/ldr, sdl/sdr): a by-value struct of bytes.
struct Continuation { char bytes[8]; };
void SetZapContinuation(void *zap, Continuation continuation)
{
    *(Continuation *)((char *)zap + 0x1C) = continuation;
}
