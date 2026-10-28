struct SAVE;
extern unsigned RO_002A38E8[];
extern char RO_002A6CA0[];
int load_file_from_disc(SAVE *save, const char *directory, const unsigned *record, const char *file);
int load_sly_icon_from_disc(SAVE *save, const char *directory)
{
    return load_file_from_disc(save, directory, RO_002A38E8, RO_002A6CA0);
}
