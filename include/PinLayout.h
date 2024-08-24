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
 */

#ifndef PINLAYOUT_H
#define PINLAYOUT_H

#include <Arduino.h>

// Set which profile to use.
#if(DPLATFORM == UNO)
// Pin layout for motor driver A
#include <PinLayoutArduinoUno.h>

#endif

// IRQ pin
// When HIGH indicates that there is data on available from PI
#define RR_IRQ_MODE RISING
#define ISR_TIMEOUT 500

// For Testing use I2C bus, or console will not work.
// TODO: Add initlization command for BUS here.
#if (BUSTYPE == I2C)
#define BUS Wire
#else
#define BUS Serial
#endif

#endif
