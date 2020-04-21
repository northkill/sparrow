#ifndef __NK_SPARROW_TILE_UTIL_H__
#define __NK_SPARROW_TILE_UTIL_H__

#include <type_traits> 

namespace nk::sparrow::util {

template < typename E, E EV, typename T = unsigned int, typename = std::enable_if< std::is_fundamental_v< T >>>
class data {
public:
    using value_type = T;

    friend auto operator == (data const& a, data const& b) noexcept -> bool
    { return a.m_value == b.m_value; }

    friend auto operator < (data const& a, data const& b) noexcept -> bool
    { return a.m_value < b.m_value; }

    friend auto operator > (data const& a, data const& b) noexcept -> bool
    { return a.m_value > b.m_value; }

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

template < typename E, E EV, typename T >
auto operator != (data<E, EV, T> const& a, data<E, EV, T> const& b) noexcept -> bool
{ return not operator == (a, b); }

template < typename E, E EV, typename T >
auto operator >= (data<E, EV, T> const& a, data<E, EV, T> const& b) noexcept -> bool
{ return not operator < (a, b); }

template < typename E, E EV, typename T >
auto operator <= (data<E, EV, T> const& a, data<E, EV, T> const& b) noexcept -> bool
{ return not operator > (a, b); }

}

#endif
