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

#ifndef HSR04_H
#define HSR04_H

#include "NewPing.h"
#include <RrOpBase.hpp>


#define SOUND_SPEED_INGORE_TEMP 0.0343

namespace rrfw {
    class Hsr04 : public  RrOpBase {
    public:
        const RrOpStorage execute(const RrOpStorage  bytes) override;
        Hsr04(int ping_pin, int max_distance),
        sonar{};
    
    private:
        int     _ping_pin;
        NewPing *sonar;
    };
}

#endif