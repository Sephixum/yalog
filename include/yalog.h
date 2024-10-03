#ifndef __YALOG_H
#define __YALOG_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef enum log_level {
    LOG_TRACE = 0,
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR,
    LOG_FATAL
} log_level_t;

typedef struct log_event {
    const char *format;
    const char *file;
    struct tm *time;
    void *stream;
    va_list argument_list;
    uint32_t line;
    log_level_t level;
} log_event_t;

void yalog_log(const log_level_t level, //
               const char *file,        //
               const uint32_t line,     //
               const char *format,      //
               ...                      //
);

#define YALOG_TRACE(fmt) yalog_log(LOG_TRACE, __FILE_NAME__, __LINE__, fmt)
#define YALOG_DEBUG(fmt) yalog_log(LOG_DEBUG, __FILE_NAME__, __LINE__, fmt)
#define YALOG_INFO(fmt) yalog_log(LOG_INFO, __FILE_NAME__, __LINE__, fmt)
#define YALOG_WARN(fmt) yalog_log(LOG_WARN, __FILE_NAME__, __LINE__, fmt)
#define YALOG_ERROR(fmt) yalog_log(LOG_ERROR, __FILE_NAME__, __LINE__, fmt)
#define YALOG_FATAL(fmt) yalog_log(LOG_FATAL, __FILE_NAME__, __LINE__, fmt)

#define YALOG_TRACE_F(fmt, ...)                                                \
    yalog_log(LOG_TRACE, __FILE_NAME__, __LINE__, fmt, __VA_ARGS__)
#define YALOG_DEBUG_F(fmt, ...)                                                \
    yalog_log(LOG_DEBUG, __FILE_NAME__, __LINE__, fmt, __VA_ARGS__)
#define YALOG_INFO_F(fmt, ...)                                                 \
    yalog_log(LOG_INFO, __FILE_NAME__, __LINE__, fmt, __VA_ARGS__)
#define YALOG_WARN_F(fmt, ...)                                                 \
    yalog_log(LOG_WARN, __FILE_NAME__, __LINE__, fmt, __VA_ARGS__)
#define YALOG_ERROR_F(fmt, ...)                                                \
    yalog_log(LOG_ERROR, __FILE_NAME__, __LINE__, fmt, __VA_ARGS__)
#define YALOG_FATAL_F(fmt, ...)                                                \
    yalog_log(LOG_FATAL, __FILE_NAME__, __LINE__, fmt, __VA_ARGS__)

#endif // !__YALOG_H
