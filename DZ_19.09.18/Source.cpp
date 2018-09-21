#include <iostream>
#include <string>
#include<fstream>

using namespace std;
ifstream my_file;
int flat_number = 0;
int fn_buffer = 0;
int x = 0;
int buf_size = 0, curr_size = 0;
//Разработайте структуру «Квартира» (номер квартиры, кол-во комнат, общая площадь). Разработайте структуру «Дом» (номер, кол-во квартир, массив квартир). 

struct flat
{
	int number;
	int room_number;
	double area;
	void enter()
	{
		cout << "Введите номер квартиры, количество комнат и их площадь: ";
		cin >> number >> room_number >> area;
	}
	void print()
	{
		cout << "Номер квартиры: " << number << " Количество комнат: " << room_number << " Площадь: " << area;
	}
};

struct home
{
	int number;	
	flat *flats;

	void del() {

		int numb;
		cout << "введите номер квартиры для удаления = ";
		cin >> numb;

		flat *tmp;
		int k = 0;

		for (int i = 0; i < flat_number; i++)
		{
			if (flats[i].number == numb) {
				k = i;

				tmp = new flat[flat_number - 1];

				for (int j = 0, z = 0; j < flat_number - 1; j++, z++)
				{
					if (j < k) tmp[j] = flats[j]; else {
						z++;
						tmp[j] = flats[z];
					}
				}

				delete[]flats;

				flats = tmp;
				flat_number--;
				break;
			}
		}
	}

	void add(flat f)
	{
		if (fn_buffer == 0)
		{
			fn_buffer = 2;
			flats = new flat[fn_buffer];
			flats[flat_number++] = f;
			x = flat_number;
		}
		else
		{
			if (flat_number < fn_buffer)
			{
				flats[flat_number++] = f;
				x = flat_number;
			}
			else
			{
				flat* tmp = new flat[fn_buffer * 2];
				for (int i = 0; i < fn_buffer; i++)
				{
					tmp[i] = flats[i];
				}

				delete[] flats;
				flats = tmp;
				fn_buffer *= 2;
				flats[flat_number++] = f;
				x = flat_number;

			}
		}

	}
	void enter()
	{
		cout << "Номер дома: ";
		cin >> number;
	}

	void print()
	{

		cout << "Номер дома :" << number << endl;
		for (int i = 0; i < flat_number; i++)
		{
			flats[i].print();
			cout << endl;
		}
	}
	void empty()
	{
		delete[] flats;
	}
};
//Разработайте приложение «Фирма риелторов». Разработайте структуру «Квартира» (номер квартиры, кол-во комнат, общая площадь, стоимость, продана/свободна/забронирована).

struct flat1
{
	int number;
	int room_number;
	int area;
	int cost;
	string inf;

	void enter()
	{
		my_file >> number >> room_number >> area >> cost >> inf;
	}
	void print()
	{
		cout << number << " " << room_number << " " << area << " " << cost << " " << inf << endl;
	}
	void enter1()
	{
		cin >>number>> room_number >> area >> cost >> inf;
	}
};

void add(flat1*& flat_num, flat1 a)
{
	if (buf_size == 0)
	{
		buf_size = 2;
		flat_num = new flat1[buf_size];
	}
	else
	{
		if (curr_size >= buf_size)
		{
			flat1* tmp = new flat1[buf_size * 2];
			for (int i = 0; i < buf_size; i++)
			{
				tmp[i] = flat_num[i];
			}
			delete[] flat_num;
			flat_num = tmp;
			buf_size *= 2;
		}
	}
	flat_num[curr_size++] = a;
}
void print_sold_flat(flat1* flat_num)
{
	string name1 = "sold";
	for (int i = 0; i < curr_size; i++)
	{
		if (flat_num[i].inf == name1)
			flat_num[i].print();
	}
}
void print_free_flat(flat1* flat_num)
{
	string name1 = "free";
	for (int i = 0; i < curr_size; i++)
	{
		if (flat_num[i].inf == name1)
			flat_num[i].print();
	}
}
void print_booked_flat(flat1* flat_num)
{
	string name1 = "booked";
	for (int i = 0; i < curr_size; i++)
	{
		if (flat_num[i].inf == name1)
			flat_num[i].print();
	}
}
void profit(flat1* flat_num)
{
	string name1 = "sold";
	int sum = 0;
	for (int i = 0; i < curr_size; i++)
	{
		if (flat_num[i].inf == name1)

		{
			flat_num[i].print();
			sum += flat_num[i].cost;
		}

	}
	cout << "Сумма прибыли проданных квартир: " << sum << endl;

}

void book_flat(flat1* flat_num)
{
	
	int poisk;
	cin >> poisk;
	for (int i = 0; i < curr_size; i++)
	{

		if (flat_num[i].number == poisk)
		{
			flat_num[i].inf = "booked";
			flat_num[i].print();
		}
	}
}
void sold_flat(flat1* flat_num)
{
	
	int poisk;
	cin >> poisk;
	for (int i = 0; i < curr_size; i++)
	{

		if (flat_num[i].number == poisk)
		{
			flat_num[i].inf = "sold";
			flat_num[i].print();
		}
	}
}
void change(flat1* flat_num)
{
	int poisk;
	int choice;
	int k;
	cin >> poisk;
	for (int i = 0; i < curr_size; i++)
	{
		if (flat_num[i].number == poisk)
		{
			flat_num[i].print();
			
		}
	}
	for (int i = 0; i < curr_size; i++)
	{
		if (flat_num[i].number == poisk)
		{
			flat_num[i].enter1();	
			break;
		}
		
	}
	cout << endl;
	for (int i = 0; i < curr_size; i++)
	{
		flat_num[i].print();

	}
	cout << endl;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	my_file.open("in.txt", ios::in);
	int n = 0;
start:
	cout << "Введите номер задания: " << endl;
	cin >> n;
	if (n == 1)
	{
		cout << "Разработайте структуру «Квартира» (номер квартиры, кол-во комнат, общая площадь). Разработайте структуру «Дом» (номер, кол-во квартир, массив квартир). Создайте экземпляр структуры  и реализуйте для него следующие функции: \n - Печать всех квартир \n - Добавление квартиры \n - Удаление квартиры" << endl;

		home ehome;
		flat f;
		ehome.enter();
		int choice;
		bool flag = false;
		while (true)
		{
			cout << "Введите 1 для добавления новой квартиры, 0 - чтобы прервать ввод. " << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				f.enter();
				ehome.add(f);
			}
			break;
			default:
				flag = true;
				break;
			}
			if (flag) break;

		}
		int n;

		while (true)
		{
			cout << "1.печать\n 3.удалить\n";
			cin >> n;
			switch (n)
			{
			case 1:	ehome.print();
				break;
			case 2: ehome.empty();
				break;
			case 3: ehome.del();
				break;
			}
		}
	}
	else if (n == 2)
	{
		cout << "Разработайте приложение «Фирма риелторов». Разработайте структуру «Квартира» (номер квартиры, кол-во комнат, общая площадь, стоимость, продана/свободна/забронирована). Создайте массив из 10 квартир." << endl;
		flat1 f1;
		flat1* f = new flat1;
		int t;
		my_file >> t;
		for (int i = 0; i < t; i++)
		{
			f1.enter();
			add(f, f1);
		}
		for (int i = 0; i < curr_size; i++)
		{
			f[i].print();
		}
		cout << endl;
		cout << "Проданные квартиры: " << endl;
		print_sold_flat(f);
		cout << endl;
		cout << "Свободные квартиры: " << endl;
		print_free_flat(f);
		cout << endl;
		cout << "Забронированные квартиры: " << endl;
		print_booked_flat(f);
		cout << endl;
		profit(f);
		cout << endl;
		book_flat(f);
		cout << endl;
		sold_flat(f);
		cout << endl;
		change(f);
		cout << endl;

		delete[]f;
	}

	goto start;
	system("pause");
	return 0;
}
