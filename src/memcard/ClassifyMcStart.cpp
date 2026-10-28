int ClassifyMcStart(int result)
{
    if (result == 0) return 0x1D; if (result > 0) return 0x1E; return 0x1F;
}
