#include <stdio.h>
#include <stdbool.h>

int main() {
	//=====block 1=====
    int complex_1= (true)? ((true)?((true)?((true)?((true)?((true)?((true)?((true)?1:0):0):0):0):0):0):0):0;	
    int complex_2= (true)? ((true)?((true)?((false)?((true)?((true)?((true)?((true)?0:0):0):0):0):1):0):0):0;	
    int complex_3= (false)? ((true)?((true)?((false)?((true)?((true)?((true)?((true)?0:0):0):0):0):0):0):0):1;	
    int complex_4= (true)? ((true)?((true)?((true)?((true)?((true)?((true)?((false)?0:1):0):0):0):0):0):0):0;	
	
	printf("===== block 1 =====\n1st = %d\n2nd = %d\n3rd = %d\n4th = %d\n",complex_1, complex_2, complex_3, complex_4);
	
	//=====block 2=====
    complex_1= (false)?0:((false)?0:((false)?0:((false)?0:((false)?0:((false)?0:((false)?0:((false)?0:((false)?0:1))))))));	
    complex_2= (false)?0:((false)?0:((false)?0:((false)?0:((false)?0:((true)?1:((false)?0:((false)?0:((false)?0:0))))))));	
    complex_3= (false)?0:((false)?0:((true)?1:((false)?0:((false)?0:((false)?0:((false)?0:((false)?0:((false)?0:0))))))));	
    complex_4= (true)?1:((false)?0:((false)?0:((false)?0:((false)?0:((false)?0:((false)?0:((false)?0:((false)?0:0))))))));	
	
	printf("===== block 2 =====\n1st = %d\n2nd = %d\n3rd = %d\n4th = %d\n",complex_1, complex_2, complex_3, complex_4);
	
	//=====block 3=====
    complex_1= (false)?0:((false)?0:((false)?0:((false)?((true)?0:0):((false)?((true)?0:0):((false)?((true)?0:0):((false)?0:((false)?0:((false)?0:1))))))));	
    complex_2= (false)?((true)?0:0):((false)?0:((false)?0:((true)?((true)?((true)?1:0):0):((false)?0:((true)?0:((false)?0:((false)?0:((false)?0:0))))))));	
    complex_3= (false)?((true)?0:0):((false)?0:((false)?0:((false)?((true)?((true)?0:0):0):((false)?0:((true)?1:((false)?0:((false)?0:((false)?0:0))))))));		
    complex_4= (true)?((false)?((false)?0:0):((true)?((false)?0:1):0)):((false)?0:((false)?0:((false)?0:((false)?0:((false)?0:((false)?0:((false)?0:((false)?0:0))))))));	
	
	printf("===== block 3 =====\n1st = %d\n2nd = %d\n3rd = %d\n4th = %d\n",complex_1, complex_2, complex_3, complex_4);
	
	//=====block 4=====
	int x = 42;
	int y = 420;
    complex_1= (y > x)? ((y >= x)?((x < y)?((x <= y)?((y == 420)?((x == 42)?((!(x > y))?((!(x >= y))?1:0):0):0):0):0):0):0):0;	
    complex_2= (x == (y/10))?((y-x == 378)?((x != 50)?((x == y)?((x !=y )?((x >= 0)?((x >= 1)?((x != 19)?0:0):0):0):0):1):0):0):0;	
    complex_3= (x == 17)?((x < y)?((x < 43)?((x > y)?((x <= y)?((y > 300)?((y > 0)?((y -10 == 410)?0:0):0):0):0):0):0):0):1;	
    complex_4= (x != y)? ((x > 6)?((x >= 42)?((y + x == 462)?((y > 5)?((y < 690)?((x < 43)?((x > 42)?0:1):0):0):0):0):0):0):0;	
	
	printf("===== block 4 =====\n1st = %d\n2nd = %d\n3rd = %d\n4th = %d\n",complex_1, complex_2, complex_3, complex_4);
	
	//=====block 5=====
    x = 0;
	y = 0;
    complex_1= (y > x)?0:((y != x)?0:((y - x == 1)?0:((y == 1)?((y == 0)?0:0):((x == 1)?((x == 0)?0:0):((x + y == 7)?((x + y == 0)?0:0):((x != 0)?0:((x < 0)?0:((x > 0)?0:1))))))));	
    x = 13;
    y = 13;
	complex_2= (y != x)?((y == 13)?0:0):((y == 0)?0:((y > 13)?0:((y >= 13)?((y <=13)?((y < 14)?1:0):0):((y > 14)?0:((x <= 13)?0:((x < y)?0:((x < 7)?0:((x > 15)?0:0))))))));	
    complex_3= (x < y)?((x == 13)?0:0):((x > y)?0:((x > 13)?0:((x != y)?((x - 13 == 0)?((x - y == 0)?0:0):0):((x > y)?0:((x >= y)?1:((y > x)?0:((y == 342)?0:((y == 5)?0:0))))))));		
    complex_4= (x >= y)?((x < 13)?((x > 13)?0:0):((y >= 13)?((y == 15 - 1)?0:1):0)):((y != 13)?0:((y + x == 13)?0:((13 != 13)?0:((15 - 1 != 14)?0:((x == 5)?0:((y == 7)?0:((y < 0)?0:((y > 420)?0:0))))))));	
	
	printf("===== block 5 =====\n1st = %d\n2nd = %d\n3rd = %d\n4th = %d\n",complex_1, complex_2, complex_3, complex_4);
	
	
	
	
    return 0;
}
