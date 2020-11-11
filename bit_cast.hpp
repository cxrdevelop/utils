#ifndef BIT_CAST_HPP
#define BIT_CAST_HPP

#include <type_traits>
#include <cstring>

namespace utils {

enum Required {
    required = 0
};

template <class T, class U>
using HaveSameSize = std::enable_if_t<sizeof(T) == sizeof(U), Required>;

template <class T>
using IsDefaultConstructible = std::enable_if_t<std::is_default_constructible<T>::value, Required>;

template <class T>
using IsTriviallyCopyable = std::enable_if_t<std::is_trivially_copyable<T>::value, Required>;

template <class T, class U, class = void>
inline constexpr bool HaveSameSize_v = false;

template <class T, class U>
inline constexpr bool HaveSameSize_v<T,U,decltype(void(std::declval<HaveSameSize<T,U>>()))> = true;

template <class T, class = void>
inline constexpr bool IsDefaultConstructible_v = false;

template <class T>
inline constexpr bool IsDefaultConstructible_v<T,decltype(void(std::declval<IsDefaultConstructible<T>>()))> = true;

template <class T, class = void>
inline constexpr bool IsTriviallyCopyable_v = false;

template <class T>
inline constexpr bool IsTriviallyCopyable_v<T,decltype(void(std::declval<IsTriviallyCopyable<T>>()))> = true;

template<typename To,
         typename From>
std::enable_if_t<
HaveSameSize_v<To,From> &&
IsTriviallyCopyable_v<To> &&
IsTriviallyCopyable_v<From> &&
IsTriviallyCopyable_v<To>,
To>
bit_cast(From const &u) noexcept {
    To t; /* NRVO variable */
    std::memcpy(&t, &u, sizeof (To));
    return t;
}

}

#endif // BIT_CAST_HPP
