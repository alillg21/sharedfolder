#ifndef _DEBUG_H_
#define _DEBUG_H_

#define KFLOG_MAX_SIZE 107 * 2560
#define RECORD_MAX_SIZE 50
#define SIZE_PER_LOG (57 + RECORD_MAX_SIZE)

enum log_type {LOG_INFO, LOG_WARNING, LOG_ERROR, LOG_TYPE_COUNT};

enum log_level {INFO_WARNING_ERROR, WARNING_AND_ERROR, JUST_ERROR, NO_LOG, LOG_LEVEL_COUNT};

enum log_place {WRITE_TO_FILE, SHOW_IN_CONSOLE, CONSOLE_AND_FILE, LOG_PLACE_COUNT};

int get_open_count();

enum log_level get_log_level();
enum log_place get_log_place();

/// Initial log manager
int LM_initial(enum log_level level, enum log_place place);
int LM_close();

int LM_write(enum log_type error, char *msg, int line, char *file);

/// Just use in debug
void LM_dump(const char *title, char *buf, int count, int ascii);
//ªÒ»°∞Ê±æ∫≈
void sdk_GetLibDEBUGVersion(char *sVer);

#define LM_LOG_INFO(fmt...) do {                    \
        char msg[100];                      \
        memset(msg, 0x00, 100);                 \
        sprintf(msg, fmt);                  \
        LM_write(LOG_INFO, msg, __LINE__, __FILE__);        \
    } while(0)

#define LM_LOG_WARNING(fmt...) do {                 \
        char msg[100];                      \
        memset(msg, 0x00, 100);                 \
        sprintf(msg, fmt);                  \
        LM_write(LOG_WARNING, msg, __LINE__, __FILE__);     \
    } while(0)

#define LM_LOG_ERROR(fmt...) do {                   \
        char msg[100];                      \
        memset(msg, 0x00, 100);                 \
        sprintf(msg, fmt);                  \
        LM_write(LOG_ERROR, msg, __LINE__, __FILE__);       \
    } while(0)

/*
int LM_write_info(int line, char *file, char *fmt...);
int LM_write_warning(int line, char *file, char *fmt...);
int LM_write_error(int line, char *file, char *fmt...);

#define LM_LOG_INFO(fmt...) LM_write_info(__LINE__, __FILE__, fmt)
#define LM_LOG_WARNING(fmt...) LM_write_warning(__LINE__, __FILE__, fmt)
#define LM_LOG_ERROR(fmt...) LM_write_error(__LINE__, __FILE__, fmt)
*/

#define WRITE_DEBUG_MESSAGE(X, fmt...) LM_##X(fmt)

#endif
