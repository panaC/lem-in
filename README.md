# lem-in

move the anthill from start room to end room with the smallest step count.. part of graph theory

This is a project of algo branch part 42 school

I realised this project with goal of find all the path from a graph (anthill) ordered by length.

More over in bonus will be print all the walking ant in stdout with arg option enabled.

## usage

`Listen on stdin`

> ./lem-in [-v] < file

## demo

```
./lem-in -v < ant1.txt
12
##start
1 23 3
2 16 7
#commentaire
3 16 3
4 16 5
5 9 3
6 1 5
7 4 8
##end
0 9 5
0-4
0-6
1-3
4-3
5-2
3-5
#autre commentaire
4-2
2-1
7-6
7-2
7-4
6-5

VERBOSE : 2 path find
VERBOSE : path numero 0
VERBOSE : 0 -> id 3 name 4 x 16 y 5
VERBOSE : 1 -> id 1 name 2 x 16 y 7
VERBOSE : 2 -> id 0 name 1 x 23 y 3
VERBOSE : path numero 1
VERBOSE : 0 -> id 5 name 6 x 1 y 5
VERBOSE : 1 -> id 4 name 5 x 9 y 3
VERBOSE : 2 -> id 2 name 3 x 16 y 3
VERBOSE : 3 -> id 0 name 1 x 23 y 3
L1-2 L2-3
L1-4 L3-2 L2-5
L1-0 L3-4 L4-2 L2-6
L3-0 L4-4 L5-2 L2-0
L4-0 L5-4 L6-2
L5-0 L6-4 L7-2
L6-0 L7-4 L8-2
L7-0 L8-4 L9-2
L8-0 L9-4 L10-2
L9-0 L10-4 L11-2
L10-0 L11-4 L12-2
L11-0 L12-4
L12-0
```

## time flow

Project realised in 1 week :
- 2-3 days for parsing
- 2-3 days for graph pathfinder algo
- 2-3 days for test and debuging

## ressources 

- [flowchart](https://drive.google.com/file/d/1Wz0kTdM4yHQg1EEiyr6p7ZJ37KEUWQ8o/view?usp=sharing)
- [pdf in french](https://cdn.intra.42.fr/pdf/pdf/185/lem-in.fr.pdf)

