#include <iostream>

int main()
{	
	int ar[] = { 1, 3, 5, 7, 9 };
	
	for(auto x : ar) {
		printf("%d ", x);
	}
	printf("\n");

	for(auto x : ar) {
		printf("%d ", x);
		if( x == 7 ) {
			break;
		}
	}
	printf("\n");

	auto num = 0; // int 型
	const auto str = "string"; // strはconst char型
	std::cout << num << " " << str << std::endl;

	return 0;
}
