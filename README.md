# Sobre
Trabalho de AED II para encontrar o numero que falta em uma sequencia

# Execucao
Primeiro Copile o gerador de sequencia com um numero faltante caso vc nao tenha um arquivo sequencial com um numero faltando.

```Bash
gcc GeraArquivoNumeroSeq.c -o"Gera"
```

Execute o arquivo copilado passando dois argumentos o tamanho da sequencia e o numero que a sequencia começará

```Bash
./Gera 100 1
```

após isso copile o sequencia.c

```Bash
gcc sequencia.c -o"Seq"
```

e passe através de um redirection pipe o arquivo com a sequencia

```Bash
./Seq < sequencia.txt
```

Depois que a entrada dos dados for feita, você saberá o numero que falta na sequencia.

