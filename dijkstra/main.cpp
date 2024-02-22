#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int INF = 100000002;  //주의 출발 노드에서 목표 노드까지 가는 비용"의 최대치가 10만이 아닙니다.

vector<int> d;
vector<bool> visit;
int N, M, start, target;
vector<int> m[1001];

//출발 노드를 설정합니다.
//출발 노드를 기준으로 각 노드의 최소 비용을 저장합니다.
//방문하지 않은 노드 중에서 가장 비용이 적은 노드르 선택합니다.
//해당 노드를 거쳐서 특정한 노드로 가는 경우를 고려하여 최소 비용을 갱신합니다.
//위 3~4 과정을 반복합니다.

int small_index() {
	int i, min = INF, min_idx=0;
	for (i = 0; i <= N; i++) {
		if (!visit[i]) {
			if (min > d[i]) {
				min_idx = i;
				min = d[i];
			}
				
		}
	}
	return min_idx;
}

void Dijkstra(int start) {
	int i, j;
	for (i = 0; i <= N; i++) {
		 d[i] = m[start][i];
	}
	visit[start] = true;
	for (i = 0; i <= N-2; i++) {
		int cur = small_index();
		visit[cur] = true;
		for (j = 0; j <= N; j++) {
			//cout << d[j] << " " << d[cur] + m[cur][j] << "\n";
			if (!visit[j]) {
				if (d[cur] + m[cur][j] < d[j])
					d[j] = d[cur] + m[cur][j];
			}
		}
	}
}

int main() {
	int u, v, w, i, j;
	cin >> N;
	cin >> M;
	
	for (i = 0; i <= N; i++) {
		for (j = 0; j <= N; j++) {
			m[i].push_back(INF);
			if (i == j) {
				m[i][j] = 0;
				m[j][i] = 0;
			}
				
		}
	}

	for ( i = 0; i < M; i++) {
		cin >> u >> v >> w;
		if (m[u][v] != INF)
			m[u][v] = min(m[u][v], w);
		else 
			m[u][v] = w;
		
		    
	}

	cin >> start >> target;

	for (i = 0; i <= N; i++) {
		visit.push_back(false);
		d.push_back(INF);
	}

	Dijkstra(start);
	cout << d[target];
	//for (i = 1; i <= N; i++) {
	//	if (d[i] == INF)
	//		cout << "INF" << "\n";
	//	else
	//	    cout << d[i]<<"\n";
	//}

}