/*
 * Network library header.
 * Copyright (C) 1998 Kunihiro Ishiguro
 *
 * This file is part of GNU Zebra.
 *
 * GNU Zebra is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2, or (at your option) any
 * later version.
 *
 * GNU Zebra is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; see the file COPYING; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef _ZEBRA_NETWORK_H
#define _ZEBRA_NETWORK_H

#ifdef HAVE_SYS_ENDIAN_H
#include <sys/endian.h>
#endif
#ifdef HAVE_ENDIAN_H
#include <endian.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Both readn and writen are deprecated and will be removed.  They are not
   suitable for use with non-blocking file descriptors.
 */
extern int readn(int, uint8_t *, int);
extern int writen(int, const uint8_t *, int);

/* Set the file descriptor to use non-blocking I/O.  Returns 0 for success,
   -1 on error. */
extern int set_nonblocking(int fd);

extern int set_cloexec(int fd);

/* Does the I/O error indicate that the operation should be retried later? */
#define ERRNO_IO_RETRY(EN)                                                     \
	(((EN) == EAGAIN) || ((EN) == EWOULDBLOCK) || ((EN) == EINTR))

extern float htonf(float);
extern float ntohf(float);

/* force type for be64toh/htobe64 to be uint64_t, *without* a direct cast
 *
 * this is a workaround for false-positive printfrr warnings from FRR's
 * frr-format GCC plugin that would be triggered from
 * { printfrr("%"PRIu64, (uint64_t)be64toh(...)); }
 *
 * the key element here is that "(uint64_t)expr" causes the warning, while
 * "({ uint64_t x = expr; x; })" does not.  (The cast is the trigger, a
 * variable of the same type works correctly.)
 */

/* zap system definitions... */
#ifdef be64toh
#undef be64toh
#endif
#ifdef htobe64
#undef htobe64
#endif

#if BYTE_ORDER == LITTLE_ENDIAN
#define be64toh(x)	({ uint64_t r = __builtin_bswap64(x); r; })
#define htobe64(x)	({ uint64_t r = __builtin_bswap64(x); r; })
#elif BYTE_ORDER == BIG_ENDIAN
#define be64toh(x)	({ uint64_t r = (x); r; })
#define htobe64(x)	({ uint64_t r = (x); r; })
#else
#error nobody expects the endianish inquisition. check OS endian.h headers.
#endif

/**
 * Helper function that returns a random long value. The main purpose of
 * this function is to hide a `random()` call that gets flagged by coverity
 * scan and put it into one place.
 *
 * The main usage of this function should be for generating jitter or weak
 * random values for simple purposes.
 *
 * See 'man 3 random' for more information.
 *
 * \returns random long integer.
 */
static inline long frr_weak_random(void)
{
	/* coverity[dont_call] */
	return random();
}

#ifdef __cplusplus
}
#endif

#endif /* _ZEBRA_NETWORK_H */
