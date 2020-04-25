#ifndef _MERINGUE_HASH_HH_
#define _MERINGUE_HASH_HH_

#include "meringue_variant.hh"

#include <array>
#include <cinttypes>

namespace meringue {

namespace hash {

inline constexpr auto G_B512 = 64;
inline constexpr auto G_B256 = 32;
inline constexpr auto G_B128 = 16;

template<std::size_t Length>
struct HashBase {
    std::array<uint8_t, Length> data;

    template<std::size_t OtherLength>
    constexpr auto
    operator==(const HashBase<OtherLength> & other) -> bool
    {
        if constexpr (Length != OtherLength) {
            return false;
        } else {
            return data == other.data;
        }
    }
};

struct Sha512 final : HashBase<G_B512> {
};

struct Sha256 final : HashBase<G_B256> {
};

} // namespace hash

using Hash = variant<hash::Sha512, hash::Sha256>;

} // namespace meringue

#endif // _MERINGUE_HASH_HH_
