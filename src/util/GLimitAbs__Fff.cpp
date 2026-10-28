float GLimitAbs(float g, float limit)
{
    float result = g;
    if (limit < result) {
        result = limit;
    } else {
        limit = -limit;
        if (result < limit)
            result = limit;
    }
    return result;
}
