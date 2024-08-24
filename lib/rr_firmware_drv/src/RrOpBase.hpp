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
 * Base class for Transmit, and Recieve. Handles Storage container, for
 * SimpleCollection.
 */

#ifndef TXRX_BASE_HPP
#define TXRX_BASE_HPP

#include <Arduino.h>
#include <stdint.h>
#include <RrFirmware.h>
#include <RrOpStorage.hpp>

namespace rrfw {



    class RrOpBase {
    public:
        /*!
         * by default returns success.
         */
        virtual const RrOpStorage execute(const RrOpStorage  bytes) 
        { 
            uint8_t data[]{};
            return RrOpStorage(RR_IO_RES_OK, 0, data);
        }

        virtual ~RrOpBase() {}
    };
}

#endif