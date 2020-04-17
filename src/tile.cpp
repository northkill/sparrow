#include <sparrow/tile.h>

namespace nk::sparrow {

tile::tile(tile_type_type const type, tile_value_type const value) noexcept
    : m_type(type)
    , m_value(value)
{ }

tile::tile(tile const& other) noexcept
    : m_type(other.m_type)
    , m_value(other.m_value)
{ }

tile& tile::operator = (tile const& other) noexcept
{
    m_type = other.m_type;
    m_value = other.m_value;
    return *this;
}

auto operator == (tile const& a, tile const& b) noexcept -> bool
{
    return a.m_type == b.m_type
            and a.m_value == b.m_value;
}

auto operator != (tile const& a, tile const& b) noexcept -> bool
{
    return not (a == b);
}

}
