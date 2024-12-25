#include "TextEditor.h"

Node::Node(char data, Node* next) : data(data), next(next) {}

TextEditor::TextEditor() : head(nullptr), cursor(nullptr) {}
TextEditor::~TextEditor() {dispose();}

void TextEditor::addText(const std::string& text) {
    for (char c : text) {
        Node* newNode = new Node(c);

        if (!cursor) 
        {
            newNode->next = head;
            head = newNode;
            cursor = newNode;
        } 
        else 
        { 
            newNode->next = cursor->next;
            cursor->next = newNode;
            cursor = newNode;
        }
    }
}


int TextEditor::deleteText(int k) 
{
    int count = 0;

    while (k-- > 0 && cursor && cursor != head) {
        Node* prev = head;
        while (prev->next != cursor)
        {
            prev = prev->next;
        }

        prev->next = cursor->next;
        delete cursor;
        cursor = prev;
        ++count;
    }

    if (cursor == head && k >= 0) 
    {
        delete head;
        head = nullptr;
        cursor = nullptr;
        ++count;
    }

    return count;
}

std::string TextEditor::cursorLeft(int k) {
    while (k-- > 0 && cursor && cursor != head) {
        Node* prev = head;
        while (prev->next != cursor) {
            prev = prev->next;
        }
        cursor = prev;
    }

    std::string result;
    Node* temp = head;
    while (temp != cursor->next) {
        result += temp->data;
        temp = temp->next;
    }

    return result.size() > 10 ? result.substr(result.size() - 10) : result;
}

std::string TextEditor::cursorRight(int k) {
    while (k-- > 0 && cursor && cursor->next) {
        cursor = cursor->next;
    }

    std::string result;
    Node* temp = head;
    while (temp != cursor->next) {
        result += temp->data;
        temp = temp->next;
    }

    return result.size() > 10 ? result.substr(result.size() - 10) : result;
}

void TextEditor::PrintText() const {
    Node* temp = head;
    while (temp) {
        std::cout << temp->data;
        temp = temp->next;
    }
    std::cout << std::endl;
}

void TextEditor::dispose() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
