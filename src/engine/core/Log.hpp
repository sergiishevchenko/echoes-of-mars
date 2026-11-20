#pragma once

#include <cstdio>
#include <utility>

namespace eom {

enum class LogLevel {
    Info,
    Warn,
    Error,
};

inline const char* toString(LogLevel level) {
    switch (level) {
    case LogLevel::Info:
        return "INFO";
    case LogLevel::Warn:
        return "WARN";
    case LogLevel::Error:
        return "ERROR";
    }
    return "LOG";
}

template <typename... Args>
inline void log(LogLevel level, const char* fmt, Args&&... args) {
    std::fprintf(stderr, "[%s] ", toString(level));
    if constexpr (sizeof...(Args) == 0) {
        std::fputs(fmt, stderr);
        std::fputc('\n', stderr);
    } else {
        std::fprintf(stderr, fmt, std::forward<Args>(args)...);
        std::fputc('\n', stderr);
    }
}

template <typename... Args>
inline void logInfo(const char* fmt, Args&&... args) {
    log(LogLevel::Info, fmt, std::forward<Args>(args)...);
}

template <typename... Args>
inline void logWarn(const char* fmt, Args&&... args) {
    log(LogLevel::Warn, fmt, std::forward<Args>(args)...);
}

template <typename... Args>
inline void logError(const char* fmt, Args&&... args) {
    log(LogLevel::Error, fmt, std::forward<Args>(args)...);
}

}  // namespace eom
