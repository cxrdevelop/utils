
template<typename R, typename... Args>
struct FunctionTraitsBase
{
    using RetType = R;
    using ArgTypes = std::tuple<Args...>;
    static constexpr std::size_t ArgCount = sizeof...(Args);
};

template<typename F> struct FunctionTraits;

template<typename R, typename... Args>
struct FunctionTraits<R(*)(Args...)>
    : FunctionTraitsBase<R, Args...>
{
    using base = FunctionTraitsBase<R, Args...>;
    using Pointer = R(*)(Args...);

    template<std::size_t N>
    using NthArg = std::tuple_element_t<N, typename base::ArgTypes>;

    using FirstArg = NthArg<0>;
    using LastArg = NthArg<base::ArgCount - 1>;
};

template<typename R>
struct FunctionTraits<R(*)()>
    : FunctionTraitsBase<R>
{
    using Pointer = R(*)();
};
