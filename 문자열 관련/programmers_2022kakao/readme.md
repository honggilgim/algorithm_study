# stl_map

각 키와 값 쌍으로 이루어진 트리. 중복은 허용하지 않음

map<key,value> 이름 의 형태로 이루어져있음

key 값을 기준으로 정렬하며, 오름차순으로 자동으로 정렬됨

include <map> 으로 사용
  
  ## 함수
  
  begin() -> 맨 첫번째 원소를 가리키는 반복자를 리턴
  
  end() -> 맨 마지막 원소를 가리키는 원소의 끝부분을 알 때 사용.
  
  rend() -> 역으로 출력하고 싶을 때 사용
  
  clear() -> 초기화
  
  insert() -> 원소 추가
  
  find() -> 키와 관련된 원소의 반복자 반환
  
  size() -> 개수 반환
  
  erase() -> 해당 원소 삭제
  
  
  # set
  
  숫자든, 문자든 중복을 없애줍니다. 삽입하는 순서에 맞춰서 정렬없이 입력됩니다. set은, 밸런스 트리로 레드 블랙 트리로 이루어져 있습니다.
  
  삽입, 삭제가 용이하며 자료 차는것도 준수합니다.
  
  set<자료형> 변수 의 형태로 선언합니다.
  
  ## set의 함수
  
  begin() -> 시작 주소 값 변환
  
  end() -> 마지막 부분 주소 값 반환
  
  rbegin() -> set의 마지막 부분을 시작점으로 지정
  
  rend() -> set의 첫번째 부분을 마지막점으로 지정
  
  c가 붙은 함수 -> const로 지정
  
  empty, size, max_size 등의 용량 함수와 inset 등의 삽입 삭제 함수도 똑같이 작동
  
  
  # sstream
  
  주어진 문자열에서 필요한 자료형에 맞는 정보를 꺼낼 때 유용하게 사용됨. stringstream 에서 공백과 개행문자를 제외한
  문자열에서 맞는 자료형의 정보를 빼냄.
  
          stringstream ss(rep);
        string from, to;
        ss >> from >> to;

        // [신고된ID, 신고한ID] 형태로 Map에 저장
        // report_map의 Value는 Set 형태이므로, 바로 insert 가능
        report_map[to].insert(from);
  
  이 구조 잘 기억해두고 써야 할 거 같음. 위의 구조는, ss로 공백으로 구분된 문자열을 받은 후 그것을 나누는 코드.
  
  
  
  # 범위 기반 for 문
  
  
  ## 예시코드
  
  int main() {
    std::vector<int> buff(10); // 원소를 10개 생성
    for (auto x : buff)
        std::cout << x << std::endl;
    return 0;
}
이런식으로 제작하면, buff 안의 인자들이 자동으로 x로 들어가 범위 기반 for문으로 작동한다.
  
  ## auto
  
  cpp에서 지원해주는 기능으로, auto를 사용하면 자동으로 그 형식에 맞는 선언문으로 변환한다.
  
