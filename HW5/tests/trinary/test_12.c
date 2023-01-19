
int main() {
	
    string result = ("wrong" if(true) else "wrong") if(false) else (("wrong" if(false) else "correct") if(true) else "wrong");		
	
	print("result = ");
	print(result);
	
    return 0;
}
