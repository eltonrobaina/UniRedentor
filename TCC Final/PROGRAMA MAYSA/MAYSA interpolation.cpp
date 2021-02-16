#include <stdio.h>

double linearInterpolation(double x0, double y0, double x1, double y1, double x) {
    return y0 + (y1 - y0) * ((x - x0) / (x1 - x0));
}

void chamaLinearInterpolation(){
    float x, x0, y0, x1, y1, i;
    int z;
    FILE *fp;
    printf("\n\n Gostaria de Registrar resultado para consulta posterior? 1-sim; 2-nao: \n\n ");
    scanf("%d", &z);
    printf("Digite o numero da estaca (x) que deseja encontrar a altura: ");
    scanf("%f", &x);
    printf("Digite o valor de (x0) do Ponto 0: ");
    scanf("%f", &x0);
    printf("Digite o valor de (y0) do Ponto 0: ");
    scanf("%f", &y0);
    printf("Digite o valor (X1) do Ponto 1: ");
    scanf("%f", &x1);
    printf("Digite o valor (Y1) do Ponto 1: ");
    scanf("%f", &y1);
    i = x0;

    while (i <= x1) {
        printf("%.lf -> %.3f\n", i, linearInterpolation(x0, y0, x1, y1, i));
      	if(z == 1){
            fp = fopen ("./Interpolação Linear das estacas.txt","a+");

            fprintf (fp, "%.lf -> %.3f\n", i, linearInterpolation(x0, y0, x1, y1, i));
        }
        fclose(fp);
        i++;
    }
    
    printf("\n");
}


void chamaLagrande(){
	float x[100],y[100],a,s=1,t=1,k=0;
    int n,i,j,d=1;
    printf("\n\n Insira o numero de estacas do perfil longitudinal:  ");
    scanf("%d",&n);
    printf("\n\n Entre com o valor da posicao da estaca em (x) e a altura (y): \n");
    for(i=0; i<n; i++)
    {
        scanf ("%f",&x[i]);
        scanf("%f",&y[i]);
    }
    printf("\n\n Todos os pontos definidos podem ser vistos a baixo: \n\n");
    for(i=0; i<n; i++)
    {
        printf("%0.3f\t%0.3f",x[i],y[i]);
        printf("\n");
    }
    while(d==1)
    {
        printf(" \n\n\n Entre com o valor da estaca (x) que deseja descobrir a altura (y) no intervalo definido anteriormente \n\n\n");
        scanf("%f",&a);
        for(i=0; i<n; i++)
        {
            s=1;
            t=1;
            for(j=0; j<n; j++)
            {
                if(j!=i)
                {
                    s=s*(a-x[j]);
                    t=t*(x[i]-x[j]);
                }
            }
            k=k+((s/t)*y[i]);
        }
        printf("\n\n O valor de altura da estaca (y) e: %f",k);
        printf("\n\n Precione 1 para interpolar os dados novamente, ou qualquer outra tecla para retornar ao menu!\n\n");
        scanf("%d",&d);
    }
    printf("\n");
}
int main() {
    int valor;

	printf("******************************************************************************************************\n");
    printf("******************************************************************************************************\n");
    printf("***************************************** !!!BEM VINDO!!!! *******************************************\n");
    printf("********************************* PROGRAMA INTERPOLADOR CIVIL MAYSA Versao Beta 1.0 ******************\n");
    printf("******************************************************************************************************\n");
    printf("******************************************************************************************************\n");
    printf("by: Elton John Robaina da Silva Matricula: 1504658\n");
    printf("\n");
    printf("ESCOLHA UMA DAS OPCOES\n");
    printf("\n");
    printf(" 1 - Interpolar por Lagrande (*Versao Beta)\n 2 - Interpolar por Sistema Linear\n 3 - Informacoes\n 4 - Sair\n \n");
    scanf("%d", &valor);

    while(valor != 4){
        if (valor == 1) {
	
            printf ("\n 1 - Interpolar por Lagrande\n");
            chamaLagrande();
        }
        else
        if (valor == 2){
		
        	printf ("2 - Interpolar por sistema Linear\n");
           chamaLinearInterpolation();
       }
        else
        if (valor == 3){
		
            printf ("3 - Informacoes \n\n");
            printf("O programa MAYSA foi desenvolvido atraves da parceria do aluno de Engenharia Civil Elton John Robainda a Silva e do programador Igor de Paula apenas para fins didaticos, desta forma esse programa nao pode ser vendido ou comercializado.\n");
            printf("Os modelos matematicos utilizados nesse programa sao amplamente utilizados na area de engenharia para encontrar valores aproximados\n.");
            printf("Os algoritimo utilizados nesse programa foram baseados nas seguintes fontes: \n\n");
            printf("https://www.codewithc.com/c-program-for-lagrange-interpolation \n");
            printf("https://batchloaf.wordpress.com/2013/03/12/2-d-linear-interpolation-in-c \n\n");
        }
        printf ("ESCOLHA UMA DAS OPCOES: \n 1 - Interpolar por Lagrande\n 2 - Interpolar por Sistema Linear\n 3 - Informacoes\n 4 - Sair\n Escolha sua opcao: \n");
        scanf("%d", &valor);
    }


    return 0;
}
