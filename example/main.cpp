#include <spdlog/spdlog.h>
#include <spdlog/sinks/udp_sink.h>
#include <spdlog/pattern_formatter.h>
#include <spdlog/syslog_formatter.h>

#ifndef SPDLOG_HEADER_ONLY
#include <spdlog/syslog_formatter-inl.h>
#endif

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
