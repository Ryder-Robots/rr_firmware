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
    Hsr04::Hsr04(int ping_ping, int max_distance):
        _ping_pin{ping_ping}
    {
        sonar = new NewPing(ping_ping, ping_ping, max_distance);
    }

     const RrOpStorage execute(const RrOpStorage  bytes)
     {
        float duration = sonar->ping();

        // Assumes and ambient temprature of 20 degrees celcius,  this will need to be 
        // turned in future versions.
        uint16_t distance = 0;
        
        if (round((duration / 2) * SOUND_SPEED_INGORE_TEMP) > 0) {
            distance = round((duration / 2) * SOUND_SPEED_INGORE_TEMP);
        }
        uint8_t p1 = 0, p2 = 0;

     }

}