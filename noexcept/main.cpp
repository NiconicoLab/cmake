#include <iostream>

// noexceptは関数が絶対に例外が発生しないことを保証し，コンパイラが最適化がしやすくする

// 例外が発生するかもしれない関数
void foo1()
{

}

void hoge2() noexcept(false)
{

}

// 例外が発生しない関数
void hoge3() noexcept
{
}

int hoge4() noexcept(true)
{
	return 0;
}

// 外側のnoexceptは例外仕様指定子(括弧内がtrueならnoexcept)とし，
// 内側のnoexceptは演算子(括弧内の式が例外を投げないならtrue)を表現
int hoge5() noexcept(noexcept(hoge4()))
{
	return 0;
}

int main()
{	
	return 0;
}
