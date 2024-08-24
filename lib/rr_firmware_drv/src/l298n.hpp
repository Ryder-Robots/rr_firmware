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
 * Code specific to the L298 motor driver.
 * 
 * For analogRead values go from 0 to 1023, analogWrite values from 0 to 255
 */


#ifndef L298_HPP
#define L298_HPP

#include <stdint.h>
#include <RrOpBase.hpp>

namespace rrfw {
    class L298 : public  RrOpBase {
    public:
        const RrOpStorage execute(const RrOpStorage  bytes) override;

        // Assign pins here.
        L298(int ena, int enb, int in1, int in2, int in3, int in4);

        ~L298();

    private:
        uint8_t toggle_bit(uint8_t flags, uint8_t test);

        int _ena;
        int _enb;
        int _in1;
        int _in2;
        int _in3;
        int _in4;
    };
}

#endif