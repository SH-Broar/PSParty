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
//    for (int i = 0; i < r; i++) // 앞부터 r개의 true가 채워진다. 나머지 뒤는 false.
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