/*
 * Copyright (C) 2008 The Android Open Source Project
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef _STRING_H
#define _STRING_H

#include <sys/cdefs.h>
#include <stddef.h>
#include <xlocale.h>

#include <bits/strcasecmp.h>

__BEGIN_DECLS

#if defined(__USE_BSD)
#include <strings.h>
#endif

void* memccpy(void* __dst, const void* __src, int __stop_char, size_t __n);
void* memchr(const void* __s, int __ch, size_t __n) __attribute_pure__;
#if defined(__cplusplus)
extern "C++" void* memrchr(void* __s, int __ch, size_t __n) __RENAME(memrchr) __attribute_pure__;
extern "C++" const void* memrchr(const void* __s, int __ch, size_t __n) __RENAME(memrchr) __attribute_pure__;
#else
void* memrchr(const void* __s, int __ch, size_t __n) __attribute_pure__;
#endif
int memcmp(const void* __lhs, const void* __rhs, size_t __n) __attribute_pure__;
void* memcpy(void*, const void*, size_t);
#if defined(__USE_GNU)
void* mempcpy(void* __dst, const void* __src, size_t __n);
#endif
void* memmove(void* __dst, const void* __src, size_t __n);
void* memset(void* __dst, int __ch, size_t __n);
void* memmem(const void* __haystack, size_t __haystack_size, const void* __needle, size_t __needle_size) __attribute_pure__;

char* strchr(const char* __s, int __ch) __attribute_pure__;
#if defined(__USE_GNU)
#if defined(__cplusplus)
extern "C++" char* strchrnul(char* __s, int __ch) __RENAME(strchrnul) __attribute_pure__;
extern "C++" const char* strchrnul(const char* __s, int __ch) __RENAME(strchrnul) __attribute_pure__;
#else
char* strchrnul(const char* __s, int __ch) __attribute_pure__;
#endif
#endif

char* strrchr(const char* __s, int __ch) __attribute_pure__;

size_t strlen(const char* __s) __attribute_pure__;

int strcmp(const char* __lhs, const char* __rhs) __attribute_pure__;
char* stpcpy(char* __dst, const char* __src);
char* strcpy(char* __dst, const char* __src);
char* strcat(char* __dst, const char* __src);
char* strdup(const char* __s);

char* strstr(const char* __haystack, const char* __needle) __attribute_pure__;
#if defined(__cplusplus)
extern "C++" char* strcasestr(char*, const char*) __RENAME(strcasestr) __attribute_pure__;
extern "C++" const char* strcasestr(const char*, const char*) __RENAME(strcasestr) __attribute_pure__;
#else
char* strcasestr(const char* __haystack, const char* __needle) __attribute_pure__;
#endif
char* strtok(char* __s, const char* __delimiter);
char* strtok_r(char* __s, const char* __delimiter, char** __pos_ptr);

char* strerror(int __errno_value);
char* strerror_l(int __errno_value, locale_t __l);
#if defined(__USE_GNU)
char* strerror_r(int __errno_value, char* __buf, size_t __n) __RENAME(__gnu_strerror_r);
#else
int strerror_r(int __errno_value, char* __buf, size_t __n);
#endif

size_t strnlen(const char* __s, size_t __n) __attribute_pure__;
char* strncat(char* __dst, const char* __src, size_t __n);
char* strndup(const char* __s, size_t __n);
int strncmp(const char* __lhs, const char* __rhs, size_t __n) __attribute_pure__;
char* stpncpy(char* __dst, const char* __src, size_t __n);
char* strncpy(char* __dst, const char* __src, size_t __n);

size_t strlcat(char* __dst, const char* __src, size_t __n);
size_t strlcpy(char* __dst, const char* __src, size_t __n);

size_t strcspn(const char* __s, const char* __reject) __attribute_pure__;
char* strpbrk(const char* __s, const char* __accept) __attribute_pure__;
char* strsep(char** __s_ptr, const char* __delimiter);
size_t strspn(const char* __s, const char* __accept);

char* strsignal(int __signal);

int strcoll(const char* __lhs, const char* __rhs) __attribute_pure__;
size_t strxfrm(char* __dst, const char* __src, size_t __n);

int strcoll_l(const char* __lhs, const char* __rhs, locale_t __l) __attribute_pure__;
size_t strxfrm_l(char* __dst, const char* __src, size_t __n, locale_t __l);

#if defined(__USE_GNU) && !defined(basename)
#if defined(__cplusplus)
extern "C++" char* basename(char* __path) __RENAME(__gnu_basename);
extern "C++" const char* basename(const char* __path) __RENAME(__gnu_basename);
#else
char* basename(const char* __path) __RENAME(__gnu_basename);
#endif
#endif


#if defined(__cplusplus)
#define __prefer_this_overload __enable_if(true, "preferred overload") __enable_if(true, "")
extern "C++" {
inline __always_inline
void* __bionic_memchr(const void* const s __pass_object_size, int c, size_t n) {
    return memchr(s, c, n);
}

inline __always_inline
const void* memchr(const void* const s __pass_object_size, int c, size_t n)
        __prefer_this_overload {
    return __bionic_memchr(s, c, n);
}

inline __always_inline
void* memchr(void* const s __pass_object_size, int c, size_t n) __prefer_this_overload {
    return __bionic_memchr(s, c, n);
}

inline __always_inline
char* __bionic_strchr(const char* const s __pass_object_size, int c) {
    return strchr(s, c);
}

inline __always_inline
const char* strchr(const char* const s __pass_object_size, int c)
        __prefer_this_overload {
    return __bionic_strchr(s, c);
}

inline __always_inline
char* strchr(char* const s __pass_object_size, int c)
        __prefer_this_overload {
    return __bionic_strchr(s, c);
}

inline __always_inline
char* __bionic_strrchr(const char* const s __pass_object_size, int c) {
    return strrchr(s, c);
}

inline __always_inline
const char* strrchr(const char* const s __pass_object_size, int c) __prefer_this_overload {
    return __bionic_strrchr(s, c);
}

inline __always_inline
char* strrchr(char* const s __pass_object_size, int c) __prefer_this_overload {
    return __bionic_strrchr(s, c);
}

inline __always_inline
char* __bionic_strstr(const char* h, const char* n) { return strstr(h, n); }

inline __always_inline
const char* strstr(const char* h, const char* n) __prefer_this_overload {
    return __bionic_strstr(h, n);
}

inline __always_inline
char* strstr(char* h, const char* n) __prefer_this_overload {
    return __bionic_strstr(h, n);
}

inline __always_inline
char* __bionic_strpbrk(const char* h, const char* n) { return strpbrk(h, n); }

inline __always_inline
char* strpbrk(char* h, const char* n) __prefer_this_overload {
    return __bionic_strpbrk(h, n);
}

inline __always_inline
const char* strpbrk(const char* h, const char* n) __prefer_this_overload {
    return __bionic_strpbrk(h, n);
}
}
#undef __prefer_this_overload
#endif

__END_DECLS

#endif
