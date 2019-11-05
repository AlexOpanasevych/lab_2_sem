/* ----------------------------------------------------------------<Header>-
 Name: 5.cpp
 Title: Задача 2.5.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-22
 Revised: 
 Description:  Создайте класс с циклической очередью целых (см. Unit 2 "A more practical example").
Сделайте очередь длиной 100 целых. В функцию main() включите краткую демонстрацию ее
работы.
Провести инициализацию с помощью конструктора.
(при желании можете раскомментировать цикл, который показывает работу циклической очереди)
 ------------------------------------------------------------------</Header>-*/

#include <iostream>
using namespace std;

class qType{
    private:    
        int size, index;
        int head, tail;
        int *queue;
    public:
        qType(int size);
        ~qType();
        //void init(int size); // инициализация
        void q(int); // запоминание
        int deq();
};

qType::qType(int size){
    this->size = size;
    queue = new int[size];
    index = 0;
    head = 0;
    tail = 0;
}

qType::~qType(){
    delete[] queue;
}

void qType::q(int num){
    if(index > size){
        cout << "Queue is full"<< endl;
    }
    else{
        queue[tail] = num;
        if (tail+1<size) tail++;
        else tail = 0;
        index++;
    }
}

int qType::deq(){
    if(index>0){
        if(head+1<size){
            head++;
            index--;
            return queue[head-1];
         }
        else{
            int p = head;
            head = 0;
            index--;
            return queue[p];
            }
        }
}

int main(){
    qType qtype(100);
    //qtype.init(100);
    qtype.q(1);
    qtype.q(2);
    qtype.q(3);
    cout << qtype.deq() << endl;
    cout << qtype.deq() << endl;
    /*for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++)
            qtype.q(j);
        for(int j = 0; j < 100; j++)
            cout<< qtype.deq()<<endl;
    }*/
    return 0;
}