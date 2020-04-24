#ifndef __NK_SPARROW_TILE_HPP__
#define __NK_SPARROW_TILE_HPP__

#include <functional>

namespace nk::sparrow {

template < typename Tileset >
class tile;

template < typename Tileset >
auto operator == (tile< Tileset > const& a, tile< Tileset > const& b) noexcept -> bool
{
    return a.m_value == b.m_value;
}

template < typename Tileset >
auto operator != (tile< Tileset > const& a, tile< Tileset > const& b) noexcept -> bool
{
    return not (operator == (a, b));
}

template < typename Tileset >
auto operator < (tile< Tileset > const& a, tile< Tileset > const& b) noexcept -> bool
{
    return a.m_value < b.m_value;
}

template < typename Tileset >
auto operator >= (tile< Tileset > const& a, tile< Tileset > const& b) noexcept -> bool
{
    return not operator < (a, b);
}

template < typename Tileset >
auto operator > (tile< Tileset > const& a, tile< Tileset > const& b) noexcept -> bool
{
    return a.m_value > b.m_value;
}

template < typename Tileset >
auto operator <= (tile< Tileset > const& a, tile< Tileset > const& b) noexcept -> bool
{
    return not operator > (a, b);
}

template < typename Tileset >
class tile {
public:
    using value_type = typename Tileset::value;

    friend auto operator == < Tileset > (tile const& a, tile const& b) noexcept -> bool;
    friend auto operator < < Tileset > (tile const& a, tile const& b) noexcept -> bool;
    friend auto operator > < Tileset > (tile const& a, tile const& b) noexcept -> bool;

    constexpr tile(value_type const& value) noexcept
        : m_value(value)
    { }

    constexpr tile(tile const& other) noexcept
        : m_value(other.m_value)
    { }

    virtual ~tile(void) = default;

    tile& operator = (tile const& other) noexcept
    {
        m_value = other.m_value;
        return *this;
    }

private:
    value_type m_value;
};

template < typename Tileset >
using tile_cref = std::reference_wrapper< const tile< Tileset >>;

template < typename Tileset >
using tile_ref = std::reference_wrapper< tile< Tileset >>;

template < typename Tileset >
auto operator == (tile_cref< Tileset > const& a, tile_cref< Tileset > const& b) noexcept -> bool
{
    return a.get() == b.get();
}

template < typename Tileset >
auto operator == (tile_cref< Tileset > const& a, tile< Tileset > const& b) noexcept -> bool
{
    return a.get() == b;
}

template < typename Tileset >
auto operator < (tile_cref< Tileset > const& a, tile_cref< Tileset > const& b) noexcept -> bool
{
    return a.get() < b.get();
}

template < typename Tileset >
auto operator < (tile_cref< Tileset > const& a, tile< Tileset > const& b) noexcept -> bool
{
    return a.get() < b;
}

}

#endif
