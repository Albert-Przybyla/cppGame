## General info
This is a simple C++ game.
	
## Technologies
Project is created with:
* SFML
* C++ 11
	
## Setup
To run this project on macos using homebrew:

```
$ brew install sfml
$ g++ -std=c++11 ./src/main.cpp -I/opt/homebrew/Cellar/sfml/2.5.1_2/include  -o game -L/opt/homebrew/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network
$ ./prog
```