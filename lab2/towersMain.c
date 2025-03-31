#include <stdlib.h>
#include <stdio.h>
#include "towers.h"

int main(int argc, char **argv)
{
	int n;
	int i;
	int from;
	int dest;

	if(argc == 2){
		from = 1;
		dest = 2;
		n = atoi(argv[1]);
		towers(n, from, dest);
	}
	else if(argc == 4){
	n = atoi(argv[1]);
	from = atoi(argv[2]);
	dest  = atoi(argv[3]);
	if(			//Make sure input arguments are valid
	from  == dest ||
	from < 1 || from > 3 ||
	from < 1 || dest > 3
	){
	fprintf(stderr, "Input arguments invalid");
	exit(1);
	}
	else
	towers(n, from, dest);
	}
	else if(argc == 1){
	n = 3;
	from = 1;
	dest = 2;
	towers(n, from, dest);
	}

	else	// If number of args is not 1, 2, or 4
		// print error
		// 1 arg: towers
		// 2 args: towers 5
		// 4 args: towers 8 1 2
	fprintf(stderr, "Number of Arguments is Incorrect");
	
	exit(0);
}
