# Project 4: Memory game

Based on the beginner knowledge i have learnt so far related to Arduino, i had indipendety designed a memory game, using components i used in the last 3 projects, and by introducing new software concepts and features.

## Equipment used:

- Arduino Mega 2560
- LED's (red, blue, green, yellow, white)
- Resistors( 330ohm (3x) and 220ohm (2x) )
- Buttons (5x)
- Potentiometer (2.2kΩ - 10kΩ)
- Passive buzzer
- LCD 1602 module
- Breadboard and jumper wires
- USB cable

## Brief project description:

- Practical use: Has a game-like system where the user has to correctly copy the random sequence of LED' lights that the microcontroller generates.

- LCD: displays menu screens and game results to guide the user through the game

- Buttons: Five buttons are used, each representing a different LED color.

- Passive buzzer: Produces noises varying in pitch, from countdowns to victory message scales.

- Potentiometer: Adjusts the LCD contrast level to improve visibility.

## Learning outcomes:

- Deeply familiarized myself with the differences between 'for' and 'while' loops in practical scenarios

- Learnt about the physics and the relationship between electrical signals and human eyesight

- Combined almost every concept learnt thus far into a single project, combined with newly learnt code features as well.

- Added multiple debugging methods to my technical databank, making finding mistakes much more efficient and hassle free.

- Found the difference between how local and global variables are used to efficiently control such game-like projects.

- Mastered the art of creating intermediate level fun display screens to gamify the project extensively.

## My improvements / experimentations: 

- Initially, I tested different resistor values with LED's to observe varying brightness levels, and related them with human eye sensitivity.

- Integrated an LCD display to provide real-time visual feedback instead of only using the Serial Monitor.

- Experimented with improving the physical circuit layout by using longer jumper wires and repositioning components for easier interaction.

- Explored future improvements such as button debouncing and more advanced sound processing methods to support multiple notes/chords.

- Developed a better understanding of the difference between `lcd.clear()` and `lcd.setCursor()` functions from the LiquidCrystal library.

## Troubleshooting log:

- Issue: Due to the increased complexity of the project, I made repeated syntax and pin connection errors, such as missing semicolons, incorrect pin numbers and small mistakes in breadboard connections.

  Fix: I created a checklist framework that I followed before uploading completed project code. This included checking pin assignments, wiring connections and code syntax, which reduced repeated mistakes.

- Issue: The breadboard became too congested, making it difficult to press the buttons properly.

  Fix: I used longer jumper wires for the button inputs and moved the buttons towards the edge of the breadboard, creating more space and making the circuit easier to interact with.

- Issue: Some buttons were not fitting tightly into the breadboard and would move when pressed.

  Fix: I checked the button orientation and positioning on the breadboard to ensure a more secure connection.

## Future improvements:

- Implement button debouncing for more reliable button detection.

- Add support for playing multiple notes simultaneously (chords).

- Improve sound generation to create a more realistic piano experience.

- Add LED indicators for visual feedback when notes are played.
