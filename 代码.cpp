#include <stdio.h>
#include <time.h> 
#include <string.h>
#include <stdlib.h>
struct System{
	int year;
	int month;
	int week;
	int second;
	int hour;
	int minute;x
	int day; 
};
//判断月份
 int Month(char *String){
 	if(strcmp(String,"Jan")==0)
 		return 1;
 	if(strcmp(String,"Feb")==0)
 		return 2;
 	if(strcmp(String,"Mar")==0)
 		return 3;
 	if(strcmp(String,"Apr")==0)
 		return 4;
 	if(strcmp(String,"May")==0)
 		return 5;
 	if(strcmp(String,"Jun")==0)
 		return 6;
 	if(strcmp(String,"Jul")==0)
 		return 7;
 	if(strcmp(String,"Aug")==0)
 		return 8;
 	if(strcmp(String,"Sept")==0)
 		return 9;
 	if(strcmp(String,"Oct")==0)
 		return 10;
 	if(strcmp(String,"Nov")==0)
 		return 11;
 	if(strcmp(String,"Dec")==0)
 		return 12;
//	switch(String){
//		case "Jan": return 1;
//		case "Feb": return 2;
//		case "Mar": return 3;
//		case "Apr": return 4;
//		case "May": return 5;
//		case "Jun": return 6;
//		case "Jul": return 7;
//		case "Aug": return 8;
//		case "Sept": return 9;
//		case "Oct": return 10;
//		case "Nov": return 11;
//		case "Dec": return 12; 		
} 


//  计算公式 
int Number(int nowyear,int leapYearNumber,int birthyear,int birthToDay,int nowToDay){
	//判断是不是过了  2月29日  如果过了就 需要 
	int num = (nowyear-birthyear)*365+leapYearNumber-(birthToDay)+nowToDay;
	return num;
}



//计算是否为闰年
int leapYear(int year){
		if(year%100!=0){
		if(year%4==0){
			return 1;
		}else{
			return 0;
		}
	}else{
		if(year%400==0){
			return 1; 
		}else{
			return 0;
		}
	}
} 



//   计算闰年的年数
int Leapyear(int birthyear,int nowyear){
	//判断 出生年份是不是闰年
	int i = birthyear;
	int change;   //算与闰年相差的年数 
	int m=leapYear(i);
	if(i==1){
		change=0;
	}else{
		change=i%4;
	}
	int num;// 闰年的的个数
	num=(nowyear-(i-change))/4-1; 
	return num;
} 



//计算  1月1号 至测定时间的天数
int Day(int month,int day,int year){
	int Day;
	switch(month) {
        case 1: Day=day;break;
        case 2: Day=31+day;break;
        case 3: Day=(31+28)+leapYear(year)+day;break;
        case 4: Day=(31+28+31)+leapYear(year)+day;break;
        case 5: Day=(31+31+30+28)+leapYear(year)+day;break;
        case 6: Day=(31+28+31+30+31)+leapYear(year)+day;break;
        case 7: Day=(31+28+31+30+31+30)+leapYear(year)+day;break;
        case 8: Day=(31+28+31+30+31+30+31)+leapYear(year)+day;break;
        case 9: Day=(31+28+31+30+31+30+31+31)+leapYear(year)+day;break;
        case 10: Day=(31+28+31+30+31+30+31+31+30)+leapYear(year)+day;break;
        case 11: Day=(31+28+31+30+31+30+31+31+30+31)+leapYear(year)+day;break;
        case 12: Day=(31+28+31+30+31+30+31+31+30+31+30)+leapYear(year)+day;break;
        default:
        	printf("输入日期错误");
			exit(0);
    }
    return Day;
}
//体力节律 
void  physicalrhythm (int num){
	int i =num%23;
	if(i==0){
		printf("体力正好处于周期日"); 
	}else if(i<12){
		printf("体力处于高潮日第%d天",i); 
	}else if(i==12){
		printf("体力正好处于临界日"); 
	}else{
		printf("体力处于低潮日第%d天",i-12);
	}
}
//情绪节律
void emotionalrhythm(int num){
	int i = num%28;
	if(i==0){
		printf("情绪正好处于周期日"); 
	}else if(i<14){
		printf("情绪处于高潮日第%d天",i); 
	}else if(i==14){
		printf("情绪正好处于临界日"); 
	}else{
		printf("情绪处于低潮日第%d天",i-14);
	}
}
//智力节律 
void brains(int num){
	int i = num%33;
	if(i==0){
		printf("智力正好处于周期日"); 
	}else if(i<17){
		printf("智力处于高潮日第%d天",i); 
	}else if(i==17){
		printf("智力正好处于临界日"); 
	}else{
		printf("智力处于低潮日第%d天",i-17);
	}
	
}
int main (){
   time_t rawtime;
   struct tm *info;
   time( &rawtime );
   info = localtime( &rawtime );
   char*string;
   string=asctime(info);
  // printf("当前的本地时间和日期：%s",asctime(info));
   char s[2]=" " ;
   char * S;
   char *middle[8]; 
   //把整个时间的字符串 拆分为  五部分   middle[0]代表 星期   ；middle[1 ]代表月份 ；middle[2] 天数；middle[3]代表时间 包括 时分秒;  middle[4]代表年份 
   S=strtok(string,s);
   for (int i = 0; i<5;i++){
   		middle[i]=S;
    	//printf("%s\n",middle[i]);
    	S=strtok(NULL,s);
   }
   //把小时 分钟 秒 分开；分开的是middle[3]   分别用middle 567 表示 ； 5 代表 小时 ；6 代表 分钟 ；7 代表 秒 
    char aprt[2]=":";
    S=NULL;
    S=strtok(middle[3],aprt);
    for(int i = 5;i<=7;i++){
    	middle[i]=S;
    	//printf("%s\n",middle[i]);
    	S=strtok(NULL,aprt);
	}
   //分别 把五部分字符串 放入对应的时间体中
    struct System system;
    system.second=atoi(middle[7]);   //秒 
    system.hour=atoi(middle[5]);     //小时 
    system.minute=atoi(middle[6]);   //分钟 
    system.month=Month(middle[1]);   //月份 
    //system.week=atoi(middle[0]);   
    system.year=atoi(middle[4]);     //年份 
    system.day=atoi(middle[2]);      //天数 
    //  得到 测试者的出生年 
    int birthYear,birthMonth,birthDay;
    int judge=0;
    
    //以下是对输入的值 是否合法的判断
	 
	while(judge==0){	
	printf("请输入 您的出生年份  分别输入公历的 年 月 日 用空格键分开 \n");
    scanf("%d%d%d",&birthYear,&birthMonth,&birthDay);
    //检测输入的值是否合法
    if(birthYear<system.year&&birthYear>1900&&birthMonth<=12&&birthMonth>=1){    //年份·和·月份 的判断   不包括与测试年份相同时 
    	if(leapYear(birthYear)){                           //如果时闰年  则对二月的日期判断 
    		if(birthMonth==2){
    			if(birthDay<=29&&birthDay>=1){
    				judge=1;
					break;
				}
				printf("输入的值有误，请重新输入。\n");
				continue;										//结束后面的检测  重新输入	
			}else if(birthMonth==1||birthMonth==3||birthMonth==5||birthMonth==7||birthMonth==8||birthMonth==10||birthMonth==12){  //对月份进行讨论 
				if(birthDay<=31&&birthDay>=1){
					judge=1;
					break;
				}
				printf("输入的值有误，请重新输入。\n");
				continue;										//结束后面的检测  重新输入
			}else if(birthMonth==4||birthMonth==6||birthMonth==9||birthMonth==11){   
				if(birthDay<=30&&birthDay>=1){
						judge=1;
						break;
					}
					printf("输入的值有误，请重新输入。\n");
					continue; 										//结束后面的检测  重新输入
				}
			}else{                                                   //如果不是闰年   对二月讨论 
				if(birthMonth==2){
					if(birthDay<=28&&birthDay>=1){                          
    					judge=1;
						break;
					}
					printf("输入的值有误，请重新输入。\n");
					continue;	                                  //结束后面的检测  重新输入 
				}else if(birthMonth==1||birthMonth==3||birthMonth==5||birthMonth==7||birthMonth==8||birthMonth==10||birthMonth==12){  //对月份讨论 
					if(birthDay<=31&&birthDay>=1){
						judge=1;
						break;
					}
					printf("输入的值有误，请重新输入。\n");
					continue;										//结束后面的检测  重新输入
				}else if(birthMonth==4||birthMonth==6||birthMonth==9||birthMonth==11){
					if(birthDay<=30&&birthDay>=1){
						judge=1;
						break;
					}
					printf("输入的值有误，请重新输入。\n");
					continue;										//结束后面的检测  重新输入
				}
			}
		}
		if(birthYear==system.year) {          //如果是今年出生的  那么月份不能超过现在测试的时间   需要对月份进行讨论 
			if(birthMonth>=1&&birthMonth<system.month){
			  	if(leapYear(birthYear)){                           //如果时闰年  则对二月的日期判断 
    				if(birthMonth==2){
    					if(birthDay<=29&&birthDay>=1){
    						judge=1;
							break;
						}
						printf("输入的值有误，请重新输入。\n");
						continue;										//结束后面的检测  重新输入	
					}else if(birthMonth==1||birthMonth==3||birthMonth==5||birthMonth==7||birthMonth==8||birthMonth==10||birthMonth==12){  //对月份进行讨论 
						if(birthDay<=31&&birthDay>=1){
							judge=1;
							break;
						}
					printf("输入的值有误，请重新输入。\n");
					continue;										//结束后面的检测  重新输入
			}else if(birthMonth==4||birthMonth==6||birthMonth==9||birthMonth==11){   
				if(birthDay<=30&&birthDay>=1){
					judge=1;
					break;
					}
					printf("输入的值有误，请重新输入。\n");
					continue;										//结束后面的检测  重新输入
				}
			}else{
				if(birthMonth==2){
					if(birthDay<=28&&birthDay>=1){                           //如果不是闰年   对二月讨论 
    					judge=1;
						break;
					}
					printf("输入的值有误，请重新输入。\n");
					continue;										//结束后面的检测  重新输入	
				}else if(birthMonth==1||birthMonth==3||birthMonth==5||birthMonth==7||birthMonth==8||birthMonth==10||birthMonth==12){  //对月份讨论 
					if(birthDay<=31&&birthDay>=1){
						judge=1;
						break;
					}
					printf("输入的值有误，请重新输入。\n");
					continue;										//结束后面的检测  重新输入
				}else if(birthMonth==4||birthMonth==6||birthMonth==9||birthMonth==11){
					if(birthDay<=30&&birthDay>=1){
							judge=1;
							break;
						}
						printf("输入的值有误，请重新输入。\n");
						continue;										//结束后面的检测  重新输入
					}
				}	
			}
			//如果与测试的月份相同  则需要判断 日期是否超过测试时间的日期 
			if(birthMonth==system.month){                       
				if(leapYear(birthYear)){                           //如果时闰年  则对二月的日期判断 
    				if(birthMonth==2){
    					if(birthDay<=29&&birthDay>=1&&birthDay<=system.day){
    						judge=1;
							break;
						}
						printf("输入的值有误，请重新输入。\n");
						continue;										//结束后面的检测  重新输入	
					}else if(birthMonth==1||birthMonth==3||birthMonth==5||birthMonth==7||birthMonth==8||birthMonth==10||birthMonth==12){  //对月份进行讨论 
							if(birthDay<=31&&birthDay>=1&&birthDay<=system.day){
								judge=1;
								break;
							}
							printf("输入的值有误，请重新输入。\n");
							continue;										//结束后面的检测  重新输入
					}else if(birthMonth==4||birthMonth==6||birthMonth==9||birthMonth==11){   
							if(birthDay<=30&&birthDay>=1&&birthDay<=system.day){
								judge=1;
								break;
							}
							printf("输入的值有误，请重新输入。\n");
							continue;										//结束后面的检测  重新输入
						}
					}else{   //如果不是闰年   对二月讨论
						if(birthMonth==2){
							if(birthDay<=28&&birthDay>=1&&birthDay<=system.day){                     
    							judge=1;
								break;
							}
							printf("输入的值有误，请重新输入。\n");
							continue;										//结束后面的检测  重新输入	
						}else if(birthMonth==1||birthMonth==3||birthMonth==5||birthMonth==7||birthMonth==8||birthMonth==10||birthMonth==12){  //对月份讨论 
								if(birthDay<=31&&birthDay>=1&&birthDay<=system.day){
								judge=1;
								break;
							}
							printf("输入的值有误，请重新输入。\n");
							continue;										//结束后面的检测  重新输入
					}else if(birthMonth==4||birthMonth==6||birthMonth==9||birthMonth==11){
							if(birthDay<=30&&birthDay>=1&&birthDay<=system.day){
								judge=1;
								break;
							}
							printf("输入的值有误，请重新输入。\n");
							continue;										//结束后面的检测  重新输入
						}
					}
				}
			}
		printf("输入的值有误，请重新输入。\n");
	}

	
    //闰年的天数 
	int LeapYear=Leapyear(birthYear,system.year);  
	// 出生的时间到1.1的天数
	int birth_daynumber= Day(birthMonth,birthDay,birthYear) ; 
	//现在的时间到1.1的天数  
	int now_daynumber=Day(system.month,system.day,system.year);
	//计算公式得出 取余数前的值   
   	int number=Number(system.year,LeapYear,birthYear,birth_daynumber,now_daynumber);
   	printf("现在测试的时间是：   %d年 %d月 %d 日 %d时 %d分 %d秒\n\n",system.year,system.month,system.day,system.hour,system.minute,system.second);
   	//printf("出生到现在%d年1月1日闰年数  也即因为闰年而增加的天数是 %d\n",system.year, LeapYear);
   	printf("现在到1月1号的天数是 %d 天\n",now_daynumber);
   	printf("出生日期到1月1号的天数是 %d 天\n",birth_daynumber);
   	//把取余数前的值  输入     得出三种情况   
	physicalrhythm(number);
	printf("\n");
   	emotionalrhythm(number);
   	printf("\n");
   	brains(number); 
   	//system("pause");
   	scanf("%d");
   	return 0;
	}