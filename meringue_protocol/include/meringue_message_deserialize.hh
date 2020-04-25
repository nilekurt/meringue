#ifndef _MERINGUE_MESSAGE_DESERIALIZE_HH_
#define _MERINGUE_MESSAGE_DESERIALIZE_HH_

#include "gsl/span"
#include "meringue_message.hh"

namespace meringue {

auto
deserialize(gsl::span<const uint8_t> bytes) -> Message;

} // namespace meringue

#endif // _MERINGUE_MESSAGE_DESERIALIZE_HH_