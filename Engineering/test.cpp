#include <iostream>
using namespace std;
#include<algorithm>
class Str{
	public:
	explicit Str(int x){
		cout<<"我是想把整数变字符串"<<endl;
	}
	explicit Str(const char* a)
	{
		cout<<"我是想把字符数组变字符串"<<endl;
	}

};


int main( ){

        char* a = "abc";
	Str s = a; 
	// 输出："我是想把整数变字符串"
	// 它把'c'的ASCII码传进去了，如果这样变成字符串那就得到一个数字，
        // 而我们期待的是把'c'变成字符串。
	return 0;
}
