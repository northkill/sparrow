#ifndef __NK_SPARROW_TILESET_H__
#define __NK_SPARROW_TILESET_H__

#include "./util.h"

namespace nk::sparrow {

enum class tile_data_types {
    tile_type_type,
    tile_value_type,
};

using tile_type_type = util::data<
        tile_data_types,
        tile_data_types::tile_type_type >;

using tile_value_type = util::data<
        tile_data_types,
        tile_data_types::tile_value_type >;

class tile {
public:
    friend auto operator == (tile const& a, tile const& b) noexcept -> bool;
    friend auto operator != (tile const& a, tile const& b) noexcept -> bool;

    tile(tile_type_type const type, tile_value_type const value) noexcept;
    tile(tile const& other) noexcept;
    tile& operator = (tile const& other) noexcept;

private:
    tile_type_type m_type;
    tile_value_type m_value;
};

auto operator == (tile const& a, tile const& b) noexcept -> bool;
auto operator != (tile const& a, tile const& b) noexcept -> bool;

}

#endif
