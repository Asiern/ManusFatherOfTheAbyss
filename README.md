#Manus : El brazo robotico

"Manus" es un brazo robótico controlado por un microcontrolador PIC24, que puede realizar una serie de movimientos mediante el uso de joysticks. Manus también tiene una pantalla LCD y una consola UART, por la que muestra los diferentes valores recogidos por los joysticks, el valor actual de los servomotores que lo están controlando y un cronómetro.

## Funcionamiento General

El movimiento del brazo robótico se realiza mediante dos joysticks: Un joystick pequeño, que lo denominaremos "JP" y un joystick grande "JG".
Moviendo estos dos joysticks , podremos realizar diferentes movimientos sobre el brazo. Aparte del control analógico de los joysticks, tenemos una pequeña palanca que puede moverse hacia delante o atrás, con la que podremos controlar el cierre y la apertura de la pinza del robot. Esta palanca se puede encontrar al lateral del joystick grande.
Finalmente, en el caso de que no se tenga acceso a la UART y el usuario quiera ver los diferentes valores de los joysticks, motores,etc... El pulsador S3 hace un scroll en la pantalla LCD, con el que se podrá ir desplazando por los diferentes apartados de las métricas que recogemos.
En el momento que se quiera dejar de utilizar el brazo, simplemente haz click con el joystick pequeño y el robot comenzará a moverse hacia una posición segura, en la cual se apagará sin riesgo a que se choque con ningún objeto.


## Conexiones

| Puerto | Pin  | Información                         | Módulo |
| ------ | ---- | ----------------------------------- | ------ |
| B      | RB0  | Eje X del joystick grande           | -      |
| B      | RB1  | Eje Y del joystick grande           | -      |
| B      | RB2  | Palanca del joystick grande         | -      |
| B      | RB8  | Eje Vertical del joystick pequeño   | -      |
| B      | RB9  | Eje Horizontal del joystick pequeño | -      |
| D      | RD6  | Pulsador S3                         | CN15   |
| D      | RD13 | Pulsador del joystick pequeño       | CN19   |

## Controles

#### UART

| Tecla      | Uso                                          |
| ---------- | -------------------------------------------- |
| Cualquiera | Cambiar el control de los servos a UART      |
| 1          | Cambiar el control de los servos a analógico |
| m          | Aumentar duty servo 1                        |
| n          | Reducir duty servo 1                         |
| b          | Aumentar duty servo 2                        |
| v          | Reducir duty servo 2                         |
| c          | Aumentar duty servo 3                        |
| x          | Reducir duty servo 3                         |
| l          | Aumentar duty servo 4                        |
| k          | Reducir duty servo 4                         |
| j          | Aumentar duty servo 5                        |
| h          | Reducir duty servo 5                         |

#### Analógicos

| Eje                       | Uso                    |
| ------------------------- | ---------------------- |
| Joystick Pequeño X        | Movimiento del servo 1 |
| Joystick Pequeño Y        | Movimiento del servo 2 |
| Joystick Pequeño Pulsador | Terminar el programa   |
| Joystick Grande X         | Movimiento del servo 3 |
| Joystick Grande Y         | Movimiento del servo 4 |
| Joystick Grande Palanca   | Movimiento del servo 5 |
| Pulsador S3               | Scroll de la LCD       |
