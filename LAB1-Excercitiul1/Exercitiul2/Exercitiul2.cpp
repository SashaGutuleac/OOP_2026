#include <cstdio> 
#include <cstring>

int main() {
	printf("introduceti numarul de cuvinte din propozitie:");
	int numar_cuvinte;
	scanf_s("%d", &numar_cuvinte);
	char lista_cuvinte[100][50];
	printf("introdu propozitia:\n");
	for (int i = 0; i < numar_cuvinte; i++)
	{
		scanf_s("%49s", lista_cuvinte[i], 49);
	}
	for (int i = 0; i < numar_cuvinte - 1; i++)
	{
		for (int j = i + 1; j < numar_cuvinte; j++)
		{
			size_t lungime_i = strlen(lista_cuvinte[i]);
			size_t lungime_j = strlen(lista_cuvinte[j]);
			bool trebuie_schimbat = false;
			if (lungime_i < lungime_j)
			{
				trebuie_schimbat = true;
			}
			else if (lungime_i == lungime_j)
			{
				if (strcmp(lista_cuvinte[i], lista_cuvinte[j]) > 0)
				{
					trebuie_schimbat = true;
				}
			}
			
			if (trebuie_schimbat)
			{
				char auxiliar[50];
				strcpy_s(auxiliar, 50, lista_cuvinte[i]);
				strcpy_s(lista_cuvinte[i], 50, lista_cuvinte[j]);
				strcpy_s(lista_cuvinte[j], 50, auxiliar);
			}
		}
	}

	printf("\n cuvintele sortate sunt : \n");
	for (int i = 0; i < numar_cuvinte; i++)
	{
		printf("%s\n", lista_cuvinte[i]);
	}
	return 0;
}