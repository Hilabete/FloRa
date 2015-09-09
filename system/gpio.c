#include "board.h"

#include "gpio-board.h"

#if defined( BOARD_IOE_EXT )
	#include "gpio-ioe.h"
#endif

void GpioInit( Gpio_t *obj, PinNames pin, PinModes mode,  PinConfigs config, PinTypes type, uint32_t value )
{
    if( ( uint32_t )( pin >> 4 ) <= 6 ) 
    {
        GpioMcuInit( obj, pin, mode, config, type, value );
    }
    else
    {
#if defined( BOARD_IOE_EXT )
  // IOExt Pin
  GpioIoeInit( obj, pin, mode, config, type, value );
#endif
    }
}

void GpioSetInterrupt( Gpio_t *obj, IrqModes irqMode, IrqPriorities irqPriority, GpioIrqHandler *irqHandler )
{
    if( ( uint32_t )( obj->pin >> 4 ) <= 6 ) 
    {
        GpioMcuSetInterrupt( obj, irqMode, irqPriority, irqHandler );
    }
    else
    {
#if defined( BOARD_IOE_EXT )
        // IOExt Pin
        GpioIoeSetInterrupt( obj, irqMode, irqPriority, irqHandler );
#endif
    }
}

void GpioRemoveInterrupt( Gpio_t *obj )
{
    if( ( uint32_t )( obj->pin >> 4 ) <= 6 ) 
    {
        //GpioMcuRemoveInterrupt( obj );
    }
    else
    {
#if defined( BOARD_IOE_EXT )
        // IOExt Pin
        //GpioIoeRemoveInterrupt( obj );
#endif
    }
}

void GpioWrite( Gpio_t *obj, uint32_t value )
{
		if(obj->pin == LED_1){
				printf("GpioWrite : LED1 %d\n", value);
		}
		//printf("GpioWrite : pin \%d %d\n", obj->pin, value);
    if( ( uint32_t )( obj->pin >> 4 ) <= 6 ) 
    {
        GpioMcuWrite( obj, value );
    }
    else
    {
#if defined( BOARD_IOE_EXT )
        // IOExt Pin
        GpioIoeWrite( obj, value );
#endif
    }
}

uint32_t GpioRead( Gpio_t *obj )
{
    if( ( uint32_t )( obj->pin >> 4 ) <= 6 ) 
    {
        return GpioMcuRead( obj );
    }
    else
    {
#if defined( BOARD_IOE_EXT )
        // IOExt Pin
        return GpioIoeRead( obj );
#else
        return 0;
#endif
    }
}
