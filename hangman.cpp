#include "hangman.h"
#include <random>
#include <stdexcept>
#include <iostream>
#include <cctype>
#include <string>
#include <algorithm> // для std::find

Hangman::Hangman(const std::map<std::string, std::vector<std::string>>& themes) : themes(themes) {
}

std::string Hangman::chooseWord() {
    if (wordList.empty()) {
        throw std::runtime_error("Word list is empty. Cannot choose a word.");
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, wordList.size() - 1);

    std::string chosenWord = wordList[distrib(gen)];
    std::cout << "Выбрано слово: " << chosenWord << std::endl;
    return chosenWord;
}

std::string Hangman::getHiddenWord(const std::string& word) {
    return std::string(word.length(), '_');
}

std::string Hangman::displayGuessedWord(const std::string& word, const std::vector<char>& guessedLetters) {
    std::string displayedWord = "";
    for (char letter : word) {
        bool guessed = false;
        for (char guessedLetter : guessedLetters) {
            if (tolower(letter) == tolower(guessedLetter)) {
                guessed = true;
                break;
            }
        }
        if (guessed) {
            displayedWord += letter;
        } else {
            displayedWord += '_';
        }
    }
    return displayedWord;
}

char Hangman::getUserInput(const std::vector<char>& guessedLetters) {
    std::string input;
    while (true) {
        std::cout << "Введите букву: ";
        std::getline(std::cin, input);

        if (input.length() != 1) {
            std::cout << "Пожалуйста, введите только одну букву." << std::endl;
        } else if (!isalpha(input[0])) {
            std::cout << "Пожалуйста, введите букву (a-z)." << std::endl;
        } else {
            char letter = tolower(input[0]);

            // Проверяем, была ли эта буква уже введена
            bool alreadyGuessed = false;
            for (char guessedLetter : guessedLetters) {
                if (guessedLetter == letter) {
                    alreadyGuessed = true;
                    break;
                }
            }

            if (alreadyGuessed) {
                std::cout << "Вы уже вводили эту букву." << std::endl;
            } else {
                return letter; // Возвращаем букву в нижнем регистре
            }
        }
    }
}

bool Hangman::isLetterInWord(char letter, const std::string& word) {
    for (char c : word) {
        if (tolower(c) == tolower(letter)) {
            return true; // Буква найдена в слове
        }
    }
    return false; // Буква не найдена в слове
}

void Hangman::drawHangman(int incorrectAttempts) {
    switch (incorrectAttempts) {
        case 0:
            std::cout << "  +---+" << std::endl;
            std::cout << "  |   |" << std::endl;
            std::cout << "      |" << std::endl;
            std::cout << "      |" << std::endl;
            std::cout << "      |" << std::endl;
            std::cout << "      |" << std::endl;
            std::cout << "=========" << std::endl;
            break;
        case 1:
            std::cout << "  +---+" << std::endl;
            std::cout << "  |   |" << std::endl;
            std::cout << "  O   |" << std::endl;
            std::cout << "      |" << std::endl;
            std::cout << "      |" << std::endl;
            std::cout << "      |" << std::endl;
            std::cout << "=========" << std::endl;
            break;
        case 2:
            std::cout << "  +---+" << std::endl;
            std::cout << "  |   |" << std::endl;
            std::cout << "  O   |" << std::endl;
            std::cout << "  |   |" << std::endl;
            std::cout << "      |" << std::endl;
            std::cout << "      |" << std::endl;
            std::cout << "=========" << std::endl;
            break;
        case 3:
            std::cout << "  +---+" << std::endl;
            std::cout << "  |   |" << std::endl;
            std::cout << "  O   |" << std::endl;
            std::cout << " /|   |" << std::endl;
            std::cout << "      |" << std::endl;
            std::cout << "      |" << std::endl;
            std::cout << "=========" << std::endl;
            break;
        case 4:
            std::cout << "  +---+" << std::endl;
            std::cout << "  |   |" << std::endl;
            std::cout << "  O   |" << std::endl;
            std::cout << " /|\\  |" << std::endl;
            std::cout << "      |" << std::endl;
            std::cout << "      |" << std::endl;
            std::cout << "=========" << std::endl;
            break;
        case 5:
            std::cout << "  +---+" << std::endl;
            std::cout << "  |   |" << std::endl;
            std::cout << "  O   |" << std::endl;
            std::cout << " /|\\  |" << std::endl;
            std::cout << " /    |" << std::endl;
            std::cout << "      |" << std::endl;
            std::cout << "=========" << std::endl;
            break;
        case 6:
            std::cout << "  +---+" << std::endl;
            std::cout << "  |   |" << std::endl;
            std::cout << "  O   |" << std::endl;
            std::cout << " /|\\  |" << std::endl;
            std::cout << " / \\  |" << std::endl;
            std::cout << "      |" << std::endl;
            std::cout << "=========" << std::endl;
            break;
        default:
            std::cout << "  +---+" << std::endl;
            std::cout << "  |   |" << std::endl;
            std::cout << "  X   |" << std::endl;
            std::cout << " /|\\  |" << std::endl;
            std::cout << " / \\  |" << std::endl;
            std::cout << "      |" << std::endl;
            std::cout << "=========" << std::endl;
            break;
    }
}

int Hangman::chooseDifficulty() {
    while (true) {
        std::cout << "Выберите сложность:" << std::endl;
        std::cout << "1 - Легкая (10 попыток)" << std::endl;
        std::cout << "2 - Средняя (6 попыток)" << std::endl;
        std::cout << "3 - Тяжелая (4 попытки)" << std::endl;
        std::cout << "Введите номер сложности: ";

        std::string input;
        std::getline(std::cin, input);

        try {
            int choice = std::stoi(input); // Преобразуем строку в число
            if (choice >= 1 && choice <= 3) {
                switch (choice) {
                    case 1: return 10; // Легкая
                    case 2: return 6;  // Средняя
                    case 3: return 4;  // Тяжелая
                }
            } else {
                std::cout << "Некорректный ввод. Пожалуйста, введите число от 1 до 3." << std::endl;
            }
        } catch (const std::invalid_argument& e) {
            std::cout << "Некорректный ввод. Пожалуйста, введите число." << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << "Слишком большое число. Пожалуйста, введите число от 1 до 3." << std::endl;
        }
    }
}

std::string Hangman::chooseTheme() {
    std::vector<std::string> themeNames;
    int i = 1;
    std::cout << "Выберите тему:" << std::endl;
    for (const auto& pair : themes) {
        std::cout << i++ << " - " << pair.first << std::endl;
        themeNames.push_back(pair.first);
    }
    std::cout << "Введите номер темы: ";

    std::string input;
    std::getline(std::cin, input);

    try {
        int choice = std::stoi(input);
        if (choice >= 1 && choice <= static_cast<int>(themes.size())) { // Преобразуем themes.size() к int
            return themeNames[choice - 1];
        } else {
            std::cout << "Некорректный ввод. Пожалуйста, введите число от 1 до " << themes.size() << "." << std::endl;
            return chooseTheme(); // Рекурсивный вызов, чтобы повторить выбор
        }
    } catch (const std::invalid_argument& e) {
        std::cout << "Некорректный ввод. Пожалуйста, введите число." << std::endl;
        return chooseTheme(); // Рекурсивный вызов
    } catch (const std::out_of_range& e) {
        std::cout << "Слишком большое число. Пожалуйста, введите число от 1 до " << themes.size() << "." << std::endl;
        return chooseTheme(); // Рекурсивный вызов
    }
}