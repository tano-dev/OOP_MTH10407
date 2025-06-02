/*
Xây dựng một chương trình C++ để quản lý thông tin của một đại học:


Các tổ chức trong một đại học gồm các phòng (ban), khoa. Ví dụ các phòng trong đại học: Phòng Đào tạo, Phòng Khảo thí, ... Mỗi phòng, khoa đều có 1 số lượng nhân viên.


Hãy xây dựng các lớp theo kĩ thuật kế thừa và đa hình. Chương trình chính sẽ thực hiện các thao tác sau:

Tạo 1 đại học.

Tạo 2 phòng trong đại học với số lượng nhân viên tương ứng.

Tạo 2 khoa trong đại học với số lượng nhân viên tương ứng.

In danh sách các phòng và khoa của đại học và tổng số nhân viên.
*/
#include<iostream>
#include<string.h>
#include<list>
#include<map>
using namespace std;

class University;
class Phong;
class PhongDaoTao;
class PhongKhaoThi;
class Khoa;
class KhoaToan;
class KhoaCNTT;
class KhoaSinh;
class Nhanvien;

class University {
private:
	string name;
	list<Phong*> phongs;
	list<Khoa*> khoas;
public:
	University(string name);
	void setName(string name);
	string getName();
	void addPhong(Phong* phong);
	void addKhoa(Khoa* khoa);
	void display();
};

class Phong {
private:
	list<Nhanvien*> nhanviens;
public:
	Phong();
	void addNhanvien(Nhanvien* nv);
	virtual void display();
};
class PhongDaoTao : public Phong {
public:
	PhongDaoTao();
	void display();
};
class PhongKhaoThi : public Phong {
public:
	PhongKhaoThi();
	void display();
};
class Khoa {
private:
	list<Nhanvien*> nhanviens;
public:
	Khoa();
	void addNhanvien(Nhanvien* nv);
	virtual void display();
};
class KhoaToan : public Khoa {
public:
	KhoaToan();
	void display();
};
class KhoaCNTT : public Khoa {
public:
	KhoaCNTT();
	void display();
};
class KhoaSinh : public Khoa {
public:
	KhoaSinh();
	void display();
};

class Nhanvien {
private:
	string name;
	string id;
public:
	Nhanvien(string name, string id);
	void setName(string name);
	void setId(string id);
	string getName();
	string getId();
	void display();
};

//University

University::University(string name) {
	this->setName(name);
}
void University::setName(string name) {
	this->name = name;
}
string University::getName() {
	return this->name;
}
void University::addPhong(Phong* phong) {
	this->phongs.push_back(phong);
}
void University::addKhoa(Khoa* khoa) {
	this->khoas.push_back(khoa);
}
void University::display() {
	cout << "Dai hoc " << this->getName() <<" :" << endl;
	cout << ">Cac phong: " << endl;
	for (auto i : this->phongs) {
		i->display();
	}
	cout << ">Cac khoa: " << endl;
	for (auto i : this->khoas) {
		i->display();
	}
}

//Phong
Phong::Phong() {}
void Phong::addNhanvien(Nhanvien* nv) {
	this->nhanviens.push_back(nv);
}
void Phong::display() {
	cout << "  Tong so nhan vien: " << this->nhanviens.size() << endl;
	cout << "  Cac nhan vien: " << endl;
	for (auto i : this->nhanviens) {
		i->display();
	}
}
PhongDaoTao::PhongDaoTao() {}
void PhongDaoTao::display() {
	cout << " -Phong Dao Tao: " << endl;
	Phong::display();
}
PhongKhaoThi::PhongKhaoThi() {}
void PhongKhaoThi::display() {
	cout << " -Phong Khao Thi: " << endl;
	Phong::display();
}
//Khoa
Khoa::Khoa() {}
void Khoa::addNhanvien(Nhanvien* nv) {
	this->nhanviens.push_back(nv);
}
void Khoa::display() {
	cout << "  Tong so nhan vien: " << this->nhanviens.size() << endl;
	cout << "  Cac nhan vien: " << endl;
	for (auto i : this->nhanviens) {
		i->display();
	}
}
KhoaToan::KhoaToan() {}
void KhoaToan::display() {
	cout << " -Khoa Toan: " << endl;
	Khoa::display();
}
KhoaCNTT::KhoaCNTT() {}
void KhoaCNTT::display() {
	cout << " -Khoa CNTT: " << endl;
	Khoa::display();
}
KhoaSinh::KhoaSinh() {}
void KhoaSinh::display() {
	cout << " -Khoa Sinh: " << endl;
	Khoa::display();
}

//Nhanvien
Nhanvien::Nhanvien(string name, string id) {
	this->setName(name);
	this->setId(id);
}
void Nhanvien::setName(string name) {
	this->name = name;
}
void Nhanvien::setId(string id) {
	this->id = id;
}
string Nhanvien::getName() {
	return this->name;
}
string Nhanvien::getId() {
	return this->id;
}
void Nhanvien::display() {
	cout << "   +Nhan vien: " << this->getName() << endl;
	cout << "   +ID: " << this->getId() << endl;
}

//int main() {
//	University* uni = new University("KHTN");
//
//	Phong* phong1 = new PhongDaoTao();
//	Phong* phong2 = new PhongKhaoThi();
//	Khoa* khoa1 = new KhoaToan();
//	Khoa* khoa2 = new KhoaCNTT();
//	Khoa* khoa3 = new KhoaSinh();
//
//	Nhanvien* nv1 = new Nhanvien("Nguyen Van Phuc Huy", "23110163");
//	Nhanvien* nv2 = new Nhanvien("Nguyen A", "23110001");
//	Nhanvien* nv3 = new Nhanvien("Nguyen B", "23110002");
//	Nhanvien* nv4 = new Nhanvien("Nguyen C", "23110003");
//
//	uni->addPhong(phong1);
//	uni->addPhong(phong2);
//	uni->addKhoa(khoa1);
//	uni->addKhoa(khoa2);
//	uni->addKhoa(khoa3);
//
//	phong1->addNhanvien(nv1);
//	phong1->addNhanvien(nv4);
//	phong2->addNhanvien(nv2);
//	phong2->addNhanvien(nv3);
//
//	khoa1->addNhanvien(nv3);
//	khoa1->addNhanvien(nv4);
//	khoa2->addNhanvien(nv1);
//	khoa2->addNhanvien(nv2);
//	khoa3->addNhanvien(nv4);
//
//	uni->display();
//
//	delete uni;
//	delete phong1;
//	delete phong2;
//	delete khoa1;
//	delete khoa2;
//	delete nv1;
//	delete nv2;
//	delete nv3;
//	delete nv4;
//
//	return 0;
//}

/*
output:
Dai hoc KHTN :
>Cac phong:
 -Phong Dao Tao:
  Tong so nhan vien: 2
  Cac nhan vien:
   +Nhan vien: Nguyen Van Phuc Huy
   +ID: 23110163
   +Nhan vien: Nguyen C
   +ID: 23110003
 -Phong Khao Thi:
  Tong so nhan vien: 2
  Cac nhan vien:
   +Nhan vien: Nguyen A
   +ID: 23110001
   +Nhan vien: Nguyen B
   +ID: 23110002
>Cac khoa:
 -Khoa Toan:
  Tong so nhan vien: 2
  Cac nhan vien:
   +Nhan vien: Nguyen B
   +ID: 23110002
   +Nhan vien: Nguyen C
   +ID: 23110003
 -Khoa CNTT:
  Tong so nhan vien: 2
  Cac nhan vien:
   +Nhan vien: Nguyen Van Phuc Huy
   +ID: 23110163
   +Nhan vien: Nguyen A
   +ID: 23110001
*/
