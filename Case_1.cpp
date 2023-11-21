#include <iostream>
#include <string>

using namespace std;

long long itc_bin_num(long long number) {
    long long res = 0;
    long long base = 1;
    while (number > 0) {
        int d = number % 2;
        res = d * base + res;
        base = base * 10;
        number = number / 2;
    }
    return res;
}

string itc_num_to_str(long long n) {
    string res = "";
    while (n > 0) {
        if (n % 10 == 1) res = "1" + res;
        if (n % 10 == 0) res = "0" + res;
        n /= 10;
    }
    return res;
}

int main()
{
    long long n, k, chk;
    chk = 0;
    cin >> k >> n;
    if (n < 0) {
        chk = 1;
        n *= -1;
        n--;
    }
    n = itc_bin_num(n);
    string n1;
    n1 = itc_num_to_str(n);
    if (n1.size() > k) {
        n1 = n1.erase(n1.size() - k, n1.size());
    }
    if (n1.size() < k){
        while (n1.size() < k) {
            n1 = '0' + n1;
        }
    }
    if (chk == 1) {
        for (int i = 0; i < n1.size(); i++) {
            if (n1[i] == '0') n1[i] = '1';
            else n1[i] = '0';
        }

    }
    cout << n1;
}
