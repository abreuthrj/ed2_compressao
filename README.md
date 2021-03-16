# Parametros
<action> <?file>

Action define a ação a ser realizada, entre elas estão:

encode -> Codifica a entrada via terminal ou <?file>
decode -> Decodifica a entrada via terminal ou <?file>

Ambos escrevem a saida no stdout padrão ( terminal ).
Portanto para setar a saida para um arquivo, usar a sintaxe:

programa encode texto.txt > codificado.txt
programa decode codificado.txt > decodificado.txt

# Parametros para o compilador
g++ *.cpp _inc/*.cpp -o program.exe