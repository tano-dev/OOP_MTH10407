
//Xây dựng một chương trình C++ để quản lý thông tin của Cho thuê mượn xe:
//Một khách hàng có thể thuê/mượn nhiều xe.
//
//Thông tin của chiếc Xe bao gồm mã đăng kí, thương hiệu (ví dụ Toyota Camry).
//
//Thông tin của một Khách hàng gồm định danh và tên.
//
//
//Chương trình chính sẽ thực hiện các thao tác sau:
//Tạo 2 khách hàng.
//Tạo 3 chiếc xe.
//
//Cho khách hàng thứ nhất thuê 2 chiếc xe đầu và thứ 2.
//
//Cho khách hàng thứ hai thuê chiếc xe thứ 3.
//
//Cho khách hàng thứ nhất trả chiếc xe thứ 2 và khách hàng thứ 2 thuê chiếc xe thứ 2 này.
//
//Hiển thị lại thông tin của khách hàng thứ 2 và các chiếc xe mà khách hàng đó đang mượn.


#include<iostream>
#include<string>
#include<list>

using namespace std;

class Car;
class Customer;

class Car {
private:
    string maDK;
    string hangXe;
public:
    Car() {
        this->maDK = "000";
        this->hangXe = "NULL";
    }
    Car(string maDK, string hangXe) {
        this->setMaDK(maDK);
        this->setHangXe(hangXe);
    }
    void setMaDK(string maDK);
    void setHangXe(string hangXe);
    string getMaDK();
    string getHangXe();
    void display();
};

class Customer {
private:
    string maDinhDanh;
    string name;
    list<Car*> cars;
public:
    Customer() {
        this->maDinhDanh = "-1";
        this->name = "NULL";
    }
    Customer(string maDinhDanh, string name) {
        this->setMaDinhDanh(maDinhDanh);
        this->setName(name);
    }
    void setMaDinhDanh(string maDinhDanh);
    void setName(string name);
    string getMaDinhDanh();
    string getName();
    void display();
    void addOneCar(Car* car);
    void removeOneCar(Car* car);
    void displayCar();
};
void Car::setMaDK(string maDK) {
    this->maDK = maDK;
}
void Car::setHangXe(string hangXe) {
    this->hangXe = hangXe;
}
string Car::getMaDK() {
    return this->maDK;
}
string Car::getHangXe() {
    return this->hangXe;
}
void Car::display() {
    cout << "Ma DK: " << this->getMaDK() << endl;
    cout << "Hang xe: " << this->getHangXe() << endl;
}
void Customer::setMaDinhDanh(string maDinhDanh) {
    this->maDinhDanh = maDinhDanh;
}
void Customer::setName(string name) {
    this->name = name;
}
string Customer::getMaDinhDanh() {
    return this->maDinhDanh;
}
string Customer::getName() {
    return this->name;
}
void Customer::display() {
    cout << "Dinh Danh: " << this->getMaDinhDanh() << endl;
    cout << "Ten: " << this->getName() << endl;
}
void Customer::addOneCar(Car* car) {
    this->cars.push_back(car);
}
void Customer::removeOneCar(Car* car) {
    this->cars.remove(car);
}
void Customer::displayCar() {
    cout << "Xe: " << endl;
    for (auto i : this->cars) {
        i->display();
    }
}

//int main() {
//    Customer* c1 = new Customer("001", "A");
//    Customer* c2 = new Customer("002", "B");
//    Car* car1 = new Car("1", "Mecs");
//    Car* car2 = new Car("2", "Lambo");
//    Car* car3 = new Car("3", "Toyota");
//    c1->addOneCar(car1);
//    c1->addOneCar(car2);
//    c2->addOneCar(car3);
//
//    cout << "Customer 1: " << endl;
//    c1->display();
//    c1->displayCar();
//    cout << "Customer 2: " << endl;
//    c2->display();
//    c2->displayCar();
//
//    c1->removeOneCar(car2);
//    c2->addOneCar(car2);
//
//    cout << "Customer 1 after: " << endl;
//    c1->display();
//    c1->displayCar();
//    cout << "Customer 2 after: " << endl;
//    c2->display();
//    c2->displayCar();
//
//    delete c1;
//    delete c2;
//    delete car1;
//    delete car2;
//    delete car3;
//
//    return 0;
//}

/*
OUTPUT:
Customer 1:
Dinh Danh: 001
Ten: A
Xe:
Ma DK: 1
Hang xe: Mecs
Ma DK: 2
Hang xe: Lambo
Customer 2:
Dinh Danh: 002
Ten: B
Xe:
Ma DK: 3
Hang xe: Toyota
Customer 1 after:
Dinh Danh: 001
Ten: A
Xe:
Ma DK: 1
Hang xe: Mecs
Customer 2 after:
Dinh Danh: 002
Ten: B
Xe:
Ma DK: 3
Hang xe: Toyota
Ma DK: 2
Hang xe: Lambo
*/