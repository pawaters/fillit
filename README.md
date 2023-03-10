# fillit
Tetris algo. Make the smallest possible "square" with a given list of tetrominoes, no external libraries.

## HOW TO RUN THE PROGRAM:
./fillit [input_file]

For example: ./fillit valid1_test7

## WHAT DOES FILLIT DO:
### - Input: a text file with tetriminoes. Example:

![Example img of input](https://github.com/pawaters/fillit/blob/master/Example%20img%20of%20input.jpg)

### - Output: gives back the smallest square that fits these tetriminoes

![Example img of output](https://github.com/pawaters/fillit/blob/master/Example_img_output.jpg)

As you can see, each tetrimino is represented with a letter.

## HOW DOES IT WORK?

In 5 parts, and in summary, with reference to the c files dealing with each part where you will be able to find comments explaining in more detail the logic:
1) **Main**: checks if one file only is given as argument, and performs some basic format checks on the input file.
2) **Parse**: takes the input file and converts it in a structure we defined, which enables our program to work on it .
3) **Validate**: makes all the checks on the input so no edge case is left.
4) **Solve**: we create an initial empty square of size X, try to put the tetriminoes, and if it doesn't work, increase the size and try again.
5) **Output & clean up**: prints the square with the solution, and frees the memory used we do not need anymore. 



