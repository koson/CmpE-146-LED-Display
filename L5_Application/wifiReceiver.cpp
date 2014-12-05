#include "wifiReceiver.hpp"
#include "tasks.hpp"
#include <stdio.h>
#include <string.h>

wifiReceiver::wifiReceiver(UartDev& xUartDev, uint8_t cPriority ) :
                           scheduler_task( "Wifi_Receiver", 2048, cPriority ),
                           xBeeWifi( xUartDev ) {

}

bool wifiReceiver::run( void *vParams ) {

    ( void ) vParams;

    const char * psFont[3] = { "Consola", "Courier", "FixedSys" };
    const char * psColor[8] =
        { "Black", "Blue", "Green", "Cyan", "Red", "Pink", "Yellow", "White" };
    const char * psBackground[8] =
        { "Black", "Blue", "Green", "Cyan", "Red", "Pink", "Yellow", "White" };

    char * cRxChar = new char();

    for(;;) {
        if ( xBeeWifi.getChar( cRxChar, portMAX_DELAY ) ) {
            printf( psFont[atoi( cRxChar )] );
            xBeeWifi.getChar( cRxChar, portMAX_DELAY );
            printf( psColor[atoi( cRxChar )] );
            xBeeWifi.getChar( cRxChar, portMAX_DELAY );
            printf( psBackground[atoi( cRxChar )] );

            while( 0 < xBeeWifi.getRxQueueSize() ) {
                xBeeWifi.getChar( cRxChar, portMAX_DELAY );
                printf( "%c", *cRxChar );
            }

        }
    }
    return 0;
}
