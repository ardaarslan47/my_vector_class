#ifndef VECTOR_H
#define VECTOR_H

const int DEFAULT_VECTOR_SIZE = 10;

template <typename T>
class Vector
{
private:
    int size;
    int capacity;
    T* elements;

public:
    Vector(){
        size = 0;
        capacity = DEFAULT_VECTOR_SIZE;
        elements = new T[DEFAULT_VECTOR_SIZE];
    }
    Vector(int n, const T& value){
        size = n;
        capacity = n * 2;
        elements = new T[capacity];
        for (int i = 0; i < size; i++){
            elements[i] = value;
        }
        
    }
    Vector(const Vector& rhs){
        size = rhs.size;
        capacity = rhs.capacity;
        elements = new T[capacity];
        for (int i = 0; i < rhs.size; i++){
            elements[i] = rhs.elements[i];
        }
    }

    ~Vector(){
        delete[] elements;
    };

    int Size() const {
        return size;
    }
    int Capacity() const {
        return capacity;
    }
    bool isEmpty() const {
        return size == 0;
    }

    T& operator [](int index){
        return elements[index];
    }
    const T& operator [](int index) const {
        return elements[index];
    }
    Vector& operator = (const Vector& rhs){
        if (rhs.size > size){
            delete[] elements;
            capacity = rhs.size * 2;
            elements = new T[capacity];
        }
        for (int i = 0; i < rhs.size; i++){
            elements[i] = rhs.elements[i];
        }
        size = rhs.size;
        return *this;
    }

    void PushBack(const T& object){
        if (size == capacity){
            T* newArray = new T[capacity * 2];
            for (int i = 0; i < size; i++){
                newArray[i] = elements[i];
            }
            delete[] elements;
            elements = newArray;
            capacity = capacity * 2;
        }
        elements[size] = object;
        size++;
    }
    void PopBack(){
        if (size > 0){
            size--;
        }
        if (static_cast<float>(size) / capacity < 0.30){
            T* newArray = new T[capacity / 2];
            for (int i = 0; i < size; i++){
                newArray[i] = elements[i];
            }
            delete[] elements;
            elements = newArray;
            capacity = capacity / 2;
        }
    }
    void Erase(int index){
        for (int i = index; i < size - 1; i++){
            elements[i] = elements[i + 1];
        }
        size--;
    }
    void Insert(int index, const T& value){
        if (size == capacity){
            T* newArray = new T[capacity * 2];
            for (int i = 0; i < size; i++){
                newArray[i] = elements[i];
            }
            delete[] elements;
            elements = newArray;
            capacity = capacity * 2;
        }
        for (int i = index; i < size; i++){
            elements[i + 1] = elements[i];
        }
        elements[index] = value;
        size++;
    }
    void Clear(){
        size = 0;
    }
};

#endif