#include <iostream>
#include "Vector.hpp"

using namespace std;

int main() {
    Vector<float> v;
    v.PushBack(10);
    v.PushBack(20);
    v.PushBack(30);
    v.PushBack(40);
    v.PushBack(50);
    v.PopBack();
    v.Erase(0);
    v.Insert(2, 99);

    Vector<float> w = v;

    for (int i = 0; i < w.Size(); i++){
        cout << w[i] << endl;
    }

    for (int i = 0; i < v.Size() ; i++) {
        cout << v[i] << endl;
    }
    cout << v.Capacity();
        
    return 0;
}