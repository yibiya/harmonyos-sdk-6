/*	$OpenBSD: ip.h,v 1.12 2006/04/27 02:19:32 tedu Exp $	*/
/*	$NetBSD: ip.h,v 1.9 1995/05/15 01:22:44 cgd Exp $	*/

/*
 * Copyright (c) 1982, 1986, 1993
 *	The Regents of the University of California.  All rights reserved.
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
 *	@(#)ip.h	8.1 (Berkeley) 6/10/93
 */

#ifndef _NETINET_IP_H_
#define _NETINET_IP_H_

#include <sys/cdefs.h>
#include <sys/types.h>
#include <endian.h>
#include <netinet/in.h>
#include <netinet/in_systm.h>

__BEGIN_DECLS

#define	IPVERSION	4

struct ip {
	u_int32_t ip_hl:4,
		  ip_v:4;
	u_int8_t  ip_tos;
	u_int16_t ip_len;
	u_int16_t ip_id;
	u_int16_t ip_off;
#define	IP_RF 0x8000
#define	IP_DF 0x4000
#define	IP_MF 0x2000
#define	IP_OFFMASK 0x1fff
	u_int8_t  ip_ttl;
	u_int8_t  ip_p;
	u_int16_t ip_sum;
	struct	  in_addr ip_src, ip_dst;
};

#define	IP_MAXPACKET	65535

#define	IPTOS_LOWDELAY		0x10
#define	IPTOS_THROUGHPUT	0x08
#define	IPTOS_RELIABILITY	0x04
#define	IPTOS_MINCOST		0x02
#if 1
#define IPTOS_CE		0x01
#define IPTOS_ECT		0x02
#endif

#define	IPTOS_PREC_NETCONTROL		0xe0
#define	IPTOS_PREC_INTERNETCONTROL	0xc0
#define	IPTOS_PREC_CRITIC_ECP		0xa0
#define	IPTOS_PREC_FLASHOVERRIDE	0x80
#define	IPTOS_PREC_FLASH		0x60
#define	IPTOS_PREC_IMMEDIATE		0x40
#define	IPTOS_PREC_PRIORITY		0x20
#define	IPTOS_PREC_ROUTINE		0x00

#define	IPTOS_ECN_NOTECT	0x00
#define	IPTOS_ECN_ECT1		0x01
#define	IPTOS_ECN_ECT0		0x02
#define	IPTOS_ECN_CE		0x03
#define	IPTOS_ECN_MASK		0x03

#define	IPOPT_COPIED(o)		((o)&0x80)
#define	IPOPT_CLASS(o)		((o)&0x60)
#define	IPOPT_NUMBER(o)		((o)&0x1f)

#define	IPOPT_CONTROL		0x00
#define	IPOPT_RESERVED1		0x20
#define	IPOPT_DEBMEAS		0x40
#define	IPOPT_RESERVED2		0x60

#define	IPOPT_EOL		0
#define	IPOPT_NOP		1

#define	IPOPT_RR		7
#define	IPOPT_TS		68
#define	IPOPT_SECURITY		130
#define	IPOPT_LSRR		131
#define	IPOPT_SATID		136
#define	IPOPT_SSRR		137

#define	IPOPT_OPTVAL		0
#define	IPOPT_OLEN		1
#define	IPOPT_OFFSET		2
#define	IPOPT_MINOFF		4

struct	ip_timestamp {
	u_int8_t ipt_code;
	u_int8_t ipt_len;
	u_int8_t ipt_ptr;
	u_int32_t ipt_flg:4,
		  ipt_oflw:4;
	union ipt_timestamp {
	n_time	ipt_time[1];
	struct	ipt_ta {
		struct in_addr ipt_addr;
		n_time ipt_time;
	} ipt_ta[1];
	} ipt_timestamp;
};

#define	IPOPT_TS_TSONLY		0
#define	IPOPT_TS_TSANDADDR	1
#define	IPOPT_TS_PRESPEC	3

#define	IPOPT_SECUR_UNCLASS	0x0000
#define	IPOPT_SECUR_CONFID	0xf135
#define	IPOPT_SECUR_EFTO	0x789a
#define	IPOPT_SECUR_MMMM	0xbc4d
#define	IPOPT_SECUR_RESTR	0xaf13
#define	IPOPT_SECUR_SECRET	0xd788
#define	IPOPT_SECUR_TOPSECRET	0x6bc5

#define	MAXTTL		255
#define	IPDEFTTL	64
#define	IPFRAGTTL	60
#define	IPTTLDEC	1

#define	IP_MSS		576

struct ippseudo {
	struct    in_addr ippseudo_src;
	struct    in_addr ippseudo_dst;
	u_int8_t  ippseudo_pad;
	u_int8_t  ippseudo_p;
	u_int16_t ippseudo_len;
};


#define IPOPT_OPTVAL 0
#define IPOPT_OLEN   1
#define IPOPT_OFFSET 2
#define IPOPT_MINOFF 4
#define MAX_IPOPTLEN 40

#define IPOPT_COPY		0x80
#define IPOPT_CLASS_MASK	0x60
#define IPOPT_NUMBER_MASK	0x1f

#define	IPOPT_CONTROL		0x00
#define	IPOPT_RESERVED1		0x20
#define	IPOPT_MEASUREMENT	0x40
#define	IPOPT_RESERVED2		0x60

#define IPOPT_END	(0 |IPOPT_CONTROL)
#define IPOPT_NOOP	(1 |IPOPT_CONTROL)
#define IPOPT_SEC	(2 |IPOPT_CONTROL|IPOPT_COPY)
#define IPOPT_TIMESTAMP	(4 |IPOPT_MEASUREMENT)
#define IPOPT_SID	(8 |IPOPT_CONTROL|IPOPT_COPY)
#define IPOPT_RA	(20|IPOPT_CONTROL|IPOPT_COPY)

struct iphdr {
#if defined(__LITTLE_ENDIAN_BITFIELD)
	uint8_t  ihl    :4,
		 version:4;
#elif defined (__BIG_ENDIAN_BITFIELD)
	uint8_t  version:4,
  		 ihl    :4;
#else
#error	"Please fix <asm/byteorder.h>"
#endif
	uint8_t	  tos;
	uint16_t  tot_len;
	uint16_t  id;
	uint16_t  frag_off;
	uint8_t   ttl;
	uint8_t   protocol;
	uint16_t  check;
	int32_t   saddr;
	int32_t   daddr;
};

struct ip_auth_hdr {
	uint8_t  nexthdr;
	uint8_t  hdrlen;
	uint16_t reserved;
	uint32_t spi;
	uint32_t seq_no;
	uint8_t  auth_data[0];
};

struct ip_esp_hdr {
	uint32_t spi;
	uint32_t seq_no;
	uint8_t  enc_data[0];
};

struct ip_comp_hdr {
	uint8_t  nexthdr;
	uint8_t  flags;
	uint16_t cpi;
};

__END_DECLS

#endif
