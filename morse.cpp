#include "pico/stdlib.h"
#include <stdio.h>
#include <string>
#include <algorithm>

#ifndef PICO_DEFAULT_LED_PIN
#warning blink example requires a board with a regular LED
#else

const uint LED_PIN = PICO_DEFAULT_LED_PIN;

std::string strToMorse(std::string word) {
    std::string morse;
    std::transform(word.begin(), word.end(), word.begin(), ::toupper);
    for (char letter : word) {
        switch (letter) {
            case 'A':
                morse += ".-";
                break;
            case 'B':
                morse += "-...";
                break;
            case 'C':
                morse += "-.-.";
                break;
            case 'D':
                morse += "-..";
                break;
            case 'E':
                morse += ".";
                break;
            case 'F':
                morse += "..-.";
                break;
            case 'G':
                morse += "--.";
                break;
            case 'H':
                morse += "....";
                break;
            case 'I':
                morse += "..";
                break;
            case 'J':
                morse += ".---";
                break;
            case 'K':
                morse += "-.-";
                break;
            case 'L':
                morse += ".-..";
                break;
            case 'M':
                morse += "--";
                break;
            case 'N':
                morse += "-.";
                break;
            case 'O':
                morse += "---";
                break;
            case 'P':
                morse += ".--.";
                break;
            case 'Q':
                morse += "--.-";
                break;
            case 'R':
                morse += ".-.";
                break;
            case 'S':
                morse += "...";
                break;
            case 'T':
                morse += "-";
                break;
            case 'U':
                morse += "..-";
                break;
            case 'V':
                morse += "...-";
                break;
            case 'W':
                morse += ".--";
                break;
            case 'X':
                morse += "-..-";
                break;
            case 'Y':
                morse += "-.--";
                break;
            case 'Z':
                morse += "--..";
                break;
            case '0':
                morse += "-----";
                break;
            case '1':
                morse += ".----";
                break;
            case '2':
                morse += "..---";
                break;
            case '3':
                morse += "...--";
                break;
            case '4':
                morse += "....-";
                break;
            case '5':
                morse += ".....";
                break;
            case '6':
                morse += "-....";
                break;
            case '7':
                morse += "--...";
                break;
            case '8':
                morse += "---..";
                break;
            case '9':
                morse += "----.";
                break;
            default:
                morse += "=";
                continue;
        }
        morse += "/";
    }
    if (!morse.empty()) {
        morse.pop_back();
    }
    return morse;
}

void shortBlink() {
    printf(".");
    gpio_put(LED_PIN, 1);
    sleep_ms(100);
    gpio_put(LED_PIN, 0);
    sleep_ms(100);
}

void longBlink() {
    printf("-");
    gpio_put(LED_PIN, 1);
    sleep_ms(300);
    gpio_put(LED_PIN, 0);
    sleep_ms(100);
}

void interLetter() {
    sleep_ms(300);
}

void spaceWords() {
    printf(" ");
    sleep_ms(500);
}

int main() {
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (!stdio_usb_connected()) {
        sleep_ms(100);
    }
    std::string word;
    char userInput;
    printf("Enter a word or a sentence (end with '!'): \n");
    while (userInput != '!') {
        userInput = getchar();
        if (userInput != '!') {
            word += userInput;
            printf("%c", userInput);
        }
    }
    printf("\nProcessing...\n");
    std::string morse = strToMorse(word);
        while (true) {
            for (char code : morse) {
                switch (code) {
                    case '.':
                    shortBlink();
                    break;
                    case '-':
                    longBlink();
                    break;
                    case '/':
                    interLetter();
                    break;
                    case '=':
                    spaceWords();
                    break;
                }
            }
            printf("\n");
        }
        return 0;
}
#endif
