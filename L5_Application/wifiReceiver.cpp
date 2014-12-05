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

    char * cRxChar = new char();

    for(;;) {
        if ( xBeeWifi.getChar( cRxChar, portMAX_DELAY ) ) {
            printf( "Font: " );
            printf( psFont[atoi( cRxChar )] );
            printf("\r\n");
            xBeeWifi.getChar( cRxChar, portMAX_DELAY );
            printf( "Text color: " );
            printf( psColor[atoi( cRxChar )] );
            printf("\r\n");
            xBeeWifi.getChar( cRxChar, portMAX_DELAY );
            printf( "Background color: " );
            printf( psColor[atoi( cRxChar )] );
            printf("\r\n");

            while( 0 < xBeeWifi.getRxQueueSize() ) {
                xBeeWifi.getChar( cRxChar, portMAX_DELAY );
                printf( "%c", *cRxChar );
            }

        }
    }
    return 0;
}
