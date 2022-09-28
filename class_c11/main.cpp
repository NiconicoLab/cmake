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

class CTest
{
public:
	CTest() = default; // コンストラクタをコンパイラのデフォルトで生成
	CTest(const CTest& ct) = delete; // コピーコンストラクタは削除
	virtual ~CTest() = default; // 仮想関数としてデストラクタをデフォルト生成

	int x;

#if 0 // 関数の後ろにconstを付けることでメンバ変数を変更することができない(コンパイルエラー)
	void updateVal(int a) const {
		x = a;
	}
#endif
	
	virtual void foo() final { ; }
	
	virtual void foo1() { ; }
	virtual void foo2() { ; }
	void foo3() { ; }

	virtual void hoge() = 0; // 純粋仮想関数
};

class CTestChild final : public CTest
{
public:
	// void foo() { ; } // NG: final 仮想関数はオーバーライドできない
	void foo1() override { ; }  // OK
	void foo2() override final { ; } // OK: override と final の両方を付けることは可能
	// void foo3() override { ; } // NG: A::foo3() は仮想関数ではないためコンパイルエラー
	// void foo4() override { ; } // NG: A::foo4() は存在しないためコンパイルエラー

	void hoge() override { ; } // 純粋仮想関数
};

int main()
{
	CSample clsA(100, 200);

	// コピーコンストラクタはオブジェクト定義時に"="による初期化によって呼び出される
	CSample clsB = clsA; // CSample clsB(clsA);でも同じ意味になる
	
	clsB = clsA; //  代入のため，コピーコンストラクタとは別物

	// ----------------------------------------------------

#if 0 // 純粋仮想関数があるクラスのため，インスタンス化できない
	CTest ctParent;
#endif
	
	CTestChild ctA;

#if 0
	CTestChild ctB = ctA; // コピーコンストラクタはdeleteで定義されているため，コンパイルエラーとなる
#else	
	CTestChild ctB;
	ctB = ctA; // コピーコンストラクタではなく，代入(ムーブ)となるため問題ない
#endif
	
	return 0;
}
