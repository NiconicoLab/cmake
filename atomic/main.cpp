#include <iostream>
#include <atomic>

void func1(void)
{
	std::atomic<int> x(3);

	// x == expectedなので、xは2に置き換えられる
	int expected = 3;
	bool result = std::atomic_compare_exchange_strong(&x, &expected, 2);

	// std::boolalphaはbool値を文字列として入出力することを指示するマニピュレータ
	std::cout << std::boolalpha << result << " " << x.load() << " " << expected << std::endl;
}

void func2(void)
{
	std::atomic<int> x(3);

	// x != expectedなので、expectedがxの値で置き換えられる
	int expected = 1;
	bool result = std::atomic_compare_exchange_strong(&x, &expected, 2);

	// std::boolalphaはbool値を文字列として入出力することを指示するマニピュレータ
	std::cout << std::boolalpha << result << " " << x.load() << " " << expected << std::endl;
}

int main()
{
	func1();
	func2();

	return 0;
}
