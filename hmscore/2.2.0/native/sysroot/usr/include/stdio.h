/*	$OpenBSD: stdio.h,v 1.35 2006/01/13 18:10:09 miod Exp $	*/
/*	$NetBSD: stdio.h,v 1.18 1996/04/25 18:29:21 jtc Exp $	*/

/*-
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Chris Torek.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)stdio.h	5.17 (Berkeley) 6/3/91
 */

#ifndef	_STDIO_H_
#define	_STDIO_H_

#include <sys/cdefs.h>
#include <sys/types.h>

#include <stdarg.h>
#include <stddef.h>

#include <bits/seek_constants.h>


__BEGIN_DECLS

typedef off_t fpos_t;
typedef off64_t fpos64_t;

struct __sFILE;
typedef struct __sFILE FILE;

extern FILE* stdin;
extern FILE* stdout;
extern FILE* stderr;

#define stdin stdin
#define stdout stdout
#define stderr stderr

#define	_IOFBF	0
#define	_IOLBF	1
#define	_IONBF	2

#define	BUFSIZ	1024
#define	EOF	(-1)

#define FOPEN_MAX 20
#define FILENAME_MAX 4096

#define L_tmpnam 4096
#define TMP_MAX 308915776

void clearerr(FILE* __fp);
int fclose(FILE* __fp);
int feof(FILE* __fp);
int ferror(FILE* __fp);
int fflush(FILE* __fp);
int fgetc(FILE* __fp);
char* fgets(char* __buf, int __size, FILE* __fp);
int fprintf(FILE* __fp , const char* __fmt, ...) __printflike(2, 3);
int fputc(int __ch, FILE* __fp);
int fputs(const char* __s, FILE* __fp);
size_t fread(void* __buf, size_t __size, size_t __count, FILE* __fp);
int fscanf(FILE* __fp, const char* __fmt, ...) __scanflike(2, 3);
size_t fwrite(const void* __buf, size_t __size, size_t __count, FILE* __fp);
int getc(FILE* __fp);
int getchar(void);
ssize_t getdelim(char** __line_ptr, size_t* __line_length_ptr, int __delimiter, FILE* __fp);
ssize_t getline(char** __line_ptr, size_t* __line_length_ptr, FILE* __fp);

void perror(const char* __msg);
int printf(const char* __fmt, ...) __printflike(1, 2);
int putc(int __ch, FILE* __fp);
int putchar(int __ch);
int puts(const char* __s);
int remove(const char* __path);
void rewind(FILE* __fp);
int scanf(const char* __fmt, ...) __scanflike(1, 2);
void setbuf(FILE* __fp, char* __buf);
int setvbuf(FILE* __fp, char* __buf, int __mode, size_t __size);
int sscanf(const char* __s, const char* __fmt, ...) __scanflike(2, 3);
int ungetc(int __ch, FILE* __fp);
int vfprintf(FILE* __fp, const char* __fmt, va_list __args) __printflike(2, 0);
int vprintf(const char* __fp, va_list __args) __printflike(1, 0);

int dprintf(int __fd, const char* __fmt, ...) __printflike(2, 3);
int vdprintf(int __fd, const char* __fmt, va_list __args) __printflike(2, 0);

#if (defined(__STDC_VERSION__) && __STDC_VERSION__ < 201112L) || \
    (defined(__cplusplus) && __cplusplus <= 201103L)
char* gets(char* __buf) __attribute__((deprecated("gets is unsafe, use fgets instead")));
#endif
int sprintf(char* __s, const char* __fmt, ...)
    __printflike(2, 3) __warnattr_strict("sprintf is often misused; please use snprintf");
int vsprintf(char* __s, const char* __fmt, va_list __args)
    __printflike(2, 0) __warnattr_strict("vsprintf is often misused; please use vsnprintf");
char* tmpnam(char* __s)
    __warnattr("tempnam is unsafe, use mkstemp or tmpfile instead");
#define P_tmpdir "/tmp/"
char* tempnam(const char* __dir, const char* __prefix)
    __warnattr("tempnam is unsafe, use mkstemp or tmpfile instead");

int rename(const char* __old_path, const char* __new_path);
int renameat(int __old_dir_fd, const char* __old_path, int __new_dir_fd, const char* __new_path);

int fseek(FILE* __fp, long __offset, int __whence);
long ftell(FILE* __fp);

#if defined(__USE_FILE_OFFSET64)
int fgetpos(FILE* __fp, fpos_t* __pos) __RENAME(fgetpos64);
int fsetpos(FILE* __fp, const fpos_t* __pos) __RENAME(fsetpos64);
int fseeko(FILE* __fp, off_t __offset, int __whence) __RENAME(fseeko64);
off_t ftello(FILE* __fp) __RENAME(ftello64);
#  if defined(__USE_BSD)
#  endif
#else
int fgetpos(FILE* __fp, fpos_t* __pos);
int fsetpos(FILE* __fp, const fpos_t* __pos);
int fseeko(FILE* __fp, off_t __offset, int __whence);
off_t ftello(FILE* __fp);
#  if defined(__USE_BSD)
#  endif
#endif
int fgetpos64(FILE* __fp, fpos64_t* __pos);
int fsetpos64(FILE* __fp, const fpos64_t* __pos);
int fseeko64(FILE* __fp, off64_t __offset, int __whence);
off64_t ftello64(FILE* __fp);
#if defined(__USE_BSD)
#endif

FILE* fopen(const char* __path, const char* __mode);
FILE* fopen64(const char* __path, const char* __mode);
FILE* freopen(const char* __path, const char* __mode, FILE* __fp);
FILE* freopen64(const char* __path, const char* __mode, FILE* __fp);
FILE* tmpfile(void);
FILE* tmpfile64(void);

int snprintf(char* __buf, size_t __size, const char* __fmt, ...) __printflike(3, 4);
int vfscanf(FILE* __fp, const char* __fmt, va_list __args) __scanflike(2, 0);
int vscanf(const char* __fmt , va_list __args) __scanflike(1, 0);
int vsnprintf(char* __buf, size_t __size, const char* __fmt, va_list __args) __printflike(3, 0);
int vsscanf(const char* __s, const char* __fmt, va_list __args) __scanflike(2, 0);

#define L_ctermid 1024
char* ctermid(char* __buf);

FILE* fdopen(int __fd, const char* __mode);
int fileno(FILE* __fp);
int pclose(FILE* __fp);
FILE* popen(const char* __command, const char* __mode);
void flockfile(FILE* __fp);
int ftrylockfile(FILE* __fp);
void funlockfile(FILE* __fp);
int getc_unlocked(FILE* __fp);
int getchar_unlocked(void);
int putc_unlocked(int __ch, FILE* __fp);
int putchar_unlocked(int __ch);

FILE* fmemopen(void* __buf, size_t __size, const char* __mode);
FILE* open_memstream(char** __ptr, size_t* __size_ptr);

#if defined(__USE_BSD) || defined(__BIONIC__)
int  asprintf(char** __s_ptr, const char* __fmt, ...) __printflike(2, 3);
char* fgetln(FILE* __fp, size_t* __length_ptr);
void setbuffer(FILE* __fp, char* __buf, int __size);
int setlinebuf(FILE* __fp);
int vasprintf(char** __s_ptr, const char* __fmt, va_list __args) __printflike(2, 0);
void clearerr_unlocked(FILE* __fp);
int feof_unlocked(FILE* __fp);
int ferror_unlocked(FILE* __fp);
int fileno_unlocked(FILE* __fp);
#endif

#if defined(__USE_BSD)
int fflush_unlocked(FILE* __fp);
int fgetc_unlocked(FILE* __fp);
int fputc_unlocked(int __ch, FILE* __fp);
size_t fread_unlocked(void* __buf, size_t __size, size_t __count, FILE* __fp);
size_t fwrite_unlocked(const void* __buf, size_t __size, size_t __count, FILE* __fp);
#endif

#if defined(__USE_GNU)
int fputs_unlocked(const char* __s, FILE* __fp);
char* fgets_unlocked(char* __buf, int __size, FILE* __fp);
#endif


__END_DECLS

#endif
