# So Long my dear !!

<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/ReivenIV/so_long?color=lightblue" />
<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/ReivenIV/so_long?color=green" />

Welcome to the 42 So_Long project! This project is part of the curriculum at 42 and focuses on creating a 2D game using the MinilibX, a simple graphic library provided by 42. So_Long is a game where the player navigates through a map, collects items, and avoids obstacles to reach the goal.

## Objective
The objective of the So_Long project is to develop a fully functional game that incorporates various game elements, such as map rendering, player movement, collision detection, item collection, and win/lose conditions. By completing this project, you will enhance your understanding of game development concepts and gain practical experience in using the MinilibX library.

## Features
Map Rendering :
So_Long allows you to load and render game maps stored in a specific format, typically a file with a .ber extension. The map consists of different tiles representing walls, paths, collectible items, the player's starting position, and the exit. The MinilibX library provides functions to render graphical elements on the screen, enabling you to display the map with the appropriate textures and colors.

## Player Movement
The player can move in four directions: up, down, left, and right, within the bounds of the map. By handling keyboard inputs, you can update the player's position on the screen accordingly. The MinilibX library provides functions to capture key events and perform actions based on the pressed keys.

## Collision Detection
To ensure the player doesn't move through walls or outside the boundaries of the map, collision detection is implemented. The game checks if the player's desired movement will result in a collision with a wall or if the player has reached the exit. If a collision is detected, the player's movement is restricted.

## Item Collection
Throughout the map, there may be collectible items that the player can interact with. When the player reaches a tile containing an item, it is collected, and the player's score is incremented. This feature adds an additional layer of gameplay and encourages exploration.

## Win/Lose Conditions 
The win condition is achieved when the player successfully reaches the exit tile. In contrast, the lose condition can be triggered by specific events, such as colliding with enemies or running out of lives. Implementing win and lose conditions adds a sense of challenge and completion to the game.


## How to test it: 
- you will need mlx and `make` it.
- clone these project & `make` it.
- you can check in launch.txt the different comands to launch the program
