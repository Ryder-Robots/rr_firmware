/********************************************
 * Ryder Robots Shared Micro-Processor
 * Copyright (C) 2024  Ryder Robots
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * =====================================================================
 * 
 * Consider this code the core structure of the micro-processor.
 * 
 * When the interrupt pin is triggerred, the MP will check USB for data
 * get it deserilized, and perform some sort of task,  either 
 * and operation or an action.
 */

#include <PinLayout.h>
#include <rr_isr.hpp>

SUPPORTED_CMD_INIT

namespace rrfw {
    
    RrOpStorage io_cmds(const RrOpStorage rx) 
    {
        static RrOpBase    uc1 = M1_U1_CLASS;
        static RrOpStorage usp = RrOpStorage(RR_IO_RES_UNSUPPORTED, 0, {});

        // Execute the command according to the profile.
        switch (rx._cmd) {
            case RR_CMD_U1:
                return uc1.execute(rx);
        }

        // if the command can not be found return unsupported.
        return usp;
    }

    int compare(const void* a, const void* b)
    {
        return (*(uint8_t*)a - *(uint8_t*)b);
    }


    /********************************************************************
     * Executes the ISR command that is given.
     ********************************************************************/
    const RrOpStorage ctl_isr(const RrOpStorage bytes)
    {
        // get static copies of the supported commands so that clock cycles are not waisted on 
        // sorting array etc.
        static size_t sz = sizeof(SUPPORTED_CMD) / sizeof(SUPPORTED_CMD[0]);
        static uint8_t *supported_cmds = NULL;

        if (supported_cmds == NULL) {
            supported_cmds = (uint8_t *) calloc(sz, sizeof(uint8_t));
            memcpy(supported_cmds, SUPPORTED_CMD, sz);
        }

        qsort(&supported_cmds, sz, sizeof(uint8_t), compare);
        uint8_t* item;
        item = (uint8_t*) bsearch(&bytes._cmd, supported_cmds, sz, sizeof(uint8_t), compare);

        if (item != NULL) {
            return io_cmds(bytes);
        }
        return RrOpStorage(RR_IO_RES_UNSUPPORTED, 0, {});
    }
}
