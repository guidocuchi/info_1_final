void mostrarInt(void *dato)
{
    printf("%d\n", *(int *)dato);
}


void mostrarFloat(void *dato)
{
    printf("%.2f\n",*(float *)dato);
}


void mostrarDouble(void *dato)
{
    printf("%lf\n", *(double *)dato);
}


void mostrarChar(void *dato)
{
    printf("%c\n",*(char *)dato);
}


void mostrarString(void *dato)
{
    printf("%s\n",(char *)dato); // No se usa * ya que es un puntero.
}

// Implementar en un futuro para imprimir estructuras.