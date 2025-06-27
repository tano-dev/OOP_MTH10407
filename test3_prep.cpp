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
#include<string.h>
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
};
class Cart {
private:
	map<Product*, int> productQuantities; 
	float totalPrice; 
public:
	Cart() {
		totalPrice = 0;
	}
	void addProduct(Product* product, int quantity);
	void display();
};

class Product {
protected:
	string name;
	float price;
public:
	Product(string name, float price);
	virtual float getPrice() = 0; // Pure virtual function
	string getName();
	void display();
};