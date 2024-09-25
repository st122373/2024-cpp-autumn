// TextEditor.cpp
#include "TextEditor.h"

// Node methods
Node::Node(char data, Node* next) : data(data), next(next) {}
Node::~Node() { next = nullptr; }

// TextEditor methods
TextEditor::TextEditor() : head(nullptr), cursor(nullptr) {}
TextEditor::~TextEditor() { dispose(); }

void TextEditor::Insert(char data) {
    if (!cursor) {
        PushHead(data);
        cursor = head;
    } else {
        cursor->next = new Node(data, cursor->next);
        cursor = cursor->next;
    }
}

void TextEditor::Backspace() {
    if (!head || !cursor) return;

    if (cursor == head) {
        PopHead();
        cursor = head;
    } else {
        Node* tmp = head;
        while (tmp->next != cursor) {
            tmp = tmp->next;
        }
        tmp->next = cursor->next;
        delete cursor;
        cursor = tmp;
    }
}

void TextEditor::MoveCursorLeft() {
    if (!cursor || cursor == head) return;

    Node* tmp = head;
    while (tmp->next != cursor) {
        tmp = tmp->next;
    }
    cursor = tmp;
}

void TextEditor::MoveCursorRight() {
    if (cursor && cursor->next) {
        cursor = cursor->next;
    }
}

void TextEditor::PrintText() const {
    Node* tmp = head;
    while (tmp) {
        std::cout << tmp->data;
        tmp = tmp->next;
    }
    std::cout << std::endl;
}

// Private methods
void TextEditor::PushHead(char data) {
    head = new Node(data, head);
}

void TextEditor::PopHead() {
    if (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

void TextEditor::dispose() {
    while (head) {
        PopHead();
    }
}
