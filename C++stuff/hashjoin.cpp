#include <iostream>
#include <vector>

using namespace std;

  int main()
{
    vector<int> A {1, 2, 3, 4, 5};

    vector<int> B {6, 7, 8, 9, 10, 11, 12};

    vector<pair<int, int>> A_merge_B(A.size() < B.size() ? A.size() : B.size());

    for(size_t i = 0; i < A_merge_B.size(); i++)
    {
        A_merge_B[i] = std::make_pair(A[i], B[i]);
    }
    for (auto& elem : A_merge_B)
    {
        std::cout << elem.first << '\t' << elem.second << '\n';
    }

}
