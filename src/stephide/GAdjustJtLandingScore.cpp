struct Jt { char pad[0xBC]; int landing; };
extern float D_FLT_002BF900;
float GAdjustJtLandingScore(Jt *self, int landing, float score, float bonus)
{
    score = score + bonus;
    if (landing == self->landing)
        score = score + D_FLT_002BF900;
    return score;
}
