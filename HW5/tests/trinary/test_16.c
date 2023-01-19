
int main() {
	
	int x = 13;
	int y = 13;
	
    byte result = 0 if(x > 13) else ((0 if(x - y == 1) else 0 ) if(y - x == 1 ) else ( 1 if(y - x >= 0) else 0));		
	
	print("result = ");
	printi((int)result);
	
	
    return 0;
}