/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "spi.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "wizchip_conf.h"
#include "socket.h"
#include <stm32f4xx_hal.h>
#include <string.h>
#include "loopback.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint8_t s=0;
uint8_t serverip[4]={192,168,1,100};
uint8_t Baglan;
uint8_t gidenler[]="Zeynep Ozturk";
uint8_t gidenler_len=sizeof(gidenler);
uint8_t received_len;
uint8_t RSR_len;
uint8_t data_buf[30];
uint8_t Kop;
char msg[60];
uint16_t okunan_veriler[20];
uint8_t bufSize[4] = {2, 2, 2, 2};
uint16_t deneme=0;
uint16_t serverport= 45000;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void cs_sel() {
	HAL_GPIO_WritePin(cs_GPIO_Port, cs_Pin, GPIO_PIN_RESET); //CS LOW
}

void cs_desel() {
	HAL_GPIO_WritePin(cs_GPIO_Port, cs_Pin, GPIO_PIN_SET); //CS HIGH
}

uint8_t spi_rb(void) {
	uint8_t rbuf;
	HAL_SPI_Receive(&hspi2, &rbuf, 1, 0xFFFFFFFF);
	return rbuf;
}

void spi_wb(uint8_t b) {
	HAL_SPI_Transmit(&hspi2, &b, 1, 0xFFFFFFFF);
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_SPI2_Init();
  /* USER CODE BEGIN 2 */
  reg_wizchip_cs_cbfunc(cs_sel, cs_desel);
  reg_wizchip_spi_cbfunc(spi_rb, spi_wb);

  wizchip_init(bufSize, bufSize);
       wiz_NetInfo netInfo = { .mac 	= {0x00, 0x08, 0xdc, 0xab, 0xcd, 0xef},	// Mac address
                               .ip 	= {192, 168, 1, 192},					// IP address
                               .sn 	= {255, 255, 255, 0},					// Subnet mask
                               .gw 	= {192, 168, 1, 2}};					// Gateway address
       wizchip_setnetinfo(&netInfo);
       wizchip_getnetinfo(&netInfo);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	  if (getSn_SR(s) != SOCK_CLOSED) {
	      close(s);
	  }

	  socket(s, Sn_MR_TCP, 50000, 0);

	  Baglan = connect_3(s, serverip, 45000);
//	  printf("connect dönüşü: %d\n", Baglan);

//	  Baglan = connect_W5x00(s, serverip, serverport);
	  Baglan=0;

//	  if (Baglan != SOCK_OK) {
//	      printf("Bağlantı hatası: %d\n", Baglan);
//	  }

	  while(getSn_SR(s) != SOCK_ESTABLISHED) {//tcp bağlantısı kurana kadar bekler
	      printf("Bağlanmaya çalışıyor...\n");
	      HAL_Delay(500);
	  }

	  printf("Bağlantı kuruldu!\n");


	  while (getSn_SR(s) == SOCK_ESTABLISHED) {
	      char mesaj[] = "Selam mecit görevimi tamamladım\n";
	      int gonderilen = send(s, (uint8_t *)mesaj, strlen(mesaj));


	  }



//	  socket(s,Sn_MR_TCP,45000,SF_TCP_NODELAY);
//
//	  while(Baglan!=SOCK_OK){
//	  		  Baglan=connect_IO_6(s,serverip,45000);
//	  	  }
//	  Baglan=0;
//
//	  uint8_t status = getSn_SR(s);
//	  if (status == SOCK_ESTABLISHED) {
//	      printf("✅ Bağlantı başarılı\n");
//	  } else {
//	      printf("❌ Bağlantı durumu: %02X\n", status);
//	  }


	  send(s,gidenler,gidenler_len);

	  while(received_len==0){
	 		  if(RSR_len = getSn_RX_RSR(s)>0)
	 			  received_len=recv(s,data_buf,RSR_len);
	 	  }

	 	  while(SOCK_OK!=Kop)
	 	  {
	 		  Kop=close(s);
	 		  Kop=0;
	 	  }
	  HAL_Delay(25000);
	 	  received_len=0;
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 82;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
