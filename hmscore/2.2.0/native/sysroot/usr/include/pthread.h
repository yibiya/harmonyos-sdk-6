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

#ifndef _PTHREAD_H_
#define _PTHREAD_H_

#include <limits.h>
#include <bits/pthread_types.h>
#include <sched.h>
#include <sys/cdefs.h>
#include <sys/types.h>
#include <time.h>

__BEGIN_DECLS

enum {
  PTHREAD_MUTEX_NORMAL = 0,
  PTHREAD_MUTEX_RECURSIVE = 1,
  PTHREAD_MUTEX_ERRORCHECK = 2,

  PTHREAD_MUTEX_ERRORCHECK_NP = PTHREAD_MUTEX_ERRORCHECK,
  PTHREAD_MUTEX_RECURSIVE_NP  = PTHREAD_MUTEX_RECURSIVE,

  PTHREAD_MUTEX_DEFAULT = PTHREAD_MUTEX_NORMAL
};

#define PTHREAD_MUTEX_INITIALIZER { { ((PTHREAD_MUTEX_NORMAL & 3) << 14) } }
#define PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP { { ((PTHREAD_MUTEX_RECURSIVE & 3) << 14) } }
#define PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP { { ((PTHREAD_MUTEX_ERRORCHECK & 3) << 14) } }

#define PTHREAD_COND_INITIALIZER  { { 0 } }
#define PTHREAD_COND_INITIALIZER_MONOTONIC_NP  { { 1 << 1 } }

#define PTHREAD_RWLOCK_INITIALIZER  { { 0 } }

enum {
  PTHREAD_RWLOCK_PREFER_READER_NP = 0,
  PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP = 1,
};

#define PTHREAD_ONCE_INIT 0

#define PTHREAD_BARRIER_SERIAL_THREAD -1

#if defined(__LP64__)
#define PTHREAD_STACK_MIN (4 * PAGE_SIZE)
#else
#define PTHREAD_STACK_MIN (2 * PAGE_SIZE)
#endif

#define PTHREAD_CREATE_DETACHED 1
#define PTHREAD_CREATE_JOINABLE 0

#define PTHREAD_EXPLICIT_SCHED 0
#define PTHREAD_INHERIT_SCHED 1

#define PTHREAD_PRIO_NONE 0
#define PTHREAD_PRIO_INHERIT 1

#define PTHREAD_PROCESS_PRIVATE 0
#define PTHREAD_PROCESS_SHARED 1

#define PTHREAD_SCOPE_SYSTEM 0
#define PTHREAD_SCOPE_PROCESS 1

int pthread_atfork(void (*__prepare)(void), void (*__parent)(void), void (*__child)(void));

int pthread_attr_destroy(pthread_attr_t* __attr);
int pthread_attr_getdetachstate(const pthread_attr_t* __attr, int* __state);
int pthread_attr_getguardsize(const pthread_attr_t* __attr, size_t* __size);
int pthread_attr_getinheritsched(const pthread_attr_t* __attr, int* __flag);
int pthread_attr_getschedparam(const pthread_attr_t* __attr, struct sched_param* __param);
int pthread_attr_getschedpolicy(const pthread_attr_t* __attr, int* __policy);
int pthread_attr_getscope(const pthread_attr_t* __attr, int* __scope);
int pthread_attr_getstack(const pthread_attr_t* __attr, void** __addr, size_t* __size);
int pthread_attr_getstacksize(const pthread_attr_t* __attr, size_t* __size);
int pthread_attr_init(pthread_attr_t* __attr);
int pthread_attr_setdetachstate(pthread_attr_t* __attr, int __state);
int pthread_attr_setguardsize(pthread_attr_t* __attr, size_t __size);
int pthread_attr_setinheritsched(pthread_attr_t* __attr, int __flag);
int pthread_attr_setschedparam(pthread_attr_t* __attr, const struct sched_param* __param);
int pthread_attr_setschedpolicy(pthread_attr_t* __attr, int __policy);
int pthread_attr_setscope(pthread_attr_t* __attr, int __scope);
int pthread_attr_setstack(pthread_attr_t* __attr, void* __addr, size_t __size);
int pthread_attr_setstacksize(pthread_attr_t* __addr, size_t __size);

int pthread_condattr_destroy(pthread_condattr_t* __attr);
int pthread_condattr_getclock(const pthread_condattr_t* __attr, clockid_t* __clock);
int pthread_condattr_getpshared(const pthread_condattr_t* __attr, int* __shared);
int pthread_condattr_init(pthread_condattr_t* __attr);
int pthread_condattr_setclock(pthread_condattr_t* __attr, clockid_t __clock);
int pthread_condattr_setpshared(pthread_condattr_t* __attr, int __shared);

int pthread_cond_broadcast(pthread_cond_t* __cond);
int pthread_cond_destroy(pthread_cond_t* __cond);
int pthread_cond_init(pthread_cond_t* __cond, const pthread_condattr_t* __attr);
int pthread_cond_signal(pthread_cond_t* __cond);
int pthread_cond_timedwait(pthread_cond_t* __cond, pthread_mutex_t* __mutex, const struct timespec* __timeout);
int pthread_cond_wait(pthread_cond_t* __cond, pthread_mutex_t* __mutex);

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wbuiltin-requires-header"
#endif
int pthread_create(pthread_t* __pthread_ptr, pthread_attr_t const* __attr, void* (*__start_routine)(void*), void*);
#if defined(__clang__)
#pragma clang diagnostic pop
#endif

int pthread_detach(pthread_t __pthread);
void pthread_exit(void* __return_value) __noreturn;

int pthread_equal(pthread_t __lhs, pthread_t __rhs);

int pthread_getattr_np(pthread_t __pthread, pthread_attr_t* __attr);

int pthread_getcpuclockid(pthread_t __pthread, clockid_t* __clock);

int pthread_getschedparam(pthread_t __pthread, int* __policy, struct sched_param* __param);

void* pthread_getspecific(pthread_key_t __key);


int pthread_join(pthread_t __pthread, void** __return_value_ptr);

int pthread_key_create(pthread_key_t* __key_ptr, void (*__key_destructor)(void*));
int pthread_key_delete(pthread_key_t __key);

int pthread_mutexattr_destroy(pthread_mutexattr_t* __attr);
int pthread_mutexattr_getpshared(const pthread_mutexattr_t* __attr, int* __shared);
int pthread_mutexattr_gettype(const pthread_mutexattr_t* __attr, int* __type);
int pthread_mutexattr_getprotocol(const pthread_mutexattr_t* __attr, int* __protocol);
int pthread_mutexattr_init(pthread_mutexattr_t* __attr);
int pthread_mutexattr_setpshared(pthread_mutexattr_t* __attr, int __shared);
int pthread_mutexattr_settype(pthread_mutexattr_t* __attr, int __type);
int pthread_mutexattr_setprotocol(pthread_mutexattr_t* __attr, int __protocol);

int pthread_mutex_destroy(pthread_mutex_t* __mutex);
int pthread_mutex_init(pthread_mutex_t* __mutex, const pthread_mutexattr_t* __attr);
int pthread_mutex_lock(pthread_mutex_t* __mutex);
int pthread_mutex_timedlock(pthread_mutex_t* __mutex, const struct timespec* __timeout)
;

int pthread_mutex_trylock(pthread_mutex_t* __mutex);
int pthread_mutex_unlock(pthread_mutex_t* __mutex);


int pthread_once(pthread_once_t* __once, void (*__init_routine)(void));

int pthread_rwlockattr_init(pthread_rwlockattr_t* __attr);
int pthread_rwlockattr_destroy(pthread_rwlockattr_t* __attr);
int pthread_rwlockattr_getpshared(const pthread_rwlockattr_t* __attr, int* __shared);
int pthread_rwlockattr_setpshared(pthread_rwlockattr_t* __attr, int __shared);
int pthread_rwlockattr_getkind_np(const pthread_rwlockattr_t* __attr, int* __kind)
;
int pthread_rwlockattr_setkind_np(pthread_rwlockattr_t* __attr, int __kind);

int pthread_rwlock_destroy(pthread_rwlock_t* __rwlock);
int pthread_rwlock_init(pthread_rwlock_t* __rwlock, const pthread_rwlockattr_t* __attr);
int pthread_rwlock_rdlock(pthread_rwlock_t* __rwlock);
int pthread_rwlock_timedrdlock(pthread_rwlock_t* __rwlock, const struct timespec* __timeout);
int pthread_rwlock_timedwrlock(pthread_rwlock_t* __rwlock, const struct timespec* __timeout);
int pthread_rwlock_tryrdlock(pthread_rwlock_t* __rwlock);
int pthread_rwlock_trywrlock(pthread_rwlock_t* __rwlock);
int pthread_rwlock_unlock(pthread_rwlock_t* __rwlock);
int pthread_rwlock_wrlock(pthread_rwlock_t* __rwlock);

int pthread_barrierattr_init(pthread_barrierattr_t* __attr);
int pthread_barrierattr_destroy(pthread_barrierattr_t* __attr);
int pthread_barrierattr_getpshared(const pthread_barrierattr_t* __attr, int* __shared);
int pthread_barrierattr_setpshared(pthread_barrierattr_t* __attr, int __shared);

int pthread_barrier_init(pthread_barrier_t* __barrier, const pthread_barrierattr_t* __attr, unsigned __count);
int pthread_barrier_destroy(pthread_barrier_t* __barrier);
int pthread_barrier_wait(pthread_barrier_t* __barrier);

int pthread_spin_destroy(pthread_spinlock_t* __spinlock);
int pthread_spin_init(pthread_spinlock_t* __spinlock, int __shared);
int pthread_spin_lock(pthread_spinlock_t* __spinlock);
int pthread_spin_trylock(pthread_spinlock_t* __spinlock);
int pthread_spin_unlock(pthread_spinlock_t* __spinlock);

pthread_t pthread_self(void) __attribute_const__;

#if defined(__USE_GNU)
int pthread_getname_np(pthread_t __pthread, char* __buf, size_t __n);
#endif
int pthread_setname_np(pthread_t __pthread, const char* __name);

int pthread_setschedparam(pthread_t __pthread, int __policy, const struct sched_param* __param);
int pthread_setschedprio(pthread_t __pthread, int __priority);

int pthread_setspecific(pthread_key_t __key, const void* __value);

typedef void (*__pthread_cleanup_func_t)(void*);

typedef struct __pthread_cleanup_t {
  struct __pthread_cleanup_t*   __cleanup_prev;
  __pthread_cleanup_func_t      __cleanup_routine;
  void*                         __cleanup_arg;
} __pthread_cleanup_t;

void __pthread_cleanup_push(__pthread_cleanup_t* c, __pthread_cleanup_func_t, void*);
void __pthread_cleanup_pop(__pthread_cleanup_t*, int);

#define  pthread_cleanup_push(routine, arg)                      \
    do {                                                         \
        __pthread_cleanup_t  __cleanup;                          \
        __pthread_cleanup_push( &__cleanup, (routine), (arg) );  \

#define  pthread_cleanup_pop(execute)                  \
        __pthread_cleanup_pop( &__cleanup, (execute)); \
    } while (0);                                       \

__END_DECLS

#endif
