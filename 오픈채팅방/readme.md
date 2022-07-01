# cpp stl map

map : key와 value로 이루어진 자료구조.

C++의 map의 내부 구현은 검색, 삽입, 삭제가 O(logn) 인 레드블랙트리로 구성

map <key, value> map1의 구조.
map <key type, value type> 이름

m.find(key) != m.end()

의 형태로 작동

m.insert({key, value}); 의 형태로 삽입

m.erase()의 형태로 지우기 작동

m[key] = value 의 형태로 할당 가능

m.size() 크기 비교

키로 값을 찾을 경우, at으로 사용 가능
m.at[key]

# cpp stringstream

빈칸으로 이루어진 스트링을 나눌 때 확인

	stringstream ss(a);
	string result[5];
	string token;

	int index = 0;

	while (ss >> token)
		result[index++] = token;
    
 의 형태로 작동.
 
 
 # 문제풀면서 어려웠던 내용
 
 leave의 구조를 처음에 생각하지 못해서 고생했다.
 leave는 두 개의 문자열로 구성되어 있어 문제가 생겼는데, 이를 예외처리 해주니 문제가 쉽게 풀렸다.
 
         if(result[0] == "Leave")
        {
            index = 0;
            continue;
        }
        
        로 구조를 바꿔주긴 했는데, 그 전에 많이 힘들었다.
