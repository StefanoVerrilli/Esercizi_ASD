#include <iostream>
#include <fstream>
#include <vector>
#include "Utils.hpp"
using namespace std;


class resolver{
  private:
    string Problem;
    string Solution;
    bool Checkforsymbols(string _Solution_line,string _Problem_line);
    bool CheckifAllNumbers(string _Solution_line);
    bool CheckifAnswerCorrect(string _Solution_line,string _Problem_line);
  public:
      resolver(string _Problem,string _Solution){
          Problem = _Problem;
          Solution = _Solution;
      }
      void IsCorrect(){
        ifstream S_Problem(Problem);
        ifstream S_Solution(Solution);
        ofstream S_Answer("Answer.txt");
        string Solution_line;
        string Problem_line;
        getline(S_Solution,Solution_line);
        getline(S_Problem,Problem_line);
        while(!S_Solution.eof()){
          /* Questa funzione utilizza le funzioni private e restituisce esito positivo solo 
          nel caso siano tutte corrette, poi scrive il risultato su file*/
          if(Checkforsymbols(Solution_line,Problem_line) && CheckifAllNumbers(Solution_line) && CheckifAnswerCorrect(Solution_line,Problem_line))
              S_Answer << "Correct" << "\n";
          else
              S_Answer << "Not Correct"<<"\n";
          getline(S_Solution,Solution_line);
          getline(S_Problem,Problem_line);
        }
        S_Answer.close();
        S_Solution.close();
        S_Problem.close();
      }

      };

      /* Questa funzione controlla che i simboli di maggiore e minore tra la soluzione
      *  ed il problema siano gli stessi ritornando falso in caso contrario
      */
      bool resolver::Checkforsymbols(string _Solution_line,string _Problem_line){
        string save_for_solution;
        for(int i=0;i<_Solution_line.length();i++){
            if(_Solution_line.at(i)== '>' || _Solution_line.at(i)=='<')
              save_for_solution+=_Solution_line.at(i);
            }
          if (_Problem_line != save_for_solution)
            return false;
          return true;
      }
      /* Quessta funzione effettua vari controlli sui numeri inseriti nella soluzione:
      - Controlla che il massimo numero nella soluzione sia uguale al numero di elementi presenti.
        viene infatti richiesto di controllare che il massimo numero presente sia il numero di numeri
        contenuti nel file di soluzione
      - Controlla se l' insieme dei numeri presenti nella soluzione è effettivamente una permutazione
        dell' insieme di numero che va da 1..N, in caso contrario ritorna falso */
      bool resolver::CheckifAllNumbers(string _Solution_line){
        int i=0,read=0,element;

        vector<int> vec,vec2;
        size_t sz;
        /* Estrapolazione dei Numeri contenuti all' interno del file soluzione ed inseriemento di
        questi ultimi in un vettore */
        while(read<_Solution_line.length()){
            element = (stoi(_Solution_line.substr(read),&sz,10));
            vec.push_back(element);
            read+=sz+1;
        }
        /* Creazione del vettore contente la sequenza di numeri da 1...N basandosi sulla
        lunghezza del vettore contente i numeri estratti dal file soluzione */
        for(i=1;i<vec.size()+1;i++){
          vec2.push_back(i);
        }

        if(!CheckIfPermutation(vec,vec2))
            return false;
        
        if(max_element(vec) != vec.size())
            return false;

            return true;
      }

      /* Questa funzione controlla le relazioni esistenti tra 2 elementi numerici all' interno del
      file di soluzione (es.3>2) andando a ritornare falso nel caso in cui anche solo una di queste
      non sia rispettata.*/
      bool resolver::CheckifAnswerCorrect(string _Solution_line,string _Problem_line){
            int i=0,val1,val2,read=0;
            size_t sz;
            val1 = stoi(_Solution_line.substr(read),&sz,10);
            /* Utilizzando la chiamata stoi() che restituisce in sz un puntatore al numero di
            caratteri letti possiamo utilizzare una variabile per tenere conto di tutti i numeri
            già letti e creare sottostringhe spiazzate di questa quantità più un carattere per
            far puntare al prossimo elemento numerico.
            Es. Leggo 10 => sz=2 => read+=2 = <||>, +1 = Prossimo elemento numerico => ripeti */
            while(i<_Problem_line.length()){
              read+=sz+1;
              val2 = stoi(_Solution_line.substr(read),&sz,10);
              if(_Problem_line.at(i) == '>' && val1 > val2){
                val1 = val2;
                i++;
                continue;}
              if(_Problem_line.at(i) == '<' && val1<val2){
                val1 = val2;
                i++;
                continue;
              }
              return false;
            }

           return true;
      }