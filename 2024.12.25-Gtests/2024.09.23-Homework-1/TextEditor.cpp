#include "TextEditor.h"

Node::Node(char data, Node* next) : data(data), next(next) {}

void TextEditor::addText(const std::string& text) {
    for (char c : text) {
        Node* newNode = new Node(c);
        if (!head) {
            head = newNode;
            cursor = newNode;
        } else {
            newNode->next = cursor->next;
            cursor->next = newNode;
            cursor = newNode; 
        }
    }
}

int TextEditor::deleteText(int k) {
    int count = 0;

    while (k-- > 0 && cursor) {
        if (cursor == head) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cursor = head;
            count++;
        } else {
            Node* prev = head;
            while (prev->next != cursor) {
                prev = prev->next;
            }
            prev->next = cursor->next;
            delete cursor;
            cursor = prev;
            count++;
        }
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

    return getText();
}

std::string TextEditor::cursorRight(int k) {
    while (k-- > 0 && cursor && cursor->next) {
        cursor = cursor->next;
    }

    return getText();
}

std::string TextEditor::getText() const {
    std::string result;
    Node* temp = head;
    while (temp) {
        result += temp->data;
        temp = temp->next;
    }
    return result;
}

void TextEditor::PrintText() const {
    std::cout << getText() << std::endl;
}

void TextEditor::dispose() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
