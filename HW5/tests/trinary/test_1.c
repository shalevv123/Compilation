#include <stdio.h>
#include <stdbool.h>

int main() {
    int one_true = (true)? 1: 0;	
    int two_t_t = (true)? ((true)?1:0): 0;	
    int two_t_f = (true)? ((false)?0:1): 0;	
	int one_false = (false)? 0: 1;	
    int two_f_t = (false)? 0: ((true)? 1: 0);	
    int two_f_f = (false)? 0: ((false)?0:1);

	printf("one_true = %d\ntwo_t_t = %d\ntwo_t_f = %d\none_false = %d\ntwo_f_t = %d\ntwo_f_f = %d\n",one_true, two_t_t, two_t_f, one_false, two_f_t, two_f_f);
	
    return 0;
}
