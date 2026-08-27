# Project 5: Arduino Memory Game

This project combines the Arduino concepts I had learnt from my previous projects into a complete interactive memory game. I independently designed the game logic, introduced new programming concepts and experimented with different hardware and software features to create a 9-round game with increasing difficulty.

<img width="400" alt="Arduino Memory Game" src="YOUR_IMAGE_LINK_HERE" />

## Equipment used:

- Arduino Mega 2560
- LEDs (red, blue, green, yellow, white)
- Resistors (330Ω (3x) and 220Ω (2x))
- Buttons (5x)
- Potentiometer (2.2kΩ - 10kΩ)
- Passive buzzer
- LCD 1602 module
- Breadboard and jumper wires
- USB cable

## Brief project description:

- Practical use: A game-like system containing 9 rounds where the user must correctly reproduce a randomly generated LED sequence.

- Increasing difficulty: The game is divided into three difficulty levels, with the speed of the LED sequence increasing after every three successful rounds.

- LCD: Displays menus, round numbers, difficulty warnings, scores and game results to provide real-time feedback to the user.

- Buttons: Five buttons are used, with each button corresponding to one of the five LED colours.

- Passive buzzer: Produces different frequencies for countdowns, button inputs, difficulty warnings and custom victory/loss jingles.

- Potentiometer: Adjusts the LCD contrast level to improve visibility.

## Learning outcomes:

- Developed a deeper understanding of `for` and `while` loops by applying them to different practical situations.

- Learnt how local and global variables can be used to manage data and persistent game states.

- Learnt how to structure a larger Arduino program using conditional statements, loops, arrays, user-defined functions and function prototypes.

- Improved my ability to visualise an algorithm before implementing it, making it easier to translate the game rules into code.

- Combined concepts from my previous projects with newly learnt programming techniques to create a complete interactive system.

- Improved my debugging approach by using the Serial Monitor to inspect array values and identify problems within the program.

- Improved code readability and organisation by structuring a program of approximately 400 lines using indentation, comments and separate functions.

- Developed a better understanding of how electrical signals and LED brightness interact with human visual perception through practical experimentation.

## My improvements / experimentations:

- Designed and implemented three difficulty levels by experimenting with different LED ON/OFF timings.

- Integrated an LCD display to provide real-time visual feedback instead of relying only on the Serial Monitor.

- Experimented with different resistor values to observe changes in LED brightness and relate them to human eye sensitivity.

- Experimented with different buzzer frequencies to create custom countdown, difficulty, victory and loss sounds.

- Created user-defined sound functions and function prototypes to keep the main program organised and reduce repeated code.

- Implemented a button-release mechanism using a `while` loop to prevent a button being held down from accidentally registering as multiple inputs.

- Implemented a persistent scoring and game-state system using global variables and Boolean logic, allowing the game to progress through multiple rounds without resetting the total score.

## Troubleshooting log:

1. Issue: The user input sequence was initially being stored incorrectly, with most array elements remaining as `0`.

   Fix: I used the Serial Monitor to compare the generated LED sequence with the user's input sequence. This helped me identify that the array position variable was being reinitialised incorrectly inside the input loop. I moved the position variable so that it could increment correctly after every button press.

2. Issue: I initially struggled to determine why the game was not correctly waiting for the user's button inputs.

   Fix: I replaced the original input structure with a `while` loop that continuously checks for button presses until the required number of inputs has been received.

3. Issue: I initially had difficulty deciding how to end the game after either a loss or successful completion of all rounds, since `return` from `loop()` would simply allow Arduino's `loop()` function to execute again.

   Fix: I used a Boolean `gameEnded` variable to control whether the main game code executes, allowing the game to remain in its final state after completion.

## Future improvements:

- Implement proper button debouncing to improve reliability when detecting rapid button presses.

- Increase the number of LEDs and sequence length as the difficulty increases, rather than only increasing the playback speed.

- Add additional gameplay features such as lives, streaks/combos and different mini-games.

- Refactor the repeated button-handling code using arrays and/or functions to make the program shorter and easier to expand.

- Develop a more structured project-management approach for larger projects involving multiple hardware and software features.
