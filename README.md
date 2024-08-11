# spdlog-syslog-formatter
Syslog(RFC5424) formatter for spdlog

## Usage
Copy the files or clone(git submodule) the repository inside your project directory.

### Header Only Version
1. Define `SPDLOG_HEADER_ONLY` macro project wide or just before the include
1. Add `include` directory in your project/executable include directory
1. Include `<spdlog/syslog_formatter.h>`
1. Refer `example/main.cpp` for usage

### Compiled Library Version
1. Add `include` directory in your project/executable include directory
1. Include `<spdlog/syslog_formatter.h>` in source files where needed
1. Include `<spdlog/syslog_formatter-inl.h>` in `main.cpp` source file
1. Refer `example/main.cpp` for usage
