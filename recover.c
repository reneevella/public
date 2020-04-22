#include <stdio.h>
#include <stdlib.h>


    //fread(data, size, number, intptr);

    //0xff 0xd8 0xff

    //cada bloco tem 512 bytes

    // data pode ser um buffer, vetor onde vc vai alocar os dados que está lendo
    //size numero de bytes que cada elemento que vc vai ler - 512
    //number numero de elemntos que vc quer(tenta) ler
    //intprt *FILE é o arquivo que vc vai ler os dados from - memory card

    //(buffer[3] & 0xf0) == 0xe0

    //guardar o numero de arquivos que achei

    //sprinft(filename, "%03i.jpg", numero_do_arquivo);

    //FILE *img = fopen(filename, "w"); // a partir daqui pode começar a gravar dados no arquivo usando fwrite

    //fwrite(data, size, number, outptr);

    //data: poiter para os bytes que vão ser gravados no aruqivo
    //size: tamanho de cada elemento a ser gravado
    //number:  numero de elementos
    //outptr: FILE * é o ponteiro para o arquivo que vc quer gravar os dados -- o jpg que vc acabou de abrir


    //fread retorna o numero de itens do tamanho size que foi lido do arquivo
    //tenta ler n elentos, se não tiver n elentos ele retorna um valor menos que n
    //criar condição para determinar se o fread chegou até o final do arquivo



int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("image");
        return 1;
    }


    unsigned char buffer[512];
    char filename[8];

    int n_files = 0;
    int n_fread = 0;

    FILE *file = fopen(argv[1], "r");
    FILE *img = NULL;

    if (file == NULL)
    {
        printf("Could not open the file");
        return 1;
    }

    n_fread = 50;


    //repete até acabar os arquivos
    while (n_files <= n_fread)
    {

        fread(buffer, 512, n_fread, file);

        //se for o começo de um JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //se for o primeiro arquivo
            if (n_files == 0)
            {
                //cria um arquivo novo 000
                sprintf(filename, "%03i.jpg", n_files);

                //abre o arquivo 000
                img = fopen(filename, "w");

                //copia 512 bytes para esse arquivo com fwrite
                fwrite(&buffer, 512, 1, img);
            }


            else
            {
                //fecha arquivo anterior
                fclose(img);

                //cria um arquivo novo 000n_files
                sprintf(filename, "%03i.jpg", n_files);

                //abre o arquivo
                img = fopen(filename, "w");

                //copia 512 bytes para esse arquivo com fwrite
                fwrite(&buffer, 512, 1, img);
            }

            n_files++;

        }

        else //já é um jpg, então continua copiando próximos 512 bytes
        {
            fwrite(&buffer, 512, 1, img);
        }

    }// fecha while

    fclose(img);
    fclose(file);

}
