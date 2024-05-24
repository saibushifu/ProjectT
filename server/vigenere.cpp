#include "vigenere.h"

QString Encrypt(QString Input, QString Key){ // функция шифрования строки шифром виженера, возвращает QString
    Input = Input.toUpper();
    Key = Key.toUpper();
    QString Output;
    int Key_Number = 0;
    QString Alphabet = ("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    int N = (Alphabet.length());
    int Ki = -1;
    int Pi = -1;

    for(int i =0; i< (Input.length());i++){
        if (Input.at(i).isLetter()){

            //Поиск i-той буквы слова в алфавите
            for(int k =0; k < N; k++){
                if(Alphabet.at(k) == Input.at(i)){
                    Pi = k;
                    break;
                }
            }
            if (Pi == -1) return "Ошибка. Убедитесь в правильности выбора алфавита.";
            //Поиск i-той буквы ключа в алфавите
            for(int j = 0;j < N;j++){
                if(Alphabet.at(j) == Key.at(Key_Number)){
                    if(Key_Number == (Key.length()-1)) Key_Number=0;
                    else Key_Number++;
                    Ki =j;
                    break;
                }
            }
            if (Ki == -1) return "Ошибка. Убедитесь в правильности выбора алфавита.";
            //Формула: Ci = (Pi+Ki)mod N, где Pi - порядковый номер i-той буквы слова в алфавите, Ci - порядковый номер i-той буквы ключа, N - мощность алфавита
            Output.append(Alphabet.at((Pi+Ki)%N));

        }
        //Знаки, которые не являются буквами, не шифруются
        else Output.append(Input.at(i));
    }
    return Output;
}




QString Decrypt(QString Input, QString Key){ // функция дешифрования строки шифром виженера, возвращает QString
    Input = Input.toUpper();
    Key = Key.toUpper();
    QString Output;
    int Key_Number = 0;
    QString Alphabet = ("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    int N = (Alphabet.length());
    int Ki = -1;
    int Ci = -1;

    for(int i =0; i< (Input.length());i++){
        if (Input.at(i).isLetter()){

            //Поиск i-той буквы зашифрованного слова в алфавите
            for(int k =0; k < N; k++){
                if(Alphabet.at(k) == Input.at(i)){
                    Ci = k;
                    break;
                }
            }
            if (Ci == -1) return "Ошибка. Убедитесь в правильности выбора алфавита.";
            //Поиск i-той буквы ключа в алфавите
            for(int j = 0;j < N;j++){
                if(Alphabet.at(j) == Key.at(Key_Number)){
                    if(Key_Number == (Key.length()-1)) Key_Number=0;
                    else Key_Number++;
                    Ki =j;
                    break;
                }
            }
            if (Ki == -1) return "Ошибка. Убедитесь в правильности выбора алфавита.";
            //Формула: Pi = (Ci-Ki+N)mod N, где Pi - порядковый номер i-той буквы слова в алфавите, Ci - порядковый номер i-той буквы ключа, N - мощность алфавита
            Output.append(Alphabet.at((Ci-Ki+N)%N));
        }
        //Знаки, которые не являются буквами, не шифруются
        else Output.append(Input.at(i));
    }
    return Output;
}