int main()
{
   int a;
   a=3;
   f(&a);
   //qui a vale 7
}
void f(int *a)
{
   /***********************************************
     qui a non vale 3 perchè a è di tipo puntatore 
     a intero, cioè una variabile che può contenere 
     l'indirizzo di un'altra variabile; 
     in questo caso l'indirizzo di a (del main)
    **********************************************/
   *a = *a + 4;   
   return;
}
