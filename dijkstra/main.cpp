#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int INF = 100000002;  //���� ��� ��忡�� ��ǥ ������ ���� ���"�� �ִ�ġ�� 10���� �ƴմϴ�.

vector<int> d;
vector<bool> visit;
int N, M, start, target;
vector<int> m[1001];

//��� ��带 �����մϴ�.
//��� ��带 �������� �� ����� �ּ� ����� �����մϴ�.
//�湮���� ���� ��� �߿��� ���� ����� ���� ��帣 �����մϴ�.
//�ش� ��带 ���ļ� Ư���� ���� ���� ��츦 ����Ͽ� �ּ� ����� �����մϴ�.
//�� 3~4 ������ �ݺ��մϴ�.

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