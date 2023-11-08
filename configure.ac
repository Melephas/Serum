#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.71])
AC_INIT([sandbox], [0.1.0], [BUG-REPORT-ADDRESS])
AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([foreign])

AC_USE_SYSTEM_EXTENSIONS

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_FUNC_ALLOCA
AC_CHECK_HEADERS([stdint.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT64_T
AC_TYPE_INT8_T
AC_TYPE_MODE_T
AC_TYPE_OFF_T
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_STRUCT_TIMEZONE
AC_TYPE_UID_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_UINT8_T
AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.
AC_FUNC_FSEEKO
AC_FUNC_MALLOC
AC_FUNC_MBRTOWC
AC_FUNC_MKTIME
AC_FUNC_REALLOC
AC_FUNC_STRCOLL
AC_FUNC_STRERROR_R
AC_FUNC_STRNLEN
AC_FUNC_STRTOD
AC_CHECK_FUNCS([atexit btowc bzero clock_gettime getdelim isascii iswprint localtime_r mblen mbrlen memchr memmove memset putenv realpath rpmatch setenv stpcpy strcasecmp strchr strcspn strdup strerror strncasecmp strndup strpbrk strrchr strspn strstr strtol strtoul strtoull tzset wcwidth])

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT
