A��o: # Teste 4
A��o: z A                            A <- 0
A��o: a A 1.0 4 3 3                  A <- x^4y^3z^3
A��o: a A -1.0 4 2 3                 A <- -x^4y^2z^3
A��o: a A 4.0 1 3 2                  A <- A + 4xy^3z^2
A��o: a A -3.0 1 3 2                 A <- A - 3xy^3z^2
A��o: a A 1.0 4 4 1                  A <- A + x^4y^4z
A��o: a A 1.0 2 0 1                  A <- A + x^2z
A��o: a A -6.0 3 4 1                 A <- A - 6x^3y^4z
A��o: a A 2.0 0 1 1                  A <- A + 2yz
A��o: a A 1.0 1 0 0                  A <- A + x
A��o: a A 3.0 0 0 0                  A <- A + 3
A��o: i A                            imprime A
A = ((x^4)y^3 + ( - x^4)y^2)z^3 + ((x)y^3)z^2 + ((x^4 - 6.0x^3)y^4 + (2.0)y + (x^2))z + ((x + 3.0))
A��o: z B                            B <- 0
A��o: a B 1.0 2 0 0                  B <- x^2 
A��o: m B A B                        B <- A * B
A��o: i B                            imprime B
B = ((x^6)y^3 + ( - x^6)y^2)z^3 + ((x^3)y^3)z^2 + ((x^6 - 6.0x^5)y^4 + (2.0x^2)y + (x^4))z + ((x^3 + 3.0x^2))
A��o: l A                            libera A
A��o: l B                            libera B
A��o: x
Processamento terminado
