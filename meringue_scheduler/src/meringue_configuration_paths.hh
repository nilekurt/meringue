#ifndef _MERINGUE_CONFIGURATION_PATHS_HH_
#define _MERINGUE_CONFIGURATION_PATHS_HH_

namespace meringue {

namespace config {

#if defined(__linux__)
inline static constexpr const char * G_PATH = "/etc/meringue/config.json";
#elif defined(_WIN32)
// @TODO
#elif defined(__FreeBSD__)
// @TODO
#elif defined(__APPLE__)
// @TODO
#else // Other
// @TODO
#endif

} // namespace config

} // namespace meringue

#endif // _MERINGUE_CONFIGURATION_PATHS_HH_
