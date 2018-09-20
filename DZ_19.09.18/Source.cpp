#include <iostream>
#include <string>
#include<fstream>

using namespace std;
ifstream my_file;
int flat_number = 0;
int fn_buffer = 0;
int buf_size = 0, curr_size = 0;
//Разработайте структуру «Квартира» (номер квартиры, кол-во комнат, общая площадь). Разработайте структуру «Дом» (номер, кол-во квартир, массив квартир). 

struct flat
{
	int number1;
	int room_number;
	int area;
	void enter()
	{
		cout << "Введите номер квартиры, количество комнат и их площадь: ";
		cin >> number1 >> room_number >> area;
	}

	void print()
	{
		cout << "Номер квартиры: " << number1 << " Количество комнат: " << room_number << " Площадь: " << area;
	}
};

struct home
{
	int number;
	
	flat *flats;	


	void add(flat f)
	{
		if (fn_buffer == 0)
		{
			fn_buffer = 2;
			flats = new flat[fn_buffer];
			flats[flat_number++] = f;
		}
		else
		{
			if (flat_number < fn_buffer)
			{
				flats[flat_number++] = f;
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
	
	void erase(flat f)
	{
		
		int choice;
		int index;
		string poisk;
		cout << "Введите 1 для удаления по номеру квартиры или 2 для удаления по количеству комнат" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cin >> poisk;
			for (int i = 0; i < flat_number; i++)
			{
				if (strstr(f[i].number1.c_str(), poisk.c_str()))
				{
					index = i;
					break;
				}
			}
		}
		break;
		case 2:
		{
			cin >> poisk;
			for (int i = 0; i < flat_number; i++)
			{
				if (strstr(f[i].room_number.c_str(), poisk.c_str()))
				{
					index = i;
					break;
				}
			}
		}
		break;

		for (int i = 0; i < flat_number - 1; i++)
		{
			f[i] = f[i + 1];
		}
		flat_number--;
		}
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
	string name1 = "free";
	string poisk;
	cin >> poisk;
	for (int i = 0; i < curr_size; i++)
	{

		if (strstr(flat_num[i].number.c_str(), poisk.c_str()))
		{

		}

	}
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
		cout << "Разработайте структуру «Квартира» (номер квартиры, кол-во комнат, общая площадь). Разработайте структуру «Дом» (номер, кол-во квартир, массив квартир). Создайте экземпляр структуры  и реализуйте для него следующие функции: \n •	Печать всех квартир \n • Добавление квартиры \n • Удаление квартиры	" << endl;

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

		ehome.print();
		ehome.empty();
		ehome.erase(f);


	}
	else if (n==2)
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

		delete[]f;
	}

	goto start;
	system("pause");
	return 0;
}
