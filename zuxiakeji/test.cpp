 #include<iostream>
using namespace std;

int main()
{
	//（1）变量初始化，再const引用 变量
	int b = 10;
	int &a = b;
    int c = 15;
    b = c;
	// b = 19;//b是可以修改的，但是a不能修改
	printf("a=%d,b=%d\n", a, b);
	system("pause");
}
