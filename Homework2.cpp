#include<iostream>
#include <list>
using namespace std;

/*
****
MERT AKTAŞ
171001037
****
*/

  class Graf
  {
      int dugum;


      list<int> *komsuluk;

      // DFS algoritması sınıfı
      void DepthFirstSearch(int v, bool ziyaret[]);
  public:
      Graf(int dugum);   // parametreli yapıcı fonksiyon tanımı
      ~Graf();       // parametresiz yapıcı fonksiyon tanımı

      void ekle(int v, int w);

      /* yönsüz Grafaki alt bileşenleri ve componentleri tespit eden fonksiyon */
      void AltBilesen();
  };


  void Graf::AltBilesen()
  {
      int i=1;
      // Tüm sınıfları ziyaret edilmemiş işaretliyoruz

      bool *ziyaret = new bool[dugum];
      for(int v = 0; v < dugum; v++)
          ziyaret[v] = false;

      for (int v=0; v<dugum; v++)
      {
          if (ziyaret[v] == false)
          {
              // v'den erişilebilen tüm dügümleri yazdırıyoruz

              cout<<"  "<<i<<"\t \t";
              i++;
              DepthFirstSearch(v, ziyaret);

              cout << "\n \n";

          }
      }
      delete[] ziyaret;
  }

  void Graf::DepthFirstSearch(int v, bool ziyaret[])
  {
      // dugumu ziyaret edildi olarak işaretleyip ekrana yazdırıyoruz
      ziyaret[v] = true;
      cout << v << ",";

      // Bu dügüme bitisik Tüm dügümler icin yineliyorum
      list<int>::iterator i;
      for(i = komsuluk[v].begin(); i != komsuluk[v].end(); ++i)
          if(!ziyaret[*i])
              DepthFirstSearch(*i, ziyaret);
  }

  Graf::Graf(int dugum)
  {
      this->dugum = dugum;
      komsuluk = new list<int>[dugum];
  }

  Graf::~Graf()
  {
      delete[] komsuluk;
  }

  // yönsüz grafta düğüm köprüsü eklemek
  void Graf::ekle(int v, int w)
  {
      komsuluk[v].push_back(w);
      komsuluk[w].push_back(v);
  }


  int main() {

      /* ------ GRAF ------

       Alt Bilesen    Dugumler

        1             0,1,4,2,10,11,8,13,18,

        2             3,9,12,6,15,19,

        3             5,14,7,16,17,


       */

      int array[20][20] = {

          {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 4, 0, 4, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2},
          {0, 2, 4, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0},

          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 5,},
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0,},
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 1, 0, 0, 0, 0, 0,},
          {0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,},
          {0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0,},

          {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 2, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 4, 0, 0, 0, 0, 0, 5, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 3, 5, 0, 0},

          {0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
          {0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 3, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 3, 0, 0, 0},
          {0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 2, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},

           };

           Graf g(20);

          list<int> visted;
          list<int> visted1;

          /* tüm satırları tarayarak kesişenleri ayırdığımız fonksiyon
            ÖRNEK : 0. satır 1. sütun ve 1. satır 0. sütun aynı köprüyü ifade ettiğinden
            bu köprüyü bir kere almak istiyoruz. Bu yüzden ziyaret edilen ve edilmeyen olmak
            üzere 2 listeyi iterator ile dolduruyor ve kullanıyoruz.
          i= i
		  j= sütun
          */
          for(int i=0;i<20;i++)
          {
              for(int j=0;j<20;j++)
              {
                  if((array[i][j]==1)&&(array[j][i]==1))
                  {

                      bool t = false;
                      list <int> :: iterator it;
                      list <int> :: iterator it1;
                      for(it = visted.begin(), it1 =visted1.begin(); it != visted.end(); ++it,++it1)
                      {
                          if(i == *it1 && j == *it){
                              t = true;
                              break;
                          }
                      }
                      if(!t){
                            /* ekle(1,4)
                          list(4,1)*/
                          visted.push_back(i);
                          visted1.push_back(j);
                          g.ekle(i, j);
                      }


                  }
              }
          }

          cout<<" Alt Bilesen \t"<<"Dugumler \n \n";
      g.AltBilesen(); // bu fonksiyonu calistirarak tüm grafın alt bilesenlerini ve dugumlerini ekrana bastiriyoruz.
      return 0;
  }
