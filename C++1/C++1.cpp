// ConsoleApplication4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<atltrace.h>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <stdlib.h>
#include <functional>

class Point
{
public:
	Point():x(0.f),y(0.f){};
	Point(float xin, float yin) { x = xin; y = yin; }
	bool operator< (Point& A){return x < A.x && y < A.y;}
	
	Point operator- (){return Point(-x,-y);}
	float& X() { return x; }
	float& Y() { return y; }
	static bool SortPoint(Point ptA, Point ptB) { return ptA < ptB; }
private:
	float x,y;
};

using namespace std;

int main()
{
	Point Pt_a(1.f,5.f), Pt_y;
	Pt_y.X() = 3;
	Pt_y.Y() = 3;


	ATLTRACE("Output Pt: (%7.2f,%7.2f)\n",Pt_a.X(), Pt_a.Y());
	ATLTRACE("Output -Pt: (%7.2f,%7.2f)\n",(-Pt_a).X(),(-Pt_a).Y());
	ATLTRACE("Output Pt: (%7.2f,%7.2f)\n", Pt_a.X(), Pt_a.Y());

    vector<float> vecFloat = {1.1,-1.1,3.4,-3.4,5.5,-5.5,7.9,-7.9};
	vector<Point> vPt = { {1,-2},{-3,-4} ,{-5,-6},{7,8} };
    list<float> listFloat;

    sort(vecFloat.begin(), vecFloat.end());
	sort(vPt.begin(), vPt.end());
	reverse(vPt.begin(), vPt.end());
	sort(vPt.begin(), vPt.end(), Point::SortPoint);
    int n = count(vecFloat.begin(), vecFloat.end(),5.5);
    vector<float>::iterator itor = vecFloat.begin();
    
    for (;itor!=vecFloat.end();itor++)
    {
        ATLTRACE("%7.2f   ceil:%7.2f   floor:%7.2f   round:%7.2f   nearbyint:%7.2f\n", (*itor),ceil(*itor),floor(*itor),round(*itor),nearbyint(*itor));
    }
  
	string s = "abcdefg";
	char a[256] = "";
	sprintf_s(a, sizeof(a), "%f %f ", vecFloat[0], vecFloat[1]);
	s += a;
	ATLTRACE2("%s",s.data());

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
