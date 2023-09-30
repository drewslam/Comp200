#include <iostream>
using std::string;

class Employee {
    public:
    string Name;
    string Company;    
    int Age;
    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }
};

int main() {
    Employee employee1 = Employee("Andrew", "Heckin Co", 32);

    std::cout << employee1.Name << " ";
    std::cout << employee1.Age << " ";
    std::cout << employee1.Company << std::endl;
    return 0;
}
