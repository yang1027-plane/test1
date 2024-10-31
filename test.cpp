#include<iostream>
#include<string>
#include<cstdlib>
#include<sstream>
using namespace std;
class COMPLEX //复数类，real为实部，imagin为虚部
{
public:
    double real = 0;
    double imagin = 0;
};

double comreal(string c)//取出实部
{
    double ret;
    int j = c.find("+");
    int p = c.find_last_of("-");
    if (j >= 0 && j < c.length())
    {
        c = c.substr(0, j);
        stringstream ss(c);
        ss >> ret;
        return ret;
    }
    else if (p > 0 && p < c.length())
    {
        c = c.substr(0, p);
        stringstream ss(c);
        ss >> ret;
        return ret;
    }
    else if (c[c.length() - 1] == 'i')
    {
        ret = 0;
        return ret;
    }
    else
    {
        int m;
        stringstream ss(c);
        ss >> m;
        return m;
    }

}

double comimagin(string c)//取出虚部
{
    double ret;
    int j = c.find("+");
    int p = c.find_last_of("-");
    int i = c.find("i");
    if (j == i -1)
    {
        ret = 1;
        return ret;
    }
    else if (p == i - 1)
    {
        ret = -1;
        return ret;
    }
    else if (j >= 0 && j < c.length())
    {
        c = c.substr(j, c.length());
        stringstream ss(c);
        ss >> ret;
        return ret;
    }
    else if (p > 0 && p < c.length())
    {
        c = c.substr(p, c.length());
        stringstream ss(c);
        ss >> ret;
        return ret;
    }
    else if (c[c.length() - 1] != 'i')
    {
        ret = 0;
        return ret;
    }
    else
    {
        c.erase(c.find("i"), 1);
        stringstream ss(c);
        ss >> ret;
        return ret;
    }


}

int main()
{
    string c1, c2;
    COMPLEX com1, com2, comresult;
    cin >> c1;
    com1.real = comreal(c1);
    com1.imagin = comimagin(c1);
    cout << com1.real << endl;
    cout << com1.imagin << endl;
    return 0;
}