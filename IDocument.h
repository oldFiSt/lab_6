#ifndef IDOCUMENT_H
#define IDOCUMENT_H

#include <string>

class IDocument {
public:
    virtual ~IDocument() = default;
    virtual void CreateDocument() = 0;
    virtual void ImportDocument(const std::string& filename) = 0;
    virtual void ExportDocument(const std::string& filename) = 0;
};

#endif 
