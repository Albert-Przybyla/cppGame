## General info
This is a simple C++ game.
	
## Technologies
Project is created with:
* SFML
* C++
	
## Setup
To run this project on macos using homebrew:

```
$ brew install sfml
$ g++ ./src/main.cpp -I/opt/homebrew/Cellar/sfml/2.5.1_2/include  -o game -L/opt/homebrew/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network
$ ./prog
```