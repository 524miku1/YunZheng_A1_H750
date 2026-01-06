程序讲解：
printf("ClockFreq of CPU：%d MHz", HAL_RCC_GetSysClockFreq()/1000000);			//获取系统频率

RTC_TimeTypeDef RTC_TimeStructure;RTC_DateTypeDef RTC_DateStructure;				//RTC时间、日期结构体

HAL_RTC_GetTime(&hrtc,&RTC_TimeStructure,RTC_FORMAT_BIN);					//获取RTC时间
HAL_RTC_GetDate(&hrtc, &RTC_DateStructure, RTC_FORMAT_BIN);					//获取RTC日期

其他：
MX中RTC开启时钟源后还需启用日历功能。
HAL_RTC_GetTime（）、HAL_RTC_GetDate()必须同时使用，详见：https://blog.csdn.net/freedompoi/article/details/112525760