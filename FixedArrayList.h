//
// Interface Definition for the FixedArrayList Class
// Author: Max Benson
// Date: 08/06/2021
//

#ifndef FIXEDARRAYLIST_H
#define FIXEDARRAYLIST_H

#include <iostream>
using std::ostream;
using std::string;

class FixedArrayList  {
public:
    FixedArrayList(size_t capacity);

    // Rule of three
    ~FixedArrayList();
    FixedArrayList(const FixedArrayList&);
    const FixedArrayList& operator=(const FixedArrayList&);

    // Other methods
    bool Get(size_t position, string& item) const;
    int Find(const string& item, size_t start = 0) const;
    bool Insert(size_t position, const string& item);
    bool Replace(size_t position, const string& item);
    bool Swap(size_t position1, size_t position2);
    bool Remove(size_t position, string& item);
    void Clear();

    size_t Size() const;

    bool CheckConsistency() const;

    // Stream output
    friend ostream& operator<<(ostream& os, const FixedArrayList& list) {
        os << "[";
        for (size_t position = 0; position < list._size; position ++) {
            if (position > 0) {
                os << ", ";
            }
            os << list._array[position];
        }
        return os << "]";
    }

private:
    string* _array;
    size_t _size;
    size_t _capacity;
};

#endif //FIXEDARRAYLIST_H
