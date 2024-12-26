#include "TextEditor.h"

Node::Node(char data, Node* next) : data(data), next(next) {}

void TextEditor::addText(const std::string& text) {
    for (char c : text) {
        Node* newNode = new Node(c);
        if (!head) {
            head = newNode;
            cursor = newNode; // Устанавливаем курсор на первый добавленный символ
        } else {
            newNode->next = cursor->next;
            cursor->next = newNode;
            cursor = newNode; // Перемещаем курсор на новый символ
        }
    }
}

int TextEditor::deleteText(int k) {
    int count = 0;

    while (k-- > 0 && cursor) {
        if (cursor == head) {
            // Удаляем первый элемент
            Node* temp = head;
            head = head->next;
            delete temp;
            cursor = head; // Перемещаем курсор на новый первый элемент
            count++;
        } else {
            // Удаляем элемент, на который указывает курсор
            Node* prev = head;
            while (prev->next != cursor) {
                prev = prev->next;
            }
            prev->next = cursor->next;
            delete cursor;
            cursor = prev; // Перемещаем курсор на предыдущий элемент
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
        cursor = prev; // Перемещаем курсор влево
    }

    // Возвращаем текст от начала до курсора
    return getText();
}

std::string TextEditor::cursorRight(int k) {
    while (k-- > 0 && cursor && cursor->next) {
        cursor = cursor->next; // Перемещаем курсор вправо
    }

    // Возвращаем текст от начала до курсора
    return getText();
}

std::string TextEditor::getText() const {
    std::string result;
    Node* temp = head;
    while (temp) {
        result += temp->data;
        temp = temp->next;
    }
    return result; // Возвращаем текст
}

void TextEditor::PrintText() const {
    std::cout << getText() << std::endl; // Печатаем весь текст
}

void TextEditor::dispose() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}