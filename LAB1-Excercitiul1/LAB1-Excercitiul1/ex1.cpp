#include <cstdio>
#include <cstring>

int transforma_in_numar(const char* text) {
	int numar_final = 0;

	for (int i = 0; text[i] != '\0'; i++) {
		if (text[i] >= '0' && text[i] <= '9') {
			numar_final = numar_final * 10 + (text[i] - '0');
		}
	}
	return numar_final;
}

int main() {
	FILE* fisier;
	long long suma_totala = 0;
	if (fopen_s(&fisier, "ini.txt", "r") != 0)
	{
		printf("eroare la deschiderea fiserului\n");

	}
	else {
		char linie_text[200];
		while (fgets(linie_text, 200, fisier)) {
			size_t lungime = strlen(linie_text);
			if (lungime > 0 && linie_text[lungime - 1] == '\n') {
				linie_text[lungime - 1] = '\0';
			}

			int numar_extras = transforma_in_numar(linie_text);
			suma_totala = suma_totala + numar_extras;
			printf("am citit linia %s | cifra adunata este %d\n", linie_text, numar_extras);

		}
		fclose(fisier);
	}
		printf("Suma totala a numereleor din fisier este %lld\n", suma_totala);
		return 0;

	
}