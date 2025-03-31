Written by Hassan Elshikh, 501263004

Requirement 1:

Suppose that towers(5, 2, 3) is invoked.

1. How will the first recursive call to towers() be invoked? Answer this question in the form: towers(x, y, z) where you give the actual values to the  three parameters.

If towers(5, 3, 2) is invoked, the first recursive call to towers would be towers(4, 2, 1). Given the algorithm n = 5, from = 3, dest = 2. Following the algorithm with these parameters, we can see that the first recursive call is towers(n-1, from, spare) which would equate to towers(4, 2, 1) where x = 4, y = 2, z = 1.

2. How many recursive calls to towers() will be made before this first recursive call actually returns to the initial invocation?

There will be 5 recursive calls made before the first recursive call returns to the initial invocation. The first recursive call would be towers(4, 2, 1) and the last one would be towers(0, 2, 1)

3. Once towers(5, 2, 3) has invoked its first recursive call to towers() and this invocation has returned, what will be printed to stdout? (i.e. What actual move will be made by towers(5, 2, 3) ?)

The first output to stdout will be:

2 3 

This is because it is simply printing the 'from' and 'dest' values.

4. How will the second recursive call to towers() be invoked? Answer this question in the form: towers(x, y, z) where you give the actual values to the three parameters.

The second recursive call to towers() will be towers(3, 2, 3). This is because it is the first recursive call made after towers(4, 2, 1), therefore it is the second recursive  call.

Question:

Suppose that towers(8, 1, 2) is invoked. How many lines will be printed to stdout?

Using the wc -l command after redirecting the output of towers(8, 2, 1) into a file named countLines, the number of lines outputed to stdout is 255.

In this lab I believe that i have achieved everything required in the lab guide, and that it was completed successfully.
