#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "hangman.h"

int main() {
    // Определяем темы и списки слов
    std::map<std::string, std::vector<std::string>> themes = {
        {"Animals", {"dog", "cat", "elephant", "lion", "tiger"}},
        {"Fruits", {"apple", "banana", "cherry", "orange", "grape"}},
        {"Countries", {"usa", "germany", "france", "japan", "china"}}
    };

    Hangman hangman(themes);

    bool playAgain = true;

    while (playAgain) {
        try {
            // Выбираем тему
            std::string chosenTheme = hangman.chooseTheme();

            // Устанавливаем список слов для выбранной темы
            hangman.wordList = themes[chosenTheme];

            int maxIncorrectAttempts = hangman.chooseDifficulty();
            std::string word = hangman.chooseWord();
            std::cout << "Загаданное слово (для отладки): " << word << std::endl;

            std::vector<char> guessedLetters;
            std::string hiddenWord = hangman.displayGuessedWord(word, guessedLetters);
            std::cout << "Зашифрованное слово: " << hiddenWord << std::endl;

            int incorrectAttempts = 0;

            while (hiddenWord != word && incorrectAttempts < maxIncorrectAttempts) {
                hangman.drawHangman(incorrectAttempts);
                std::cout << "Осталось попыток: " << maxIncorrectAttempts - incorrectAttempts << std::endl;

                char guessedLetter = hangman.getUserInput(guessedLetters);

                if (hangman.isLetterInWord(guessedLetter, word)) {
                    std::cout << "Буква '" << guessedLetter << "' есть в слове." << std::endl;
                } else {
                    std::cout << "Буквы '" << guessedLetter << "' нет в слове." << std::endl;
                    incorrectAttempts++;
                }

                guessedLetters.push_back(guessedLetter);
                hiddenWord = hangman.displayGuessedWord(word, guessedLetters);
                std::cout << "Зашифрованное слово: " << hiddenWord << std::endl;
            }

            hangman.drawHangman(incorrectAttempts);

            if (hiddenWord == word) {
                std::cout << "Поздравляем! Вы угадали слово: " << word << std::endl;
            } else {
                std::cout << "Вы проиграли! Загаданное слово было: " << word << std::endl;
            }

            // Спрашиваем пользователя, хочет ли он сыграть еще раз
            std::string playAgainInput;
            std::cout << "Хотите сыграть еще раз? (y/n): ";
            std::getline(std::cin, playAgainInput);

            if (playAgainInput != "y") {
                playAgain = false;
            }

        } catch (const std::runtime_error& error) {
            std::cerr << "Ошибка: " << error.what() << std::endl;
            playAgain = false;
        }
    }

    std::cout << "Спасибо за игру!" << std::endl;

    return 0;
}