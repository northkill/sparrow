#ifndef __NK_SPARROW_RIICHI_RULE_HPP__
#define __NK_SPARROW_RIICHI_RULE_HPP__ 

#include "../rule.hpp"
#include "./tileset.hpp"

namespace nk::sparrow::riichi {

class rule : public sparrow::rule< riichi::rule, riichi::tileset > {
public:
    static constexpr std::array< wall_component, 37 > wall_components {
        std::make_tuple(tileset::kaze::ton, 4),
        std::make_tuple(tileset::kaze::nan, 4),
        std::make_tuple(tileset::kaze::sha, 4),
        std::make_tuple(tileset::kaze::pei, 4),
        std::make_tuple(tileset::sangen::haku, 4),
        std::make_tuple(tileset::sangen::hatsu, 4),
        std::make_tuple(tileset::sangen::chun, 4),
        std::make_tuple(tileset::pinzu::pin1, 4),
        std::make_tuple(tileset::pinzu::pin2, 4),
        std::make_tuple(tileset::pinzu::pin3, 4),
        std::make_tuple(tileset::pinzu::pin4, 4),
        std::make_tuple(tileset::pinzu::pin5, 2),
        std::make_tuple(tileset::aka_pinzu::pin5, 2),
        std::make_tuple(tileset::pinzu::pin6, 4),
        std::make_tuple(tileset::pinzu::pin7, 4),
        std::make_tuple(tileset::pinzu::pin8, 4),
        std::make_tuple(tileset::pinzu::pin9, 4),
        std::make_tuple(tileset::manzu::man1, 4),
        std::make_tuple(tileset::manzu::man2, 4),
        std::make_tuple(tileset::manzu::man3, 4),
        std::make_tuple(tileset::manzu::man4, 4),
        std::make_tuple(tileset::manzu::man5, 3),
        std::make_tuple(tileset::aka_manzu::man5, 1),
        std::make_tuple(tileset::manzu::man6, 4),
        std::make_tuple(tileset::manzu::man7, 4),
        std::make_tuple(tileset::manzu::man8, 4),
        std::make_tuple(tileset::manzu::man9, 4),
        std::make_tuple(tileset::souzu::sou1, 4),
        std::make_tuple(tileset::souzu::sou2, 4),
        std::make_tuple(tileset::souzu::sou3, 4),
        std::make_tuple(tileset::souzu::sou4, 4),
        std::make_tuple(tileset::souzu::sou5, 3),
        std::make_tuple(tileset::aka_souzu::sou5, 1),
        std::make_tuple(tileset::souzu::sou6, 4),
        std::make_tuple(tileset::souzu::sou7, 4),
        std::make_tuple(tileset::souzu::sou8, 4),
        std::make_tuple(tileset::souzu::sou9, 4),
    };
};

}

#endif
