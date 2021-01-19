# Arquivos em C
Um exercício para praticar o uso de arquivos na linguagem C

## Principais funções usadas para manipulação de arquivos


### fseek(ponteiro para arquivo, número de bytes pulados, local de posicionamento do ponteiro);

* Posiciona o ponteiro no arquivo
* SEEK_SET - início do arquivo
* SEEK_CUR - posição corrente
* SEEK_END - final do arquivo (número de bytes a pular é contado para trás)


### fread(buffer que armazena o dado lido, tamanho do bloco de leitura(bytes), número de blocos a ler, ponteiro para arquivo);

* Lê os dados do arquivo


### fwrite(buffer que armazena o dado a ser escrito no arquivo, tamanho do bloco a ser escrito(bytes), número de blocos a escrever, ponteriro para o arquivo);

* Escreve dados no arquivo


### fopen("nome do arquivo.extensao", "modo de abertura");

* Abre o arquivo

Modos de abertura | Significado
----------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------
"r"	| Abre um arquivo texto para leitura. O arquivo deve existir antes de ser aberto.
"w"	| Abrir um arquivo texto para gravação. Se o arquivo não existir, ele será criado. Se já existir, o conteúdo anterior será destruído.
"a"	| Abrir um arquivo texto para gravação. Os dados serão adicionados no fim do arquivo ("append"), se ele já existir, ou um novo arquivo será criado, no caso de arquivo não existente anteriormente.
"rb"	| Abre um arquivo binário para leitura. Igual ao modo "r" anterior, só que o arquivo é binário.
"wb"	| Cria um arquivo binário para escrita, como no modo "w" anterior, só que o arquivo é binário.
"ab"	| Acrescenta dados binários no fim do arquivo, como no modo "a" anterior, só que o arquivo é binário.
"r+"	| Abre um arquivo texto para leitura e gravação. O arquivo deve existir e pode ser modificado.
"w+"	| Cria um arquivo texto para leitura e gravação. Se o arquivo existir, o conteúdo anterior será destruído. Se não existir, será criado.
"a+"	| Abre um arquivo texto para gravação e leitura. Os dados serão adicionados no fim do arquivo se ele já existir, ou um novo arquivo será criado, no caso de arquivo não existente anteriormente.
"r+b"	| Abre um arquivo binário para leitura e escrita. O mesmo que "r+" acima, só que o arquivo é binário.
"w+b"	| Cria um arquivo binário para leitura e escrita. O mesmo que "w+" acima, só que o arquivo é binário.
"a+b"	| Acrescenta dados ou cria uma arquivo binário para leitura e escrita. O mesmo que "a+" acima, só que o arquivo é binário

### fclose(ponteiro para o arquivo);
* fecha o arquivo no final do código
