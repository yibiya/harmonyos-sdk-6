/*
 * Copyright (C) 2017 The Android Open Source Project
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

#pragma once


#include <sys/cdefs.h>

#include <linux/wait.h>

#define WEXITSTATUS(__status) (((__status) & 0xff00) >> 8)

#define WCOREDUMP(__status) ((__status) & 0x80)

#define WTERMSIG(__status) ((__status) & 0x7f)

#define WSTOPSIG(__status) WEXITSTATUS(__status)

#define WIFEXITED(__status) (WTERMSIG(__status) == 0)

#define WIFSTOPPED(__status) (WTERMSIG(__status) == 0x7f)

#define WIFSIGNALED(__status) (WTERMSIG((__status)+1) >= 2)

#define WIFCONTINUED(__status) ((__status) == 0xffff)

#define W_EXITCODE(__exit_code, __signal_number) ((__exit_code) << 8 | (__signal_number))

#define W_STOPCODE(__signal_number) ((__signal_number) << 8 | 0x7f)
