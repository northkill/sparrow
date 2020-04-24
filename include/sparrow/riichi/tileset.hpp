#ifndef __NK_SPARROW_RIICHI_TILESET_HPP__
#define __NK_SPARROW_RIICHI_TILESET_HPP__

#include <variant>

namespace nk::sparrow::riichi {

class tileset {
public:
    enum class kaze {
        ton, nan, sha, pei,
    };

    enum class sangen {
        haku, hatsu, chun,
    };

    enum class pinzu {
        pin1, pin2, pin3, pin4, pin5, pin6, pin7, pin8, pin9,
    };

    enum class manzu {
        man1, man2, man3, man4, man5, man6, man7, man8, man9,
    };

    enum class souzu {
        sou1, sou2, sou3, sou4, sou5, sou6, sou7, sou8, sou9,
    };

    // spicy version
    enum class aka_pinzu {
        pin1, pin2, pin3, pin4, pin5, pin6, pin7, pin8, pin9,
    };

    enum class aka_manzu {
        man1, man2, man3, man4, man5, man6, man7, man8, man9,
    };

    enum class aka_souzu {
        sou1, sou2, sou3, sou4, sou5, sou6, sou7, sou8, sou9,
    };

    using value = std::variant<
        kaze, sangen, pinzu, manzu, souzu, aka_pinzu, aka_souzu, aka_manzu >;

    tileset(void) = delete;
};

}

#endif
