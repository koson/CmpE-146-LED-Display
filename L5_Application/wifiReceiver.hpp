/*
 * wifiReceiver.hpp
 *
 *  Created on: Dec 4, 2014
 *      Author: Will Zegers
 */

#ifndef WIFIRECEIVER_HPP_
#define WIFIRECEIVER_HPP_

#include "tasks.hpp"
#include "uart_dev.hpp"

class wifiReceiver : public scheduler_task {

    public:
        wifiReceiver(UartDev& xUartDev, uint8_t cPriority );

        bool run( void *vParams );

    private:
        UartDev& xBeeWifi;
};
#endif /* WIFIRECEIVER_HPP_ */
