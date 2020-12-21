#ifndef NON_COPYABLE_H
#define NON_COPYABLE_H

namespace utils {

struct non_copyable {
    non_copyable(const non_copyable &) = delete;
    non_copyable& operator=(const non_copyable&) = delete;

protected:
    non_copyable() = default;
    ~non_copyable() = default;
};

}

#endif // CLASS_TYPES_H
