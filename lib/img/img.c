/**
* Funções de manipulação de PPM
*/
void readingPPMAscii(char nomeArquivo[MAX_NOME]); // -i [input-file]
void readingPPMBin(char nomeArquivo[MAX_NOME]); // -i [input-file]
int readingPPM(char nomeArquivo[MAX_NOME]); // -i [input-file]
#include "ppm.c"

/**
* Validar a imagem inserida pelo usuário.
* Verifica a extensão e o tamanho do nome da imagem.
* Retorna TRUE para imagem válida e FALSE para não válida.
*/
int validateImagem(char *nomeImagem){
	// Verifica o tamanho do nome da imagem
	int tamanho = tamanhoNomeArquivo(nomeImagem, 0);
	if(tamanho > MAX_NOME){
		printf("Nome de imagem inválido! Deve conter, no máximo, %d caracteres.\n", MAX_NOME);
		return FALSE;
	}
	printf("Tamanho do nome do arquivo %s: %d\n", nomeImagem, tamanho);

	// Verifica a extensão da imagem
	char *extensao = malloc(3*sizeof(char));
	extensao[0] = nomeImagem[tamanho-3];
	extensao[1] = nomeImagem[tamanho-2];
	extensao[2] = nomeImagem[tamanho-1];
	if(!checkExtensao(extensao)){
		printf("Extensão de imagem inválida! O programa só aceita imagens de extensão .ppm e .bmp.\n");
		return FALSE;
	}
	printf("Extensão %s (codigo: %d)\n", extensao, checkExtensao(extensao));

	return TRUE;
}