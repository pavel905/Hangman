#include <iostream>
#include <vector>
#include "hangman.h"

int main() {
    std::vector<std::string> words = {"apple", "banana", "cherry"};
    Hangman hangman(words); // Создаем объект класса Hangman

    try {
        std::string word = hangman.chooseWord(); // Вызываем метод через объект
        std::cout << "Загаданное слово (для отладки): " << word << std::endl;

        std::vector<char> guessedLetters;
        std::string hiddenWord = hangman.displayGuessedWord(word, guessedLetters); // Вызываем метод через объект
        std::cout << "Зашифрованное слово: " << hiddenWord << std::endl;

        // Пример использования getUserInput и isLetterInWord
        char guessedLetter = hangman.getUserInput(guessedLetters); // Вызываем метод через объект

        if (hangman.isLetterInWord(guessedLetter, word)) { // Вызываем метод через объект
            std::cout << "Буква '" << guessedLetter << "' есть в слове." << std::endl;
        } else {
            std::cout << "Буквы '" << guessedLetter << "' нет в слове." << std::endl;
        }

        guessedLetters.push_back(guessedLetter);
        std::string partiallyGuessedWord = hangman.displayGuessedWord(word, guessedLetters); // Вызываем метод через объект
        std::cout << "Слово с угаданными буквами: " << partiallyGuessedWord << std::endl;

    } catch (const std::runtime_error& error) {
        std::cerr << "Ошибка: " << error.what() << std::endl;
        return 1;
    }

    return 0;
}