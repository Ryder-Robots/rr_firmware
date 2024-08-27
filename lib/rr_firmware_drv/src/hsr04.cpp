/*!
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
 * Code for HSR04 ultrasonic sensor or compatible model.  Supports
 * GPIO pins for communication,  note that it uses one wire for RX/TX
 */

#include <hsr04.hpp>

namespace rrfw {

    /*******************************************************************************
     * allocate the pin pin.
     */
    Hsr04::Hsr04(int echo_pin, int trig_pin, int max_distance):
        _echo_pin{echo_pin},
        _trig_pin{trig_pin}
    {
        _sonar = new NewPing(trig_pin, echo_pin, max_distance);
    }

     const RrOpStorage Hsr04::execute(const RrOpStorage  bytes)
     {
        float distance = _sonar->ping_cm();

        // technically this should not happen,  but lets assume it can.
        if (distance < 0) {
            distance = 0;
        }
        uint16_t b1 = round(distance);
        uint8_t data[] = {b1 >> 0x10, 1 >> 0x00};

        return RrOpStorage(RR_IO_RES_OK, 2, data);
     }

}