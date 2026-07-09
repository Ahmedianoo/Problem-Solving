#include <iostream>

using namespace std;


// solution: 1
string addBinary(string a, string b) {
    int carry = 0;
    string sum = "";

    int i = a.size() - 1;
    int j = b.size() - 1;

    while(i >= 0 || j >= 0 || carry){
        int digitA = i >= 0 ? a[i--] - '0' : 0;
        int digitB = j >= 0 ? b[j--] - '0' : 0;

        int total = digitA + digitB + carry;

        char c = total % 2 + '0'; 
        sum = c + sum;
        carry = total / 2;        
    }  

    return sum;
}

// solution: 2
// string addBinary(string a, string b) {
//     int carry = 0;
//     string sum = "";

//     reverse(a.begin(), a.end());
//     reverse(b.begin(), b.end());

//     for(int i = 0; i < max(a.size(), b.size()); i++){
//         int digitA = i < a.size() ? a[i] - '0' : 0;
//         int digitB = i < b.size() ? b[i] - '0' : 0;

//         int total = digitA + digitB + carry;
        
//         char c = total % 2 + '0'; 
//         sum = c + sum;
//         carry = total / 2;
//     }

//     if (carry == 1){
//         sum = '1' + sum;
//     }

//     return sum;
// }

// solution: 3
// string addBinary(string a, string b) {
//     bool carry = 0;
//     string sum = "";

//     reverse(a.begin(), a.end());
//     reverse(b.begin(), b.end());

//     for(int i = 0; i < max(a.size(), b.size()); i++){
//         char digitA = i < a.size() ? a[i] : '0';
//         char digitB = i < b.size() ? b[i] : '0';

//         if(digitA == '0' && digitB == '0' && carry == 0){
//             sum = '0' + sum;
//         }
//         else if(digitA == '0' && digitB == '0' && carry == 1){
//             carry = 0;
//             sum = '1' + sum;
//         }
//         else if(digitA == '1' && digitB == '1' && carry == 0){
//             carry = 1;
//             sum = '0' + sum;
//         }
//         else if(digitA == '1' && digitB == '1' && carry == 1){
//             sum = '1' + sum;
//         }
//         else if(carry == 0){
//             sum = '1' + sum;
//         }
//         else if(carry == 1){
//             sum = '0' + sum;
//         }
//     }

//     if (carry == 1){
//         sum = '1' + sum;
//     }

//     return sum;
// }