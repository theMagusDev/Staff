#ifndef STAFF_HEADING_H
#define STAFF_HEADING_H

class Heading {
 public:
    virtual ~Heading() = default;
    virtual int calcHeads() = 0;
};

#endif //STAFF_HEADING_H
