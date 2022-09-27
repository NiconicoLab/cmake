#include <stdio.h>

class CSample
{
public:
	int x;
	int y;
	
	CSample(int a, int b);
	CSample(const CSample& cls);
	~CSample();
};

CSample::CSample(int a, int b)
{
	printf("CSample\n");
	x = a;
	y = b;
}

//  コピーコンストラクタの定義
CSample::CSample(const CSample& cls)
{
	printf("Copy CSample\n");
	x = cls.x;
	y = cls.y;
}

CSample::~CSample()
{
	printf("~CSample\n");
}

int main()
{
	CSample clsA(100, 200);

	// コピーコンストラクタはオブジェクト定義時に"="による初期化によって呼び出される
	CSample clsB = clsA; // CSample clsB(clsA);でも同じ意味になる
	
	clsB = clsA; //  代入のため，コピーコンストラクタとは別物
	
	return 0;
}
