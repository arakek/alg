#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

vector < vector<int> > mc;
vector < vector<int> > flow;
vector <int> path;

int bfs()
{
	const int n = mc.size();

	path.clear();
	vector<bool> visited(n, false);
	vector<int> route(n, -1);

	queue <int> q;
	q.push(0);
	while (!q.empty() && q.front() != 1)
	{
		const int now = q.front();
		q.pop();
		if (visited[now]) continue;
		visited[now]=true;
		for (int i=0; i<n; ++i)
		{
			if (mc[now][i] && !visited[i]) 
			{
				q.push(i);
				route[i] = now;
			}
		}
	}
	
	if(q.empty()) return false;

	int t=1;
	while (t)
	{
		path.push_back(t);
		t=route[t];
	}
	path.push_back(0);
	reverse(path.begin(),path.end());
	return true;
}

int main ()
{
	int n;
	cin>>n;
	mc.assign(n, vector<int>(n));

	for (int i=0; i<n;++i)
		for (int j=0; j<n; ++j)
			cin>>mc[i][j];

	flow.assign(n,vector<int>(n));

	while (bfs()) 
	{
		int minMC=0x7fffffff; //самое большое число 0111 
		for (int i=0; i<path.size() - 1; ++i)
		{
			const int a = path[i];
			const int b = path[i + 1];
			if (mc[a][b] < minMC) minMC = mc[a][b];
		}

		for (int i=0; i<path.size()-1;++i)
		{
			const int a = path[i];
			const int b = path[i + 1];
			mc[a][b] -= minMC;
			mc[b][a] += minMC;
			flow[a][b] += minMC;
			flow[b][a] -= minMC;
		}
	}

	int s = 0;
	for(int i = 0; i < n; ++i)
		s += flow[0][i];

	cout << s << endl;
}

