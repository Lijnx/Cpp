#include <iostream>
#include <string>
using namespace std;

#define N 3

int max(int* score, int n)
{
	int i, k, mx;
	mx = score[0];
	k = 0;
	for (i = 1; i < n; i++)
		if (score[i] > mx)
		{
			mx = score[i];
			k = i;
		}
	return k;
}

int main()
{
	setlocale(LC_ALL, "russian");

	int i;
	struct team
	{
		string name;
		string city;
		int score;
	} teams[N];
	int scores[N];

	for (i = 0; i < N; i++)
	{
		cout << "Команда " << i << endl;
		cout << "Введите название: ";
		cin >> teams[i].name;;
		cout << "Введите город: ";
		cin >> teams[i].city;
		cout << "Введите кол-во очков: ";
		cin >> teams[i].score;
		scores[i] = teams[i].score;
		cout << endl;
	}

	int k = max(scores, N);
	cout << "Команда с максимумом очков:" << endl;
	cout << teams[k].name << endl;
	cout << teams[k].city << endl;
	cout << teams[k].score << endl;

	return 0;
}