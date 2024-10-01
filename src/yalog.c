#include "yalog.h"

#define RESET "\033[0m"
#define BOLD "\033[1m"

#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define ORANGE "\033[38;5;208m"
#define GRAY "\x1b[90m"

/**
 * Use of anonymous structure to manage
 * static option data.
 *
 * static struct {
 *     bool quiet;
 * } opts;
 *
 */

static const char *log_level_strings[] = {
    "TRACE", //
    "DEBUG", //
    "INFO",  //
    "WARN",  //
    "ERROR", //
    "FATAL"  //
};

static const char *log_level_colors[] = {CYAN,   //
                                         BLUE,   //
                                         WHITE,  //
                                         YELLOW, //
                                         RED,    //
                                         ORANGE};
static const char *log_level_to_string(log_level_t level) {
    return log_level_strings[level];
}

static const char *log_level_to_color(log_level_t level) {
    return log_level_colors[level];
}

static void write_to_stream(log_event_t *event) {
    char buffer[16] = {0};
    size_t written_string_size = //
        strftime(buffer,         //
                 sizeof(buffer), //
                 "%H:%M:%S",     //
                 event->time     //
        );

    if (!written_string_size) {
        fprintf(stderr, "strftime failed.");
    }

    /* *
     * Since strftime does not add a terminating
     * character we manually add it to the buffer.
     * The written_string_size variable is the number
     * of characters written to buffer which is used
     * to point to last index of the buffer.
     *
     */
    buffer[written_string_size] = '\0';

    fprintf(event->stream,                               //
            "%s " BOLD "%s%-5s " GRAY "[%s:%d]: " RESET, //
            buffer,                                      //
            log_level_to_color(event->level),            //
            log_level_to_string(event->level),           //
            event->file,                                 //
            event->line                                  //
    );
    vfprintf(stdout, event->format, event->argument_list);
    fprintf(stdout, "\n");
    fflush(stdout);
}

static void initialize_event_time(log_event_t *event) {
    if (event->time) {
        return;
    }

    time_t absolute_time = time(NULL);
    event->time = localtime(&absolute_time);
}

void yalog_log(const log_level_t level, //
               const char *file,        //
               const uint32_t line,     //
               const char *format,      //
               ...                      //
) {
    log_event_t event = {
        .format = format, //
        .line = line,     //
        .level = level,   //
        .file = file,     //
    };
    initialize_event_time(&event);

    switch (level) {
    case LOG_WARN:
    case LOG_ERROR:
    case LOG_FATAL:
        event.stream = stderr;
        break;

    default:
        event.stream = stdout;
    }

    va_start(event.argument_list, format);
    va_end(event.argument_list);

    write_to_stream(&event);
}
