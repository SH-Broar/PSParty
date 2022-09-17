#include <Windows.h>
#include <iostream>
#include <thread>
#include <vector>
#include <string>
using namespace std;

volatile int sum;

void f()
{
	for (int i = 0; i < 25000; ++i)
	{
		sum += 1;
	}
}

int main()
{

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> randomContainer;
	randomContainer.resize(25);

	while (true)
	{
		sum = 0;

		thread t1{ f };
		thread t2{ f };
		thread t3{ f };
		thread t4{ f };

		t1.join();
		t2.join();
		t3.join();
		t4.join();

		randomContainer[sum % 25]++;
		
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
		for (int i=0;i<randomContainer.size();++i)
		{
			cout << i << " : " << randomContainer[i] << "\n";
		}
	}

	
}