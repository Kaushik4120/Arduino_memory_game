# Project 4: Memory game



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

- Practical use: Combines buttons, potentiometer, buzzer and LCD display to create a simple digital piano system.

- Potentiometer: Adjusts the LCD contrast level to improve visibility.

- LCD: Displays the note name and frequency corresponding to the button being pressed.

- Buttons: Five buttons are used, each representing a different note from the C Major scale (4th octave).

- Passive buzzer: Produces the sound output using the frequency corresponding to the pressed button.

## Learning outcomes:

- Learnt how to use arrays and loops to make code cleaner, more efficient and easier to expand.

- Learnt how to use a new hardware component (LCD 1602 module) from scratch and integrate it into an existing project.

- Learnt how to use library functions to simplify hardware communication (LiquidCrystal library).

- Improved my understanding of circuit organisation and ways to reduce congestion when using multiple components.

- Improved my debugging approach by identifying and solving both software and hardware issues.

## My improvements / experimentations:

- Used arrays combined with loops instead of repeated conditional statements, making it easier to add new notes onto the piano.

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
