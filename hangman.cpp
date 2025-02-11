#include "hangman.h"
#include <random>
#include <stdexcept>
#include <iostream> // Для отладочного вывода

Hangman::Hangman(const std::vector<std::string>& wordList) : wordList(wordList) {}

std::string Hangman::chooseWord() {
    if (wordList.empty()) {
        throw std::runtime_error("Word list is empty. Cannot choose a word.");
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, wordList.size() - 1);

    std::string chosenWord = wordList[distrib(gen)];
    std::cout << "Выбрано слово: " << chosenWord << std::endl; // Отладочный вывод
    return chosenWord;
}

std::string Hangman::getHiddenWord(const std::string& word) {
    return std::string(word.length(), '_'); // Все символы - подчеркивания
}

std::string Hangman::displayGuessedWord(const std::string& word, const std::vector<char>& guessedLetters) {
    std::string displayedWord = "";
    for (char letter : word) {
        bool guessed = false;
        for (char guessedLetter : guessedLetters) {
            if (tolower(letter) == tolower(guessedLetter)) { //Сравнение без учета регистра
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