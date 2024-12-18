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

#ifndef _SYS_STAT_H_
#define _SYS_STAT_H_

#include <bits/timespec.h>
#include <linux/stat.h>
#include <sys/cdefs.h>
#include <sys/types.h>

__BEGIN_DECLS

#if defined(__aarch64__)
#define __STAT64_BODY \
  dev_t st_dev; \
  ino_t st_ino; \
  mode_t st_mode; \
  nlink_t st_nlink; \
  uid_t st_uid; \
  gid_t st_gid; \
  dev_t st_rdev; \
  unsigned long __pad1; \
  off_t st_size; \
  int st_blksize; \
  int __pad2; \
  long st_blocks; \
  struct timespec st_atim; \
  struct timespec st_mtim; \
  struct timespec st_ctim; \
  unsigned int __unused4; \
  unsigned int __unused5; \

#elif defined(__x86_64__)
#define __STAT64_BODY \
  dev_t st_dev; \
  ino_t st_ino; \
  unsigned long st_nlink; \
  mode_t st_mode; \
  uid_t st_uid; \
  gid_t st_gid; \
  unsigned int __pad0; \
  dev_t st_rdev; \
  off_t st_size; \
  long st_blksize; \
  long st_blocks; \
  struct timespec st_atim; \
  struct timespec st_mtim; \
  struct timespec st_ctim; \
  long __pad3[3]; \

#else
#define __STAT64_BODY \
  unsigned long long st_dev; \
  unsigned char __pad0[4]; \
  unsigned long __st_ino; \
  unsigned int st_mode; \
  nlink_t st_nlink; \
  uid_t st_uid; \
  gid_t st_gid; \
  unsigned long long st_rdev; \
  unsigned char __pad3[4]; \
  long long st_size; \
  unsigned long st_blksize; \
  unsigned long long st_blocks; \
  struct timespec st_atim; \
  struct timespec st_mtim; \
  struct timespec st_ctim; \
  unsigned long long st_ino; \

#endif

struct stat { __STAT64_BODY };
struct stat64 { __STAT64_BODY };

#undef __STAT64_BODY

#define st_atime st_atim.tv_sec
#define st_mtime st_mtim.tv_sec
#define st_ctime st_ctim.tv_sec
#define st_atimensec st_atim.tv_nsec
#define st_mtimensec st_mtim.tv_nsec
#define st_ctimensec st_ctim.tv_nsec
#define st_atime_nsec st_atim.tv_nsec
#define st_mtime_nsec st_mtim.tv_nsec
#define st_ctime_nsec st_ctim.tv_nsec

#if defined(__USE_BSD)
#define ACCESSPERMS (S_IRWXU | S_IRWXG | S_IRWXO)
#define ALLPERMS    (S_ISUID | S_ISGID | S_ISVTX | S_IRWXU | S_IRWXG | S_IRWXO)
#define DEFFILEMODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)
#endif

#if defined(__USE_BSD) || defined(__USE_GNU)
#define S_IREAD S_IRUSR
#define S_IWRITE S_IWUSR
#define S_IEXEC S_IXUSR
#endif

#define S_TYPEISMQ(__sb) 0
#define S_TYPEISSEM(__sb) 0
#define S_TYPEISSHM(__sb) 0
#define S_TYPEISTMO(__sb) 0

int chmod(const char* __path, mode_t __mode);
int fchmod(int __fd, mode_t __mode);
int mkdir(const char* __path, mode_t __mode);

int fstat(int __fd, struct stat* __buf);
int fstat64(int __fd, struct stat64* __buf);
int fstatat(int __dir_fd, const char* __path, struct stat* __buf, int __flags);
int fstatat64(int __dir_fd, const char* __path, struct stat64* __buf, int __flags);
int lstat(const char* __path, struct stat* __buf);
int lstat64(const char* __path, struct stat64* __buf);
int stat(const char* __path, struct stat* __buf);
int stat64(const char* __path, struct stat64* __buf);

int mknod(const char* __path, mode_t __mode, dev_t __dev);
mode_t umask(mode_t __mask);


int mkfifo(const char* __path, mode_t __mode);

int mkfifoat(int __dir_fd, const char* __path, mode_t __mode);

int fchmodat(int __dir_fd, const char* __path, mode_t __mode, int __flags);
int mkdirat(int __dir_fd, const char* __path, mode_t __mode);
int mknodat(int __dir_fd, const char* __path, mode_t __mode, dev_t __dev);

#define UTIME_NOW  ((1L << 30) - 1L)
#define UTIME_OMIT ((1L << 30) - 2L)
int utimensat(int __dir_fd, const char* __path, const struct timespec __times[2], int __flags)
;
int futimens(int __dir_fd, const struct timespec __times[2]);

__END_DECLS


#endif
