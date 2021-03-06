/*
 * This file is part of the Green End SFTP Server.
 * Copyright (C) 2007 Richard Kettlewell
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA
 */

/** @file debug.h @brief Debug support interface */

#ifndef DEBUG_H
#  define DEBUG_H

/* Debug support */

/** @brief True if debug information is to be written */
extern int sftp_debugging;

/** @brief Filename for debug information */
extern const char *sftp_debugpath;

/** @brief Debug output of bytes in hex
 * @param ptr Start of region to dump
 * @param n Number of bytes to dump
 *
 * @ref sftp_debugging must be nonzero.
 */
void sftp_debug_hexdump(const void *ptr, size_t n);

/** @brief Write a debug message
 * @param fmt Format string as per printf(3)
 * @param ... Arguments
 *
 * @ref sftp_debugging must be nonzero.
 */
void sftp_debug_printf(const char *fmt, ...) attribute((format(printf, 1, 2)));

/** @brief Issue a debug message
 * @param x Parenthesized format string and arguments
 *
 * Typical usage would be:
 *
 * @code
 * D(("the value of x is %d", x));
 * @endcode
 */
#  define D(x)                                                                 \
    do {                                                                       \
      if(sftp_debugging)                                                       \
        sftp_debug_printf x;                                                   \
    } while(0)

#endif /* DEBUG_H */

/*
Local Variables:
c-basic-offset:2
comment-column:40
fill-column:79
indent-tabs-mode:nil
End:
*/
