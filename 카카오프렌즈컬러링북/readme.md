# pair class

두 객체를 하나의 객체로 취급 할 수 있게 묶어주는 클래스입니다. 데이터 쌍을 표현할 때 사용한다고 합니다.

![image](https://user-images.githubusercontent.com/48556879/178992258-c9a53e46-6ea8-4c12-b626-2a19d254aba9.png)

이런 식으로 queue와 연동하여 사용도 가능합니다.

선언할 때는, pair<type,type> 이름

의 형식으로 선언합니다.

p.first는 p의 첫번째 인자를 반환하고,
p.second는 두번째 인자를 반환합니다.
make_pair(변수1,변수2) 의 경우는, 변수 1과 변수 2가 들어간 pair를 만들어줍니다.

![image](https://user-images.githubusercontent.com/48556879/178992528-7af8fc95-9b33-4927-b12d-f0cdc98712f2.png)

Q.front()를 이용하여 first와 second를 뽑아내는 모습입니다.

# BFS

너비 우선 탐색으로, 루트 노드에서 시작해서 인접한 노드를 먼저 탐색하는 방법입니다.

위 코드에서는, i,j부터 즉, 0,0부터 탐색을 시작합니다.

이 방법은 깊게 탐색하는 것이 아닌, 넓게 탐색하는 것을 목표로 둡니다.

## 특징

<ol>재귀적으로 동작하지 않습니다.</ol>

<ol>중요한 점인데, 어떤 노드를 방문하였는지 여부를 반드시 검사해야 합니다.</ol>

![image](https://user-images.githubusercontent.com/48556879/178993287-87105f15-88fc-4da0-b444-9f96e9bd1a47.png)

위 코드에서는, bool 2차원 배열을 선언해 이를 이용하여 방문여부를 체크하고

![image](https://user-images.githubusercontent.com/48556879/178993401-74c99a6f-ddaf-44fe-bca9-5a660bdc7953.png)

코드를 사용해 false를 확인합니다.

<ol>큐를 사용하는데, 큐는 선입선출 원칙으로 탐색하기에 bfs에 아주 걸맞습니다.</ol>


# 어려웠던 점

bfs가 너무 오랜만이라 구현하는데 어려움을 겪었습니다. 예전에 공부했었는데, 부족한 점이 많았습니다.
요즘 구현 관련 문제가 중요하다고 생각해서 이쪽으로 공부했었는데, bfs와 dfs도 부족한 점이 많았습니다.
내일부터는 알고리즘 관련 공부를 해야겠습니다.

