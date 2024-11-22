#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Document.h"
#include "Circle.h"
#include "Rectangle.h"
#include <memory>

class Controller {
private:
    std::shared_ptr<Document> document; // Оставляем как private

public:
    Controller() : document(std::make_shared<Document>()) {}

    void HandleCreateDocument() {
        document->CreateDocument();
    }

    void HandleImportDocument(const std::string& filename) {
        document->ImportDocument(filename);
    }

    void HandleExportDocument(const std::string& filename) {
        document->ExportDocument(filename);
    }

    void HandleAddShape(const std::string& shapeType, const std::string& color) {
        if (shapeType == "circle") {
            document->AddShape(std::make_shared<Circle>(color));
        } else if (shapeType == "rectangle") {
            document->AddShape(std::make_shared<Rectangle>(color));
        }
    }

    void HandleRemoveShape(std::shared_ptr<IShape> shape) {
        document->RemoveShape(shape);
    }

    size_t GetShapeCount() const { // Метод для получения количества фигур
        return document->GetShapeCount();
    }

    std::shared_ptr<IShape> GetLastShape() const { // Метод для получения последней фигуры
        return document->GetLastShape();
    }
};

#endif 
