#include "meringue_message_serialize.hh"

#include "meringue_header.hh"
#include "meringue_message.hh"

namespace meringue {

template<>
auto
serialize(const msg::AbortRequest & msg) -> std::vector<uint8_t>
{
    (void)msg;
    return {};
}

template<>
auto
serialize(const msg::AbortResponse & msg) -> std::vector<uint8_t>
{
    (void)msg;
    return {};
}

template<>
auto
serialize(const msg::ExecutionRequest & msg) -> std::vector<uint8_t>
{
    (void)msg;
    return {};
}

template<>
auto
serialize(const msg::ExecutionResponse & msg) -> std::vector<uint8_t>
{
    (void)msg;
    return {};
}

template<>
auto
serialize(const msg::ExecutionResult & msg) -> std::vector<uint8_t>
{
    (void)msg;
    return {};
}

template<>
auto
serialize(const msg::StatusRequest & msg) -> std::vector<uint8_t>
{
    (void)msg;
    return {};
}

template<>
auto
serialize(const msg::StatusResponse & msg) -> std::vector<uint8_t>
{
    (void)msg;
    return {};
}

template<>
auto
serialize(const Message & msg) -> std::vector<uint8_t>
{
    return visit([](const auto & unboxed) { return serialize(unboxed); }, msg);
}

} // namespace meringue