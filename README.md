𝑺𝒐_𝒍𝒐𝒏𝒈

    A simple 2D game where the player collects items and escapes the map.

______________________________________________________________________________________

Description

The so_long project is part of the 42 School curriculum. The goal is to create a small 2D game using the minilibx graphics library. The game features a player navigating a grid-based map, collecting items, and reaching the exit while adhering to strict coding standards.

Features

	•	Reads and validates a map file provided as input.
	•	Renders the game in a window using the minilibx library.
	•	Allows the player to move up, down, left, and right.
	•	Counts and displays the number of movements.
	•	Ends the game when all items are collected, and the player reaches the exit.

 Requirements

	•	minilibx: A minimalistic graphics library.
	•	gcc: For compiling the program.
	•	macOS to run the program

 Controls

	•	W: Move up.
	•	A: Move left.
	•	S: Move down.
	•	D: Move right.
	•	ESC: Close the game.

 Map Format

The game uses a .ber file as the map input. The map must adhere to the following rules:

	1.	The map must be rectangular.
	2.	It must contain only these characters:
	•	1: Wall.
	•	0: Empty space.
	•	P: Player starting position (exactly 1).
	•	C: Collectible items (at least 1).
	•	E: Exit (exactly 1).
	3.	The map must be surrounded by walls (1).
	4.	The player must be able to reach all collectibles and the exit.

