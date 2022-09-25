#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;

class Player
{
public:
	Player(int score, string name)
	{
		this->_score = score;
		this->_name = name;
	}
	int _score;
	string _name;
};

void createPlayer(vector<Player>& v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nameSeed[i];
		Player p(0, name);
		v.push_back(p);
	}
}

void grade(vector<Player>& v)
{
	for (vector<Player>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			int s = rand() % 41 + 60;
			d.push_back(s);
		}
		sort(d.begin(), d.end());

		d.pop_back();
		d.pop_front();

		int sum = 0;
		for (int i = 0; i < d.size(); i++)
		{
			sum += d[i];
		}
		sum /= d.size();
		(*it)._score = sum;
	}
}

void show(const vector<Player>& v)
{
	for (vector<Player>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		cout << it->_name << "，平均分：" << it->_score << endl;;
	}
}

int main()
{
	vector<Player> v;
	createPlayer(v);
	grade(v);
	show(v);

	system("pause");
	return 0;
}