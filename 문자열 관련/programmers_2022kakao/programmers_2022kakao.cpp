#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {

    // 결과 Vector를 0으로 초기화
    vector<int> answer(id_list.size(), 0);

    // 각 멤버의 index를 Map에 저장
    map<string, int> id_idx_map;

    // [신고된ID, 신고한ID]를 저장할 Map 생성
    map<string, set<string>> report_map;

    // 각 멤버의 index를 Map에 저장
    for (auto i = 0; i < id_list.size(); ++i) {
        id_idx_map[id_list[i]] = i;
    }

    // [신고된ID, 신고한ID]를 Map에 저장
    for (auto rep : report) {

        // 문자열 형태의 각 신고 정보를 parsing
        stringstream ss(rep);
        string from, to;
        ss >> from >> to;

        // [신고된ID, 신고한ID] 형태로 Map에 저장
        // report_map의 Value는 Set 형태이므로, 바로 insert 가능
        report_map[to].insert(from);

    }

    // report_map을 탐색하며, 신고한ID의 개수가 K개 이상일 경우, 신고한ID들의 메일수를 +1
    for (auto iter : report_map) {
        if (iter.second.size() >= k) {
            for (auto in_iter : iter.second) {
                answer[id_idx_map[in_iter]]++;
            }
        }
    }

    return answer;
}