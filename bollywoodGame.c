#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void clrscr() {
    printf("\e[1;1H\e[2J"); // ANSI escape code to clear screen
}

int selectMovie(char *word) {
    FILE *movies = fopen("movies.txt", "r");
    if (movies == NULL) {
        perror("Error opening file");
        return -1;
    }
    int lines = 0;
    char c = fgetc(movies);
    while (c != EOF) {
        if (c == '\n') {
            lines++;
        }
        c = fgetc(movies);
    }
    lines++;
    rewind(movies);
    int movie = rand() % lines;
    int count = 0;
    c = fgetc(movies);
    while (c != EOF) {
        if (count == movie) {
            int len = 0;
            while (c != '\n' && c != EOF) {
                word[len] = c;
                c = fgetc(movies);
                len++;
            }
            word[len] = '\0';
        }
        if (c == '\n') {
            count++;
        }
        if (count > movie) {
            break;
        }
        c = fgetc(movies);
    }
    fclose(movies);
    return 0;
}

int checkOver(char *current) {
    for (int i = 0; i < strlen(current); i++) {
        if (current[i] == '_') {
            return 0;
        }
    }
    return 1;
}

void initGame(char *word, char *current) {
    char bollywood[17] = "B O L L Y W O O D";
    char *guesses;
    guesses = calloc(0, sizeof(char));
    int arrLen = 0;
    for (int i = 0; i < strlen(word); i++) {
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' || word[i] == '!' || word[i] == '-' || word[i] == ':') {
            current[i] = word[i];
        } else {
            if (word[i] != ' ') {
                current[i] = '_';
            } else {
                current[i] = ' ';
            }
        }
    }
    printf("\nHello! Welcome to the Bollywood game. You have to guess the movie name letter by letter before you run out of turns.\n\nDon't try vowels as they are already given.\n");
    printf("\n\n\nPress enter to start. ");
    getchar();
    clrscr();
    while (1) {
        int gameOver = checkOver(current);
        if (gameOver) {
            clrscr();
            printf("\nHurray! You gueesed the whole name '%s' and won the game.\n\n", current);
            free(guesses);
            break;
        }
        printf("\n\nChances Left: %s", bollywood);
        printf("\n\nMovie to guess: ");
        for (int l = 0; l < strlen(current); l++) {
            printf("%c ", current[l]);
        }
        printf("\n\nGuess a letter: ");
        char guess;
        scanf(" %c", &guess);
        getchar();
        if (!((guess >= 'a' && guess <= 'z') || (guess >= '0' && guess <= '9'))) {
            clrscr();
            printf("\n'%c' - You can only use lowercase english letters and numeric digits.", guess);
            continue;
        }
        int alreadyGuessed;
        for (int a = 0; a < arrLen; a++) {
            if (guess == guesses[a]) {
                alreadyGuessed = 1;
                break;
            }
        }
        if (alreadyGuessed == 1) {
            clrscr();
            printf("\n'%c' - You have already tried that guess.", guess);
            alreadyGuessed = 0;
            continue;
        } else {
            guesses = realloc(guesses, sizeof(char) * (arrLen + 1));
            guesses[arrLen] = guess;
            arrLen++;
        }
        int right = 0;
        for (int j = 0; j < strlen(word); j++) {
            if (word[j] == guess) {
                current[j] = guess;
                right = 1;
            }
        }
        if (right == 1) {
            if (guess == 'a' || guess == 'e' || guess  == 'i' || guess == 'o' || guess == 'u') {
                clrscr();
                printf("\n'%c' - Correct vowels are already given to you.", guess);
            } else {
                clrscr();
                printf("\n'%c' - That was a right guess.", guess);
            }
        }
        int cut = 0;
        if (right != 1) {
            clrscr();
            printf("\n'%c' - Opps! That's not a right guess.", guess);
            for (int k = 0; k < 17; k++) {
                if (bollywood[k] != '-' && bollywood[k] != ' ') {
                    bollywood[k] = '-';
                    cut = 1;
                    break;
                }
            }
        }
        int quit = 1;
        for (int k = 0; k < 17; k++) {
            if (bollywood[k] != '-' && bollywood[k] != ' ') {
                quit = 0;
                break;
            }
        }
        if (quit == 1) {
            clrscr();
            printf("\n\n%s", bollywood);
            printf("\nGame Over! You ran out of chances. The correct name was '%s'\n\n", word);
            free(guesses);
            break;
        }
    }
    return;
}

int main() {
    srand(time(NULL));
    char word[50] = {'\0'}, current[50] = {'\0'};
    int err = selectMovie(word);
    if (err == 0) {
        initGame(word, current);
    }
    return 0;
}