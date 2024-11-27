#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to hold fruit information
typedef struct {
    char name[50];
    char hints[5][100];
} Fruit;

// Function to load fruit data
Fruit loadFruitData(int fruitIndex) {
    Fruit fruit;

    if (fruitIndex == 0) {
        strcpy(fruit.name, "Apple");
        strcpy(fruit.hints[0], "It's a common fruit.");
        strcpy(fruit.hints[1], "It's often red, but can be green or yellow.");
        strcpy(fruit.hints[2], "It grows on trees.");
        strcpy(fruit.hints[3], "It's often used in pies and juice.");
        strcpy(fruit.hints[4], "Many people eat it as a snack.");
    } else if (fruitIndex == 1) {
        strcpy(fruit.name, "Banana");
        strcpy(fruit.hints[0], "It's a long, curved fruit.");
        strcpy(fruit.hints[1], "It's usually yellow when ripe.");
        strcpy(fruit.hints[2], "It's known for its potassium content.");
        strcpy(fruit.hints[3], "Monkeys love to eat them.");
        strcpy(fruit.hints[4], "It's often eaten as a snack or in smoothies.");
    } else if (fruitIndex == 2) {
        strcpy(fruit.name, "Orange");
        strcpy(fruit.hints[0], "It's round and usually orange.");
        strcpy(fruit.hints[1], "It's a citrus fruit.");
        strcpy(fruit.hints[2], "It's known for its vitamin C content.");
        strcpy(fruit.hints[3], "It's often juiced.");
        strcpy(fruit.hints[4], "It's peeled before eating.");
    } else if (fruitIndex == 3) {
        strcpy(fruit.name, "Grapes");
        strcpy(fruit.hints[0], "They're small and round.");
        strcpy(fruit.hints[1], "They grow in clusters.");
        strcpy(fruit.hints[2], "They can be green, red, or purple.");
        strcpy(fruit.hints[3], "They're often used to make wine.");
        strcpy(fruit.hints[4], "They're a healthy snack.");
    } else if (fruitIndex == 4) {
        strcpy(fruit.name, "Mango");
        strcpy(fruit.hints[0], "It's known as the king of fruits.");
        strcpy(fruit.hints[1], "It's tropical and sweet.");
        strcpy(fruit.hints[2], "It has a large pit inside.");
        strcpy(fruit.hints[3], "It's often yellow or orange when ripe.");
        strcpy(fruit.hints[4], "It's a popular summer fruit.");
    } else if (fruitIndex == 5) {
        strcpy(fruit.name, "Strawberry");
        strcpy(fruit.hints[0], "It's small and heart-shaped.");
        strcpy(fruit.hints[1], "It's red with tiny seeds on the surface.");
        strcpy(fruit.hints[2], "It's sweet and juicy.");
        strcpy(fruit.hints[3], "It's often used in desserts and jams.");
        strcpy(fruit.hints[4], "It's a favorite in summer.");
    } else if (fruitIndex == 6) {
        strcpy(fruit.name, "Pineapple");
        strcpy(fruit.hints[0], "It's a tropical fruit.");
        strcpy(fruit.hints[1], "It has spiky skin.");
        strcpy(fruit.hints[2], "Its flesh is sweet and yellow.");
        strcpy(fruit.hints[3], "It's often used in juices and on pizzas.");
        strcpy(fruit.hints[4], "It has a crown of leaves.");
    } else if (fruitIndex == 7) {
        strcpy(fruit.name, "Watermelon");
        strcpy(fruit.hints[0], "It's large and round.");
        strcpy(fruit.hints[1], "It has green skin and red flesh.");
        strcpy(fruit.hints[2], "It's very juicy and sweet.");
        strcpy(fruit.hints[3], "It's a favorite at picnics.");
        strcpy(fruit.hints[4], "It contains many black seeds.");
    } else if (fruitIndex == 8) {
        strcpy(fruit.name, "Cherry");
        strcpy(fruit.hints[0], "It's small and round.");
        strcpy(fruit.hints[1], "It's bright red or dark red.");
        strcpy(fruit.hints[2], "It's often used as a topping on desserts.");
        strcpy(fruit.hints[3], "It has a single pit inside.");
        strcpy(fruit.hints[4], "It grows on trees in bunches.");
    } else if (fruitIndex == 9) {
        strcpy(fruit.name, "Peach");
        strcpy(fruit.hints[0], "It's fuzzy on the outside.");
        strcpy(fruit.hints[1], "Its flesh is soft and juicy.");
        strcpy(fruit.hints[2], "It's often orange or pinkish in color.");
        strcpy(fruit.hints[3], "It has a hard pit in the center.");
        strcpy(fruit.hints[4], "It's a popular summer fruit.");
    } else {
        strcpy(fruit.name, "Unknown Fruit");
        for (int i = 0; i < 5; i++) strcpy(fruit.hints[i], "No hint available.");
    }
    return fruit;
}

// Function to play the game
void playFruitGame() {
    Fruit fruit;
    char guess[50];
    int attempts, correct, fruitIndex;

    while (1) { // Infinite loop to keep the game running
        // Initialize variables
        attempts = 0;
        correct = 0;
        fruitIndex = rand() % 10; // Randomly select a fruit (adjust based on total fruits)
        fruit = loadFruitData(fruitIndex);

        printf("\nWelcome to the Fruit Guessing Game!\n");
        printf("I'm thinking of a fruit. You have 3 attempts and 5 hints.\n\n");

        // Show hints one by one
        for (int i = 0; i < 5; i++) {
            printf("Hint %d: %s\n", i + 1, fruit.hints[i]);
        }
        printf("\n");

        // Guessing loop
        while (attempts < 3 && !correct) {
            printf("Enter your guess (or type 'quit' to exit): ");
            scanf("%s", guess);

            if (strcasecmp(guess, "quit") == 0) {
                printf("You chose to quit. Thanks for playing!\n");
                return; // Exit the game
            }

            if (strcasecmp(guess, fruit.name) == 0) {
                correct = 1;
            } else {
                attempts++;
                printf("Incorrect guess. Attempts remaining: %d\n\n", 3 - attempts);
            }
        }

        // Game result
        if (correct) {
            printf("Congratulations! You guessed it. The fruit was %s.\n", fruit.name);
        } else {
            printf("You ran out of attempts. The fruit was %s.\n", fruit.name);
        }

        printf("\nStarting a new round...\n");
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    playFruitGame();
    return 0;
}
