#ifndef _MERINGUE_MESSAGE_HH_
#define _MERINGUE_MESSAGE_HH_

#include "meringue_hash.hh"
#include "meringue_optional.hh"
#include "meringue_variant.hh"

namespace meringue {

namespace msg {

struct AbortRequest {
};

struct AbortResponse {
};

struct ExecutionRequest {
    variant<Hash, uint32_t> toolchain_id;
    std::string             command;
};

struct ExecutionResponse {
};

struct ExecutionResult {
};

struct StatusRequest {
};

struct StatusResponse {
};

} // namespace msg

using Message = variant<monostate,
                        msg::AbortRequest,
                        msg::AbortResponse,
                        msg::ExecutionRequest,
                        msg::ExecutionResponse,
                        msg::ExecutionResult,
                        msg::StatusRequest,
                        msg::StatusResponse>;

} // namespace meringue

#endif // _MERINGUE_MESSAGE_HH_