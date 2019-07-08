/**
 Wyres private code
 */

#include <string.h>
#include <assert.h>
#include "sysinit/sysinit.h"
#include "os/os.h"
#include "bsp.h"

#include "wyres-generic/wutils.h"
#include "wyres-generic/timemgr.h"
#include "wyres-generic/rebootMgr.h"
#include "app-core/app_core.h"
#include "app_SM.h"


/**
 * main
 *
 * The main task for the project. This function initializes packages,
 * and then blinks the BSP LED in a loop.
 *
 * @return int NOTE: this function should never return!
 */
int
main(int argc, char **argv)
{

#ifdef ARCH_sim
    mcu_sim_parse_args(argc, argv);
#endif
    // Allow debugger to get its rear in gear (otherwise misses initial breakpoints)
    TMMgr_busySleep(5000);
    // init everyone
    sysinit();

    // unittest or real app?
#ifdef UNITTEST
    bool ret = true;
    // call the unittests here
    ret &= unittest_gps();
    ret &= unittest_cfg();
//    assert(ret);        // If UTs fail, assert - this should probably return a value from the main?
#endif /* UNITTEST */
    log_debug("starting SM....");
    // startup app tasks etc
//    app_sm_init();
//    app_sm_start();
    // OR
    app_core_start();

    while (1) {
        os_eventq_run(os_eventq_dflt_get());
    }
    assert(0);

    return 0;
}
