#include "constants/moves.h"

#if I_USE_EVO_HELD_ITEMS_FROM_BAG == TRUE
    #define EVO_HELD_ITEM_TYPE ITEM_USE_PARTY_MENU
    #define EVO_HELD_ITEM_FIELD_FUNC ItemUseOutOfBattle_EvolutionStone
#else
    #define EVO_HELD_ITEM_TYPE ITEM_USE_BAG_MENU
    #define EVO_HELD_ITEM_FIELD_FUNC ItemUseOutOfBattle_CannotUse
#endif

#if I_GEM_BOOST_POWER >= GEN_6
    #define GEM_BOOST_PARAM 30
#else
    #define GEM_BOOST_PARAM 50
#endif

#if I_TYPE_BOOST_POWER >= GEN_4 // For non Pokémon-specific type-boosting held items.
    #define TYPE_BOOST_PARAM 20
#else
    #define TYPE_BOOST_PARAM 10
#endif

#define X_ITEM_STAGES (B_X_ITEMS_BUFF >= GEN_7) ? 2 : 1

// Shared Item Description entries

static const u8 sFullHealDesc[]       = _("Cura todos los\n"
                                          "problemas de estado de\n"
                                          "un Pokémon.");

static const u8 sPokeDollDesc[]       = _("Usar para huir de\n"
                                          "cualquier batalla con\n"
                                          "un Pokémon salvaje.");

static const u8 sMaxReviveDesc[]      = _("Revive a un Pokémon\n"
                                          "debilitado con todo\n"
                                          "su HP.");

static const u8 sHealthFeatherDesc[]  = _("Un objeto que aumenta\n"
                                          "los PS base de\n"
                                          "un Pokémon.");

static const u8 sMuscleFeatherDesc[]  = _("Un objeto que aumenta\n"
                                          "el Ataque base de\n"
                                          "un Pokémon.");

static const u8 sResistFeatherDesc[]  = _("Un objeto que aumenta\n"
                                          "la Defensa base de\n"
                                          "un Pokémon.");

static const u8 sGeniusFeatherDesc[]  = _("Un objeto que aumenta\n"
                                          "el Ataque Especial\n"
                                          "base de un Pokémon.");

static const u8 sCleverFeatherDesc[]  = _("Un objeto que aumenta\n"
                                          "la Defensa Especial\n"
                                          "base de un Pokémon.");

static const u8 sSwiftFeatherDesc[]   = _("Un objeto que aumenta\n"
                                          "la Velocidad base de\n"
                                          "un Pokémon.");

static const u8 sBigMushroomDesc[]    = _("Un hongo raro que\n"
                                          "se vendería a un\n"
                                          "precio alto.");

static const u8 sShardsDesc[]         = _("Un fragmento de un\n"
                                          "objeto antiguo. Se\n"
                                          "puede vender a bajo precio.");

static const u8 sRootFossilDesc[]     = _("Un fósil de un\n"
                                          "Pokémon antiguo\n"
                                          "que vivía en el fondo del mar.");

static const u8 sFossilizedFishDesc[] = _("Un fósil de un\n"
                                          "Pokémon antiguo\n"
                                          "que vivía en el mar.");

static const u8 sBeadMailDesc[]       = _("Correo con un\n"
                                          "dibujo del Pokémon\n"
                                          "que lo sostiene.");

static const u8 sEvolutionStoneDesc[] = _("Hace evolucionar a\n"
                                          "ciertas especies de Pokémon.");

static const u8 sNectarDesc[]         = _("Néctar de flor que\n"
                                          "cambia la forma de\n"
                                          "ciertos Pokémon.");

static const u8 sCharizarditeDesc[]   = _("Esta piedra permite\n"
                                          "a Charizard Megaevolucionar en batalla.");

static const u8 sMewtwoniteDesc[]     = _("Esta piedra permite\n"
                                          "a Mewtwo Megaevolucionar en batalla.");

static const u8 sSeaIncenseDesc[]     = _("Un objeto que se lleva\n"
                                          "puesto y aumenta\n"
                                          "levemente el poder de los movimientos de tipo Agua.");

static const u8 sOddIncenseDesc[]     = _("Un objeto que se lleva\n"
                                          "puesto y aumenta el\n"
                                          "poder de los movimientos de tipo Psíquico.");

static const u8 sRockIncenseDesc[]    = _("Un objeto que se lleva\n"
                                          "puesto y aumenta el\n"
                                          "poder de los movimientos de tipo Roca.");

static const u8 sFullIncenseDesc[]    = _("Un objeto que se lleva\n"
                                          "puesto y hace que el\n"
                                          "portador se mueva más lentamente.");

static const u8 sRoseIncenseDesc[]    = _("Un objeto que se lleva\n"
                                          "puesto y aumenta el\n"
                                          "poder de los movimientos de tipo Planta.");

static const u8 sLuckIncenseDesc[]    = _("Duplica el dinero en\n"
                                          "batalla si el portador\n"
                                          "participa.");

static const u8 sPureIncenseDesc[]    = _("Un objeto que se lleva\n"
                                          "puesto y ayuda a\n"
                                          "rechazar a los Pokémon salvajes.");

static const u8 sKingsRockDesc[]      = _("Un objeto que se lleva\n"
                                          "puesto y puede hacer\n"
                                          "que el objetivo retroceda al ser alcanzado.");

static const u8 sFigyBerryDesc[]      = _("Un objeto que se lleva\n"
                                          "puesto y restaura PS,\n"
                                          "pero puede causar confusión.");

static const u8 sQuestionMarksDesc[]  = _("?????");

static const u8 sKeyToRoomDesc[]      = _("Una llave que abre una\n"
                                          "puerta dentro del\n"
                                          "Barco Abandonado.");

static const u8 sTeraShardDesc[]      = _("Estos fragmentos pueden\n"
                                          "formarse cuando un\n"
                                          "Pokémon Tera se desmaya.");

const struct Item gItems[] =
{
    [ITEM_NONE] =
    {
        .name = _("????????"),
        .price = 0,
        .description = sQuestionMarksDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Poké Balls

    [ITEM_POKE_BALL] =
    {
        .name = _("Poké Ball"),        // Nombre = "Poké Ball"
        .price = 200,                   // Precio = 200
        .description = COMPOUND_STRING("Herramienta para\n"
                                       "capturar Pokémon\n"
                                       "salvajes."), // Descripción = "Herramienta para\ncapturar Pokémon\nsalvajes."
        .pocket = POCKET_POKE_BALLS,   // Bolsillo = POCKET_POKE_BALLS
        .type = ITEM_USE_BAG_MENU,      // Tipo = ITEM_USE_BAG_MENU
        .battleUsage = EFFECT_ITEM_THROW_BALL,  // Uso en batalla = EFFECT_ITEM_THROW_BALL
        .secondaryId = ITEM_POKE_BALL - FIRST_BALL,  // ID secundaria = ITEM_POKE_BALL - FIRST_BALL
    },

[ITEM_GREAT_BALL] =
    {
        .name = _("Super Ball"),          // Nombre = "Super Ball"
        .price = 600,                     // Precio = 600
        .description = COMPOUND_STRING("Buena para atrapar\n"
                                       "Pokémon con mayor\n"
                                       "índice de captura."),  // Descripción = "Buena para atrapar\nPokémon con mayor\níndice de captura."
        .pocket = POCKET_POKE_BALLS,     // Bolsillo = POCKET_POKE_BALLS
        .type = ITEM_USE_BAG_MENU,        // Tipo = ITEM_USE_BAG_MENU
        .battleUsage = EFFECT_ITEM_THROW_BALL,  // Uso en batalla = EFFECT_ITEM_THROW_BALL
        .secondaryId = ITEM_GREAT_BALL - FIRST_BALL,  // ID secundaria = ITEM_GREAT_BALL - FIRST_BALL
    },

[ITEM_ULTRA_BALL] =
    {
        .name = _("Ultra Ball"),          // Nombre = "Ultra Ball"
        .price = 800,                     // Precio = 800
        .description = COMPOUND_STRING("Mejor para atrapar\n"
                                       "Pokémon con mayor\n"
                                       "índice de captura."),  // Descripción = "Mejor para atrapar\nPokémon con mayor\níndice de captura."
        .pocket = POCKET_POKE_BALLS,     // Bolsillo = POCKET_POKE_BALLS
        .type = ITEM_USE_BAG_MENU,        // Tipo = ITEM_USE_BAG_MENU
        .battleUsage = EFFECT_ITEM_THROW_BALL,  // Uso en batalla = EFFECT_ITEM_THROW_BALL
        .secondaryId = ITEM_ULTRA_BALL - FIRST_BALL,  // ID secundaria = ITEM_ULTRA_BALL - FIRST_BALL
    },

[ITEM_MASTER_BALL] =
    {
        .name = _("Master Ball"),         // Nombre = "Master Ball"
        .price = 0,                       // Precio = 0
        .description = COMPOUND_STRING("La mejor para\n"
                                       "atrapar Pokémon\n"
                                       "sin fallar."),  // Descripción = "La mejor para\natrapar Pokémon\nsin fallar."
        .pocket = POCKET_POKE_BALLS,     // Bolsillo = POCKET_POKE_BALLS
        .type = ITEM_USE_BAG_MENU,        // Tipo = ITEM_USE_BAG_MENU
        .battleUsage = EFFECT_ITEM_THROW_BALL,  // Uso en batalla = EFFECT_ITEM_THROW_BALL
        .secondaryId = ITEM_MASTER_BALL - FIRST_BALL,  // ID secundaria = ITEM_MASTER_BALL - FIRST_BALL
    },

[ITEM_PREMIER_BALL] =
    {
        .name = _("Honor Ball"),          // Nombre = "Honor Ball"
        .price = 20,                      // Precio = 20
        .description = COMPOUND_STRING("Rara, creada en\n"
                                       "conmemoración de\n"
                                       "algún evento."),  // Descripción = "Rara, creada en\nconmemoración de\nalgún evento."
        .pocket = POCKET_POKE_BALLS,     // Bolsillo = POCKET_POKE_BALLS
        .type = ITEM_USE_BAG_MENU,        // Tipo = ITEM_USE_BAG_MENU
        .battleUsage = EFFECT_ITEM_THROW_BALL,  // Uso en batalla = EFFECT_ITEM_THROW_BALL
        .secondaryId = ITEM_PREMIER_BALL - FIRST_BALL,  // ID secundaria = ITEM_PREMIER_BALL - FIRST_BALL
    },

[ITEM_HEAL_BALL] =
    {
        .name = _("Sana Ball"),           // Nombre = "Sana Ball"
        .price = 300,                     // Precio = 300
        .description = COMPOUND_STRING("Restaura Pokémon\n"
                                       "capturados."),  // Descripción = "Restaura Pokémon\ncapturados."
        .pocket = POCKET_POKE_BALLS,     // Bolsillo = POCKET_POKE_BALLS
        .type = ITEM_USE_BAG_MENU,        // Tipo = ITEM_USE_BAG_MENU
        .battleUsage = EFFECT_ITEM_THROW_BALL,  // Uso en batalla = EFFECT_ITEM_THROW_BALL
        .secondaryId = ITEM_HEAL_BALL - FIRST_BALL,  // ID secundaria = ITEM_HEAL_BALL - FIRST_BALL
    },

[ITEM_NET_BALL] =
    {
        .name = _("Malla Ball"),          // Nombre = "Malla Ball"
        .price = 1000,                    // Precio = 1000
        .description = COMPOUND_STRING("Funciona bien con\n"
                                       "Pokémon de tipo\n"
                                       "Agua e Insecto."),  // Descripción = "Funciona bien con\nPokémon de tipo\nAgua e Insecto."
        .pocket = POCKET_POKE_BALLS,     // Bolsillo = POCKET_POKE_BALLS
        .type = ITEM_USE_BAG_MENU,        // Tipo = ITEM_USE_BAG_MENU
        .battleUsage = EFFECT_ITEM_THROW_BALL,  // Uso en batalla = EFFECT_ITEM_THROW_BALL
        .secondaryId = ITEM_NET_BALL - FIRST_BALL,  // ID secundaria = ITEM_NET_BALL - FIRST_BALL
    },

[ITEM_NEST_BALL] =
    {
        .name = _("Nido Ball"),           // Nombre = "Nido Ball"
        .price = 1000,                    // Precio = 1000
        .description = COMPOUND_STRING("Mejor para atrapar\n"
                                       "Pokémon más débiles."),  // Descripción = "Mejor para atrapar\nPokémon más débiles."
        .pocket = POCKET_POKE_BALLS,     // Bolsillo = POCKET_POKE_BALLS
        .type = ITEM_USE_BAG_MENU,        // Tipo = ITEM_USE_BAG_MENU
        .battleUsage = EFFECT_ITEM_THROW_BALL,  // Uso en batalla = EFFECT_ITEM_THROW_BALL
        .secondaryId = ITEM_NEST_BALL - FIRST_BALL,  // ID secundaria = ITEM_NEST_BALL - FIRST_BALL
    },

[ITEM_DIVE_BALL] =
    {
        .name = _("Buceo Ball"),          // Nombre = "Buceo Ball"
        .price = 1000,                    // Precio = 1000
        .description = COMPOUND_STRING("Mejor para atrapar\n"
                                       "Pokémon del fondo\n"
                                       "del océano."),  // Descripción = "Mejor para atrapar\nPokémon del fondo\ndel océano."
        .pocket = POCKET_POKE_BALLS,     // Bolsillo = POCKET_POKE_BALLS
        .type

 = ITEM_USE_BAG_MENU,        // Tipo = ITEM_USE_BAG_MENU
        .battleUsage = EFFECT_ITEM_THROW_BALL,  // Uso en batalla = EFFECT_ITEM_THROW_BALL
        .secondaryId = ITEM_DIVE_BALL - FIRST_BALL,  // ID secundaria = ITEM_DIVE_BALL - FIRST_BALL
    },

[ITEM_DUSK_BALL] =
    {
        .name = _("Ocaso Ball"),          // Nombre = "Ocaso Ball"
        .price = 1000,                    // Precio = 1000
        .description = COMPOUND_STRING("Funciona bien en\n"
                                       "lugares oscuros."),  // Descripción = "Funciona bien en\nlugares oscuros."
        .pocket = POCKET_POKE_BALLS,     // Bolsillo = POCKET_POKE_BALLS
        .type = ITEM_USE_BAG_MENU,        // Tipo = ITEM_USE_BAG_MENU
        .battleUsage = EFFECT_ITEM_THROW_BALL,  // Uso en batalla = EFFECT_ITEM_THROW_BALL
        .secondaryId = ITEM_DUSK_BALL - FIRST_BALL,  // ID secundaria = ITEM_DUSK_BALL - FIRST_BALL
    },

[ITEM_TIMER_BALL] =
    {
        .name = _("Turno Ball"),          // Nombre = "Turno Ball"
        .price = 1000,                    // Precio = 1000
        .description = COMPOUND_STRING("Gana poder después\nde muchos turnos en\nbatalla."),  // Descripción = "Gana poder después\nde muchos turnos en\nbatalla."
        .pocket = POCKET_POKE_BALLS,     // Bolsillo = POCKET_POKE_BALLS
        .type = ITEM_USE_BAG_MENU,        // Tipo = ITEM_USE_BAG_MENU
        .battleUsage = EFFECT_ITEM_THROW_BALL,  // Uso en batalla = EFFECT_ITEM_THROW_BALL
        .secondaryId = ITEM_TIMER_BALL - FIRST_BALL,  // ID secundaria = ITEM_TIMER_BALL - FIRST_BALL
    },

[ITEM_QUICK_BALL] =
    {
        .name = _("Veloz Ball"),          // Nombre = "Veloz Ball"
        .price = 1000,                    // Precio = 1000
        .description = COMPOUND_STRING("Funciona bien en el\n"
                                       "primer turno de\nbatalla."),  // Descripción = "Funciona bien en el\nprimer turno de\nbatalla."
        .pocket = POCKET_POKE_BALLS,     // Bolsillo = POCKET_POKE_BALLS
        .type = ITEM_USE_BAG_MENU,        // Tipo = ITEM_USE_BAG_MENU
        .battleUsage = EFFECT_ITEM_THROW_BALL,  // Uso en batalla = EFFECT_ITEM_THROW_BALL
        .secondaryId = ITEM_QUICK_BALL - FIRST_BALL,  // ID secundaria = ITEM_QUICK_BALL - FIRST_BALL
    },

[ITEM_REPEAT_BALL] =
    {
        .name = _("Acopio Ball"),         // Nombre = "Acopio Ball"
        .price = 1000,                    // Precio = 1000
        .description = COMPOUND_STRING("Mejor para atrapar\n"
                                       "Pokémon ya capturados."),  // Descripción = "Mejor para atrapar\nPokémon ya capturados."
        .pocket = POCKET_POKE_BALLS,     // Bolsillo = POCKET_POKE_BALLS
        .type = ITEM_USE_BAG_MENU,        // Tipo = ITEM_USE_BAG_MENU
        .battleUsage = EFFECT_ITEM_THROW_BALL,  // Uso en batalla = EFFECT_ITEM_THROW_BALL
        .secondaryId = ITEM_REPEAT_BALL - FIRST_BALL,  // ID secundaria = ITEM_REPEAT_BALL - FIRST_BALL
    },

[ITEM_LUXURY_BALL] =
    {
        .name = _("Lujo Ball"),           // Nombre = "Lujo Ball"
        .price = 1000,                    // Precio = 1000
        .description = COMPOUND_STRING("Cómoda para Pokémon\n"
                                       "haciéndolos más\n"
                                       "amigables."),  // Descripción = "Cómoda para Pokémon\nhaciéndolos más\namigables."
        .pocket = POCKET_POKE_BALLS,     // Bolsillo = POCKET_POKE_BALLS
        .type = ITEM_USE_BAG_MENU,        // Tipo = ITEM_USE_BAG_MENU
        .battleUsage = EFFECT_ITEM_THROW_BALL,  // Uso en batalla = EFFECT_ITEM_THROW_BALL
        .secondaryId = ITEM_LUXURY_BALL - FIRST_BALL,  // ID secundaria = ITEM_LUXURY_BALL - FIRST_BALL
    },

[ITEM_LEVEL_BALL] =
    {
        .name = _("Nivel Ball"),          // Nombre = "Nivel Ball"
        .price = 0,                       // Precio = 0
        .description = COMPOUND_STRING("Funciona bien con\n"
                                       "Pokémon de nivel\n"
                                       "bajo."),  // Descripción = "Funciona bien con\nPokémon de nivel\nbajo."
        .pocket = POCKET_POKE_BALLS,     // Bolsillo = POCKET_POKE_BALLS
        .type = ITEM_USE_BAG_MENU,        // Tipo = ITEM_USE_BAG_MENU
        .battleUsage = EFFECT_ITEM_THROW_BALL,  // Uso en batalla = EFFECT_ITEM_THROW_BALL
        .secondaryId = ITEM_LEVEL_BALL - FIRST_BALL,  // ID secundaria = ITEM_LEVEL_BALL - FIRST_BALL
    },

[ITEM_LURE_BALL] =
    {
        .name = _("Cebo Ball"),           // Nombre = "Cebo Ball"
        .price = 0,                       // Precio = 0
        .description = COMPOUND_STRING("Funciona bien con\n"
                                       "Pokémon pescados."),  // Descripción = "Funciona bien con\nPokémon pescados."
        .pocket = POCKET_POKE_BALLS,     // Bolsillo = POCKET_POKE_BALLS
        .type = ITEM_USE_BAG_MENU,        // Tipo = ITEM_USE_BAG_MENU
        .battleUsage = EFFECT_ITEM_THROW_BALL,  // Uso en batalla = EFFECT_ITEM_THROW_BALL
        .secondaryId = ITEM_LURE_BALL - FIRST_BALL,  // ID secundaria = ITEM_LURE_BALL - FIRST_BALL
    },

[ITEM_MOON_BALL] =
    {
        .name = _("Luna Ball"),           // Nombre = "Luna Ball"
        .price = 0,                       // Precio = 0
        .description = COMPOUND_STRING("Funciona bien con\n"
                                       "Pokémon que evolucionan\n"
                                       "con Piedra Lunar."),  // Descripción = "Funciona bien con\nPokémon que evolucionan\ncon Piedra Lunar."
        .pocket = POCKET_POKE_BALLS,     // Bolsillo = POCKET_POKE_BALLS
        .type = ITEM_USE_BAG_MENU,        // Tipo = ITEM_USE_BAG_MENU
        .battleUsage = EFFECT_ITEM_THROW_BALL,  // Uso en batalla = EFFECT_ITEM_THROW_BALL
        .secondaryId = ITEM_MOON_BALL - FIRST_BALL,  // ID secundaria = ITEM_MOON_BALL - FIRST_BALL
    },

[ITEM_FRIEND_BALL] =
    {
        .name = _("Amigo Ball"),          // Nombre = "Amigo Ball"
        .price = 0,                       // Precio = 0
        .description = COMPOUND_STRING("Hace que un Pokémon\n"
                                       "capturado sea más\n"
                                       "amistoso."),  // Descripción = "Hace que un Pokémon\ncapturado sea más\namistoso."
        .pocket = POCKET_POKE_BALLS,     // Bolsillo = POCKET_POKE_BALLS
        .type = ITEM_USE_BAG_MENU,        // Tipo = ITEM_USE_BAG_MENU
        .battleUsage = EFFECT_ITEM_THROW_BALL,  // Uso en batalla = EFFECT_ITEM_THROW_BALL
        .secondaryId = ITEM_FRIEND_BALL - FIRST_BALL,  // ID secundaria = ITEM_FRIEND_BALL - FIRST_BALL
    },

[ITEM_LOVE_BALL] =
    {
        .name = _("Amor Ball"),           // Nombre = "Amor Ball"
        .price = 0,                       // Precio = 0
        .description = COMPOUND_STRING("Funciona bien con\n"
                                       "Pokémon del género\n"
                                       "opuesto."),  // Descripción = "Funciona bien con\nPokémon del género\nopuesto."
        .pocket = POCKET_POKE_BALLS,     // Bolsillo = POCKET_POKE_BALLS
        .type = ITEM_USE_BAG_MENU,        // Tipo = ITEM_USE_BAG_MENU
        .battleUsage = EFFECT_ITEM_THROW_BALL,  // Uso en batalla = EFFECT_ITEM_THROW_BALL
        .secondaryId = ITEM_LOVE_BALL - FIRST_BALL,  // ID secundaria = ITEM_LOVE_BALL - FIRST_BALL
    },

[ITEM_FAST_BALL] =
    {
        .name = _("Rapid Ball"),          // Nombre = "Rapid Ball"
        .price = 0,                       // Precio = 0
        .description = COMPOUND_STRING("Funciona bien con\n"
                                       "Pokémon muy rápidos."),  // Descripción = "Funciona bien con\nPokémon muy rápidos."
        .pocket = POCKET_POKE_BALLS,     // Bolsillo = POCKET_POKE_BALLS
        .type = ITEM_USE_BAG_MENU,        // Tipo = ITEM_USE_BAG_MENU
        .battleUsage = EFFECT_ITEM_THROW_BALL,  // Uso en batalla = EFFECT_ITEM_THROW_BALL
        .secondaryId = ITEM_FAST_BALL - FIRST_BALL,  // ID secundaria = ITEM_FAST_BALL - FIRST_BALL
    },

[ITEM_HEAVY_BALL] =
    {
        .name = _("Peso Ball"),           // Nombre = "Peso Ball"
        .price = 0,                       // Precio = 0
        .description = COMPOUND_STRING("Funciona bien con\n"
                                       "Pokémon muy pesados."),  // Descripción = "Funciona bien con\nPokémon muy pesados."
        .pocket = POCKET_POKE_BALLS,     // Bolsillo = POCKET_POKE_BALLS
        .type = ITEM_USE_BAG_MENU,        // Tipo = ITEM_USE_BAG_MENU
        .battleUsage = EFFECT_ITEM_THROW_BALL,  // Uso en bat
        .secondaryId = ITEM_HEAVY_BALL - FIRST_BALL,  // ID secundaria = ITEM_HEAVY_BALL - FIRST_BALL
    },

[ITEM_DREAM_BALL] =
    {
        .name = _("Ensueño Ball"),        // Nombre = "Ensueño Ball"
        .price = 0,                       // Precio = 0
        #if B_DREAM_BALL_MODIFIER >= GEN_8
            .description = COMPOUND_STRING("Funciona bien con\n"
                                           "Pokémon dormidos."),  // Descripción = "Funciona bien con\nPokémon dormidos."
        #else
            .description = COMPOUND_STRING("Una Poké Ball usada en\n"
                                           "el Bosque de Entrada."),  // Descripción = "Una Poké Ball usada en\nel Bosque de Entrada."
        #endif
        .pocket = POCKET_POKE_BALLS,     // Bolsillo = POCKET_POKE_BALLS
        .type = ITEM_USE_BAG_MENU,        // Tipo = ITEM_USE_BAG_MENU
        .battleUsage = EFFECT_ITEM_THROW_BALL,  // Uso en batalla = EFFECT_ITEM_THROW_BALL
        .secondaryId = ITEM_DREAM_BALL - FIRST_BALL,  // ID secundaria = ITEM_DREAM_BALL - FIRST_BALL
    },

[ITEM_SAFARI_BALL] =
    {
        .name = _("Safari Ball"),         // Nombre = "Safari Ball"
        .price = 0,                       // Precio = 0
        .description = COMPOUND_STRING("Una Ball especial\n"
                                       "usada solo en la\n"
                                       "Zona Safari."),  // Descripción = "Una Ball especial\nusada solo en la\nZona Safari."
        .pocket = POCKET_POKE_BALLS,     // Bolsillo = POCKET_POKE_BALLS
        .type = ITEM_USE_BAG_MENU,        // Tipo = ITEM_USE_BAG_MENU
        .battleUsage = EFFECT_ITEM_THROW_BALL,  // Uso en batalla = EFFECT_ITEM_THROW_BALL
        .secondaryId = ITEM_SAFARI_BALL - FIRST_BALL,  // ID secundaria = ITEM_SAFARI_BALL - FIRST_BALL
    },

[ITEM_SPORT_BALL] =
    {
        .name = _("Competi Ball"),        // Nombre = "Competi Ball"
        .price = 0,                       // Precio = 0
        .description = COMPOUND_STRING("Una Ball especial usada\n"
                                       "en el Concurso de Captura\n"
                                       "de Insectos."),  // Descripción = "Una Ball especial usada\nen el Concurso de Captura\n
        .pocket = POCKET_POKE_BALLS,     // Bolsillo = POCKET_POKE_BALLS
        .type = ITEM_USE_BAG_MENU,        // Tipo = ITEM_USE_BAG_MENU
        .battleUsage = EFFECT_ITEM_THROW_BALL,  // Uso en batalla = EFFECT_ITEM_THROW_BALL
        .secondaryId = ITEM_SPORT_BALL - FIRST_BALL,  // ID secundaria = ITEM_SPORT_BALL - FIRST_BALL
    },

[ITEM_PARK_BALL] =
    {
        .name = _("Parque Ball"),         // Nombre = "Parque Ball"
        .price = 0,                       // Precio = 0
        .description = COMPOUND_STRING("Una Ball especial para\n"
                                       "el Parque Amistad."),  // Descripción = "Una Ball especial para\nel Parque Amistad."
        .pocket = POCKET_POKE_BALLS,     // Bolsillo = POCKET_POKE_BALLS
        .type = ITEM_USE_BAG_MENU,        // Tipo = ITEM_USE_BAG_MENU
        .battleUsage = EFFECT_ITEM_THROW_BALL,  // Uso en batalla = EFFECT_ITEM_THROW_BALL
        .secondaryId = ITEM_PARK_BALL - FIRST_BALL,  // ID secundaria = ITEM_PARK_BALL - FIRST_BALL
    },

[ITEM_BEAST_BALL] =
    {
        .name = _("Ente Ball"),           // Nombre = "Ente Ball"
        .price = 0,                       // Precio = 0
        .description = COMPOUND_STRING("Una Ball diseñada para\n"
                                       "capturar Ultraentes."),  // Descripción = "Una Ball diseñada para\ncapturar Ultraentes."
        .pocket = POCKET_POKE_BALLS,     // Bolsillo = POCKET_POKE_BALLS
        .type = ITEM_USE_BAG_MENU,        // Tipo = ITEM_USE_BAG_MENU
        .battleUsage = EFFECT_ITEM_THROW_BALL,  // Uso en batalla = EFFECT_ITEM_THROW_BALL
        .secondaryId = ITEM_BEAST_BALL - FIRST_BALL,  // ID secundaria = ITEM_BEAST_BALL - FIRST_BALL
    },

[ITEM_CHERISH_BALL] =
    {
        .name = _("Gloria Ball"),         // Nombre = "Gloria Ball"
        .price = 0,                       // Precio = 0
        .description = COMPOUND_STRING("Una rara Ball hecha en\n"
                                       "conmemoración de algún\n"
                                       "evento especial."),  // Descripción = "Una rara Ball hecha en\nconmemoración de algún\nevento especial."
        .pocket = POCKET_POKE_BALLS,     // Bolsillo = POCKET_POKE_BALLS
        .type = ITEM_USE_BAG_MENU,        // Tipo = ITEM_USE_BAG_MENU
        .battleUsage = EFFECT_ITEM_THROW_BALL,  // Uso en batalla = EFFECT_ITEM_THROW_BALL
        .secondaryId = ITEM_CHERISH_BALL - FIRST_BALL,  // ID secundaria = ITEM_CHERISH_BALL - FIRST_BALL
    },

// Medicine

[ITEM_POTION] =
    {
        .name = _("Poción"),                // Nombre = "Poción"
        .price = 200,                       // Precio = 200
        .holdEffectParam = 20,              // Parámetro de efecto al sostener = 20
        .description = COMPOUND_STRING("Restaura los PS de\n"
                                       "un Pokémon en\n"
                                       "20 puntos."),  // Descripción = "Restaura los PS de\nun Pokémon en\n20 puntos."
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,        // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .battleUsage = EFFECT_ITEM_RESTORE_HP,         // Uso en batalla = EFFECT_ITEM_RESTORE_HP
        .flingPower = 30,                   // Poder al lanzar = 30
    },

[ITEM_SUPER_POTION] =
    {
        .name = _("Superpoción"),          // Nombre = "Superpoción"
        .price = 700,                       // Precio = 700
        .holdEffectParam = 60,              // Parámetro de efecto al sostener = 60
        #if I_HEALTH_RECOVERY >= GEN_7
            .description = COMPOUND_STRING("Restaura los PS de\n"
                                           "un Pokémon en\n"
                                           "60 puntos."),  // Descripción = "Restaura los PS de\nun Pokémon en\n60 puntos."
        #else
            .description = COMPOUND_STRING("Restaura los PS de\n"
                                           "un Pokémon en\n"
                                           "50 puntos."),  // Descripción = "Restaura los PS de\nun Pokémon en\n50 puntos."
        #endif
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,        // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .battleUsage = EFFECT_ITEM_RESTORE_HP,         // Uso en batalla = EFFECT_ITEM_RESTORE_HP
        .flingPower = 30,                   // Poder al lanzar = 30
    },

[ITEM_HYPER_POTION] =
    {
        .name = _("Hiperpoción"),          // Nombre = "Hiperpoción"
        .price = 1500,                      // Precio = 1500
        .holdEffectParam = 120,             // Parámetro de efecto al sostener = 120
        #if I_HEALTH_RECOVERY >= GEN_7
            .description = COMPOUND_STRING("Restaura los PS de\n"
                                           "un Pokémon en\n"
                                           "120 puntos."),  // Descripción = "Restaura los PS de\nun Pokémon en\n120 puntos."
        #else
            .description = COMPOUND_STRING("Restaura los PS de\n"
                                           "un Pokémon en\n"
                                           "200 puntos."),  // Descripción = "Restaura los PS de\nun Pokémon en\n200 puntos."
        #endif
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,        // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .battleUsage = EFFECT_ITEM_RESTORE_HP,         // Uso en batalla = EFFECT_ITEM_RESTORE_HP
        .flingPower = 30,                   // Poder al lanzar = 30
    },

[ITEM_MAX_POTION] =
    {
        .name = _("Max Poción"),           // Nombre = "Max Poción"
        .price = 2500,                      // Precio = 2500
        .holdEffectParam = 255,             // Parámetro de efecto al sostener = 255
        .description = COMPOUND_STRING("Restaura completamente\n"
                                       "los PS de un Pokémon."),  // Descripción = "Restaura completamente\nlos PS de un Pokémon."
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,        // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .battleUsage = EFFECT_ITEM_RESTORE_HP,         // Uso en batalla = EFFECT_ITEM_RESTORE_HP
        .flingPower = 30,                   // Poder al lanzar = 30
    },

[ITEM_FULL_RESTORE] =
    {
        .name = _("Restaura todo"),         // Nombre = "Restaura todo"
        .price = 3000,                      // Precio = 3000
        .holdEffectParam = 255,             // Parámetro de efecto al sostener = 255
        .description = COMPOUND_STRING("Restaura completamente\n"
                                       "los PS y el estado de un\n"
                                       "Pokémon."),  // Descripción = "Restaura completamente\nlos PS y el estado de un\nPokémon."
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,        // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .battleUsage = EFFECT_ITEM_HEAL_AND_CURE_STATUS,  // Uso en batalla = EFFECT_ITEM_HEAL_AND_CURE_STATUS
        .flingPower = 30,                   // Poder al lanzar = 30
    },

[ITEM_REVIVE] =
    {
        .name = _("Revivir"),               // Nombre = "Revivir"
        .price = 2000,                      // Precio = 2000
        .description = COMPOUND_STRING("Revive a un Pokémon\n"
                                       "debilitado con la\n"
                                       "mitad de sus PS."),  // Descripción = "Revive a un Pokémon\ndebilitado con la\nmitad de sus PS."
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,        // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .battleUsage = EFFECT_ITEM_REVIVE,  // Uso en batalla = EFFECT_ITEM_REVIVE
        .flingPower = 30,                   // Poder al lanzar = 30
    },

[ITEM_MAX_REVIVE] =
    {
        .name = _("Max Revivir"),           // Nombre = "Max Revivir"
        .price = 4000,                      // Precio = 4000
        .description = sMaxReviveDesc,     // Descripción = sMaxReviveDesc
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,        // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .battleUsage = EFFECT_ITEM_REVIVE,  // Uso en batalla = EFFECT_ITEM_REVIVE
        .flingPower = 30,                   // Poder al lanzar = 30
    },

[ITEM_FRESH_WATER] =
    {
        .name = _("Agua fresca"),           // Nombre = "Agua fresca"
        .price = 200,                       // Precio = 200
        .holdEffectParam = 30,              // Parámetro de efecto al sostener = 30
        #if I_HEALTH_RECOVERY >= GEN_7
            .description = COMPOUND_STRING("Agua mineral que\n"
                                           "restaura los PS en\n"
                                           "30 puntos."),  // Descripción = "Agua mineral que\nrestaura los PS en\n30 puntos."
        #else
            .description = COMPOUND_STRING("Agua mineral que\n"
                                           "restaura los PS en\n"
                                           "50 puntos."),  // Descripción = "Agua mineral que\nrestaura los PS en\n50 puntos."
        #endif
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,        // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .battleUsage = EFFECT_ITEM_RESTORE_HP,         // Uso en batalla = EFFECT_ITEM_RESTORE_HP
        .flingPower = 30,                   // Poder al lanzar = 30
    },

[ITEM_SODA_POP] =
    {
        .name = _("Refresco"),              // Nombre = "Refresco"
        .price = 300,                       // Precio = 300
        .holdEffectParam = 50,              // Parámetro de efecto al sostener = 50
        #if I_HEALTH_RECOVERY >= GEN_7
            .description = COMPOUND_STRING("Bebida gaseosa que\n"
                                           "restaura los PS en\n"
                                           "50 puntos."),  // Descripción = "Bebida gaseosa que\nrestaura los PS en\n50 puntos."
        #else
            .description = COMPOUND_STRING("Bebida gaseosa que\n"
                                           "restaura los PS en\n"
                                           "60 puntos."),  // Descripción = "Bebida gaseosa que\nrestaura los PS en\n60 puntos."
        #endif
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,        // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .battleUsage = EFFECT_ITEM_RESTORE_HP,         // Uso en batalla = EFFECT_ITEM_RESTORE_HP
        .flingPower = 30,                   // Poder al lanzar = 30
    },

[ITEM_LEMONADE] =
    {
        .name = _("Limonada"),              // Nombre = "Limonada"
        .price = 400,                       // Precio = 400
        .holdEffectParam = 70,              // Parámetro de efecto al sostener = 70
#if I_HEALTH_RECOVERY >= GEN_7
        .description = COMPOUND_STRING("Bebida muy dulce que\n"
                                       "restaura los PS en\n"
                                       "70 puntos."),  // Descripción = "Bebida muy dulce que\nrestaura los PS en\n70 puntos."
#else
        .description = COMPOUND_STRING("Bebida muy dulce que\n"
                                       "restaura los PS en\n"
                                       "80 puntos."),  // Descripción = "Bebida muy dulce que\nrestaura los PS en\n80 puntos."
#endif
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,        // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .battleUsage = EFFECT_ITEM_RESTORE_HP,         // Uso en batalla = EFFECT_ITEM_RESTORE_HP
        .flingPower = 30,                   // Poder al lanzar = 30
    },

[ITEM_MOOMOO_MILK] =
    {
        .name = _("Leche Moomoo"),         // Nombre = "Leche Moomoo"
        .price = 600,                       // Precio = 600
        .holdEffectParam = 100,             // Parámetro de efecto al sostener = 100
        .description = COMPOUND_STRING("Una leche nutritiva\n"
                                       "que restaura los PS\n"
                                       "en 100 puntos."),   // Descripción = "Una leche nutritiva\nque restaura los PS\nen 100 puntos."
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,        // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .battleUsage = EFFECT_ITEM_RESTORE_HP,         // Uso en batalla = EFFECT_ITEM_RESTORE_HP
        .flingPower = 30,                   // Poder al lanzar = 30
    },

[ITEM_ENERGY_POWDER] =
    {
        .name = _("Polvo energía"),        // Nombre = "Polvo energía"
        .price = 500,                       // Precio = 500
        #if I_HEALTH_RECOVERY >= GEN_7
            .description = COMPOUND_STRING("Un polvo amargo\n"
                                           "que restaura los PS\n"
                                           "en 60 puntos."),   // Descripción = "Un polvo amargo\nque restaura los PS\nen 60 puntos."
        #else
            .description = COMPOUND_STRING("Un polvo amargo\n"
                                           "que restaura los PS\n"
                                           "en 50 puntos."),   // Descripción = "Un polvo amargo\nque restaura los PS\nen 50 puntos."
        #endif
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,        // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .battleUsage = EFFECT_ITEM_RESTORE_HP,         // Uso en batalla = EFFECT_ITEM_RESTORE_HP
        .flingPower = 30,                   // Poder al lanzar = 30
    },

    [ITEM_ENERGY_ROOT] =
    {
        .name = _("Raíz energía"),         // Nombre = "Raíz energía"
        .price = 1200,                      // Precio = 1200
        #if I_HEALTH_RECOVERY >= GEN_7
            .description = COMPOUND_STRING("Una raíz amarga\n"
                                           "que restaura los PS\n"
                                           "en 120 puntos."),  // Descripción = "Una raíz amarga\nque restaura los PS\nen 120 puntos."
        #else
            .description = COMPOUND_STRING("Una raíz amarga\n"
                                           "que restaura los PS\n"
                                           "en 200 puntos."),  // Descripción = "Una raíz amarga\nque restaura los PS\nen 200 puntos."
        #endif
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,        // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .battleUsage = EFFECT_ITEM_RESTORE_HP,         // Uso en batalla = EFFECT_ITEM_RESTORE_HP
        .flingPower = 30,                   // Poder al lanzar = 30
    },

[ITEM_HEAL_POWDER] =
    {
        .name = _("Polvo cura."),          // Nombre = "Polvo cura."
        .price = 300,                       // Precio = 300
        .description = COMPOUND_STRING("Un polvo amargo\n"
                                       "que cura todos\n"
                                       "los problemas de estado."),  // Descripción = "Un polvo amargo\nque cura todos\nlos problemas de estado."
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,        // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .battleUsage = EFFECT_ITEM_CURE_STATUS,        // Uso en batalla = EFFECT_ITEM_CURE_STATUS
        .flingPower = 30,                   // Poder al lanzar = 30
    },

[ITEM_REVIVAL_HERB] =
    {
        .name = _("Hierba rev."),          // Nombre = "Hierba rev."
        .price = 2800,                      // Precio = 2800
        .description = COMPOUND_STRING("Una hierba muy amarga\n"
                                       "que revive a un\n"
                                       "Pokémon debilitado."),  // Descripción = "Una hierba muy amarga\nque revive a un\nPokémon debilitado."
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,        // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .battleUsage = EFFECT_ITEM_REVIVE,   // Uso en batalla = EFFECT_ITEM_REVIVE
        .flingPower = 30,                   // Poder al lanzar = 30
    },

[ITEM_ANTIDOTE] =
    {
        .name = _("Antídoto"),             // Nombre = "Antídoto"
        .price = 200,                       // Precio = 200
        .description = COMPOUND_STRING("Cura a un Pokémon\n"
                                       "envenenado."),     // Descripción = "Cura a un Pokémon\nenvenenado."
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,        // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .battleUsage = EFFECT_ITEM_CURE_STATUS,        // Uso en batalla = EFFECT_ITEM_CURE_STATUS
        .flingPower = 30,                   // Poder al lanzar = 30
    },

[ITEM_PARALYZE_HEAL] =
    {
        .name = _("Antiparaliz"),          // Nombre = "Antiparaliz"
        .price = 300,                       // Precio = 300
        .description = COMPOUND_STRING("Cura a un Pokémon\n"
                                       "paralizado."),     // Descripción = "Cura a un Pokémon\nparalizado."
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,        // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .battleUsage = EFFECT_ITEM_CURE_STATUS,        // Uso en batalla = EFFECT_ITEM_CURE_STATUS
        .flingPower = 30,                   // Poder al lanzar = 30
    },

[ITEM_BURN_HEAL] =
    {
        .name = _("Antiquemar"),           // Nombre = "Antiquemar"
        .price = 300,                       // Precio = 300
        .description = COMPOUND_STRING("Cura a un Pokémon\n"
                                       "quemado."),        // Descripción = "Cura a un Pokémon\nquemado."
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,        // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .battleUsage = EFFECT_ITEM_CURE_STATUS,        // Uso en batalla = EFFECT_ITEM_CURE_STATUS
        .flingPower = 30,                   // Poder al lanzar = 30
    },

[ITEM_ICE_HEAL] =
    {
        .name = _("Antihielo"),            // Nombre = "Antihielo"
        .price = 100,                       // Precio = 100
        .description = COMPOUND_STRING("Descongela a un\n"
                                       "Pokémon congelado."),  // Descripción = "Descongela a un\nPokémon congelado."
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,        // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .battleUsage = EFFECT_ITEM_CURE_STATUS,        // Uso en batalla = EFFECT_ITEM_CURE_STATUS
        .flingPower = 30,                   // Poder al lanzar = 30
    },

[ITEM_AWAKENING] =
    {
        .name = _("Despertar"),            // Nombre = "Despertar"
        .price = 100,                       // Precio = 100
        .description = COMPOUND_STRING("Despierta a un\n"
                                       "Pokémon dormido."),  // Descripción = "Despierta a un\nPokémon dormido."
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,        // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .battleUsage = EFFECT_ITEM_CURE_STATUS,        // Uso en batalla = EFFECT_ITEM_CURE_STATUS
        .flingPower = 30,                   // Poder al lanzar = 30
    },

[ITEM_FULL_HEAL] =
    {
        .name = _("Cura total"),           // Nombre = "Cura total"
        .price = 400,                       // Precio = 400
        .description = sFullHealDesc,      // Descripción = sFullHealDesc (valor definido en otra parte del código)
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,        // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .battleUsage = EFFECT_ITEM_CURE_STATUS,        // Uso en batalla = EFFECT_ITEM_CURE_STATUS
        .flingPower = 30,                   // Poder al lanzar = 30
    },

    [ITEM_ETHER] =
    {
        .name = _("Éter"),  // Nombre = "Éter"
        .price = 1200,      // Precio = 1200
        .holdEffectParam = 10,  // Parámetro de efecto al sostener = 10
        .description = COMPOUND_STRING("Restaura los PP\n"
                                       "de un movimiento seleccionado\n"
                                       "en 10 puntos."),  // Descripción = "Restaura los PP\nde un movimiento seleccionado\nen 10 puntos."
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU_MOVES,  // Tipo = ITEM_USE_PARTY_MENU_MOVES
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,  // Función de uso fuera de batalla = ItemUseOutOfBattle_PPRecovery
        .battleUsage = EFFECT_ITEM_RESTORE_PP,         // Uso en batalla = EFFECT_ITEM_RESTORE_PP
        .flingPower = 30,                   // Poder al lanzar = 30
    },

[ITEM_MAX_ETHER] =
    {
        .name = _("Max éter"),  // Nombre = "Max éter"
        .price = 2000,           // Precio = 2000
        .holdEffectParam = 255,  // Parámetro de efecto al sostener = 255
        .description = COMPOUND_STRING("Restaura completamente los\n"
                                       "PP de un movimiento seleccionado."),  // Descripción = "Restaura completamente los\nPP de un movimiento seleccionado."
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU_MOVES,  // Tipo = ITEM_USE_PARTY_MENU_MOVES
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,  // Función de uso fuera de batalla = ItemUseOutOfBattle_PPRecovery
        .battleUsage = EFFECT_ITEM_RESTORE_PP,         // Uso en batalla = EFFECT_ITEM_RESTORE_PP
        .flingPower = 30,                   // Poder al lanzar = 30
    },

[ITEM_ELIXIR] =
    {
        .name = _("Elixir"),  // Nombre = "Elixir"
        .price = 3000,         // Precio = 3000
        .holdEffectParam = 10,  // Parámetro de efecto al sostener = 10
        .description = COMPOUND_STRING("Restaura los PP\n"
                                       "de todos los movimientos en 10 puntos."),  // Descripción = "Restaura los PP\nde todos los movimientos en 10 puntos."
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,        // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,  // Función de uso fuera de batalla = ItemUseOutOfBattle_PPRecovery
        .battleUsage = EFFECT_ITEM_RESTORE_PP,         // Uso en batalla = EFFECT_ITEM_RESTORE_PP
        .flingPower = 30,                   // Poder al lanzar = 30
    },

[ITEM_MAX_ELIXIR] =
    {
        .name = _("Max elixir"),  // Nombre = "Max elixir"
        .price = 4500,            // Precio = 4500
        .holdEffectParam = 255,   // Parámetro de efecto al sostener = 255
        .description = COMPOUND_STRING("Restaura completamente los\n"
                                       "PP de todos los movimientos de un Pokémon."),  // Descripción = "Restaura completamente los\nPP de todos los movimientos de un Pokémon."
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,        // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,  // Función de uso fuera de batalla = ItemUseOutOfBattle_PPRecovery
        .battleUsage = EFFECT_ITEM_RESTORE_PP,         // Uso en batalla = EFFECT_ITEM_RESTORE_PP
        .flingPower = 30,                   // Poder al lanzar = 30
    },

[ITEM_BERRY_JUICE] =
    {
        .name = _("Zumo de baya"),  // Nombre = "Zumo de baya"
        .price = 200,               // Precio = 200
        .holdEffect = HOLD_EFFECT_RESTORE_HP,  // Efecto al sostener = HOLD_EFFECT_RESTORE_HP
        .holdEffectParam = 20,      // Parámetro de efecto al sostener = 20
        .description = COMPOUND_STRING("Un jugo 100% puro\n"
                                       "que restaura HP\n"
                                       "en 20 puntos."),  // Descripción = "Un jugo 100% puro\nque restaura HP\nen 20 puntos."
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,        // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .battleUsage = EFFECT_ITEM_RESTORE_HP,         // Uso en batalla = EFFECT_ITEM_RESTORE_HP
        .flingPower = 30,                   // Poder al lanzar = 30
    },

[ITEM_SACRED_ASH] =
    {
        .name = _("Ceniza sag."),  // Nombre = "Ceniza sag."
        .price = 50000,             // Precio = 50000
        .description = COMPOUND_STRING("Revive completamente y\n"
                                       "restaura a todos los\n"
                                       "Pokémon debilitados."),  // Descripción = "Revive completamente y\nrestaura a todos los\nPokémon debilitados."
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,        // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_SacredAsh,  // Función de uso fuera de batalla = ItemUseOutOfBattle_SacredAsh
        .flingPower = 30,                   // Poder al lanzar = 30
    },

[ITEM_SWEET_HEART] =
    {
        .name = _("Corazón dulce"),  // Nombre = "Corazón dulce"
        .price = 3000,                // Precio = 3000
        .holdEffectParam = 20,       // Parámetro de efecto al sostener = 20
        .description = COMPOUND_STRING("Un chocolate dulce\n"
                                       "que restaura HP\n"
                                       "en 20 puntos."),  // Descripción = "Un chocolate dulce\nque restaura HP\nen 20 puntos."
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,        // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .battleUsage = EFFECT_ITEM_RESTORE_HP,         // Uso en batalla = EFFECT_ITEM_RESTORE_HP
        .flingPower = 30,                   // Poder al lanzar = 30
    },

[ITEM_MAX_HONEY] =
    {
        .name = _("Maxipanal"),  // Nombre = "Maxipanal"
        .price = 8000,            // Precio = 8000
        .description = sMaxReviveDesc,  // Descripción = sMaxReviveDesc
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,        // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .battleUsage = EFFECT_ITEM_REVIVE,         // Uso en batalla = EFFECT_ITEM_REVIVE
        .flingPower = 30,                   // Poder al lanzar = 30
    },

// Regional Specialties

    [ITEM_PEWTER_CRUNCHIES] =
    {
        .name = _("Rokikos"),  // Nombre = "Rokikos"
        .price = 250,           // Precio = 250
        .description = sFullHealDesc,  // Descripción = sFullHealDesc
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,        // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .battleUsage = EFFECT_ITEM_CURE_STATUS,         // Uso en batalla = EFFECT_ITEM_CURE_STATUS
        .flingPower = 30,                   // Poder al lanzar = 30
    },

[ITEM_RAGE_CANDY_BAR] =
    {
        .name = _("Caram. furia"),  // Nombre = "Caram. furia"
        .price = 350,                // Precio = 350
        .description = sFullHealDesc,  // Descripción = sFullHealDesc
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,        // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .battleUsage = EFFECT_ITEM_CURE_STATUS,         // Uso en batalla = EFFECT_ITEM_CURE_STATUS
        .flingPower = 30,                   // Poder al lanzar = 30
    },

[ITEM_LAVA_COOKIE] =
    {
        .name = _("Galleta lava"),  // Nombre = "Galleta lava"
        .price = 350,                // Precio = 350
        .description = COMPOUND_STRING("Una especialidad local\n"
                                       "que cura todos los\n"
                                       "problemas de estado."),  // Descripción = "Una especialidad local\nque cura todos los\nproblemas de estado."
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,        // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .battleUsage = EFFECT_ITEM_CURE_STATUS,         // Uso en batalla = EFFECT_ITEM_CURE_STATUS
        .flingPower = 30,                   // Poder al lanzar = 30
    },

[ITEM_OLD_GATEAU] =
    {
        .name = _("Barrita plus"),  // Nombre = "Barrita plus"
        .price = 350,                // Precio = 350
        .description = sFullHealDesc,  // Descripción = sFullHealDesc
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,        // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .battleUsage = EFFECT_ITEM_CURE_STATUS,         // Uso en batalla = EFFECT_ITEM_CURE_STATUS
        .flingPower = 30,                   // Poder al lanzar = 30
    },

[ITEM_CASTELIACONE] =
    {
        .name = _("Porcehelado"),  // Nombre = "Porcehelado"
        .price = 350,               // Precio = 350
        .description = sFullHealDesc,  // Descripción = sFullHealDesc
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,        // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .battleUsage = EFFECT_ITEM_CURE_STATUS,         // Uso en batalla = EFFECT_ITEM_CURE_STATUS
        .flingPower = 30,                   // Poder al lanzar = 30
    },

[ITEM_LUMIOSE_GALETTE] =
    {
        .name = _("Luminicola"),  // Nombre = "Luminicola"
        .price = 350,              // Precio = 350
        .description = sFullHealDesc,  // Descripción = sFullHealDesc
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,        // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .battleUsage = EFFECT_ITEM_CURE_STATUS,         // Uso en batalla = EFFECT_ITEM_CURE_STATUS
        .flingPower = 30,                   // Poder al lanzar = 30
    },

[ITEM_SHALOUR_SABLE] =
    {
        .name = _("Gall. Yantra"),  // Nombre = "Gall. Yantra"
        .price = 350,                // Precio = 350
        .description = sFullHealDesc,  // Descripción = sFullHealDesc
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,        // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .battleUsage = EFFECT_ITEM_CURE_STATUS,         // Uso en batalla = EFFECT_ITEM_CURE_STATUS
        .flingPower = 30,                   // Poder al lanzar = 30
    },

[ITEM_BIG_MALASADA] =
    {
        .name = _("Malasada maxi"),  // Nombre = "Malasada maxi"
        .price = 350,                 // Precio = 350
        .description = sFullHealDesc,  // Descripción = sFullHealDesc
        .pocket = POCKET_ITEMS,             // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,        // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .battleUsage = EFFECT_ITEM_CURE_STATUS,         // Uso en batalla = EFFECT_ITEM_CURE_STATUS
        .flingPower = 30,                   // Poder al lanzar = 30
    },

// Vitamins

    [ITEM_HP_UP] =
    {
        .name = _("Más PS"),  // Nombre = "Más PS"
        .price = 10000,        // Precio = 10000
        .description = COMPOUND_STRING("Aumenta los PS base de\n"
                                       "un Pokémon."),  // Descripción = "Raises the base HP\nof one Pokémon."
        .pocket = POCKET_ITEMS,                 // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,            // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .flingPower = 30,                       // Poder al lanzar = 30
    },

[ITEM_PROTEIN] =
    {
        .name = _("Proteína"),  // Nombre = "Proteína"
        .price = 10000,         // Precio = 10000
        .description = COMPOUND_STRING("Aumenta el stat de Ataque\n"
                                       "base de un Pokémon."),  // Descripción = "Raises the base\nAttack stat of one\nPokémon."
        .pocket = POCKET_ITEMS,                 // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,            // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .flingPower = 30,                       // Poder al lanzar = 30
    },

[ITEM_IRON] =
    {
        .name = _("Hierro"),  // Nombre = "Hierro"
        .price = 10000,       // Precio = 10000
        .description = COMPOUND_STRING("Aumenta el stat de Defensa\n"
                                       "base de un Pokémon."),  // Descripción = "Raises the base\nDefense stat of\none Pokémon."
        .pocket = POCKET_ITEMS,                 // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,            // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .flingPower = 30,                       // Poder al lanzar = 30
    },

[ITEM_CALCIUM] =
    {
        .name = _("Calcio"),  // Nombre = "Calcio"
        .price = 10000,       // Precio = 10000
        .description = COMPOUND_STRING("Aumenta el stat de Ataque Especial\n"
                                       "base de un Pokémon."),  // Descripción = "Raises the base\nSp. Atk stat of one\nPokémon."
        .pocket = POCKET_ITEMS,                 // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,            // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .flingPower = 30,                       // Poder al lanzar = 30
    },

[ITEM_ZINC] =
    {
        .name = _("Zinc"),  // Nombre = "Zinc"
        .price = 10000,     // Precio = 10000
        .description = COMPOUND_STRING("Aumenta el stat de Defensa Especial\n"
                                       "base de un Pokémon."),  // Descripción = "Raises the base\nSp. Def stat of one\nPokémon."
        .pocket = POCKET_ITEMS,                 // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,            // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .flingPower = 30,                       // Poder al lanzar = 30
    },

[ITEM_CARBOS] =
    {
        .name = _("Carburante"),  // Nombre = "Carburante"
        .price = 10000,           // Precio = 10000
        .description = COMPOUND_STRING("Aumenta el stat de Velocidad\n"
                                       "base de un Pokémon."),  // Descripción = "Raises the base\nSpeed stat of one\nPokémon."
        .pocket = POCKET_ITEMS,                 // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,            // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .flingPower = 30,                       // Poder al lanzar = 30
    },

[ITEM_PP_UP] =
    {
        .name = _("Más PP"),  // Nombre = "Más PP"
        .price = 10000,        // Precio = 10000
        .description = COMPOUND_STRING("Aumenta el máximo de\n"
                                       "PP de un movimiento\n"
                                       "seleccionado."),  // Descripción = "Raises the maximum\nPP of a selected\nmove."
        .pocket = POCKET_ITEMS,                 // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,            // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_PPUp,  // Función de uso fuera de batalla = ItemUseOutOfBattle_PPUp
        .flingPower = 30,                       // Poder al lanzar = 30
    },

[ITEM_PP_MAX] =
    {
        .name = _("Máx PP"),  // Nombre = "Máx PP"
        .price = 10000,        // Precio = 10000
        .description = COMPOUND_STRING("Aumenta los PP de un\n"
                                       "movimiento al máximo."),  // Descripción = "Raises the PP of a\nmove to its maximum\npoints."
        .pocket = POCKET_ITEMS,                 // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,            // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_PPUp,  // Función de uso fuera de batalla = ItemUseOutOfBattle_PPUp
        .flingPower = 30,                       // Poder al lanzar = 30
    },

// EV Feathers

    [ITEM_HEALTH_FEATHER] =
    {
        .name = _("Pluma vigor"),
        .price = 300,
        .description = sHealthFeatherDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .flingPower = 20,
    },

    [ITEM_MUSCLE_FEATHER] =
    {
        .name = _("Pluma músculo"),
        .price = 300,
        .description = sMuscleFeatherDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .flingPower = 20,
    },

    [ITEM_RESIST_FEATHER] =
    {
        .name = _("Pluma aguante"),
        .price = 300,
        .description = sResistFeatherDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .flingPower = 20,
    },

    [ITEM_GENIUS_FEATHER] =
    {
        .name = _("Pluma inte."),
        .price = 300,
        .description = sGeniusFeatherDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .flingPower = 20,
    },

    [ITEM_CLEVER_FEATHER] =
    {
        .name = _("Pluma mente"),
        .price = 300,
        .description = sCleverFeatherDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .flingPower = 20,
    },

    [ITEM_SWIFT_FEATHER] =
    {
        .name = _("Pluma ímpetu"),
        .price = 300,
        .description = sSwiftFeatherDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .flingPower = 20,
    },

// Ability Modifiers

[ITEM_ABILITY_CAPSULE] =
    {
        .name = _("Cápsula hab."),  // Nombre = "Cápsula hab."
        .price = 10000,              // Precio = 10000
        .holdEffectParam = 0,        // Parámetro de efecto al sostener = 0
        .description = COMPOUND_STRING("Cambia la habilidad de un\n"
                                       "Pokémon."),  // Descripción = "Switches a Poké-\nmon's ability."
        .pocket = POCKET_ITEMS,                 // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,            // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_AbilityCapsule,  // Función de uso fuera de batalla = ItemUseOutOfBattle_AbilityCapsule
    },

[ITEM_ABILITY_PATCH] =
    {
        .name = _("Parche hab."),  // Nombre = "Parche hab."
        .price = 0,                  // Precio = 0
        .holdEffectParam = 0,        // Parámetro de efecto al sostener = 0
        .description = COMPOUND_STRING("Convierte la habilidad de un\n"
                                       "Pokémon en una habilidad\n"
                                       "rara."),  // Descripción = "Turns the ability\nof a Pokémon into\na rare ability."
        .pocket = POCKET_ITEMS,                 // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,            // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_AbilityPatch,  // Función de uso fuera de batalla = ItemUseOutOfBattle_AbilityPatch
    },

// Mints

    [ITEM_LONELY_MINT] =
    {
        .name = _("Menta huraña"),  // Nombre = "Menta huraña"
        .price = 20,                   // Precio = 20
        .description = COMPOUND_STRING("Se puede oler. Aumenta el\n"
                                       "Ataque, pero reduce la\n"
                                       "Defensa."),  // Descripción = "Can be smelled. It\nups Attack, but\nreduces Defense."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse (Todo)
        .flingPower = 10,                          // Poder de lanzamiento = 10
    },

[ITEM_ADAMANT_MINT] =
    {
        .name = _("Menta firme"),  // Nombre = "Menta firme"
        .price = 20,                   // Precio = 20
        .description = COMPOUND_STRING("Se puede oler. Aumenta el\n"
                                       "Ataque, pero reduce el\n"
                                       "Ataque especial."),  // Descripción = "Can be smelled. It\nups Attack, but\nreduces Sp. Atk."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse (Todo)
        .flingPower = 10,                          // Poder de lanzamiento = 10
    },

[ITEM_NAUGHTY_MINT] =
    {
        .name = _("Menta pícara"),  // Nombre = "Menta pícara"
        .price = 20,                   // Precio = 20
        .description = COMPOUND_STRING("Se puede oler. Aumenta el\n"
                                       "Ataque, pero reduce la\n"
                                       "Defensa especial."),  // Descripción = "Can be smelled. It\nups Attack, but\nreduces Sp. Def."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse (Todo)
        .flingPower = 10,                          // Poder de lanzamiento = 10
    },

[ITEM_BRAVE_MINT] =
    {
        .name = _("Menta audaz"),  // Nombre = "Menta audaz"
        .price = 20,                   // Precio = 20
        .description = COMPOUND_STRING("Se puede oler. Aumenta el\n"
                                       "Ataque, pero reduce la\n"
                                       "Velocidad."),  // Descripción = "Can be smelled. It\nups Attack, but\nreduces Speed."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse (Todo)
        .flingPower = 10,                          // Poder de lanzamiento = 10
    },

    [ITEM_BOLD_MINT] =
    {
        .name = _("Menta osada"),  // Nombre = "Menta osada"
        .price = 20,                   // Precio = 20
        .description = COMPOUND_STRING("Se puede oler. Aumenta la\n"
                                       "Defensa, pero reduce el\n"
                                       "Ataque."),  // Descripción = "Can be smelled. It\nups Defense, but\nreduces Attack."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse (Todo)
        .flingPower = 10,                          // Poder de lanzamiento = 10
    },

[ITEM_IMPISH_MINT] =
    {
        .name = _("Menta agitada"),  // Nombre = "Menta agitada"
        .price = 20,                   // Precio = 20
        .description = COMPOUND_STRING("Se puede oler. Aumenta la\n"
                                       "Defensa, pero reduce el\n"
                                       "Ataque especial."),  // Descripción = "Can be smelled. It\nups Defense, but\nreduces Sp. Atk."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse (Todo)
        .flingPower = 10,                          // Poder de lanzamiento = 10
    },

[ITEM_LAX_MINT] =
    {
        .name = _("Menta floja"),  // Nombre = "Menta floja"
        .price = 20,                   // Precio = 20
        .description = COMPOUND_STRING("Se puede oler. Aumenta la\n"
                                       "Defensa, pero reduce la\n"
                                       "Defensa especial."),  // Descripción = "Can be smelled. It\nups Defense, but\nreduces Sp. Def."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse (Todo)
        .flingPower = 10,                          // Poder de lanzamiento = 10
    },

[ITEM_RELAXED_MINT] =
    {
        .name = _("Menta plácida"),  // Nombre = "Menta plácida"
        .price = 20,                   // Precio = 20
        .description = COMPOUND_STRING("Se puede oler. Aumenta la\n"
                                       "Defensa, pero reduce la\n"
                                       "Velocidad."),  // Descripción = "Can be smelled. It\nups Defense, but\nreduces Speed."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse (Todo)
        .flingPower = 10,                          // Poder de lanzamiento = 10
    },

    [ITEM_MODEST_MINT] =
    {
        .name = _("Menta modesta"),  // Nombre = "Menta modesta"
        .price = 20,                   // Precio = 20
        .description = COMPOUND_STRING("Se puede oler. Aumenta la\n"
                                       "Ataque especial, pero\n"
                                       "reduce el Ataque."),  // Descripción = "Can be smelled. It\nups Sp. Atk, but\nreduces Attack."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse (Todo)
        .flingPower = 10,                          // Poder de lanzamiento = 10
    },

[ITEM_MILD_MINT] =
    {
        .name = _("Menta afable"),  // Nombre = "Menta afable"
        .price = 20,                   // Precio = 20
        .description = COMPOUND_STRING("Se puede oler. Aumenta la\n"
                                       "Ataque especial, pero\n"
                                       "reduce la Defensa."),  // Descripción = "Can be smelled. It\nups Sp. Atk, but\nreduces Defense."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse (Todo)
        .flingPower = 10,                          // Poder de lanzamiento = 10
    },

[ITEM_RASH_MINT] =
    {
        .name = _("Menta alocada"),  // Nombre = "Menta alocada"
        .price = 20,                   // Precio = 20
        .description = COMPOUND_STRING("Se puede oler. Aumenta la\n"
                                       "Ataque especial, pero\n"
                                       "reduce la Defensa especial."),  // Descripción = "Can be smelled. It\nups Sp. Atk, but\nreduces Sp. Def."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse (Todo)
        .flingPower = 10,                          // Poder de lanzamiento = 10
    },

[ITEM_QUIET_MINT] =
    {
        .name = _("Menta mansa"),  // Nombre = "Menta mansa"
        .price = 20,                   // Precio = 20
        .description = COMPOUND_STRING("Se puede oler. Aumenta la\n"
                                       "Ataque especial, pero\n"
                                       "reduce la Velocidad."),  // Descripción = "Can be smelled. It\nups Sp. Atk, but\nreduces Speed."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse (Todo)
        .flingPower = 10,                          // Poder de lanzamiento = 10
    },

[ITEM_CALM_MINT] =
    {
        .name = _("Menta serena"),  // Nombre = "Menta serena"
        .price = 20,                   // Precio = 20
        .description = COMPOUND_STRING("Se puede oler. Aumenta la\n"
                                       "Defensa especial, pero\n"
                                       "reduce el Ataque."),  // Descripción = "Can be smelled. It\nups Sp. Def, but\nreduces Attack."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse (Todo)
        .flingPower = 10,                          // Poder de lanzamiento = 10
    },

[ITEM_GENTLE_MINT] =
    {
        .name = _("Menta amable"),  // Nombre = "Menta amable"
        .price = 20,                   // Precio = 20
        .description = COMPOUND_STRING("Se puede oler. Aumenta la\n"
                                       "Defensa especial, pero\n"
                                       "reduce la Defensa."),  // Descripción = "Can be smelled. It\nups Sp. Def, but\nreduces Defense."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse (Todo)
        .flingPower = 10,                          // Poder de lanzamiento = 10
    },

[ITEM_CAREFUL_MINT] =
    {
        .name = _("Menta cauta"),  // Nombre = "Menta cauta"
        .price = 20,                   // Precio = 20
        .description = COMPOUND_STRING("Se puede oler. Aumenta la\n"
                                       "Defensa especial, pero\n"
                                       "reduce el Ataque especial."),  // Descripción = "Can be smelled. It\nups Sp. Def, but\nreduces Sp. Atk."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse (Todo)
        .flingPower = 10,                          // Poder de lanzamiento = 10
    },

    [ITEM_SASSY_MINT] =
    {
        .name = _("Menta grosera"),  // Nombre = "Menta grosera"
        .price = 20,                   // Precio = 20
        .description = COMPOUND_STRING("Se puede oler. Aumenta la\n"
                                       "Defensa especial, pero\n"
                                       "reduce la Velocidad."),  // Descripción = "Can be smelled. It\nups Sp. Def, but\nreduces Speed."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse (Todo)
        .flingPower = 10,                          // Poder de lanzamiento = 10
    },

[ITEM_TIMID_MINT] =
    {
        .name = _("Menta miedosa"),  // Nombre = "Menta miedosa"
        .price = 20,                   // Precio = 20
        .description = COMPOUND_STRING("Se puede oler. Aumenta la\n"
                                       "Velocidad, pero\n"
                                       "reduce el Ataque."),  // Descripción = "Can be smelled. It\nups Speed, but\nreduces Attack."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse (Todo)
        .flingPower = 10,                          // Poder de lanzamiento = 10
    },

[ITEM_HASTY_MINT] =
    {
        .name = _("Menta activa"),  // Nombre = "Menta activa"
        .price = 20,                   // Precio = 20
        .description = COMPOUND_STRING("Se puede oler. Aumenta la\n"
                                       "Velocidad, pero\n"
                                       "reduce la Defensa."),  // Descripción = "Can be smelled. It\nups Speed, but\nreduces Defense."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse (Todo)
        .flingPower = 10,                          // Poder de lanzamiento = 10
    },

[ITEM_JOLLY_MINT] =
    {
        .name = _("Menta alegre"),  // Nombre = "Menta alegre"
        .price = 20,                   // Precio = 20
        .description = COMPOUND_STRING("Se puede oler. Aumenta la\n"
                                       "Velocidad, pero\n"
                                       "reduce el Ataque especial."),  // Descripción = "Can be smelled. It\nups Speed, but\nreduces Sp. Atk."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse (Todo)
        .flingPower = 10,                          // Poder de lanzamiento = 10
    },

[ITEM_NAIVE_MINT] =
    {
        .name = _("Menta ingenua"),  // Nombre = "Menta ingenua"
        .price = 20,                   // Precio = 20
        .description = COMPOUND_STRING("Se puede oler. Aumenta la\n"
                                       "Velocidad, pero\n"
                                       "reduce la Defensa especial."),  // Descripción = "Can be smelled. It\nups Speed, but\nreduces Sp. Def."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse (Todo)
        .flingPower = 10,                          // Poder de lanzamiento = 10
    },

[ITEM_SERIOUS_MINT] =
    {
        .name = _("Menta seria"),  // Nombre = "Menta seria"
        .price = 20,                   // Precio = 20
        .description = COMPOUND_STRING("Se puede oler. Hace que cada\n"
                                       "estadística crezca por igual."),  // Descripción = "Can be smelled. It\nmakes each stat\ngrow equally."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse (Todo)
        .flingPower = 10,                          // Poder de lanzamiento = 10
    },

// Candy

    [ITEM_RARE_CANDY] =
    {
        .name = _("Caramelorraro"),  // Nombre = "Caramelorraro"
        .price = 10000,                   // Precio = 10000
        .description = COMPOUND_STRING("Aumenta el nivel de\n"
                                       "un Pokémon en uno."),  // Descripción = "Raises the level\nof a Pokémon by\none."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,               // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy, // Función de uso fuera de batalla = ItemUseOutOfBattle_RareCandy
        .flingPower = 30,                          // Poder de lanzamiento = 30
    },

[ITEM_EXP_CANDY_XS] =
    {
        .name = _("Cmlo Exp. XS"),  // Nombre = "Cmlo Exp. XS"
        .price = 20,                   // Precio = 20
        .holdEffectParam = EXP_100,               // Parámetro de efecto al sostener = EXP_100
        .description = COMPOUND_STRING("Da una pequeña\n"
                                       "cantidad de Exp. a\n"
                                       "un solo Pokémon."),  // Descripción = "Gives a very small\namount of Exp. to\na single Pokémon."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,               // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy, // Función de uso fuera de batalla = ItemUseOutOfBattle_RareCandy
        .flingPower = 30,                          // Poder de lanzamiento = 30
    },

[ITEM_EXP_CANDY_S] =
    {
        .name = _("Cmlo Exp. S"),  // Nombre = "Cmlo Exp. S"
        .price = 240,                   // Precio = 240
        .holdEffectParam = EXP_800,               // Parámetro de efecto al sostener = EXP_800
        .description = COMPOUND_STRING("Da una pequeña cantidad\n"
                                       "de Exp. a un solo\n"
                                       "Pokémon."),  // Descripción = "Gives a small\namount of Exp. to\na single Pokémon."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,               // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy, // Función de uso fuera de batalla = ItemUseOutOfBattle_RareCandy
        .flingPower = 30,                          // Poder de lanzamiento = 30
    },

[ITEM_EXP_CANDY_M] =
    {
        .name = _("Cmlo Exp. M"),  // Nombre = "Cmlo Exp. M"
        .price = 1000,                   // Precio = 1000
        .holdEffectParam = EXP_3000,              // Parámetro de efecto al sostener = EXP_3000
        .description = COMPOUND_STRING("Da una cantidad\n"
                                       "moderada de Exp. a\n"
                                       "un solo Pokémon."),  // Descripción = "Gives a moderate\namount of Exp. to\na single Pokémon."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,               // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy, // Función de uso fuera de batalla = ItemUseOutOfBattle_RareCandy
        .flingPower = 30,                          // Poder de lanzamiento = 30
    },

[ITEM_EXP_CANDY_L] =
    {
        .name = _("Cmlo Exp. L"),  // Nombre = "Cmlo Exp. L"
        .price = 3000,                   // Precio = 3000
        .holdEffectParam = EXP_10000,             // Parámetro de efecto al sostener = EXP_10000
        .description = COMPOUND_STRING("Da una gran cantidad\n"
                                       "de Exp. a un solo\n"
                                       "Pokémon."),  // Descripción = "Gives a large\namount of Exp. to\na single Pokémon."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,               // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy, // Función de uso fuera de batalla = ItemUseOutOfBattle_RareCandy
        .flingPower = 30,                          // Poder de lanzamiento = 30
    },

[ITEM_EXP_CANDY_XL] =
    {
        .name = _("Cmelo Exp. XL"),  // Nombre = "Cmelo Exp. XL"
        .price = 10000,                  // Precio = 10000
        .holdEffectParam = EXP_30000,            // Parámetro de efecto al sostener = EXP_30000
        .description = COMPOUND_STRING("Da una cantidad muy\n"
                                       "grande de Exp. a un\n"
                                       "solo Pokémon."),  // Descripción = "Gives a very large\namount of Exp. to\na single Pokémon."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,               // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy, // Función de uso fuera de batalla = ItemUseOutOfBattle_RareCandy
        .flingPower = 30,                          // Poder de lanzamiento = 30
    },

[ITEM_DYNAMAX_CANDY] =
    {
        .name = _("CmloDynamax"),  // Nombre = "CmloDynamax"
        .price = 0,                    // Precio = 0
        .description = COMPOUND_STRING("Aumenta el Nivel Dynamax\n"
                                       "de un solo Pokémon en uno."),  // Descripción = "Raises the Dynamax\nLevel of a single\nPokémon by one."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse (Todo)
        .flingPower = 30,                          // Poder de lanzamiento = 30
    },

// Medicinal Flutes

    [ITEM_BLUE_FLUTE] =
    {
        .name = _("Flauta azul"),  // Nombre = "Flauta azul"
        .price = 20,                   // Precio = 20
        .description = COMPOUND_STRING("Una flauta de cristal que\n"
                                       "despierta a los Pokémon\n"
                                       "dormidos."),  // Descripción = "A glass flute that\nawakens sleeping\nPokémon."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,               // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Medicine, // Función de uso fuera de batalla = ItemUseOutOfBattle_Medicine
        .battleUsage = EFFECT_ITEM_CURE_STATUS,    // Uso en batalla = EFFECT_ITEM_CURE_STATUS
        .flingPower = 30,                          // Poder de lanzamiento = 30
    },

[ITEM_YELLOW_FLUTE] =
    {
        .name = _("Flauta amar"),  // Nombre = "Flauta amar"
        .price = 20,                   // Precio = 20
        .description = COMPOUND_STRING("Una flauta de cristal que\n"
                                       "despierta a los Pokémon\n"
                                       "confundidos."),  // Descripción = "A glass flute that\nsnaps Pokémon\nout of confusion."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,               // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse
        .battleUsage = EFFECT_ITEM_CURE_STATUS,    // Uso en batalla = EFFECT_ITEM_CURE_STATUS
        .flingPower = 30,                          // Poder de lanzamiento = 30
    },

[ITEM_RED_FLUTE] =
    {
        .name = _("Flauta roja"),  // Nombre = "Flauta roja"
        .price = 20,                   // Precio = 20
        .description = COMPOUND_STRING("Una flauta de cristal que\n"
                                       "hace que los Pokémon\n"
                                       "dejen de sentir atracción."),  // Descripción = "A glass flute that\nsnaps Pokémon\nout of attraction."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,               // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse
        .battleUsage = EFFECT_ITEM_CURE_STATUS,    // Uso en batalla = EFFECT_ITEM_CURE_STATUS
        .flingPower = 30,                          // Poder de lanzamiento = 30
    },

// Encounter-modifying Flutes

[ITEM_BLACK_FLUTE] =
    {
        .name = _("Flauta negra"),  // Nombre = "Flauta negra"
        .price = 20,                   // Precio = 20
        .holdEffectParam = 50,         // Parámetro del efecto de retención = 50
        .description = COMPOUND_STRING("Una flauta de cristal que\n"
                                       "mantiene alejados a los\n"
                                       "Pokémon salvajes."),  // Descripción = "A glass flute that\nkeeps away wild\nPokémon."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,               // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_BlackWhiteFlute, // Función de uso fuera de batalla = ItemUseOutOfBattle_BlackWhiteFlute
        .flingPower = 30,                          // Poder de lanzamiento = 30
    },

[ITEM_WHITE_FLUTE] =
    {
        .name = _("Flauta blanca"),  // Nombre = "Flauta blanca"
        .price = 20,                   // Precio = 20
        .holdEffectParam = 150,        // Parámetro del efecto de retención = 150
        .description = COMPOUND_STRING("Una flauta de cristal que\n"
                                       "atrae a los Pokémon\n"
                                       "salvajes."),  // Descripción = "A glass flute that\nlures wild Pokémon."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_PARTY_MENU,               // Tipo = ITEM_USE_PARTY_MENU
        .fieldUseFunc = ItemUseOutOfBattle_BlackWhiteFlute, // Función de uso fuera de batalla = ItemUseOutOfBattle_BlackWhiteFlute
        .flingPower = 30,                          // Poder de lanzamiento = 30
    },

// Encounter Modifiers

    [ITEM_REPEL] =
    {
        .name = _("Repelente"),        // Nombre = "Repelente"
        .price = 400,                  // Precio = 400
        .holdEffectParam = 100,        // Parámetro del efecto de retención = 100
        .description = COMPOUND_STRING("Aleja a los Pokémon\n"
                                       "salvajes débiles por\n"
                                       "100 pasos."),  // Descripción = "Repels weak wild\nPokémon for 100\nsteps."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Repel,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Repel
        .flingPower = 30,                          // Poder de lanzamiento = 30
    },

[ITEM_SUPER_REPEL] =
    {
        .name = _("Super Repel"),      // Nombre = "Super Repel"
        .price = 700,                  // Precio = 700
        .holdEffectParam = 200,        // Parámetro del efecto de retención = 200
        .description = COMPOUND_STRING("Aleja a los Pokémon\n"
                                       "salvajes débiles por\n"
                                       "200 pasos."),  // Descripción = "Repels weak wild\nPokémon for 200\nsteps."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Repel,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Repel
        .flingPower = 30,                          // Poder de lanzamiento = 30
    },

[ITEM_MAX_REPEL] =
    {
        .name = _("Máx Repel"),        // Nombre = "Máx Repel"
        .price = 900,                  // Precio = 900
        .holdEffectParam = 250,        // Parámetro del efecto de retención = 250
        .description = COMPOUND_STRING("Aleja a los Pokémon\n"
                                       "salvajes débiles por\n"
                                       "250 pasos."),  // Descripción = "Repels weak wild\nPokémon for 250\nsteps."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Repel,  // Función de uso fuera de batalla = ItemUseOutOfBattle_Repel
        .flingPower = 30,                          // Poder de lanzamiento = 30
    },

[ITEM_LURE] =
    {
        .name = _("Colonia"),          // Nombre = "Colonia"
        .price = 400,                  // Precio = 400
        .holdEffectParam = 100,        // Parámetro del efecto de retención = 100
        .description = COMPOUND_STRING("Aumenta la probabilidad\n"
                                       "de encontrar Pokémon\n"
                                       "durante 100 pasos."),  // Descripción = "Makes Pokémon more\nlikely to appear\nfor 100 steps."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Lure,   // Función de uso fuera de batalla = ItemUseOutOfBattle_Lure
        .secondaryId = 0,                          // ID secundaria = 0
        .flingPower = 30,                          // Poder de lanzamiento = 30
    },

[ITEM_SUPER_LURE] =
    {
        .name = _("Super colonia"),    // Nombre = "Super colonia"
        .price = 700,                  // Precio = 700
        .holdEffectParam = 200,        // Parámetro del efecto de retención = 200
        .description = COMPOUND_STRING("Aumenta la probabilidad\n"
                                       "de encontrar Pokémon\n"
                                       "durante 200 pasos."),  // Descripción = "Makes Pokémon more\nlikely to appear\nfor 200 steps."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Lure,   // Función de uso fuera de batalla = ItemUseOutOfBattle_Lure
        .secondaryId = 0,                          // ID secundaria = 0
        .flingPower = 30,                          // Poder de lanzamiento = 30
    },

[ITEM_MAX_LURE] =
    {
        .name = _("Colonia máx"),      // Nombre = "Colonia máx"
        .price = 900,                  // Precio = 900
        .holdEffectParam = 250,        // Parámetro del efecto de retención = 250
        .description = COMPOUND_STRING("Aumenta la probabilidad\n"
                                       "de encontrar Pokémon\n"
                                       "durante 250 pasos."),  // Descripción = "Makes Pokémon more\nlikely to appear\nfor 250 steps."
        .pocket = POCKET_ITEMS,                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_Lure,   // Función de uso fuera de batalla = ItemUseOutOfBattle_Lure
        .secondaryId = 0,                          // ID secundaria = 0
        .flingPower = 30,                          // Poder de lanzamiento = 30
    },

[ITEM_ESCAPE_ROPE] =
    {
        .name = _("Cuerda Huida"),      // Nombre = "Cuerda Huida"
        .description = COMPOUND_STRING("Se usa para escapar\n"
                                       "instantáneamente de\n"
                                       "una cueva o mazmorra."),  // Descripción = "Use to escape\ninstantly from a\ncave or a dungeon."
        #if I_KEY_ESCAPE_ROPE >= GEN_8
            .price = 0,                     // Precio = 0
            .importance = 1,                // Importancia = 1
            .pocket = POCKET_KEY_ITEMS,     // Bolsillo = POCKET_KEY_ITEMS
        #else
            .price = 1000,                  // Precio = 1000
            .pocket = POCKET_ITEMS,         // Bolsillo = POCKET_ITEMS
        #endif
        .type = ITEM_USE_FIELD,             // Tipo = ITEM_USE_FIELD
        .fieldUseFunc = ItemUseOutOfBattle_EscapeRope,  // Función de uso fuera de batalla = ItemUseOutOfBattle_EscapeRope
        .flingPower = 30,                   // Poder de lanzamiento = 30
    },

// X Items

    [ITEM_X_ATTACK] =
    {
        .name = _("Ataque X"),                 // Nombre = "Ataque X"
        .price = 1000,                          // Precio = 1000
        .holdEffectParam = X_ITEM_STAGES,      // Parámetro de efecto de retención = X_ITEM_STAGES
        #if B_X_ITEMS_BUFF >= GEN_7
            .description = COMPOUND_STRING("Aumenta drásticamente\n"
                                           "el Ataque durante\n"
                                           "una batalla."),   // Descripción = "Sharply raises stat\nAttack during\none battle."
        #else
            .description = COMPOUND_STRING("Aumenta el Ataque\ndurante una batalla."),  // Descripción = "Raises the stat\nAttack during one\nbattle."
        #endif
        .pocket = POCKET_ITEMS,                 // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,              // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,  // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,     // Uso en batalla = EFFECT_ITEM_INCREASE_STAT
        .flingPower = 30,                       // Poder de lanzamiento = 30
    },

    [ITEM_X_DEFENSE] =
    {
        .name = _("Defensa X"),                // Nombre = "Defensa X"
        .price = 2000,                          // Precio = 2000
        .holdEffectParam = X_ITEM_STAGES,      // Parámetro de efecto de retención = X_ITEM_STAGES
        #if B_X_ITEMS_BUFF >= GEN_7
            .description = COMPOUND_STRING("Aumenta drásticamente\n"
                                           "la Defensa durante\n"
                                           "una batalla."),   // Descripción = "Sharply raises stat\nDefense during\none battle."
        #else
            .description = COMPOUND_STRING("Aumenta la Defensa\ndurante una batalla."),  // Descripción = "Raises the stat\nDefense during one\nbattle."
        #endif
        .pocket = POCKET_ITEMS,                 // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,              // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,  // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,     // Uso en batalla = EFFECT_ITEM_INCREASE_STAT
        .flingPower = 30,                       // Poder de lanzamiento = 30
    },

    [ITEM_X_SP_ATK] =
    {
        .name = _("Atq. Esp. X"),              // Nombre = "Atq. Esp. X"
        .price = 1000,                          // Precio = 1000
        .holdEffectParam = X_ITEM_STAGES,      // Parámetro de efecto de retención = X_ITEM_STAGES
        #if B_X_ITEMS_BUFF >= GEN_7
            .description = COMPOUND_STRING("Aumenta drásticamente\n"
                                           "el Atq. Esp. durante\n"
                                           "una batalla."),   // Descripción = "Sharply raises stat\nSp. Atk during\none battle."
        #else
            .description = COMPOUND_STRING("Aumenta el Atq. Esp.\ndurante una batalla."),  // Descripción = "Raises the stat\nSp. Atk during one\nbattle."
        #endif
        .pocket = POCKET_ITEMS,                 // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,              // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,  // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,     // Uso en batalla = EFFECT_ITEM_INCREASE_STAT
        .flingPower = 30,                       // Poder de lanzamiento = 30
    },

    [ITEM_X_SP_DEF] =
    {
        .name = _("Def. Esp. X"),              // Nombre = "Def. Esp. X"
        .price = 2000,                          // Precio = 2000
        .holdEffectParam = X_ITEM_STAGES,      // Parámetro de efecto de retención = X_ITEM_STAGES
        #if B_X_ITEMS_BUFF >= GEN_7
            .description = COMPOUND_STRING("Aumenta drásticamente\n"
                                           "la Def. Esp. durante\n"
                                           "una batalla."),   // Descripción = "Sharply raises stat\nSp. Def during\none battle."
        #else
            .description = COMPOUND_STRING("Aumenta la Def. Esp.\ndurante una batalla."),  // Descripción = "Raises the stat\nSp. Def during one\nbattle."
        #endif
        .pocket = POCKET_ITEMS,                 // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,              // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,  // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,     // Uso en batalla = EFFECT_ITEM_INCREASE_STAT
        .flingPower = 30,                       // Poder de lanzamiento = 30
    },

    [ITEM_X_SPEED] =
    {
        .name = _("Velocidad X"),              // Nombre = "Velocidad X"
        .price = 1000,                          // Precio = 1000
        .holdEffectParam = X_ITEM_STAGES,      // Parámetro de efecto de retención = X_ITEM_STAGES
        #if B_X_ITEMS_BUFF >= GEN_7
            .description = COMPOUND_STRING("Aumenta drásticamente\n"
                                           "la Velocidad durante\n"
                                           "una batalla."),   // Descripción = "Sharply raises stat\nSpeed during\none battle."
        #else
            .description = COMPOUND_STRING("Aumenta la Velocidad\ndurante una batalla."),  // Descripción = "Raises the stat\nSpeed during one\nbattle."
        #endif
        .pocket = POCKET_ITEMS,                 // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,              // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,  // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,     // Uso en batalla = EFFECT_ITEM_INCREASE_STAT
        .flingPower = 30,                       // Poder de lanzamiento = 30
    },

    [ITEM_X_ACCURACY] =
    {
        .name = _("Precisión X"),              // Nombre = "Precisión X"
        .price = 1000,                          // Precio = 1000
        .holdEffectParam = X_ITEM_STAGES,      // Parámetro de efecto de retención = X_ITEM_STAGES
        #if B_X_ITEMS_BUFF >= GEN_7
            .description = COMPOUND_STRING("Aumenta drásticamente\n"
                                           "la precisión de los\n"
                                           "movimientos durante\n"
                                           "una batalla."),   // Descripción = "Sharply raises move\naccuracy during\none battle."
        #else
            .description = COMPOUND_STRING("Aumenta la precisión\n"
                                           "de los movimientos\ndurante una batalla."),  // Descripción = "Raises accuracy\nof attack moves\nduring one battle."
        #endif
        .pocket = POCKET_ITEMS,                 // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,              // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,  // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,     // Uso en batalla = EFFECT_ITEM_INCREASE_STAT
        .flingPower = 30,                       // Poder de lanzamiento = 30
    },

    [ITEM_DIRE_HIT] =
    {
        .name = _("Directo"),                   // Nombre = "Directo"
        .price = 1000,                          // Precio = 1000
        .description = COMPOUND_STRING("Aumenta la\n"
                                       "probabilidad de\n"
                                       "golpe crítico en\n"
                                       "una batalla."),  // Descripción = "Raises the\ncritical-hit ratio\nduring one battle."
        .pocket = POCKET_ITEMS,                 // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,              // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,  // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse
        .battleUsage = EFFECT_ITEM_SET_FOCUS_ENERGY,    // Uso en batalla = EFFECT_ITEM_SET_FOCUS_ENERGY
        .flingPower = 30,                       // Poder de lanzamiento = 30
    },

    [ITEM_GUARD_SPEC] =
    {
        .name = _("Guardia Esp."),              // Nombre = "Guardia Esp."
        .price = 1500,                          // Precio = 1500
        .description = COMPOUND_STRING("Evita la reducción\nde estadísticas\n"
                                       "cuando se usa en\n"
                                       "una batalla."),   // Descripción = "Prevents stat\nreduction when\nused in battle."
        .pocket = POCKET_ITEMS,                 // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,              // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,  // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse
        .battleUsage = EFFECT_ITEM_SET_MIST,           // Uso en batalla = EFFECT_ITEM_SET_MIST
        .flingPower = 30,                       // Poder de lanzamiento = 30
    },

    [ITEM_POKE_DOLL] =
    {
        .name = _("Poké muñeco"),              // Nombre = "Poké muñeco"
        .price = 100,                           // Precio = 100
        .description = sPokeDollDesc,          // Descripción = sPokeDollDesc (definido en otro lugar)
        .pocket = POCKET_ITEMS,                 // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,              // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,  // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse
        .battleUsage = EFFECT_ITEM_ESCAPE,      // Uso en batalla = EFFECT_ITEM_ESCAPE
        .flingPower = 30,                       // Poder de lanzamiento = 30
    },

    [ITEM_FLUFFY_TAIL] =
    {
        .name = _("Cola Skitty"),               // Nombre = "Cola Skitty"
        .price = 100,                           // Precio = 100
        .description = sPokeDollDesc,          // Descripción = sPokeDollDesc (definido en otro lugar)
        .pocket = POCKET_ITEMS,                 // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,              // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,  // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse
        .battleUsage = EFFECT_ITEM_ESCAPE,      // Uso en batalla = EFFECT_ITEM_ESCAPE
        .flingPower = 30,                       // Poder de lanzamiento = 30
    },

    [ITEM_POKE_TOY] =
    {
        .name = _("Pokéseñuelo"),              // Nombre = "Pokéseñuelo"
        .price = 100,                           // Precio = 100
        .description = sPokeDollDesc,          // Descripción = sPokeDollDesc (definido en otro lugar)
        .pocket = POCKET_ITEMS,                 // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,              // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,  // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse
        .battleUsage = EFFECT_ITEM_ESCAPE,      // Uso en batalla = EFFECT_ITEM_ESCAPE
        .flingPower = 30,                       // Poder de lanzamiento = 30
    },

    [ITEM_MAX_MUSHROOMS] =
    {
        .name = _("Maxiseta"),                  // Nombre = "Maxiseta"
        .price = 8000,                          // Precio = 8000
        .description = COMPOUND_STRING("Aumenta todas las\n"
                                       "estadísticas durante\n"
                                       "una batalla en un\n"
                                       "nivel."),        // Descripción = "Raises every stat\nduring one battle\nby one stage."
        .pocket = POCKET_ITEMS,                 // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,              // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,  // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse
        .battleUsage = EFFECT_ITEM_INCREASE_ALL_STATS,  // Uso en batalla = EFFECT_ITEM_INCREASE_ALL_STATS
        .flingPower = 30,                       // Poder de lanzamiento = 30
    },

// Treasures

    [ITEM_BOTTLE_CAP] =
    {
        .name = _("Chapa plat"),                                  // Nombre = "Chapa plat"
        .price = 5000,                                            // Precio = 5000
        .description = COMPOUND_STRING("Una hermosa chapa que\n"
                                       "emite un destello\n"
                                       "plateado."),           // Descripción = "A beautiful bottle\ncap that gives off\na silver gleam."
        .pocket = POCKET_ITEMS,                                   // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                                // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,            // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse
        .flingPower = 30,                                         // Poder de lanzamiento = 30
    },

    [ITEM_GOLD_BOTTLE_CAP] =
    {
        .name = _("Chapa oro"),                                   // Nombre = "Chapa oro"
        .price = 10000,                                           // Precio = 10000
        .description = COMPOUND_STRING("Una hermosa chapa que\n"
                                       "emite un destello\n"
                                       "dorado."),             // Descripción = "A beautiful bottle\ncap that gives off\na golden gleam."
        .pocket = POCKET_ITEMS,                                   // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                                // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,            // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse
        .flingPower = 30,                                         // Poder de lanzamiento = 30
    },

    [ITEM_NUGGET] =
    {
        .name = _("Pepita"),                                      // Nombre = "Pepita"
        .price = 10000,                                            // Precio = 10000
        .description = COMPOUND_STRING("Una pepita de oro puro.\n"
                                       "Puede venderse a un\n"
                                       "precio elevado."),      // Descripción = "A nugget of pure\ngold. Can be sold at\na high price."
        .pocket = POCKET_ITEMS,                                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,             // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse
        .flingPower = 30,                                          // Poder de lanzamiento = 30
    },

    [ITEM_BIG_NUGGET] =
    {
        .name = _("Maxipepita"),                                   // Nombre = "Maxipepita"
        .price = 40000,                                            // Precio = 40000
        .description = COMPOUND_STRING("Una gran pepita hecha\n"
                                       "de oro, se vende a un\n"
                                       "precio elevado."),      // Descripción = "A big nugget made\nof gold, sellable\nat a high price."
        .pocket = POCKET_ITEMS,                                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,             // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse
        .flingPower = 130,                                         // Poder de lanzamiento = 130
    },

    [ITEM_TINY_MUSHROOM] =
    {
        .name = _("Seta pequeña"),                                 // Nombre = "Seta pequeña"
        .price = 500,                                              // Precio = 500
        .description = COMPOUND_STRING("Una seta común que se\n"
                                       "vende a un precio\n"
                                       "económico."),           // Descripción = "A plain mushroom\nthat would sell\nat a cheap price."
        .pocket = POCKET_ITEMS,                                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,             // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse
        .flingPower = 30,                                          // Poder de lanzamiento = 30
    },

    [ITEM_BIG_MUSHROOM] =
    {
        .name = _("Seta grande"),                                  // Nombre = "Seta grande"
        .price = 5000,                                             // Precio = 5000
        .description = sBigMushroomDesc,                          // Descripción = sBigMushroomDesc (definido en otro lugar)
        .pocket = POCKET_ITEMS,                                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,             // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse
        .flingPower = 30,                                          // Poder de lanzamiento = 30
    },

    [ITEM_BALM_MUSHROOM] =
    {
        .name = _("Seta aroma"),                                   // Nombre = "Seta aroma"
        .price = 15000,                                            // Precio = 15000
        .description = sBigMushroomDesc,                          // Descripción = sBigMushroomDesc (definido en otro lugar)
        .pocket = POCKET_ITEMS,                                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,             // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse
        .flingPower = 30,                                          // Poder de lanzamiento = 30
    },

    [ITEM_PEARL] =
    {
        .name = _("Perla"),                                        // Nombre = "Perla"
        .price = 2000,                                             // Precio = 2000
        .description = COMPOUND_STRING("Una bonita perla que\n"
                                       "se vende a un precio\n"
                                       "económico."),           // Descripción = "A pretty pearl\nthat would sell at a\ncheap price."
        .pocket = POCKET_ITEMS,                                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,             // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse
        .flingPower = 30,                                          // Poder de lanzamiento = 30
    },

    [ITEM_BIG_PEARL] =
    {
        .name = _("Perla grande"),                                  // Nombre = "Perla grande"
        .price = 8000,                                             // Precio = 8000
        .description = COMPOUND_STRING("Una hermosa perla\n"
                                       "grande que se vende\n"
                                       "a un precio elevado."), // Descripción = "A lovely large pearl\nthat would sell at a\nhigh price."
        .pocket = POCKET_ITEMS,                                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,             // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse
        .flingPower = 30,                                          // Poder de lanzamiento = 30
    },

    [ITEM_PEARL_STRING] =
    {
        .name = _("Sarta perlas"),                                  // Nombre = "Sarta perlas"
        .price = 20000,                                            // Precio = 20000
        .description = COMPOUND_STRING("Perlas muy grandes\n"
                                       "que se venden a un\n"
                                       "precio elevado."),      // Descripción = "Very large pearls\nthat would sell at a\nhigh price."
        .pocket = POCKET_ITEMS,                                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,             // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse
        .flingPower = 30,                                          // Poder de lanzamiento = 30
    },

    [ITEM_STARDUST] =
    {
        .name = _("Polvoestelar"),                                 // Nombre = "Polvoestelar"
        .price = 3000,                                             // Precio = 3000
        .description = COMPOUND_STRING("Hermosa arena roja.\n"
                                       "Se puede vender a un\n"
                                       "precio elevado."),      // Descripción = "Beautiful red sand.\nCan be sold at a\nhigh price."
        .pocket = POCKET_ITEMS,                                    // Bolsillo = POCKET_ITEMS
        .type = ITEM_USE_BAG_MENU,                                 // Tipo = ITEM_USE_BAG_MENU
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,             // Función de uso fuera de batalla = ItemUseOutOfBattle_CannotUse
        .flingPower = 30,                                          // Poder de lanzamiento = 30
    },

    [ITEM_STAR_PIECE] =
    {
        .name = _("Pieza Estelar"),
        .price = 12000,
        .description = COMPOUND_STRING("Un fragmento de gema roja.\n"
                                       "Se vende a un precio muy alto."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_COMET_SHARD] =
    {
        .name = _("Frag. Cometa"),
        .price = 25000,
        .description = COMPOUND_STRING("Un fragmento de cometa.\n"
                                       "Se vende a un precio alto."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_SHOAL_SALT] =
    {
        .name = _("Sal Cardumen"),
        .price = 20,
        .description = COMPOUND_STRING("Sal obtenida de lo más profundo\n"
                                       "de la Cueva Cardumen."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_SHOAL_SHELL] =
    {
        .name = _("C. Cardumen"),
        .price = 20,
        .description = COMPOUND_STRING("Una concha encontrada\n"
                                       "en lo más profundo de la\n"
                                       "Cueva Cardumen."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_RED_SHARD] =
    {
        .name = _("Frag. Rojo"),
        .price = 1000,
        .description = sShardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_BLUE_SHARD] =
    {
        .name = _("Frag. Azul"),
        .price = 1000,
        .description = sShardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_YELLOW_SHARD] =
    {
        .name = _("Frag. Amar."),
        .price = 1000,
        .description = sShardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_GREEN_SHARD] =
    {
        .name = _("Frag. Verde"),
        .price = 1000,
        .description = sShardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_HEART_SCALE] =
    {
        .name = _("Esc. Corazón"),
        .price = 100,
        .description = COMPOUND_STRING("Una escama encantadora.\n"
                                       "Es codiciada por los coleccionistas."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_HONEY] =
    {
        .name = _("Miel"),
        .price = 300,
        .description = COMPOUND_STRING("Miel dulce que atrae\n"
                                       "a Pokémon salvajes al usarse."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Honey,
        .flingPower = 30,
    },

    [ITEM_RARE_BONE] =
    {
        .name = _("Hueso Raro"),
        .price = 5000,
        .description = COMPOUND_STRING("Un hueso muy raro.\n"
                                       "Se puede vender a un alto precio."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

    [ITEM_ODD_KEYSTONE] =
    {
        .name = _("Piedra Esp."),
        .price = 2100,
        .description = COMPOUND_STRING("A veces se oyen voces\n"
                                       "provenientes de esta piedra\n"
                                       "extraña."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_PRETTY_FEATHER] =
    {
        .name = _("Pluma Hermosa"),
        .price = 1000,
        .description = COMPOUND_STRING("Una pluma hermosa pero simple\n"
                                       "que no hace nada."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 20,
    },

    [ITEM_RELIC_COPPER] =
    {
        .name = _("Mon. Cobre"),
        .price = 0,
        .description = COMPOUND_STRING("Una moneda de cobre usada\n"
                                       "hace mucho tiempo. Se vende\n"
                                       "a un alto precio."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_RELIC_SILVER] =
    {
        .name = _("Mon. Plata"),
        .price = 0,
        .description = COMPOUND_STRING("Una moneda de plata usada\n"
                                       "hace mucho tiempo. Se vende\n"
                                       "a un alto precio."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_RELIC_GOLD] =
    {
        .name = _("Mon. Oro"),
        .price = 0,
        .description = COMPOUND_STRING("Una moneda de oro usada\n"
                                       "hace mucho tiempo. Se vende\n"
                                       "a un alto precio."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_RELIC_VASE] =
    {
        .name = _("Á. Antigua"),
        .price = 0,
        .description = COMPOUND_STRING("Un jarrón hecho hace mucho\n"
                                       "tiempo. Se vende a un alto\n"
                                       "precio."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_RELIC_BAND] =
    {
        .name = _("B. Antiguo"),
        .price = 0,
        .description = COMPOUND_STRING("Una pulsera antigua. Se vende\n"
                                       "a un alto precio."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_RELIC_STATUE] =
    {
        .name = _("E. Antigua"),
        .price = 0,
        .description = COMPOUND_STRING("Una estatua antigua. Se vende\n"
                                       "a un alto precio."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_RELIC_CROWN] =
    {
        .name = _("C. Antigua"),
        .price = 0,
        .description = COMPOUND_STRING("Una corona antigua. Se vende\n"
                                       "a un alto precio."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_STRANGE_SOUVENIR] =
    {
        .name = _("Rec. Extraño"),
        .price = 3000,
        .description = COMPOUND_STRING("Un adorno que representa a\n"
                                       "un Pokémon de Alola."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

// Fossils

    [ITEM_HELIX_FOSSIL] =
    {
        .name = _("Fósil Helix"),
        .description = COMPOUND_STRING("Un fragmento de la concha de\n"
                                       "un antiguo Pokémon marino."),
        #if I_KEY_FOSSILS >= GEN_4
            .price = 7000,
            .pocket = POCKET_ITEMS,
        #else
            .price = 0,
            .importance = 1,
            .pocket = POCKET_KEY_ITEMS,
        #endif
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

    [ITEM_DOME_FOSSIL] =
    {
        .name = _("Fósil Domo"),
        .description = COMPOUND_STRING("Un fragmento del caparazón de\n"
                                       "un antiguo Pokémon marino."),
        #if I_KEY_FOSSILS >= GEN_4
            .price = 7000,
            .pocket = POCKET_ITEMS,
        #else
            .price = 0,
            .importance = 1,
            .pocket = POCKET_KEY_ITEMS,
        #endif
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

    [ITEM_OLD_AMBER] =
    {
        .name = _("Ámbar Viejo"),
        .description = COMPOUND_STRING("Una piedra que contiene los\n"
                                       "genes de un antiguo Pokémon."),
        #if I_KEY_FOSSILS >= GEN_4
            .price = 10000,
            .pocket = POCKET_ITEMS,
        #else
            .price = 0,
            .importance = 1,
            .pocket = POCKET_KEY_ITEMS,
        #endif
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

    [ITEM_ROOT_FOSSIL] =
    {
        .name = _("Fósil Raíz"),
        .description = sRootFossilDesc,
        #if I_KEY_FOSSILS >= GEN_4
            .price = 7000,
            .pocket = POCKET_ITEMS,
        #else
            .price = 0,
            .importance = 1,
            .pocket = POCKET_KEY_ITEMS,
        #endif
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

    [ITEM_CLAW_FOSSIL] =
    {
        .name = _("Fósil Garra"),
        .description = sRootFossilDesc,
        #if I_KEY_FOSSILS >= GEN_4
            .price = 7000,
            .pocket = POCKET_ITEMS,
        #else
            .price = 0,
            .importance = 1,
            .pocket = POCKET_KEY_ITEMS,
        #endif
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

    [ITEM_ARMOR_FOSSIL] =
    {
        .name = _("Fósil Arm."),
        .price = 7000,
        .description = COMPOUND_STRING("Un fragmento de la cabeza de\n"
                                       "un Pokémon prehistórico."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

    [ITEM_SKULL_FOSSIL] =
    {
        .name = _("Fósil Cráneo"),
        .price = 7000,
        .description = COMPOUND_STRING("Un fragmento del collar de\n"
                                       "un Pokémon prehistórico."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

    [ITEM_COVER_FOSSIL] =
    {
        .name = _("Fósil Cub."),
        .price = 7000,
        .description = COMPOUND_STRING("Un fragmento de la espalda de\n"
                                       "un Pokémon prehistórico."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

    [ITEM_PLUME_FOSSIL] =
    {
        .name = _("Fósil Pluma"),
        .price = 7000,
        .description = COMPOUND_STRING("Un fragmento del ala de\n"
                                       "un Pokémon prehistórico."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

    [ITEM_JAW_FOSSIL] =
    {
        .name = _("Fósil Mand."),
        .price = 7000,
        .description = COMPOUND_STRING("Un fragmento de la mandíbula\n"
                                       "grande de un Pokémon prehistórico."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

    [ITEM_SAIL_FOSSIL] =
    {
        .name = _("Fósil Aleta"),
        .price = 7000,
        .description = COMPOUND_STRING("Un fragmento de la vela de piel\n"
                                       "de un Pokémon prehistórico."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

    [ITEM_FOSSILIZED_BIRD] =
    {
        .name = _("Fósil Ave"),
        .price = 5000,
        .description = COMPOUND_STRING("Un fósil de un antiguo Pokémon\n"
                                       "que surcaba los cielos."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

    [ITEM_FOSSILIZED_FISH] =
    {
        .name = _("Fósil Pez"),
        .price = 5000,
        .description = sFossilizedFishDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

    [ITEM_FOSSILIZED_DRAKE] =
    {
        .name = _("Fósil Draco"),
        .price = 5000,
        .description = COMPOUND_STRING("Un fósil de un antiguo Pokémon\n"
                                       "que deambulaba por tierra."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

    [ITEM_FOSSILIZED_DINO] =
    {
        .name = _("Fósil Plesio"),
        .price = 5000,
        .description = sFossilizedFishDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

// Mulch

    [ITEM_GROWTH_MULCH] =
    {
        .name = _("Abono Rápido"),
        .price = 200,
        .description = COMPOUND_STRING("Un fertilizante que acelera el\n"
                                       "crecimiento de las Bayas."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Por hacer
        .flingPower = 30,
    },

    [ITEM_DAMP_MULCH] =
    {
        .name = _("Abono Lento"),
        .price = 200,
        .description = COMPOUND_STRING("Un fertilizante que ralentiza el\n"
                                       "crecimiento de las Bayas."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Por hacer
        .flingPower = 30,
    },

    [ITEM_STABLE_MULCH] =
    {
        .name = _("Abono Fijador"),
        .price = 200,
        .description = COMPOUND_STRING("Un fertilizante que aumenta la\n"
                                       "vida útil de los árboles de Bayas."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Por hacer
        .flingPower = 30,
    },

    [ITEM_GOOEY_MULCH] =
    {
        .name = _("Abono Brote"),
        .price = 200,
        .description = COMPOUND_STRING("Un fertilizante que hace que más\n"
                                       "Bayas vuelvan a crecer después de caer."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Por hacer
        .flingPower = 30,
    },

    [ITEM_RICH_MULCH] =
    {
        .name = _("Abono Fértil"),
        .price = 200,
        .description = COMPOUND_STRING("Un fertilizante que aumenta la\n"
                                       "cantidad de Bayas recolectadas."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Por hacer
        .flingPower = 30,
    },

    [ITEM_SURPRISE_MULCH] =
    {
        .name = _("Abono Sorp."),
        .price = 200,
        .description = COMPOUND_STRING("Un fertilizante que aumenta la\n"
                                       "probabilidad de mutaciones de Bayas."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Por hacer
        .flingPower = 30,
    },

    [ITEM_BOOST_MULCH] =
    {
        .name = _("Abono Fruct."),
        .price = 200,
        .description = COMPOUND_STRING("Un fertilizante que acelera el secado\n"
                                       "del suelo blando."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Por hacer
        .flingPower = 30,
    },

    [ITEM_AMAZE_MULCH] =
    {
        .name = _("Abono Asom."),
        .price = 200,
        .description = COMPOUND_STRING("Un fertilizante Rico, Sorprendente\n"
                                       "y Estimulante a la vez."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Por hacer
        .flingPower = 30,
    },

// Apricorns

    [ITEM_RED_APRICORN] =
    {
        .name = _("Bonguri Rojo"),
        .price = 200,
        .description = COMPOUND_STRING("Un Bonguri rojo.\n"
                                       "Asalta tus\n"
                                       "narices."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BLUE_APRICORN] =
    {
        .name = _("Bonguri Azul"),
        .price = 200,
        .description = COMPOUND_STRING("Un Bonguri azul.\n"
                                       "Huele un poco a\n"
                                       "hierba."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_YELLOW_APRICORN] =
    {
        .name = _("Bonguri Amar"),
        .price = 200,
        .description = COMPOUND_STRING("Un Bonguri amarillo.\n"
                                       "Tiene un aroma\n"
                                       "revigorizante."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GREEN_APRICORN] =
    {
        .name = _("Bonguri Verde"),
        .price = 200,
        .description = COMPOUND_STRING("Un Bonguri verde.\n"
                                       "Tiene un extraño\n"
                                       "y aromático olor."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_PINK_APRICORN] =
    {
        .name = _("Bonguri Rosa"),
        .price = 200,
        .description = COMPOUND_STRING("Un Bonguri rosa.\n"
                                       "Tiene un agradable\n"
                                       "y dulce aroma."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_WHITE_APRICORN] =
    {
        .name = _("Bonguri Bl."),
        .price = 200,
        .description = COMPOUND_STRING("Un Bonguri blanco.\n"
                                       "No huele a nada\n"
                                       "en particular."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BLACK_APRICORN] =
    {
        .name = _("Bonguri Negro"),
        .price = 200,
        .description = COMPOUND_STRING("Un Bonguri negro.\n"
                                       "Tiene un olor\n"
                                       "indescriptible."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_WISHING_PIECE] =
    {
        .name = _("Trozo deseo"),
        .price = 20,
        .description = COMPOUND_STRING("Lánzalo en una\n"
                                       "Guarida Pokémon para\n"
                                       "atraer a Pokémon Dinamax."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Por hacer
        .flingPower = 50,
    },

    [ITEM_GALARICA_TWIG] =
    {
        .name = _("Rama Galar"),
        .price = 40,
        .description = COMPOUND_STRING("Una ramita de un árbol\n"
                                       "en Galar llamado\n"
                                       "Galarica."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_ARMORITE_ORE] =
    {
        .name = _("Min. Duralium"),
        .price = 40,
        .description = COMPOUND_STRING("Un mineral raro. Se puede\n"
                                       "encontrar en la Isla de la\n"
                                       "Armadura en Galar."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_DYNITE_ORE] =
    {
        .name = _("Min. Maxinium"),
        .price = 20,
        .description = COMPOUND_STRING("Un mineral misterioso. Se\n"
                                       "puede encontrar en la Guarida\n"
                                       "Max de Galar."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

// Mail

    [ITEM_ORANGE_MAIL] =
    {
        .name = _("Carta Naranja"),
        .price = 50,
        .description = COMPOUND_STRING("Una carta con estampado\n"
                                       "de Zigzagoon para que la\n"
                                       "lleve un Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_ORANGE_MAIL),
    },

    [ITEM_HARBOR_MAIL] =
    {
        .name = _("Carta Puerto"),
        .price = 50,
        .description = COMPOUND_STRING("Una carta con estampado\n"
                                       "de Wingull para que la\n"
                                       "lleve un Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_HARBOR_MAIL),
    },

    [ITEM_GLITTER_MAIL] =
    {
        .name = _("Carta Brillo"),
        .price = 50,
        .description = COMPOUND_STRING("Una carta con estampado\n"
                                       "de Pikachu para que la\n"
                                       "lleve un Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_GLITTER_MAIL),
    },

    [ITEM_MECH_MAIL] =
    {
        .name = _("Carta Imán"),
        .price = 50,
        .description = COMPOUND_STRING("Una carta con estampado\n"
                                       "de Magnemite para que la\n"
                                       "lleve un Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_MECH_MAIL),
    },

    [ITEM_WOOD_MAIL] =
    {
        .name = _("Carta Madera"),
        .price = 50,
        .description = COMPOUND_STRING("Una carta con estampado\n"
                                       "de Slakoth para que la\n"
                                       "lleve un Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_WOOD_MAIL),
    },

    [ITEM_WAVE_MAIL] =
    {
        .name = _("Carta Ola"),
        .price = 50,
        .description = COMPOUND_STRING("Una carta con estampado\n"
                                       "de Wailmer para que la\n"
                                       "lleve un Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_WAVE_MAIL),
    },

    [ITEM_BEAD_MAIL] =
    {
        .name = _("Carta Imagen"),
        .price = 50,
        .description = sBeadMailDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_BEAD_MAIL),
    },

    [ITEM_SHADOW_MAIL] =
    {
        .name = _("Carta Sombra"),
        .price = 50,
        .description = COMPOUND_STRING("Una carta con estampado\n"
                                       "de Duskull para que la\n"
                                       "lleve un Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_SHADOW_MAIL),
    },

    [ITEM_TROPIC_MAIL] =
    {
        .name = _("Carta Trop."),
        .price = 50,
        .description = COMPOUND_STRING("Una carta con estampado\n"
                                       "de Bellossom para que la\n"
                                       "lleve un Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_TROPIC_MAIL),
    },

    [ITEM_DREAM_MAIL] =
    {
        .name = _("Carta Sueño"),
        .price = 50,
        .description = sBeadMailDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_DREAM_MAIL),
    },

    [ITEM_FAB_MAIL] =
    {
        .name = _("Carta Fab."),
        .price = 50,
        .description = COMPOUND_STRING("Una carta con estampado\n"
                                       "gorgeous para que la lleve\n"
                                       "un Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_FAB_MAIL),
    },

    [ITEM_RETRO_MAIL] =
    {
        .name = _("Carta Retro"),
        .price = 50,
        .description = COMPOUND_STRING("Carta con dibujos de tres\n"
                                       "Pokémon para que la lleve\n"
                                       "un Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_RETRO_MAIL),
    },

// Evolution Items

    [ITEM_FIRE_STONE] =
    {
        .name = _("Piedra Fuego"),
        .price = 3000,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .flingPower = 30,
    },

    [ITEM_WATER_STONE] =
    {
        .name = _("Piedra Agua"),
        .price = 3000,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .flingPower = 30,
    },

    [ITEM_THUNDER_STONE] =
    {
        .name = _("Piedra Trueno"),
        .price = 3000,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .flingPower = 30,
    },

    [ITEM_LEAF_STONE] =
    {
        .name = _("Piedra Hoja"),
        .price = 3000,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .flingPower = 30,
    },

    [ITEM_ICE_STONE] =
    {
        .name = _("Piedra Hielo"),
        .price = 3000,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .flingPower = 30,
    },

    [ITEM_SUN_STONE] =
    {
        .name = _("Piedra Solar"),
        .price = 3000,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .flingPower = 30,
    },

    [ITEM_MOON_STONE] =
    {
        .name = _("Piedra Lunar"),
        .price = 3000,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .flingPower = 30,
    },

    [ITEM_SHINY_STONE] =
    {
        .name = _("Piedra Día"),
        .price = 3000,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .flingPower = 30,
    },

    [ITEM_DUSK_STONE] =
    {
        .name = _("Piedra Noche"),
        .price = 3000,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .flingPower = 80,
    },

    [ITEM_DAWN_STONE] =
    {
        .name = _("Piedra Alba"),
        .price = 3000,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .flingPower = 80,
    },

    [ITEM_SWEET_APPLE] =
    {
        .name = _("Manzana Dulce"),
        .price = 2200,
        .description = COMPOUND_STRING("Una manzana muy dulce\n"
                                       "que hace que ciertos\n"
                                       "Pokémon evolucionen."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .flingPower = 30,
    },

    [ITEM_TART_APPLE] =
    {
        .name = _("Manzana Ácida"),
        .price = 2200,
        .description = COMPOUND_STRING("Una manzana muy ácida\n"
                                       "que hace que ciertos\n"
                                       "Pokémon evolucionen."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .flingPower = 30,
    },

    [ITEM_CRACKED_POT] =
    {
        .name = _("T. Agrietada"),
        .price = 1600,
        .description = COMPOUND_STRING("Una tetera agrietada\n"
                                       "que hace que ciertos\n"
                                       "Pokémon evolucionen."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .flingPower = 80,
    },

    [ITEM_CHIPPED_POT] =
    {
        .name = _("Tetera Rota"),
        .price = 38000,
        .description = COMPOUND_STRING("Una tetera rota\n"
                                       "que hace que ciertos\n"
                                       "Pokémon evolucionen."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .flingPower = 80,
    },

    [ITEM_GALARICA_CUFF] =
    {
        .name = _("Puño Galarica"),
        .price = 6000,
        .description = COMPOUND_STRING("Un puño de Galar\n"
                                       "que hace que ciertos\n"
                                       "Pokémon evolucionen."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .flingPower = 30,
    },

    [ITEM_GALARICA_WREATH] =
    {
        .name = _("G. Galarica"),
        .price = 6000,
        .description = COMPOUND_STRING("Una guirnalda hecha\n"
                                       "en Galar. Hace que\n"
                                       "algunos Pokémon evolucionen."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .flingPower = 30,
    },

    [ITEM_DRAGON_SCALE] =
    {
        .name = _("Escama Dragón"),
        .price = 2000,
        .holdEffect = HOLD_EFFECT_DRAGON_SCALE,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING("Una escama extraña\n"
                                       "sostenida por Pokémon\n"
                                       "de tipo Dragón."),
        .pocket = POCKET_ITEMS,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .flingPower = 30,
    },

    [ITEM_UPGRADE] =
    {
        .name = _("Mejora"),
        .price = 2000,
        .holdEffect = HOLD_EFFECT_UPGRADE,
        .description = COMPOUND_STRING("Una caja peculiar\n"
                                       "fabricada por Silph Co."),
        .pocket = POCKET_ITEMS,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .flingPower = 30,
    },

    [ITEM_PROTECTOR] =
    {
        .name = _("Protector"),
        .price = 2000,
        .description = COMPOUND_STRING("Querido por ciertos\n"
                                       "Pokémon. Es rígido\n"
                                       "y pesado."),
        .pocket = POCKET_ITEMS,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .flingPower = 80,
    },

    [ITEM_ELECTIRIZER] =
    {
        .name = _("Electrizador"),
        .price = 2000,
        .description = COMPOUND_STRING("Querido por ciertos\n"
                                       "Pokémon. Está lleno\n"
                                       "de energía eléctrica."),
        .pocket = POCKET_ITEMS,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .flingPower = 80,
    },

    [ITEM_MAGMARIZER] =
    {
        .name = _("Magmatizador"),
        .price = 2000,
        .description = COMPOUND_STRING("Querido por ciertos\n"
                                       "Pokémon. Está lleno\n"
                                       "de energía magma."),
        .pocket = POCKET_ITEMS,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .flingPower = 80,
    },

    [ITEM_DUBIOUS_DISC] =
    {
        .name = _("Disco Dudoso"),
        .price = 2000,
        .description = COMPOUND_STRING("Un dispositivo transparente\n"
                                       "que rebosa datos dudosos."),
        .pocket = POCKET_ITEMS,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .flingPower = 50,
    },

    [ITEM_REAPER_CLOTH] =
    {
        .name = _("Tela Lúgubre"),
        .price = 2000,
        .description = COMPOUND_STRING("Querido por ciertos\n"
                                       "Pokémon. Impregnado\n"
                                       "de energía espiritual."),
        .pocket = POCKET_ITEMS,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .flingPower = 10,
    },

    [ITEM_PRISM_SCALE] =
    {
        .name = _("Esc. Prisma"),
        .price = 2000,
        .description = COMPOUND_STRING("Una escama misteriosa\n"
                                       "que hace evolucionar a\n"
                                       "ciertos Pokémon. Brilla."),
        .pocket = POCKET_ITEMS,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .flingPower = 30,
    },

    [ITEM_WHIPPED_DREAM] =
    {
        .name = _("Sueño Montado"),
        .price = 2000,
        .description = COMPOUND_STRING("Un dulce suave\n"
                                       "amado por ciertos\n"
                                       "Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .flingPower = 80,
    },

    [ITEM_SACHET] =
    {
        .name = _("Frag. Sachet"),
        .price = 2000,
        .description = COMPOUND_STRING("Un saquito lleno de\n"
                                       "perfumes que le encantan\n"
                                       "a cierto Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .flingPower = 80,
    },

    [ITEM_OVAL_STONE] =
    {
        .name = _("Piedra Oval"),
        .price = 2000,
        .description = COMPOUND_STRING("Hace evolucionar a cierto\n"
                                       "Pokémon. Tiene forma de huevo."),
        .pocket = POCKET_ITEMS,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .flingPower = 80,
    },

    [ITEM_STRAWBERRY_SWEET] =
    {
        .name = _("C. Fresa"),
        .price = 500,
        .description = COMPOUND_STRING("Dulce con forma de fresa\n"
                                       "amado por Milcery."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_LOVE_SWEET] =
    {
        .name = _("C. Corazón"),
        .price = 500,
        .description = COMPOUND_STRING("Un dulce en forma de corazón\n"
                                       "amado por Milcery."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_BERRY_SWEET] =
    {
        .name = _("C. Fruto"),
        .price = 500,
        .description = COMPOUND_STRING("Dulce con forma de baya\n"
                                       "amado por Milcery."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_CLOVER_SWEET] =
    {
        .name = _("C. Trébol"),
        .price = 500,
        .description = COMPOUND_STRING("Dulce con forma de trébol\n"
                                       "amado por Milcery."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_FLOWER_SWEET] =
    {
        .name = _("C. Flor"),
        .price = 500,
        .description = COMPOUND_STRING("Dulce con forma de flor\n"
                                       "amado por Milcery."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_STAR_SWEET] =
    {
        .name = _("C. Estrella"),
        .price = 500,
        .description = COMPOUND_STRING("Dulce con forma de estrella\n"
                                       "amado por Milcery."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_RIBBON_SWEET] =
    {
        .name = _("C. Lazo"),
        .price = 500,
        .description = COMPOUND_STRING("Dulce con forma de lazo\n"
                                       "amado por Milcery."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_EVERSTONE] =
    {
        .name = _("Piedra Eterna"),
        .price = 3000,
        .holdEffect = HOLD_EFFECT_PREVENT_EVOLVE,
        .description = COMPOUND_STRING("Un objeto de retención\n"
                                       "maravilloso que evita\n"
                                       "la evolución."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

// Nectars

    [ITEM_RED_NECTAR] =
    {
        .name = _("Nectar rojo"),
        .price = 300,
        .holdEffectParam = 0,
        .description = sNectarDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange_ConsumedOnUse,
        .flingPower = 10,
    },

    [ITEM_YELLOW_NECTAR] =
    {
        .name = _("Nectar amar"),
        .price = 300,
        .holdEffectParam = 0,
        .description = sNectarDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange_ConsumedOnUse,
        .flingPower = 10,
    },

    [ITEM_PINK_NECTAR] =
    {
        .name = _("Nectar rosa"),
        .price = 300,
        .holdEffectParam = 0,
        .description = sNectarDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange_ConsumedOnUse,
        .flingPower = 10,
    },

    [ITEM_PURPLE_NECTAR] =
    {
        .name = _("Nectar morado"),
        .price = 300,
        .holdEffectParam = 0,
        .description = sNectarDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange_ConsumedOnUse,
        .flingPower = 10,
    },

// Plates

    [ITEM_FLAME_PLATE] =
    {
        .name = _("Tabla llama"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING("A tablet that ups\n"
                                       "the power of\n"
                                       "Fire-type moves."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
        .flingPower = 90,
    },

    [ITEM_SPLASH_PLATE] =
    {
        .name = _("Tabla linfa"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING("A tablet that ups\n"
                                       "the power of\n"
                                       "Water-type moves."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .flingPower = 90,
    },

    [ITEM_ZAP_PLATE] =
    {
        .name = _("Tabla trueno"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING("A tablet that ups\n"
                                       "the power of Elec-\n"
                                       "tric-type moves."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC,
        .flingPower = 90,
    },

    [ITEM_MEADOW_PLATE] =
    {
        .name = _("Tabla pradal"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING("A tablet that ups\n"
                                       "the power of\n"
                                       "Grass-type moves."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GRASS,
        .flingPower = 90,
    },

    [ITEM_ICICLE_PLATE] =
    {
        .name = _("Tabla helada"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING("A tablet that ups\n"
                                       "the power of\n"
                                       "Ice-type moves."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE,
        .flingPower = 90,
    },

    [ITEM_FIST_PLATE] =
    {
        .name = _("Tabla fuerte"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING("A tablet that ups\n"
                                       "the power of Fight-\n"
                                       "ing-type moves."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIGHTING,
        .flingPower = 90,
    },

    [ITEM_TOXIC_PLATE] =
    {
        .name = _("Tabla tóxica"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING("A tablet that ups\n"
                                       "the power of\n"
                                       "Poison-type moves."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_POISON,
        .flingPower = 90,
    },

    [ITEM_EARTH_PLATE] =
    {
        .name = _("Tabla terrax"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING("A tablet that ups\n"
                                       "the power of\n"
                                       "Ground-type moves."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GROUND,
        .flingPower = 90,
    },

    [ITEM_SKY_PLATE] =
    {
        .name = _("Tabla cielo"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING("A tablet that ups\n"
                                       "the power of\n"
                                       "Flying-type moves."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FLYING,
        .flingPower = 90,
    },

    [ITEM_MIND_PLATE] =
    {
        .name = _("Tabla mental"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING("A tablet that ups\n"
                                       "the power of Psy\n"
                                       "chic-type moves."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_PSYCHIC,
        .flingPower = 90,
    },

    [ITEM_INSECT_PLATE] =
    {
        .name = _("Tabla bicho"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING("A tablet that ups\n"
                                       "the power of\n"
                                       "Bug-type moves."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_BUG,
        .flingPower = 90,
    },

    [ITEM_STONE_PLATE] =
    {
        .name = _("Tabla pétrea"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING("A tablet that ups\n"
                                       "the power of\n"
                                       "Rock-type moves."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ROCK,
        .flingPower = 90,
    },

    [ITEM_SPOOKY_PLATE] =
    {
        .name = _("Tabla terror"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING("A tablet that ups\n"
                                       "the power of\n"
                                       "Ghost-type moves."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GHOST,
        .flingPower = 90,
    },

    [ITEM_DRACO_PLATE] =
    {
        .name = _("Tabla draco"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING("A tablet that ups\n"
                                       "the power of\n"
                                       "Dragon-type moves."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DRAGON,
        .flingPower = 90,
    },

    [ITEM_DREAD_PLATE] =
    {
        .name = _("Tabla oscura"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING("A tablet that ups\n"
                                       "the power of\n"
                                       "Dark-type moves."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DARK,
        .flingPower = 90,
    },

    [ITEM_IRON_PLATE] =
    {
        .name = _("Tabla acero"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING("A tablet that ups\n"
                                       "the power of\n"
                                       "Steel-type moves."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_STEEL,
        .flingPower = 90,
    },

    [ITEM_PIXIE_PLATE] =
    {
        .name = _("Tabla duende"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING("A stone tablet that\n"
                                       "boosts the power of\n"
                                       "Fairy-type moves."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FAIRY,
        .flingPower = 90,
    },

// Drives

    [ITEM_DOUSE_DRIVE] =
    {
        .name = _("HidroROM"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_DRIVE,
        .description = COMPOUND_STRING("Cambia el Ataque Tecnoblast\n"
                                       "de Genesect a tipo Agua."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .flingPower = 70,
    },

    [ITEM_SHOCK_DRIVE] =
    {
        .name = _("FulgoROM"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_DRIVE,
        .description = COMPOUND_STRING("Cambia el Ataque Tecnoblast\n"
                                       "de Genesect a tipo Eléctrico."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC,
        .flingPower = 70,
    },

    [ITEM_BURN_DRIVE] =
    {
        .name = _("PiroROM"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_DRIVE,
        .description = COMPOUND_STRING("Cambia el Ataque Tecnoblast\n"
                                       "de Genesect a tipo Fuego."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
        .flingPower = 70,
    },

    [ITEM_CHILL_DRIVE] =
    {
        .name = _("CrioROM"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_DRIVE,
        .description = COMPOUND_STRING("Cambia el Ataque Tecnoblast\n"
                                       "de Genesect a tipo Hielo."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE,
        .flingPower = 70,
    },

// Memories

    [ITEM_FIRE_MEMORY] =
    {
        .name = _("Disco fuego"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING("Un disco con datos de tipo Fuego.\n"
                                       "Cambia el tipo de Silvally."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
        .flingPower = 50,
    },

    [ITEM_WATER_MEMORY] =
    {
        .name = _("Disco agua"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING("Un disco con datos de tipo Agua.\n"
                                       "Cambia el tipo de Silvally."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .flingPower = 50,
    },

    [ITEM_ELECTRIC_MEMORY] =
    {
        .name = _("Disco eléct."),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING("Un disco con datos de tipo Eléctrico.\n"
                                       "Cambia el tipo de Silvally."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC,
        .flingPower = 50,
    },

    [ITEM_GRASS_MEMORY] =
    {
        .name = _("Disco planta"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING("Un disco con datos de tipo Planta.\n"
                                       "Cambia el tipo de Silvally."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GRASS,
        .flingPower = 50,
    },

    [ITEM_ICE_MEMORY] =
    {
        .name = _("Disco hielo"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING("Un disco con datos de tipo Hielo.\n"
                                       "Cambia el tipo de Silvally."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE,
        .flingPower = 50,
    },

    [ITEM_FIGHTING_MEMORY] =
    {
        .name = _("Disco lucha"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING("Un disco con datos de tipo Lucha.\n"
                                       "Cambia el tipo de Silvally."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIGHTING,
        .flingPower = 50,
    },

    [ITEM_POISON_MEMORY] =
    {
        .name = _("Disco veneno"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING("Un disco con datos de tipo Veneno.\n"
                                       "Cambia el tipo de Silvally."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_POISON,
        .flingPower = 50,
    },

    [ITEM_GROUND_MEMORY] =
    {
        .name = _("Disco Terra"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING("Un disco con datos de tipo Tierra.\n"
                                       "Cambia el tipo de Silvally."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GROUND,
        .flingPower = 50,
    },

    [ITEM_FLYING_MEMORY] =
    {
        .name = _("Disco vuelo"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING("Un disco con datos de tipo Volador.\n"
                                       "Cambia el tipo de Silvally."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FLYING,
        .flingPower = 50,
    },

    [ITEM_PSYCHIC_MEMORY] =
    {
        .name = _("Disco psíq."),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING("Un disco con datos de tipo Psíquico.\n"
                                       "Cambia el tipo de Silvally."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_PSYCHIC,
        .flingPower = 50,
    },

    [ITEM_BUG_MEMORY] =
    {
        .name = _("Disco Bicho"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING("Un disco con datos de tipo Bicho.\n"
                                       "Cambia el tipo de Silvally."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_BUG,
        .flingPower = 50,
    },

    [ITEM_ROCK_MEMORY] =
    {
        .name = _("Disco roca"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING("Un disco con datos de tipo Roca.\n"
                                       "Cambia el tipo de Silvally."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ROCK,
        .flingPower = 50,
    },

    [ITEM_GHOST_MEMORY] =
    {
        .name = _("Disco fant."),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING("Un disco con datos de tipo Fantasma.\n"
                                       "Cambia el tipo de Silvally."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GHOST,
        .flingPower = 50,
    },

    [ITEM_DRAGON_MEMORY] =
    {
        .name = _("Disco dragon"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING("Un disco con datos de tipo Dragón.\n"
                                       "Cambia el tipo de Silvally."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DRAGON,
        .flingPower = 50,
    },

    [ITEM_DARK_MEMORY] =
    {
        .name = _("Disco sin."),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING("Un disco con datos de tipo Siniestro.\n"
                                       "Cambia el tipo de Silvally."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DARK,
        .flingPower = 50,
    },

    [ITEM_STEEL_MEMORY] =
    {
        .name = _("Disco acero"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING("Un disco con datos de tipo Acero.\n"
                                       "Cambia el tipo de Silvally."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_STEEL,
        .flingPower = 50,
    },

    [ITEM_FAIRY_MEMORY] =
    {
        .name = _("Disco hada"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING("Un disco con datos de tipo Hada.\n"
                                       "Cambia el tipo de Silvally."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FAIRY,
        .flingPower = 50,
    },

    [ITEM_RUSTED_SWORD] =
    {
        .name = _("Espada ox."),
        .price = 0,
        .description = COMPOUND_STRING("Una espada oxidada. Un héroe la usó\n"
                                       "para detener un desastre."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_RUSTED_SHIELD] =
    {
        .name = _("Escudo ox."),
        .price = 0,
        .description = COMPOUND_STRING("Un escudo oxidado. Un héroe lo usó\n"
                                       "para detener un desastre."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Colored Orbs

    [ITEM_RED_ORB] =
    {
        .name = _("Prisma rojo"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_PRIMAL_ORB,
        .description = COMPOUND_STRING("Un orbe rojo y brillante\n"
                                       "que se dice que contiene un\n"
                                       "poder antiguo."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BLUE_ORB] =
    {
        .name = _("Prisma azul"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_PRIMAL_ORB,
        .description = COMPOUND_STRING("Un orbe azul y brillante\n"
                                       "que se dice que contiene un\n"
                                       "poder antiguo."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Mega Stones

    [ITEM_VENUSAURITE] =
    {
        .name = _("Venusaurita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite a\n"
                                       "Venusaur Megaevolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_CHARIZARDITE_X] =
    {
        .name = _("Charizard X"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sCharizarditeDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_CHARIZARDITE_Y] =
    {
        .name = _("Charizard Y"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sCharizarditeDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_BLASTOISINITE] =
    {
        .name = _("Blastoisita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite a\n"
                                       "Blastoise Megaevolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_BEEDRILLITE] =
    {
        .name = _("Beedrillita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite a\n"
                                       "Beedrill Megaevolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_PIDGEOTITE] =
    {
        .name = _("Pidgeotita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite a\n"
                                       "Pidgeot Megaevolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_ALAKAZITE] =
    {
        .name = _("Alakazamita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite a\n"
                                       "Alakazam Megaevolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_SLOWBRONITE] =
    {
        .name = _("Slowbronita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite a\n"
                                       "Slowbro Megaevolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_GENGARITE] =
    {
        .name = _("Gengarita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite a\n"
                                       "Gengar Megaevolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_KANGASKHANITE] =
    {
        .name = _("Kangaskhanita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite a\n"
                                       "Kangaskhan Megaevolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_PINSIRITE] =
    {
        .name = _("Pinsirita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite a\n"
                                       "Pinsir Megaevolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_GYARADOSITE] =
    {
        .name = _("Gyaradosita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite a\n"
                                       "Gyarados Megaevolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_AERODACTYLITE] =
    {
        .name = _("Aerodactylita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite a\n"
                                       "Aerodactyl Megaevolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_MEWTWONITE_X] =
    {
        .name = _("Mewtwonita X"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sMewtwoniteDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_MEWTWONITE_Y] =
    {
        .name = _("Mewtwonita Y"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sMewtwoniteDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_AMPHAROSITE] =
    {
        .name = _("Ampharosita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite a\n"
                                       "Ampharos Megaevolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_STEELIXITE] =
    {
        .name = _("Steelixita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite a\n"
                                       "Steelix Megaevolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_SCIZORITE] =
    {
        .name = _("Scizorita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite a\n"
                                       "Scizor Megaevolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_HERACRONITE] =
    {
        .name = _("Heracronita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite a\n"
                                       "Heracross Megaevolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_HOUNDOOMINITE] =
    {
        .name = _("Houndoomita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite a\n"
                                       "Houndoom Megaevolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_TYRANITARITE] =
    {
        .name = _("Tyranitarita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite a\n"
                                       "Tyranitar Megaevolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_SCEPTILITE] =
    {
        .name = _("Sceptilita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite a\n"
                                       "Sceptile Megaevolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_BLAZIKENITE] =
    {
        .name = _("Blazikenite"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite\n"
                                       "a Blaziken Mega Evolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_SWAMPERTITE] =
    {
        .name = _("Swampertite"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite\n"
                                       "a Swampert Mega Evolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_GARDEVOIRITE] =
    {
        .name = _("Gardevoirite"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite\n"
                                       "a Gardevoir Mega Evolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_SABLENITE] =
    {
        .name = _("Sablenite"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite\n"
                                       "a Sableye Mega Evolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_MAWILITE] =
    {
        .name = _("Mawilite"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite\n"
                                       "a Mawile Mega Evolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_AGGRONITE] =
    {
        .name = _("Aggronite"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite\n"
                                       "a Aggron Mega Evolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_MEDICHAMITE] =
    {
        .name = _("Medichamite"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite\n"
                                       "a Medicham Mega Evolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_MANECTITE] =
    {
        .name = _("Manectite"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite\n"
                                       "a Manectric Mega Evolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_SHARPEDONITE] =
    {
        .name = _("Sharpedonite"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite\n"
                                       "a Sharpedo Mega Evolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_CAMERUPTITE] =
    {
        .name = _("Cameruptite"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite\n"
                                       "a Camerupt Mega Evolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_ALTARIANITE] =
    {
        .name = _("Altarianite"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite\n"
                                       "a Altaria Mega Evolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_BANETTITE] =
    {
        .name = _("Banettite"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite\n"
                                       "a Banette Mega Evolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_ABSOLITE] =
    {
        .name = _("Absolite"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite\n"
                                       "a Absol Mega Evolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_GLALITITE] =
    {
        .name = _("Glalitite"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite\n"
                                       "a Glalie Mega Evolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_SALAMENCITE] =
    {
        .name = _("Salamencite"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite\n"
                                       "a Salamence Mega Evolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_METAGROSSITE] =
    {
        .name = _("Metagrossite"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite\n"
                                       "a Metagross Mega Evolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_LATIASITE] =
    {
        .name = _("Latiasite"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite\n"
                                       "a Latias Mega Evolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_LATIOSITE] =
    {
        .name = _("Latiosite"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite\n"
                                       "a Latios Mega Evolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_LOPUNNITE] =
    {
        .name = _("Lopunnite"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite\n"
                                       "a Lopunny Mega Evolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_GARCHOMPITE] =
    {
        .name = _("Garchompite"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite\n"
                                       "a Garchomp Mega Evolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_LUCARIONITE] =
    {
        .name = _("Lucarionite"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite\n"
                                       "a Lucario Mega Evolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_ABOMASITE] =
    {
        .name = _("Abomasite"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite\n"
                                       "a Abomasnow Mega Evolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_GALLADITE] =
    {
        .name = _("Galladite"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite\n"
                                       "a Gallade Mega Evolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_AUDINITE] =
    {
        .name = _("Audinite"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite\n"
                                       "a Audino Mega Evolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_DIANCITE] =
    {
        .name = _("Diancite"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Esta piedra permite\n"
                                       "a Diancie Mega Evolucionar\n"
                                       "en batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

// Gems

    [ITEM_NORMAL_GEM] =
    {
        .name = _("Gema normal"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING("Aumenta el\n"
                                       "poder de los movimientos\n"
                                       "de tipo Normal."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_NORMAL,
    },

    [ITEM_FIRE_GEM] =
    {
        .name = _("Gema fuego"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING("Aumenta el\n"
                                       "poder de los movimientos\n"
                                       "de tipo Fuego."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
    },

    [ITEM_WATER_GEM] =
    {
        .name = _("Gema agua"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING("Aumenta el\n"
                                       "poder de los movimientos\n"
                                       "de tipo Agua."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
    },

    [ITEM_ELECTRIC_GEM] =
    {
        .name = _("Gema eléc."),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING("Aumenta el\n"
                                       "poder de los movimientos\n"
                                       "de tipo Eléctrico."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC,
    },

    [ITEM_GRASS_GEM] =
    {
        .name = _("Gema planta"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING("Aumenta el\n"
                                       "poder de los movimientos\n"
                                       "de tipo Planta."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GRASS,
    },

    [ITEM_ICE_GEM] =
    {
        .name = _("Gema hielo"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING("Aumenta el\n"
                                       "poder de los movimientos\n"
                                       "de tipo Hielo."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE,
    },

    [ITEM_FIGHTING_GEM] =
    {
        .name = _("Gema lucha"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING("Aumenta el\n"
                                       "poder de los movimientos\n"
                                       "de tipo Lucha."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIGHTING,
    },

    [ITEM_POISON_GEM] =
    {
        .name = _("Gema veneno"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING("Aumenta el\n"
                                       "poder de los movimientos\n"
                                       "de tipo Veneno."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_POISON,
    },

    [ITEM_GROUND_GEM] =
    {
        .name = _("Gema tierra"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING("Aumenta el\n"
                                       "poder de los movimientos\n"
                                       "de tipo Tierra."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GROUND,
    },

    [ITEM_FLYING_GEM] =
    {
        .name = _("Gema vuelo"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING("Aumenta el\n"
                                       "poder de los movimientos\n"
                                       "de tipo Volador."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FLYING,
    },

    [ITEM_PSYCHIC_GEM] =
    {
        .name = _("Gema psíquica"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING("Aumenta el\n"
                                       "poder de los movimientos\n"
                                       "de tipo Psíquico."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_PSYCHIC,
    },

    [ITEM_BUG_GEM] =
    {
        .name = _("Gema bicho"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING("Aumenta el\n"
                                       "poder de los movimientos\n"
                                       "de tipo Bicho."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_BUG,
    },

    [ITEM_ROCK_GEM] =
    {
        .name = _("Gema roca"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING("Aumenta el\n"
                                       "poder de los movimientos\n"
                                       "de tipo Roca."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ROCK,
    },

    [ITEM_GHOST_GEM] =
    {
        .name = _("Gema fant."),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING("Aumenta el\n"
                                       "poder de los movimientos\n"
                                       "de tipo Fantasma."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GHOST,
    },

    [ITEM_DRAGON_GEM] =
    {
        .name = _("Gema dragón"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING("Aumenta el\n"
                                       "poder de los movimientos\n"
                                       "de tipo Dragón."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DRAGON,
    },

    [ITEM_DARK_GEM] =
    {
        .name = _("Gema sin."),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING("Aumenta el\n"
                                       "poder de los movimientos\n"
                                       "de tipo Siniestro."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DARK,
    },

    [ITEM_STEEL_GEM] =
    {
        .name = _("Gema acero"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING("Aumenta el\n"
                                       "poder de los movimientos\n"
                                       "de tipo Acero."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_STEEL,
    },

    [ITEM_FAIRY_GEM] =
    {
        .name = _("Gema hada"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING("Aumenta el\n"
                                       "poder de los movimientos\n"
                                       "de tipo Hada."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FAIRY,
    },

// Z-Crystals

    [ITEM_NORMALIUM_Z] =
{
    .name = _("Normastal Z"),
    .price = 0,
    .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
    .description = COMPOUND_STRING("Mejora los movimientos de tipo Normal\n"
                                   "convirtiéndolos en Movimientos Z."),
    .pocket = POCKET_ITEMS,
    .type = ITEM_USE_BAG_MENU,
    .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    .secondaryId = TYPE_NORMAL
},

[ITEM_FIRIUM_Z] =
{
    .name = _("Pirostal Z"),
    .price = 0,
    .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
    .description = COMPOUND_STRING("Mejora los movimientos de tipo Fuego\n"
                                   "convirtiéndolos en Movimientos Z."),
    .pocket = POCKET_ITEMS,
    .type = ITEM_USE_BAG_MENU,
    .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    .secondaryId = TYPE_FIRE
},

[ITEM_WATERIUM_Z] =
{
    .name = _("Hidrostal Z"),
    .price = 0,
    .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
    .description = COMPOUND_STRING("Mejora los movimientos de tipo Agua\n"
                                   "convirtiéndolos en Movimientos Z."),
    .pocket = POCKET_ITEMS,
    .type = ITEM_USE_BAG_MENU,
    .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    .secondaryId = TYPE_WATER
},

    [ITEM_ELECTRIUM_Z] =
    {
        .name = _("Electrostal Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING("Mejora los movimientos de tipo Eléctrico\n"
                                       "convirtiéndolos en Movimientos Z."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC
    },

    [ITEM_GRASSIUM_Z] =
    {
        .name = _("Fitostal Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING("Mejora los movimientos de tipo Planta\n"
                                       "convirtiéndolos en Movimientos Z."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GRASS
    },

    [ITEM_ICIUM_Z] =
    {
        .name = _("Criostal Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING("Mejora los movimientos de tipo Hielo\n"
                                       "convirtiéndolos en Movimientos Z."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE
    },

    [ITEM_FIGHTINIUM_Z] =
    {
        .name = _("Lizastal Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING("Mejora los movimientos de tipo Lucha\n"
                                       "convirtiéndolos en Movimientos Z."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIGHTING
    },

    [ITEM_POISONIUM_Z] =
    {
        .name = _("Toxistal Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING("Mejora los movimientos de tipo Veneno\n"
                                       "convirtiéndolos en Movimientos Z."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_POISON
    },

    [ITEM_GROUNDIUM_Z] =
    {
        .name = _("Geostal Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING("Mejora los movimientos de tipo Tierra\n"
                                       "convirtiéndolos en Movimientos Z."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GROUND
    },

    [ITEM_FLYINIUM_Z] =
    {
        .name = _("Aerostal Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING("Mejora los movimientos de tipo Volador\n"
                                       "convirtiéndolos en Movimientos Z."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FLYING
    },

    [ITEM_PSYCHIUM_Z] =
    {
        .name = _("Psicostal Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING("Mejora los movimientos de tipo Psíquico\n"
                                       "convirtiéndolos en Movimientos Z."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_PSYCHIC
    },

    [ITEM_BUGINIUM_Z] =
    {
        .name = _("Insectostal Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING("Mejora los movimientos de tipo Bicho\n"
                                       "convirtiéndolos en Movimientos Z."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_BUG
    },

    [ITEM_ROCKIUM_Z] =
    {
        .name = _("Litostal Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING("Mejora los movimientos de tipo Roca\n"
                                       "convirtiéndolos en Movimientos Z."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ROCK
    },

    [ITEM_GHOSTIUM_Z] =
    {
        .name = _("Espect. Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING("Mejora los movimientos de tipo Fantasma\n"
                                       "convirtiéndolos en Movimientos Z."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GHOST
    },

    [ITEM_DRAGONIUM_Z] =
    {
        .name = _("Dracostal Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING("Mejora los movimientos de tipo Dragón\n"
                                       "convirtiéndolos en Movimientos Z."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DRAGON
    },

    [ITEM_DARKINIUM_Z] =
    {
        .name = _("Nictostal Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING("Mejora los movimientos de tipo Siniestro\n"
                                       "convirtiéndolos en Movimientos Z."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DARK
    },

    [ITEM_STEELIUM_Z] =
    {
        .name = _("Metalostal Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING("Mejora los movimientos de tipo Acero\n"
                                       "convirtiéndolos en Movimientos Z."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_STEEL
    },

    [ITEM_FAIRIUM_Z] =
    {
        .name = _("Feeristal Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING("Mejora los movimientos de tipo Hada\n"
                                       "convirtiéndolos en Movimientos Z."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FAIRY
    },

    [ITEM_PIKANIUM_Z] =
    {
        .name = _("Pikastal Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING("Mejora el movimiento Voltio Cruel de Pikachu\n"
                                       "convirtiéndolo en un Movimiento Z."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255  // movimiento Z exclusivo
    },

    [ITEM_EEVIUM_Z] =
    {
        .name = _("Eeveestal Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING("Mejora el movimiento Última Baza de Eevee\n"
                                       "convirtiéndolo en un Movimiento Z."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255  // movimiento Z exclusivo
    },

    [ITEM_SNORLIUM_Z] =
    {
        .name = _("Snorlastal Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING("Mejora el movimiento Giga Impacto de Snorlax\n"
                                       "convirtiéndolo en un Movimiento Z."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255  // movimiento Z exclusivo
    },

    [ITEM_MEWNIUM_Z] =
    {
        .name = _("Mewstal Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING("Mejora el movimiento Psíquico de Mew\n"
                                       "convirtiéndolo en un Movimiento Z."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255  // movimiento Z exclusivo
    },

    [ITEM_DECIDIUM_Z] =
    {
        .name = _("Dueyestal Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING("Mejora el movimiento Impresionar de Decidueye\n"
                                       "convirtiéndolo en un Movimiento Z."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255  // movimiento Z exclusivo
    },

    [ITEM_INCINIUM_Z] =
    {
        .name = _("Incinostal Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING("Mejora el movimiento Lariat Oscuro de Incineroar\n"
                                       "convirtiéndolo en un Movimiento Z."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255  // movimiento Z exclusivo
    },

    [ITEM_PRIMARIUM_Z] =
    {
        .name = _("Primastal Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING("Mejora el movimiento Aria Burbuja de Primarina\n"
                                       "convirtiéndolo en un Movimiento Z."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255  // movimiento Z exclusivo
    },

    [ITEM_LYCANIUM_Z] =
    {
        .name = _("Lycanrostal Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING("Mejora el movimiento Roca Afilada de Lycanroc\n"
                                       "convirtiéndolo en un Movimiento Z."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255  // movimiento Z exclusivo
    },

    [ITEM_MIMIKIUM_Z] =
    {
        .name = _("Mimikyustal Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING("Mejora el movimiento Carantoña de Mimikyu\n"
                                       "convirtiéndolo en un Movimiento Z."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255  // movimiento Z exclusivo
    },

    [ITEM_KOMMONIUM_Z] =
    {
        .name = _("Kommostal Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING("Mejora las movimientos de tipo Dragón\n"
                                       "de Kommo-o convirtiéndolos en movimientos Z."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255  // movimiento Z exclusivo
    },

    [ITEM_TAPUNIUM_Z] =
    {
        .name = _("Tapistal Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING("Mejora el movimiento de los tapus,\n"
                                       "Locura Natural, convirtiéndolo en un movimiento Z."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255  // movimiento Z exclusivo
    },

    [ITEM_SOLGANIUM_Z] =
    {
        .name = _("Solgastal Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING("Mejora el movimiento de Solgaleo,\n"
                                       "Golpe Solar, convirtiéndolo en un movimiento Z."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255  // movimiento Z exclusivo
    },

    [ITEM_LUNALIUM_Z] =
    {
        .name = _("Lunalastal Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING("Mejora el movimiento de Lunala,\n"
                                       "Rayo Umbrío, convirtiéndolo en un movimiento Z."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255  // movimiento Z exclusivo
    },

    [ITEM_MARSHADIUM_Z] =
    {
        .name = _("Marshastal Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING("Mejora el movimiento de Marshadow,\n"
                                       "Ladrón Espectral, convirtiéndolo en un movimiento Z."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255  // movimiento Z exclusivo
    },

    [ITEM_ALORAICHIUM_Z] =
    {
        .name = _("Alo-Raistal Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING("Mejora el movimiento de Raichu de Alola,\n"
                                       "Trueno, convirtiéndolo en un movimiento Z."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255  // movimiento Z exclusivo
    },

    [ITEM_PIKASHUNIUM_Z] =
    {
        .name = _("Ashtal Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING("Mejora el movimiento de Pikachu con gorra,\n"
                                       "Rayo, convirtiéndolo en un movimiento Z."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255  // movimiento Z exclusivo
    },

    [ITEM_ULTRANECROZIUM_Z] =
    {
        .name = _("Ultranestal Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING("Un cristal para transformar\n"
                                       "a Necrozma fusionado\n"
                                       "en una nueva forma."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255  // movimiento Z exclusivo
    },

// Species-specific Held Items

    [ITEM_LIGHT_BALL] =
    {
        .name = _("Bola luminosa"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_LIGHT_BALL,
        .description = COMPOUND_STRING("Un objeto que se lleva\n"
                                       "y aumenta el Ataque y\n"
                                       "Ataque Especial de Pikachu."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_LEEK] =
    {
        .name = _("Puerro"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_LEEK,
        .description = COMPOUND_STRING("Un objeto que se lleva\n"
                                       "y aumenta la probabilidad\n"
                                       "de golpe crítico de Farfetch'd."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
    },

    [ITEM_THICK_CLUB] =
    {
        .name = _("Hueso grueso"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_THICK_CLUB,
        .description = COMPOUND_STRING("Un objeto que se lleva\n"
                                       "y aumenta el Ataque de Cubone\n"
                                       "o Marowak."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 90,
    },

    [ITEM_LUCKY_PUNCH] =
    {
        .name = _("Puño suerte"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_LUCKY_PUNCH,
        .description = COMPOUND_STRING("Un objeto que se lleva\n"
                                       "y aumenta la probabilidad\n"
                                       "de golpe crítico de Chansey."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 40,
    },

    [ITEM_METAL_POWDER] =
    {
        .name = _("P. metálico"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_METAL_POWDER,
        .description = COMPOUND_STRING("Un objeto que se lleva\n"
                                       "y aumenta la Defensa de Ditto."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_QUICK_POWDER] =
    {
        .name = _("P. veloz"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_QUICK_POWDER,
        .description = COMPOUND_STRING("Un objeto que se lleva\n"
                                       "por Ditto. Este polvo\n"
                                       "extraño aumenta la Velocidad."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_DEEP_SEA_SCALE] =
    {
        .name = _("Escama marina"),
        .price = 2000,
        .holdEffect = HOLD_EFFECT_DEEP_SEA_SCALE,
        .description = COMPOUND_STRING("Un objeto que se lleva\n"
                                       "y aumenta la Defensa Especial\n"
                                       "de Clamperl."),
        .pocket = POCKET_ITEMS,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .flingPower = 30,
    },

    [ITEM_DEEP_SEA_TOOTH] =
    {
        .name = _("Diente marino"),
        .price = 2000,
        .holdEffect = HOLD_EFFECT_DEEP_SEA_TOOTH,
        .description = COMPOUND_STRING("Un objeto que se lleva\n"
                                       "y aumenta el Ataque Especial\n"
                                       "de Clamperl."),
        .pocket = POCKET_ITEMS,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .flingPower = 90,
    },

    [ITEM_SOUL_DEW] =
    {
        .name = _("Rocío bondad"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_SOUL_DEW,
        .holdEffectParam = B_SOUL_DEW_BOOST >= GEN_7 ? 20 : 50,
        #if B_SOUL_DEW_BOOST >= GEN_7
            .description = COMPOUND_STRING("Potencia los movimientos\n"
                                           "Psíquicos y de tipo Dragón\n"
                                           "de Latios y Latias."),
        #else
            .description = COMPOUND_STRING("Objeto que se lleva: aumenta\n"
                                           "el Ataque Especial y la Defensa\n"
                                           "Especial de Latios y Latias."),
        #endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_ADAMANT_ORB] =
    {
        .name = _("Diamansfera"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_ADAMANT_ORB,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING("Aumenta el poder de\n"
                                       "los movimientos de tipo Dragón\n"
                                       "y Acero de Dialga."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
    },

    [ITEM_LUSTROUS_ORB] =
    {
        .name = _("Lustresfera"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_LUSTROUS_ORB,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING("Aumenta el poder de\n"
                                       "los movimientos de tipo Dragón\n"
                                       "y Agua de Palkia."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
    },

    [ITEM_GRISEOUS_ORB] =
    {
        .name = _("Griseosfera"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_GRISEOUS_ORB,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING("Potencia los movimientos\n"
                                       "de tipo Dragón y Fantasma\n"
                                       "de Giratina."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
    },

// Incenses

    [ITEM_SEA_INCENSE] =
    {
        .name = _("Inc. marino"),
        .price = 2000,
        .holdEffect = HOLD_EFFECT_WATER_POWER,
        .holdEffectParam = 20,
        .description = sSeaIncenseDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_LAX_INCENSE] =
    {
        .name = _("Inc. suave"),
        .price = 5000,
        .holdEffect = HOLD_EFFECT_EVASION_UP,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING("A hold item that\n"
                                       "slightly lowers the\n"
                                       "foe's accuracy."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_ODD_INCENSE] =
    {
        .name = _("Inc. raro"),
        .price = 2000,
        .holdEffect = HOLD_EFFECT_PSYCHIC_POWER,
        .holdEffectParam = 20,
        .description = sOddIncenseDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_ROCK_INCENSE] =
    {
        .name = _("Inc. roca"),
        .price = 2000,
        .holdEffect = HOLD_EFFECT_ROCK_POWER,
        .holdEffectParam = 20,
        .description = sRockIncenseDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_FULL_INCENSE] =
    {
        .name = _("Inc. lento"),
        .price = 5000,
        .holdEffect = HOLD_EFFECT_LAGGING_TAIL,
        .holdEffectParam = 5,
        .description = sFullIncenseDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_WAVE_INCENSE] =
    {
        .name = _("Inc. acua"),
        .price = 2000,
        .holdEffect = HOLD_EFFECT_WATER_POWER,
        .holdEffectParam = 20,
        .description = sSeaIncenseDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_ROSE_INCENSE] =
    {
        .name = _("Inc. floral"),
        .price = 2000,
        .holdEffect = HOLD_EFFECT_GRASS_POWER,
        .holdEffectParam = 20,
        .description = sRoseIncenseDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_LUCK_INCENSE] =
    {
        .name = _("Inc. duplo"),
        .price = 11000,
        .holdEffect = HOLD_EFFECT_DOUBLE_PRIZE,
        .description = sLuckIncenseDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_PURE_INCENSE] =
    {
        .name = _("Inc. puro"),
        .price = 6000,
        .holdEffect = HOLD_EFFECT_REPEL,
        .description = sPureIncenseDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

// Contest Scarves

    [ITEM_RED_SCARF] =
    {
        .name = _("Pañuelo rojo"),
        .price = 100,
        .description = COMPOUND_STRING("Un objeto que se lleva\n"
                                       "y aumenta el Estilo\n"
                                       "en los Concursos."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_BLUE_SCARF] =
    {
        .name = _("Pañuelo azul"),
        .price = 100,
        .description = COMPOUND_STRING("Un objeto que se lleva\n"
                                       "y aumenta la Belleza\n"
                                       "en los Concursos."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_PINK_SCARF] =
    {
        .name = _("Pañuelo rosa"),
        .price = 100,
        .description = COMPOUND_STRING("Un objeto que se lleva\n"
                                       "y aumenta la Monada\n"
                                       "en los Concursos."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_GREEN_SCARF] =
    {
        .name = _("Pañuelo verde"),
        .price = 100,
        .description = COMPOUND_STRING("Un objeto que se lleva\n"
                                       "y aumenta el Intelecto\n"
                                       "en los Concursos."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_YELLOW_SCARF] =
    {
        .name = _("Pañuelo amar"),
        .price = 100,
        .description = COMPOUND_STRING("Un objeto que se lleva\n"
                                       "y aumenta la Dureza\n"
                                       "en los Concursos."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

// EV Gain Modifiers

    [ITEM_MACHO_BRACE] =
    {
        .name = _("Brazal firme"),
        .price = 3000,
        .holdEffect = HOLD_EFFECT_MACHO_BRACE,
        .description = COMPOUND_STRING("Un objeto que se lleva\n"
                                       "y fomenta el crecimiento,\n"
                                       "pero reduce la Velocidad."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
    },

    [ITEM_POWER_WEIGHT] =
    {
        .name = _("Pesa recia"),
        .price = 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = 8,
        .description = COMPOUND_STRING("Un objeto que se lleva\n"
                                       "y fomenta el aumento de PS,\n"
                                       "pero reduce la Velocidad."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_HP,
        .flingPower = 70,
    },

    [ITEM_POWER_BRACER] =
    {
        .name = _("Brazal recio"),
        .price = 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = 8,
        .description = COMPOUND_STRING("Un objeto que se lleva\n"
                                       "y fomenta el aumento de Ataque,\n"
                                       "pero reduce la Velocidad."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_ATK,
        .flingPower = 70,
    },

    [ITEM_POWER_BELT] =
    {
        .name = _("Cinto recio"),
        .price = 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = 8,
        .description = COMPOUND_STRING("Un objeto que se lleva\n"
                                       "y fomenta el aumento de Defensa,\n"
                                       "pero reduce la Velocidad."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_DEF,
        .flingPower = 70,
    },

    [ITEM_POWER_LENS] =
    {
        .name = _("Lente recia"),
        .price = 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = 8,
        .description = COMPOUND_STRING("Objeto que se lleva y\n"
                                       "fomenta el aumento de Ataque Especial,\n"
                                       "pero reduce la Velocidad."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_SPATK,
        .flingPower = 70,
    },

    [ITEM_POWER_BAND] =
    {
        .name = _("Banda recia"),
        .price = 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = 8,
        .description = COMPOUND_STRING("Objeto que se lleva y\n"
                                       "fomenta el aumento de Defensa Especial,\n"
                                       "pero reduce la Velocidad."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_SPDEF,
        .flingPower = 70,
    },

    [ITEM_POWER_ANKLET] =
    {
        .name = _("Franja recia"),
        .price = 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = 8,
        .description = COMPOUND_STRING("Un objeto que se lleva\n"
                                       "y fomenta el aumento de Velocidad,\n"
                                       "pero reduce la Velocidad."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_SPEED,
        .flingPower = 70,
    },

// Type-boosting Held Items

    [ITEM_SILK_SCARF] =
    {
        .name = _("Pañ. Seda"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_NORMAL_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING("Un objeto que se lleva\n"
                                       "y aumenta el poder de\n"
                                       "los movimientos de tipo Normal."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_CHARCOAL] =
    {
        .name = _("Carbón"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_FIRE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING("Un objeto que se lleva\n"
                                       "y aumenta el poder de\n"
                                       "los movimientos de tipo Fuego."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_MYSTIC_WATER] =
    {
        .name = _("Agua Mística"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_WATER_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING("Un objeto que se lleva\n"
                                       "y aumenta el poder de\n"
                                       "los movimientos de tipo Agua."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_MAGNET] =
    {
        .name = _("Imán"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_ELECTRIC_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING("Un objeto que se lleva\n"
                                       "y potencia los movimientos de tipo Eléctrico."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_MIRACLE_SEED] =
    {
        .name = _("Sem. Milagro"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_GRASS_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = sRoseIncenseDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_NEVER_MELT_ICE] =
    {
        .name = _("Hielo Eterno"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_ICE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING("Un objeto que se lleva\n"
                                       "y aumenta el poder de\n"
                                       "los movimientos de tipo Hielo."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_BLACK_BELT] =
    {
        .name = _("Cinto Negro"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_FIGHTING_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING("Un objeto que se lleva\n"
                                       "y potencia los movimientos de tipo Lucha."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_POISON_BARB] =
    {
        .name = _("Púa Veneno"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_POISON_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING("Un objeto que se lleva\n"
                                       "y aumenta el poder de\n"
                                       "los movimientos de tipo Veneno."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 70,
    },

    [ITEM_SOFT_SAND] =
    {
        .name = _("Arena Fina"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_GROUND_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING("Un objeto que se lleva\n"
                                       "y aumenta el poder de\n"
                                       "los movimientos de tipo Tierra."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_SHARP_BEAK] =
    {
        .name = _("Pico Afilado"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_FLYING_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING("Un objeto que se lleva\n"
                                       "y aumenta el poder de\n"
                                       "los movimientos de tipo Volador."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 50,
    },

    [ITEM_TWISTED_SPOON] =
    {
        .name = _("C. Torcida"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PSYCHIC_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = sOddIncenseDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_SILVER_POWDER] =
    {
        .name = _("Polvo Plata"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_BUG_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING("Un objeto que se lleva\n"
                                       "y aumenta el poder de\n"
                                       "los movimientos de tipo Bicho."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_HARD_STONE] =
    {
        .name = _("Piedra Dura"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_ROCK_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = sRockIncenseDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

    [ITEM_SPELL_TAG] =
    {
        .name = _("E. Mística"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_GHOST_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING("Un objeto que se lleva\n"
                                       "y aumenta el poder de\n"
                                       "los movimientos de tipo Fantasma."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_DRAGON_FANG] =
    {
        .name = _("Colm. Dragón"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_DRAGON_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING("Un objeto que se lleva\n"
                                       "y aumenta el poder de\n"
                                       "los movimientos de tipo Dragón."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 70,
    },

    [ITEM_BLACK_GLASSES] =
    {
        .name = _("Gafas Oscuras"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_DARK_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING("Un objeto que se lleva\n"
                                       "y aumenta el poder de\n"
                                       "los movimientos de tipo Siniestro."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_METAL_COAT] =
    {
        .name = _("Abrigo Met."),
        .price = 2000,
        .holdEffect = HOLD_EFFECT_STEEL_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING("Un objeto que se lleva\n"
                                       "y aumenta el poder de\n"
                                       "los movimientos de tipo Acero."),
        .pocket = POCKET_ITEMS,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .flingPower = 30,
    },

// Choice Items

    [ITEM_CHOICE_BAND] =
    {
        .name = _("Cinta Elec."),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_CHOICE_BAND,
        .description = COMPOUND_STRING("Aumenta el poder de\n"
                                       "un movimiento, pero\n"
                                       "permite usar solo ese movimiento."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_CHOICE_SPECS] =
    {
        .name = _("Gafas Elec."),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_CHOICE_SPECS,
        .description = COMPOUND_STRING("Aumenta el Ataque\n"
                                       "Especial, pero permite\n"
                                       "usar solo un movimiento."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_CHOICE_SCARF] =
    {
        .name = _("Pañuelo Elec."),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_CHOICE_SCARF,
        .description = COMPOUND_STRING("Aumenta la Velocidad,\n"
                                       "pero permite usar solo\n"
                                       "un movimiento."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

// Status Orbs

    [ITEM_FLAME_ORB] =
    {
        .name = _("Orbe Llamas"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_FLAME_ORB,
        .description = COMPOUND_STRING("Un extraño orbe que\n"
                                       "inflige quemaduras al\n"
                                       "portador durante la batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_TOXIC_ORB] =
    {
        .name = _("Orbe Tóxico"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_TOXIC_ORB,
        .description = COMPOUND_STRING("Un extraño orbe que\n"
                                       "envenena gravemente al\n"
                                       "portador durante la batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

// Weather Rocks

    [ITEM_DAMP_ROCK] =
    {
        .name = _("Roca Lluvia"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_DAMP_ROCK,
        .description = COMPOUND_STRING("Extiende la duración\n"
                                       "de Danza Lluvia si es\n"
                                       "usado por el portador."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
    },

    [ITEM_HEAT_ROCK] =
    {
        .name = _("Roca Calor"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_HEAT_ROCK,
        .description = COMPOUND_STRING("Extiende la duración\n"
                                       "de Día Soleado si es\n"
                                       "usado por el portador."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
    },

    [ITEM_SMOOTH_ROCK] =
    {
        .name = _("Roca Suave"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_SMOOTH_ROCK,
        .description = COMPOUND_STRING("Extiende la duración\n"
                                       "de Tormenta de Arena si es\n"
                                       "usado por el portador."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_ICY_ROCK] =
    {
        .name = _("Roca Helada"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_ICY_ROCK,
        .description = COMPOUND_STRING("Extiende la duración\n"
                                       "de Granizo si es usado\n"
                                       "por el portador."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 40,
    },

// Terrain Seeds

    [ITEM_ELECTRIC_SEED] =
    {
        .name = _("Sem. Eléctro"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_SEEDS,
        .holdEffectParam = HOLD_EFFECT_PARAM_ELECTRIC_TERRAIN,
        .description = COMPOUND_STRING("Aumenta la Defensa en\n"
                                       "Terreno Eléctrico,\n"
                                       "pero solo una vez."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_PSYCHIC_SEED] =
    {
        .name = _("Sem. Psíquica"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_SEEDS,
        .holdEffectParam = HOLD_EFFECT_PARAM_PSYCHIC_TERRAIN,
        .description = COMPOUND_STRING("Aumenta la Defensa Especial en\n"
                                       "Terreno Psíquico,\n"
                                       "pero solo una vez."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_MISTY_SEED] =
    {
        .name = _("Sem. Bruma"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_SEEDS,
        .holdEffectParam = HOLD_EFFECT_PARAM_MISTY_TERRAIN,
        .description = COMPOUND_STRING("Aumenta la Defensa Especial en\n"
                                       "Terreno de Neblina,\n"
                                       "pero solo una vez."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_GRASSY_SEED] =
    {
        .name = _("Sem. Planta"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_SEEDS,
        .holdEffectParam = HOLD_EFFECT_PARAM_GRASSY_TERRAIN,
        .description = COMPOUND_STRING("Aumenta la Defensa en\n"
                                       "Terreno de Hierba,\n"
                                       "pero solo una vez."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

// Type-activated Stat Modifiers

    [ITEM_ABSORB_BULB] =
    {
        .name = _("Túberculo"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_ABSORB_BULB,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING("Aumenta el Ataque Especial si\n"
                                       "el portador es golpeado por un\n"
                                       "movimiento de tipo Agua."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_CELL_BATTERY] =
    {
        .name = _("Pila"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_CELL_BATTERY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING("Aumenta el Ataque si el\n"
                                       "portador es golpeado por un\n"
                                       "movimiento de tipo Eléctrico."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_LUMINOUS_MOSS] =
    {
        .name = _("Musgo Lum."),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_LUMINOUS_MOSS,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING("Aumenta la Defensa Especial si\n"
                                       "el portador es golpeado por un\n"
                                       "movimiento de tipo Agua."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_SNOWBALL] =
    {
        .name = _("Bola de Nieve"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_SNOWBALL,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING("Aumenta el Ataque si su\n"
                                       "portador es golpeado por un\n"
                                       "movimiento de tipo Hielo."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

// Misc. Held Items

    [ITEM_BRIGHT_POWDER] =
    {
        .name = _("Polvo Brillo"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_EVASION_UP,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING("Un objeto que al ser\n"
                                       "sostenido reduce la\n"
                                       "precisión del rival."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_WHITE_HERB] =
    {
        .name = _("Hierba Blanca"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_RESTORE_STATS,
        .description = COMPOUND_STRING("Un objeto que al ser\n"
                                       "sostenido restaura\n"
                                       "cualquier estadística\n"
                                       "bajada."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_EXP_SHARE] =
    {
        .name = _("Repartir Exp."),
        .price = 3000,
        .holdEffect = HOLD_EFFECT_EXP_SHARE,
        #if I_EXP_SHARE_ITEM >= GEN_6
            .description = COMPOUND_STRING("Este dispositivo otorga\n"
                                           "exp. a otros miembros\n"
                                           "del equipo."),
        #else
            .description = COMPOUND_STRING("Un objeto que obtiene\n"
                                           "puntos de experiencia\n"
                                           "en combates."),
        #endif
        .pocket = I_EXP_SHARE_ITEM >= GEN_6 ? POCKET_KEY_ITEMS : POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_ExpShare,
        .flingPower = 30,
    },

    [ITEM_QUICK_CLAW] =
    {
        .name = _("Garra Rápida"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_QUICK_CLAW,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING("Un objeto que, al ser\n"
                                       "sostenido, permite\n"
                                       "atacar primero en\n"
                                       "ocasiones."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_SOOTHE_BELL] =
    {
        .name = _("Campana Calma"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_FRIENDSHIP_UP,
        .description = COMPOUND_STRING("Un objeto que al ser\n"
                                       "sostenido calma\n"
                                       "espíritus y fomenta\n"
                                       "la amistad."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_MENTAL_HERB] =
    {
        .name = _("Hierba Mental"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_MENTAL_HERB,
        #if B_MENTAL_HERB >= GEN_5
            .description = COMPOUND_STRING("Despierta a Pokémon\n"
                                           "de los efectos que\n"
                                           "impiden usar movimientos."),
        #else
            .description = COMPOUND_STRING("Un objeto que, al ser\n"
                                           "sostenido, despierta\n"
                                           "a un Pokémon del\n"
                                           "enamoramiento."),
        #endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_KINGS_ROCK] =
    {
        .name = _("Piedra Rey"),
        .price = 5000,
        .holdEffect = HOLD_EFFECT_FLINCH,
        .holdEffectParam = 10,
        .description = sKingsRockDesc,
        .pocket = POCKET_ITEMS,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .flingPower = 30,
    },

    [ITEM_AMULET_COIN] =
    {
        .name = _("Mon. Amuleto"),
        .price = 10000,
        .holdEffect = HOLD_EFFECT_DOUBLE_PRIZE,
        .description = sLuckIncenseDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_CLEANSE_TAG] =
    {
        .name = _("Amuleto Puro"),
        .price = 5000,
        .holdEffect = HOLD_EFFECT_REPEL,
        .description = sPureIncenseDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_SMOKE_BALL] =
    {
        .name = _("Bola de Humo"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_CAN_ALWAYS_RUN,
        .description = COMPOUND_STRING("Un objeto que garantiza\n"
                                       "la huida de Pokémon\n"
                                       "salvajes."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_FOCUS_BAND] =
    {
        .name = _("Banda Foco"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_FOCUS_BAND,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING("Un objeto que, al ser\n"
                                       "sostenido, evita el\n"
                                       "desmayo ocasional."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_LUCKY_EGG] =
    {
        .name = _("Huevo Suerte"),
        .price = 10000,
        .holdEffect = HOLD_EFFECT_LUCKY_EGG,
        .description = COMPOUND_STRING("Un objeto que, al ser\n"
                                       "sostenido, aumenta\n"
                                       "los puntos de experiencia\n"
                                       "ganados en combate."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_SCOPE_LENS] =
    {
        .name = _("Lupa Enfoque"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_SCOPE_LENS,
        .description = COMPOUND_STRING("Un objeto que, al ser\n"
                                       "sostenido, mejora la\n"
                                       "probabilidad de\n"
                                       "impacto crítico."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_LEFTOVERS] =
    {
        .name = _("Restos"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_LEFTOVERS,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING("Un objeto que, al ser\n"
                                       "sostenido, restaura\n"
                                       "gradualmente los PS\n"
                                       "en combate."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_SHELL_BELL] =
    {
        .name = _("Cam. Concha"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_SHELL_BELL,
        .holdEffectParam = 8,
        .description = COMPOUND_STRING("Un objeto que, al ser\n"
                                       "sostenido, restaura\n"
                                       "PS al golpear al rival."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_WIDE_LENS] =
    {
        .name = _("Lente Angular"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_WIDE_LENS,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING("Una lupa que mejora\n"
                                       "la precisión de los\n"
                                       "movimientos."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_MUSCLE_BAND] =
    {
        .name = _("Banda Fuerte"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_MUSCLE_BAND,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING("Una cinta para la cabeza\n"
                                       "que aumenta el poder de\n"
                                       "los movimientos físicos."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_WISE_GLASSES] =
    {
        .name = _("Gafas Sabias"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_WISE_GLASSES,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING("Un par de gafas que\n"
                                       "aumenta el poder de los\n"
                                       "movimientos especiales."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_EXPERT_BELT] =
    {
        .name = _("Cinta Experta"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_EXPERT_BELT,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING("Un cinturón que aumenta\n"
                                       "el poder de los movimientos\n"
                                       "supereficaces."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_LIGHT_CLAY] =
    {
        .name = _("Arc. Ligera"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_LIGHT_CLAY,
        .description = COMPOUND_STRING("Extiende la duración de\n"
                                       "los movimientos de barrera\n"
                                       "usados por el portador."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_LIFE_ORB] =
    {
        .name = _("Orbe Vida"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_LIFE_ORB,
        .description = COMPOUND_STRING("Aumenta el poder de los\n"
                                       "movimientos a cambio de\n"
                                       "quitar algunos PS por turno."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_POWER_HERB] =
    {
        .name = _("Hierba Pod."),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_POWER_HERB,
        .description = COMPOUND_STRING("Permite el uso inmediato\n"
                                       "de un movimiento que carga\n"
                                       "primero."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_FOCUS_SASH] =
    {
        .name = _("Banda Enfoque"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_FOCUS_SASH,
        .description = COMPOUND_STRING("Si el portador tiene\n"
                                       "PS completos, aguanta\n"
                                       "un impacto KO con 1 PS."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_ZOOM_LENS] =
    {
        .name = _("Lupa Aum."),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_ZOOM_LENS,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING("Si el portador se mueve\n"
                                       "después del rival, aumenta\n"
                                       "la precisión."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_METRONOME] =
    {
        .name = _("Metrónomo"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_METRONOME,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING("Un objeto que, al ser sostenido,\n"
                                       "aumenta el poder de un movimiento\n"
                                       "usado consecutivamente."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_IRON_BALL] =
    {
        .name = _("Bola Férrea"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_IRON_BALL,
        .description = COMPOUND_STRING("Reduce la Velocidad y permite\n"
                                       "que los Pokémon de tipo\n"
                                       "Volador sean afectados por movimientos\n"
                                       "de tipo Tierra."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 130,
    },

    [ITEM_LAGGING_TAIL] =
    {
        .name = _("Cola Rezagada"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_LAGGING_TAIL,
        .description = sFullIncenseDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_DESTINY_KNOT] =
    {
        .name = _("Nudo Destino"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_DESTINY_KNOT,
        .description = COMPOUND_STRING("Si el portador se enamora,\n"
                                       "el rival también lo hace."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_BLACK_SLUDGE] =
    {
        .name = _("Lodo Negro"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_BLACK_SLUDGE,
        .description = COMPOUND_STRING("Restaura gradualmente los PS de\n"
                                       "los Pokémon de tipo Veneno. Daña a los\n"
                                       "demás."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_GRIP_CLAW] =
    {
        .name = _("Garra Agarre"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_GRIP_CLAW,
        .description = COMPOUND_STRING("Hace que los movimientos de\n"
                                       "sujeción usados por el portador\n"
                                       "duren 7 turnos."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 90,
    },

    [ITEM_STICKY_BARB] =
    {
        .name = _("Barba Peg."),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_STICKY_BARB,
        .description = COMPOUND_STRING("Daña al portador cada turno. Puede\n"
                                       "adherirse a los rivales."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_SHED_SHELL] =
    {
        .name = _("C. Muda"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_SHED_SHELL,
        .description = COMPOUND_STRING("Permite al portador cambiar de\n"
                                       "combate sin fallar."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_BIG_ROOT] =
    {
        .name = _("Raíz Grande"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_BIG_ROOT,
        .holdEffectParam = 30,
        .description = COMPOUND_STRING("Un objeto que, al ser sostenido,\n"
                                       "aumenta el poder de los movimientos\n"
                                       "que roban PS."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_RAZOR_CLAW] =
    {
        .name = _("Garra Afilada"),
        .price = 5000,
        .holdEffect = HOLD_EFFECT_SCOPE_LENS,
        .description = COMPOUND_STRING("Una garra enganchada que\n"
                                       "aumenta la probabilidad de\n"
                                       "golpe crítico del portador."),
        .pocket = POCKET_ITEMS,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .flingPower = 80,
    },

    [ITEM_RAZOR_FANG] =
    {
        .name = _("Colm. Afilado"),
        .price = 5000,
        .holdEffect = HOLD_EFFECT_FLINCH,
        .holdEffectParam = 10,
        .description = sKingsRockDesc,
        .pocket = POCKET_ITEMS,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .flingPower = 30,
    },

    [ITEM_EVIOLITE] =
    {
        .name = _("Eviolita"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_EVIOLITE,
        .holdEffectParam = 50,
        .description = COMPOUND_STRING("Aumenta la Defensa y Defensa Especial\n"
                                       "de los Pokémon que pueden evolucionar."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 40,
    },

    [ITEM_FLOAT_STONE] =
    {
        .name = _("Piedra Ligera"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_FLOAT_STONE,
        .description = COMPOUND_STRING("Es tan ligera que, al ser sostenida,\n"
                                       "reduce a la mitad el peso de un Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_ROCKY_HELMET] =
    {
        .name = _("Casco dentado"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_ROCKY_HELMET,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING("Lastima al oponente si lo\n"
                                       "toca su portador."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
    },

    [ITEM_AIR_BALLOON] =
    {
        .name = _("Globo helio"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_AIR_BALLOON,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING("Eleva al portador en el aire.\n"
                                       "Si es golpeado, este objeto estallará."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_RED_CARD] =
    {
        .name = _("Tarjeta roja"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_RED_CARD,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING("Cambia al oponente si le pega\n"
                                       "al portador."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_RING_TARGET] =
    {
        .name = _("Blanco"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_RING_TARGET,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING("Los movimientos que normalmente\n"
                                       "no tendrían efecto afectarán al\n"
                                       "portador."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_BINDING_BAND] =
    {
        .name = _("Banda atadura"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_BINDING_BAND,
        .description = COMPOUND_STRING("Aumenta el poder de los movimientos\n"
                                       "de sujeción cuando se lleva puesto."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_EJECT_BUTTON] =
    {
        .name = _("Botón escape"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_EJECT_BUTTON,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING("Cambia al usuario si es golpeado\n"
                                       "por el oponente."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_WEAKNESS_POLICY] =
    {
        .name = _("Seguro deb."),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_WEAKNESS_POLICY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING("Si es alcanzado por un movimiento\n"
                                       "super efectivo, aumenta Ataque y\n"
                                       "Ataque Especial."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_ASSAULT_VEST] =
    {
        .name = _("Chal. asalto"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_ASSAULT_VEST,
        .holdEffectParam = 50,
        .description = COMPOUND_STRING("Aumenta la Defensa Especial pero\n"
                                       "evita el uso de movimientos de\n"
                                       "estado."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_SAFETY_GOGGLES] =
    {
        .name = _("Gafa protec"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_SAFETY_GOGGLES,
        .description = COMPOUND_STRING("Protege contra daño del clima y\n"
                                       "movimientos en polvo."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_ADRENALINE_ORB] =
    {
        .name = _("Nerviosfera"),
        .price = 300,
        .holdEffect = HOLD_EFFECT_ADRENALINE_ORB,
        .description = COMPOUND_STRING("Aumenta la Velocidad si el usuario\n"
                                       "está intimidado, pero solo una vez."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_TERRAIN_EXTENDER] =
    {
        .name = _("Cubresuelos"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_TERRAIN_EXTENDER,
        .description = COMPOUND_STRING("Extiende la duración del\n"
                                       "terreno de combate activo."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
    },

    [ITEM_PROTECTIVE_PADS] =
    {
        .name = _("Paracontacto"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_PROTECTIVE_PADS,
        .description = COMPOUND_STRING("Protege al portador de los efectos\n"
                                       "de los movimientos de contacto."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_THROAT_SPRAY] =
    {
        .name = _("Espray bucal"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_THROAT_SPRAY,
        .description = COMPOUND_STRING("Aumenta el Ataque Especial si el\n"
                                       "portador usa un movimiento de\n"
                                       "sonido."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_EJECT_PACK] =
    {
        .name = _("Moch. escape"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_EJECT_PACK,
        .description = COMPOUND_STRING("Obliga al usuario a cambiar si\n"
                                       "sus estadísticas se ven reducidas."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 50,
    },

    [ITEM_HEAVY_DUTY_BOOTS] =
    {
        .name = _("Botas gruesas"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_HEAVY_DUTY_BOOTS,
        .description = COMPOUND_STRING("Botas que previenen los efectos de\n"
                                       "las trampas en el campo de batalla."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_BLUNDER_POLICY] =
    {
        .name = _("Seguro fallo"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_BLUNDER_POLICY,
        .description = COMPOUND_STRING("Aumenta la Velocidad si el usuario\n"
                                       "falla debido a la Precisión."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_ROOM_SERVICE] =
    {
        .name = _("Servicio raro"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_ROOM_SERVICE,
        .description = COMPOUND_STRING("Reduce la Velocidad si se activa\n"
                                       "la Sala de Trucos."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

    [ITEM_UTILITY_UMBRELLA] =
    {
        .name = _("Parasol multi"),
        .price = 4000,
        .holdEffect = HOLD_EFFECT_UTILITY_UMBRELLA,
        .description = COMPOUND_STRING("Un paraguas que protege contra\n"
                                       "los efectos del clima."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
    },

// Berries

    [ITEM_CHERI_BERRY] =
    {
        .name = _("Baya Zreza"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_CURE_PAR,
        .description = COMPOUND_STRING("Un objeto que se\n"
                                       "sostiene y cura la\n"
                                       "parálisis en combate."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .flingPower = 10,
    },

    [ITEM_CHESTO_BERRY] =
    {
        .name = _("Baya Atania"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_CURE_SLP,
        .description = COMPOUND_STRING("Un objeto que se\n"
                                       "sostiene y despierta\n"
                                       "a Pokémon en combate."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .flingPower = 10,
    },

    [ITEM_PECHA_BERRY] =
    {
        .name = _("Baya Meloc"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_CURE_PSN,
        .description = COMPOUND_STRING("Un objeto que se\n"
                                       "sostiene y cura el\n"
                                       "envenenamiento en combate."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .flingPower = 10,
    },

    [ITEM_RAWST_BERRY] =
    {
        .name = _("Baya Safre"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_CURE_BRN,
        .description = COMPOUND_STRING("Un objeto que se\n"
                                       "sostiene y cura la\n"
                                       "quemadura en combate."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .flingPower = 10,
    },

    [ITEM_ASPEAR_BERRY] =
    {
        .name = _("Baya Perasi"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_CURE_FRZ,
        .description = COMPOUND_STRING("Un objeto que se\n"
                                       "sostiene y descongela\n"
                                       "a Pokémon en combate."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .flingPower = 10,
    },

    [ITEM_LEPPA_BERRY] =
    {
        .name = _("Baya Zanama"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_RESTORE_PP,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING("Un objeto que se\n"
                                       "sostiene y restaura\n"
                                       "10 PP en combate."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU_MOVES,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = EFFECT_ITEM_RESTORE_PP,
        .flingPower = 10,
    },

    [ITEM_ORAN_BERRY] =
    {
        .name = _("Baya Aranja"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_RESTORE_HP,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING("Un objeto que se\n"
                                       "sostiene y restaura\n"
                                       "10 PS en combate."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .flingPower = 10,
    },

    [ITEM_PERSIM_BERRY] =
    {
        .name = _("Baya Caquic"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_CURE_CONFUSION,
        .description = COMPOUND_STRING("Un objeto que se\n"
                                       "sostiene y cura la\n"
                                       "confusión en combate."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .flingPower = 10,
    },

    [ITEM_LUM_BERRY] =
    {
        .name = _("Baya Ziuela"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_CURE_STATUS,
        .description = COMPOUND_STRING("Un objeto que se\n"
                                       "sostiene y cura\n"
                                       "cualquier problema de estado en combate."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .flingPower = 10,
    },

    [ITEM_SITRUS_BERRY] =
    {
        .name = _("Baya Zidra"),
        .price = 20,
        #if I_SITRUS_BERRY_HEAL >= GEN_4
            .holdEffect = HOLD_EFFECT_RESTORE_PCT_HP,
            .holdEffectParam = 25,
            .description = COMPOUND_STRING("Un objeto que se\n"
                                           "sostiene y restaura\n"
                                           "un poco de PS al usuario."),
        #else
            .holdEffect = HOLD_EFFECT_RESTORE_HP,
            .holdEffectParam = 30,
            .description = COMPOUND_STRING("Un objeto que se\n"
                                           "sostiene y restaura\n"
                                           "30 PS en combate."),
        #endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .flingPower = 10,
    },

    [ITEM_FIGY_BERRY] =
    {
        .name = _("Baya Higog"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_SPICY,
        .holdEffectParam = CONFUSE_BERRY_HEAL_FRACTION,
        .description = sFigyBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_WIKI_BERRY] =
    {
        .name = _("Baya Wiki"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_DRY,
        .holdEffectParam = CONFUSE_BERRY_HEAL_FRACTION,
        .description = sFigyBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_MAGO_BERRY] =
    {
        .name = _("Baya Ango"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_SWEET,
        .holdEffectParam = CONFUSE_BERRY_HEAL_FRACTION,
        .description = sFigyBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_AGUAV_BERRY] =
    {
        .name = _("Baya Guaya"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_BITTER,
        .holdEffectParam = CONFUSE_BERRY_HEAL_FRACTION,
        .description = sFigyBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_IAPAPA_BERRY] =
    {
        .name = _("Baya Pabaya"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_SOUR,
        .holdEffectParam = CONFUSE_BERRY_HEAL_FRACTION,
        .description = sFigyBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_RAZZ_BERRY] =
    {
        .name = _("Baya Frambu"),
        .price = 20,
        .description = COMPOUND_STRING("Ingrediente de\n"
                                       "{POKEBLOCK}. Plántala\n"
                                       "en tierra fructífera para\n"
                                       "cultivar Frambu."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_BLUK_BERRY] =
    {
        .name = _("Baya Oram"),
        .price = 20,
        .description = COMPOUND_STRING("Ingrediente de\n"
                                       "{POKEBLOCK}. Plántala\n"
                                       "en tierra fructífera para\n"
                                       "cultivar Oram."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_NANAB_BERRY] =
    {
        .name = _("Baya Latano"),
        .price = 20,
        .description = COMPOUND_STRING("Ingrediente de\n"
                                       "{POKEBLOCK}. Plántala\n"
                                       "en tierra fructífera para\n"
                                       "cultivar Latano."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_WEPEAR_BERRY] =
    {
        .name = _("Baya Peragu"),
        .price = 20,
        .description = COMPOUND_STRING("Ingrediente de\n"
                                       "{POKEBLOCK}. Plántala\n"
                                       "en tierra fructífera para\n"
                                       "cultivar Peragu."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_PINAP_BERRY] =
    {
        .name = _("Baya Pinia"),
        .price = 20,
        .description = COMPOUND_STRING("Ingrediente de\n"
                                       "{POKEBLOCK}. Plántala\n"
                                       "en tierra fructífera para\n"
                                       "cultivar Pinia."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_POMEG_BERRY] =
    {
        .name = _("Baya Grana"),
        .price = 20,
        .description = COMPOUND_STRING("Hace que un Pokémon\n"
                                       "sea amigable pero\n"
                                       "reduce los PS base."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .flingPower = 10,
    },

    [ITEM_KELPSY_BERRY] =
    {
        .name = _("Baya Algama"),
        .price = 20,
        .description = COMPOUND_STRING("Hace que un Pokémon\n"
                                       "sea amigable pero\n"
                                       "reduce el Ataque base."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .flingPower = 10,
    },

    [ITEM_QUALOT_BERRY] =
    {
        .name = _("Baya Ispero"),
        .price = 20,
        .description = COMPOUND_STRING("Hace que un Pokémon\n"
                                       "sea amigable pero\n"
                                       "reduce la Defensa base."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .flingPower = 10,
    },

    [ITEM_HONDEW_BERRY] =
    {
        .name = _("Baya Meluce"),
        .price = 20,
        .description = COMPOUND_STRING("Hace que un Pokémon sea\n"
                                       "amigable pero disminuye\n"
                                       "el At. Esp. base."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .flingPower = 10,
    },

    [ITEM_GREPA_BERRY] =
    {
        .name = _("Baya Uvav"),
        .price = 20,
        .description = COMPOUND_STRING("Hace que un Pokémon sea\n"
                                       "amigable pero disminuye\n"
                                       "la Def. Esp. base."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .flingPower = 10,
    },

    [ITEM_TAMATO_BERRY] =
    {
        .name = _("Baya Tamate"),
        .price = 20,
        .description = COMPOUND_STRING("Hace que un Pokémon sea\n"
                                       "amigable pero disminuye\n"
                                       "la Velocidad base."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .flingPower = 10,
    },

    [ITEM_CORNN_BERRY] =
    {
        .name = _("Baya Mais"),
        .price = 20,
        .description = COMPOUND_STRING("Ingrediente de {POKEBLOCK}.\n"
                                       "Plántala en tierra fructífera\n"
                                       "para hacer crecer Cornn."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_MAGOST_BERRY] =
    {
        .name = _("Baya Aostan"),
        .price = 20,
        .description = COMPOUND_STRING("Ingrediente de {POKEBLOCK}.\n"
                                       "Plántala en tierra fructífera\n"
                                       "para hacer crecer Magost."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_RABUTA_BERRY] =
    {
        .name = _("Baya Rautan"),
        .price = 20,
        .description = COMPOUND_STRING("Ingrediente de {POKEBLOCK}.\n"
                                       "Plántala en tierra fructífera\n"
                                       "para hacer crecer Rabuta."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_NOMEL_BERRY] =
    {
        .name = _("Baya Monli"),
        .price = 20,
        .description = COMPOUND_STRING("Ingrediente de {POKEBLOCK}.\n"
                                       "Plántala en tierra fructífera\n"
                                       "para hacer crecer Nomel."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_SPELON_BERRY] =
    {
        .name = _("Baya Wikano"),
        .price = 20,
        .description = COMPOUND_STRING("Ingrediente de {POKEBLOCK}.\n"
                                       "Plántala en tierra fructífera\n"
                                       "para hacer crecer Spelon."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_PAMTRE_BERRY] =
    {
        .name = _("Baya Plama"),
        .price = 20,
        .description = COMPOUND_STRING("Ingrediente de {POKEBLOCK}.\n"
                                       "Plántala en tierra fructífera\n"
                                       "para hacer crecer Pamtre."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_WATMEL_BERRY] =
    {
        .name = _("Baya Sambia"),
        .price = 20,
        .description = COMPOUND_STRING("Ingrediente de {POKEBLOCK}.\n"
                                       "Plántala en tierra fructífera\n"
                                       "para hacer crecer Watmel."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_DURIN_BERRY] =
    {
        .name = _("Baya Rudion"),
        .price = 20,
        .description = COMPOUND_STRING("Ingrediente de {POKEBLOCK}.\n"
                                       "Plántala en tierra fructífera\n"
                                       "para hacer crecer Durin."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_BELUE_BERRY] =
    {
        .name = _("Baya Andano"),
        .price = 20,
        .description = COMPOUND_STRING("Ingrediente de {POKEBLOCK}.\n"
                                       "Plántala en tierra fructífera\n"
                                       "para hacer crecer Belue."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_CHILAN_BERRY] =
    {
        .name = _("Baya Chilan"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_NORMAL,
        .description = COMPOUND_STRING("Un objeto que sostiene\n"
                                       "debilita un movimiento\n"
                                       "Normal."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_OCCA_BERRY] =
    {
        .name = _("Baya Caoca"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_FIRE,
        .description = COMPOUND_STRING("Un objeto que sostiene\n"
                                       "debilita un movimiento\n"
                                       "de Fuego si es débil a él."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_PASSHO_BERRY] =
    {
        .name = _("Baya Pasio"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_WATER,
        .description = COMPOUND_STRING("Un objeto que sostiene\n"
                                       "debilita un movimiento\n"
                                       "de Agua si es débil a él."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_WACAN_BERRY] =
    {
        .name = _("Baya Gualot"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_ELECTRIC,
        .description = COMPOUND_STRING("Un objeto que sostiene\n"
                                       "debilita un movimiento\n"
                                       "Eléctrico si es débil a él."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_RINDO_BERRY] =
    {
        .name = _("Baya Tamar"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_GRASS,
        .description = COMPOUND_STRING("Un objeto que sostiene\n"
                                       "debilita un movimiento\n"
                                       "Planta si es débil a él."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_YACHE_BERRY] =
    {
        .name = _("Baya Rimoya"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_ICE,
        .description = COMPOUND_STRING("Un objeto que sostiene\n"
                                       "debilita un movimiento\n"
                                       "de Hielo si es débil a él."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_CHOPLE_BERRY] =
    {
        .name = _("Baya Pomaro"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_FIGHTING,
        .description = COMPOUND_STRING("Un objeto que sostiene\n"
                                       "debilita un movimiento\n"
                                       "de Lucha si es débil a él."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_KEBIA_BERRY] =
    {
        .name = _("Baya Kebia"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_POISON,
        .description = COMPOUND_STRING("Un objeto que sostiene\n"
                                       "debilita un movimiento\n"
                                       "Veneno si es débil a él."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_SHUCA_BERRY] =
    {
        .name = _("Baya Acardo"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_GROUND,
        .description = COMPOUND_STRING("Un objeto que sostiene\n"
                                       "debilita un movimiento\n"
                                       "Tierra si es débil a él."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_COBA_BERRY] =
    {
        .name = _("Baya Kouba"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_FLYING,
        .description = COMPOUND_STRING("Un objeto que sostiene\n"
                                       "debilita un movimiento\n"
                                       "Volador si es débil a él."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_PAYAPA_BERRY] =
    {
        .name = _("Baya Payapa"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_PSYCHIC,
        .description = COMPOUND_STRING("Un objeto que sostiene\n"
                                       "debilita un movimiento\n"
                                       "Psíquico si es débil a él."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_TANGA_BERRY] =
    {
        .name = _("Baya Yecana"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_BUG,
        .description = COMPOUND_STRING("Un objeto que sostiene\n"
                                       "debilita un movimiento\n"
                                       "Bicho si es débil a él."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_CHARTI_BERRY] =
    {
        .name = _("Baya Alcho"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_ROCK,
        .description = COMPOUND_STRING("Un objeto que se sostiene y\n"
                                       "debilita un movimiento de\n"
                                       "Tipo Roca si es débil a él."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_KASIB_BERRY] =
    {
        .name = _("Baya Drasi"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_GHOST,
        .description = COMPOUND_STRING("Un objeto que se sostiene y\n"
                                       "debilita un movimiento de\n"
                                       "Tipo Fantasma si es débil a él."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_HABAN_BERRY] =
    {
        .name = _("Baya Anjiro"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_DRAGON,
        .description = COMPOUND_STRING("Un objeto que se sostiene y\n"
                                       "debilita un movimiento de\n"
                                       "Tipo Dragón si es débil a él."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_COLBUR_BERRY] =
    {
        .name = _("Baya Dillo"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_DARK,
        .description = COMPOUND_STRING("Un objeto que se sostiene y\n"
                                       "debilita un movimiento de\n"
                                       "Tipo Siniestro si es débil a él."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_BABIRI_BERRY] =
    {
        .name = _("Baya Baribá"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_STEEL,
        .description = COMPOUND_STRING("Un objeto que se sostiene y\n"
                                       "debilita un movimiento de\n"
                                       "Tipo Acero si es débil a él."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_ROSELI_BERRY] =
    {
        .name = _("Baya Hibis"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_FAIRY,
        .description = COMPOUND_STRING("Un objeto que se sostiene y\n"
                                       "debilita un movimiento de\n"
                                       "Tipo Hada si es débil a él."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_LIECHI_BERRY] =
    {
        .name = _("Baya Lichi"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_ATTACK_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING("Un objeto que se sostiene y\n"
                                       "aumenta el Ataque en\n"
                                       "aprietos."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_GANLON_BERRY] =
    {
        .name = _("Baya Gonlan"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_DEFENSE_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING("Un objeto que se sostiene y\n"
                                       "aumenta la Defensa en\n"
                                       "aprietos."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_SALAC_BERRY] =
    {
        .name = _("Baya Aslac"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_SPEED_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING("Un objeto que se sostiene y\n"
                                       "aumenta la Velocidad en\n"
                                       "aprietos."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_PETAYA_BERRY] =
    {
        .name = _("Baya Yapati"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_SP_ATTACK_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING("Un objeto que se sostiene y\n"
                                       "aumenta el Ataque Especial en\n"
                                       "aprietos."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_APICOT_BERRY] =
    {
        .name = _("Baya Aricoc"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_SP_DEFENSE_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING("Un objeto que se sostiene y\n"
                                       "aumenta la Defensa Especial en\n"
                                       "aprietos."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_LANSAT_BERRY] =
    {
        .name = _("Baya Zonlan"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_CRITICAL_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING("Un objeto que se sostiene y\n"
                                       "aumenta la probabilidad de\n"
                                       "golpear críticamente en aprietos."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_STARF_BERRY] =
    {
        .name = _("Baya Arabol"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_RANDOM_STAT_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING("Un objeto que se sostiene y\n"
                                       "aumenta drásticamente una\n"
                                       "estadística en aprietos."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_ENIGMA_BERRY] =
    {
        .name = _("Baya Enigma"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_ENIGMA_BERRY,
        .description = COMPOUND_STRING("Un objeto que se sostiene y\n"
                                       "cura de movimientos super\n"
                                       "efectivos."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_MICLE_BERRY] =
    {
        .name = _("Baya Lagro"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_MICLE_BERRY,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING("Cuando se sostiene, aumenta\n"
                                       "la precisión de un movimiento\n"
                                       "en aprietos."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_CUSTAP_BERRY] =
    {
        .name = _("Baya Chiri"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_CUSTAP_BERRY,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING("Permite a un Pokémon en aprietos\n"
                                       "moverse primero una vez."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_JABOCA_BERRY] =
    {
        .name = _("Baya Jaboca"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_JABOCA_BERRY,
        .description = COMPOUND_STRING("Si es golpeado por un movimiento\n"
                                       "físico, lastimará al atacante\n"
                                       "un poco."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_ROWAP_BERRY] =
    {
        .name = _("Baya Magua"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_ROWAP_BERRY,
        .description = COMPOUND_STRING("Si es golpeado por un movimiento\n"
                                       "especial, lastimará al atacante\n"
                                       "un poco."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_KEE_BERRY] =
    {
        .name = _("Baya Biglia"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_KEE_BERRY,
        .description = COMPOUND_STRING("Si es golpeado por un movimiento\n"
                                       "físico, aumentará la Defensa\n"
                                       "un poco."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_MARANGA_BERRY] =
    {
        .name = _("Baya Maranga"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_MARANGA_BERRY,
        .description = COMPOUND_STRING("Si es golpeado por un movimiento\n"
                                       "especial, aumentará la Defensa\n"
                                       "Especial un poco."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_ENIGMA_BERRY_E_READER] =
    {
        .name = _("Baya Enigma"),
        .price = 20,
        .description = COMPOUND_STRING("Ingrediente para {POKEBLOCK}.\n"
                                       "Plántala en suelo franco\n"
                                       "para cultivar un misterio."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU, // El tipo es manejado por ItemUseOutOfBattle_EnigmaBerry
        .fieldUseFunc = ItemUseOutOfBattle_EnigmaBerry,
        .battleUsage = EFFECT_ITEM_ENIGMA_BERRY_EREADER,
        .flingPower = 10,
    },

// TMs/HMs. They don't have a set flingPower, as that's handled by GetFlingPowerFromItemId.

    [ITEM_TM_FOCUS_PUNCH] =
    {
        .name = _("MT01"),
        .price = 3000,
        .description = COMPOUND_STRING("Poderoso, pero hace\n"
                                       "retroceder al usuario\n"
                                       "si es golpeado por el oponente."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_FOCUS_PUNCH,
    },

    [ITEM_TM_DRAGON_CLAW] =
    {
        .name = _("MT02"),
        .price = 3000,
        .description = COMPOUND_STRING("Engancha y corta al\n"
                                       "oponente con garras\n"
                                       "largas y afiladas."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_DRAGON_CLAW,
    },

    [ITEM_TM_WATER_PULSE] =
    {
        .name = _("MT03"),
        .price = 3000,
        .description = COMPOUND_STRING("Genera una onda\n"
                                       "ultrasónica que puede\n"
                                       "causar confusión."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_WATER_PULSE,
    },

    [ITEM_TM_CALM_MIND] =
    {
        .name = _("MT04"),
        .price = 3000,
        .description = COMPOUND_STRING("Aumenta el Ataque\n"
                                       "Especial y la Defensa\n"
                                       "Especial enfocando la mente."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_CALM_MIND,
    },

    [ITEM_TM_ROAR] =
    {
        .name = _("MT05"),
        .price = 1000,
        .description = COMPOUND_STRING("Un rugido salvaje que\n"
                                       "hace huir al oponente para\n"
                                       "dar por terminada la batalla."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_ROAR,
    },

    [ITEM_TM_TOXIC] =
    {
        .name = _("MT06"),
        .price = 3000,
        .description = COMPOUND_STRING("Envenena al oponente\n"
                                       "con una toxina que\n"
                                       "empeora gradualmente."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_TOXIC,
    },

    [ITEM_TM_HAIL] =
    {
        .name = _("MT07"),
        .price = 3000,
        .description = COMPOUND_STRING("Crea una tormenta de\n"
                                       "granizo que daña a\n"
                                       "todos los tipos excepto el Hielo."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_HAIL,
    },

    [ITEM_TM_BULK_UP] =
    {
        .name = _("MT08"),
        .price = 3000,
        .description = COMPOUND_STRING("Aumenta el volumen del\n"
                                       "cuerpo para potenciar el\n"
                                       "Ataque y la Defensa."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_BULK_UP,
    },

    [ITEM_TM_BULLET_SEED] =
    {
        .name = _("MT09"),
        .price = 3000,
        .description = COMPOUND_STRING("Dispara de 2 a 5 semillas\n"
                                       "en fila para golpear al\n"
                                       "oponente."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_BULLET_SEED,
    },

    [ITEM_TM_HIDDEN_POWER] =
    {
        .name = _("MT10"),
        .price = 3000,
        .description = COMPOUND_STRING("El poder del ataque\n"
                                       "varía entre diferentes\n"
                                       "Pokémon."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_HIDDEN_POWER,
    },

    [ITEM_TM_SUNNY_DAY] =
    {
        .name = _("MT11"),
        .price = 2000,
        .description = COMPOUND_STRING("Aumenta el poder de\n"
                                       "los movimientos de tipo\n"
                                       "Fuego durante 5 turnos."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_SUNNY_DAY,
    },

    [ITEM_TM_TAUNT] =
    {
        .name = _("MT12"),
        .price = 3000,
        .description = COMPOUND_STRING("Enfurece al oponente\n"
                                       "para que solo pueda\n"
                                       "usar movimientos de ataque."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_TAUNT,
    },

    [ITEM_TM_ICE_BEAM] =
    {
        .name = _("MT13"),
        .price = 3000,
        .description = COMPOUND_STRING("Dispara un rayo frío\n"
                                       "que puede congelar al oponente."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_ICE_BEAM,
    },

    [ITEM_TM_BLIZZARD] =
    {
        .name = _("MT14"),
        .price = 5500,
        .description = COMPOUND_STRING("Un brutal ataque de nieve\n"
                                       "y viento que puede congelar\n"
                                       "al oponente."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_BLIZZARD,
    },

    [ITEM_TM_HYPER_BEAM] =
    {
        .name = _("MT15"),
        .price = 7500,
        .description = COMPOUND_STRING("Poderoso, pero necesita\n"
                                       "recargar en el próximo turno."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_HYPER_BEAM,
    },

    [ITEM_TM_LIGHT_SCREEN] =
    {
        .name = _("MT16"),
        .price = 3000,
        .description = COMPOUND_STRING("Crea una pared de luz\n"
                                       "que reduce el daño de Ataque\n"
                                       "Especial."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_LIGHT_SCREEN,
    },

    [ITEM_TM_PROTECT] =
    {
        .name = _("MT17"),
        .price = 3000,
        .description = COMPOUND_STRING("Anula todo el daño,\n"
                                       "pero puede fallar si se\n"
                                       "usa en sucesión."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_PROTECT,
    },

    [ITEM_TM_RAIN_DANCE] =
    {
        .name = _("MT18"),
        .price = 2000,
        .description = COMPOUND_STRING("Aumenta el poder de\n"
                                       "los movimientos de tipo\n"
                                       "Agua durante 5 turnos."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_RAIN_DANCE,
    },

    [ITEM_TM_GIGA_DRAIN] =
    {
        .name = _("MT19"),
        .price = 3000,
        .description = COMPOUND_STRING("Recupera la mitad de los\n"
                                       "PS del daño que inflige."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_GIGA_DRAIN,
    },

    [ITEM_TM_SAFEGUARD] =
    {
        .name = _("MT20"),
        .price = 3000,
        .description = COMPOUND_STRING("Evita problemas de\n"
                                       "estado con un poder\n"
                                       "místico."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_SAFEGUARD,
    },

    [ITEM_TM_FRUSTRATION] =
    {
        .name = _("MT21"),
        .price = 1000,
        .description = COMPOUND_STRING("Cuanto menos te\n"
                                       "quiera el usuario, más\n"
                                       "poderoso será este movimiento."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_FRUSTRATION,
    },

    [ITEM_TM_SOLAR_BEAM] =
    {
        .name = _("MT22"),
        .price = 3000,
        .description = COMPOUND_STRING("Absorbe la luz solar en el\n"
                                       "primer turno, luego\n"
                                       "ataca en el próximo turno."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_SOLAR_BEAM,
    },

    [ITEM_TM_IRON_TAIL] =
    {
        .name = _("MT23"),
        .price = 3000,
        .description = COMPOUND_STRING("Golpea al oponente con\n"
                                       "una cola dura. Puede\n"
                                       "disminuir la Defensa."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_IRON_TAIL,
    },

    [ITEM_TM_THUNDERBOLT] =
    {
        .name = _("MT24"),
        .price = 3000,
        .description = COMPOUND_STRING("Un poderoso ataque\n"
                                       "eléctrico que puede\n"
                                       "causar parálisis."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_THUNDERBOLT,
    },

    [ITEM_TM_THUNDER] =
    {
        .name = _("MT25"),
        .price = 5500,
        .description = COMPOUND_STRING("Golpea al oponente con\n"
                                       "un rayo. Puede paralizar."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_THUNDER,
    },

    [ITEM_TM_EARTHQUAKE] =
    {
        .name = _("MT26"),
        .price = 3000,
        .description = COMPOUND_STRING("Causa un terremoto\n"
                                       "sin efecto\n"
                                       "en los enemigos voladores."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_EARTHQUAKE,
    },

    [ITEM_TM_RETURN] =
    {
        .name = _("MT27"),
        .price = 1000,
        .description = COMPOUND_STRING("Cuanto más le gustes al usuario,\n"
                                       "más poderoso será este movimiento."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_RETURN,
    },

    [ITEM_TM_DIG] =
    {
        .name = _("MT28"),
        .price = 2000,
        .description = COMPOUND_STRING("Excava bajo tierra en\n"
                                       "el primer turno y luego\n"
                                       "ataca en el siguiente."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_DIG,
    },

    [ITEM_TM_PSYCHIC] =
    {
        .name = _("MT29"),
        .price = 2000,
        .description = COMPOUND_STRING("Un poderoso ataque psíquico\n"
                                       "que puede reducir la Def. Esp."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_PSYCHIC,
    },

    [ITEM_TM_SHADOW_BALL] =
    {
        .name = _("MT30"),
        .price = 3000,
        .description = COMPOUND_STRING("Lanza una masa oscura\n"
                                       "al oponente. Puede\n"
                                       "reducir la Def. Esp."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_SHADOW_BALL,
    },

    [ITEM_TM_BRICK_BREAK] =
    {
        .name = _("MT31"),
        .price = 3000,
        .description = COMPOUND_STRING("Destruye barreras\n"
                                       "como Pantalla Luz\n"
                                       "y causa daño."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_BRICK_BREAK,
    },

    [ITEM_TM_DOUBLE_TEAM] =
    {
        .name = _("MT32"),
        .price = 2000,
        .description = COMPOUND_STRING("Crea copias ilusorias\n"
                                       "para mejorar la\n"
                                       "evasión."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_DOUBLE_TEAM,
    },

    [ITEM_TM_REFLECT] =
    {
        .name = _("MT33"),
        .price = 3000,
        .description = COMPOUND_STRING("Crea una pared de luz\n"
                                       "que debilita los\n"
                                       "ataques físicos."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_REFLECT,
    },

    [ITEM_TM_SHOCK_WAVE] =
    {
        .name = _("MT34"),
        .price = 3000,
        .description = COMPOUND_STRING("Golpea al oponente con\n"
                                       "una descarga eléctrica\n"
                                       "que nunca falla."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_SHOCK_WAVE,
    },

    [ITEM_TM_FLAMETHROWER] =
    {
        .name = _("MT35"),
        .price = 3000,
        .description = COMPOUND_STRING("Libera una corriente de\n"
                                       "fuego que puede quemar\n"
                                       "al oponente."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_FLAMETHROWER,
    },

    [ITEM_TM_SLUDGE_BOMB] =
    {
        .name = _("MT36"),
        .price = 1000,
        .description = COMPOUND_STRING("Lanza lodo al oponente.\n"
                                       "Puede envenenar al oponente."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_SLUDGE_BOMB,
    },

    [ITEM_TM_SANDSTORM] =
    {
        .name = _("MT37"),
        .price = 2000,
        .description = COMPOUND_STRING("Causa una tormenta de arena\n"
                                       "que afecta al oponente\n"
                                       "durante varios turnos."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_SANDSTORM,
    },

    [ITEM_TM_FIRE_BLAST] =
    {
        .name = _("MT38"),
        .price = 5500,
        .description = COMPOUND_STRING("Un potente ataque de fuego\n"
                                       "que puede quemar al oponente."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_FIRE_BLAST,
    },

    [ITEM_TM_ROCK_TOMB] =
    {
        .name = _("MT39"),
        .price = 3000,
        .description = COMPOUND_STRING("Detiene al oponente\n"
                                       "con rocas. Puede reducir\n"
                                       "la Velocidad."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_ROCK_TOMB,
    },

    [ITEM_TM_AERIAL_ACE] =
    {
        .name = _("MT40"),
        .price = 3000,
        .description = COMPOUND_STRING("Un ataque extremadamente\n"
                                       "rápido que no se puede evitar."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_AERIAL_ACE,
    },

    [ITEM_TM_TORMENT] =
    {
        .name = _("MT41"),
        .price = 3000,
        .description = COMPOUND_STRING("Impide al oponente\n"
                                       "usar el mismo movimiento\n"
                                       "dos veces seguidas."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_TORMENT,
    },

    [ITEM_TM_FACADE] =
    {
        .name = _("MT42"),
        .price = 3000,
        .description = COMPOUND_STRING("Aumenta el Ataque cuando\n"
                                       "el usuario está envenenado,\n"
                                       "quemado o paralizado."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_FACADE,
    },

    [ITEM_TM_SECRET_POWER] =
    {
        .name = _("MT43"),
        .price = 3000,
        .description = COMPOUND_STRING("Añade un efecto al\n"
                                       "ataque dependiendo\n"
                                       "de la ubicación."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_SECRET_POWER,
    },

    [ITEM_TM_REST] =
    {
        .name = _("MT44"),
        .price = 3000,
        .description = COMPOUND_STRING("El usuario duerme\n"
                                       "durante 2 turnos para\n"
                                       "restaurar salud y estado."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_REST,
    },

    [ITEM_TM_ATTRACT] =
    {
        .name = _("MT45"),
        .price = 3000,
        .description = COMPOUND_STRING("Dificulta atacar a un\n"
                                       "enemigo del género\n"
                                       "opuesto."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_ATTRACT,
    },

    [ITEM_TM_THIEF] =
    {
        .name = _("MT46"),
        .price = 3000,
        .description = COMPOUND_STRING("Mientras ataca,\n"
                                       "puede robar el objeto\n"
                                       "sostenido por el oponente."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_THIEF,
    },

    [ITEM_TM_STEEL_WING] =
    {
        .name = _("MT47"),
        .price = 3000,
        .description = COMPOUND_STRING("Despliega alas afiladas\n"
                                       "y golpea al oponente."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_STEEL_WING,
    },

    [ITEM_TM_SKILL_SWAP] =
    {
        .name = _("MT48"),
        .price = 3000,
        .description = COMPOUND_STRING("Intercambia habilidades\n"
                                       "con el oponente en el\n"
                                       "turno en que se usa."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_SKILL_SWAP,
    },

    [ITEM_TM_SNATCH] =
    {
        .name = _("MT49"),
        .price = 3000,
        .description = COMPOUND_STRING("Roba los efectos\n"
                                       "del movimiento que el\n"
                                       "enemigo está intentando usar."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_SNATCH,
    },

    [ITEM_TM_OVERHEAT] =
    {
        .name = _("MT50"),
        .price = 3000,
        .description = COMPOUND_STRING("Permite un ataque\n"
                                       "a plena potencia, pero reduce\n"
                                       "drásticamente la Atq. Esp."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_OVERHEAT,
    },

    [ITEM_TM51] =
    {
        .name = _("MT51"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM52] =
    {
        .name = _("MT52"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM53] =
    {
        .name = _("MT53"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM54] =
    {
        .name = _("MT54"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM55] =
    {
        .name = _("MT55"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM56] =
    {
        .name = _("MT56"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM57] =
    {
        .name = _("MT57"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM58] =
    {
        .name = _("MT58"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM59] =
    {
        .name = _("MT59"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM60] =
    {
        .name = _("MT60"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM61] =
    {
        .name = _("MT61"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM62] =
    {
        .name = _("MT62"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM63] =
    {
        .name = _("MT63"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM64] =
    {
        .name = _("MT64"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM65] =
    {
        .name = _("MT65"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM66] =
    {
        .name = _("MT66"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM67] =
    {
        .name = _("MT67"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM68] =
    {
        .name = _("MT68"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM69] =
    {
        .name = _("MT69"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM70] =
    {
        .name = _("MT70"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM71] =
    {
        .name = _("MT71"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM72] =
    {
        .name = _("MT72"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM73] =
    {
        .name = _("MT73"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM74] =
    {
        .name = _("MT74"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM75] =
    {
        .name = _("MT75"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM76] =
    {
        .name = _("MT76"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM77] =
    {
        .name = _("MT77"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM78] =
    {
        .name = _("MT78"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM79] =
    {
        .name = _("MT79"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM80] =
    {
        .name = _("MT80"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM81] =
    {
        .name = _("MT81"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM82] =
    {
        .name = _("MT82"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM83] =
    {
        .name = _("MT83"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM84] =
    {
        .name = _("MT84"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM85] =
    {
        .name = _("MT85"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM86] =
    {
        .name = _("MT86"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM87] =
    {
        .name = _("MT87"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM88] =
    {
        .name = _("MT88"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM89] =
    {
        .name = _("MT89"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM90] =
    {
        .name = _("MT90"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM91] =
    {
        .name = _("MT91"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM92] =
    {
        .name = _("MT92"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM93] =
    {
        .name = _("MT93"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM94] =
    {
        .name = _("MT94"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM95] =
    {
        .name = _("MT95"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM96] =
    {
        .name = _("MT96"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM97] =
    {
        .name = _("MT97"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM98] =
    {
        .name = _("MT98"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM99] =
    {
        .name = _("MT99"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM100] =
    {
        .name = _("MT100"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_HM_CUT] =
    {
        .name = _("MO01"),
        .price = 0,
        .description = COMPOUND_STRING("Ataca al enemigo\n"
                                       "con cuchillas o garras\n"
                                       "afiladas."),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_CUT,
    },

    [ITEM_HM_FLY] =
    {
        .name = _("MO02"),
        .price = 0,
        .description = COMPOUND_STRING("Vuela en el\n"
                                       "primer turno y luego\n"
                                       "ataca en el siguiente."),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_FLY,
    },

    [ITEM_HM_SURF] =
    {
        .name = _("MO03"),
        .price = 0,
        .description = COMPOUND_STRING("Crea una enorme\n"
                                       "ola y la estrella\n"
                                       "contra el enemigo."),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_SURF,
    },

    [ITEM_HM_STRENGTH] =
    {
        .name = _("MO04"),
        .price = 0,
        .description = COMPOUND_STRING("Genera un enorme\n"
                                       "poder y luego golpea\n"
                                       "al enemigo."),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_STRENGTH,
    },

    [ITEM_HM_FLASH] =
    {
        .name = _("MO05"),
        .price = 0,
        .description = COMPOUND_STRING("Libera un poderoso\n"
                                       "destello de luz que\n"
                                       "reduce la precisión."),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_FLASH,
    },

    [ITEM_HM_ROCK_SMASH] =
    {
        .name = _("MO06"),
        .price = 0,
        .description = COMPOUND_STRING("Un ataque muy fuerte\n"
                                       "que puede destrozar\n"
                                       "rocas y bajar la Defensa."),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_ROCK_SMASH,
    },

    [ITEM_HM_WATERFALL] =
    {
        .name = _("MO07"),
        .price = 0,
        .description = COMPOUND_STRING("Ataca al enemigo\n"
                                       "con suficiente fuerza\n"
                                       "como para subir cascadas."),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_WATERFALL,
    },

    [ITEM_HM_DIVE] =
    {
        .name = _("MO08"),
        .price = 0,
        .description = COMPOUND_STRING("Se sumerge bajo el\n"
                                       "agua en el primer turno\n"
                                       "y luego ataca en el siguiente."),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_DIVE,
    },


// Charms

    [ITEM_OVAL_CHARM] =
    {
        .name = _("Amuleto oval"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING("Aumenta la probabilidad\n"
                                       "de encontrar huevos\n"
                                       "en la guardería."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SHINY_CHARM] =
    {
        .name = _("Amuleto iris"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING("Un amuleto que aumentará\n"
                                       "la probabilidad de\n"
                                       "encontrar Pokémon variocolor."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_CATCHING_CHARM] =
    {
        .name = _("Amuleto cap."),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING("Un amuleto que aumenta\n"
                                       "la probabilidad de\n"
                                       "capturas críticas."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_EXP_CHARM] =
    {
        .name = _("Amuleto Exp."),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING("Un amuleto que aumenta\n"
                                       "la cantidad de Exp.\n"
                                       "ganada en combate."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Form-changing Key Items

    [ITEM_ROTOM_CATALOG] =
    {
        .name = _("Cat. Rotom"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING("Un catálogo lleno de\n"
                                       "dispositivos que le\n"
                                       "gustan a Rotom."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RotomCatalog,
    },

    [ITEM_GRACIDEA] =
    {
        .name = _("Gracídea"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING("Los ramos hechos con\n"
                                       "ella se ofrecen como\n"
                                       "símbolo de gratitud."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange,
    },

    [ITEM_REVEAL_GLASS] =
    {
        .name = _("Espejo veraz"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING("Este cristal devuelve\n"
                                       "a un Pokémon a su\n"
                                       "forma original."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange,
    },

    [ITEM_DNA_SPLICERS] =
    {
        .name = _("Punta ADN"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING("Un empalmador que fusiona\n"
                                       "a Kyurem y a un\n"
                                       "cierto Pokémon."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Fusion,
    },

    [ITEM_ZYGARDE_CUBE] =
    {
        .name = _("Arca Zygarde"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING("Un objeto para almacenar\n"
                                       "núcleos y células de Zygarde."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ZygardeCube,
    },

    [ITEM_PRISON_BOTTLE] =
    {
        .name = _("Vas. castigo"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING("Una botella usada para\n"
                                       "sellar a cierto Pokémon\n"
                                       "hace mucho tiempo."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange,
    },

    [ITEM_N_SOLARIZER] =
    {
        .name = _("Necrosol"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING("Un dispositivo para fusionar\n"
                                       "y dividir a Necrozma\n"
                                       "usando un Solgaleo."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Fusion,
    },

    [ITEM_N_LUNARIZER] =
    {
        .name = _("Necroluna"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING("Un dispositivo para fusionar\n"
                                       "y dividir a Necrozma\n"
                                       "usando un Lunala."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Fusion,
    },

    [ITEM_REINS_OF_UNITY] =
    {
        .name = _("Riendas unión"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING("Riendas que unen a\n"
                                       "Calyrex con su\n"
                                       "amado corcel."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Fusion,
    },

// Battle Mechanic Key Items

    [ITEM_MEGA_RING] =
    {
        .name = _("Mega-aro"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING("Permite a los {PKMN}\n"
                                       "que sostengan su Piedra\n"
                                       "Mega Megaevolucionar."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_Z_POWER_RING] =
    {
        .name = _("Pulsera Z"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING("Un extraño anillo\n"
                                       "que permite el uso\n"
                                       "de Movimientos Z."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DYNAMAX_BAND] =
    {
        .name = _("Maximuñequera"),
        .price = 0,
        .description = COMPOUND_STRING("Una banda que lleva una\n"
                                       "Estrella Fugaz que\n"
                                       "permite Dynamax."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Misc. Key Items

    [ITEM_BICYCLE] =
    {
        .name = _("Bicicleta"),
        .price = 0,
        .description = COMPOUND_STRING("Una bicicleta plegable\n"
                                       "más rápida que las\n"
                                       "zapatillas para correr."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MACH_BIKE] =
    {
        .name = _("Bici carreras"),
        .price = 0,
        .description = COMPOUND_STRING("Una bicicleta plegable\n"
                                       "que duplica tu\n"
                                       "velocidad o más."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Bike,
        .secondaryId = MACH_BIKE,
    },

    [ITEM_ACRO_BIKE] =
    {
        .name = _("Bici acrób."),
        .price = 0,
        .description = COMPOUND_STRING("Una bicicleta plegable\n"
                                       "capaz de saltos y\n"
                                       "caballitos."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Bike,
        .secondaryId = ACRO_BIKE,
    },

    [ITEM_OLD_ROD] =
    {
        .name = _("Caña vieja"),
        .price = 0,
        .description = COMPOUND_STRING("Se usa en cualquier cuerpo\n"
                                       "de agua para pescar\n"
                                       "Pokémon salvajes."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
        .secondaryId = OLD_ROD,
    },

    [ITEM_GOOD_ROD] =
    {
        .name = _("Caña buena"),
        .price = 0,
        .description = COMPOUND_STRING("Una caña de pescar\n"
                                       "decente para atrapar\n"
                                       "Pokémon salvajes."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
        .secondaryId = GOOD_ROD,
    },

    [ITEM_SUPER_ROD] =
    {
        .name = _("Super caña"),
        .price = 0,
        .description = COMPOUND_STRING("La mejor caña de pescar\n"
                                       "para atrapar Pokémon\n"
                                       "salvajes."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
        .secondaryId = SUPER_ROD,
    },

    [ITEM_DOWSING_MACHINE] =
    {
        .name = _("Zahorí"),
        .price = 0,
        .description = COMPOUND_STRING("Un dispositivo que\n"
                                       "indica un objeto\n"
                                       "invisible mediante sonido."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Itemfinder,
    },

    [ITEM_TOWN_MAP] =
    {
        .name = _("Mapa"),
        .price = 0,
        .description = COMPOUND_STRING("Se puede ver en\n"
                                       "cualquier momento.\n"
                                       "Muestra tu ubicación actual."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_VS_SEEKER] =
    {
        .name = _("Buscapelea"),
        .price = 0,
        .description = COMPOUND_STRING("Unidad recargable\n"
                                       "que señala Entrenadores\n"
                                       "listos para la batalla."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
#if I_VS_SEEKER_CHARGING != 0
        .fieldUseFunc = FieldUseFunc_VsSeeker,
#else
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
#endif
    },

    [ITEM_TM_CASE] =
    {
        .name = _("Caja MT"),
        .price = 0,
        .description = COMPOUND_STRING("Una caja conveniente\n"
                                       "que contiene MT y MO."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BERRY_POUCH] =
    {
        .name = _("Saco bayas"),
        .price = 0,
        .description = COMPOUND_STRING("Un contenedor conveniente\n"
                                       "que guarda Bayas."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_POKEMON_BOX_LINK] =
    {
        .name = _("Caja Pokémon"),
        .price = 0,
        .description = COMPOUND_STRING("Este dispositivo otorga\n"
                                       "acceso al Sistema de\n"
                                       "Almacenamiento de {PKMN}."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Todo
    },

    [ITEM_COIN_CASE] =
    {
        .name = _("Monedero"),
        .price = 0,
        .description = COMPOUND_STRING("Una caja que guarda\n"
                                       "hasta 9,999 monedas."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CoinCase,
    },

    [ITEM_POWDER_JAR] =
    {
        .name = _("Bote polvos"),
        .price = 0,
        .description = COMPOUND_STRING("Almacena polvo de Baya\n"
                                       "hecho con una Triturabayas."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PowderJar,
    },

    [ITEM_WAILMER_PAIL] =
    {
        .name = _("Wailmegadera"),
        .price = 0,
        .description = COMPOUND_STRING("Una herramienta usada\n"
                                       "para regar Bayas y\n"
                                       "plantas."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_WailmerPail,
    },

    [ITEM_POKE_RADAR] =
    {
        .name = _("Pokéradar"),
        .price = 0,
        .description = COMPOUND_STRING("Una herramienta usada\n"
                                       "para buscar Pokémon\n"
                                       "ocultos en la hierba."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Todo
    },

    [ITEM_POKEBLOCK_CASE] =
    {
        .name = _("Tubo pokéc."),
        .price = 0,
        .description = COMPOUND_STRING("Un estuche para guardar\n"
                                       "{POKEBLOCK}s hechos con\n"
                                       "una Mezcla de Bayas."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PBLOCK_CASE,
        .fieldUseFunc = ItemUseOutOfBattle_PokeblockCase,
    },

    [ITEM_SOOT_SACK] =
    {
        .name = _("Saco hollín"),
        .price = 0,
        .description = COMPOUND_STRING("Un saco usado para\n"
                                       "recoger y guardar\n"
                                       "ceniza volcánica."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_POKE_FLUTE] =
    {
        .name = _("Poké flauta"),
        .price = 0,
        .description = COMPOUND_STRING("Una flauta de sonido\n"
                                       "agradable que despierta\n"
                                       "a los Pokémon."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_FAME_CHECKER] =
    {
        .name = _("Memorín"),
        .price = 0,
        .description = COMPOUND_STRING("Almacena información\n"
                                       "sobre personas famosas\n"
                                       "para recordar instantáneamente."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_TEACHY_TV] =
    {
        .name = _("Poké Tele"),
        .price = 0,
        .description = COMPOUND_STRING("Un televisor sintonizado\n"
                                       "a un programa de consejos\n"
                                       "para Entrenadores."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Story Key Items

    [ITEM_SS_TICKET] =
    {
        .name = _("Ticket S.S."),
        .price = 0,
        .description = COMPOUND_STRING("El boleto necesario\n"
                                       "para navegar en un\n"
                                       "ferry."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_EON_TICKET] =
    {
        .name = _("Ticket Eon"),
        .price = 0,
        .description = COMPOUND_STRING("El boleto para un\n"
                                       "ferry hacia una isla\n"
                                       "lejana al sur."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 1,
    },

    [ITEM_MYSTIC_TICKET] =
    {
        .name = _("Ticket Mystic"),
        .price = 0,
        .description = COMPOUND_STRING("Un boleto necesario\n"
                                       "para abordar el barco\n"
                                       "a Roca Oculta."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_AURORA_TICKET] =
    {
        .name = _("Ticket Aurora"),
        .price = 0,
        .description = COMPOUND_STRING("Un boleto necesario\n"
                                       "para abordar el barco\n"
                                       "a Isla Origen."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_OLD_SEA_MAP] =
    {
        .name = _("Mapa viejo"),
        .price = 0,
        .description = COMPOUND_STRING("Un mapa marino desgastado\n"
                                       "que muestra el camino\n"
                                       "a una isla específica."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LETTER] =
    {
        .name = _("Carta"),
        .price = 0,
        .description = COMPOUND_STRING("Una carta para Steven\n"
                                       "del presidente de\n"
                                       "Devon Corp."),
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DEVON_PARTS] =
    {
        .name = _("Piezas Devon"),
        .price = 0,
        .description = COMPOUND_STRING("Un paquete que\n"
                                       "contiene las piezas\n"
                                       "mecánicas de Devon."),
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GO_GOGGLES] =
    {
        .name = _("Gafas aisl."),
        .price = 0,
        .description = COMPOUND_STRING("Gafas ingeniosas que\n"
                                       "protegen los ojos de\n"
                                       "las tormentas de arena."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DEVON_SCOPE] =
    {
        .name = _("Det. Devon"),
        .price = 0,
        .description = COMPOUND_STRING("Un dispositivo de Devon\n"
                                       "que señala cualquier\n"
                                       "Pokémon invisible."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BASEMENT_KEY] =
    {
        .name = _("Llave sótano"),
        .price = 0,
        .description = COMPOUND_STRING("La llave para el\n"
                                       "Nueva Malvalona bajo\n"
                                       "Ciudad Malvalona."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SCANNER] =
    {
        .name = _("Escáner"),
        .price = 0,
        .description = COMPOUND_STRING("Un dispositivo encontrado\n"
                                       "dentro del\n"
                                       "Barco Abandonado."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_STORAGE_KEY] =
    {
        .name = _("Llave"),
        .price = 0,
        .description = COMPOUND_STRING("La llave para el\n"
                                       "almacén dentro del\n"
                                       "Barco Abandonado."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_KEY_TO_ROOM_1] =
    {
        .name = _("Ll. hab. 1"),
        .price = 0,
        .description = sKeyToRoomDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_KEY_TO_ROOM_2] =
    {
        .name = _("Ll. hab. 2"),
        .price = 0,
        .description = sKeyToRoomDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_KEY_TO_ROOM_4] =
    {
        .name = _("Ll. hab. 4"),
        .price = 0,
        .description = sKeyToRoomDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_KEY_TO_ROOM_6] =
    {
        .name = _("Ll. hab. 6"),
        .price = 0,
        .description = sKeyToRoomDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_METEORITE] =
    {
        .name = _("Meteorito"),
        .price = 0,
        .description = COMPOUND_STRING("Un meteorito encontrado\n"
                                       "en Cascada Meteoro."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange,
    },

    [ITEM_MAGMA_EMBLEM] =
    {
        .name = _("Signo Magma"),
        .price = 0,
        .description = COMPOUND_STRING("Un objeto similar a una medalla\n"
                                       "con la misma forma que el\n"
                                       "emblema del Equipo Magma."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_CONTEST_PASS] =
    {
        .name = _("Pase concurso"),
        .price = 0,
        .description = COMPOUND_STRING("El pase necesario\n"
                                       "para participar en\n"
                                       "concursos Pokémon."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_PARCEL] =
    {
        .name = _("Correo Oak"),
        .price = 0,
        .description = COMPOUND_STRING("Un paquete para el Prof.\n"
                                       "Oak de un empleado de la\n"
                                       "tienda Pokémon."),
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SECRET_KEY] =
    {
        .name = _("Ll. secreta"),
        .price = 0,
        .description = COMPOUND_STRING("La llave de la entrada del\n"
                                       "gimnasio de Isla Canela."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BIKE_VOUCHER] =
    {
        .name = _("Bono bici"),
        .price = 0,
        .description = COMPOUND_STRING("Un vale para\n"
                                       "obtener una bicicleta\n"
                                       "en la Tienda de bicicletas."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GOLD_TEETH] =
    {
        .name = _("Dentadura oro"),
        .price = 0,
        .description = COMPOUND_STRING("Prótesis doradas perdidas\n"
                                       "por el guardián\n"
                                       "de la Zona Safari."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_CARD_KEY] =
    {
        .name = _("Ll. tarjeta"),
        .price = 0,
        .description = COMPOUND_STRING("Una llave de tipo tarjeta\n"
                                       "utilizada en la oficina de\n"
                                       "Silph Co."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LIFT_KEY] =
    {
        .name = _("Ll. ascensor"),
        .price = 0,
        .description = COMPOUND_STRING("Una llave de ascensor\n"
                                       "utilizada en el Escondite\n"
                                       "del Team Rocket."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SILPH_SCOPE] =
    {
        .name = _("Visor Silph"),
        .price = 0,
        .description = COMPOUND_STRING("El visor de Silph Co.\n"
                                       "hace que los POKéMON\n"
                                       "invisibles sean visibles."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_TRI_PASS] =
    {
        .name = _("Tri-pase"),
        .price = 0,
        .description = COMPOUND_STRING("Un pase para transbordadores\n"
                                       "entre las Islas Uno, Dos y\n"
                                       "Tres."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_RAINBOW_PASS] =
    {
        .name = _("Pase iris"),
        .price = 0,
        .description = COMPOUND_STRING("Para transbordadores que\n"
                                       "sirven a Vermilion y las\n"
                                       "Islas Sevii."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_TEA] =
    {
        .name = _("Té"),
        .price = 0,
        .description = COMPOUND_STRING("Un té refrescante preparado\n"
                                       "por una anciana."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_RUBY] =
    {
        .name = _("Rubí"),
        .price = 0,
        .description = COMPOUND_STRING("Una joya roja y exquisita que\n"
                                       "brilla intensamente y simboliza\n"
                                       "la pasión."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SAPPHIRE] =
    {
        .name = _("Zafiro"),
        .price = 0,
        .description = COMPOUND_STRING("Una brillante gema azul que\n"
                                       "simboliza la honestidad."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ABILITY_SHIELD] =
    {
        .name = _("Escudo hab."),
        .price = 20000,
        .holdEffect = HOLD_EFFECT_ABILITY_SHIELD,
        .description = COMPOUND_STRING("Evita cambios de habilidad\n"
                                       "para el portador de este\n"
                                       "objeto."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_CLEAR_AMULET] =
    {
        .name = _("Amuleto puro"),
        .price = 30000,
        .holdEffect = HOLD_EFFECT_CLEAR_AMULET,
        .description = COMPOUND_STRING("Evita reducciones de estadísticas\n"
                                       "para el portador de este objeto."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_PUNCHING_GLOVE] =
    {
        .name = _("Guante boxeo"),
        .price = 15000,
        .holdEffect = HOLD_EFFECT_PUNCHING_GLOVE,
        .description = COMPOUND_STRING("Potencia los movimientos de\n"
                                       "golpeo y elimina su contacto."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_COVERT_CLOAK] =
    {
        .name = _("Capa furtiva"),
        .price = 20000,
        .holdEffect = HOLD_EFFECT_COVERT_CLOAK,
        .description = COMPOUND_STRING("Protege al portador de los\n"
                                       "efectos secundarios de los\n"
                                       "movimientos."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_LOADED_DICE] =
    {
        .name = _("Dado cargado"),
        .price = 20000,
        .holdEffect = HOLD_EFFECT_LOADED_DICE,
        .description = COMPOUND_STRING("Arroja números altos. Los\n"
                                       "ataques de varios golpes\n"
                                       "golpean más veces."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_AUSPICIOUS_ARMOR] =
    {
        .name = _("Arm. afort."),
        .price = 3000,
        .description = COMPOUND_STRING("Armadura habitada por\n"
                                       "deseos afortunados.\n"
                                       "Provoca la evolución."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .flingPower = 30,
    },

    [ITEM_BOOSTER_ENERGY] =
    {
        .name = _("E. potencia"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_BOOSTER_ENERGY,
        .description = COMPOUND_STRING("Energía encapsulada que\n"
                                       "mejora a los Pokémon con\n"
                                       "ciertas habilidades."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_BIG_BAMBOO_SHOOT] =
    {
        .name = _("Bambú grande"),
        .price = 3000,
        .description = COMPOUND_STRING("Un brote de bambú grande\n"
                                       "y raro. Mejor vendido a\n"
                                       "gourmets."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_GIMMIGHOUL_COIN] =
    {
        .name = _("M. Gimmi."),
        .price = 400,
        .description = COMPOUND_STRING("Los Gimmighoul atesoran\n"
                                       "y valoran estas curiosas\n"
                                       "monedas."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LEADERS_CREST] =
    {
        .name = _("Filo líder"),
        .price = 3000,
        .description = COMPOUND_STRING("Un fragmento de una antigua\n"
                                       "hoja de algún tipo. Sostenido\n"
                                       "por Bisharp."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MALICIOUS_ARMOR] =
    {
        .name = _("Arm. malic."),
        .price = 3000,
        .description = COMPOUND_STRING("Armadura habitada por\n"
                                       "una voluntad maliciosa.\n"
                                       "Provoca la evolución."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .flingPower = 30,
    },

    [ITEM_MIRROR_HERB] =
    {
        .name = _("Hierba espejo"),
        .price = 30000,
        .holdEffect = HOLD_EFFECT_MIRROR_HERB,
        .description = COMPOUND_STRING("Refleja los aumentos de\n"
                                       "estadísticas de un\n"
                                       "enemigo, pero solo una vez."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_SCROLL_OF_DARKNESS] =
    {
        .name = _("P. oscuro"),
        .price = 0,
        .description = COMPOUND_STRING("Un pergamino peculiar con\n"
                                       "secretos del camino oscuro."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
    },

    [ITEM_SCROLL_OF_WATERS] =
    {
        .name = _("P. aguas"),
        .price = 0,
        .description = COMPOUND_STRING("Un pergamino peculiar con\n"
                                       "secretos del camino del agua."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
    },

    [ITEM_TERA_ORB] =
    {
        .name = _("Orbe Terastal"),
        .price = 0,
        .description = COMPOUND_STRING("Las cargas de energía se\n"
                                       "pueden usar para provocar\n"
                                       "Terastalización."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_TINY_BAMBOO_SHOOT] =
    {
        .name = _("Bambú peq."),
        .price = 750,
        .description = COMPOUND_STRING("Un brote de bambú pequeño\n"
                                       "y raro. Mejor vendido a\n"
                                       "gourmets."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_BUG_TERA_SHARD] =
    {
        .name = _("T. bicho"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DARK_TERA_SHARD] =
    {
        .name = _("T. siniestro"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DRAGON_TERA_SHARD] =
    {
        .name = _("T. dragón"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ELECTRIC_TERA_SHARD] =
    {
        .name = _("T. eléc."),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_FAIRY_TERA_SHARD] =
    {
        .name = _("T. Hada"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_FIGHTING_TERA_SHARD] =
    {
        .name = _("T. lucha"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_FIRE_TERA_SHARD] =
    {
        .name = _("T. fuego"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_FLYING_TERA_SHARD] =
    {
        .name = _("T. vuelo"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GHOST_TERA_SHARD] =
    {
        .name = _("T. fant."),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GRASS_TERA_SHARD] =
    {
        .name = _("T. planta"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GROUND_TERA_SHARD] =
    {
        .name = _("T. tierra"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ICE_TERA_SHARD] =
    {
        .name = _("T. hielo"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_NORMAL_TERA_SHARD] =
    {
        .name = _("T. normal"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_POISON_TERA_SHARD] =
    {
        .name = _("T. veneno"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_PSYCHIC_TERA_SHARD] =
    {
        .name = _("T. psíquico"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ROCK_TERA_SHARD] =
    {
        .name = _("T. roca"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_STEEL_TERA_SHARD] =
    {
        .name = _("T. acero"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_WATER_TERA_SHARD] =
    {
        .name = _("T. agua"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ADAMANT_CRYSTAL] =
    {
        .name = _("C. adamantino"),
        .price = 0,
        .description = COMPOUND_STRING("Una gema grande y brillante\n"
                                       "que permite a Dialga\n"
                                       "cambiar de forma."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
    },

    [ITEM_GRISEOUS_CORE] =
    {
        .name = _("Núcleo griseo"),
        .price = 0,
        .description = COMPOUND_STRING("Una gema grande y brillante\n"
                                       "que permite a Giratina\n"
                                       "cambiar de forma."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
    },

    [ITEM_LUSTROUS_GLOBE] =
    {
        .name = _("E. lustrosa"),
        .price = 0,
        .description = COMPOUND_STRING("Una gema grande y brillante\n"
                                       "que permite a Palkia\n"
                                       "cambiar de forma."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
    },

    [ITEM_BLACK_AUGURITE] =
    {
        .name = _("Aug. negra"),
        .price = 8000,
        .description = COMPOUND_STRING("Una piedra negra que\n"
                                       "hace evolucionar a\n"
                                       "algunos Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .flingPower = 30,
    },

    [ITEM_LINKING_CORD] =
    {
        .name = _("Cordón unión"),
        .price = 8000,
        .description = COMPOUND_STRING("Un cordón misterioso\n"
                                       "que hace evolucionar a\n"
                                       "algunos Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .flingPower = 30,
    },

    [ITEM_PEAT_BLOCK] =
    {
        .name = _("Bloque turba"),
        .price = 10000,
        .description = COMPOUND_STRING("Un bloque de material\n"
                                       "que hace evolucionar a\n"
                                       "algunos Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .flingPower = 30,
    },

    [ITEM_BERSERK_GENE] =
    {
        .name = _("Gen loco"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_BERSERK_GENE,
        .description = COMPOUND_STRING("Aumenta drásticamente\n"
                                       "el Ataque, pero causa\n"
                                       "confusión duradera."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_FAIRY_FEATHER] =
    {
        .name = _("Pluma feérica"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_FAIRY_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING("Un objeto de sujeción que\n"
                                       "aumenta el poder de los\n"
                                       "movimientos de tipo Hada."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_SYRUPY_APPLE] =
    {
        .name = _("Man. melosa"),
        .price = 2200,
        .description = COMPOUND_STRING("Una manzana muy melosa\n"
                                       "que hace evolucionar a\n"
                                       "ciertos Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .flingPower = 30,
    },

    [ITEM_UNREMARKABLE_TEACUP] =
    {
        .name = _("Taza mediocre"),
        .price = 1600,
        .description = COMPOUND_STRING("Una taza agrietada que\n"
                                       "hace evolucionar a\n"
                                       "ciertos Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .flingPower = 80,
    },

    [ITEM_MASTERPIECE_TEACUP] =
    {
        .name = _("Taza exq."),
        .price = 38000,
        .description = COMPOUND_STRING("Una taza astillada que\n"
                                       "hace evolucionar a\n"
                                       "ciertos Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .flingPower = 80,
    },

    [ITEM_CORNERSTONE_MASK] =
    {
        .name = _("Másc. cim."),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MASK,
        .description = COMPOUND_STRING("Permite a Ogerpon\n"
                                       "usar el tipo Roca\n"
                                       "en combate."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ROCK,
    },

    [ITEM_WELLSPRING_MASK] =
    {
        .name = _("Másc. aguas"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MASK,
        .description = COMPOUND_STRING("Permite a Ogerpon\n"
                                       "usar el tipo Agua\n"
                                       "en combate."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
    },

    [ITEM_HEARTHFLAME_MASK] =
    {
        .name = _("Másc. hoguera"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MASK,
        .description = COMPOUND_STRING("Permite a Ogerpon\n"
                                       "usar el tipo Fuego\n"
                                       "en combate."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
    },

    [ITEM_HEALTH_MOCHI] =
    {
        .name = _("Mochi vigor"),
        .price = 500,
        .description = sHealthFeatherDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .flingPower = 30,
    },

    [ITEM_MUSCLE_MOCHI] =
    {
        .name = _("Mochi músculo"),
        .price = 500,
        .description = sMuscleFeatherDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .flingPower = 30,
    },

    [ITEM_RESIST_MOCHI] =
    {
        .name = _("Mochi aguante"),
        .price = 500,
        .description = sResistFeatherDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .flingPower = 30,
    },

    [ITEM_GENIUS_MOCHI] =
    {
        .name = _("Mochi int."),
        .price = 500,
        .description = sGeniusFeatherDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .flingPower = 30,
    },

    [ITEM_CLEVER_MOCHI] =
    {
        .name = _("Mochi mente"),
        .price = 500,
        .description = sCleverFeatherDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .flingPower = 30,
    },

    [ITEM_SWIFT_MOCHI] =
    {
        .name = _("Mochi ímpetu"),
        .price = 500,
        .description = sSwiftFeatherDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .flingPower = 30,
    },

    [ITEM_FRESH_START_MOCHI] =
    {
        .name = _("Mochi Renacer"),
        .price = 300,
        .description = COMPOUND_STRING("Un objeto que reinicia\n"
                                       "todos los puntos base de\n"
                                       "un Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ResetEVs,
        .flingPower = 30,
    },

    [ITEM_GLIMMERING_CHARM] =
    {
        .name = _("Am. Brillante"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING("Un amuleto que eleva\n"
                                       "las fragmentos\n"
                                       "de las incursiones Tera."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_POKE_VIAL] =
    {
        .name = _("Pokévial"),
        .price = 0,
        .description = COMPOUND_STRING("Restaura los PS\n"
                                       "del equipo POKéMON."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeVial,
    },
};
