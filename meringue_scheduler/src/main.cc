#include "Args/all.hpp"
#include "gsl/span"
#include "meringue_configuration_paths.hh"

#include <iostream>

auto
main(int argc, char ** argv) -> int
{
    try {
        Args::CmdLine cmd(argc, argv);

        Args::Arg config_arg("config", true, false);
        config_arg.setDescription("Path to configuration file.");
        config_arg.setValueSpecifier("config.json");
        cmd.addArg(config_arg);

        cmd.addHelp(true, argv[0], "Meringue Scheduler");

        cmd.parse();
    } catch (const Args::HelpHasBeenPrintedException & /*unused*/) {
        return -1;
    } catch (const Args::BaseException & e) {
        std::cerr << e.desc() << "\n";
        return -1;
    } catch (...) {
        std::cerr << "Caught unhandled exception!\n";
        return -1;
    }

    return 0;
}
