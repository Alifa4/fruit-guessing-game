#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to hold fruit information
typedef struct {
    char name[50];
    char hints[5][100];
} Fruit;

// Function to load fruit data (you'll need to populate this)
Fruit loadFruitData(int fruitIndex) {
    Fruit fruit;
    // Example data - REPLACE THIS WITH YOUR OWN FRUIT DATA
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
    }
    // Add more fruits here...
    else {
        strcpy(fruit.name, "Unknown Fruit"); // Default if index is out of range
        for (int i = 0; i < 5; i++) strcpy(fruit.hints[i], "No hint available.");
    }
    return fruit;
}


// Function to play the game
void playFruitGame() {
    Fruit fruit;
    char guess[50];
    int attempts = 0, correct = 0;
    int fruitIndex = rand() % 3; //  Randomly select a fruit (adjust range as needed)

    fruit = loadFruitData(fruitIndex);

    printf("Welcome to the Fruit Guessing Game!\n");
    printf("I'm thinking of a fruit. You have 3 attempts and 5 hints.\n\n");

    // Show hints one by one
    for (int i = 0; i < 5; i++) {
        printf("Hint %d: %s\n", i + 1, fruit.hints[i]);
    }
    printf("\n");


    while (attempts < 3 && !correct) {
        printf("Enter your guess: ");
        scanf("%s", guess);

        if (strcasecmp(guess, fruit.name) == 0) {
            correct = 1;
        } else {
            attempts++;
            printf("Incorrect guess. Attempts remaining: %d\n\n", 3 - attempts);
        }
    }

    if (correct) {
        printf("Congratulations! You guessed it. The fruit was %s.\n", fruit.name);
    } else {
        printf("You ran out of attempts. The fruit was %s.\n", fruit.name);
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    playFruitGame();
    return 0;
}
