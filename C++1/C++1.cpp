// ConsoleApplication4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <stdlib.h>
#include <functional>

class MyClass
{
public:
	MyClass() {};
	MyClass(float xin, float yin) { x = xin; y = yin; }
	bool operator() (MyClass& A)
	{
		return A.x > x && A.y > y;
	}
	
	MyClass operator- ()
	{
		float xx = -x;
		float yy = -y;
		return MyClass(xx,yy);
	}
	float x,y;
private:
	
};

using namespace std;

int main()
{
	negate<MyClass> nn;
	MyClass aMyClass, bMyClass;
	aMyClass.x = 1;
	aMyClass.y = 5;
	bMyClass.x = 3;
	bMyClass.y = 3;

	cout << aMyClass.x << " "<< aMyClass.y<<endl;
	cout << (-aMyClass).x  << (-aMyClass).y<<endl;
	cout << aMyClass.x << " " << aMyClass.y << endl;
	vector<MyClass> v;


    vector<float> vecFloat = {1.1,-1.1,3.4,-3.4,5.5,-5.5,7.9,-7.9};
    list<float> listFloat;

    sort(vecFloat.begin(), vecFloat.end());
    int n = count(vecFloat.begin(), vecFloat.end(),55);
    vector<float>::iterator itor = vecFloat.begin();
    
    for (;itor!=vecFloat.end();itor++)
    {
        cout << (*itor) <<" ceil "<<ceil(*itor) << " floor "<< floor(*itor)<< " round " <<round(*itor) << " nearbyint " << nearbyint(*itor) << endl;
    }
    cout << n << endl;

	string s = "abcdefg";
	char& a = s[2];
	char& b = s[3];
	a = '1';
	b = '2';

	cout << s << endl;
	cout << (int*)s.c_str() << endl;

	s = "pppppppppppppppppppppppp";

	cout << s << endl;
	cout << (int*)s.c_str() << endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
