#ifndef DEBUG_H
#define DEBUG_H

#if defined(GLOBAL_DEBUG_ON)

#define ANSI_BLACK     "\033[30m"
#define ANSI_RED       "\033[31m"
#define ANSI_GREEN     "\033[32m"
#define ANSI_YELLOW    "\033[33m"
#define ANSI_BLUE      "\033[34m"
#define ANSI_MAGENTA   "\033[35m"
#define ANSI_CYAN      "\033[36m"
#define ANSI_WHITE     "\033[37m"

#define ANSI_LIGHTBLACK     "\033[90m"
#define ANSI_LIGHTRED       "\033[91m"
#define ANSI_LIGHTGREEN     "\033[92m"
#define ANSI_LIGHTYELLOW    "\033[93m"
#define ANSI_LIGHTBLUE      "\033[94m"
#define ANSI_LIGHTMAGENTA   "\033[95m"
#define ANSI_LIGHTCYAN      "\033[96m"
#define ANSI_LIGHTWHITE     "\033[97m"

#define ANSI_CLEAR     "\033[0m"


#define CR  "\r\n"
#define IPPSTR  IPSTR":%d"
#define IPP2STR(t)  IP2STR((t)->remote_ip), (t)->remote_port
#define IPP2STR_LOCAL(t)  IP2STR((t)->local_ip), (t)->local_port
#define STARTSWITH(str, searchfor) \
    (strncmp(searchfor, str, strlen(searchfor)) == 0)


#define PRINTLN( fmt, c, ... ) os_printf( \
        c"%s:%d"ANSI_LIGHTMAGENTA" [%s] "ANSI_CLEAR fmt CR, \
        __FILE__, __LINE__, __func__, ## __VA_ARGS__ )

#define INFO( fmt, ... )   PRINTLN(fmt, ANSI_LIGHTBLUE, ## __VA_ARGS__ )
#define ERROR( fmt, ... )  PRINTLN(fmt, ANSI_LIGHTRED, ## __VA_ARGS__ )
#define DEBUG( fmt, ... )  PRINTLN(fmt, ANSI_LIGHTYELLOW, ## __VA_ARGS__ )
#define CHK( fmt, ... )    PRINTLN(fmt, ANSI_LIGHTGREEN, ## __VA_ARGS__ )

#else

#define INFO( format, ... )
#define DEBUG( format, ... )
#define ERROR( format, ... )
#define CHK( format, ... )

#endif


#endif
