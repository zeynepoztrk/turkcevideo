# Stm32+W5500 TCP/IP 

Projede STM32F446R kartındaki verileri ethernet kablosuyla bir bilgisayara aktaracağız. STM32F446R kartımızı ethernet ile bilgisayara bağlamak için w5500 kullanıyoruz. 

 
## Donanım

### Gerekenler

*STM32 mikrodenetleyici
*W5500

### Kablolama
| STM PIN | W5500 | 
|----------|----------|
| SPI MOSI   | MOSI   | 
| SPI MISO   | MISO   | 
| SPI CLK  |  CLK   | 
| GPIO Output(CS)  |  SCS   | 
| GND   | GND   | 
| 3.3V   | 3.3V   | 

#İndirilenler 
[W5500'ün kendi kütüphanesini](https://github.com/Wiznet/ioLibrary_Driver) zip dosyası olarak indirip içindeki Application ve Ethernet dosyalarını STM32CubeIDE'ye ekliyoruz.
Sonra aşağıdakileri include ediyoruz:
```
#include "wizchip_conf.h"        //W5500 (WIZnet) Ethernet çipini kullanmak için.
#include "socket.h"              //W5500 (WIZnet) Ethernet çipini kullanmak için.
#include <stm32f4xx_hal.h>
#include <string.h>            
```
# .ioc ayarları:

## Clock Configuration
![image](https://github.com/user-attachments/assets/ad7f1a32-05f3-4cd3-af79-babe26f7ad00)



 /*/ Şimdi ayarlardan spi'ı açmamız lazım ki w5500 ile iletişim kurabilelim.
 
# Kod

bunları tamamladıktan sonra wizchip_init başlatılır. bunun için içerisine tcp ile aktarılacak paketlerin boyutları girilir.

```
wizchip_init(bufSize, bufSize);     // wizchip_init arabellek boyutları ile başlatılır.
```

W5500'ü ethernet ile bilgisayara bağlayabilmek için w5500'ümüzün ağ parametrelerini(mac adresi, ip adresi, subnet adresi ve Gateway adresi ) girmemiz gerekemektedir.    
```                                
       wiz_NetInfo netInfo = { .mac 	= {0x00, 0x08, 0xdc, 0xab, 0xcd, 0xef},	// Mac address
                               .ip 	= {192, 168, 1, 192}, // IP address
                               .sn 	= {255, 255, 255, 0}, // Subnet mask
                               .gw 	= {192, 168, 1, 2}};  // Gateway address

       wizchip_setnetinfo(&netInfo);        // 
       wizchip_getnetinfo(&netInfo);        // W5500 başlattık ve IP,subnet,gateway ayarlarını yaptık
```

## Sunucu ile Bağlantı Kurulması:

```
	  int8_t socket  ( uint8_t  sn,  uint8_t  protocol,  uint16_t  port,  uint8_t  flag);
									// portu 50000 olan yeni bir local TCP soketi oluşturur

	  Baglan = connect_3(uint8_t  sn, uint8_t *  addr, uint16_t  port );
									// Sunucunun hedefleyeceği port ve ip adresleri girilir.

```
Dikkat edilmesi gereken en önemli nokta: Connect ve Socket fonksiyonlarında aynı port numarası kullanılmamalıdır. Bu port çakışmasına neden olacağı için çalışmayacaktır.

## Sunucuya Veri Gönderilmesi

```
int32_t send  ( uint8_t  sn,  uint8_t *  buf,  uint16_t  len ); 
									// TCP soketindeki bağlı porta veri gönderir


```




# JAVA Kodları:

## İçe aktardığımız kütüphaneler:


```
import java.io.*;			// InputStream, BufferedReader, InputStreamReader, IOException kütüphanelerinin genel halidir
import java.net.*; 			// ServerSocket, Socket, InetAddress kütüphanelerinin genel halidir.

```

## Kodlar:

STM kodlarında "connect" fonksiyonu ile belirlediğimiz port numarasını  bir "socket"e atayarak ethernet ile bağlantı kurmamızı  ve tcp ile veri gönderilen verileri okumayı sağlayacağız 
```
        ServerSocket SSOKET = null;
        try {
            SSOKET = new ServerSocket(PORT);
            SSOKET.setSoTimeout(TIMEOUT);                                       // Bağlantı bekleme timeout'u
            System.out.println("Server başlatıldı, port:" + PORT);
```


# ÇIKTI:

<p align="center">
  <img src="https://github.com/user-attachments/assets/a3d6c0db-754d-47c2-ba9a-499bef0e609d" width="300"/>
</p>

<p align="center">
  <img src="https://github.com/user-attachments/assets/8bc26f26-2d60-4415-98f2-9d1e5958507b" width="300"/>
</p>
