#include<iostream>
#include<string>

struct Node
{
    char data;
    Node* next;
    Node(char data, Node* next = nullptr) : data(data), next(next) {}
    ~Node() { next = nullptr; }
};

class TextEditor
{
public:
    TextEditor() : head(nullptr), cursor(nullptr) {}
    ~TextEditor() { dispose(); }

    // Вставка символа в позицию курсора
    void Insert(char data) {
        if (!cursor) {
            PushHead(data);  // если курсор не установлен, добавляем в начало
            cursor = head;   // курсор указывает на новый элемент
        } else {
            cursor->next = new Node(data, cursor->next);  // вставляем новый элемент после курсора
            cursor = cursor->next;  // курсор перемещается на новый элемент
        }
    }

    // Удаление символа перед курсором (аналог Backspace)
    void Backspace() {
        if (!head || !cursor) return;

        if (cursor == head) {
            PopHead();
            cursor = head;
        } else {
            Node* tmp = head;
            while (tmp->next != cursor) {
                tmp = tmp->next;
            }
            tmp->next = cursor->next;  // удаляем текущий элемент
            delete cursor;
            cursor = tmp;  // курсор смещается назад
        }
    }

    // Перемещение курсора влево
    void MoveCursorLeft() {
        if (!cursor || cursor == head) return;

        Node* tmp = head;
        while (tmp->next != cursor) {
            tmp = tmp->next;
        }
        cursor = tmp;  // перемещаем курсор на элемент влево
    }

    // Перемещение курсора вправо
    void MoveCursorRight() {
        if (cursor && cursor->next) {
            cursor = cursor->next;  // перемещаем курсор вправо
        }
    }

    // Вывод текущего текста
    void PrintText() const {
        Node* tmp = head;
        while (tmp) {
            std::cout << tmp->data;
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }

private:
    Node* head;
    Node* cursor;  // указатель на текущую позицию курсора

    void PushHead(char data) {
        head = new Node(data, head);
    }

    void PopHead() {
        if (head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    void dispose() {
        while (head) {
            PopHead();
        }
    }
};

int main() {
    TextEditor editor;

    // Вставка текста
    editor.Insert('H');
    editor.Insert('e');
    editor.Insert('l');
    editor.Insert('l');
    editor.MoveCursorLeft();
    editor.MoveCursorLeft();
    editor.Insert('i');
    editor.MoveCursorLeft();
    editor.Insert('i');
    editor.PrintText();  // Вывод: Heilo
    editor.PrintText();  // Вывод: Heilo
    editor.Insert('i');
    editor.MoveCursorLeft();
    editor.Insert('i');
    editor.PrintText();  // Вывод: Heilo
    editor.PrintText();  // Вывод: Heilo
    editor.Insert('o');

    editor.PrintText();  // Вывод: Hello

    // Удаление символа (Backspace)
    editor.Backspace();
    editor.PrintText();  // Вывод: Hell

    // Перемещение курсора влево и вставка
    editor.MoveCursorLeft();
    editor.MoveCursorLeft();
    editor.Insert('i');
    editor.MoveCursorLeft();
    editor.Insert('i');
    editor.PrintText();  // Вывод: Heilo
    editor.PrintText();  // Вывод: Heilo

    return 0;
}
