A��o: # Teste 5
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
A��o: c B A                          B <- A
A��o: m B A B                        B <- A * B
A��o: i B                            imprime B
B = ((x^8)y^6 + ( - 2.0x^8)y^5 + (x^8)y^4)z^6 + ((2.0x^5)y^6 + ( - 2.0x^5)y^5)z^5 + ((2.0x^8 - 12.0x^7)y^7 + ( - 2.0x^8 + 12.0x^7 + x^2)y^6 + (4.0x^4)y^4 + (2.0x^6 - 4.0x^4)y^3 + ( - 2.0x^6)y^2)z^4 + ((2.0x^5 - 12.0x^4)y^7 + (4.0x)y^4 + (2.0x^5 + 6.0x^4 + 2.0x^3)y^3 + ( - 2.0x^5 - 6.0x^4)y^2)z^3 + ((x^8 - 12.0x^7 + 36.0x^6)y^8 + (4.0x^4 - 24.0x^3)y^5 + (2.0x^6 - 12.0x^5)y^4 + (2.0x^2 + 6.0x)y^3 + (4.0)y^2 + (4.0x^2)y + (x^4))z^2 + ((2.0x^5 - 6.0x^4 - 36.0x^3)y^4 + (4.0x + 12.0)y + (2.0x^3 + 6.0x^2))z + ((x^2 + 6.0x + 9.0))
A��o: l A                            libera A
A��o: l B                            libera B
A��o: x
Processamento terminado
