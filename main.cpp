#include <iostream>
using namespace std;
class date {
    friend bool check_time(date &c1,date &c2);
    friend istream &operator>>(istream &in, date &obj);
    friend ostream &operator<<(ostream &out, date &obj);
public:
    date(const date &obj) {
        day = obj.day;
        month = obj.month;
        year = obj.year;
    }
    date(int, int, int);
    date() {
        day = 0;
        month = 0;
        year = 0;
    }
    void setdate(int, int, int);
    int getday() {
        return day;
    }
    int getmonth() {
        return month;
    }
    int getyear() {
        return year;
    }
    void displayinfo() {
             cout<< day << '/' << month << '/' << year << " ";
    }
private:
    int day;
    int month;
    int year;
    int days_of_month[13] = {0, 30, 30, 30, 30, 30, 30, 31, 31, 31, 31, 31, 31};
};

date::date(int _d, int _m, int _y) {
    setdate(_d, _m, _y);
}
void date::setdate(int _day, int _month, int _year) {
    if (_year > 0) {
        year = _year;
    } else {
        year = 1402;
    }

    if (_month > 0 && _month < 13) {
        month = _month;
    } else {
        month = 1;
    }

    if (_day > 0 && _day <= days_of_month[month]) {
        day = _day;
    } else {
        day = 1;
    }
}
istream &operator>>(istream &in, date &obj) {
    cout << "Enter Day:\n";
    in >> obj.day;
    cout << "Enter month:\n";
    in >> obj.month;
    cout << "Enter year:\n";
    in >> obj.year;
    return in;
}

ostream &operator<<(ostream &out, date &obj) {
    out << obj.day << '/' << obj.month << '/' << obj.year << endl;
    return out;
}
bool check_time(date &c1,date &c2)
{
    if(c1.day < c2.day && c1.month < c2.month && c1.year < c2.year)
    {
        return true;
    }else{
        return false;
    }
}
///----------------------------------------------------------------------------------
class Food{
    friend istream &operator >>(istream &in,Food &obj);
    friend ostream &operator <<(ostream &out,Food &obj);
public:
    Food(string _name = "",double _price = 0,string dec = "",string inger = "",date pro = date(1,1,1),date exp = date(2,2,2),bool c = false)
    {
        setname(_name);
        setprice(_price);
        setdecription(dec);
        setingerdients(inger);
        product = date();
        expiration = date();
        //setcheck(c);
    }
    void setname(string n)
    {
        name = n;
    }
    void setprice(double p)
    {
        if(p > 0)
        {
            price = p;
        }else{
            price = 0;
        }
    }
    void setdecription(string d)
    {
        decription = d;
    }
    void setingerdients(string i)
    {
        ingerdients = i;
    }
    void setcoocking_metods(string c_m)
    {
        coocking_metods = c_m;
    }
    void setproduct(int d,int m,int y)
    {
        product.setdate(d,m,y);
    }
    void setexpiration(int d,int m,int y)
    {
        expiration.setdate(d,m,y);
    }
    /*void setcheck(bool ch)
    {
        ch = check(product,ingerdients);
        check = ch;
    }*/
    string getname()
    {
        return name;
    }
    double getprice()
    {
        return price;
    }
    string getdecription()
    {
        return decription;
    }
    string getingerdients()
    {
        return ingerdients;
    }
    string getcoocking_metods()
    {
        return coocking_metods;
    }
    date getproduct()
    {
        return product;
    }
    date getexpiration()
    {
        return expiration;
    }
private:
    string name;
    double price;
    string decription; /// توضیحات
    string ingerdients; /// مواد تشکیل دهنده
    string coocking_metods;
    date product; /// تاریخ تولید
    date expiration; /// تاریخ انقضا
    //bool check;
};
istream &operator >>(istream &in,Food &obj)
{
    for(int i=0;i<60;i++)
    {
        cout << "<>";
    }
    cout << "\nEnter name of your food:\n";
    in >> obj.name;
    cout << "Enter decription:\n";
    in >> obj.decription;
    cout << "Enter ingerdients:\n";
    in >> obj.ingerdients;
    cout << "Enter Coocking Metods:\n";
    in >> obj.coocking_metods;
    cout << "Enter product Time:\n";
    in >> obj.product;
    cout << "Enter expiration:\n";
    in >> obj.expiration;
    for(int i=0;i<60;i++)
    {
        cout << "<>";
    }
    return in;

}
ostream &operator <<(ostream &out,Food &obj)
{
    for(int i=0;i<60;i++)
    {
        cout << "<>";
    }
    out << "\nName of food "<<obj.name<<" The Price of food "<<obj.price<<
    "\ndecription:\n"<<obj.decription<<"\ningerdients:\n"<<
    obj.ingerdients<<"\nCoocking Metod:\n"<<obj.coocking_metods<<
    "\nproduct Time: "<<obj.product<<"\nexpiration: "<<obj.expiration<<endl;
    for(int i=0;i<60;i++)
    {
        cout << "<>";
    }
    return out;
}
///----------------------------------------------------------------------------------
int main() {
Food flavor;
cin >> flavor;
cout << flavor;
date first = flavor.getproduct();
date end = flavor.getexpiration();
bool check = check_time(first,end);
cout << endl;
for(int i=0;i<60;i++)
{
    cout << "<>";
}
if(check)
{
    cout << "\nTaste is GOOD!\n";
}else{
    cout << "\nPrefer Don't taste this FOOD!\n";
}
    return 0;
}
