func numero uno(numero a)
  var numero b;
realiza
  SI (a IGUAL 0) REALIZA
    a = 0;
  SINO
    a = uno(a-1,3);
  FIN
  regresa(a);
fin

programa viko;
REALIZA
  imprime(uno(5));
FIN