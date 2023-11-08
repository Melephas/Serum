#include <cstdio>

#include "serum.hpp"


int main() {
    auto log = serum::services::logging::get_logger();
    log->info("hello world!");
    log->info(log->name());
}
