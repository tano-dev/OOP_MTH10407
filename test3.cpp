/*
Một trang web (WebPage)  bao gồm nhiều đối tượng (Object). Đối tượng có thể là tập tin HTML (HTMLFile), hình ảnh (Image), âm thanh (Audio), ... Riêng tập tin HTML có thể chứa liên kết đến nhiều đối tượng khác.

Sơ đồ lớp của một trang web được mô tả trong hình sau:
Sơ đò: Biết: HTMLFile<>-----*Object, Image -->Object, Audio -->Object


Các thao tác trên đối tượng gồm có:

- Thêm/Xóa liên kết với đối tượng khác trong trường hợp đối tượng  là HTMLFile.

- Hiển thị thông tin của đối tượng: gồm tên của đối tượng (tên của tập tin HTML/Image/Audio/..) và thông tin các đối tượng liên kết với nó nếu có.

- Đếm số lượng đối tượng của một trang web (Xem ví dụ ở dưới).

Chương trình chính sẽ thực hiện các thao tác sau:

Tạo sơ đồ đối tượng như sau:

Tạo một đối tượng home là tập tin HTML, sau đó tạo 3 đối tượng header, main, footer là tập tin HTML, rồi cho đối tượng home liên kết (bao gồm) với header, main, và footer.

Tạo đối tượng picture1 và picture2 là tập tin hình ảnh. Tạo đối tượng audio là tập tin âm thanh. Sau đó tạo liên kết như trong sơ đồ ở dưới.



In thông tin của đối tượng home (và các đối tượng nó bao gồm) .

In số đối tượng có trong đối tượng home, đếm cả các đối tượng mà nó bao gồm và chính nó. Trong ví dụ trên, home có 7 đối tượng.


*/

#include<iostream>
#include<string.h>
#include<list>
#include<map>
using namespace std;

class Object;
class HTMLFile;
class Image;
class Audio;

class Object {
private:
    string name;
public:
    Object(string name);
    virtual void display();
    void setName(string name);
    string getName();
    virtual  int sumObjs();
    void displayInfo();
    ~Object() {};
};
class HTMLFile : public Object {
private:
    list<Object*> objects;
public:
    HTMLFile(string name);
    void addObj(Object* obj);
    void removeObj(Object* obj);
    list<Object*> getObjects();
    int sumObjs();
    void display();
    ~HTMLFile() {};
};
class Image : public Object {
public:
    Image(string name);
    void display();
    int sumObjs();
    ~Image() {}
};
class Audio : public Object {
public:
    Audio(string name);
    void display();
    int sumObjs();
    ~Audio() {}
};
//Object
Object::Object(string name) {
    this->name = name;
}
void Object::setName(string name) {
    this->name = name;
}
string Object::getName() {
    return this->name;
}
void Object::display() {
    cout << "Object Name: " << this->getName() << endl;
}
void Object::displayInfo() {
    cout << "  >>Obj Name: " << this->getName() << endl;
}
int Object::sumObjs() {
    return 1;
}
//HTMLFile
HTMLFile::HTMLFile(string name) : Object(name) {}
void HTMLFile::addObj(Object* obj) {
    this->objects.push_back(obj);
}
void HTMLFile::removeObj(Object* obj) {
    this->objects.remove(obj);
}
list<Object*> HTMLFile::getObjects() {
    return this->objects;
}
int HTMLFile::sumObjs() {
    int count = 1;
    for (auto i : objects) {
        count = count + i->sumObjs();
    }
    return count;
}

void HTMLFile::display() {
    Object::display();
    cout << Object::getName() << "'s objects:" << endl;
    if (objects.empty()) {
        cout << "  > Nothing" << endl;
        return;
    }
    for (auto i : objects) {
        i->display();
    }
}
//Image
Image::Image(string name) : Object(name) {}
void Image::display() {
    cout << " >>Image" << endl;
    Object::displayInfo();
}
int Image::sumObjs() {
    return 1;
}
//Audio
Audio::Audio(string name) : Object(name) {}
void Audio::display() {
    cout << " >>Audio" << endl;
    Object::displayInfo();
}
int Audio::sumObjs() {
    return 1;
}

int main() {
    // HTMLS
    HTMLFile* home = new HTMLFile("home.html");
    HTMLFile* header = new HTMLFile("header.html");
    HTMLFile* main = new HTMLFile("main.html");
    HTMLFile* footer = new HTMLFile("footer.html");
    // objects
    Image* picture1 = new Image("header.jpg");
    Image* picture2 = new Image("main.png");
    Audio* audio = new Audio("audio.mp3");
    home->addObj(header);
    home->addObj(main);
    home->addObj(footer);
    header->addObj(picture1);
    main->addObj(picture2);
    main->addObj(audio);
    home->display();
    cout << "Tong cac object trong home: " << home->sumObjs() << endl;

    delete home;
    delete header;
    delete main;
    delete footer;
    delete picture1;
    delete picture2;
    delete audio;
    return 0;
}

//Output:
/*
Object Name: home.html
home.html's objects:
Object Name: header.html
header.html's objects:
 >>Image
  >>Obj Name: header.jpg
Object Name: main.html
main.html's objects:
 >>Image
  >>Obj Name: main.png
 >>Audio
  >>Obj Name: audio.mp3
Object Name: footer.html
footer.html's objects:
  > Nothing
Tong cac object trong home: 7
*/