#define _CRT_SECURE_NO_WARNINGS_
#include <iostream>
#include <string.h>
#include <iomanip>
#pragma warning(disable : 4996)
using namespace std;
class Manufacturer {
public:
	Manufacturer() {
		guarantee = 0;
		company = new char[10];
		adress = new char[10];
		telephone = new char[10];
		strcpy(company, "Empty");
		strcpy(adress, "Empty");
		strcpy(telephone, "Empty");
	}
	Manufacturer(int g, char* c, char* a, char* t) {
		guarantee = g;
		company = new char[strlen(c) + 1];
		adress = new char[strlen(a) + 1];
		telephone = new char[strlen(t) + 1];
		strcpy(company, c);
		strcpy(adress, a);
		strcpy(telephone, t);
	}
	Manufacturer(const Manufacturer& other) {
		guarantee = other.guarantee;
		company = new char[strlen(other.company) + 1];
		adress = new char[strlen(other.adress) + 1];
		telephone = new char[strlen(other.telephone) + 1];
		strcpy(company, other.company);
		strcpy(adress, other.adress);
		strcpy(telephone, other.telephone);
	}
	int GetGuarantee() {
		return guarantee;
	}
	char* GetName() {
		return company;
	}
	char* GetAdress() {
		return adress;
	}
	char* GetTelephone() {
		return telephone;
	}
	Manufacturer& SetGuarantee(int Guarantee) {
		guarantee = Guarantee;
		return *this;
	}
	Manufacturer& SetName(char* c) {
		delete[] company;
		company = new char[strlen(c) + 1];
		strcpy(company, c);
		return *this;
	}
	Manufacturer& SetAdress(char* a) {
		delete[] adress;
		adress = new char[strlen(a) + 1];
		strcpy(adress, a);
		return *this;
	}
	Manufacturer& SetPhone_Number(char* t) {
		delete[] telephone;
		telephone = new char[strlen(t) + 1];
		strcpy(telephone, t);
		return *this;
	}
	void Print_Manufacture() {
		cout << "Name of manufacturer: " << company << endl;
		cout << "Adress: " << adress << endl;
		cout << "Phone number: " << telephone << endl;
		cout << "Guarantee period: " << guarantee << endl;
	}
	void ShortPrint() {
		cout << "\nName of manufacturer: " << company << endl;
	}
	bool operator == (const Manufacturer& other) {
		return (strcmp(company, other.company) == 0 &&
			strcmp(adress, other.adress) == 0 &&
			strcmp(telephone, other.telephone) == 0 &&
			guarantee == other.guarantee);
	}
	friend ostream& operator<<(ostream& out, Manufacturer&
		outstream);
	friend istream& operator>>(istream& in, Manufacturer&
		instream);
public:
	char* company;
	char* adress;
	char* telephone;
	int guarantee;
};
istream& operator>>(istream& in, Manufacturer& instream) {
	cout << "Name of manufacturer: ";
	in.getline(instream.company, 20);
	cout << "Adress: ";
	in.getline(instream.adress, 20);
	cout << "Phone number : ";
	in.getline(instream.telephone, 20);
	cout << "Guarantee period: ";
	in >> instream.guarantee;
	in.ignore(1, '\n');
	return in;
}
ostream& operator<<(ostream& out, Manufacturer& outstream) {
	out << "Name of manufacturer: " << outstream.company <<
		endl;
	out << "Adress: " << outstream.adress << endl;
	out << "Phone number: " << outstream.telephone << endl;
	out << "Guarantee: " << outstream.guarantee << endl;
	return out;
}
class Product {
public:
	Product() {
		price = 0;
		name = new char[10];
		strcpy(name, "Empty");
	}
	Product(char* n, double p, int g, char* c, char* a, char* t) :
		firm(g, c, a, t) {
		price = p;
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	Product(Product& other) :firm(other.firm) {
		price = other.price;
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
	}
	~Product() {
		delete[] name;
	}
	double GetPrice() {
		return price;
	}
	char* GetName_prod() {
		return name;
	}
	double GetGuarantee() {
		return firm.GetGuarantee();
	}
	char* GetName() {
		return firm.GetName();
	}
	char* GetAdress() {
		return firm.GetAdress();
	}
	char* GetPhone_Number() {
		return firm.GetTelephone();
	}
	Product& SetPrice(double p) {
		price = p;
		return *this;
	}
	Product& SetName_Prod(char* n) {
		delete[] name;
		name = new char[strlen(n) + 1];
		strcpy(name, n);
		return *this;
	}
	Product& SetFirm(int g, char* n, char* a, char* t) {
		firm.SetGuarantee(g);
		firm.SetAdress(a);
		firm.SetName(n);
		firm.SetPhone_Number(t);
		return *this;
	}
	virtual void Print() {
		cout << "Name of product: " << name << endl;
		cout << "Price of product: " << price << endl;
		firm.Print_Manufacture();
	}
	void ShortPrint() {
		cout << "\nName of product: " << name << " by " <<
			firm.GetName() << endl;
	}
	bool operator == (Product& other) {
		return (strcmp(name, other.name) == 0 &&
			strcmp(firm.GetName(), other.firm.GetName()) == 0
			&&
			strcmp(firm.GetAdress(), other.firm.GetAdress()) ==
			0 &&
			strcmp(firm.GetTelephone(),
				other.firm.GetTelephone()) == 0 &&
			price == other.price &&
			firm.GetGuarantee() == other.firm.GetGuarantee());
	}
	Product& SetWarehouse() {
		this->name = new char[10];
		strcpy(name, "Unknown");
		this->price = 0;
		firm.company = new char[10];
		firm.adress = new char[10];
		firm.telephone = new char[10];
		strcpy(firm.company, "Unknown");
		strcpy(firm.adress, "Unknown");
		strcpy(firm.telephone, "Unknown");
		firm.guarantee = 0;
		return *this;
	}
	friend ostream& operator<<(ostream& out, Product&
		outstream);
	friend istream& operator>>(istream& in, Product& instream);
public:
	char* name;
	double price;
	Manufacturer firm;
};
istream& operator>>(istream& in, Product& instream) {
	in >> instream.firm;
	cout << "Name of product: ";
	in.getline(instream.name, 20);
	cout << "Price: ";
	in >> instream.price;
	in.ignore(1, '\n');
	return in;
}
ostream& operator<<(ostream& out, Product& outstream) {
	out << "Name of product: " << outstream.name << endl;
	out << "Price of product: " << outstream.price << endl;
	out << outstream.firm;
	return out;
}
class Done_Product : public Product {
public:
	Done_Product() {
		quantity = 0;
		day = 0;
		month = 0;
		year = 0;
	}
	Done_Product(int q, int y, int m, int d, char* n, double p, int g,
		char* c, char* a, char* t) : Product(n, p, g, c, a, t) {
		quantity = q;
		year = y;
		month = m;
		day = d;
	}
	Done_Product(Done_Product& other) :Product(other) {
		quantity = other.quantity;
		day = other.day;
		month = other.month;
		year = other.year;
	}
	~Done_Product() {}
	long GetQuantity() {
		return quantity;
	}
	int GetYear() {
		return year;
	}
	int GetMonth() {
		return month;
	}
	int GetDay() {
		return day;
	}
	Done_Product& SetQuantity(long q) {
		quantity = q;
		return *this;
	}
	Done_Product& SetYear(long y) {
		year = y;
		return *this;
	}
	Done_Product& SetMonth(long m) {
		month = m;
		return *this;
	}
	Done_Product& SetDay(long d) {
		day = d;
		return *this;
	}
	virtual void Print() {
		cout << "Name of product: " << name << endl;
		cout << "Price of product: " << price << endl;
		cout << quantity << " products was done " << day << " " <<
			month << " " << year << endl;
	}
	void Short_Print_Done_Product() {
		cout << quantity << " products was done " << day << " " <<
			month << " " <<
			year << endl;
	}
	Done_Product& operator ++() {
		quantity++;
		return *this;
	}
	Done_Product& operator +=(Done_Product& other) {
		quantity += other.quantity;
		return *this;
	}
	bool operator < (const Done_Product& other) {
		return (quantity < other.quantity);
	}
	Done_Product(Product& other);
	friend Product;
protected:
	int quantity, year, month, day;
};
class Sold_Product : public Done_Product {
public:
	Sold_Product() {
		number = ++count;
		quantity_sold = 0;
		day_sold = 0;
		month_sold = 0;
		year_sold = 0;
	}
	Sold_Product(int y_s, int m_s, int d_s, long q_s,
		long quantity, int year, int month, int day, char*
		namE_prod, double pricE,
		int guaranteE,
		char* namE, char* adresS, char* phone_numbeR)
		:year_sold(y_s),
		month_sold(m_s),
		day_sold(d_s), quantity_sold(q_s), Done_Product(quantity,
			year, month, day,
			namE_prod, pricE, guaranteE, namE, adresS,
			phone_numbeR) {
		number = ++count;
	}
	Sold_Product(Sold_Product& other) :Done_Product(other) {
		number = ++count;
		quantity_sold = other.quantity_sold;
		day_sold = other.day_sold;
		month_sold = other.month_sold;
		year_sold = other.year_sold;
	}
	~Sold_Product() {
		number = count--;
	}
	long GetQuantity_Sold() {
		return quantity_sold;
	}
	int GetYear_Sold() {
		return year_sold;
	}
	int GetMonth_Sold() {
		return month_sold;
	}
	int GetDay_Sold() {
		return day_sold;
	}
	Sold_Product& SetQuantity_Sold(long q) {
		quantity_sold = q;
		return *this;
	}
	Sold_Product& SetYear_Sold(long y) {
		year_sold = y;
		return *this;
	}
	Sold_Product& SetMonth_Sold(long m) {
		month_sold = m;
		return *this;
	}
	Sold_Product& SetDay_Sold(long d) {
		day_sold = d;
		return *this;
	}
	virtual void Print() {
		cout << quantity << " products was done " << day << " " <<
			month << " " << year << endl;
		cout << "Product number: " << number << " - " <<
			quantity_sold << " products was sold " << day_sold << " " <<
			month_sold << " " << year_sold << endl;
	}
	void Print_Sold_Product() {
		cout << quantity << " products was done " << day << " " <<
			month << " " << year << endl;
	}
private:
	int year_sold, month_sold, day_sold;
	long quantity_sold;
	static int count;
	int number;
};
int Sold_Product::count = 0;
class Storage {
public:
	Storage() {
		this->size = 2;
		array = new Product[size];
		this->number = 1;
	}
	Storage(int n) {
		this->size = n;
		array = new Product[size];
		for (int i = 0; i < this->size; i++) {
			array[i].SetWarehouse();
		}
		this->number = 1;
	}
	Storage(const Storage& other) {
		this->number = other.number;
		this->size = other.size;
		for (int i = 0; i < this->size; i++) {
			array[i] = other.array[i];
		}
	}
	~Storage() {
		delete[] array;
	}
	Product& operator[] (int val) {
		if ((val < size) && (val >= 0)) {
			return this->array[val];
		}
		else {
			cout << "Impossible" << endl;
		}
	}
	int GetNumber() {
		return number;
	}
	void PrintNumber() {
		cout << "number:" << number << endl;
	}
private:
	int number;
	int size;
	Product* array;
};
Done_Product::Done_Product(Product& other) {
	this->price = other.price;
	this->firm = other.firm;
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
	quantity = 100000;
	year = 1000;
	month = 10;
	day = 10;
}
int main() {
	Product* a[3];
	char q1[]{ "hgjk" };
	char q2[]{ "bvdjb" };
	char q3[]{ "eqeqwe" };
	char q4[]{ "+3807859343" };
	char q5[]{ "sakldjk" };
	char q6[]{ "snfknd" };
	char q7[]{ "vnkfg" };
	char q8[]{ "+3804758993" };
	char q9[]{ "abcdefgh" };
	char q10[]{ "bbbbdsdf" };
	char q11[]{ "hertyu" };
	char q12[]{ "+3806873284" };
	Product b(q1, 123.89, 7, q2, q3, q4);
	Done_Product c(2678, 2022, 02, 12, q5, 56.13, 3, q6, q7, q8);
	Sold_Product d(2021, 12, 29, 1000, 150000, 2021, 12, 28, q9,
		50.12, 9, q10, q11, q12);
	a[0] = &b;
	a[1] = &c;
	a[2] = &d;
	for (int i = 0; i < 3; i++) {
		a[i]->Print();
		cout << endl;
	}
	Done_Product c1(20000, 2021, 10, 12, q5, 52.13, 12, q6, q7, q8);
	cout << "Done_Product->Product:" << endl;
	Product b1 = c1;
	b1.Print();
	cout << endl;
	cout << "Product->Done_Product:" << endl;
	Done_Product c2 = b1;
	c2.Print();
	cout << endl;
	Storage e;
	e[0].Print();
	return 0;
}