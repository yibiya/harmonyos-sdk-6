/*	$NetBSD: ttydefaults.h,v 1.16 2008/05/24 14:06:39 yamt Exp $	*/

/*-
 * Copyright (c) 1982, 1986, 1993
 *	The Regents of the University of California.  All rights reserved.
 * (c) UNIX System Laboratories, Inc.
 * All or some portions of this file are derived from material licensed
 * to the University of California by American Telephone and Telegraph
 * Co. or Unix System Laboratories, Inc. and are reproduced herein with
 * the permission of UNIX System Laboratories, Inc.
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
 *	@(#)ttydefaults.h	8.4 (Berkeley) 1/21/94
 */

/*
 * System wide defaults for terminal state.
 */
#ifndef _SYS_TTYDEFAULTS_H_
#define	_SYS_TTYDEFAULTS_H_

#include <sys/cdefs.h>

#define	TTYDEF_IFLAG	(BRKINT | ICRNL | IMAXBEL | IXON | IXANY)
#define TTYDEF_OFLAG	(OPOST | ONLCR | XTABS)
#define TTYDEF_LFLAG	(ECHO | ICANON | ISIG | IEXTEN | ECHOE|ECHOKE|ECHOCTL)
#define TTYDEF_CFLAG	(CREAD | CS8 | HUPCL)
#define TTYDEF_SPEED	(B9600)

#define CTRL(x)	(x&037)
#define	CEOF		CTRL('d')
#define	CEOL		'\0'
#define	CERASE		0177
#define	CINTR		CTRL('c')
#define	CSTATUS		CTRL('t')
#define	CKILL		CTRL('u')
#define	CMIN		1
#define	CQUIT		034
#define	CSUSP		CTRL('z')
#define	CTIME		0
#define	CDSUSP		CTRL('y')
#define	CSTART		CTRL('q')
#define	CSTOP		CTRL('s')
#define	CLNEXT		CTRL('v')
#define	CDISCARD 	CTRL('o')
#define	CWERASE 	CTRL('w')
#define	CREPRINT 	CTRL('r')
#define	CEOT		CEOF
#define	CBRK		CEOL
#define CRPRNT		CREPRINT
#define	CFLUSH		CDISCARD

#endif
