func numero funcionNueva(numero a)
realiza
  SI (a IGUAL 1) REALIZA
    a = 1;
  SINO
    a = funcionNueva(a-1)*a;
  FIN
  regresa(a);
fin

programa viko;
REALIZA
  imprime(funcionNueva(5));
FIN