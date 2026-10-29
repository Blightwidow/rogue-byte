// 0x1DBBA0 ShopMenu_IrowEnd
extern int g_crowShop_2C35B4;
extern int g_fShopArrowsTakeRow_3DA570;

int ShopMenu_IrowEnd(int pshop)
{
    int irowEnd = ((int *)(void *)pshop)[0x94] + g_crowShop_2C35B4;
    if (g_fShopArrowsTakeRow_3DA570 != 0) {
        irowEnd -= (0 < ((int *)(void *)pshop)[0x94]);
        irowEnd -= (irowEnd < ((int *)(void *)pshop)[0x12]);
    }
    return irowEnd;
}