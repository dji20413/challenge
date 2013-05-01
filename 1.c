#include <stdio.h>

unsigned long length = 0;

unsigned long cycle(unsigned long num) {
  length++;
	
	if( num == 1 ) 
		return length;
	
	
	if( num % 2 == 0 )
		return cycle(num/2);
	else
		return cycle(num*3+1);
}

void main() {
	unsigned long n, _i, _j, i, j, max_cycle;
	
	while(scanf("%ld %ld", &_i, &_j) != EOF ) {
		
		i = _i;
		j = _j;
		
		if( i > j ) {
			unsigned long tmp = j;
			j = i;
			i = tmp;
		}
		
		if( j > 1000000 || i < 1 )
			continue;
		
		max_cycle = 0;
		
		for( n = i ; n <= j ; n++ ) {
			length = 0;
			cycle(n);		
			if( length > max_cycle ) {
				max_cycle = length;
			}
		}
		
		printf("%u %u %u\n", _i, _j, max_cycle);
	}
	
	return 0;
}
