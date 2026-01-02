----- std::vector -----
Por que não acessar a RAM diretamente? -> SEGURANÇA

Cada programa tem sua própria memória virtual.
|
->Previne que um programa interfira em outro

Quando se cria uma variável, "health", por exemplo, ele vai ser alocado em algum lugar da RAM.

Na RAM não nos referimos ao endereço e sim ao nome da variável

Programas não podem usar a mesma célula de RAM

Quando criamos uma variável ele vai mandar para um STACK.

std::vector <int> ages;
ages.push_back(12);     //reserva 4 locais próximos um ao outro na RAM
               (13);
               (14);
               (15);
               (16);    //sem espaço nos 4 locais reservados, entao copia a data anterior [12, 13, 14, 15] e copia para uma outra parte da RAM com mais 4 locais reservados; 8 espaços reservados [n + 4]

O processo de copiar a data da RAM para outra parte dela é um processo demorado.
-> COmo deixar mais rápido? Se souber quanto de data se precisa, deve informar para que a RAM reserve espaço suficiente (informar o espaço a ser reservado).

Coisas que estão mais próximas na RAM são muito mais rápidas de pegar

Como  numa lista há uma "sequencia" eles devem estar proximos.

Quando se aloca algo numa lista se reserva espaço extra que podera ser usado pela lista futuramente.




----- Shooting Bullets -----
Direction = T(target) - C(current location)

se Position += (-860, -490) <-- Acontece em um único frame ("teleporta")

Normalization = move por mais frames
D = (T - C).Normaize()
T. |---------------------| .C
            <- <- <- <-

Magnitude do vector
sqrt(x2 + y2)
sqrt(860 * 860 + 490 * 490)
sqrt(739.600 + 240.100)
sqrt(979.700)

magnitude = 989.79 <- magnitude do vetor, o quãp longo ele é

Normalizar o vetor
Pega o valor x e y e divide pela magnitude

x-axis  860 / 989.7979591815 = 0.86886418
y-axis  490 / 989.7979591815 = 0.495050

-0.86886418, -0.495050  -> vetor normalizado

sqrt(-0.86886418 * -0.86886418 + -0.495050 * -0.495050)
sqrt(0.999998)
1   -> quantidade de vetores, 1 unico vetor




----- Static, Passing by References and Value, Translation Unit -----
Como funciona uma função em C++?
Basicamente, quando passamos algo por uma função, ela COPIA o valor passado
    Exemplo:
        void ReduceHP (int hp) {
            hp --;
        }

        int main() {
            int health = 100;
            ReduceHP(health);

            std::cout << health << std::endl;          -> [Ainda assim, a saída será "100", pois não está retornando nada]
        }


        health      |       hp
        0x00A5      |       hp              -> [São duas variáveis diferentes, o que ocorre é somente a copia do valor de health]
        [100]       |       [100]           



        int ReduceHP (int hp) {
            return --hp;                -> [Nesse caso a saída é "99", pois a função está retornando algo]
        }



        OU
        REFERENCIA

        Caso eu utilize uma referencia ("&"), ainda assim funciona, mesmo eu nao retornando nada

        void ReduceHP (int& hp) {
            --hp                        -> [Nesse caso, quando eu escrevo isso na main -> [ReduceHP(health)] o código, ao invés de passar somente o valor de health, ele passa o endereço de memória [0x00A5], fazendo com que o hp e health sejam a mesma coisa e quando a função [--hp], essa mudança ocorre no health da main]
        }

                            
        [hp]& - [heath] -> [hp] --hp    [health] -> [hp]        [health]
        n/A     100        (health)     100         (health)    99                  AMBOS POSSUEM O MESMO ENDEREÇO DE MEMORIA, POR ISSO QUANDO EU ALTERO O VALOR DE HP O VALOR DE HEALTH TBM ALTERA
                            100                     99



Quando usar "static"? Quando não importa de ter multiplos objetos compartilhando da mesma data.





----- AABB Collision -----
Axis Aligned Bounding Box

1. Se a ponta de uma forma for MAIOR que a ponta de uma segunda forma, há uma colisão.
2. Se a outra ponta da segunda forma for maior que que a outra ponta da primeira forma.

Se a ponta DIREITA da caixa branca for MAIOR que a ponta ESQUERDA da caixa preta E a ponta DIREITA da caixa preta for MENOR que a ponta ESQUERDA da caixa branca HÁ UMA COLISÃO!

if (whiteBox.Right > blackBox.Left &&
    blackBox.Right > whiteBox.Left)

Se a parte de BAIXO do cubo preto for MAIOR que a parte de CIMA do cubo branco E a parte de BAIXO do cubo branco for MAIOR que a parte de CIMA do cubo preto, HÁ UMA COLISÃO!

if (blackBox.bottom > whiteBox.top &&
    whiteBox.bottom > blackBox.top)