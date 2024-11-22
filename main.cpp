#include <iostream>
#include <memory>
#include "Circle.h"
#include "Controller.h"

void ShowMenu() {
    std::cout << "Выберите действие:\n";
    std::cout << "1. Создать новый документ\n";
    std::cout << "2. Импортировать документ из файла\n";
    std::cout << "3. Экспортировать документ в файл\n";
    std::cout << "4. Добавить фигуру (круг/прямоугольник)\n";
    std::cout << "5. Удалить фигуру\n";
    std::cout << "0. Выход\n";
}

int main() {
    Controller controller;
    int choice;

    do {
        ShowMenu();
        std::cout << "Введите номер действия: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                controller.HandleCreateDocument();
                break;
            case 2: {
                std::string filename;
                std::cout << "Введите имя файла для импорта: ";
                std::cin >> filename;
                controller.HandleImportDocument(filename);
                break;
            }
            case 3: {
                std::string filename;
                std::cout << "Введите имя файла для экспорта: ";
                std::cin >> filename;
                controller.HandleExportDocument(filename);
                break;
            }
            case 4: {
                std::string shapeType, color;
                std::cout << "Введите тип фигуры (circle/rectangle): ";
                std::cin >> shapeType;
                std::cout << "Введите цвет фигуры: ";
                std::cin >> color;
                controller.HandleAddShape(shapeType, color);
                break;
            }
            case 5: { // Удаление фигуры
                if (controller.GetShapeCount() > 0) { // Проверяем, есть ли фигуры
                    auto shape = controller.GetLastShape(); // Получаем последнюю фигуру
                    controller.HandleRemoveShape(shape); // Удаляем её
                } else {
                    std::cout << "No shapes to remove." << std::endl;
                }
                break;
            }
            case 0:
                std::cout << "Выход из программы." << std::endl;
                break;
            default:
                std::cout << "Неверный выбор. Пожалуйста, попробуйте снова." << std::endl;
        }

    } while (choice != 0);

    return 0;
}
