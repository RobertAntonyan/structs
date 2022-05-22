#include <iostream>
#include <string>

struct A
{
    float weight;
    std::string _name;
    int *ptr;

public:
    A() { std::cout << "Constructor call by default " << this << std::endl; }
    A(float _weight)
    {
        weight = _weight;
        std::cout << "Constructor call with 1 parameter " << this << std::endl;
    }
    A(float _weight, std::string name)
    {
        weight = _weight;
        _name = name;
        std::cout << "Constructor call with 2 parameter " << this << std::endl;
    }
    A(float _weight, std::string name, int *ptr)
    {
        weight = _weight;
        _name = name;
        std::cout << "Constructor call with 3 parameter " << this << std::endl;
    }

public:
    A(const A &other)
    {
        weight = other.weight;
        _name = other._name;
        *ptr = *other.ptr;

        std::cout << "Object copy constructor call " << this << std::endl;
    }

    ~A()
    {
        std::cout << "Destruktor call " << this << std::endl;
    }

public:
    void setWeight(float x)
    {

        weight = x;
    }

    float getWeight(float weight)
    {
        return weight;
    }
    void setString(std::string str)
    {
        _name = str;
    }

    std::string getString(std::string _name)
    {
        return _name;
    }
    void setArr(int *arr, int size)
    {
        ptr = new int[size];
        for (int i = 0; i < size; ++i)
        {
            ptr[i] = arr[i];
        }
    }
    void getArr(int *ptr, int size)
    {
        for (int i = 0; i < size; ++i)
        {
            std::cout << ptr[i] << " ";
            std::cout << std::endl;
        }
    }

    void deleteArr(int *arr, int size)
    {
        delete[] ptr;
    }
    void toString(int *ptr, float weight, std::string STR, int size)
    {
        std::cout <<"The value for array is " << std::endl;
        for (int i = 0; i < size; ++i)
        {
            std::cout << ptr[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "The value for weight is " <<  weight << std::endl;
        std::cout << "The name is " << STR << std::endl;
    }
};

int main()
{
    float x;
    int y;
    std::cout <<"Enter the value for x "; 
    std::cin >> x;
    std::string _str;
    std::cout <<"Enter the name for _str "; 
    std::cin >> _str;
    const int size = 3;
    int tmp_arr[size] = {1, 2, 3};
    int arr[size] = {7, 8, 9};
    A b(3.14, "Hi");
    b.setArr(arr, size);
    b.getArr(arr, size);
    b.deleteArr(arr, size);
    A myObject_1;
    myObject_1.weight = 70.5;
    myObject_1._name = "Robert";
    myObject_1.setArr(tmp_arr, size);
    myObject_1.setWeight(x);
    std::cout << myObject_1.getWeight(x) << std::endl;
    myObject_1.setString(_str);
    std::cout << myObject_1.getString(_str) << std::endl;
    myObject_1.toString(arr,x,_str,size);
}
    
