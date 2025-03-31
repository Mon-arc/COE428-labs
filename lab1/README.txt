Everything worked.

Question 1:
A way that we could take advantage of a betterSort() function while still using the mySort() function primarily would require us to call the betterSort() function from within mySort(). This is because betterSort() has a different signature, and so we would not be able to call it from sortMain.c, and instead would need to use mySort() as a middle-man. This implementation could look something like this (within mySort.c):

void mySort(int d[], unsigned int n){
	betterSort(d, 0, n - 1);
}

This way we are still using the mySort() function along with its signature, although we are hardcoding the arguments being passed to the betterSort function to exploit its advantages.

Notes:
During the portion of the lab where we try to incorporate the arguments in sortMain2.c, at first every time I would run the command with some arguments to be sorted, for example:
testCmdSort 4 3 2 1
The program would output something like:
0
1
2
3
4

The zero at the beginning was always being outputed. I found that this was because I wrote the code to contain all of the arguments and pass them as elements to be sorted in the data[] array. This meant that the argument "testCmdSort" was also being passed as an element to be sorted, which would always be 0. This is why I had to set nDataItems = argc - 1, and why I had to modify the code to only use the arguments after this initial argument.
