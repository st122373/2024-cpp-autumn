// TextEditor.h
#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <iostream>
#include <string>

struct Node
{
    char data;
    Node* next;
    Node(char data, Node* next = nullptr);
    ~Node();
};

class TextEditor
{
public:
    TextEditor();
    ~TextEditor();

    void Insert(char data);
    void Backspace();
    void MoveCursorLeft();
    void MoveCursorRight();
    void PrintText() const;

private:
    Node* head;
    Node* cursor;

    void PushHead(char data);
    void PopHead();
    void dispose();
};

#endif // TEXTEDITOR_H
