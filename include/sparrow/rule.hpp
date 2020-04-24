#ifndef __NK_SPARROW_RULE_HPP__
#define __NK_SPARROW_RULE_HPP__

#include "./tile.hpp"

namespace nk::sparrow {

template < typename SubRule, typename Tileset >
class rule {
public:
    using tileset = Tileset;
    using tile_type = sparrow::tile< Tileset >;
    using wall_component = std::tuple< typename tileset::value, unsigned int >;

    static constexpr auto wall_size(void) noexcept
    {
        unsigned int count = 0;
        for (auto const& component : SubRule::wall_components)
            count += std::get<1>(component);
        return count;
    }

    rule(void) = delete;
};

}

#endif
