#ifndef __NK_SPARROW_TILE_UTIL_H__
#define __NK_SPARROW_TILE_UTIL_H__

#include <type_traits> 

namespace nk::sparrow::util {

template < typename E, E EV, typename T = unsigned int, typename = std::enable_if< std::is_fundamental_v< T >>>
class data {
public:
    using value_type = T;

    friend auto operator == (data const& a, data const& b) -> bool
    { return a.m_value == b.m_value; }

    friend auto operator != (data const& a, data const& b) -> bool
    { return not (a == b); }

    explicit data(value_type const& value) noexcept
        : m_value(value)
    { }

    data(data const& other) noexcept
        : m_value(other.m_value)
    { }

    auto operator = (data const& other) noexcept -> auto&
    {
        m_value = other.m_value;
        return *this;
    }

private:
    value_type m_value;
};

}

#endif
