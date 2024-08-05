#include <iostream>
#include <fstream>
#include <stdlib.h>

#include <assert.h>

using namespace std;

#define MAXN 26
#define HAS_EDGE(i,j) E[i][j]
//( i<j ? E[i][j]==1 : E[j][i]==1 )

long in_count = 0;
long out_count = 0;
int E[MAXN][MAXN];

ofstream outfile;

int load_graph_mc()
{
	int n = cin.get();
	if(n == EOF) return 0;
	assert(n <= MAXN);

	in_count++;
	if(in_count % 10000 == 0) 
	cout << "load complement of graph #" << in_count << ": n = " << n << " ; so far wrote "<< out_count <<"\n";

	for (int i=0;i<n;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			E[i][j] = E[j][i] = 1;
		}
	}

	for (int i=0;i<n-1;i++)
	{
		while(1)
		{
			int j = cin.get();
			if(j == 0) break;
			j--;
//			cout << "edge: "<<i<<","<<j<<endl;
			assert(i < j);
			assert(j < n);
			E[i][j] = E[j][i] = 0;
		}
	}

	return n;
}

int store_graph_mc(int n)
{
	outfile.put(n);
	out_count++;
	for (int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(E[i][j] == 0) outfile.put(j+1);
		}
		outfile.put(0);
	}
//	cout << "FOUND!\n";

}


int test_valid(int n)
{
	// complement triangle free
	for(int a=0;a<n;a++)
	{
		for(int b=a+1;b<n;b++)
		{
			if(E[a][b]) continue;
			for(int c=b+1;c<n;c++)
			{			
				if(E[a][c] || E[b][c]) continue;
				return 0;
			}	
		}	
	}
	// clique
	for(int a=0;a<n-6;a++)
	{
		for(int b=a+1;b<n-5;b++)
		{
			if(!E[a][b]) continue;
			for(int c=b+1;c<n-4;c++)
			{			
				if(!E[a][c]) continue;
				if(!E[b][c]) continue;
				for(int d=c+1;d<n-3;d++)
				{			
					if(!E[a][d]) continue;
					if(!E[b][d]) continue;
					if(!E[c][d]) continue;
					for(int e=d+1;e<n-2;e++)
					{			
						if(!E[a][e]) continue;
						if(!E[b][e]) continue;
						if(!E[c][e]) continue;
						if(!E[d][e]) continue;
						for(int f=e+1;f<n-1;f++)
						{			
							if(!E[a][f]) continue;
							if(!E[b][f]) continue;
							if(!E[c][f]) continue;
							if(!E[d][f]) continue;
							if(!E[e][f]) continue;
							for(int g=f+1;g<n;g++)
							{			
								if(!E[a][g]) continue;
								if(!E[b][g]) continue;
								if(!E[c][g]) continue;
								if(!E[d][g]) continue;
								if(!E[e][g]) continue;
								if(!E[f][g]) continue;
								return 0;
							}
						}
					}
				}
			}	
		}	
	}
	// K333
	for(int a=0;a<n-2;a++)
	{
		for(int b=a+1;b<n-1;b++)
		{
			for(int c=b+1;c<n;c++)
			{			
				for(int d=a+1;d<n-2;d++)
				{			
					if(d == a || d == b || d == c) continue;
					if(!HAS_EDGE(a,d) || !HAS_EDGE(b,d) || !HAS_EDGE(c,d)) continue;
					for(int e=d+1;e<n-1;e++)
					{		
						if(e == a || e == b || e == c) continue;	
						if(!HAS_EDGE(a,e) || !HAS_EDGE(b,e) || !HAS_EDGE(c,e)) continue;
						for(int f=e+1;f<n;f++)
						{			
							if(f == a || f == b || f == c) continue;	
							if(!HAS_EDGE(a,f) || !HAS_EDGE(b,f) || !HAS_EDGE(c,f)) continue;
							for(int g=d+1;g<n-2;g++)
							{			
								if(g == a || g == b || g == c) continue;	
								if(g == d || g == e || g == f) continue;	
								if(!HAS_EDGE(a,g) || !HAS_EDGE(b,g) || !HAS_EDGE(c,g)) continue;
								if(!HAS_EDGE(d,g) || !HAS_EDGE(e,g) || !HAS_EDGE(f,g)) continue;
								for(int h=g+1;h<n-1;h++)
								{			
									if(h == a || h == b || h == c) continue;	
									if(h == d || h == e || h == f) continue;	
									if(!HAS_EDGE(a,h) || !HAS_EDGE(b,h) || !HAS_EDGE(c,h)) continue;
									if(!HAS_EDGE(d,h) || !HAS_EDGE(e,h) || !HAS_EDGE(f,h)) continue;
									for(int i=h+1;i<n;i++)
									{			
										if(i == a || i == b || i == c) continue;	
										if(i == d || i == e || i == f) continue;	
										if(!HAS_EDGE(a,i) || !HAS_EDGE(b,i) || !HAS_EDGE(c,i)) continue;
										if(!HAS_EDGE(d,i) || !HAS_EDGE(e,i) || !HAS_EDGE(f,i)) continue;
										return 0;
									}
								}
							}
						}
					}
				}
			}	
		}	
	}
	return 1;
}

int main(int argc,char** argv)
{
	outfile.open(argv[1]);

	while(1)
	{
		int n = load_graph_mc();
		if(n==0) break;
		
		if(!test_valid(n)) continue;

		long last_out_count = out_count;
		store_graph_mc(n);
	}
	cout << "total number of valid graphs:" << out_count << "\n";
} 
