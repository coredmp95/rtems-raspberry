/*
 *  Spinlock Manager -- Translate SuperCore Status
 *
 *  COPYRIGHT (c) 1989-2006.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.com/license/LICENSE.
 *
 *  $Id$
 */

#if HAVE_CONFIG_H
#include "config.h"
#endif

#include <pthread.h>
#include <errno.h>

#include <rtems/system.h>
#include <rtems/posix/spinlock.h>

/*
 *  _POSIX_Spinlock_Translate_core_spinlock_return_code
 *
 *  Input parameters:
 *    the_spinlock_status - spinlock status code to translate
 *
 *  Output parameters:
 *    status code - translated POSIX status code
 *
 */

/* XXX fix me */
static int _POSIX_Spinlock_Return_codes[] = {
  0,                        /* CORE_SPINLOCK_SUCCESSFUL */
  EDEADLK,                  /* CORE_SPINLOCK_HOLDER_RELOCKING */
  -1,                       /* CORE_SPINLOCK_TIMEOUT */
  EBUSY,                    /* CORE_SPINLOCK_IS_BUSY */
  EBUSY,                    /* CORE_SPINLOCK_UNAVAILABLE */
  0                         /* CORE_SPINLOCK_NOT_LOCKED */
};


int _POSIX_Spinlock_Translate_core_spinlock_return_code(
  CORE_spinlock_Status  the_spinlock_status
)
{
  if ( the_spinlock_status <= CORE_SPINLOCK_STATUS_LAST )
    return _POSIX_Spinlock_Return_codes[the_spinlock_status];
  return POSIX_BOTTOM_REACHED();
}
