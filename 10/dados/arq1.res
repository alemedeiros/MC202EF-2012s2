A��o: # Teste 1
A��o: z A                            A <- 0
A��o: a A 1.0 10 3 2                 A <- x^10y^3z^2
A��o: a A 2.0 8 3 2                  A <- A + 2x^8y^3z^2
A��o: a A 3.0 8 2 2                  A <- A + 3x^8y^2z^2
A��o: a A 1.0 4 4 1                  A <- A + x^4y^4z
A��o: a A -6.0 3 4 1                 A <- A - 6x^3y^4z
A��o: a A 2.0 0 1 1                  A <- A + 2yz
A��o: i A                            imprime A
A = ((x^10 + 2.0x^8)y^3 + (3.0x^8)y^2)z^2 + ((x^4 - 6.0x^3)y^4 + (2.0)y)z
A��o: c B A                          B <- A
A��o: i B                            imprime B
B = ((x^10 + 2.0x^8)y^3 + (3.0x^8)y^2)z^2 + ((x^4 - 6.0x^3)y^4 + (2.0)y)z
A��o: l A                            libera A
A��o: l B                            libera B
A��o: x
Processamento terminado
