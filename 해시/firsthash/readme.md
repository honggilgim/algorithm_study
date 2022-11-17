# c++ hash 알고리즘

# 1. unordered_map

hsah 자료구조의 하나입니다. 빠른 것이 장점으로, 정렬을 기대하면 안됩니다. 정렬되어있는 키와 값의 구조를 원하면 STL map 라이브러리를 사용하면 됩니다.

하지만, 정렬되지 않은 unordered_map은 빠릅니다. 매우 빠릅니다.

해쉬테이블로 구현한 자료구조로 시간복잡도가 매우 낮습니다. 중복된 데이터를 허용하지 않으며, map에 비해 데이터가 많을 시 월등한 성능을 보여줍니다.

## 부분 함수

- empty( ) :맵이 비어있는지 확인하는 함수

- size( ) :맵의 크기를 확인하는 함수

- operator [ ] : 맵에서 key를 통해 value를 지정하는 operator

- find( key ) : 맵에서 key에 해당하는 원소를 찾는 함수

- count( key ) :맵에서 key에 해당하는 원소의 갯수를 반환하는 함수

- insert( {key, value} ) :맵에 pair<key,value> 를 추가하는 함수

- erase( key ) :맵에서 key에 해당하는 원소를 제거하는 함수
erase 하는 방법 : 특정 position의 pair 삭제, key를 통해 삭제, 범위 삭제

- clear( ) :맵을 초기화하는 함수
 
- operator = 대입연산자 가능

의 부분함수들이 있으며, 대입연산자 기능을 통해 map[man]++와 같이 ++로 값을 더해줄 수 있고,
'''
if(map.end() == map.find(man))
'''
의 구문으로 map에서 if문을 활용할 수 있습니다. 이 if문은, map의 끝에서 man을 찾지 못할경우 true를 반환합니다.
--역시 사용이 가능합니다.
