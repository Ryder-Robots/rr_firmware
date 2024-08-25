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
 * Profile for Arduino UNO
 */

#ifndef PINLAYOUTARDUINOUNO_H
#define PINLAYOUTARDUINOUNO_H

#include <l298n.hpp>
#include <hsr04.hpp>

// PIN Layout for supported devices.

// Pin Layout for M1_U1 motor driver.
#define M1_U1_ENA 3  // (Enable A) - pin  8 (L298N) 
#define M1_U1_ENB 5  // (Enables B) - pin 14 (L298N) 

#define M1_U1_IN1 9  // pin  7(L298N)
#define M1_U1_IN2 4  // pin  9(L298N)
#define M1_U1_IN3 6  // pin 13(L298N)
#define M1_U1_IN4 7  // pin 15(L298N)

#define M1_U4_TXRX 8 // Trig/Echo pin

#define M1_U1_CLASS L298(M1_U1_ENA, M1_U1_ENB, M1_U1_IN1, M1_U1_IN2, M1_U1_IN3, M1_U1_IN4)
#define M1_U4_CLASS Hsr04(M1_U4_TXRX);

#define RR_IRQ_PIN  2

// Add supported actions, and obvservations here,  DO NOT ADD supported responses.
#define SUPPORTED_CMD_INIT extern const uint8_t SUPPORTED_CMD[] = {RR_CMD_U1, RR_CMD_U4};

#endif
