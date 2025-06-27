//#include<iostream>
//#include<string.h>
//#include<list>
//#include<map>
//using namespace std;
//
//class User;
//class Item;
//class Digital;
//class Fashion;
//class Cart;
//
//class User{
//private:
//	string ID;
//	string name;
//	Cart* cart;
//public:
//	~User(){}
//	User(string ID,string name);
//
//	void setID(string ID);
//	void setName(string name);
//
//	string getID();
//	string getName();
//	Cart* getCart();
//
//	void display();
//};
//
//class Item{
//private:
//	string name;
//	double price;
//public:
//	~Item(){}
//	Item(string name,double price);
//
//	void setName(string name);
//	void setPrice(double price);
//
//	string getName();
//	double getPrice();
//
//	virtual void display();
//};
//
//class Digital : public Item{
//public:
//	~Digital(){}
//	Digital(string name,double price);
//
//	double getPrice();
//
//	void display();
//};
//
//class Fashion : public Item{
//private:
//	double discount;
//public:
//	~Fashion(){}
//	Fashion(string name,double price,double discount);
//
//	void setDiscount(double discount);
//
//	double getDiscount();
//
//	void display();
//
//};
//
//class Cart{
//private:
//	map<Item* ,int> items;
//public:
//	~Cart(){
//		for(auto it : items){
//			delete it.first;
//		}
//		items.clear();
//	}
//
//	void addItem(Item* item, int number);
//
//	map<Item*,int> getItem();
//
//	void displayItem();
//	void displaySumPrice();
//};
//
////Class User
//User::User(string ID, string name) {
//    this->setID(ID);
//    this->setName(name);
//    this->cart =  new Cart();
//}
//
//void User::setID(string ID) {
//    this->ID = ID;
//}
//
//void User::setName(string name) {
//    this->name = name;
//}
//
//string User::getID() {
//    return this->ID;
//}
//
//string User::getName() {
//    return this->name;
//}
//
//Cart* User::getCart(){
//	return this->cart;
//}
//
//void User::display() {
//    cout << "ID: " << this->getID() << '\n';
//    cout << "Name: " << this->getName() << '\n';
//}
//
//
//
////Class Item
//Item::Item(string name, double price) {
//    this->setName(name);
//    this->setPrice(price);
//}
//
//void Item::setName(string name) {
//    this->name = name;
//}
//
//void Item::setPrice(double price) {
//    this->price = price;
//}
//
//string Item::getName() {
//    return this->name;
//}
//
//double Item::getPrice() {
//    return this->price;
//}
//
//void Item::display() {
//    cout << "Name: " << this->getName() << '\n';
//    cout << "Price: " << this->getPrice() << '\n';
//}
//
//
//
////Class Digital
//Digital::Digital(string name,double price):Item(name,price){
//
//}
//
//
//void Digital::display(){
//	Item::display();
//	cout<<endl;
//}
//
//
//
////Class Fashion
//Fashion::Fashion(string name, double price,double discount) : Item(name,price) {
//	this->setPrice((1-discount)*price);
//    this->setDiscount(discount);
//}
//
//void Fashion::setDiscount(double discount) {
//    this->discount = discount;
//}
//
//double Fashion::getDiscount() {
//    return this->discount;
//}
//
//
//void Fashion::display() {
//    cout<<"Item : " << this->getName() <<endl;
//    cout<<"Price (Discounted): "<< this->getPrice()<<endl;
//}
//
////Class Cart
//void Cart::addItem(Item* item,int number){
//	items[item] += number;
//}
//
//map<Item*,int> Cart::getItem(){
//	return this->items;
//}
//
//void Cart::displayItem(){
//	int i=0;
//	for(pair<Item*,int> it : this->items){
//		cout<<'#' << ++i<<endl;
//		it.first->display();
//		cout<<"Amount : " << it.second<<endl;
//
//	}
//}
//
//void Cart::displaySumPrice(){
//	double s =0;
//	for(pair<Item*,int> it : this->items){
//		s = s + (it.first->getPrice()) * it.second;
//	}
//	cout<<"Sum price : "<< s<< endl;
//}
//int main(){
//	Digital* laptop = new Digital("Laptop",1000);
//	Fashion* aothun = new Fashion("Ao Thun",50,0.2);
//	User* person = new User("001","Alice");
//	person->getCart()->addItem(laptop,1);
//	person->getCart()->addItem(aothun,2);
//	person->getCart()->displayItem();
//	person->getCart()->displaySumPrice();
//	delete person;
//	return 0;
//}