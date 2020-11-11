#ifndef BIT_CAST14_HPP
#define BIT_CAST14_HPP

#include <type_traits>
#include <cstring>

namespace utils14 {

enum Required {
    required = 0
};

template <class T, class U>
using HaveSameSize = std::enable_if_t<sizeof(T) == sizeof(U), Required>;

template <class T>
using IsDefaultConstructible = std::enable_if_t<std::is_default_constructible<T>::value, Required>;

template <class T>
using IsTriviallyCopyable = std::enable_if_t<std::is_trivially_copyable<T>::value, Required>;


template <class To,
          class From,
          HaveSameSize<To, From> same_size = required,
          IsDefaultConstructible<To> default_constructibe_to = required,
          IsTriviallyCopyable<From> trivially_copy_from = required,
          IsTriviallyCopyable<To> trivially_copy_to = required>
To bit_cast(const From& from) {
    To to;
    std::memcpy(&to, &from, sizeof(To));
    return to;
}
}

#endif // BIT_CAST2_HPP
