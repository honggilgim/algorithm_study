#include <string>
#include <vector>
#include <numeric>
#include <string>
#include <functional>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {

    int answer = -2;
    int count = 0;

    int length = queue1.size();

    long suma = accumulate(queue1.begin(), queue1.end(), 0);
    long sumb = accumulate(queue2.begin(), queue2.end(), 0);
    long sum = suma + sumb;
    if (sum % 2 == 1)
        return -1;

    int idx_1 = 0;
    int idx_2 = 0;

    while (true)
    {

        if (suma == sumb)
        {
            break;
        }
        count++;
        if (count > length * 3)
        {
            count = -1;
            break;
        }

        if (suma > sumb)
        {
            int a = queue1[idx_1];
            //queue1.erase(queue1.begin()); // q1 pop_front
            idx_1++;
            queue2.push_back(a); // q2 push)back
            suma -= a;
            sumb += a;
        }
        else
        {
            int b = queue2[idx_2];
            idx_2++;
            //queue2.erase(queue2.begin()); // q2 pop_front
            queue1.push_back(b); // q1 push back
            sumb -= b;
            suma += b;
        }
    }

    answer = count;


    return answer;
}