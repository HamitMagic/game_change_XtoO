#include <iostream>

using namespace std;

void fill_array(const int &size, string *field) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            field[i][j] = 'X';
        }
    }
}

void print(const int &size, string *field) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
}

void change_one_cell(string *field, const int &x, const int &y){
    if (field [x][y] == 'X') field [x][y] = 'O';
    else field [x][y] = 'X';
}

void change_cells(const int &size, string *field, const int &x, const int &y) {
    change_one_cell(field, x, y);
    
    if (x-1 >= 0) {
        change_one_cell(field, x-1, y);
    }
    if (x+1 < size){
        change_one_cell(field, x+1, y);
    }
    if (y-1 >= 0){
        change_one_cell(field, x, y-1);
    }
    if (y+1 < size){
        change_one_cell(field, x, y+1);
    }
    print(size, field);
}

bool exit(const string *field, const int &size){
    for (int i = 0; i < size;  i++){
        for (int j = 0; j < size; j++){
            if (field[i][j] == 'X') {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int size;
    cout << "Введите число обозначающее сторону квадратного поля: ";
    cin >> size;
    string field[size];
    fill_array(size, field);
    cout << "Ваше текущее поле:" << endl;
    print(size, field);
    int input;
    while (exit(field, size)) {
        cout << "Введите двухзначное чило (от 00 до 99) для изменеия поля: ";
        cin >> input;
        int y = input%10;
        int x = input/10;
        change_cells(size, field, x, y);
    }
    cout << "ВАУ, да вы гений" << endl;


    return 0;
}