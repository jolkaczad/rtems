/*
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.com/license/LICENSE.
 *
 *  $Id$
 */


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
#include <errno.h>
#include <sched.h>


#if defined(__rtems__)
#include <rtems.h>
#include <bsp.h>
#include <pmacros.h>
#endif

void *countTaskDeferred(void *ignored)
{
  int i=0;
  int type,state;

  pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, &type);
  pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, &state);
  while (1) {
    printf("countTaskDeferred: elapsed time (second): %2d\n", i++ );
    sleep(1);
    pthread_testcancel();
  }
}

void *countTaskAsync(void *ignored)
{
  int i=0;
  int type,state;

  pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, &type);
  pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, &state);
  while (1) {
    printf("countTaskAsync: elapsed time (second): %2d\n", i++ );
    sleep(1);
  }
}

#if defined(__rtems__)
  void *POSIX_Init(void *ignored)
#else
  int main(int argc, char **argv)
#endif
{
  pthread_t task;
  int taskparameter = 0;

  puts( "\n\n*** POSIX CANCEL TEST ***" );

  /* Start countTask deferred */
  {
    int task_ret;
    task_ret = pthread_create(&task, NULL, countTaskDeferred, &taskparameter);
    if (task_ret) {
      perror("pthread_create: countTask");
      rtems_test_exit(EXIT_FAILURE);
    }
    /* sleep for 5 seconds, then cancel it */
    sleep(5);
    pthread_cancel(task);
    pthread_join(task, NULL);
  }

  /* Start countTask asynchronous */
  {
    int task_ret;
    task_ret = pthread_create(&task, NULL, countTaskAsync, &taskparameter);
    if (task_ret) {
      perror("pthread_create: countTask");
      rtems_test_exit(EXIT_FAILURE);
    }
    /* sleep for 5 seconds, then cancel it */
    sleep(5);
    pthread_cancel(task);
    pthread_join(task, NULL);
  }


  puts( "*** END OF POSIX CANCEL TEST ***" );

  #if defined(__rtems__)
    rtems_test_exit(EXIT_SUCCESS);
    return NULL;
  #else
    return 0;
  #endif
}

/* configuration information */
#if defined(__rtems__)

#define CONFIGURE_APPLICATION_NEEDS_CONSOLE_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_CLOCK_DRIVER

#define CONFIGURE_MAXIMUM_POSIX_THREADS 2
#define CONFIGURE_POSIX_INIT_THREAD_TABLE

#define CONFIGURE_INIT
#include <rtems/confdefs.h>

#endif /* __rtems__ */

