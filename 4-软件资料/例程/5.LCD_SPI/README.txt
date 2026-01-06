程序讲解：
MX_SPI1_Init();//MX配置SPI，模式3，8位
LCD_Init();//LCD初始化
LCD_Fill(0, 0, 128, 160, WHITE);//填充白色
LCD_DrawLine(12,24,116,24,RED);//划线
LCD_ShowString(24,30,"LCD_W:",RED,WHITE,16,0);//写汉字
LCD_ShowIntNum(72,30,LCD_W,3,RED,WHITE,16);//写数字

其他：
SPI的GPIO速度需要调到中等以上。