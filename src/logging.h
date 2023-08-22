#pragma once
extern int bg;
extern int silent;
#define error_print(...)              \
    do                                \
    {                                 \
        if (!silent)                      \
            fprintf(stderr, __VA_ARGS__); \
    } while (0)

#define info_print(...)               \
    do                                \
    {                                 \
        if (!silent)                      \
            fprintf(stderr, __VA_ARGS__); \
    } while (0)

extern int verbose;

#define debug_print(...)                  \
    do                                    \
    {                                     \
        if (verbose)                      \
            fprintf(stderr, __VA_ARGS__); \
    } while (0)
