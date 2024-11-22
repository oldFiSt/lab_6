#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "IDocument.h"
#include <vector>
#include <memory>
#include <fstream>
#include <iostream>
#include <algorithm>

class Document : public IDocument {
private:
    std::vector<std::shared_ptr<IShape>> shapes;

public:
    void CreateDocument() override {
        shapes.clear();
        std::cout << "New document created." << std::endl;
    }

    void ImportDocument(const std::string& filename) override {
        // Пример импорта (реализация может быть расширена)
        std::ifstream file(filename);
        if (file.is_open()) {
            // Логика импорта из файла (упрощенная)
            std::cout << "Document imported from " << filename << "." << std::endl;
            file.close();
        } else {
            std::cerr << "Failed to open file: " << filename << std::endl;
        }
    }

    void ExportDocument(const std::string& filename) override {
        // Пример экспорта (реализация может быть расширена)
        std::ofstream file(filename);
        if (file.is_open()) {
            file << "Exported shapes data." << std::endl; // Упрощенный экспорт
            file.close();
            std::cout << "Document exported to " << filename << "." << std::endl;
        } else {
            std::cerr << "Failed to open file: " << filename << std::endl;
        }
    }

    void AddShape(std::shared_ptr<IShape> shape) {
        shapes.push_back(shape);
        shape->Draw(); // Рисуем добавляемую фигуру
    }

    void RemoveShape(std::shared_ptr<IShape> shape) {
        auto it = std::find(shapes.begin(), shapes.end(), shape);
        if (it != shapes.end()) {
            shape->Erase(); // Стираем фигуру перед удалением
            shapes.erase(it); // Удаляем фигуру
            std::cout << "Shape removed." << std::endl;
        } else {
            std::cerr << "Shape not found." << std::endl;
        }
    }

    size_t GetShapeCount() const { // Метод для получения количества фигур
        return shapes.size();
    }

    std::shared_ptr<IShape> GetLastShape() const { // Метод для получения последней фигуры
        if (!shapes.empty()) {
            return shapes.back();
        }
        return nullptr; // Возвращаем nullptr, если нет фигур
    }
};

#endif // DOCUMENT_H
