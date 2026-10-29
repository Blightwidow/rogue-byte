typedef int s128 __attribute__((mode(TI)));
struct JtPipe { char pad[0x30]; s128 foot; s128 hand; };
extern "C" void SetJtPipeHandFoot(JtPipe *self, s128 foot, s128 hand)
{
    self->foot = foot;
    self->hand = hand;
}
