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

#ifndef _MNTENT_H_
#define _MNTENT_H_

#include <stdio.h>
#include <sys/cdefs.h>
#include <paths.h>

#define MOUNTED _PATH_MOUNTED

#define MNTTYPE_IGNORE "ignore"
#define MNTTYPE_NFS "nfs"
#define MNTTYPE_SWAP "swap"

#define MNTOPT_DEFAULTS "defaults"
#define MNTOPT_NOAUTO "noauto"
#define MNTOPT_NOSUID "nosuid"
#define MNTOPT_RO "ro"
#define MNTOPT_RW "rw"
#define MNTOPT_SUID "suid"

struct mntent {
  char* mnt_fsname;
  char* mnt_dir;
  char* mnt_type;
  char* mnt_opts;
  int mnt_freq;
  int mnt_passno;
};

__BEGIN_DECLS

int endmntent(FILE* __fp);
struct mntent* getmntent(FILE* __fp);
struct mntent* getmntent_r(FILE* __fp, struct mntent* __entry, char* __buf, int __size);
FILE* setmntent(const char* __filename, const char* __type);
char* hasmntopt(const struct mntent* __entry, const char* __option);

__END_DECLS

#endif
