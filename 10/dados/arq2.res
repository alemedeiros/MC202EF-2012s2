A��o: # Teste 2
A��o: z A                            A <- 0
A��o: a A 1.0 10 3 2                 A <- x^10y^3z^2
A��o: a A 2.0 8 3 2                  A <- A + 2x^8y^3z^2
A��o: a A 3.0 8 2 2                  A <- A + 3x^8y^2z^2
A��o: a A 1.0 4 4 1                  A <- A + x^4y^4z
A��o: a A -6.0 3 4 1                 A <- A - 6x^3y^4z
A��o: a A 2.0 0 1 1                  A <- A + 2yz
A��o: i A                            imprime A
A = ((x^10 + 2.0x^8)y^3 + (3.0x^8)y^2)z^2 + ((x^4 - 6.0x^3)y^4 + (2.0)y)z
A��o: z B                            B <- 0
A��o: a B 1.0 1 3 2                  B <- xy^3z^2
A��o: a B -2.0 8 3 2                 B <- B - 2x^8y^3z^2
A��o: a B -5.0 7 2 2                 B <- B - 5x^7y^2z^2
A��o: a B 1.0 4 4 1                  B <- B + x^4y^4z
A��o: a B 6.0 3 4 1                  B <- B + 6x^3y^4z
A��o: a B 2.0 1 1 1                  B <- B + 2xyz
A��o: a B 3.0 0 0 0                  B <- B + 3
A��o: i B                            imprime B
B = (( - 2.0x^8 + x)y^3 + ( - 5.0x^7)y^2)z^2 + ((x^4 + 6.0x^3)y^4 + (2.0x)y)z + ((3.0))
A��o: s C A B                        C <- A + B  
A��o: i C
C = ((x^10 + x)y^3 + (3.0x^8 - 5.0x^7)y^2)z^2 + ((2.0x^4)y^4 + (2.0x + 2.0)y)z + ((3.0))
A��o: l A                            libera A
A��o: l B                            libera B
A��o: l C                            libera C
A��o: x
Processamento terminado
