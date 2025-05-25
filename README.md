# Stm32+W5500 TCP/IP 
##Donanım

###Gerekenler

*STM32 mikrodenetleyici
*W5500

###Kablolama
| STM PIN | W5500 | 
|----------|----------|
| SPI MOSI   | MOSI   | 
| SPI MISO   | MISO   | 
| SPI CLK  |  CLK   | 
| GPIO Output(CS)  |  SCS   | 
| GND   | GND   | 
| 3.3V   | 3.3V   | 

###İndirilenler 
[W5500'ün kendi kütüphanesini](https://github.com/Wiznet/ioLibrary_Driver) zip dosyası olarak indirip içindeki Application ve Ethernet dosyalarını STM32CubeIDE'ye ekliyoruz.
Sonra aşağıdakileri include ediyoruz:
```
#include "wizchip_conf.h"        //W5500 (WIZnet) Ethernet çipini kullanmak için.
#include "socket.h"              //W5500 (WIZnet) Ethernet çipini kullanmak için.
#include <stm32f4xx_hal.h>
#include <string.h>            
```

###Clock Configuration
![image](https://github.com/user-attachments/assets/ad7f1a32-05f3-4cd3-af79-babe26f7ad00)


### .ioc ayarları


