//static const u16 sTilesetPalOverride_General01_05[] = INCBIN_U16("data/tilesets/primary/general/override_palettes/01_05.gbapal");

//static const u16 sTilesetPalOverride_Petalburg06_08[] = INCBIN_U16("data/tilesets/secondary/petalburg/override_palettes/06_08.gbapal");

#define OVERRIDES_END { .slot = 0xFF, }

const struct PaletteOverride gTilesetPalOverrides_General[] =
{
    {
        .startHour = HOUR_NIGHT,
        .endHour = HOUR_MORNING,

    },
    {
        .startHour = HOUR_NIGHT,
        .endHour = HOUR_MORNING,

    },
    OVERRIDES_END
};

const struct PaletteOverride gTilesetPalOverrides_Petalburg[] =
{
    {
        .startHour = HOUR_NIGHT,
        .endHour = HOUR_MORNING,

    },
    {
        .startHour = HOUR_NIGHT,
        .endHour = HOUR_MORNING,

    },
    OVERRIDES_END
};
