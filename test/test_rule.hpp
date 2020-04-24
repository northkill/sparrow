#ifndef __NK_SPARROW_TEST_RULE_HPP__
#define __NK_SPARROW_TEST_RULE_HPP__

#include <sparrow/rule.hpp>

#include "./test_tileset.hpp"

namespace nk::sparrow::test {

class rule : public sparrow::rule< test::rule, test::tileset > {
public:
    static constexpr std::array< wall_component, 6 > wall_components {
        std::make_tuple(tileset::a::one, 1),
        std::make_tuple(tileset::b::one, 2),
        std::make_tuple(tileset::b::two, 2),
        std::make_tuple(tileset::c::one, 3),
        std::make_tuple(tileset::c::two, 3),
        std::make_tuple(tileset::c::three, 3),
    };
};

}

#endif
