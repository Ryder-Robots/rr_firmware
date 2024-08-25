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



#ifndef RR_ISR_HPP
#define RR_ISR_HPP

#include <stdlib.h>
#include <RrOpStorage.hpp>
#include <RrFirmware.h>
#include <RrOpBase.hpp>
#include <PinLayout.h>
#include <PinLayout.h>

namespace rrfw {

    // This functino is called by isr(), and designed specifically for unit testing.
    const  RrOpStorage  ctl_isr(const RrOpStorage bytes);

}
#endif