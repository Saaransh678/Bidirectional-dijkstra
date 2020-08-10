#include<bits/stdc++.h>
using namespace std;

void
shortestpath (int src, int dist[], int prev[], unordered_set < int >proc,
	      int dst, int distr[], int prevr[], unordered_set < int >procr) 
{
  
int distance = INT_MAX;
  
int ubest;

for (auto x:proc)
    
    {
      
if (dist[x] + distr[x] < distance)
	
	{
	  
distance = dist[x] + distr[x];
	  
ubest = x;
	
}
    
}

for (auto x:procr)
    
    {
      
if (dist[x] + distr[x] < distance)
	
	{
	  
distance = dist[x] + distr[x];
	  
ubest = x;
	
}
    
}
  
vector < int >path;
  
int last = ubest;
  
while (last != src)
    
    {
      
path.push_back (last + 1);
      
last = prev[last];
    
 
}
  
 
reverse (path.begin (), path.end ());
  
last = ubest;
  
while (last != dst)
    
    {
      last = prevr[last];
      
 
path.push_back (last + 1);
    
 
}
  
 
cout << distance << "\n";
  
cout << src + 1 << " ";
  
for (int i = 0; i < path.size (); i++)
    
cout << path[i] << " ";

} 
void

transposeGraph (vector < pair < int, int >>adj[], 
vector < pair < int,
		int >>transpose[], int v) 
{
  
 
for (int i = 0; i < v; i++)
    
for (int j = 0; j < adj[i].size (); j++)
      
transpose[adj[i][j].first].push_back (make_pair (i, adj[i][j].second));

} 
int

main () 
{
  
int v, e;
  int x, y, w;
  
cin >> v >> e;
  
vector < pair < int, int >>adj[v];
  
for (int i = 0; i < e; i++)
    
    {
      
cin >> x >> y >> w;
      
x--;
      
y--;
      
adj[x].push_back (make_pair (y, w));
    
} 
vector < pair < int, int >>transpose[v];
  
transposeGraph (adj, transpose, v);
  
int dist[v];
  int distr[v];
  
for (int i = 0; i < v; i++)
    
    {
      dist[i] = INT_MAX;
      
distr[i] = INT_MAX;
    } 
int src, dst;
  
cin >> src >> dst;
  
src--;
  
dst--;
  
dist[src] = 0;
  
distr[dst] = 0;
  
int prev[v];
  int prevr[v];
  
memset (prev, -1, sizeof (prev));
  
memset (prevr, -1, sizeof (prevr));
  
unordered_set < int >proc;
  unordered_set < int >procr;
  
set < pair < int, int >>s;
  
set < pair < int, int >>s1;
  
s.insert (make_pair (0, src));
  
s1.insert (make_pair (0, dst));
  
  do
    
    {
      
pair < int, int >temp = *(s.begin ());
      
s.erase (s.begin ());
      
int u = temp.second;
      
vector < pair < int, int >>::iterator i;
      
for (i = adj[u].begin (); i != adj[u].end (); ++i)
	
	{
	  
int v = (*i).first;
	  
int weight = (*i).second;
	  
if (dist[v] > dist[u] + weight)
	    
	    {
	      
if (dist[v] != INT_MAX)
		
s.erase (s.find (make_pair (dist[v], v)));
	      
dist[v] = dist[u] + weight;
	      
prev[v] = u;
	      
s.insert (make_pair (dist[v], v));
	    
}
	
}
      
proc.insert (u);
      
if (procr.find (u) != procr.end ())
	
	{
	  
shortestpath (src, dist, prev, proc, dst, distr, prevr, procr);
	  
break;
	
}
      
pair < int, int >temp1 = *(s1.begin ());
      
s1.erase (s1.begin ());
      
int u1 = temp1.second;
      
 
for (i = transpose[u1].begin (); i != transpose[u1].end (); ++i)
	
	{
	  
int v = (*i).first;
	  
int weight = (*i).second;
	  
if (distr[v] > distr[u1] + weight)
	    
	    {
	      
if (distr[v] != INT_MAX)
		
s1.erase (s1.find (make_pair (distr[v], v)));
	      
distr[v] = distr[u1] + weight;
	      
prevr[v] = u1;
	      
s1.insert (make_pair (distr[v], v));
	    
}
	
}
      
procr.insert (u1);
      
if (proc.find (u1) != proc.end ())
	
	{
	  
shortestpath (src, dist, prev, proc, dst, distr, prevr, procr);
	  
break;
	
}
    
 
 
 
}
  while (true);

 
}
