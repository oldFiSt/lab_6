#ifndef ISHAPE_H
#define ISHAPE_H

class IShape {
public:
    virtual ~IShape() = default;
    virtual void Draw() = 0;
    virtual void Erase() = 0;
};

#endif 
