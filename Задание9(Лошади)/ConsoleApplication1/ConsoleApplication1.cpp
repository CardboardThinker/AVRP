#include "msoftcon.h"
#include "msoftcon.cpp"
#include <iostream>
#include <cstdlib> 
#include <ctime> 
using namespace std;
const int CPF = 5; //Для изображения на экране: длина фурлонга в столбцах
const int maxHorses = 7; //Максимально возможное количество лошадей
class track; //Класс, представляющий скаковой трек (предварительное объявление класса для того, чтобы можно было его использовать в тексте программы раньше, чем он будет определен)
class comtrack; //Предварительное объявление нового класса, представляющего скаковой трек
class horse { //Класс, представляющий бегущую лошадь
protected:
	const track* ptrTrack; //Скаковой трек, по которому бежит лошадь (указатель на константу)
	const int horse_number; //Номер лошади (константа)
	float finish_time; //Время со старта забега до пересечения линии финиша (в секундах)
	float distance_run; //Длина (в фурлонгах) части дистанции, пройденной на данный момент
public:
	horse(const int n, const track* ptrT) : //Конструктор с двумя аргументами: номер лошади, указатель на трек
		horse_number(n),
		ptrTrack(ptrT),
		distance_run(0.0) //Лошадь еще не стартовала
	{ }
	~horse() //Деструктор
	{ }
	void display_horse(const float elapsed_time); //Метод для отображения лошади на экране
};
class comhorse : public horse { //Новый класс, представляющий бегущую лошадь, производный от старого
private:
	const comtrack* ptrTrack; //Скаковой трек (нового класса), по которому бежит лошадь (указатель на константу)
public:
	comhorse(const int n, const comtrack* ptrT) : //Конструктор с двумя аргументами: номер лошади, указатель на трек
		horse(n, NULL), //NULL — означает, что не будет использоваться объект старого класса track,
		ptrTrack(ptrT)  //При этом остальные поля старого класса horse будем использовать
	{ }
	void display_horse(const float elapsed_time); //Прототип, перегруженный метод для отображения лошади на экране
};
class track { //Класс, представляющий скаковой трек
protected:
	horse* hArray[maxHorses]; //Массив указателей на объекты-лошади
	int total_horses; //Общее количество лошадей, участвующих в забеге
	int horse_count; //Счетчик лошадей, обработанных на текущий момент времени (в каждый момент времени нужно вычислять новое положение каждой лошади и отображать эту лошадь на экране; счетчик показывает сколько лошадей уже обработано)
	const float track_length; //Длина трека (в фурлонгах)
	float elapsed_time; //Время, прошедшее со старта забега (в секундах)
public:
	track(float lenT, int nH); //Конструктор с двумя аргументами: длина трека, количество лошадей, участвующих в забеге
	~track(); //Деструктор
	void display_track(); //Метод для отображения трека на экране
	void run(); //Метод для запуска забега
	float get_track_len() const; //Метод для получения длины трека
};
class comtrack : public track { //Новый класс, представляющий скаковой трек, производный от старого
private:
	comhorse* hArray[maxHorses]; //Массив указателей на объекты-лошади
	int horse_count;
public:
	comtrack(float lenT, int nH); //Конструктор с двумя аргументами: длина трека, количество лошадей, участвующих в забеге
	~comtrack(); //Деструктор
	void run(); //Метод для запуска забега
	friend void comhorse::display_horse(float); //Метод display_horse класса comhorse является дружественным
};
void horse::display_horse(float elapsed_time) { //Метод для отображения лошади на экране (elapsed_time — время, прошедшее со старта забега)
	set_cursor_pos(1 + int(distance_run * CPF), 2 + horse_number * 2); 	// установим курсор в нужную позицию на экране: координата Х зависит от длины части дистанции пройденной лошадью на данный момент;координата Y зависит от номера лошади, так как лошади отображаются по порядку сверху вниз
	set_color(static_cast<color>(cBLUE + horse_number)); //Все лошади отображаются разных цветов, цвет зависит от номера лошади
	char horse_char = '0' + static_cast<wchar_t>(horse_number); //Вычисляем символ для отображения номера лошади 
	_putwch(' '); _putwch('\xDB'); _putwch(horse_char); _putwch('\xDB'); //Отображаем лошадь четырьмя символами: пробел, закрашенный прямоугольник, номер лошади, закрашенный прямоугольник (пробел нужен, чтобы стирать предыдущее местонахождение лошади)
	if (distance_run < ptrTrack->get_track_len() + 1.0 / CPF) { // если финиш еще не достигнут
		if (rand() % 3) //Случайным образом генерируем одно из трех чисел: 0 или 1 или 2 в случае генерации 0 лошадь остается на месте, в случае генерации 1 или 2 лошадь продвигается вперед на 0,2 фурлонга
			distance_run += 0.2F;
		finish_time = elapsed_time; //Запоминаем в поле finish_time для текущей лошади время, прошедшее со старта забега
	}
	else { //Финиш достигнут
		int mins = int(finish_time) / 60; //Вывести время, прошедшее со старта забега до пересечения линии финиша, на экран
		int secs = int(finish_time) - mins * 60;
		wcout << L" Время = " << mins << ":" << secs;
	}
}
void comhorse::display_horse(float elapsed_time) { //Перегруженный метод для отображения лошади на экране для нового класса (elapsed_time — время, прошедшее со старта забега)
	set_cursor_pos(1 + int(distance_run * CPF), 2 + horse_number * 2); //Установим курсор в нужную позицию на экране: координата Х зависит от длины части дистанции пройденной лошадью на данный момент;координата Y зависит от номера лошади, так как лошади отображаются по порядку сверху вниз
	set_color(static_cast<color>(cBLUE + horse_number)); //Все лошади отображаются разных цветов, цвет зависит от номера лошади
	wchar_t horse_char = L'0' + static_cast<wchar_t>(horse_number); //Вычисляем символ для отображения номера лошади
	_putwch(L' '); _putwch(L'\xDB'); _putwch(horse_char); _putwch(L'\xDB'); //Отображаем лошадь четырьмя символами: пробел, закрашенный прямоугольник, номер лошади, закрашенный прямоугольник (пробел нужен, чтобы стирать предыдущее местонахождение лошади)
	if (distance_run < ptrTrack->get_track_len() + 1.0 / CPF) { //Если финиш еще не достигнут
		float speed = 0.2F; //Скорость лошади по умолчанию (0.2 фурлонга за тик)
		if (distance_run >= ptrTrack->get_track_len() / 3) { //Если лошадь прошла 1/3 или больше общей длины трека
			if (ptrTrack->total_horses > 1) { //Если в гонке участвует больше одной лошади
				int Ld, Sc; //Номера лошадей: лидера и идущей второй
				if (ptrTrack->hArray[0]->distance_run < ptrTrack->hArray[1]->distance_run) //Сначала возьмем в качестве лидера и идущей второй
				{
					Ld = 1; Sc = 0; //Первые две лошади из массива (номера этих лошадей 0 и 1)
				}
				else
				{
					Ld = 0; Sc = 1;
				}
				for (int j = 2; j < ptrTrack->total_horses; j++) { //Просмотрим массив указателей на объекты-лошади, начиная с лошади под номером 2
					if (ptrTrack->hArray[Ld]->distance_run < ptrTrack->hArray[j]->distance_run) {
						Sc = Ld; Ld = j;
					}
					else if (ptrTrack->hArray[Sc]->distance_run < ptrTrack->hArray[j]->distance_run) {
						Sc = j;
					}
				}
				if (distance_run == ptrTrack->hArray[Ld]->distance_run || distance_run == ptrTrack->hArray[Sc]->distance_run) { //Если наша лошадь является лидером или идущей второй (сравниваем не номера, а пройденные дистанции, из-за того, что несколько лошадей могут идти вровень)
					if (ptrTrack->hArray[Ld]->distance_run - ptrTrack->hArray[Sc]->distance_run <= 0.1F) //И расстояние между лидером и идущей второй не превышает 0.1 фурлонга
						speed = 0.3F; //Временно ускорим нашу лошадь с 0.2 до 0.3 фурлонга за тик
				}
			}
		}
		if (rand() % 3) //Случайным образом генерируем одно из трех чисел: 0 или 1 или 2 в случае генерации 0 лошадь остается на месте, в случае генерации 1 или 2 лошадь продвигается вперед на количество фурлонгов, указанное в переменной speed
			distance_run += speed;
		finish_time = elapsed_time; //Запоминаем в поле finish_time для текущей лошади время, прошедшее со старта забега
	}
	else { //Финиш достигнут
		int mins = int(finish_time) / 60; //Вывести время, прошедшее со старта забега до пересечения линии финиша, на экран
		int secs = int(finish_time) - mins * 60;
		cout << " Время = " << mins << ":" << secs;
	}
}
track::track(float lenT, int nH) : //Конструктор с двумя аргументами: длина трека, количество лошадей, участвующих в забеге
	track_length(lenT), //Длина трека
	total_horses(nH), //Количество лошадей, участвующих в забеге
	horse_count(0), //На треке еще нет лошадей
	elapsed_time(0.0) //Забег еще не стартовал
{
	init_graphics(); //Инициализация консольной графики
	total_horses = (total_horses > maxHorses) ? maxHorses : total_horses; //Количество лошадей не может быть больше указанного в константе maxHorses
	for (int j = 0; j < total_horses; j++) //Создать объекты класса horse и заполнить массив указателей на них
		hArray[j] = new horse(horse_count++, this);
	time_t aTime; //Инициализировать генерацию случайных чисел, исходя из текущего системного времени
	srand(static_cast<unsigned>(time(&aTime)));
	display_track(); //Отобразить сконструированный трек на экране
}
comtrack::comtrack(float lenT, int nH) : //Конструктор с двумя аргументами: длина трека, количество лошадей, участвующих в забеге (для трека нового класса)
	track(lenT, nH), horse_count(0)
{
	for (int j = 0; j < total_horses; j++) //Создать объекты нового класса comhorse и заполнить массив указателей на них
		hArray[j] = new comhorse(horse_count++, this);
}
track::~track() //Деструктор
{
	for (int j = 0; j < total_horses; j++) //Освободить память, выделенную в конструкторе под объекты-лошади
		delete hArray[j];
}
comtrack::~comtrack() //Деструктор (для трека нового класса)
{
	for (int j = 0; j < total_horses; j++) //Освободить память, выделенную в конструкторе под объекты-лошади нового класса
		delete hArray[j];
}
void track::display_track() //Метод для отображения трека на экране
{
	clear_screen(); //Очистить экран
	//Отобразить трек
	for (int f = 0; f <= track_length; f++) //Цикл столбцов (фурлонгов)
		for (int r = 1; r <= total_horses * 2 + 1; r++) { //Цикл экранных строк (рядов)
			set_cursor_pos(f * CPF + 5, r);  //Установим курсор в нужное место
			if (f == 0 || f == track_length) //Если это начало или конец трека
				cout << '!'; //Рисуем стартовую или финишную линию
			else                         
				cout << '|'; //Иначе рисуем отметку очередного фурлонга
		}
}
void track::run() //Метод для запуска забега
{
	while (!_kbhit()) { //Продолжать цикл до момента нажатия любой клавиши на клавиатуре
		elapsed_time += 1.75; //Увеличиваем время забега на 1,75 секунд
		for (int j = 0; j < total_horses; j++) // обрабатываем очередное движение каждой лошади
			hArray[j]->display_horse(elapsed_time);
		wait(500); //Функция из msoftcon.h, пауза на 500 миллисекунд
	}
	_getwch(); //Принять символ с клавиатуры, возникший из-за нажатия на клавишу
	cout << endl;
}
void comtrack::run() //Метод для запуска забега (для трека нового класса)
{
	while (!_kbhit()) { //Продолжать цикл до момента нажатия любой клавиши на клавиатуре
		elapsed_time += 1.75; //Увеличиваем время забега на 1,75 секунд
		for (int j = 0; j < total_horses; j++) //Обрабатываем очередное движение каждой лошади (нового класса)
			hArray[j]->display_horse(elapsed_time);
		wait(500); 	//Функция из msoftcon.h, пауза на 500 миллисекунд
	}
	_getwch(); //Принять символ с клавиатуры, возникший из-за нажатия на клавишу
	cout << endl;
}
float track::get_track_len() const //Метод для получения длины трека
{
	return track_length;
}
int main() {
	setlocale(LC_ALL, "Russian");
	float length; //Длина трека (дистанции)
	int total; //Количество лошадей, участвующих в забеге
	cout << "Введите длину дистанции (от 1 до 12 фурлонгов): "; //Получаем данные для забега от пользователя
	cin >> length;
	cout << "Введите количество лошадей (от 1 до 7): "; 
	cin >> total;
	comtrack theTrack(length, total); //Создаем трек
	theTrack.run(); //Запускаем забег
	cout << endl;
	return 0;
}

