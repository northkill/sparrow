#ifndef __NK_SPARROW_TILE_H__
#define __NK_SPARROW_TILE_H__

namespace nk::sparrow {

class tile {
public:
    friend auto operator == (tile const& a, tile const& b) noexcept -> bool;
    friend auto operator < (tile const& a, tile const& b) noexcept -> bool;
    friend auto operator > (tile const& a, tile const& b) noexcept -> bool;

    tile(unsigned int const type, unsigned int const value) noexcept;
    tile(tile const& other) noexcept;

    tile& operator = (tile const& other) noexcept;

private:
    unsigned int m_type;
    unsigned int m_value;
};

auto operator == (tile const& a, tile const& b) noexcept -> bool;
auto operator != (tile const& a, tile const& b) noexcept -> bool;
auto operator < (tile const& a, tile const& b) noexcept -> bool;
auto operator >= (tile const& a, tile const& b) noexcept -> bool;
auto operator > (tile const& a, tile const& b) noexcept -> bool;
auto operator <= (tile const& a, tile const& b) noexcept -> bool;

}

#endif
