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