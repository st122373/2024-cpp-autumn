#include "TextEditor.h"

int main() {
    TextEditor editor;

    editor.addText("Hello, world!");
    editor.PrintText();  
    std::cout << editor.cursorLeft(5) << std::endl;  
    editor.addText("of bebra");
    editor.PrintText(); 

    editor.deleteText(4);
    editor.PrintText();  

    std::cout << editor.cursorRight(5) << std::endl;  

    return 0;
}