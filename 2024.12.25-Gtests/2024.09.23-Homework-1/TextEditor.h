#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <iostream>
#include <string>

struct Node {
    char data;
    Node* next;
    Node(char data, Node* next = nullptr);
};

class TextEditor {
public:
    TextEditor() : head(nullptr), cursor(nullptr) {}
    ~TextEditor() { dispose(); }

    void addText(const std::string& text);
    int deleteText(int k);
    std::string cursorLeft(int k);
    std::string cursorRight(int k);
    void PrintText() const;

private:
    Node* head;
    Node* cursor;

    void dispose();
    std::string getText() const; // Вспомогательный метод для получения текста
};

#endif // TEXTEDITOR_H
