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
//�ж��·�
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


//  ���㹫ʽ 
int Number(int nowyear,int leapYearNumber,int birthyear,int birthToDay,int nowToDay){
	//�ж��ǲ��ǹ���  2��29��  ������˾� ��Ҫ 
	int num = (nowyear-birthyear)*365+leapYearNumber-(birthToDay)+nowToDay;
	return num;
}



//�����Ƿ�Ϊ����
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



//   �������������
int Leapyear(int birthyear,int nowyear){
	//�ж� ��������ǲ�������
	int i = birthyear;
	int change;   //���������������� 
	int m=leapYear(i);
	if(i==1){
		change=0;
	}else{
		change=i%4;
	}
	int num;// ����ĵĸ���
	num=(nowyear-(i-change))/4-1; 
	return num;
} 



//����  1��1�� ���ⶨʱ�������
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
        	printf("�������ڴ���");
			exit(0);
    }
    return Day;
}
//�������� 
void  physicalrhythm (int num){
	int i =num%23;
	if(i==0){
		printf("�������ô���������"); 
	}else if(i<12){
		printf("�������ڸ߳��յ�%d��",i); 
	}else if(i==12){
		printf("�������ô����ٽ���"); 
	}else{
		printf("�������ڵͳ��յ�%d��",i-12);
	}
}
//��������
void emotionalrhythm(int num){
	int i = num%28;
	if(i==0){
		printf("�������ô���������"); 
	}else if(i<14){
		printf("�������ڸ߳��յ�%d��",i); 
	}else if(i==14){
		printf("�������ô����ٽ���"); 
	}else{
		printf("�������ڵͳ��յ�%d��",i-14);
	}
}
//�������� 
void brains(int num){
	int i = num%33;
	if(i==0){
		printf("�������ô���������"); 
	}else if(i<17){
		printf("�������ڸ߳��յ�%d��",i); 
	}else if(i==17){
		printf("�������ô����ٽ���"); 
	}else{
		printf("�������ڵͳ��յ�%d��",i-17);
	}
	
}
int main (){
   time_t rawtime;
   struct tm *info;
   time( &rawtime );
   info = localtime( &rawtime );
   char*string;
   string=asctime(info);
  // printf("��ǰ�ı���ʱ������ڣ�%s",asctime(info));
   char s[2]=" " ;
   char * S;
   char *middle[8]; 
   //������ʱ����ַ��� ���Ϊ  �岿��   middle[0]���� ����   ��middle[1 ]�����·� ��middle[2] ������middle[3]����ʱ�� ���� ʱ����;  middle[4]������� 
   S=strtok(string,s);
   for (int i = 0; i<5;i++){
   		middle[i]=S;
    	//printf("%s\n",middle[i]);
    	S=strtok(NULL,s);
   }
   //��Сʱ ���� �� �ֿ����ֿ�����middle[3]   �ֱ���middle 567 ��ʾ �� 5 ���� Сʱ ��6 ���� ���� ��7 ���� �� 
    char aprt[2]=":";
    S=NULL;
    S=strtok(middle[3],aprt);
    for(int i = 5;i<=7;i++){
    	middle[i]=S;
    	//printf("%s\n",middle[i]);
    	S=strtok(NULL,aprt);
	}
   //�ֱ� ���岿���ַ��� �����Ӧ��ʱ������
    struct System system;
    system.second=atoi(middle[7]);   //�� 
    system.hour=atoi(middle[5]);     //Сʱ 
    system.minute=atoi(middle[6]);   //���� 
    system.month=Month(middle[1]);   //�·� 
    //system.week=atoi(middle[0]);   
    system.year=atoi(middle[4]);     //��� 
    system.day=atoi(middle[2]);      //���� 
    //  �õ� �����ߵĳ����� 
    int birthYear,birthMonth,birthDay;
    int judge=0;
    
    //�����Ƕ������ֵ �Ƿ�Ϸ����ж�
	 
	while(judge==0){	
	printf("������ ���ĳ������  �ֱ����빫���� �� �� �� �ÿո���ֿ� \n");
    scanf("%d%d%d",&birthYear,&birthMonth,&birthDay);
    //��������ֵ�Ƿ�Ϸ�
    if(birthYear<system.year&&birthYear>1900&&birthMonth<=12&&birthMonth>=1){    //��ݡ��͡��·� ���ж�   ����������������ͬʱ 
    	if(leapYear(birthYear)){                           //���ʱ����  ��Զ��µ������ж� 
    		if(birthMonth==2){
    			if(birthDay<=29&&birthDay>=1){
    				judge=1;
					break;
				}
				printf("�����ֵ�������������롣\n");
				continue;										//��������ļ��  ��������	
			}else if(birthMonth==1||birthMonth==3||birthMonth==5||birthMonth==7||birthMonth==8||birthMonth==10||birthMonth==12){  //���·ݽ������� 
				if(birthDay<=31&&birthDay>=1){
					judge=1;
					break;
				}
				printf("�����ֵ�������������롣\n");
				continue;										//��������ļ��  ��������
			}else if(birthMonth==4||birthMonth==6||birthMonth==9||birthMonth==11){   
				if(birthDay<=30&&birthDay>=1){
						judge=1;
						break;
					}
					printf("�����ֵ�������������롣\n");
					continue; 										//��������ļ��  ��������
				}
			}else{                                                   //�����������   �Զ������� 
				if(birthMonth==2){
					if(birthDay<=28&&birthDay>=1){                          
    					judge=1;
						break;
					}
					printf("�����ֵ�������������롣\n");
					continue;	                                  //��������ļ��  �������� 
				}else if(birthMonth==1||birthMonth==3||birthMonth==5||birthMonth==7||birthMonth==8||birthMonth==10||birthMonth==12){  //���·����� 
					if(birthDay<=31&&birthDay>=1){
						judge=1;
						break;
					}
					printf("�����ֵ�������������롣\n");
					continue;										//��������ļ��  ��������
				}else if(birthMonth==4||birthMonth==6||birthMonth==9||birthMonth==11){
					if(birthDay<=30&&birthDay>=1){
						judge=1;
						break;
					}
					printf("�����ֵ�������������롣\n");
					continue;										//��������ļ��  ��������
				}
			}
		}
		if(birthYear==system.year) {          //����ǽ��������  ��ô�·ݲ��ܳ������ڲ��Ե�ʱ��   ��Ҫ���·ݽ������� 
			if(birthMonth>=1&&birthMonth<system.month){
			  	if(leapYear(birthYear)){                           //���ʱ����  ��Զ��µ������ж� 
    				if(birthMonth==2){
    					if(birthDay<=29&&birthDay>=1){
    						judge=1;
							break;
						}
						printf("�����ֵ�������������롣\n");
						continue;										//��������ļ��  ��������	
					}else if(birthMonth==1||birthMonth==3||birthMonth==5||birthMonth==7||birthMonth==8||birthMonth==10||birthMonth==12){  //���·ݽ������� 
						if(birthDay<=31&&birthDay>=1){
							judge=1;
							break;
						}
					printf("�����ֵ�������������롣\n");
					continue;										//��������ļ��  ��������
			}else if(birthMonth==4||birthMonth==6||birthMonth==9||birthMonth==11){   
				if(birthDay<=30&&birthDay>=1){
					judge=1;
					break;
					}
					printf("�����ֵ�������������롣\n");
					continue;										//��������ļ��  ��������
				}
			}else{
				if(birthMonth==2){
					if(birthDay<=28&&birthDay>=1){                           //�����������   �Զ������� 
    					judge=1;
						break;
					}
					printf("�����ֵ�������������롣\n");
					continue;										//��������ļ��  ��������	
				}else if(birthMonth==1||birthMonth==3||birthMonth==5||birthMonth==7||birthMonth==8||birthMonth==10||birthMonth==12){  //���·����� 
					if(birthDay<=31&&birthDay>=1){
						judge=1;
						break;
					}
					printf("�����ֵ�������������롣\n");
					continue;										//��������ļ��  ��������
				}else if(birthMonth==4||birthMonth==6||birthMonth==9||birthMonth==11){
					if(birthDay<=30&&birthDay>=1){
							judge=1;
							break;
						}
						printf("�����ֵ�������������롣\n");
						continue;										//��������ļ��  ��������
					}
				}	
			}
			//�������Ե��·���ͬ  ����Ҫ�ж� �����Ƿ񳬹�����ʱ������� 
			if(birthMonth==system.month){                       
				if(leapYear(birthYear)){                           //���ʱ����  ��Զ��µ������ж� 
    				if(birthMonth==2){
    					if(birthDay<=29&&birthDay>=1&&birthDay<=system.day){
    						judge=1;
							break;
						}
						printf("�����ֵ�������������롣\n");
						continue;										//��������ļ��  ��������	
					}else if(birthMonth==1||birthMonth==3||birthMonth==5||birthMonth==7||birthMonth==8||birthMonth==10||birthMonth==12){  //���·ݽ������� 
							if(birthDay<=31&&birthDay>=1&&birthDay<=system.day){
								judge=1;
								break;
							}
							printf("�����ֵ�������������롣\n");
							continue;										//��������ļ��  ��������
					}else if(birthMonth==4||birthMonth==6||birthMonth==9||birthMonth==11){   
							if(birthDay<=30&&birthDay>=1&&birthDay<=system.day){
								judge=1;
								break;
							}
							printf("�����ֵ�������������롣\n");
							continue;										//��������ļ��  ��������
						}
					}else{   //�����������   �Զ�������
						if(birthMonth==2){
							if(birthDay<=28&&birthDay>=1&&birthDay<=system.day){                     
    							judge=1;
								break;
							}
							printf("�����ֵ�������������롣\n");
							continue;										//��������ļ��  ��������	
						}else if(birthMonth==1||birthMonth==3||birthMonth==5||birthMonth==7||birthMonth==8||birthMonth==10||birthMonth==12){  //���·����� 
								if(birthDay<=31&&birthDay>=1&&birthDay<=system.day){
								judge=1;
								break;
							}
							printf("�����ֵ�������������롣\n");
							continue;										//��������ļ��  ��������
					}else if(birthMonth==4||birthMonth==6||birthMonth==9||birthMonth==11){
							if(birthDay<=30&&birthDay>=1&&birthDay<=system.day){
								judge=1;
								break;
							}
							printf("�����ֵ�������������롣\n");
							continue;										//��������ļ��  ��������
						}
					}
				}
			}
		printf("�����ֵ�������������롣\n");
	}

	
    //��������� 
	int LeapYear=Leapyear(birthYear,system.year);  
	// ������ʱ�䵽1.1������
	int birth_daynumber= Day(birthMonth,birthDay,birthYear) ; 
	//���ڵ�ʱ�䵽1.1������  
	int now_daynumber=Day(system.month,system.day,system.year);
	//���㹫ʽ�ó� ȡ����ǰ��ֵ   
   	int number=Number(system.year,LeapYear,birthYear,birth_daynumber,now_daynumber);
   	printf("���ڲ��Ե�ʱ���ǣ�   %d�� %d�� %d �� %dʱ %d�� %d��\n\n",system.year,system.month,system.day,system.hour,system.minute,system.second);
   	//printf("����������%d��1��1��������  Ҳ����Ϊ��������ӵ������� %d\n",system.year, LeapYear);
   	printf("���ڵ�1��1�ŵ������� %d ��\n",now_daynumber);
   	printf("�������ڵ�1��1�ŵ������� %d ��\n",birth_daynumber);
   	//��ȡ����ǰ��ֵ  ����     �ó��������   
	physicalrhythm(number);
	printf("\n");
   	emotionalrhythm(number);
   	printf("\n");
   	brains(number); 
   	//system("pause");
   	scanf("%d");
   	return 0;
	}