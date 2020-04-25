#include "meringue_message_deserialize.hh"

namespace meringue {

auto
deserialize(gsl::span<const uint8_t> bytes) -> Message
{
    (void)bytes;
    return monostate{};
}

} // namespace meringue
