#include <iostream>
#include <vector>
#include "hangman.h"

int main() {
    std::vector<std::string> words = {"apple", "banana", "cherry"};
    Hangman hangman(words); // Создаем объект класса Hangman

    try {
        std::string word = hangman.chooseWord();
        std::cout << "Загаданное слово (для отладки): " << word << std::endl;

        std::vector<char> guessedLetters;
        std::string hiddenWord = hangman.displayGuessedWord(word, guessedLetters);
        std::cout << "Зашифрованное слово: " << hiddenWord << std::endl;

        // Цикл игры: повторяем, пока слово не угадано или не исчерпаны попытки (пока что без лимита попыток)
        while (hiddenWord != word) { // Пока слово не угадано
            char guessedLetter = hangman.getUserInput(guessedLetters);

            if (hangman.isLetterInWord(guessedLetter, word)) {
                std::cout << "Буква '" << guessedLetter << "' есть в слове." << std::endl;
            } else {
                std::cout << "Буквы '" << guessedLetter << "' нет в слове." << std::endl;
            }

            guessedLetters.push_back(guessedLetter);
            hiddenWord = hangman.displayGuessedWord(word, guessedLetters); // Обновляем зашифрованное слово
            std::cout << "Зашифрованное слово: " << hiddenWord << std::endl;
        }

        std::cout << "Поздравляем! Вы угадали слово: " << word << std::endl;

    } catch (const std::runtime_error& error) {
        std::cerr << "Ошибка: " << error.what() << std::endl;
        return 1;
    }

    return 0;
}