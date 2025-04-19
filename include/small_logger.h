/*
 * Copyright (c) 2025 Mira Ly
 * SPDX-Identifier: Apache-2.0
 */

#ifndef SMALL_LOGGER_H_
#define SMALL_LOGGER_H_

#ifndef __cplusplus
#include <stdbool.h>
#endif
#include <stdio.h>
#ifdef __linux__
#include <unistd.h>
#elif defined(_WIN32)
#include <io.h>
#endif

/*
 * Header library for logging.
 * You may customize the color and style of output by using the following
 * macros:
 * - LOG_CODE_DEBUG
 * - LOG_CODE_INFO
 * - LOG_CODE_WARN
 * - LOG_CODE_ERR
 *
 * To set the log level, define LOG_LEVEL (default = 4)
 * DEBUG: >= 4
 * INFO: >= 3
 * WARN: >= 2
 * ERR: >= 1
 */

#define LOG_CODE_COLOR_BLACK   "\x1b[30m"
#define LOG_CODE_COLOR_RED     "\x1b[31m"
#define LOG_CODE_COLOR_GREEN   "\x1b[32m"
#define LOG_CODE_COLOR_YELLOW  "\x1b[33m"
#define LOG_CODE_COLOR_BLUE    "\x1b[34m"
#define LOG_CODE_COLOR_MAGENTA "\x1b[35m"
#define LOG_CODE_COLOR_CYAN    "\x1b[36m"
#define LOG_CODE_COLOR_WHITE   "\x1b[37m"
#define LOG_CODE_COLOR_DEFAULT "\x1b[39m"

#define LOG_CODE_BG_COLOR_BLACK   "\x1b[40m"
#define LOG_CODE_BG_COLOR_RED     "\x1b[41m"
#define LOG_CODE_BG_COLOR_GREEN   "\x1b[42m"
#define LOG_CODE_BG_COLOR_YELLOW  "\x1b[43m"
#define LOG_CODE_BG_COLOR_BLUE    "\x1b[44m"
#define LOG_CODE_BG_COLOR_MAGENTA "\x1b[45m"
#define LOG_CODE_BG_COLOR_CYAN    "\x1b[46m"
#define LOG_CODE_BG_COLOR_WHITE   "\x1b[47m"
#define LOG_CODE_BG_COLOR_DEFAULT "\x1b[49m"

#define LOG_CODE_COLOR_BRIGHT_RED     "\x1b[91m"
#define LOG_CODE_COLOR_BRIGHT_GREEN   "\x1b[92m"
#define LOG_CODE_COLOR_BRIGHT_YELLOW  "\x1b[93m"
#define LOG_CODE_COLOR_BRIGHT_BLUE    "\x1b[94m"
#define LOG_CODE_COLOR_BRIGHT_MAGENTA "\x1b[95m"
#define LOG_CODE_COLOR_BRIGHT_CYAN    "\x1b[96m"
#define LOG_CODE_COLOR_BRIGHT_WHITE   "\x1b[97m"

#define LOG_CODE_BG_COLOR_BRIGHT_RED     "\x1b[101m"
#define LOG_CODE_BG_COLOR_BRIGHT_GREEN   "\x1b[102m"
#define LOG_CODE_BG_COLOR_BRIGHT_YELLOW  "\x1b[103m"
#define LOG_CODE_BG_COLOR_BRIGHT_BLUE    "\x1b[104m"
#define LOG_CODE_BG_COLOR_BRIGHT_MAGENTA "\x1b[105m"
#define LOG_CODE_BG_COLOR_BRIGHT_CYAN    "\x1b[106m"
#define LOG_CODE_BG_COLOR_BRIGHT_WHITE   "\x1b[107m"

#define LOG_CODE_CLEAR         "\x1b[0m"
#define LOG_CODE_BOLD          "\x1b[1m"
#define LOG_CODE_FAINT         "\x1b[2m"
#define LOG_CODE_ITALIC        "\x1b[3m"
#define LOG_CODE_UNDERLINE     "\x1b[4m"
#define LOG_CODE_BLINKING      "\x1b[5m"
#define LOG_CODE_HIDDEN        "\x1b[8m"
#define LOG_CODE_STRIKETHROUGH "\x1b[9m"

#define LOG_CODE_TRUE_COLOR(r, g, b) "\x1b[38;2;" #r ";" #g ";" #b "m"

#define LOG_CODE_BG_TRUE_COLOR(r, g, b) "\x1b[48;2;" #r ";" #g ";" #b "m"

#ifndef LOG_LEVEL
#define LOG_LEVEL 4
#endif

#ifndef LOG_CODE_DEBUG
#define LOG_CODE_DEBUG LOG_CODE_COLOR_YELLOW
#endif

#ifndef LOG_CODE_INFO
#define LOG_CODE_INFO LOG_CODE_COLOR_BRIGHT_GREEN
#endif

#ifndef LOG_CODE_WARN
#define LOG_CODE_WARN LOG_CODE_COLOR_BRIGHT_YELLOW
#endif

#ifndef LOG_CODE_ERR
#define LOG_CODE_ERR LOG_CODE_COLOR_BRIGHT_RED
#endif

#if defined(NDEBUG) || LOG_LEVEL < 4
#define LOGF_DEBUG(file, str, ...)
#else
#define LOGF_DEBUG(file, str, ...)                                             \
    do {                                                                       \
        if (isatty(fileno(file))) {                                            \
            fprintf(file,                                                      \
                    LOG_CODE_DEBUG "[DEBUG] %s:%d: " str LOG_CODE_CLEAR,       \
                    __FILE__,                                                  \
                    __LINE__ __VA_OPT__(, ) __VA_ARGS__);                      \
        } else {                                                               \
            fprintf(file,                                                      \
                    "[DEBUG] %s:%d: " str,                                     \
                    __FILE__,                                                  \
                    __LINE__ __VA_OPT__(, ) __VA_ARGS__);                      \
        }                                                                      \
    } while (0)
#endif
#define LOG_DEBUG(str, ...) LOGF_DEBUG(stdout, str, __VA_ARGS__)

#if LOG_LEVEL >= 3
#define LOGF_INFO(file, str, ...)                                              \
    do {                                                                       \
        if (isatty(fileno(file))) {                                            \
            fprintf(file,                                                      \
                    LOG_CODE_INFO "[INFO] %s:%d: " str LOG_CODE_CLEAR,         \
                    __FILE__,                                                  \
                    __LINE__ __VA_OPT__(, ) __VA_ARGS__);                      \
        } else {                                                               \
            fprintf(file,                                                      \
                    "[INFO] %s:%d: " str,                                      \
                    __FILE__,                                                  \
                    __LINE__ __VA_OPT__(, ) __VA_ARGS__);                      \
        }                                                                      \
    } while (0)

#else
#define LOGF_INFO(file, str, ...)
#endif /* LOG_LEVEL >= 3 */
#define LOG_INFO(str, ...) LOGF_INFO(stdout, str, __VA_ARGS__)

#if LOG_LEVEL >= 2
#define LOGF_WARN(file, str, ...)                                              \
    do {                                                                       \
        if (isatty(fileno(file))) {                                            \
            fprintf(file,                                                      \
                    LOG_CODE_WARN "[WARN] %s:%d: " str LOG_CODE_CLEAR,         \
                    __FILE__,                                                  \
                    __LINE__ __VA_OPT__(, ) __VA_ARGS__);                      \
        } else {                                                               \
            fprintf(file,                                                      \
                    "[WARN] %s:%d: " str,                                      \
                    __FILE__,                                                  \
                    __LINE__ __VA_OPT__(, ) __VA_ARGS__);                      \
        }                                                                      \
    } while (0)
#else
#define LOGF_WARN(file, str, ...)
#endif /* LOG_LEVEL >= 2 */
#define LOG_WARN(str, ...) LOGF_WARN(stdout, str, __VA_ARGS__)

#if LOG_LEVEL >= 1
#define LOGF_ERR(file, str, ...)                                               \
    do {                                                                       \
        if (isatty(fileno(file))) {                                            \
            fprintf(file,                                                      \
                    LOG_CODE_ERR "[ERROR] %s:%d: " str LOG_CODE_CLEAR,         \
                    __FILE__,                                                  \
                    __LINE__ __VA_OPT__(, ) __VA_ARGS__);                      \
        } else {                                                               \
            fprintf(file,                                                      \
                    "[ERROR] %s:%d: " str,                                     \
                    __FILE__,                                                  \
                    __LINE__ __VA_OPT__(, ) __VA_ARGS__);                      \
        }                                                                      \
    } while (0)
#else
#define LOGF_ERR(file, str, ...)
#endif /* LOG_LEVEL >= 1*/
#define LOG_ERR(str, ...) LOGF_ERR(stderr, str, __VA_ARGS__)

#endif /* SMALL_LOGGER_H_ */
