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
    TextEditor();
    ~TextEditor();

    void addText(const std::string& text); 
    int deleteText(int k); 
    std::string cursorLeft(int k);   
    std::string cursorRight(int k);  
    void PrintText() const; 

private:
    Node* head; 
    Node* cursor;   

    void dispose();
};

#endif // TEXTEDITOR_H