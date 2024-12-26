#include <gtest/gtest.h>
#include "TextEditor.h"

TEST(TextEditorTest, AddText) {
    TextEditor editor;
    editor.addText("Hello");
    editor.addText(" World");
    
    std::string result = editor.cursorLeft(11); // Перемещение курсора влево на 11 символов
    EXPECT_EQ(result, "Hello World");
}

TEST(TextEditorTest, DeleteText) {
    TextEditor editor;
    editor.addText("Hello World");
    
    int deletedCount = editor.deleteText(5); // Удаляем 5 символов
    EXPECT_EQ(deletedCount, 5);
    
    std::string result = editor.cursorLeft(6); // Перемещение курсора влево на 6 символов
    EXPECT_EQ(result, "Hello ");
}

TEST(TextEditorTest, CursorLeft) {
    TextEditor editor;
    editor.addText("Hello World");
    
    std::string result = editor.cursorLeft(5); // Перемещение курсора влево на 5 символов
    EXPECT_EQ(result, "Hello World");
}

TEST(TextEditorTest, CursorRight) {
    TextEditor editor;
    editor.addText("Hello");
    editor.cursorLeft(5); // Перемещаем курсор влево на 5 символов
    std::string result = editor.cursorRight(2); // Перемещаем курсор вправо на 2 символа
    EXPECT_EQ(result, "Hello");
}

TEST(TextEditorTest, DeleteTextAtStart) {
    TextEditor editor;
    editor.addText("Hello");
    editor.deleteText(1); // Удаляем 1 символ
    std::string result = editor.cursorLeft(4); // Перемещение курсора влево на 4 символа
    EXPECT_EQ(result, "Hell");
}

TEST(TextEditorTest, PrintText) {
    TextEditor editor;
    editor.addText("Hello");
    editor.addText(" World");
    
    testing::internal::CaptureStdout(); // Захват стандартного вывода
    editor.PrintText();
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_EQ(output, "Hello World\n");
}


TEST(TextEditorTest, AddEmptyText) {
    TextEditor editor;
    editor.addText(""); // Добавляем пустой текст
    
    std::string result = editor.cursorLeft(1); // Перемещение курсора
    EXPECT_EQ(result, ""); // Ожидаем пустую строку
}

TEST(TextEditorTest, CursorMovementOutOfBounds) {
    TextEditor editor;
    editor.addText("Hello");
    
    editor.cursorLeft(10); // Перемещение курсора влево за пределы
    std::string result = editor.cursorLeft(0); // Проверка текущего положения курсора
    EXPECT_EQ(result, "Hello"); // Ожидаем, что курсор не изменится
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); // Инициализация Google Test
    return RUN_ALL_TESTS(); // Запуск всех тестов
}