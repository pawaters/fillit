# fillit
Tetris algo. Make the smallest possible "square" with a given list of tetrominoes, no external libraries.

HOW TO RUN THE PROGRAM:
./fillit [input_file]
For example: ./fillit valid1_test7

WHAT DOES FILLIT DO:
- Input: a text file with tetriminoes. Example:

...#
...#
...#
...#

....
....
....
####

.###
...#
....
....

- Output: gives back the smallest square that fits these tetriminoes

ABBBB
ACCC.
A..C.
A....
.....

As you can see, each tetrimino is represented with a letter.

HOW DOES IT WORK?

In 5 parts, and in a nutshell:
1) Main: checks if one file only is given as argument, and performs some basic format checks on the input file.
2) Parse: takes the input file and converts it in a structure we defined, which enables our program to work on it.
3) Validate: makes all the checks on the input so no edge case is left.
4) Solve: we create an initial empty square of size X, try to put the tetriminoes, and if it doesn't work, increase the size of the square and try again (algo in more detail below)
5) Output & clean up: prints the square with the solution, and frees the memory used we do not need anymore. 

ALGORITHM
- create an initial map
- is the piece in bounds?
- does the piece overlap with another already set there?
    if yes: then place it and try the next piece, until all is done.
    if no: move the last piece by 1 and try again. if no piece works, increase the size of the square.
- if still no solution, move last piece.
This is done thanks to nested loops and recursion.

