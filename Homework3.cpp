#include<iostream>
#include<math.h>
#include<conio.h>
#include<vector>
#include<locale.h>
using namespace std;
std::vector<int> DereceDizisi;

/*

|--------------------------------|
|        MERT AKTAŞ              |
|        171001037               |
|        N.Ö                     |
|--------------------------------|

*/


int determinantBulma( int komsulukMatrisi[4][4], int n) {
   int determ = 0;
   int altMatris[4][4];
   if (n == 2)
   return ((komsulukMatrisi[0][0] * komsulukMatrisi[1][1]) - (komsulukMatrisi[1][0] * komsulukMatrisi[0][1]));
   else {
      for (int x = 0; x < n; x++) {
         int alt_i = 0;
         for (int i = 1; i < n; i++) {
            int alt_j = 0;
            for (int j = 0; j < n; j++) {
               if (j == x)
               continue;
               altMatris[alt_i][alt_j] = komsulukMatrisi[i][j];
               alt_j++;
            }
            alt_i++;
         }
         determ = determ + (pow(-1, x) * komsulukMatrisi[0][x] * determinantBulma( altMatris, n - 1 ));
      }
   }
   return determ;
}


int MatrisDerecesi(int komsulukMatrisi[5][5])
{
    int temp=0;

        for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
                if(komsulukMatrisi[i][j]==1)
            {
                    temp=temp+1;

            }

        }

          DereceDizisi.push_back(temp);
          temp=0;
        }
        /*
        for(int i=0;i<5;i++){
            cout<<i<<". satir "<<DereceDizisi[i]<<"\n";
        }
        */
        return 0;
};


int KofaktorBulma(int array[5][5])
{       int temp=0;
        int temp2=0;
        int temp_arr[4][4];
        for(int i=0;i<5;i++){

            if(temp2<DereceDizisi[i])

                temp=i;
                temp2=DereceDizisi[i];
        }

        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){



                 if( (i==temp)){

                   temp_arr[i][j]=array[i+1][j];


                   }
                else if(j==temp)
                {
                    temp_arr[i][j]=array[i][j+1];

                }

                else
                {
                 temp_arr[i][j]=array[i][j];
                }

            }


        }
        temp_arr[3][3]=array[4][4];

/*
cout<<"TEMP:"<<temp<<"\n";

        cout<<"\n 4x4 MATRİS:\n" ;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                cout<<temp_arr[i][j]<<"\n";
            }
            cout<<"------"<<"\n";
        }
*/
        cout<<"Yayilim Agaci Sayisi: "<<determinantBulma(temp_arr,4);
        return 0;
}


int cMatrisiOlusturma(int komsulukMatrisi[5][5])
{
    int array[5][5];

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(i==j)
            {
                array[i][j] =DereceDizisi[i];
            }
            else
            {
             int x=komsulukMatrisi[i][j]*-1;
             array[i][j]=x;
            }
        }
    }
    KofaktorBulma(array);
    return 0;
}




int main()
{
    setlocale(LC_ALL, "Turkish");

    int komsulukMatrisi[5][5]= {
                        {0, 0, 0, 1, 1},
                        {0, 0, 0, 1, 0},
                        {0, 0, 0, 1, 1},
                        {1, 1, 1, 0, 0},
                        {1, 0, 1, 0, 0}

                        };

    int i, j;

    MatrisDerecesi(komsulukMatrisi);
    cMatrisiOlusturma(komsulukMatrisi);

    return 0;
}
