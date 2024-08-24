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

#include <rr_isr.hpp>

namespace rrfw {
    static RrOpBase* io_functions[RR_IO_SZ];

    /********************************************************************
     * Register handlers for the commands, each handler should have its
     * own constructor, which set hte arguments correly, or the profile
     * will mark the command as unsupported.
     * 
     */
    void setup_isr() {
       io_functions[0] = M1_U1_CLASS;
    }

    /*******************************************************************
     * Explicitly call the drivers deconsrtuctor, this is because we 
     * are refercining the class therefore need to deconstruct.
     */
    void tear_down_isr()
    {
        for (auto i : io_functions) {
            delete(i);
        }
    }

    /********************************************************************
     * Executes the ISR command that is given.
     */
    const RrOpStorage ctl_isr(const RrOpStorage bytes)
    {
        // Look for an operational handler.
        if (bytes._cmd <= RR_IO_SZ && bytes._sz >= 2) {
            return io_functions[bytes._cmd]->execute(bytes);
        }
        uint8_t data[] = {};
        return RrOpStorage(RR_IO_RES_UNSUPPORTED, 2, data);
    }

    void isr()
    {
        for (int i = 0; i < ISR_TIMEOUT; i++)
        {
            if (BUS.available() > 0) {
                String data = BUS.readString();
                
                if (data.length() < 2 ||  data.length() != (uint8_t) data.charAt(1)) {
                    uint8_t ret[] = {RR_IO_RES_UNSUPPORTED, 0};
                    BUS.write(ret, 2);
                    return;
                }
                String rdata = data.substring(2);
                RrOpStorage res = ctl_isr(RrOpStorage(
                    (uint8_t) data.c_str()[0], 
                    (uint8_t)data.c_str()[1], 
                    (uint8_t *) rdata.c_str()));
                BUS.write(res._cmd);
                BUS.write(res._sz);
                BUS.write(res._data, res._sz);
            }

            // break the loop,  there is no data.
            if (i == ISR_TIMEOUT) {
                uint8_t rv[] = {RR_IO_RES_TIMEOUT, 0};
                BUS.write(rv, 2);
                break;
            }
        }
    }
}
