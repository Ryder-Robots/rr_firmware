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

#include <l298n.hpp>

namespace rrfw {
    L298::L298(int ena, int enb, int in1, int in2, int in3, int in4):
        _ena{ena},
        _enb{enb},
        _in1{in1},
        _in2{in2},
        _in3{in3},
        _in4{in4}  
    {

        for (auto i : (int[]){_ena, _enb, _in1, _in2, _in3, _in4})
        {
            pinMode(i, OUTPUT);
        }

        // Ground everything, To keep ,motors even.
        analogWrite(_ena, LOW);  
        analogWrite(_enb, LOW);
        for (auto i : (int[]){_in1, _in2, _in3, _in4})
        {
            digitalWrite(i, LOW);
        }
    }

    const RrOpStorage L298::execute(const RrOpStorage bytes)
    {
        
        uint8_t *data = {};
        if (bytes._sz != 3) {
            
            return RrOpStorage(RR_IO_RES_BAD_RQ, 0, data);

        }
        byte ma_flags = bytes._data[0], ena = bytes._data[1], enb = bytes._data[2];

        digitalWrite(_in1, toggle_bit(ma_flags, RR_MOTOR_FLAG_IN1));
        digitalWrite(_in2, toggle_bit(ma_flags, RR_MOTOR_FLAG_IN2));
        digitalWrite(_in3, toggle_bit(ma_flags, RR_MOTOR_FLAG_IN3));
        digitalWrite(_in4, toggle_bit(ma_flags, RR_MOTOR_FLAG_IN4));
        analogWrite(_ena, ena);
        analogWrite(_enb, enb);

        return RrOpStorage(RR_IO_RES_ACTION_SENT, 0, data);
    }

    // attempting to teminate all motors
    L298::~L298()
    {
        analogWrite(_ena, LOW);  
        analogWrite(_enb, LOW);

        for (auto i : (int[]){_in1, _in2, _in3, _in4})
        {
            digitalWrite(i, LOW);
        }
    }


    uint8_t L298::toggle_bit(byte flags, byte test)
    {
        return ((flags &= test) == test) ? HIGH : LOW;
    }
}