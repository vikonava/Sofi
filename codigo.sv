func numero fibonacci(numero a)
realiza
  SI (a IGUAL 0) REALIZA
    a = 0;
  FIN
  SI (a IGUAL 1) REALIZA
    a = 1;
  FIN
  SI (a MAYOR 1) REALIZA
    a = fibonacci(a-1)+fibonacci(a-2);
  FIN
  regresa(a);
fin

programa viko;
  var numero i;
REALIZA
  para (i = 10; i mayor 0; i = i - 1;) REALIZA
    imprime(fibonacci(i));
  FIN
FIN