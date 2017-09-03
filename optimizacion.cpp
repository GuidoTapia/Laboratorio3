#include <iostream>

using namespace std;

int equipoA(int x){
    if (x==0){
        return 3;
    }
    else if(x==1){
        return -2;
    }
    else{
        return -1;
    }
}
int equipoB(int x){
    if (x==0){
        return 0;
    }
    else if(x==1){
        return 1;
    }
    else{
        return 2;
    }
}
void imprimirR(string arr[],int x, int i){
    if (x==0){
        cout<<arr[i]<<" le gana a "<<arr[i+1]<<endl;
    }
    else if (x==1){
        cout<<arr[i]<<" y "<<arr[i+1]<<" empatan"<<endl;
    }
    else{
        cout<<arr[i+1]<<" le gana a "<<arr[i]<<endl;
    }
}
int main()
{
    int puntos[]={25,36,21,24,23,10,21,20,23,7};
    int auxiliar[]={0,1,2,3,4,5,6,7,8,9};
    int maximo= 0;
    int imaximo= 0;
    int orden[]={0,1,2,3,4,5,6,7,8,9};
    bool flag=false;
    int contador=0;
    string paises[]={"Colombia","Brasil","Paraguay","Uruguay","Chile","Bolivia","Peru","Ecuador","Argentina","Venezuela"};
    for(int a=0;a<3;a++){
        puntos[0]+=equipoA(a);
        puntos[1]+=equipoB(a);
        for(int b=0;b<3;b++){
            puntos[2]+=equipoA(b);
            puntos[3]+=equipoB(b);
            for(int c=0;c<3;c++){
                puntos[4]+=equipoA(c);
                puntos[5]+=equipoB(c);
                for(int d=0;d<3;d++){
                    puntos[6]+=equipoA(d);
                    puntos[7]+=equipoB(d);
                    for(int e=0;e<3;e++){
                        puntos[8]+=equipoA(e);
                        puntos[9]+=equipoB(e);
                        for (int i=0;i<10;i++){
                            auxiliar[i]=puntos[i];
                        }
                        flag=false;
                        for(int i=0;i<10;i++){
                            imaximo=0;
                            maximo=auxiliar[0];
                            for(int j=1;j<10;j++){
                                if(auxiliar[j]>=maximo){
                                    maximo=auxiliar[j];
                                    imaximo=j;
                                }
                            }
                            orden[i]=imaximo;
                            auxiliar[imaximo]=0;
                            if (imaximo==6){
                                if (i<5){
                                    flag = true;
                                }
                                else if(i==5 && puntos[7]==puntos[orden[4]]){
                                    flag=true;
                                }
                            }
                        }
                        if (flag==true){
                            imprimirR(paises,a,0);
                            imprimirR(paises,b,2);
                            imprimirR(paises,c,4);
                            imprimirR(paises,d,6);
                            imprimirR(paises,e,8);
                            for(int i=0;i<10;i++){
                                cout<<i+1<<")  "<< paises[orden[i]] <<"\t"<< puntos[orden[i]]<<endl;
                            }
                            contador++;
                        }
                    }
                    puntos[9]-=3;
                }
                puntos[7]-=3;
            }
            puntos[5]-=3;
        }
        puntos[3]-=3;
    }
    cout<<"Hay "<< contador <<" posibles resultados en los que Peru puede clasificar al mundial 2018\n";
    cout<< "Es " <<((float)contador/243)*100 << "% probable que Peru clasifique al mundial"<<endl;
    return 0;
}
