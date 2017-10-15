                                           ----------Welcome to BlockMe!-----------
/*authors: George Karagiannis,Fotis Georgakopoulos*/

A simple terminal game written in C.All you have to do is to cross the border and reach the opposite side.Sounds simple right?
You can play VS A.I opponents,or human ones(if you have any friends at all).

Each round,you can:
-Place a 2-block obstacle by defining the position,as soon as the input refers to successive blocks(for example A8A9 is correct,A8C6 is incorrect)up to 5 in total.
-Make a move to the next block,by moving up,down,left or right.For example if you are at A7 you can move to A8 by typing A8 or 8A.The input is case insensitive.
-Ask for help,by typing "help",without the " ". 
-Exit the game by typing "exit",without the " ".

Some things to note:
-Player 1 is a bot with pathfinding capabilities.We implemented a table mapping algorithm to find the shortest path to victory.He can be a tough opponent.
-The other players are simple AI opponents.
-All A.I opponents use a simple deciding factor,whether to place an obstacle or move.
-One player must be a human.(we recommend to place player 1 as an A.I opponent so that you can test our pathfinding algorithm-It has some flaws)


Good luck and have fun!
