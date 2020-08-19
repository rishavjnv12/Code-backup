#include <bits/stdc++.h>
#define zz BulkPoolAllocator
#ifndef ROBIN_HOOD_H_INCLUDED
#define ROBIN_HOOD_H_INCLUDED
#define ROBIN_HOOD_VERSION_MAJOR 3
#define ROBIN_HOOD_VERSION_MINOR 6
#define ROBIN_HOOD_VERSION_PATCH 0
#ifdef ROBIN_HOOD_LOG_ENABLED
#    include <iostream>
#    define ROBIN_HOOD_LOG(x) std::cout << __FUNCTION__ << "@" << __LINE__ << ": " << x << std::endl
#else
#    define ROBIN_HOOD_LOG(x)
#endif
#ifdef ROBIN_HOOD_TRACE_ENABLED
#    include <iostream>
#    define ROBIN_HOOD_TRACE(x) \
        std::cout << __FUNCTION__ << "@" << __LINE__ << ": " << x << std::endl
#else
#    define ROBIN_HOOD_TRACE(x)
#endif
#ifdef ROBIN_HOOD_COUNT_ENABLED
#else
#    define ROBIN_HOOD_COUNT(x)
#endif
#define ROBIN_HOOD(x) ROBIN_HOOD_PRIVATE_DEFINITION_##x()
#define ROBIN_HOOD_UNUSED(identifier)
#if SIZE_MAX == UINT32_MAX
#    define ROBIN_HOOD_PRIVATE_DEFINITION_BITNESS() 32
#elif SIZE_MAX == UINT64_MAX
#    define ROBIN_HOOD_PRIVATE_DEFINITION_BITNESS() 64
#else
#    error Unsupported bitness
#endif
#ifdef _MSC_VER
#    define ROBIN_HOOD_PRIVATE_DEFINITION_LITTLE_ENDIAN() 1
#    define ROBIN_HOOD_PRIVATE_DEFINITION_BIG_ENDIAN() 0
#else
#    define ROBIN_HOOD_PRIVATE_DEFINITION_LITTLE_ENDIAN() \
        (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__)
#    define ROBIN_HOOD_PRIVATE_DEFINITION_BIG_ENDIAN() (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
#endif
#ifdef _MSC_VER
#    define ROBIN_HOOD_PRIVATE_DEFINITION_NOINLINE() __declspec(noinline)
#else
#    define ROBIN_HOOD_PRIVATE_DEFINITION_NOINLINE() __attribute__((noinline))
#endif
#if !defined(__cpp_exceptions) && !defined(__EXCEPTIONS) && !defined(_CPPUNWIND)
#    define ROBIN_HOOD_PRIVATE_DEFINITION_HAS_EXCEPTIONS() 0
#else
#    define ROBIN_HOOD_PRIVATE_DEFINITION_HAS_EXCEPTIONS() 1
#endif
#ifdef _MSC_VER
#    if ROBIN_HOOD(BITNESS) == 32
#        define ROBIN_HOOD_PRIVATE_DEFINITION_BITSCANFORWARD() _BitScanForward
#    else
#        define ROBIN_HOOD_PRIVATE_DEFINITION_BITSCANFORWARD() _BitScanForward64
#    endif
#    include <intrin.h>
#    pragma intrinsic(ROBIN_HOOD(BITSCANFORWARD))
#    define ROBIN_HOOD_COUNT_TRAILING_ZEROES(x)                                       \
        [](size_t mask) noexcept -> int {                                             \
            unsigned long index;                                                      \
            return ROBIN_HOOD(BITSCANFORWARD)(&index, mask) ? static_cast<int>(index) \
                                                            : ROBIN_HOOD(BITNESS);    \
        }(x)
#else
#    if ROBIN_HOOD(BITNESS) == 32
#        define ROBIN_HOOD_PRIVATE_DEFINITION_CTZ() __builtin_ctzl
#        define ROBIN_HOOD_PRIVATE_DEFINITION_CLZ() __builtin_clzl
#    else
#        define ROBIN_HOOD_PRIVATE_DEFINITION_CTZ() __builtin_ctzll
#        define ROBIN_HOOD_PRIVATE_DEFINITION_CLZ() __builtin_clzll
#    endif
#    define ROBIN_HOOD_COUNT_LEADING_ZEROES(x) ((x) ? ROBIN_HOOD(CLZ)(x) : ROBIN_HOOD(BITNESS))
#    define ROBIN_HOOD_COUNT_TRAILING_ZEROES(x) ((x) ? ROBIN_HOOD(CTZ)(x) : ROBIN_HOOD(BITNESS))
#endif
#ifndef __has_cpp_attribute 
#    define __has_cpp_attribute(x) 0
#endif
#if __has_cpp_attribute(clang::fallthrough)
#    define ROBIN_HOOD_PRIVATE_DEFINITION_FALLTHROUGH() [[clang::fallthrough]]
#elif __has_cpp_attribute(gnu::fallthrough)
#    define ROBIN_HOOD_PRIVATE_DEFINITION_FALLTHROUGH() [[gnu::fallthrough]]
#else
#    define ROBIN_HOOD_PRIVATE_DEFINITION_FALLTHROUGH()
#endif
#ifdef _MSC_VER
#    define ROBIN_HOOD_LIKELY(condition) condition
#    define ROBIN_HOOD_UNLIKELY(condition) condition
#else
#    define ROBIN_HOOD_LIKELY(condition) __builtin_expect(condition, 1)
#    define ROBIN_HOOD_UNLIKELY(condition) __builtin_expect(condition, 0)
#endif
#if defined(__GNUC__) && __GNUC__ < 5
#    define ROBIN_HOOD_IS_TRIVIALLY_COPYABLE(...) __has_trivial_copy(__VA_ARGS__)
#else
#    define ROBIN_HOOD_IS_TRIVIALLY_COPYABLE(...) std::is_trivially_copyable<__VA_ARGS__>::value
#endif
#define ROBIN_HOOD_PRIVATE_DEFINITION_CXX() __cplusplus
#define ROBIN_HOOD_PRIVATE_DEFINITION_CXX98() 199711L
#define ROBIN_HOOD_PRIVATE_DEFINITION_CXX11() 201103L
#define ROBIN_HOOD_PRIVATE_DEFINITION_CXX14() 201402L
#define ROBIN_HOOD_PRIVATE_DEFINITION_CXX17() 201703L
#if ROBIN_HOOD(CXX) >= ROBIN_HOOD(CXX17)
#    define ROBIN_HOOD_PRIVATE_DEFINITION_NODISCARD() [[nodiscard]]
#else
#    define ROBIN_HOOD_PRIVATE_DEFINITION_NODISCARD()
#endif
namespace robin_hood {
#if ROBIN_HOOD(CXX) >= ROBIN_HOOD(CXX14)
#    define ROBIN_HOOD_STD std
#else
#endif
namespace detail {
#if defined(__SIZEOF_INT128__)
#    define ROBIN_HOOD_PRIVATE_DEFINITION_HAS_UMUL128() 1
#    if defined(__GNUC__) || defined(__clang__)
#        pragma GCC diagnostic push
#        pragma GCC diagnostic ignored "-Wpedantic"
using uint128_t = unsigned __int128;
#        pragma GCC diagnostic pop
#    endif
inline uint64_t umul128(uint64_t a, uint64_t b, uint64_t* high) noexcept {
    auto result = static_cast<uint128_t>(a) * static_cast<uint128_t>(b);
    *high = static_cast<uint64_t>(result >> 64U);
    return static_cast<uint64_t>(result);
}
#elif (defined(_MSC_VER) && ROBIN_HOOD(BITNESS) == 64)
#else
#endif
template <typename T>
inline T reinterpret_cast_no_cast_align_warning(void* ptr) noexcept {
    return reinterpret_cast<T>(ptr);
}
template <typename T>
inline T reinterpret_cast_no_cast_align_warning(void const* ptr) noexcept {
    return reinterpret_cast<T>(ptr);
}
template <typename E, typename... Args>
ROBIN_HOOD(NOINLINE)
#if ROBIN_HOOD(HAS_EXCEPTIONS)
void doThrow(Args&&... args) {
    
    throw E(std::forward<Args>(args)...);
}
#else
void doThrow(Args&&... ROBIN_HOOD_UNUSED(args) ) {
    abort();
}
#endif
template <typename E, typename T, typename... Args>
T* assertNotNull(T* t, Args&&... args) {
    if (ROBIN_HOOD_UNLIKELY(nullptr == t)) {
        doThrow<E>(std::forward<Args>(args)...);
    }
    return t;
}
template <typename T>
inline T unaligned_load(void const* ptr) noexcept {
    
    
    T t;
    std::memcpy(&t, ptr, sizeof(T));
    return t;
}
template <typename T, size_t MinNumAllocs = 4, size_t MaxNumAllocs = 256>
class zz {
public:
    zz() noexcept = default;
    
    zz(const zz& ROBIN_HOOD_UNUSED(o) ) noexcept
        : mHead(nullptr)
        , mListForFree(nullptr) {}
    zz(zz&& o) noexcept
        : mHead(o.mHead)
        , mListForFree(o.mListForFree) {
        o.mListForFree = nullptr;
        o.mHead = nullptr;
    }
    zz& operator=(zz&& o) noexcept {
        reset();
        mHead = o.mHead;
        mListForFree = o.mListForFree;
        o.mListForFree = nullptr;
        o.mHead = nullptr;
        return *this;
    }
    zz&
    
    operator=(const zz& ROBIN_HOOD_UNUSED(o) ) noexcept {
        
        return *this;
    }
    ~zz() noexcept {
        reset();
    }
    
    void reset() noexcept {
        while (mListForFree) {
            T* tmp = *mListForFree;
            free(mListForFree);
            mListForFree = reinterpret_cast_no_cast_align_warning<T**>(tmp);
        }
        mHead = nullptr;
    }
    
    
    
    T* allocate() {
        T* tmp = mHead;
        if (!tmp) {
            tmp = performAllocation();
        }
        mHead = *reinterpret_cast_no_cast_align_warning<T**>(tmp);
        return tmp;
    }
    
    
    
    
    void deallocate(T* obj) noexcept {
        *reinterpret_cast_no_cast_align_warning<T**>(obj) = mHead;
        mHead = obj;
    }
    
    
    
    void addOrFree(void* ptr, const size_t numBytes) noexcept {
        
        if (numBytes < ALIGNMENT + ALIGNED_SIZE) {
            
            free(ptr);
        } else {
            add(ptr, numBytes);
        }
    }
    void swap(zz<T, MinNumAllocs, MaxNumAllocs>& other) noexcept {
        using std::swap;
        swap(mHead, other.mHead);
        swap(mListForFree, other.mListForFree);
    }
private:
    
    
    
    
    ROBIN_HOOD(NODISCARD) size_t calcNumElementsToAlloc() const noexcept {
        auto tmp = mListForFree;
        size_t numAllocs = MinNumAllocs;
        while (numAllocs * 2 <= MaxNumAllocs && tmp) {
            auto x = reinterpret_cast<T***>(tmp);
            tmp = *x;
            numAllocs *= 2;
        }
        return numAllocs;
    }
    
    void add(void* ptr, const size_t numBytes) noexcept {
        const size_t numElements = (numBytes - ALIGNMENT) / ALIGNED_SIZE;
        auto data = reinterpret_cast<T**>(ptr);
        
        auto x = reinterpret_cast<T***>(data);
        *x = mListForFree;
        mListForFree = data;
        
        auto const headT =
            reinterpret_cast_no_cast_align_warning<T*>(reinterpret_cast<char*>(ptr) + ALIGNMENT);
        auto const head = reinterpret_cast<char*>(headT);
        
        for (size_t i = 0; i < numElements; ++i) {
            *reinterpret_cast_no_cast_align_warning<char**>(head + i * ALIGNED_SIZE) =
                head + (i + 1) * ALIGNED_SIZE;
        }
        
        *reinterpret_cast_no_cast_align_warning<T**>(head + (numElements - 1) * ALIGNED_SIZE) =
            mHead;
        mHead = headT;
    }
    
    
    ROBIN_HOOD(NOINLINE) T* performAllocation() {
        size_t const numElementsToAlloc = calcNumElementsToAlloc();
        
        
        size_t const bytes = ALIGNMENT + ALIGNED_SIZE * numElementsToAlloc;
        add(assertNotNull<std::bad_alloc>(malloc(bytes)), bytes);
        return mHead;
    }
    
#if ROBIN_HOOD(CXX) >= ROBIN_HOOD(CXX14)
    static constexpr size_t ALIGNMENT =
        (std::max)(std::alignment_of<T>::value, std::alignment_of<T*>::value);
#else
    static const size_t ALIGNMENT =
        (ROBIN_HOOD_STD::alignment_of<T>::value > ROBIN_HOOD_STD::alignment_of<T*>::value)
            ? ROBIN_HOOD_STD::alignment_of<T>::value
            : +ROBIN_HOOD_STD::alignment_of<T*>::value; 
#endif
    static constexpr size_t ALIGNED_SIZE = ((sizeof(T) - 1) / ALIGNMENT + 1) * ALIGNMENT;
    static_assert(MinNumAllocs >= 1, "MinNumAllocs");
    static_assert(MaxNumAllocs >= MinNumAllocs, "MaxNumAllocs");
    static_assert(ALIGNED_SIZE >= sizeof(T*), "ALIGNED_SIZE");
    static_assert(0 == (ALIGNED_SIZE % sizeof(T*)), "ALIGNED_SIZE mod");
    static_assert(ALIGNMENT >= sizeof(T*), "ALIGNMENT");
    T* mHead{nullptr};
    T** mListForFree{nullptr};
};
template <typename T, size_t MinSize, size_t MaxSize, bool IsFlat>
struct NodeAllocator;
template <typename T, size_t MinSize, size_t MaxSize>
struct NodeAllocator<T, MinSize, MaxSize, true> {
    
    void addOrFree(void* ptr, size_t ROBIN_HOOD_UNUSED(numBytes) ) noexcept {
        free(ptr);
    }
};
template <typename T, size_t MinSize, size_t MaxSize>
struct NodeAllocator<T, MinSize, MaxSize, false> : public zz<T, MinSize, MaxSize> {};
template <typename T>
struct identity_hash {
    constexpr size_t operator()(T const& obj) const noexcept {
        return static_cast<size_t>(obj);
    }
};
namespace swappable {
using std::swap;
template <typename T>
struct nothrow {
    static const bool value = noexcept(swap(std::declval<T&>(), std::declval<T&>()));
};
} 
} 
struct is_transparent_tag {};
template <typename T1, typename T2>
struct pair {
    using first_type = T1;
    using second_type = T2;
    template <typename U1 = T1, typename U2 = T2,
              typename = typename std::enable_if<std::is_default_constructible<U1>::value &&
                                                 std::is_default_constructible<U2>::value>::type>
    constexpr pair() noexcept(noexcept(U1()) && noexcept(U2()))
        : first()
        , second() {}
    
    explicit constexpr pair(std::pair<T1, T2> const& o) noexcept(
        noexcept(T1(std::declval<T1 const&>())) && noexcept(T2(std::declval<T2 const&>())))
        : first(o.first)
        , second(o.second) {}
    
    explicit constexpr pair(std::pair<T1, T2>&& o) noexcept(
        noexcept(T1(std::move(std::declval<T1&&>()))) &&
        noexcept(T2(std::move(std::declval<T2&&>()))))
        : first(std::move(o.first))
        , second(std::move(o.second)) {}
    constexpr pair(T1&& a, T2&& b) noexcept(noexcept(T1(std::move(std::declval<T1&&>()))) &&
                                            noexcept(T2(std::move(std::declval<T2&&>()))))
        : first(std::move(a))
        , second(std::move(b)) {}
    template <typename U1, typename U2>
    constexpr pair(U1&& a, U2&& b) noexcept(noexcept(T1(std::forward<U1>(std::declval<U1&&>()))) &&
                                            noexcept(T2(std::forward<U2>(std::declval<U2&&>()))))
        : first(std::forward<U1>(a))
        , second(std::forward<U2>(b)) {}
    template <typename... U1, typename... U2>
    constexpr pair(
        std::piecewise_construct_t , std::tuple<U1...> a,
        std::tuple<U2...> b) noexcept(noexcept(pair(std::declval<std::tuple<U1...>&>(),
                                                    std::declval<std::tuple<U2...>&>(),
                                                    ROBIN_HOOD_STD::index_sequence_for<U1...>(),
                                                    ROBIN_HOOD_STD::index_sequence_for<U2...>())))
        : pair(a, b, ROBIN_HOOD_STD::index_sequence_for<U1...>(),
               ROBIN_HOOD_STD::index_sequence_for<U2...>()) {}
    
    template <typename... U1, size_t... I1, typename... U2, size_t... I2>
    pair(std::tuple<U1...>& a, std::tuple<U2...>& b,
         ROBIN_HOOD_STD::index_sequence<I1...> ,
         ROBIN_HOOD_STD::index_sequence<
             I2...> ) noexcept(noexcept(T1(std::
                                                         forward<U1>(std::get<I1>(
                                                             std::declval<
                                                                 std::tuple<U1...>&>()))...)) &&
                                         noexcept(T2(std::forward<U2>(
                                             std::get<I2>(std::declval<std::tuple<U2...>&>()))...)))
        : first(std::forward<U1>(std::get<I1>(a))...)
        , second(std::forward<U2>(std::get<I2>(b))...) {
        
        
        (void)a;
        (void)b;
    }
    void swap(pair<T1, T2>& o) noexcept((detail::swappable::nothrow<T1>::value) &&
                                        (detail::swappable::nothrow<T2>::value)) {
        using std::swap;
        swap(first, o.first);
        swap(second, o.second);
    }
    T1 first;  
    T2 second; 
};
template <typename A, typename B>
inline void swap(pair<A, B>& a, pair<A, B>& b) noexcept(
    noexcept(std::declval<pair<A, B>&>().swap(std::declval<pair<A, B>&>()))) {
    a.swap(b);
}
template <typename A, typename B>
inline constexpr bool operator==(pair<A, B> const& x, pair<A, B> const& y) {
    return (x.first == y.first) && (x.second == y.second);
}
template <typename A, typename B>
inline constexpr bool operator!=(pair<A, B> const& x, pair<A, B> const& y) {
    return !(x == y);
}
template <typename A, typename B>
inline constexpr bool operator<(pair<A, B> const& x, pair<A, B> const& y) {
    return x.first < y.first || (!(y.first < x.first) && x.second < y.second);
}
template <typename A, typename B>
inline constexpr bool operator>(pair<A, B> const& x, pair<A, B> const& y) {
    return y < x;
}
template <typename A, typename B>
inline constexpr bool operator<=(pair<A, B> const& x, pair<A, B> const& y) {
    return !(x > y);
}
template <typename A, typename B>
inline constexpr bool operator>=(pair<A, B> const& x, pair<A, B> const& y) {
    return !(x < y);
}
static size_t hash_bytes(void const* ptr, size_t const len) noexcept {
    static constexpr uint64_t m = UINT64_C(0xc6a4a7935bd1e995);
    static constexpr uint64_t seed = UINT64_C(0xe17a1465);
    static constexpr unsigned int r = 47;
    auto const data64 = static_cast<uint64_t const*>(ptr);
    uint64_t h = seed ^ (len * m);
    size_t const n_blocks = len / 8;
    for (size_t i = 0; i < n_blocks; ++i) {
        auto k = detail::unaligned_load<uint64_t>(data64 + i);
        k *= m;
        k ^= k >> r;
        k *= m;
        h ^= k;
        h *= m;
    }
    auto const data8 = reinterpret_cast<uint8_t const*>(data64 + n_blocks);
    switch (len & 7U) {
    case 7:
        h ^= static_cast<uint64_t>(data8[6]) << 48U;
        ROBIN_HOOD(FALLTHROUGH); 
    case 6:
        h ^= static_cast<uint64_t>(data8[5]) << 40U;
        ROBIN_HOOD(FALLTHROUGH); 
    case 5:
        h ^= static_cast<uint64_t>(data8[4]) << 32U;
        ROBIN_HOOD(FALLTHROUGH); 
    case 4:
        h ^= static_cast<uint64_t>(data8[3]) << 24U;
        ROBIN_HOOD(FALLTHROUGH); 
    case 3:
        h ^= static_cast<uint64_t>(data8[2]) << 16U;
        ROBIN_HOOD(FALLTHROUGH); 
    case 2:
        h ^= static_cast<uint64_t>(data8[1]) << 8U;
        ROBIN_HOOD(FALLTHROUGH); 
    case 1:
        h ^= static_cast<uint64_t>(data8[0]);
        h *= m;
        ROBIN_HOOD(FALLTHROUGH); 
    default:
        break;
    }
    h ^= h >> r;
    h *= m;
    h ^= h >> r;
    return static_cast<size_t>(h);
}
inline size_t hash_int(uint64_t obj) noexcept {
#if ROBIN_HOOD(HAS_UMUL128)
    
    static constexpr uint64_t k = UINT64_C(0xde5fb9d2630458e9);
    uint64_t h;
    uint64_t l = detail::umul128(obj, k, &h);
    return h + l;
#elif ROBIN_HOOD(BITNESS) == 32
#else
#endif
}
template <typename T>
struct hash : public std::hash<T> {
    size_t operator()(T const& obj) const
        noexcept(noexcept(std::declval<std::hash<T>>().operator()(std::declval<T const&>()))) {
        
        auto result = std::hash<T>::operator()(obj);
        
        return hash_int(static_cast<uint64_t>(result));
    }
};
template <>
struct hash<std::string> {
    size_t operator()(std::string const& str) const noexcept {
        return hash_bytes(str.data(), str.size());
    }
};
template <class T>
struct hash<T*> {
    size_t operator()(T* ptr) const noexcept {
        return hash_int(reinterpret_cast<size_t>(ptr));
    }
};
#define ROBIN_HOOD_HASH_INT(T)                           \
    template <>                                          \
    struct hash<T> {                                     \
        size_t operator()(T obj) const noexcept {        \
            return hash_int(static_cast<uint64_t>(obj)); \
        }                                                \
    }
#if defined(__GNUC__) && !defined(__clang__)
#    pragma GCC diagnostic push
#    pragma GCC diagnostic ignored "-Wuseless-cast"
#endif
ROBIN_HOOD_HASH_INT(bool);
ROBIN_HOOD_HASH_INT(char);
ROBIN_HOOD_HASH_INT(signed char);
ROBIN_HOOD_HASH_INT(unsigned char);
ROBIN_HOOD_HASH_INT(char16_t);
ROBIN_HOOD_HASH_INT(char32_t);
ROBIN_HOOD_HASH_INT(wchar_t);
ROBIN_HOOD_HASH_INT(short);
ROBIN_HOOD_HASH_INT(unsigned short);
ROBIN_HOOD_HASH_INT(int);
ROBIN_HOOD_HASH_INT(unsigned int);
ROBIN_HOOD_HASH_INT(long);
ROBIN_HOOD_HASH_INT(long long);
ROBIN_HOOD_HASH_INT(unsigned long);
ROBIN_HOOD_HASH_INT(unsigned long long);
#if defined(__GNUC__) && !defined(__clang__)
#    pragma GCC diagnostic pop
#endif
namespace detail {
template <typename T>
struct WrapHash : public T {
    WrapHash() = default;
    explicit WrapHash(T const& o) noexcept(noexcept(T(std::declval<T const&>())))
        : T(o) {}
};
template <typename T>
struct WrapKeyEqual : public T {
    WrapKeyEqual() = default;
    explicit WrapKeyEqual(T const& o) noexcept(noexcept(T(std::declval<T const&>())))
        : T(o) {}
};
template <bool IsFlat, size_t MaxLoadFactor100, typename Key, typename T, typename Hash,
          typename KeyEqual>
class Table
    : public WrapHash<Hash>,
      public WrapKeyEqual<KeyEqual>,
      detail::NodeAllocator<
          typename std::conditional<
              std::is_void<T>::value, Key,
              robin_hood::pair<typename std::conditional<IsFlat, Key, Key const>::type, T>>::type,
          4, 16384, IsFlat> {
public:
    static constexpr bool is_flat = IsFlat;
    static constexpr bool is_map = !std::is_void<T>::value;
    static constexpr bool is_set = !is_map;
    using key_type = Key;
    using mapped_type = T;
    using value_type = typename std::conditional<
        is_set, Key,
        robin_hood::pair<typename std::conditional<is_flat, Key, Key const>::type, T>>::type;
    using size_type = size_t;
    using hasher = Hash;
    using key_equal = KeyEqual;
    using Self = Table<IsFlat, MaxLoadFactor100, key_type, mapped_type, hasher, key_equal>;
private:
    static_assert(MaxLoadFactor100 > 10 && MaxLoadFactor100 < 100,
                  "MaxLoadFactor100 needs to be >10 && < 100");
    using WHash = WrapHash<Hash>;
    using WKeyEqual = WrapKeyEqual<KeyEqual>;
    
    
    static constexpr size_t InitialNumElements = sizeof(uint64_t);
    static constexpr uint32_t InitialInfoNumBits = 5;
    static constexpr uint8_t InitialInfoInc = 1U << InitialInfoNumBits;
    static constexpr uint8_t InitialInfoHashShift = sizeof(size_t) * 8 - InitialInfoNumBits;
    using DataPool = detail::NodeAllocator<value_type, 4, 16384, IsFlat>;
    
    using InfoType = uint32_t;
    
    
    
    
    template <typename M, bool>
    class DataNode {};
    
    template <typename M>
    class DataNode<M, true> final {
    public:
        template <typename... Args>
        explicit DataNode(M& ROBIN_HOOD_UNUSED(map) , Args&&... args) noexcept(
            noexcept(value_type(std::forward<Args>(args)...)))
            : mData(std::forward<Args>(args)...) {}
        DataNode(M& ROBIN_HOOD_UNUSED(map) , DataNode<M, true>&& n) noexcept(
            std::is_nothrow_move_constructible<value_type>::value)
            : mData(std::move(n.mData)) {}
        
        void destroy(M& ROBIN_HOOD_UNUSED(map) ) noexcept {}
        void destroyDoNotDeallocate() noexcept {}
        value_type const* operator->() const noexcept {
            return &mData;
        }
        value_type* operator->() noexcept {
            return &mData;
        }
        const value_type& operator*() const noexcept {
            return mData;
        }
        value_type& operator*() noexcept {
            return mData;
        }
        template <typename VT = value_type>
        ROBIN_HOOD(NODISCARD)
        typename std::enable_if<is_map, typename VT::first_type&>::type getFirst() noexcept {
            return mData.first;
        }
        template <typename VT = value_type>
        ROBIN_HOOD(NODISCARD)
        typename std::enable_if<is_set, VT&>::type getFirst() noexcept {
            return mData;
        }
        template <typename VT = value_type>
        ROBIN_HOOD(NODISCARD)
        typename std::enable_if<is_map, typename VT::first_type const&>::type getFirst() const
            noexcept {
            return mData.first;
        }
        template <typename VT = value_type>
        ROBIN_HOOD(NODISCARD)
        typename std::enable_if<is_set, VT const&>::type getFirst() const noexcept {
            return mData;
        }
        template <typename MT = mapped_type>
        ROBIN_HOOD(NODISCARD)
        typename std::enable_if<is_map, MT&>::type getSecond() noexcept {
            return mData.second;
        }
        template <typename MT = mapped_type>
        ROBIN_HOOD(NODISCARD)
        typename std::enable_if<is_set, MT const&>::type getSecond() const noexcept {
            return mData.second;
        }
        void swap(DataNode<M, true>& o) noexcept(
            noexcept(std::declval<value_type>().swap(std::declval<value_type>()))) {
            mData.swap(o.mData);
        }
    private:
        value_type mData;
    };
    
    template <typename M>
    class DataNode<M, false> {
    public:
        template <typename... Args>
        explicit DataNode(M& map, Args&&... args)
            : mData(map.allocate()) {
            ::new (static_cast<void*>(mData)) value_type(std::forward<Args>(args)...);
        }
        DataNode(M& ROBIN_HOOD_UNUSED(map) , DataNode<M, false>&& n) noexcept
            : mData(std::move(n.mData)) {}
        void destroy(M& map) noexcept {
            
            mData->~value_type();
            map.deallocate(mData);
        }
        void destroyDoNotDeallocate() noexcept {
            mData->~value_type();
        }
        value_type const* operator->() const noexcept {
            return mData;
        }
        value_type* operator->() noexcept {
            return mData;
        }
        const value_type& operator*() const {
            return *mData;
        }
        value_type& operator*() {
            return *mData;
        }
        template <typename VT = value_type>
        ROBIN_HOOD(NODISCARD)
        typename std::enable_if<is_map, typename VT::first_type&>::type getFirst() noexcept {
            return mData->first;
        }
        template <typename VT = value_type>
        ROBIN_HOOD(NODISCARD)
        typename std::enable_if<is_set, VT&>::type getFirst() noexcept {
            return *mData;
        }
        template <typename VT = value_type>
        ROBIN_HOOD(NODISCARD)
        typename std::enable_if<is_map, typename VT::first_type const&>::type getFirst() const
            noexcept {
            return mData->first;
        }
        template <typename VT = value_type>
        ROBIN_HOOD(NODISCARD)
        typename std::enable_if<is_set, VT const&>::type getFirst() const noexcept {
            return *mData;
        }
        template <typename MT = mapped_type>
        ROBIN_HOOD(NODISCARD)
        typename std::enable_if<is_map, MT&>::type getSecond() noexcept {
            return mData->second;
        }
        template <typename MT = mapped_type>
        ROBIN_HOOD(NODISCARD)
        typename std::enable_if<is_map, MT const&>::type getSecond() const noexcept {
            return mData->second;
        }
        void swap(DataNode<M, false>& o) noexcept {
            using std::swap;
            swap(mData, o.mData);
        }
    private:
        value_type* mData;
    };
    using Node = DataNode<Self, IsFlat>;
    
    ROBIN_HOOD(NODISCARD) key_type const& getFirstConst(Node const& n) const noexcept {
        return n.getFirst();
    }
    
    
    ROBIN_HOOD(NODISCARD) key_type const& getFirstConst(key_type const& k) const noexcept {
        return k;
    }
    
    template <typename Q = mapped_type>
    ROBIN_HOOD(NODISCARD)
    typename std::enable_if<!std::is_void<Q>::value, key_type const&>::type
        getFirstConst(value_type const& vt) const noexcept {
        return vt.first;
    }
    
    template <typename M, bool UseMemcpy>
    struct Cloner;
    
    template <typename M>
    struct Cloner<M, true> {
        void operator()(M const& source, M& target) const {
            auto src = reinterpret_cast<char const*>(source.mKeyVals);
            auto tgt = reinterpret_cast<char*>(target.mKeyVals);
            auto const numElementsWithBuffer = target.calcNumElementsWithBuffer(target.mMask + 1);
            std::copy(src, src + target.calcNumBytesTotal(numElementsWithBuffer), tgt);
        }
    };
    template <typename M>
    struct Cloner<M, false> {
        void operator()(M const& s, M& t) const {
            auto const numElementsWithBuffer = t.calcNumElementsWithBuffer(t.mMask + 1);
            std::copy(s.mInfo, s.mInfo + t.calcNumBytesInfo(numElementsWithBuffer), t.mInfo);
            for (size_t i = 0; i < numElementsWithBuffer; ++i) {
                if (t.mInfo[i]) {
                    ::new (static_cast<void*>(t.mKeyVals + i)) Node(t, *s.mKeyVals[i]);
                }
            }
        }
    };
    
    template <typename M, bool IsFlatAndTrivial>
    struct Destroyer {};
    template <typename M>
    struct Destroyer<M, true> {
        void nodes(M& m) const noexcept {
            m.mNumElements = 0;
        }
        void nodesDoNotDeallocate(M& m) const noexcept {
            m.mNumElements = 0;
        }
    };
    template <typename M>
    struct Destroyer<M, false> {
        void nodes(M& m) const noexcept {
            m.mNumElements = 0;
            
            auto const numElementsWithBuffer = m.calcNumElementsWithBuffer(m.mMask + 1);
            for (size_t idx = 0; idx < numElementsWithBuffer; ++idx) {
                if (0 != m.mInfo[idx]) {
                    Node& n = m.mKeyVals[idx];
                    n.destroy(m);
                    n.~Node();
                }
            }
        }
        void nodesDoNotDeallocate(M& m) const noexcept {
            m.mNumElements = 0;
            
            auto const numElementsWithBuffer = m.calcNumElementsWithBuffer(m.mMask + 1);
            for (size_t idx = 0; idx < numElementsWithBuffer; ++idx) {
                if (0 != m.mInfo[idx]) {
                    Node& n = m.mKeyVals[idx];
                    n.destroyDoNotDeallocate();
                    n.~Node();
                }
            }
        }
    };
    
    struct fast_forward_tag {};
    
    template <bool IsConst>
    
    class Iter {
    private:
        using NodePtr = typename std::conditional<IsConst, Node const*, Node*>::type;
    public:
        using difference_type = std::ptrdiff_t;
        using value_type = typename Self::value_type;
        using reference = typename std::conditional<IsConst, value_type const&, value_type&>::type;
        using pointer = typename std::conditional<IsConst, value_type const*, value_type*>::type;
        using iterator_category = std::forward_iterator_tag;
        
        
        Iter() = default;
        
        
        
        template <bool OtherIsConst,
                  typename = typename std::enable_if<IsConst && !OtherIsConst>::type>
        
        Iter(Iter<OtherIsConst> const& other) noexcept
            : mKeyVals(other.mKeyVals)
            , mInfo(other.mInfo) {}
        Iter(NodePtr valPtr, uint8_t const* infoPtr) noexcept
            : mKeyVals(valPtr)
            , mInfo(infoPtr) {}
        Iter(NodePtr valPtr, uint8_t const* infoPtr,
             fast_forward_tag ROBIN_HOOD_UNUSED(tag) ) noexcept
            : mKeyVals(valPtr)
            , mInfo(infoPtr) {
            fastForward();
        }
        template <bool OtherIsConst,
                  typename = typename std::enable_if<IsConst && !OtherIsConst>::type>
        Iter& operator=(Iter<OtherIsConst> const& other) noexcept {
            mKeyVals = other.mKeyVals;
            mInfo = other.mInfo;
            return *this;
        }
        
        Iter& operator++() noexcept {
            mInfo++;
            mKeyVals++;
            fastForward();
            return *this;
        }
        reference operator*() const {
            return **mKeyVals;
        }
        pointer operator->() const {
            return &**mKeyVals;
        }
        template <bool O>
        bool operator==(Iter<O> const& o) const noexcept {
            return mKeyVals == o.mKeyVals;
        }
        template <bool O>
        bool operator!=(Iter<O> const& o) const noexcept {
            return mKeyVals != o.mKeyVals;
        }
    private:
        
        void fastForward() noexcept {
            int inc;
            do {
                auto const n = detail::unaligned_load<size_t>(mInfo);
#if ROBIN_HOOD(LITTLE_ENDIAN)
                inc = ROBIN_HOOD_COUNT_TRAILING_ZEROES(n) / 8;
#else
                inc = ROBIN_HOOD_COUNT_LEADING_ZEROES(n) / 8;
#endif
                mInfo += inc;
                mKeyVals += inc;
            } while (inc == static_cast<int>(sizeof(size_t)));
        }
        friend class Table<IsFlat, MaxLoadFactor100, key_type, mapped_type, hasher, key_equal>;
        NodePtr mKeyVals{nullptr};
        uint8_t const* mInfo{nullptr};
    };
    
    
    
    
    template <typename HashKey>
    void keyToIdx(HashKey&& key, size_t* idx, InfoType* info) const {
        
        
        
        using Mix =
            typename std::conditional<std::is_same<::robin_hood::hash<key_type>, hasher>::value,
                                      ::robin_hood::detail::identity_hash<size_t>,
                                      ::robin_hood::hash<size_t>>::type;
        *idx = Mix{}(WHash::operator()(key));
        *info = mInfoInc + static_cast<InfoType>(*idx >> za);
        *idx &= mMask;
    }
    
    void next(InfoType* info, size_t* idx) const noexcept {
        *idx = *idx + 1;
        *info += mInfoInc;
    }
    void nextWhileLess(InfoType* info, size_t* idx) const noexcept {
        
        while (*info < mInfo[*idx]) {
            next(info, idx);
        }
    }
    
    void
    shiftUp(size_t startIdx,
            size_t const insertion_idx) noexcept(std::is_nothrow_move_assignable<Node>::value) {
        auto idx = startIdx;
        ::new (static_cast<void*>(mKeyVals + idx)) Node(std::move(mKeyVals[idx - 1]));
        while (--idx != insertion_idx) {
            mKeyVals[idx] = std::move(mKeyVals[idx - 1]);
        }
        idx = startIdx;
        while (idx != insertion_idx) {
            ROBIN_HOOD_COUNT(shiftUp);
            mInfo[idx] = static_cast<uint8_t>(mInfo[idx - 1] + mInfoInc);
            if (ROBIN_HOOD_UNLIKELY(mInfo[idx] + mInfoInc > 0xFF)) {
                mMaxNumElementsAllowed = 0;
            }
            --idx;
        }
    }
    void shiftDown(size_t idx) noexcept(std::is_nothrow_move_assignable<Node>::value) {
        
        
        mKeyVals[idx].destroy(*this);
        
        while (mInfo[idx + 1] >= 2 * mInfoInc) {
            ROBIN_HOOD_COUNT(shiftDown);
            mInfo[idx] = static_cast<uint8_t>(mInfo[idx + 1] - mInfoInc);
            mKeyVals[idx] = std::move(mKeyVals[idx + 1]);
            ++idx;
        }
        mInfo[idx] = 0;
        
        
        mKeyVals[idx].~Node();
    }
    
    template <typename Other>
    ROBIN_HOOD(NODISCARD)
    size_t findIdx(Other const& key) const {
        size_t idx;
        InfoType info;
        keyToIdx(key, &idx, &info);
        do {
            
            if (info == mInfo[idx] &&
                ROBIN_HOOD_LIKELY(WKeyEqual::operator()(key, mKeyVals[idx].getFirst()))) {
                return idx;
            }
            next(&info, &idx);
            if (info == mInfo[idx] &&
                ROBIN_HOOD_LIKELY(WKeyEqual::operator()(key, mKeyVals[idx].getFirst()))) {
                return idx;
            }
            next(&info, &idx);
        } while (info <= mInfo[idx]);
        
        return mMask == 0 ? 0
                          : static_cast<size_t>(std::distance(
                                mKeyVals, reinterpret_cast_no_cast_align_warning<Node*>(mInfo)));
    }
    void cloneData(const Table& o) {
        Cloner<Table, IsFlat && ROBIN_HOOD_IS_TRIVIALLY_COPYABLE(Node)>()(o, *this);
    }
    
    
    size_t insert_move(Node&& keyval) {
        
        
        if (0 == mMaxNumElementsAllowed && !try_increase_info()) {
            throwOverflowError(); 
        }
        size_t idx;
        InfoType info;
        keyToIdx(keyval.getFirst(), &idx, &info);
        
        while (info <= mInfo[idx]) {
            idx = idx + 1;
            info += mInfoInc;
        }
        
        auto const insertion_idx = idx;
        auto const insertion_info = static_cast<uint8_t>(info);
        if (ROBIN_HOOD_UNLIKELY(insertion_info + mInfoInc > 0xFF)) {
            mMaxNumElementsAllowed = 0;
        }
        
        while (0 != mInfo[idx]) {
            next(&info, &idx);
        }
        auto& l = mKeyVals[insertion_idx];
        if (idx == insertion_idx) {
            ::new (static_cast<void*>(&l)) Node(std::move(keyval));
        } else {
            shiftUp(idx, insertion_idx);
            l = std::move(keyval);
        }
        
        mInfo[insertion_idx] = insertion_info;
        ++mNumElements;
        return insertion_idx;
    }
public:
    using iterator = Iter<false>;
    using const_iterator = Iter<true>;
    
    
    
    
    
    explicit Table(size_t ROBIN_HOOD_UNUSED(bucket_count)  = 0, const Hash& h = Hash{},
                   const KeyEqual& equal = KeyEqual{}) noexcept(noexcept(Hash(h)) &&
                                                                noexcept(KeyEqual(equal)))
        : WHash(h)
        , WKeyEqual(equal) {
        ROBIN_HOOD_TRACE(this);
    }
    template <typename Iter>
    Table(Iter first, Iter last, size_t ROBIN_HOOD_UNUSED(bucket_count)  = 0,
          const Hash& h = Hash{}, const KeyEqual& equal = KeyEqual{})
        : WHash(h)
        , WKeyEqual(equal) {
        ROBIN_HOOD_TRACE(this);
        insert(first, last);
    }
    Table(std::initializer_list<value_type> initlist,
          size_t ROBIN_HOOD_UNUSED(bucket_count)  = 0, const Hash& h = Hash{},
          const KeyEqual& equal = KeyEqual{})
        : WHash(h)
        , WKeyEqual(equal) {
        ROBIN_HOOD_TRACE(this);
        insert(initlist.begin(), initlist.end());
    }
    Table(Table&& o) noexcept
        : WHash(std::move(static_cast<WHash&>(o)))
        , WKeyEqual(std::move(static_cast<WKeyEqual&>(o)))
        , DataPool(std::move(static_cast<DataPool&>(o))) {
        ROBIN_HOOD_TRACE(this);
        if (o.mMask) {
            mKeyVals = std::move(o.mKeyVals);
            mInfo = std::move(o.mInfo);
            mNumElements = std::move(o.mNumElements);
            mMask = std::move(o.mMask);
            mMaxNumElementsAllowed = std::move(o.mMaxNumElementsAllowed);
            mInfoInc = std::move(o.mInfoInc);
            za = std::move(o.za);
            
            o.init();
        }
    }
    Table& operator=(Table&& o) noexcept {
        ROBIN_HOOD_TRACE(this);
        if (&o != this) {
            if (o.mMask) {
                
                destroy();
                mKeyVals = std::move(o.mKeyVals);
                mInfo = std::move(o.mInfo);
                mNumElements = std::move(o.mNumElements);
                mMask = std::move(o.mMask);
                mMaxNumElementsAllowed = std::move(o.mMaxNumElementsAllowed);
                mInfoInc = std::move(o.mInfoInc);
                za = std::move(o.za);
                WHash::operator=(std::move(static_cast<WHash&>(o)));
                WKeyEqual::operator=(std::move(static_cast<WKeyEqual&>(o)));
                DataPool::operator=(std::move(static_cast<DataPool&>(o)));
                o.init();
            } else {
                
                clear();
            }
        }
        return *this;
    }
    Table(const Table& o)
        : WHash(static_cast<const WHash&>(o))
        , WKeyEqual(static_cast<const WKeyEqual&>(o))
        , DataPool(static_cast<const DataPool&>(o)) {
        ROBIN_HOOD_TRACE(this);
        if (!o.empty()) {
            
            
            auto const numElementsWithBuffer = calcNumElementsWithBuffer(o.mMask + 1);
            mKeyVals = static_cast<Node*>(detail::assertNotNull<std::bad_alloc>(
                malloc(calcNumBytesTotal(numElementsWithBuffer))));
            
            mInfo = reinterpret_cast<uint8_t*>(mKeyVals + numElementsWithBuffer);
            mNumElements = o.mNumElements;
            mMask = o.mMask;
            mMaxNumElementsAllowed = o.mMaxNumElementsAllowed;
            mInfoInc = o.mInfoInc;
            za = o.za;
            cloneData(o);
        }
    }
    
    
    
    Table& operator=(Table const& o) {
        ROBIN_HOOD_TRACE(this);
        if (&o == this) {
            
            return *this;
        }
        
        
        if (o.empty()) {
            if (0 == mMask) {
                
                return *this;
            }
            
            
            destroy();
            init();
            WHash::operator=(static_cast<const WHash&>(o));
            WKeyEqual::operator=(static_cast<const WKeyEqual&>(o));
            DataPool::operator=(static_cast<DataPool const&>(o));
            return *this;
        }
        
        Destroyer<Self, IsFlat && std::is_trivially_destructible<Node>::value>{}.nodes(*this);
        if (mMask != o.mMask) {
            
            if (0 != mMask) {
                
                free(mKeyVals);
            }
            auto const numElementsWithBuffer = calcNumElementsWithBuffer(o.mMask + 1);
            mKeyVals = static_cast<Node*>(detail::assertNotNull<std::bad_alloc>(
                malloc(calcNumBytesTotal(numElementsWithBuffer))));
            
            mInfo = reinterpret_cast<uint8_t*>(mKeyVals + numElementsWithBuffer);
            
        }
        WHash::operator=(static_cast<const WHash&>(o));
        WKeyEqual::operator=(static_cast<const WKeyEqual&>(o));
        DataPool::operator=(static_cast<DataPool const&>(o));
        mNumElements = o.mNumElements;
        mMask = o.mMask;
        mMaxNumElementsAllowed = o.mMaxNumElementsAllowed;
        mInfoInc = o.mInfoInc;
        za = o.za;
        cloneData(o);
        return *this;
    }
    
    void swap(Table& o) {
        ROBIN_HOOD_TRACE(this);
        using std::swap;
        swap(o, *this);
    }
    
    void clear() {
        ROBIN_HOOD_TRACE(this);
        if (empty()) {
            
            
            return;
        }
        Destroyer<Self, IsFlat && std::is_trivially_destructible<Node>::value>{}.nodes(*this);
        auto const numElementsWithBuffer = calcNumElementsWithBuffer(mMask + 1);
        
        uint8_t const z = 0;
        std::fill(mInfo, mInfo + calcNumBytesInfo(numElementsWithBuffer), z);
        mInfo[numElementsWithBuffer] = 1;
        mInfoInc = InitialInfoInc;
        za = InitialInfoHashShift;
    }
    
    ~Table() {
        ROBIN_HOOD_TRACE(this);
        destroy();
    }
    
    bool operator==(const Table& other) const {
        ROBIN_HOOD_TRACE(this);
        if (other.size() != size()) {
            return false;
        }
        for (auto const& otherEntry : other) {
            if (!has(otherEntry)) {
                return false;
            }
        }
        return true;
    }
    bool operator!=(const Table& other) const {
        ROBIN_HOOD_TRACE(this);
        return !operator==(other);
    }
    template <typename Q = mapped_type>
    typename std::enable_if<!std::is_void<Q>::value, Q&>::type operator[](const key_type& key) {
        ROBIN_HOOD_TRACE(this);
        return doCreateByKey(key);
    }
    template <typename Q = mapped_type>
    typename std::enable_if<!std::is_void<Q>::value, Q&>::type operator[](key_type&& key) {
        ROBIN_HOOD_TRACE(this);
        return doCreateByKey(std::move(key));
    }
    template <typename Iter>
    void insert(Iter first, Iter last) {
        for (; first != last; ++first) {
            
            insert(value_type(*first));
        }
    }
    template <typename... Args>
    std::pair<iterator, bool> emplace(Args&&... args) {
        ROBIN_HOOD_TRACE(this);
        Node n{*this, std::forward<Args>(args)...};
        auto r = doInsert(std::move(n));
        if (!r.second) {
            
            
            n.destroy(*this);
        }
        return r;
    }
    std::pair<iterator, bool> insert(const value_type& keyval) {
        ROBIN_HOOD_TRACE(this);
        return doInsert(keyval);
    }
    std::pair<iterator, bool> insert(value_type&& keyval) {
        return doInsert(std::move(keyval));
    }
    
    size_t count(const key_type& key) const { 
        ROBIN_HOOD_TRACE(this);
        auto kv = mKeyVals + findIdx(key);
        if (kv != reinterpret_cast_no_cast_align_warning<Node*>(mInfo)) {
            return 1;
        }
        return 0;
    }
    bool contains(const key_type& key) const { 
        return 1U == count(key);
    }
    
    
    template <typename Q = mapped_type>
    
    typename std::enable_if<!std::is_void<Q>::value, Q&>::type at(key_type const& key) {
        ROBIN_HOOD_TRACE(this);
        auto kv = mKeyVals + findIdx(key);
        if (kv == reinterpret_cast_no_cast_align_warning<Node*>(mInfo)) {
            doThrow<std::out_of_range>("key not found");
        }
        return kv->getSecond();
    }
    
    
    template <typename Q = mapped_type>
    
    typename std::enable_if<!std::is_void<Q>::value, Q const&>::type at(key_type const& key) const {
        ROBIN_HOOD_TRACE(this);
        auto kv = mKeyVals + findIdx(key);
        if (kv == reinterpret_cast_no_cast_align_warning<Node*>(mInfo)) {
            doThrow<std::out_of_range>("key not found");
        }
        return kv->getSecond();
    }
    const_iterator find(const key_type& key) const { 
        ROBIN_HOOD_TRACE(this);
        const size_t idx = findIdx(key);
        return const_iterator{mKeyVals + idx, mInfo + idx};
    }
    template <typename OtherKey>
    const_iterator find(const OtherKey& key, is_transparent_tag ) const {
        ROBIN_HOOD_TRACE(this);
        const size_t idx = findIdx(key);
        return const_iterator{mKeyVals + idx, mInfo + idx};
    }
    iterator find(const key_type& key) {
        ROBIN_HOOD_TRACE(this);
        const size_t idx = findIdx(key);
        return iterator{mKeyVals + idx, mInfo + idx};
    }
    template <typename OtherKey>
    iterator find(const OtherKey& key, is_transparent_tag ) {
        ROBIN_HOOD_TRACE(this);
        const size_t idx = findIdx(key);
        return iterator{mKeyVals + idx, mInfo + idx};
    }
    iterator begin() {
        ROBIN_HOOD_TRACE(this);
        if (empty()) {
            return end();
        }
        return iterator(mKeyVals, mInfo, fast_forward_tag{});
    }
    const_iterator begin() const { 
        ROBIN_HOOD_TRACE(this);
        return cbegin();
    }
    const_iterator cbegin() const { 
        ROBIN_HOOD_TRACE(this);
        if (empty()) {
            return cend();
        }
        return const_iterator(mKeyVals, mInfo, fast_forward_tag{});
    }
    iterator end() {
        ROBIN_HOOD_TRACE(this);
        
        
        return iterator{reinterpret_cast_no_cast_align_warning<Node*>(mInfo), nullptr};
    }
    const_iterator end() const { 
        ROBIN_HOOD_TRACE(this);
        return cend();
    }
    const_iterator cend() const { 
        ROBIN_HOOD_TRACE(this);
        return const_iterator{reinterpret_cast_no_cast_align_warning<Node*>(mInfo), nullptr};
    }
    iterator erase(const_iterator pos) {
        ROBIN_HOOD_TRACE(this);
        
        
        return erase(iterator{const_cast<Node*>(pos.mKeyVals), const_cast<uint8_t*>(pos.mInfo)});
    }
    
    iterator erase(iterator pos) {
        ROBIN_HOOD_TRACE(this);
        
        auto const idx = static_cast<size_t>(pos.mKeyVals - mKeyVals);
        shiftDown(idx);
        --mNumElements;
        if (*pos.mInfo) {
            
            return pos;
        }
        
        return ++pos;
    }
    size_t erase(const key_type& key) {
        ROBIN_HOOD_TRACE(this);
        size_t idx;
        InfoType info;
        keyToIdx(key, &idx, &info);
        
        do {
            if (info == mInfo[idx] && WKeyEqual::operator()(key, mKeyVals[idx].getFirst())) {
                shiftDown(idx);
                --mNumElements;
                return 1;
            }
            next(&info, &idx);
        } while (info <= mInfo[idx]);
        
        return 0;
    }
    
    
    void rehash(size_t c) {
        reserve(c);
    }
    
    
    void reserve(size_t c) {
        ROBIN_HOOD_TRACE(this);
        auto const minElementsAllowed = (std::max)(c, mNumElements);
        auto newSize = InitialNumElements;
        while (calcMaxNumElementsAllowed(newSize) < minElementsAllowed && newSize != 0) {
            newSize *= 2;
        }
        if (ROBIN_HOOD_UNLIKELY(newSize == 0)) {
            throwOverflowError();
        }
        rehashPowerOfTwo(newSize);
    }
    size_type size() const noexcept { 
        ROBIN_HOOD_TRACE(this);
        return mNumElements;
    }
    size_type max_size() const noexcept { 
        ROBIN_HOOD_TRACE(this);
        return static_cast<size_type>(-1);
    }
    ROBIN_HOOD(NODISCARD) bool empty() const noexcept {
        ROBIN_HOOD_TRACE(this);
        return 0 == mNumElements;
    }
    float max_load_factor() const noexcept { 
        ROBIN_HOOD_TRACE(this);
        return MaxLoadFactor100 / 100.0F;
    }
    
    float load_factor() const noexcept { 
        ROBIN_HOOD_TRACE(this);
        return static_cast<float>(size()) / static_cast<float>(mMask + 1);
    }
    ROBIN_HOOD(NODISCARD) size_t mask() const noexcept {
        ROBIN_HOOD_TRACE(this);
        return mMask;
    }
    ROBIN_HOOD(NODISCARD) size_t calcMaxNumElementsAllowed(size_t maxElements) const noexcept {
        if (ROBIN_HOOD_LIKELY(maxElements <= (std::numeric_limits<size_t>::max)() / 100)) {
            return maxElements * MaxLoadFactor100 / 100;
        }
        
        return (maxElements / 100) * MaxLoadFactor100;
    }
    ROBIN_HOOD(NODISCARD) size_t calcNumBytesInfo(size_t numElements) const noexcept {
        
        
        return numElements + sizeof(uint64_t);
    }
    ROBIN_HOOD(NODISCARD)
    size_t calcNumElementsWithBuffer(size_t numElements) const noexcept {
        auto maxNumElementsAllowed = calcMaxNumElementsAllowed(numElements);
        return numElements + (std::min)(maxNumElementsAllowed, (static_cast<size_t>(0xFF)));
    }
    
    ROBIN_HOOD(NODISCARD) size_t calcNumBytesTotal(size_t numElements) const {
#if ROBIN_HOOD(BITNESS) == 64
        return numElements * sizeof(Node) + calcNumBytesInfo(numElements);
#else
        
        auto const ne = static_cast<uint64_t>(numElements);
        auto const s = static_cast<uint64_t>(sizeof(Node));
        auto const infos = static_cast<uint64_t>(calcNumBytesInfo(numElements));
        auto const total64 = ne * s + infos;
        auto const total = static_cast<size_t>(total64);
        if (ROBIN_HOOD_UNLIKELY(static_cast<uint64_t>(total) != total64)) {
            throwOverflowError();
        }
        return total;
#endif
    }
private:
    template <typename Q = mapped_type>
    ROBIN_HOOD(NODISCARD)
    typename std::enable_if<!std::is_void<Q>::value, bool>::type has(const value_type& e) const {
        ROBIN_HOOD_TRACE(this);
        auto it = find(e.first);
        return it != end() && it->second == e.second;
    }
    template <typename Q = mapped_type>
    ROBIN_HOOD(NODISCARD)
    typename std::enable_if<std::is_void<Q>::value, bool>::type has(const value_type& e) const {
        ROBIN_HOOD_TRACE(this);
        return find(e) != end();
    }
    
    
    void rehashPowerOfTwo(size_t numBuckets) {
        ROBIN_HOOD_TRACE(this);
        Node* const oldKeyVals = mKeyVals;
        uint8_t const* const oldInfo = mInfo;
        const size_t oldMaxElementsWithBuffer = calcNumElementsWithBuffer(mMask + 1);
        
        init_data(numBuckets);
        if (oldMaxElementsWithBuffer > 1) {
            for (size_t i = 0; i < oldMaxElementsWithBuffer; ++i) {
                if (oldInfo[i] != 0) {
                    insert_move(std::move(oldKeyVals[i]));
                    
                    oldKeyVals[i].~Node();
                }
            }
            
            DataPool::addOrFree(oldKeyVals, calcNumBytesTotal(oldMaxElementsWithBuffer));
        }
    }
    ROBIN_HOOD(NOINLINE) void throwOverflowError() const {
#if ROBIN_HOOD(HAS_EXCEPTIONS)
        throw std::overflow_error("robin_hood::map overflow");
#else
        abort();
#endif
    }
    void init_data(size_t max_elements) {
        mNumElements = 0;
        mMask = max_elements - 1;
        mMaxNumElementsAllowed = calcMaxNumElementsAllowed(max_elements);
        auto const numElementsWithBuffer = calcNumElementsWithBuffer(max_elements);
        
        mKeyVals = reinterpret_cast<Node*>(detail::assertNotNull<std::bad_alloc>(
            calloc(1, calcNumBytesTotal(numElementsWithBuffer))));
        mInfo = reinterpret_cast<uint8_t*>(mKeyVals + numElementsWithBuffer);
        
        mInfo[numElementsWithBuffer] = 1;
        mInfoInc = InitialInfoInc;
        za = InitialInfoHashShift;
    }
    template <typename Arg, typename Q = mapped_type>
    typename std::enable_if<!std::is_void<Q>::value, Q&>::type doCreateByKey(Arg&& key) {
        while (true) {
            size_t idx;
            InfoType info;
            keyToIdx(key, &idx, &info);
            nextWhileLess(&info, &idx);
            
            
            while (info == mInfo[idx]) {
                if (WKeyEqual::operator()(key, mKeyVals[idx].getFirst())) {
                    
                    return mKeyVals[idx].getSecond();
                }
                next(&info, &idx);
            }
            
            if (ROBIN_HOOD_UNLIKELY(mNumElements >= mMaxNumElementsAllowed)) {
                increase_size();
                continue;
            }
            
            auto const insertion_idx = idx;
            auto const insertion_info = info;
            if (ROBIN_HOOD_UNLIKELY(insertion_info + mInfoInc > 0xFF)) {
                mMaxNumElementsAllowed = 0;
            }
            
            while (0 != mInfo[idx]) {
                next(&info, &idx);
            }
            auto& l = mKeyVals[insertion_idx];
            if (idx == insertion_idx) {
                
                
                ::new (static_cast<void*>(&l))
                    Node(*this, std::piecewise_construct,
                         std::forward_as_tuple(std::forward<Arg>(key)), std::forward_as_tuple());
            } else {
                shiftUp(idx, insertion_idx);
                l = Node(*this, std::piecewise_construct,
                         std::forward_as_tuple(std::forward<Arg>(key)), std::forward_as_tuple());
            }
            
            mInfo[insertion_idx] = static_cast<uint8_t>(insertion_info);
            ++mNumElements;
            return mKeyVals[insertion_idx].getSecond();
        }
    }
    
    template <typename Arg>
    std::pair<iterator, bool> doInsert(Arg&& keyval) {
        while (true) {
            size_t idx;
            InfoType info;
            keyToIdx(getFirstConst(keyval), &idx, &info);
            nextWhileLess(&info, &idx);
            
            while (info == mInfo[idx]) {
                if (WKeyEqual::operator()(getFirstConst(keyval), mKeyVals[idx].getFirst())) {
                    
                    
                    return std::make_pair<iterator, bool>(iterator(mKeyVals + idx, mInfo + idx),
                                                          false);
                }
                next(&info, &idx);
            }
            
            if (ROBIN_HOOD_UNLIKELY(mNumElements >= mMaxNumElementsAllowed)) {
                increase_size();
                continue;
            }
            
            auto const insertion_idx = idx;
            auto const insertion_info = info;
            if (ROBIN_HOOD_UNLIKELY(insertion_info + mInfoInc > 0xFF)) {
                mMaxNumElementsAllowed = 0;
            }
            
            while (0 != mInfo[idx]) {
                next(&info, &idx);
            }
            auto& l = mKeyVals[insertion_idx];
            if (idx == insertion_idx) {
                ::new (static_cast<void*>(&l)) Node(*this, std::forward<Arg>(keyval));
            } else {
                shiftUp(idx, insertion_idx);
                l = Node(*this, std::forward<Arg>(keyval));
            }
            
            mInfo[insertion_idx] = static_cast<uint8_t>(insertion_info);
            ++mNumElements;
            return std::make_pair(iterator(mKeyVals + insertion_idx, mInfo + insertion_idx), true);
        }
    }
    bool try_increase_info() {
        ROBIN_HOOD_LOG("mInfoInc=" << mInfoInc << ", numElements=" << mNumElements
                                   << ", maxNumElementsAllowed="
                                   << calcMaxNumElementsAllowed(mMask + 1));
        if (mInfoInc <= 2) {
            
            return false;
        }
        
        mInfoInc = static_cast<uint8_t>(mInfoInc >> 1U);
        
        
        ++za;
        auto const numElementsWithBuffer = calcNumElementsWithBuffer(mMask + 1);
        for (size_t i = 0; i < numElementsWithBuffer; i += 8) {
            auto val = unaligned_load<uint64_t>(mInfo + i);
            val = (val >> 1U) & UINT64_C(0x7f7f7f7f7f7f7f7f);
            std::memcpy(mInfo + i, &val, sizeof(val));
        }
        
        mInfo[numElementsWithBuffer] = 1;
        mMaxNumElementsAllowed = calcMaxNumElementsAllowed(mMask + 1);
        return true;
    }
    void increase_size() {
        
        if (0 == mMask) {
            init_data(InitialNumElements);
            return;
        }
        auto const maxNumElementsAllowed = calcMaxNumElementsAllowed(mMask + 1);
        if (mNumElements < maxNumElementsAllowed && try_increase_info()) {
            return;
        }
        ROBIN_HOOD_LOG("mNumElements=" << mNumElements << ", maxNumElementsAllowed="
                                       << maxNumElementsAllowed << ", load="
                                       << (static_cast<double>(mNumElements) * 100.0 /
                                           (static_cast<double>(mMask) + 1)));
        
        if (mNumElements * 2 < calcMaxNumElementsAllowed(mMask + 1)) {
            throwOverflowError();
        }
        rehashPowerOfTwo((mMask + 1) * 2);
    }
    void destroy() {
        if (0 == mMask) {
            
            return;
        }
        Destroyer<Self, IsFlat && std::is_trivially_destructible<Node>::value>{}
            .nodesDoNotDeallocate(*this);
        
        
        
        
        if (mKeyVals != reinterpret_cast<Node*>(&mMask)) {
            free(mKeyVals);
        }
    }
    void init() noexcept {
        mKeyVals = reinterpret_cast<Node*>(&mMask);
        mInfo = reinterpret_cast<uint8_t*>(&mMask);
        mNumElements = 0;
        mMask = 0;
        mMaxNumElementsAllowed = 0;
        mInfoInc = InitialInfoInc;
        za = InitialInfoHashShift;
    }
    
    Node* mKeyVals = reinterpret_cast<Node*>(&mMask);    
    uint8_t* mInfo = reinterpret_cast<uint8_t*>(&mMask); 
    size_t mNumElements = 0,mMask = 0,mMaxNumElementsAllowed = 0;                                                
    InfoType mInfoInc = InitialInfoInc,za = InitialInfoHashShift;                     
                                                         
};
} 
template <typename Key, typename T, typename Hash = hash<Key>,
          typename KeyEqual = std::equal_to<Key>, size_t MaxLoadFactor100 = 80>
using unordered_flat_map = detail::Table<true, MaxLoadFactor100, Key, T, Hash, KeyEqual>;
template <typename Key, typename T, typename Hash = hash<Key>,
          typename KeyEqual = std::equal_to<Key>, size_t MaxLoadFactor100 = 80>
using unordered_node_map = detail::Table<false, MaxLoadFactor100, Key, T, Hash, KeyEqual>;
template <typename Key, typename T, typename Hash = hash<Key>,
          typename KeyEqual = std::equal_to<Key>, size_t MaxLoadFactor100 = 80>
using unordered_map =
    detail::Table<sizeof(robin_hood::pair<Key, T>) <= sizeof(size_t) * 6 &&
                      std::is_nothrow_move_constructible<robin_hood::pair<Key, T>>::value &&
                      std::is_nothrow_move_assignable<robin_hood::pair<Key, T>>::value,
                  MaxLoadFactor100, Key, T, Hash, KeyEqual>;
template <typename Key, typename Hash = hash<Key>, typename KeyEqual = std::equal_to<Key>,
          size_t MaxLoadFactor100 = 80>
using unordered_flat_set = detail::Table<true, MaxLoadFactor100, Key, void, Hash, KeyEqual>;
template <typename Key, typename Hash = hash<Key>, typename KeyEqual = std::equal_to<Key>,
          size_t MaxLoadFactor100 = 80>
using unordered_node_set = detail::Table<false, MaxLoadFactor100, Key, void, Hash, KeyEqual>;
template <typename Key, typename Hash = hash<Key>, typename KeyEqual = std::equal_to<Key>,
          size_t MaxLoadFactor100 = 80>
using unordered_set = detail::Table<sizeof(Key) <= sizeof(size_t) * 6 &&
                                        std::is_nothrow_move_constructible<Key>::value &&
                                        std::is_nothrow_move_assignable<Key>::value,
                                    MaxLoadFactor100, Key, void, Hash, KeyEqual>;
} 
#endif
#define endl '\n'
#define cin(t) cin>>t
#define int long long
#define nl cout<<endl
using namespace std;
const int BLK = 400;
const int maxN = 20;
vector<int> adj[100001];
int wt[100001],S[100001],T[100001],tree[200002],LCA[100001][maxN],level[100001],ans[100001];
robin_hood::unordered_map<int,int> mp,nodef;
struct query{
    int l,r,idx,flag,lca;
};
query Q[100001];
int timer=1,res;
void add(int pos){
   int node = tree[pos];
   nodef[node]++;
    if(nodef[node]==1){
        mp[wt[node]]++;
        if(mp[wt[node]]==1){
            res++;
        }
    }else if(nodef[node]==2){
        mp[wt[node]]--;
        if(mp[wt[node]]==0){
            res--;
        }
    }
}
void remove(int pos){
    int node = tree[pos];
    nodef[node]--;
    if(nodef[node]==1){
        mp[wt[node]]++;
        if(mp[wt[node]]==1){
            res++;
        }
    }else if(nodef[node]==0){
        mp[wt[node]]--;
        if(mp[wt[node]]==0){
            res--;
        }
    }
}
bool comp(query a,query b){
    int x=a.l/BLK;
    int y=b.l/BLK;
    if(x!=y){
        return x<y;
    }
    return x%2 ? a.r<b.r : a.r > b.r;
}
void dfs(int node,int par,int lvl){
    level[node]=lvl;
    LCA[node][0]=par;
    tree[timer]=node;
    S[node]=timer++;
    for(int child:adj[node]){
        if(child!=par)
            dfs(child,node,lvl+1);
    }
    tree[timer]=node;
    T[node]=timer++;
}
void init_lca(int n){
    for(int j=1;j<maxN;j++){
        for(int i=1;i<=n;i++){
            if(LCA[i][j-1]!=-1)
                LCA[i][j]=LCA[LCA[i][j-1]][j-1];
        }
    }
}
int get_lca(int a,int b){
    if(level[a] > level[b]){
        swap(a,b);
    }
	
	int d = level[b] - level[a];
	int f = 0;
	while(d>0){
		if(d & 1)
            b = LCA[b][f];
		
		d >>= 1;
		f++;
	}
	
	if(a == b) return a;
	
	for(int j=maxN-1;j>=0;j--){
	    if(LCA[a][j] != -1 && (LCA[a][j] != LCA[b][j])){
            a = LCA[a][j];
            b = LCA[b][j];
        }
	}       
	
	return LCA[a][0];
}
int32_t main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>wt[i];
    }
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1,0);
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    init_lca(n);
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        if(S[a]>S[b]){
            swap(a,b);
        }
        int lca=get_lca(a,b);
        if(a!=lca){
            Q[i].l=T[a];
            Q[i].r=S[b];
            Q[i].flag=1;
            Q[i].lca=lca;
            Q[i].idx=i;
        }else{
            Q[i].l=S[a];
            Q[i].r=S[b];
            Q[i].flag=0;
            Q[i].lca=lca;
            Q[i].idx=i;
        }
    }
    sort(Q+1,Q+m+1,comp);
    int ML=1,MR=0;
    
    res=0;
    for(int i=1;i<=m;i++){
        int L=Q[i].l;
        int R=Q[i].r;
        int idx=Q[i].idx;
        int lca=Q[i].lca;
        bool flag=Q[i].flag;
        while(MR<R){
            MR++;
            add(MR);
        }
        while(ML>L){
            ML--;
            add(ML);
        }
        while(MR>R){
            remove(MR);
            MR--;
        }
        while(ML<L){
            remove(ML);
            ML++;
        }
        ans[idx] = res;
        if(flag){
            if(mp[wt[lca]]==0){
                ans[idx]++;
            }
        }
    }
    
    for(int i=1;i<=m;i++){
            cout<<ans[i]<<endl;
    }
    return 0;
}
