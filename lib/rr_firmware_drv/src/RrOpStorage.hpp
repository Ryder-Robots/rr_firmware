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
 * Base storage class for firmware operations,  this class attempts to emulate the I2C format
 * which is cmd, size, *data
 */

#ifndef RROPSTORAGE_HPP
#define RROPSTORAGE_HPP
#include <stdint.h>
#include <RrFirmware.h>


namespace rrfw {

    class RrOpStorage {
        public:
            RrOpStorage(const RR_CMD cmd, const uint8_t sz, uint8_t *data):
            _cmd{cmd},
            _sz{sz}
            {
                _data = data;
            }

            uint8_t _cmd;
            uint8_t _sz;
            uint8_t *_data;
    };
}

#endif