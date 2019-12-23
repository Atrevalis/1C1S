#include <iostream>
#include <fstream>
#include <cmath>
int dimA;//по возможности заменить функцией
int dimB;//
using namespace std;
int** consoleInsert(bool check,int **&array, char symbol);
int** fileInsert(bool check,int **&array, char symbol);
void editArray(bool check,int **&array);
void fileOutput(bool check, int **&array, int dim);
void consoleOutput(bool check, int **&array, int dim);
int** calculate(int **&arrayA,int **&arrayB, bool checkA,bool checkB);

int main() {
    char A = 'A';//symbol
    char B = 'B';//symbol
    char f;//номер функции
    bool exit = false;// выход Д/Н
    int ins;//номер матрицы
    int **arrayA;
    int **arrayB;
    bool checkA = false;//чекер заполнения массива А
    bool checkB = false;//чекер заполнения массива Б
    while(!exit){
        cout<<"Выберите дальнейшее действие:"<<"\n";
        cout<<"1:Ввод матрицы "<<"\n";
        cout<<"2:Вывод матрицы "<<"\n";
        cout<<"3:Редактирование матрицы "<<"\n";
        cout<<"4:Перемножение матриц "<<"\n";
        cout<<"5:Завершение программы "<<"\n";
        cin>>f;
        switch(f){
            case '1':
                cout<<"Выберите какую матрицу вы будете вводить:"<<"\n";
                cout<<"1:A"<<"\n"<<"2:Б"<<"\n"<<"Чтобы вернутся в меню введите любое значение кроме предложенных"<<"\n";
                cin>>ins;//ПОПРАВИТЬ ОШИБКУ С ВВОДОМ НЕ ЧИСЕЛ
                switch(ins){
                    case 1:
                        cout<<"Выберите каким способом вы будете заполнять матрицу"<<"\n"<<"1:Консоль"<<"\n"<<"2:Файл"<<"\n";
                        cout<<"Чтобы вернутся в меню введите любое значение кроме предложенных"<<"\n";
                        cin>>(ins);//ПОПРАВИТЬ ОШИБКУ С ВВОДОМ НЕ ЧИСЕЛ
                        switch(ins){
                            case 1: arrayA = consoleInsert(checkA,arrayA,A);
                                checkA = true;
                                break;
                            case 2: arrayA = fileInsert(checkA,arrayA,A);//ADD ARRAY C
                                checkA = true;
                                break;
                            default:break;
                        }
                        break;
                    case 2:
                        cout<<"Выберите каким способом вы будете заполнять матрицу"<<"\n"<<"1:Консоль"<<"\n"<<"2:Файл"<<"\n";
                        cout<<"Чтобы вернутся в меню введите любое значение кроме предложенных"<<"\n";
                        cin>>(ins);//ПОПРАВИТЬ ОШИБКУ С ВВОДОМ НЕ ЧИСЕЛ
                        switch(ins){
                            case 1: arrayB = consoleInsert(checkB,arrayB,B);
                                checkB = true;
                                break;
                            case 2: arrayB = fileInsert(checkB,arrayB,B);//ADD ARRAY C
                                checkB = true;
                                break;
                            default:break;
                        }
                        break;
                    default:break;//заглушка
                }
                break;
            case '2':
                cout<<"Выберите, какую матрицу вы хотите вывести"<<"\n"<<"1:А"<<"\n"<<"2:Б"<<"\n";
                cin>>(ins);
                switch(ins){
                    case 1:
                        cout<<"Выберите каким способом вы будете выводить матрицу"<<"\n"<<"1:Консоль"<<"\n"<<"2:Файл"<<"\n";
                        cout<<"Чтобы вернутся в меню введите любое значение кроме предложенных"<<"\n";
                        cin>>(ins);//ПОПРАВИТЬ ОШИБКУ С ВВОДОМ НЕ ЧИСЕЛ
                        switch(ins){
                            case 1:
                                consoleOutput(checkA,arrayA,dimA);
                                break;
                            case 2:
                                fileOutput(checkA,arrayA,dimA);
                                break;
                        }
                        break;
                    case 2:
                        cout<<"Выберите каким способом вы будете выводить матрицу"<<"\n"<<"1:Консоль"<<"\n"<<"2:Файл"<<"\n";
                        cout<<"Чтобы вернутся в меню введите любое значение кроме предложенных"<<"\n";
                        cin>>(ins);//ПОПРАВИТЬ ОШИБКУ С ВВОДОМ НЕ ЧИСЕЛ
                        switch(ins){
                            case 1:
                                consoleOutput(checkB,arrayB,dimB);
                                break;
                            case 2:
                                fileOutput(checkB,arrayB,dimB);
                                break;
                        }
                        break;
                    default:
                        break;
                }
                break;
            case '3':
                cout<<"Выберите, какую матрицу вы хотите отредактировать"<<"\n"<<"1:А"<<"\n"<<"2:Б"<<"\n";
                cin>>(ins);
                switch(ins) {
                    case 1:
                        editArray(checkA, arrayA);
                        break;
                    case 2:
                        editArray(checkB, arrayB);
                        break;
                    default:
                        break;
                }
            case '4': break;
            case '5':
                exit = true;
                cout<<"ОКОНЧАНИЕ РАБОТЫ ПРОГРАММЫ";
                break;
            default:
                cout<<"Введено неправильное значение. Попробуйте еще раз"<<"\n";
                break;
        }
    }
}

void consoleOutput(bool check, int **&array, int dim) {//DONE
    if (check) {
        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                cout << array[i][j]<<" ";
            }
           cout <<"\n";
        }
    }else{cout<<"Массива не существует"<<"\n";}
}

void fileOutput(bool check, int **&array, int dim){//DONE
    if (check) {
        ofstream matrix;
        bool  exit=false;
        string path;
        while(!exit) {
            cout<<"Введите путь файла"<<"\n";
            cin>>path;
            matrix.open(path);
            if (matrix.is_open()) {
                for(int i=0;i<dim;i++){
                    for(int j=0;j<dim;j++){matrix<<array[i][j]<<" ";}
                    matrix<<"\n";
                }
                exit = true;
            } else {cout << "Файл не был найден, попробуйте еще раз" << "\n"; }
        }
        matrix.close();
    } else{cout<<"Массива не существует"<<"\n";}
}

int** consoleInsert(bool check,int **&array,char symbol){//DONE
    if(check){delete[] array;}
    int dim;
    cout<<"Введите размерность квадратной матрицы"<<"\n";
    cin>>dim;//ПОПРАВИТЬ ОШИБКУ С ВВОДОМ НЕ ЧИСЕЛ
    if(symbol == 'A'){ dimA = dim;}
    if(symbol == 'B'){ dimB = dim;}
    array = new int*[dim];//создание строк
    for(int i = 0;i<dim;i++){array[i]=new int[dim];}//создание столбцов
    cout<<"Введите матрицу размерностью "<<dim<<"X"<<dim<<"\n";
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            cin>>array[i][j];
        }
    }
    return array;
}
int** fileInsert(bool check,int **&array,char symbol){//DONE
    if(check){delete[] array;}
    bool  exit=false;
    string path;
    ifstream matrix;
    while(!exit) {
        cout<<"Введите путь файла"<<"\n";
        cin>>path;
        matrix.open(path);
        if (matrix.is_open()) {
            matrix.seekg(0, ios_base::end);
            int dim = (int) sqrt((double) matrix.tellg()/2);//нахождение размерности
            matrix.seekg(0, ios_base::beg);
            if(symbol == 'A'){ dimA = dim;}
            if(symbol == 'B'){ dimB = dim;}
            array = new int*[dim];//создание строк
            for(int i = 0;i<dim;i++){array[i]=new int[dim];}//создание столбцов
            for(int i=0;i<dim;i++){
                for(int j=0;j<dim;j++){
                    matrix>>array[i][j];
                }
            }
            exit = true;
        } else {cout << "Файл не был найден, попробуйте еще раз" << "\n"; }
    }
    matrix.close();
    return array;
}
void editArray(bool check,int **&array){//DONE
    int column;
    int line;
    char trigger;
    bool exit = false;
    if(check) {
        while (!exit) {
            cout <<"Выберите элемент, который вы хотите изменить" << "\n";
            cout <<"+===========================================+"<< "\n";
            cout << "Введите строку в которой содержится элемент" << "\n";
            cin >> line;
            cout << "Введите столбец в котором содержится элемент" << "\n";
            cin >> column;
            cout << "Введите новое значение " << "\n";
            cin >> array[--line][--column];
            cout << "Продолжить изменение массива? Y/N"<< "\n";
            cin >> trigger;
            if ((trigger == 'N') or (trigger == 'n')) { exit = true; }
        }
    } else{cout<<"Массива не существует"<<"\n";}
}
int** calculate(int **&arrayA,int **&arrayB, bool checkA,bool checkB){

}

