#include "fmt/format.h"
#include <fmt/core.h>
#include <fmt/chrono.h>

using namespace std::literals::chrono_literals;


int main() {
    fmt::print("Hello, world!\n");
    std::string s = fmt::format("The answer is {}.", 42);
    fmt::print(s);

    fmt::print("Default format: {} {}\n", 42s, 100ms);
    fmt::print("strftime-like format: {:%H:%M:%S}\n", 3h + 15min + 30s);
    return 0;
}


