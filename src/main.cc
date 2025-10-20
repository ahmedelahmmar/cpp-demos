#include "experiments/revealing_the_vtbl.hpp"

int main(const int argc, const char **argv)
{
    static_cast<void>(argc);
    static_cast<void>(argv);

    RevealingTheVtbl experiment;
    experiment.run();

    return 0;
}