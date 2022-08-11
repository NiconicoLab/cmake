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

	return 0;
}
