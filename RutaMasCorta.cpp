#include <iostream>
using namespace std;
#include <limits.h>
//n�mero de v�rtices en el grafo
#define V 9
int minDistance(int dist[], bool sptSet[])
{

	//inicializamos con el valor m�nimo
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

void printSolution(int dist[])
{
	cout << "Vertice \t Distancia desde el origen" << endl;
	for (int i = 0; i < V; i++)
		cout << i << " \t\t\t\t" << dist[i] << endl;
}

void dijkstra(int graph[V][V], int src)
{
	int dist[V]; /*Este arreglo mantendra la distancia m�s corta desde el origen hasta "i"*/

	bool sptSet[V]; /*sptSet[i] ser� verdadero si el v�rtice "i" se incluye en el �rbol de ruta
					m�s corta o se finaliza la distancia m�s corta desde src a "i"*/
					
	//Inicializamos todas las distancias como INFINITE y stpSet[] como Falso
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	//Distancia del v�rtice a si mismo siempre es 0
	dist[src] = 0;

	//Busca la ruta m�s corta para todos los v�rtices
	for (int count = 0; count < V - 1; count++) {
		/*Elija el v�rtice de distancia m�nima del conjunto de v�rtices a�n no procesados.
		"u" siempre es igual a "src" en la primera iteraci�n.*/		
		int u = minDistance(dist, sptSet);

		//Marcar el v�rtice seleccionado como procesado
		sptSet[u] = true;

		//Actualiza el valor de "dist" de los v�rtices adyacentes del v�rtice seleccionado.
		for (int v = 0; v < V; v++)

			/*Actualiza dist[v] solo si no est� en sptSet,
			hay un borde "u" a "v", y el peso total de la ruta "src" a "v"
			a trav�s de "u" es menor que el valor actual de dist[v]*/
			
			if (!sptSet[v] && graph[u][v]
				&& dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	//Imprime el arreglo de distancias
	printSolution(dist);
}

//FUNCI�N PRINCIPAL
int main()
{

	//Creamos el grafo mencionado en el trabajo de investigaci�n
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

	//llama a la funci�n 
	dijkstra(graph, 0);

	return 0;
}

