#include <iostream>
#include <array>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	//array<array<int, 8>,8> edges;
	//{
	//	edges[0][1] = 1;
	//	edges[0][2] = 1;
	//	edges[1][2] = 1;
	//	edges[1][3] = 1;
	//	edges[2][3] = 1;
	//	edges[2][4] = 1;
	//	edges[3][4] = 1;
	//	edges[3][5] = 1;
	//	edges[4][5] = 1;
	//	edges[4][6] = 1;
	//	edges[5][7] = 1;
	//	edges[6][7] = 1;
	//	edges[1][0] = 1;
	//	edges[2][0] = 1;
	//	edges[2][1] = 1;
	//	edges[3][1] = 1;
	//	edges[3][2] = 1;
	//	edges[4][2] = 1;
	//	edges[4][3] = 1;
	//	edges[5][3] = 1;
	//	edges[5][4] = 1;
	//	edges[6][4] = 1;
	//	edges[7][5] = 1;
	//	edges[7][6] = 1;
	//}
	array<int, 8> prevroutes{1,0,0,0,0,0,0,0};
	array<int, 8> routes{1,0,0,0,0,0,0,0};

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		routes[0] = (prevroutes[1] + prevroutes[2]) % 1000000007;
		routes[1] = (((prevroutes[0] + prevroutes[2]) % 1000000007) + (prevroutes[3] % 1000000007)) % 1000000007;
		routes[2] = (((prevroutes[0] + prevroutes[1]) % 1000000007) + ((prevroutes[3] + prevroutes[4]) % 1000000007)) % 1000000007;
		routes[3] = (((prevroutes[1] + prevroutes[2]) % 1000000007) + ((prevroutes[4] + prevroutes[5]) % 1000000007)) % 1000000007;
		routes[4] = (((prevroutes[2] + prevroutes[3]) % 1000000007) + ((prevroutes[5] + prevroutes[6]) % 1000000007)) % 1000000007;
		routes[5] = (((prevroutes[3] + prevroutes[4]) % 1000000007) + (prevroutes[7] % 1000000007)) % 1000000007;
		routes[6] = (prevroutes[4] + prevroutes[7]) % 1000000007;
		routes[7] = (prevroutes[5] + prevroutes[6]) % 1000000007;

		prevroutes = routes;
	}

	cout << routes[0];
}