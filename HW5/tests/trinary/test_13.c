
int main() {
	
	int x = 42;
	int y = 420;
	
    string result = "wrong" if(x > y) else ("wrong" if(y == x) else ("correct" if(x <= y) else "wrong"));		
	
	print("result = ");
	print(result);
	
	
    return 0;
}
