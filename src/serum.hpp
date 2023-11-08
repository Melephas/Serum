#pragma once

#include <cstddef>
#include <format>
#include <iostream>
#include <optional>
#include <span>
#include <string_view>


namespace serum::services {
    class nameable_i {
        public:
            virtual ~nameable_i() = default;

            virtual auto name() -> std::string_view { return "nameable_i"; }
    };


    namespace io {
        class writer_i : public virtual nameable_i {
            public:
                virtual ~writer_i() = default;

                virtual auto write(const std::span<std::byte>& data) -> std::size_t = 0;

                auto name() -> std::string_view override { return "writer_i"; }
        };


        class reader_i : public virtual nameable_i {
            public:
                virtual ~reader_i() = default;

                virtual auto read(std::size_t max_len) -> std::span<std::byte> = 0;

                auto name() -> std::string_view override { return "reader_i"; }
        };


        class string_writer_i : public virtual writer_i, public virtual nameable_i {
            public:
                virtual ~string_writer_i() = default;

                virtual auto write_string_view(std::string_view view) -> std::size_t = 0;
                virtual auto write_string(const std::string& str) -> std::size_t = 0;

                auto name() -> std::string_view override { return "string_writer_i"; }
        };


        class string_reader_i : public virtual reader_i, public virtual nameable_i {
            public:
                virtual ~string_reader_i() = default;

                virtual auto read_string(std::size_t max_len) -> std::string = 0;

                auto name() -> std::string_view override { return "string_reader_i"; }
        };
    }


    namespace logging {
        enum class log_level { debug, info, warn, error };

        auto string_to_log_level(std::string_view str) -> std::optional<log_level>;
        auto log_level_to_string(log_level level) -> std::string_view;

        class logger_i : public virtual nameable_i {
            public:
                virtual ~logger_i() = default;

                virtual auto path() -> std::string_view = 0;
                virtual auto set_path(std::string new_path) -> void = 0;
                virtual auto log(std::string_view message, log_level level) -> void = 0;
                virtual auto debug(std::string_view message) -> void {
                    log(message, log_level::debug);
                }
                virtual auto info(std::string_view message) -> void {
                    log(message, log_level::info);
                }
                virtual auto warn(std::string_view message) -> void {
                    log(message, log_level::warn);
                }
                virtual auto error(std::string_view message) -> void {
                    log(message, log_level::error);
                }

                auto name() -> std::string_view override { return "logger_i"; }
        };


        auto get_logger() -> std::unique_ptr<logger_i>;


        namespace implementation {
            class console_logger : public virtual logger_i {
                    std::string log_path;
                public:
                    virtual ~console_logger() = default;

                    auto log(std::string_view message, log_level level) -> void override {
                        std::cout << "[" << log_level_to_string(level) << "] " << message << std::endl;
                    }
                    auto path() -> std::string_view override {
                        return log_path;
                    }
                    auto set_path(std::string new_path) -> void override {
                        log_path = new_path;
                    }

                    auto name() -> std::string_view override { return "console_logger"; }
            };
        }
    }
}
