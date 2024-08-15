# spdlog-syslog-formatter
Syslog(RFC5424) formatter for spdlog

## Usage
Copy the files or clone(git submodule) the repository inside your project directory.

### Header Only Version
1. Define `SPDLOG_HEADER_ONLY` macro project wide or just before the include
1. Add `include` directory to the project/executable include directories
1. Include `<spdlog/syslog_formatter.h>`

### Compiled Library Version
1. Add `include` directory to the project/executable include directories
1. Include `<spdlog/syslog_formatter.h>` in source files where needed
1. Add the following snippet in main source file(e.g., `main.cpp`) 
```c++
...
#undef SPDLOG_SHARED_LIB
#include <spdlog/syslog_formatter-inl.h>
...
```

## Example
```c++
int main(void)
{
    // run "nc -klu 514" to receive the syslog message
    spdlog::sinks::udp_sink_config udp_sink_config("127.0.0.1", 514);
    auto udp_logger = spdlog::udp_logger_mt("udp_logger", udp_sink_config);

    spdlog::syslog_formatter syslog_formatter(spdlog::facility::user, "localhost", "example");
    udp_logger->set_formatter(syslog_formatter.clone());

    udp_logger->info("this message will be logged in local syslog receiver");

    return 0;
}
```
