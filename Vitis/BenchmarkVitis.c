
#include "xparameters.h"          // Parámetros del sistema
#include "xtmrctr.h"              // Librería para el temporizador/counter
#include "xil_printf.h"           // Para la impresión de mensajes en la consola

#define TIMER_DEVICE_ID  XPAR_AXI_TIMER_0_DEVICE_ID  // ID del timer

// Instanciar un objeto de la clase XTmrCtr
XTmrCtr TimerInstance;

int main() {
    int Status;
    int result;
    u32 StartTime, EndTime;
    u32 TimeTaken;

    // Inicializar el Timer
    Status = XTmrCtr_Initialize(&TimerInstance, TIMER_DEVICE_ID);
    if (Status != XST_SUCCESS) {
        xil_printf("Error al inicializar el Timer\r\n");
        return XST_FAILURE;
    }

    // Establecer el temporizador a 0 
    XTmrCtr_SetResetValue(&TimerInstance, 0, 0);
    XTmrCtr_Start(&TimerInstance, 0);

    // Obtener el tiempo de inicio (en ciclos de reloj)
    StartTime = XTmrCtr_GetValue(&TimerInstance, 0);


    for (int i = 0; i < 1000; i++) {
         result = i * i;  // Simulación de operaciones
    }

    // Obtener el tiempo final
    EndTime = XTmrCtr_GetValue(&TimerInstance, 0);

    // Calcular los ciclos de reloj transcurridos
    TimeTaken = EndTime - StartTime;

    // Imprimir el resultado en la consola
    xil_printf("Ciclos de reloj: %u\r\n", TimeTaken);

    return 0;
}









