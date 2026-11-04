struct LM { float lo; float hi; };
float GLimitLm(LM *lm, float g)
{
    if (g < lm->lo)
        return lm->lo;
    if (lm->hi < g)
        return lm->hi;
    return g;
}
