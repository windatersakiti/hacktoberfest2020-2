#include <iostream>
#include <stdio.h>

#define MAX 50
#define true 1
#define false 0

char stack[MAX];
int top1, top2;

// Inisialisasi stack
void init() {
    top1 = 0;
    top2 = MAX+1;
}

// Mencari tau apakah stack masih bisa digunakan apa enggak


// Mencari tau apakah stack 1 atau stack 2 masih kosong apa enggak
int empty(int nomorstack) {
    switch(nomorstack) {
        case 1:
            if(top1 == 0) {
                return true;
            } else {
                return false;
            }
            break;
        case 2:
            if(top2 == MAX + 1) {
                return true;
            } else {
                return false;
            }
            break;
        default: printf("Nomor stack salah");
            break;
    }
}

// Buat hapus semua data stack di dalam array

// Buat push data ke dalam stack array, misalnya ---> push('sesuatu', 1);
// Ini berarti kita push string 'sesuatu' ke stack pertama
void push(char data, int nomorstack) {
    if(!full()) {
        switch(nomorstack) {
            case 1:
                top1++;
                stack[top1] = data;
                break;
            case 2:
                top2--;
                stack[top2] = data;
                break;
            default: printf("\nNomor stack salah");
                break;
        }
    } else {
        printf("\nStack penuh");
    }

}

// Buat pop data stack misal mau pop stack pertama ---> pop(1);
// Kalau mau dicetak tinggal gini ---> std::cout << pop(1);
char pop(int nomorstack) {
    char data;
    if(!empty(nomorstack)) {
        switch(nomorstack) {
            case 1:
                data = stack[top1];
                top1--;
                return data;
                break;
            case 2:
                data = stack[top2];
                top2++;
                return data;
                break;
            default: printf("\nNomor stack salah");
            break;
        }
    } else {
        printf("\nStack masih kosong");
    }

    return 0;
}

// Tampilkan semua data stack di dalam array
void display() {
    if ((top1 = 0) && (top2 = MAX + 1)) { std::cout << "(empty)\n";  return; }
    for (int t = 0 ; t < MAX ; t++) std::cout << stack[t] << " ";
    std::cout << "\n";
}

// Program berjalan
int main() {
    // Inisialisasi stack, yang ini harus jalan dulu
    init();

    // Masukin 'a' ke dalam stack pertama
    push('a', 1);
    // Masukin 'n' ke dalam stack pertama
    push('n', 1);
    // Masukin 'u' ke dalam stack pertama
    push('u', 1);

    // cetak pop dari stack pertama
    std::cout << "Hasil pop stack pertama: " << pop(1) << "\n";

    // cetak array termasuk kedua stack
    display();

    std::cout << "\n";

    // Masukin '*' ke dalam stack kedua, char '*' gak akan masuk karena udah ke pop
    push('*', 2);
    // Masukin 's' ke dalam stack kedua
    push('s', 2);
    // Masukin 'e' ke dalam stack kedua
    push('e', 2);
    // Masukin 'm' ke dalam stack kedua
    push('m', 2);
    // Masukin 'e' ke dalam stack kedua
    push('e', 2);
    // Masukin 'g' ke dalam stack kedua
    push('g', 2);

    // cetak pop dari stack kedua
    std::cout << "Hasil pop stack kedua: " << pop(2) << "\n";
    // cetak array termasuk kedua stack
    display();
    system('cls');

    // exit with no error
    // http://en.wikipedia.org/wiki/Error_code
    return 0;
}
