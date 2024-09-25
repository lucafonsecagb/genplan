# Gerador de Planilha de Horários CSV

Este projeto gera uma planilha no formato CSV contendo horários de início, intervalo, retorno e fim para cada dia, com variação aleatória nos horários e garantindo que a jornada de trabalho total seja de 8 horas por dia. O número de dias é passado como argumento na linha de comando.

## Funcionalidades

- Gera uma planilha CSV com colunas:
  - `dia`: Identificador do dia.
  - `inicio`: Horário de início do expediente.
  - `intervalo`: Horário de início do intervalo para o almoço.
  - `retorno`: Horário de retorno do intervalo.
  - `fim`: Horário de fim do expediente.
- A variação dos horários de início, intervalo e retorno é de até ±10 minutos.
- A soma total de horas trabalhadas por dia é garantida em 8 horas.

## Requisitos

- GCC (GNU Compiler Collection)
- Sistema Linux/Ubuntu (ou compatível com GCC)

## Compilação

Para compilar o programa, utilize o seguinte comando:

```bash
g++ -o gerar_csv gerar_csv.cpp
```

## USO

Após a compilação, você pode executar o programa da seguinte forma (Substitua **<numero_de_dias>** pelo número de dias para os quais você deseja gerar os horários):

```bash
./gerar_csv --amount-days <numero_de_dias>
```
## Estrutura do CSV

O arquivo planilha.csv será gerado com o seguinte formato:

```csv
dia,inicio,intervalo,retorno,fim
Dia 1,09:05,12:10,13:35,18:00
Dia 2,08:55,12:03,13:33,17:58
Dia 3,09:01,11:59,13:32,18:01
...
```

## Contribuições

Sinta-se à vontade para abrir issues ou enviar pull requests. Qualquer tipo de contribuição é bem-vinda!

## Licença

Este projeto está licenciado sob a licença MIT.
