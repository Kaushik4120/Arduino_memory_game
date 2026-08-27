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

- Practical use: Has a game-like system containing 9 rounds with increasing difficulty where the user has to correctly copy the random sequence the LED's lights that the microcontroller generates.

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

- Mastered the art of creating intermediate level fun display screens to gamify the project extensively, using my knowledge of delay() and LCD functions

- Learnt to structure my 400-line code in an efficient manner using indentation and comments to improve the code's readability.

- Learnt and implemented new concepts using my past experience in coding languages, such as user defined functions, different combinations of loops and conditional statements

- Learnt how to visualize the game's algorithm and practically experiment with it, which immensely with writing the code.

- Rather than ineffectively using the 'return' function, I used Boolean conditional statements to manage game losses/victories.
  
## My improvements / experimentations: 

- Initially, I tested different resistor values with LED's to observe varying brightness levels, and related them with human eye sensitivity.

- Integrated an LCD display to provide real-time visual feedback instead of only using the Serial Monitor.

- Experimented with different frequency sounds, which helped me create custom jingles for menu screens and victory/loss messages.

- Used user-defined functions and function prototypes to write the game sound jingles, which improved reduced code length and improved readability.

- When any button in the user sequence was pressed for too long, it registered as multiple presses. To solve this, I used a simple conditional statement positioned inside a while loop, which made sure only a single press would be registered while the button is still being pressed.


## Troubleshooting log:

- Issue: I consistently forgot how a button worked, because it involved a slightly non-intuitive physics concept related to electrical circuits.

  Fix: I made up a two-point framework stating the two main differences between pull-up and pull-down resistors using mnemonic devices, which made the concept much more memorable.

- Issue: Initially, no matter how hard I tried, I lost on the very fisrt round every time. 

  Fix: I was skeptical of some technical errors, and used the Serial monitor to check if both the LED and user sequence arrays matched. This helped me find out the wrong location of my variables initalization, and eventually solve it. 

## Future improvements:

- Implement button debouncing to make sure faulty circuit boards do not negatively affect gameplay.

- Increase LED count with increasing difficulty, in addition to solely an increase in speed.

- Add additional features such as game lives, streaks/combos as well as options to play various mini-games in addition to the memory game itself.

- Use other coding techniques to make the code even shorter and avoiding repetitive conditional statements.

- Setting up a proper multi-stage project management framework for large projects involving different features, to make the process much smoother.
