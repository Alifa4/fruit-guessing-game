# Fruit Guessing Game

Welcome to the **Fruit Guessing Game**, a simple terminal-based guessing game written in C. The game randomly selects a fruit and provides hints for you to guess its name. It's fun, educational, and a great way to learn C programming concepts like structures, randomization, and user interaction.

---

## Features

- **Random Fruit Selection**: The game selects a fruit from a list of predefined fruits.
- **Hint System**: Each fruit comes with five descriptive hints to help you guess.
- **Multiple Attempts**: Players get up to three attempts per round.
- **Case-Insensitive Input**: The game accepts guesses without worrying about capitalization.
- **Infinite Gameplay**: The game loops until the player chooses to quit.

---

## How to Play

1. Clone this repository or copy the code into a file named `fruit_guessing_game.c`.
2. Compile the program using:
   ```bash
   gcc fruit_guessing_game.c -o fruit_guessing_game
   ```
3. Run the game:
   ```bash
   ./fruit_guessing_game
   ```
4. Follow the on-screen instructions:
   - Read the hints provided.
   - Enter your guesses.
   - Type `quit` to exit the game at any time.

---

## Example Gameplay

```plaintext
Welcome to the Fruit Guessing Game!
I'm thinking of a fruit. You have 3 attempts and 5 hints.

Hint 1: It's small and round.
Hint 2: It's bright red or dark red.
Hint 3: It's often used as a topping on desserts.
Hint 4: It has a single pit inside.
Hint 5: It grows on trees in bunches.

Enter your guess (or type 'quit' to exit): Cherry
Congratulations! You guessed it. The fruit was Cherry.

Starting a new round...
```

---

## Adding New Fruits

To add more fruits:

1. Increase the range of the `rand() % N` expression in the `playFruitGame()` function, where `N` is the total number of fruits.
2. Add the fruit's data in the `loadFruitData()` function. For example:
   ```c
   else if (fruitIndex == 10) {
       strcpy(fruit.name, "Kiwi");
       strcpy(fruit.hints[0], "It's small and brown.");
       strcpy(fruit.hints[1], "Its flesh is green and has black seeds.");
       strcpy(fruit.hints[2], "It's sweet and tangy.");
       strcpy(fruit.hints[3], "It is often eaten with a spoon.");
       strcpy(fruit.hints[4], "It is a popular tropical fruit.");
   }
   ```

---

## Requirements

- A C compiler (e.g., GCC)
- A terminal or command-line interface

---

## Future Enhancements

- **Hint-by-Hint Display**: Reveal hints one at a time instead of all at once.
- **Scoring System**: Keep track of correct guesses and show a score at the end.
- **Custom Fruits**: Allow players to input their own fruits and hints.
- **File-Based Data**: Load fruit data from a file for easier management.

---

## License

This project is licensed under the MIT License. Feel free to use, modify, and distribute it as you like.

---

## Contributing

If you'd like to contribute:

1. Fork this repository.
2. Make your changes.
3. Submit a pull request.

---

Enjoy the game! 🎉
