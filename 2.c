#include <stdio.h>

// array
char ar[100][100];
char mine[100][100];
int n, m;
  
int calc(int x, int y) {
		
	int l, r, t, b, i, j;
	int cnt = 0;
	
	if( ar[x][y] == '*' )
		return -1;
		
	l = y <= 0 ? 0 : y-1;
	r = y >= n-1 ? y : y+1;	
	
	t = x <= 0 ? 0 : x-1;	
	b = x >= m-1 ? m : x+1;		
	
	for( i = t ; i <= b ; i++ ) {
		for( j = l ; j <= r ; j++ )	{
			if( ar[i][j] == '*' ) 
				cnt++;			
		}
	}
	return cnt;
}


int main() {

	int i, j;
	int tot = 1;

	// input n, m
	while(scanf("%d %d", &n, &m) != EOF ) {

		if( m>0 && m <= 100 && n > 0 && n <= 100 ) {
				
			for( i = 0 ; i < n ; i++ ) {		
				scanf("%s", ar[i]);			
			}
					
			for( i = 0 ; i < n ; i++ ) {	 // i = row
				for( j = 0 ; j < m ; j++ ) { // j = col
					int ret = calc(i, j); 	 // row, col
					if( ret == -1 ) {
						mine[i][j] = '*';
					} else {
						mine[i][j] = '0' + ret;
					}								
				}
				mine[i][j] = '\0';
			}
			
			printf("\nField #%d:\n", tot++);
			for( i = 0 ; i < n ; i ++ ) {		
				printf("%s\n", mine[i]);			
			}
		}		
	}
	
	return 0;
}
