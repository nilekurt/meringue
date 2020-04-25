#include "gsl/span"
#include "meringue_client.hh"

auto
main(int argc, char ** argv) -> int
{
    const gsl::span<char *> args(argv, argc);

    return 0;
}
