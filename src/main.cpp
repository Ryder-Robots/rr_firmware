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
 *  entrypoint program for firmnware.
 */

#include <Arduino.h>
#include <Wire.h>
#include <rr_isr.hpp>


/*******************************************************
 * For some reason only known to the code maintainers Wire
 * only works in the main module,  and not in other files,
 * so this function must live here.
 */
void isr()
{
    for (int i = 0; i < ISR_TIMEOUT; i++)
    {
        if (BUS.available() > 0) {
            String data = BUS.readString();
            
            if (data.length() < 2 ||  data.length() != (uint8_t) data.charAt(1)) {
                uint8_t ret[] = {RR_IO_RES_UNSUPPORTED, 0};
                BUS.write(ret, 2);
                return;
            }
            String rdata = data.substring(2);
            rrfw::RrOpStorage res = rrfw::ctl_isr(rrfw::RrOpStorage(
                (uint8_t) data.c_str()[0], 
                (uint8_t)data.c_str()[1], 
                (uint8_t *) rdata.c_str()));

            // Concatinate the string to trigger block write.
            String res_data = String(res._cmd) + String(res._sz) + String((char *)res._data);
            BUS.write(res_data.c_str());
        }

        // break the loop,  there is no data.
        if (i == ISR_TIMEOUT) {
            uint8_t rv[] = {RR_IO_RES_TIMEOUT, 0};
            BUS.write(rv, 2);
            break;
        }
    }
}

void setup() {
  // put your setup code here, to run once:;
  rrfw::setup_isr();
  // put in the begin BUS command,  this will need to be a macro. Serial.begin(9600);
  //attachInterrupt(digitalPinToInterrupt(RR_IRQ_PIN), isr, RR_IRQ_MODE);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Check GPS every X amount of seconds.
}
