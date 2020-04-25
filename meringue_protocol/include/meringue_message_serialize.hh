#ifndef _MERINGUE_MESSAGE_SERIALIZE_HH_
#define _MERINGUE_MESSAGE_SERIALIZE_HH_

#include <cinttypes>
#include <vector>

namespace meringue {

template<typename T>
auto
serialize(const T & msg) -> std::vector<uint8_t>;

} // namespace meringue

#endif // _MERINGUE_MESSAGE_SERIALIZE_HH_
