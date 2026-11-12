// SPDX-License-Identifier: GPL-3.0-or-later
#include "types.h"

/* The output callback: writes one character, counts it against *size, returns how many characters it wrote. */
typedef s32 (*PutCharacter)(void *context, u32 *size, s32 character);

s32 func_00235930(PutCharacter out, void *context, u32 *size, double value);

/* Each argument takes one 8-byte slot of the register save area. */
#define VA_ARG(arguments, type) (*(type *)((arguments += 8) - 8))
#define IS_DIGIT(character) ((character) >= '0' && (character) <= '9')

#define FLAG_LEFT 0x1
#define FLAG_PLUS 0x2
#define FLAG_ZERO 0x4
#define FLAG_SPACE 0x8
#define FLAG_ALTERNATE 0x10
#define FLAG_PRECISION 0x20
#define FLAG_LONG 0x40
#define FLAG_SHORT 0x80
#define FLAG_CHARACTER 0x100

/* A small vprintf core: formats format with the arguments at arguments through out, returns the count out reported. */
s32 func_00235B08(PutCharacter out, void *context, u32 size, const char *format, char *arguments)
{
    char buffer[32];
    char prefix[32];
    char *bufferEnd;
    s32 width;
    s32 prefixLength;
    s32 count;
    char *pointer;
    char *start;
    const char *digits;
    char *string;
    u64 value;
    s64 signedValue;
    float floatValue;
    s32 flags;
    s32 precision;
    s32 length;
    s32 index;
    char pad;

    bufferEnd = &buffer[31];
    count = 0;
    for (; *format; *format && format++) {
        flags = 0;
        width = 0;
        precision = 0;
        prefixLength = 0;
        if (*format == '%') {
        again:
                switch (*++format) {
                case '-':
                    flags |= FLAG_LEFT;
                    goto again;
                case '+':
                    flags |= FLAG_PLUS;
                    goto again;
                case '0':
                    flags |= FLAG_ZERO;
                    goto again;
                case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                    index = 0;
                    do {
                        index = index * 10 + (*format++ - '0');
                    } while (IS_DIGIT(*format));
                    width = index;
                checkEnd:
                    if (*format == 0) {
                        continue;
                    }
                    format--;
                    goto again;
                case '.':
                    flags |= FLAG_PRECISION;
                    if (*++format == '*') {
                        index = VA_ARG(arguments, s32);
                        precision = (index >= -1) ? index : -1;
                        goto again;
                    }
                    index = 0;
                    while (IS_DIGIT(*format)) {
                        index = index * 10 + (*format++ - '0');
                    }
                    precision = (index >= -1) ? index : -1;
                    goto checkEnd;
                case ' ':
                    flags |= FLAG_SPACE;
                    goto again;
                case '#':
                    flags |= FLAG_ALTERNATE;
                    goto again;
                case 'l':
                    flags |= FLAG_LONG;
                    goto again;
                case 'h':
                    flags |= FLAG_SHORT;
                    goto again;
                case 'o':
                    if (flags & FLAG_LONG) {
                        value = VA_ARG(arguments, u64);
                    } else if (flags & FLAG_SHORT) {
                        value = VA_ARG(arguments, u16);
                    } else {
                        value = VA_ARG(arguments, u32);
                    }
                    pointer = bufferEnd;
                    if (value == 0) {
                        if (!(flags & FLAG_PRECISION) || precision != 0) {
                            *pointer-- = '0';
                        }
                    } else {
                        do {
                            *pointer-- = (value & 7) + '0';
                            value >>= 3;
                        } while (value);
                        if (flags & FLAG_ALTERNATE) {
                            *pointer-- = '0';
                        }
                    }
                    start = pointer + 1;
                    length = bufferEnd - pointer;
                    break;
                case 'x':
                    digits = "0123456789abcdef";
                    if (flags & FLAG_ALTERNATE) {
                        prefix[0] = '0';
                        prefix[1] = 'x';
                        prefixLength = 2;
                    }
                    goto hexadecimal;
                case 'X':
                    digits = "0123456789ABCDEF";
                    if (flags & FLAG_ALTERNATE) {
                        prefix[0] = '0';
                        prefix[1] = 'X';
                        prefixLength = 2;
                    }
                hexadecimal:
                    if (flags & FLAG_LONG) {
                        value = VA_ARG(arguments, u64);
                    } else if (flags & FLAG_SHORT) {
                        value = VA_ARG(arguments, u16);
                    } else {
                        value = VA_ARG(arguments, u32);
                    }
                    pointer = bufferEnd;
                    if (value == 0) {
                        prefixLength = 0;
                        if (!(flags & FLAG_PRECISION) || precision != 0) {
                            *pointer-- = '0';
                        }
                    } else {
                        do {
                            *pointer-- = digits[value & 15];
                            value >>= 4;
                        } while (value);
                    }
                    start = pointer + 1;
                    length = bufferEnd - pointer;
                    break;
                case 'd':
                case 'i':
                    if (flags & FLAG_LONG) {
                        signedValue = VA_ARG(arguments, s64);
                    } else if (flags & FLAG_SHORT) {
                        signedValue = VA_ARG(arguments, s16);
                    } else {
                        signedValue = VA_ARG(arguments, s32);
                    }
                    pointer = bufferEnd;
                    if (signedValue >= 0) {
                        if (flags & FLAG_PLUS) {
                            prefix[0] = '+';
                            prefixLength = 1;
                        } else if (flags & FLAG_SPACE) {
                            prefix[0] = ' ';
                            prefixLength = 1;
                        }
                    } else {
                        prefix[0] = '-';
                        prefixLength = 1;
                    }
                    if (signedValue == 0) {
                        if (!(flags & FLAG_PRECISION) || precision != 0) {
                            *pointer-- = '0';
                        }
                    } else {
                        if (signedValue < 0) {
                            signedValue = -signedValue;
                        }
                        while (signedValue) {
                            *pointer-- = signedValue % 10 + '0';
                            signedValue /= 10;
                        }
                    }
                    start = pointer + 1;
                    length = bufferEnd - pointer;
                    break;
                case 'u':
                    if (flags & FLAG_LONG) {
                        value = VA_ARG(arguments, u64);
                    } else if (flags & FLAG_SHORT) {
                        value = VA_ARG(arguments, u16);
                    } else {
                        value = VA_ARG(arguments, u32);
                    }
                    pointer = bufferEnd;
                    if (value == 0) {
                        if (!(flags & FLAG_PRECISION) || precision != 0) {
                            *pointer-- = '0';
                        }
                    } else {
                        do {
                            *pointer-- = value % 10 + '0';
                            value /= 10;
                        } while (value);
                    }
                    start = pointer + 1;
                    length = bufferEnd - pointer;
                    break;
                case 'e':
                case 'f':
                    floatValue = VA_ARG(arguments, double);
                    if (floatValue == 0.0f) {
                        count += out(context, &size, '0');
                    } else {
                        count += func_00235930(out, context, &size, floatValue);
                    }
                    continue;
                case 's':
                    string = VA_ARG(arguments, char *);
                    if (string == 0) {
                        out(context, &size, '(');
                        out(context, &size, 'n');
                        out(context, &size, 'u');
                        out(context, &size, 'l');
                        out(context, &size, 'l');
                        out(context, &size, ')');
                        continue;
                    }
                    pointer = string;
                    if (flags & FLAG_PRECISION) {
                        index = 0;
                        while (index < precision && *pointer++) {
                            index++;
                        }
                        length = index;
                    } else {
                        length = 0;
                        while (*pointer) {
                            pointer++;
                            length++;
                        }
                    }
                    start = string;
                    break;
                case 'c':
                    value = VA_ARG(arguments, char);
                    flags |= FLAG_CHARACTER;
                    precision = 1;
                    pointer = bufferEnd;
                    *pointer-- = value;
                    start = pointer + 1;
                    length = bufferEnd - pointer;
                    break;
                case 'p':
                    value = VA_ARG(arguments, u32);
                    digits = "0123456789abcdef";
                    pointer = bufferEnd;
                    if (value == 0) {
                        if (!(flags & FLAG_PRECISION) || precision != 0) {
                            *pointer-- = '0';
                        }
                    } else {
                        do {
                            *pointer-- = digits[value & 15];
                            value >>= 4;
                        } while (value);
                    }
                    prefix[0] = '0';
                    prefix[1] = 'x';
                    prefixLength = 2;
                    start = pointer + 1;
                    length = bufferEnd - pointer;
                    break;
                default:
                    if (*format == 0) {
                        continue;
                    }
                    flags |= FLAG_CHARACTER;
                    precision = 1;
                    pointer = bufferEnd;
                    *pointer-- = *format;
                    start = pointer + 1;
                    length = bufferEnd - pointer;
                    break;
                }
            if (length < precision) {
                precision -= length;
            } else {
                precision = 0;
            }
            width = width - length - prefixLength - precision;
            pointer = start + length;
            if (flags & FLAG_CHARACTER) {
                pad = ' ';
                if ((flags & FLAG_ZERO) && width > 0) {
                    pad = '0';
                }
            } else {
                pad = ' ';
                if ((flags & FLAG_ZERO) && !(flags & FLAG_PRECISION) && width > 0) {
                    pad = '0';
                }
            }
            if (flags & FLAG_LEFT) {
                for (index = 0; index < prefixLength; index++) {
                    count += out(context, &size, prefix[index]);
                }
                for (index = 0; index < precision; index++) {
                    count += out(context, &size, '0');
                }
                while (start < pointer) {
                    count += out(context, &size, *start++);
                }
                for (index = 0; index < width; index++) {
                    count += out(context, &size, ' ');
                }
            } else if (flags & FLAG_ZERO) {
                if (pad == '0') {
                    for (index = 0; index < prefixLength; index++) {
                        count += out(context, &size, prefix[index]);
                    }
                    for (index = 0; index < width; index++) {
                        count += out(context, &size, pad);
                    }
                } else {
                    for (index = 0; index < width; index++) {
                        count += out(context, &size, pad);
                    }
                    for (index = 0; index < prefixLength; index++) {
                        count += out(context, &size, prefix[index]);
                    }
                }
                for (index = 0; index < precision; index++) {
                    count += out(context, &size, '0');
                }
                while (start < pointer) {
                    count += out(context, &size, *start++);
                }
            } else {
                for (index = 0; index < width; index++) {
                    count += out(context, &size, pad);
                }
                for (index = 0; index < prefixLength; index++) {
                    count += out(context, &size, prefix[index]);
                }
                for (index = 0; index < precision; index++) {
                    count += out(context, &size, '0');
                }
                while (start < pointer) {
                    count += out(context, &size, *start++);
                }
            }
        } else if (*format != 0) {
            count += out(context, &size, *format);
        }
    }
    out(context, &size, 0);
    return count;
}
