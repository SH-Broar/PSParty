//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main() {
//    const int r = 2;
//
//    vector<char> arr{ 'a', 'b', 'c', 'd' };
//    vector<bool> temp(arr.size(), false);
//    for (int i = 0; i < r; i++) // �պ��� r���� true�� ä������. ������ �ڴ� false.
//        temp[i] = true;
//
//    do {
//        for (int i = 0; i < arr.size(); ++i) {
//            if (temp[i])
//                cout << arr[i] << ' ';
//        }
//        cout << endl;
//    } while (prev_permutation(temp.begin(), temp.end()));
//}