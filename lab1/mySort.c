void mySort(int d[], unsigned int n)
{
	int x, y;

	for(int i = 0; i < n; i++){
		x = i - 1;
		y = d[i];
		while(x>=0 && d[x]>y){
			d[x+1] = d[x];
			x--;
		}
		d[x+1] = y;
	}

}
