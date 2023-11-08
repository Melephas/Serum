#include "serum.hpp"

auto serum::services::logging::get_logger() -> std::unique_ptr<serum::services::logging::logger_i> {
    return std::make_unique<serum::services::logging::implementation::console_logger>();
}

auto serum::services::logging::string_to_log_level(std::string_view str) -> std::optional<serum::services::logging::log_level> {
    if ("debug" == str) return std::make_optional(serum::services::logging::log_level::debug);
    if ("info" == str) return std::make_optional(serum::services::logging::log_level::info);
    if ("warn" == str) return std::make_optional(serum::services::logging::log_level::warn);
    if ("error" == str) return std::make_optional(serum::services::logging::log_level::error);
    return std::nullopt;
}

auto serum::services::logging::log_level_to_string(serum::services::logging::log_level level) -> std::string_view {
    switch (level) {
        case serum::services::logging::log_level::debug: return "debug";
        case serum::services::logging::log_level::info: return "info";
        case serum::services::logging::log_level::warn: return "warn";
        case serum::services::logging::log_level::error: return "error";
        default: return "!";
    }
}
