#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
using namespace std;
// 最短路径算法 Shortest Path Algorithm SPA 解决 最短路径 问题 by hsluoyz 

//object part
#define pointNumber 10
#define distFT_MAX 1000000
int distFT[pointNumber][pointNumber];
//object part

//point part

int prev_[pointNumber];
int dist[pointNumber];
int s[pointNumber];
//point part

int RandomIntLessThan(int aint)
{
	return (int) ((double) aint * (double) rand() / (double) (RAND_MAX + 1));
}

int RandomTrueBy(double aprob)
{
	double res = (double) rand() / (RAND_MAX + 1);
	if (res <= aprob)
		return 1;
	else
		return 0;
}

void Dijkstra(int v)
{

	for (int i = 0; i < pointNumber; i ++)
	{
		dist[i] = distFT[v][i];
		if (dist[i] == distFT_MAX)
			prev_[i] = -1;
		else
			prev_[i] = 0;
		s[i] = 0;
	}
	s[v] = 1;

	for (int i = 0; i < pointNumber - 1; i ++)
	{
		int u = -1;
		int tempdist = distFT_MAX;
		for (int m = 0; m < pointNumber; m ++)
		{
			if (dist[m] < tempdist && s[m] == 0)
			{
				tempdist = dist[m];
				u = m;
			}
		}
		if (u == -1)
		{
			cout << "The isolated point exsits." << endl;
			break;
		}
		s[u] = 1;
		cout << "change:" << u << endl;

		for (int j = 0; j < pointNumber; j ++)
		{
			if (s[j] == 0)
			{
				int newdist = dist[u] + distFT[u][j];
				if (newdist < dist[j])
				{
					dist[j] = newdist;
					prev_[j] = u;
				}
			}
		}
	}
}

void DisplayMap(){
	for (int i = 0; i < pointNumber; i ++)
	{
		for (int j = 0; j < pointNumber; j ++)
		{
			cout << distFT[i][j] << " ";
		}
		cout << endl;
	}
}

void Display(int v, int a)
{
	//point part
	int stack[100];
	int stackNumber = 0;
	int i = a;
	while (i != v)
	{
		stack[stackNumber] = i;
		stackNumber ++;
		i = prev_[i];
	}
	stack[stackNumber] = v;
	stackNumber ++;
	for (int j = stackNumber - 1; j > 0; j --)
	{
		cout << stack[j] << " -> ";
	}
	cout << stack[0] << endl;
	//point part
}

void main(){
	srand((unsigned) time(NULL));
	//object part
	for (int i = 0; i < pointNumber; i ++)
	{
		distFT[i][i] = 0;
		for (int j = i + 1; j < pointNumber; j ++)
		{
			if (RandomTrueBy(0.1))
			{
				distFT[i][j] = distFT_MAX;
			}
			else
				distFT[i][j] = RandomIntLessThan(100);
		}
	}
	for (int i = 0; i < pointNumber; i ++)
	{
		for (int j = 0; j < i; j ++)
		{
			distFT[i][j] = distFT[j][i];
		}
	}
	DisplayMap();
	Dijkstra(0);
	Display(0, pointNumber - 1);
	//object part
}