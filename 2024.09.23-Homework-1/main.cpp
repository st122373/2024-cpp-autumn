// main.cpp
#include "TextEditor.h"

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
    editor.Insert('o');
    editor.PrintText();  // Вывод: Helilo

    // Удаление символа (Backspace)
    editor.Backspace();
    editor.PrintText();  // Вывод: Helil

    // Перемещение курсора влево и вставка
    editor.MoveCursorLeft();
    editor.MoveCursorLeft();
    editor.Insert('i');
    editor.MoveCursorLeft();
    editor.Insert('i');
    editor.PrintText();  // Вывод: Heilioil
    editor.PrintText();  // Вывод: Heliloil

    return 0;
}
