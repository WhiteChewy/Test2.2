#include <iostream>
#include <vector>
const int size = 10;

using namespace  std;

class Queue {

private:
	
	unsigned int top;   //позиция верхнего элемента
	unsigned int bottom;//позиция последнего элемента
	unsigned int size;  //размер буфера
	unsigned int real_size; //количество элементов в буфере

public:
	
	vector<int> buff;

	//конструктор
	Queue(unsigned int n){
		top = 0;
		bottom = 0;
		size = 0;
		buff.reserve(n);
		for (int i = 0; i < n; i++) {
			buff.push_back(0);
			size++;
		}
	}

	//добавление элемента в буфер
	void Enqueue(int n) {
		if (bottom < size) {
			buff[bottom] = n;
			bottom += 1;
		}
		else {
			buff[0] = n;
			bottom = 1;
		}
		if (real_size < size) {
			real_size++;
		}
		else {
			real_size = 10;
		}
	}

	//удаление элемента из буфера
	int Dequeue() {
		int deleted;
		if (top < size) {
			deleted = buff[top];
			buff[top] = 0;
			top++;
		}
		else {
			deleted = buff[top];
			buff[top] = 0;
			top = 0;
		}
		if (real_size > 0) {
			real_size--;
		}
		else {
			real_size = 0;
		}
		return deleted;
	}
	
	//значение верхнего элемента
	int Top(){
		if (top == size) {
			top = 0;
		}
		return buff[top];
	}
	
	//размер буфера
	int Size() {
		return buff.size();
	}

	//флаг пустого буфера
	bool isEmpty() {
		if (real_size == 0) { return true; }
		else return false;
	}


};

int main() {
	int c = 0;
	Queue Buffer(10);
	setlocale(LC_ALL, "Russian");
	cout << "========= Проверка буфера ==========";
	
	for (int i = 0; i < 10; i++) {
		Buffer.Enqueue(i+1);
	}
	for (int i = 0; i < 3; i++) {
			cout << "\n Удаляю элемент [" << i+1 << "] " << Buffer.Top();
			Buffer.Dequeue();
	}
	for (int i = 0; i < 10; i++) {
		cout << "\nЭлемент [" << i + 1 << "] " << Buffer.Top();
		Buffer.Dequeue();
	}
	if (Buffer.isEmpty()) { cout << "\nБуффер пуст!"; }
	return 0;
}