#include <bits/stdc++.h>

using namespace std;


const int SIZE = 1000;
string t[SIZE];

bool isPrime(int x) 
{
    if (x <= 1) return false;
    if (x % 2 == 0 && x != 2) return false;
    for (int i = 3; i * i <= x; i += 2) 
    {
        if (x % i == 0) return false;
    }
    return true;
}

bool isHalfPrime(int x) 
{
    if (isPrime(x)) return false;
    if (x % 2 == 0) return isPrime(x / 2);
    for (int i = 3; i * i <= x; i++) 
    {
        if (x % i == 0) return isPrime(x / i);
    }
}

int binToDec(string bin) 
{
    int n = 0;
    int base = 1;
    for (int i = bin.length() - 1; i >= 0; i--) 
    {
        n += (bin[i] - '0') * base;
        base *= 2;
    }
    return n;
}

void zadanie1() {
    cout << "Zadanie 1:" << "\n";
    int length;
    string w1, w2;
    for (int i = 0; i < SIZE; i++) 
    {
        length = t[i].length();
        if (length % 2 != 0) continue;
        w1 = t[i].substr(0, length / 2);
        w2 = t[i].substr(length / 2, length / 2);
        if (w1 == w2) 
        {
            cout << t[i] << "\n";
        }
    }
}

void zadanie2() {
    cout << "Zadanie 2:" << "\n";
    int length, counter = 0;
    for (int i = 0; i < SIZE; i++) 
    {
        length = t[i].length();
        counter++;
        for (int j = 1; j < length; j++) 
        {
            if (t[i][j] == '1' && t[i][j - 1] == '1') 
            {
                counter--;
                break;
            }
        }
    }
    cout << counter << "\n";
}


void zadanie3() {
    cout << "Zadanie 3:\n";
    int counter = 0, max = 0, min = 999999999;
    int number;
    for (int i = 0; i < SIZE; i++) 
    {
        number = binToDec(t[i]);

        if (isHalfPrime(number)) 
        {
            counter++;
            if (number > max) max = number;
            if (number < min) min = number;
        }
    }
    cout << "Liczb polpierwszych jest: " << counter << "\n";
    cout << "Min: " << min << "\nMax: " << max << "\n";
}

int main() {
    ifstream in("ciagi.txt");
    for (int i = 0; i < SIZE; i++) in >> t[i];

    zadanie1();
    zadanie2();
    zadanie3();
}
