#include <types.h>
#include "subprograms.h"
#include <core/thread.h>
/*****************************************************/
/*  This file was automatically generated by Ocarina */
/*  Do NOT hand-modify this file, as your            */
/*  changes will be lost when you re-run Ocarina     */
/*****************************************************/
/*  Periodic task : thr2*/

/***************/
/* thr2_job   */ 
/**************/

void* thr2_job ()
{

  pok_ret_t ret;
  while (1)
  {
    /*  Call implementation*/
    test__hello_part2 ();
    pok_thread_period ();
  }
}


