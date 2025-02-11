#include <iostream>
#include <vector>
#include "hangman.h"

int main() {
    std::vector<std::string> words = {"apple", "banana", "cherry"};
    Hangman hangman(words);

    try {
        std::string word = hangman.chooseWord();
        std::cout << "Загаданное слово (для отладки): " << word << std::endl;

        std::vector<char> guessedLetters;
        std::string hiddenWord = hangman.displayGuessedWord(word, guessedLetters);
        std::cout << "Зашифрованное слово: " << hiddenWord << std::endl;

        int incorrectAttempts = 0; // Счетчик неправильных попыток
        int maxIncorrectAttempts = 6; // Максимальное количество неправильных попыток

        // Цикл игры: повторяем, пока слово не угадано или не исчерпаны попытки
        while (hiddenWord != word && incorrectAttempts < maxIncorrectAttempts) {
            hangman.drawHangman(incorrectAttempts); // Отрисовываем виселицу
            std::cout << "Осталось попыток: " << maxIncorrectAttempts - incorrectAttempts << std::endl; // Показываем количество оставшихся попыток

            char guessedLetter = hangman.getUserInput(guessedLetters);

            if (hangman.isLetterInWord(guessedLetter, word)) {
                std::cout << "Буква '" << guessedLetter << "' есть в слове." << std::endl;
            } else {
                std::cout << "Буквы '" << guessedLetter << "' нет в слове." << std::endl;
                incorrectAttempts++; // Увеличиваем счетчик неправильных попыток
            }

            guessedLetters.push_back(guessedLetter);
            hiddenWord = hangman.displayGuessedWord(word, guessedLetters); // Обновляем зашифрованное слово
            std::cout << "Зашифрованное слово: " << hiddenWord << std::endl;
        }

        hangman.drawHangman(incorrectAttempts); // Отрисовываем финальную виселицу

        if (hiddenWord == word) {
            std::cout << "Поздравляем! Вы угадали слово: " << word << std::endl;
        } else {
            std::cout << "Вы проиграли! Загаданное слово было: " << word << std::endl;
        }

    } catch (const std::runtime_error& error) {
        std::cerr << "Ошибка: " << error.what() << std::endl;
        return 1;
    }

    return 0;
}