#include <iostream>
#include <time.h>

int main()
{
	// constexprは型修飾子ではなく型指定子で，ROM化可能 or ROM化できる可能性があるという意味を持つ
	// inline展開されてプログラムに埋め込まれる
	constexpr unsigned int num = 10;
	printf("%d\n", num);

	// 乱数の初期化
	srand(time(NULL));

	// C+11以降constはRAMにしか配置できない変数に対して使う修飾子
	const int s = rand() % 10 + 1;
 	// constexpr int s = rand() % 10 + 1; // コンパイル時に値が決まらないため，コンパイルエラーが出る
	printf("rand = %d\n", s);
	
	return 0;
}
