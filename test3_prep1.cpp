/*
Xây dựng một chương trình C++ để quản lý thông tin của một giỏ hàng trong thương mại điện tử
Một người dùng có một giỏ hàng để lưu các mặt hàng muốn mua. Người dùng có thông tin bao gồm định danh, tên. Giỏ hàng có thuộc tính là tổng tiền để lưu tổng giá tiền phải trả của các mặt hàng có trong giỏ hàng.

Mặt hàng có các thuộc tính là tên và giá tiền. Giỏ hàng của người dùng có thể có nhiều mặt hàng, và ngược lại mặt hàng có thể xuất hiện trong nhiều giỏ hàng của các khách hàng khác nhau. Khi thêm một mặt hàng vào giỏ hàng của một người dùng thì phải quản lý được số lượng của mặt hàng đó.

Mặt hàng có các loại hàng điện tử, hàng thời trang. Mặt hàng thời trang có thêm thuộc tính giảm giá tính theo phần trăm.

Chương trình chính phải làm các chức năng sau:

Tạo 1 mặt hàng điện tử là laptop có giá 1000.
Tạo 1 mặt hàng thời trang là áo thun có giá 50, được giảm giá 20%.
Tạo 1 người dùng có định danh là 001, và tên là Alice.
Cho 1 laptop vào giỏ hàng của Alice.
Cho 2 áo thun vào giỏ hàng của Alice.
In giỏ hàng của Alice và tổng tiền của giỏ hàng.
*/

#include<iostream>
#include<string>
#include<list>
#include<map>
using namespace std;

class User;
class Cart;
class Product;
class ElectronicProduct;
class FashionProduct;

class User {
private:
	string id;
	string name;
	Cart* cart;
public:
	User(string id, string name);
	void setCart(Cart* cart);
	string getId();
	string getName();
	void addProduct(Product* product, int quantity);
	void displayCart();
	void display();
	~User();
};
class Cart {
private:
	map<Product*, int> products;
	User* cartOwner = nullptr;
	float totalPrice = 0; 
public:
	Cart(User* owner);
	void setCartOwner(User* owner);
	string getCartOwnerName();
	void calculateTotalPrice();
	void addProduct(Product* product, int quantity);
	void displayProducts();
	void display();
	~Cart();
};

class Product {
private:
	string name;
	float price;
public:
	Product(string name, float price);
	void setName(string name);
	void setPrice(float price);
	virtual float getPrice();
	string getName();
	virtual void display();
	~Product() {};
};
class ElectronicProduct : public Product {
public:
	ElectronicProduct(string name, float price);
	void display();
	~ElectronicProduct();
};
class FashionProduct : public Product {
private:
	float discount; 
public:
	FashionProduct(string name, float price, float discount);
	float getPrice();
	void display();
	~FashionProduct();
};

//User
User::User(string id, string name) {
	this->id = id;
	this->name = name;
	this->cart = new Cart(this);
}
void User::setCart(Cart* cart) {
	this->cart = cart;
	cart->setCartOwner(this);
}
string User::getId() {
	return this->id;
}
string User::getName() {
	return this->name;
}
void User::addProduct(Product* product, int quantity) {
	this->cart->addProduct(product, quantity);
}
void User::displayCart() {
	this->cart->displayProducts();
}
void User::display() {
	cout << "User ID: " << this->getId() << endl;
	cout << "Name: " << this->getName() << endl;
	this->cart->display();
}
User::~User() {
	delete this->cart;
}
//Cart
Cart::Cart(User* owner) {
	totalPrice = 0;
	setCartOwner(owner);
}
void Cart::setCartOwner(User* owner) {
	this->cartOwner = owner;
}
string Cart::getCartOwnerName() {
	return this->cartOwner->getName();
}
void Cart::calculateTotalPrice() {
	totalPrice = 0;
	for (auto& item : products) {
		totalPrice += item.first->getPrice() * item.second;
	}
}
void Cart::addProduct(Product* product, int quantity) {
	if (products.find(product) != products.end()) {
		products[product] += quantity;
	}
	else {
		products[product] = quantity;
	}
	calculateTotalPrice();
}
void Cart::displayProducts() {
	cout << this->getCartOwnerName() << "'s Cart contents:" << endl;
	for (auto& item : products) {
		cout << "- " << item.first->getName() << ": " << item.second << " pcs, Price: " << item.first->getPrice() * item.second << endl;
	}
	cout << "Total Price: " << totalPrice << endl;
}
void Cart::display() {
	cout << " Cart contents:" << endl;
	for (auto& item : products) {
		item.first->display();
		cout << "-->Quantity: " << item.second << endl;
		cout << "-->Sum:" << item.first->getPrice()*item.second << endl;
	}
	cout << "Total Price: " << totalPrice << endl;
}
Cart::~Cart() {
	products.clear();
}
//Product
Product::Product(string name, float price) {
	this->name = name;
	this->price = price;
}
void Product::setName(string name) {
	this->name = name;
}
void Product::setPrice(float price) {
	this->price = price;
}
float Product::getPrice() {
	return this->price;
}
string Product::getName() {
	return this->name;
}
void Product::display() {
	cout << "-->Product Name: " << this->getName() << endl;
	cout << "-->Price: " << this->getPrice() << endl;
}
ElectronicProduct::ElectronicProduct(string name, float price) : Product(name, price) {}
void ElectronicProduct::display() {
	cout << "-->Electronic Product: " << this->getName() << endl;
	cout << "-->Price: " << this->getPrice() << endl;
}
ElectronicProduct::~ElectronicProduct() {}
FashionProduct::FashionProduct(string name, float price, float discount) : Product(name, price) {
	this->discount = discount;
}
float FashionProduct::getPrice() {
	return Product::getPrice() * (1 - discount);
}
void FashionProduct::display() {
	cout << "-->Fashion Product: " << this->getName() << endl;
	cout << "-->Price after discount: " << this->getPrice() << endl;
}
FashionProduct::~FashionProduct() {}
// Main function
//int main() {
//
//	// Create products
//	ElectronicProduct* laptop = new ElectronicProduct("Laptop", 1000);
//	FashionProduct* tshirt = new FashionProduct("T-Shirt", 50, 0.2); // 20% discount
//	// Create user
//	User* alice = new User("001", "Alice");
//	// Add products to Alice's cart
//	alice->addProduct(laptop, 1);
//	alice->addProduct(tshirt, 2);
//	// Display Alice's information and cart
//	alice->displayCart();
//	alice->display();
//	// Clean up
//	delete laptop;
//	delete tshirt;
//	delete alice;
//	return 0;
//}
