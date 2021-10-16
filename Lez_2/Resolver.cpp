#include <iostream>
#include <fstream>
#include <vector>
#include "Utils.hpp"
using namespace std;


class resolver{
  private:
    string Problem;
    string Solution;
    bool checkIfSymbolsAreCorrect(string _Solution_line,string _Problem_line);
    bool checkIfAllNumbersAreUsed(string _Solution_line);
    bool checkLogic(string _Solution_line,string _Problem_line);
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
        while(getline(S_Solution,Solution_line) && getline(S_Problem,Problem_line)){
          /* Questa funzione utilizza le funzioni private e restituisce esito positivo solo 
          nel caso siano tutte corrette, poi scrive il risultato su file*/
          if(checkIfSymbolsAreCorrect(Solution_line,Problem_line) && checkIfAllNumbersAreUsed(Solution_line) && checkLogic(Solution_line,Problem_line))
              S_Answer << "Correct" << "\n";
          else
              S_Answer << "Not Correct"<<"\n";
        }
        S_Answer.close();
        S_Solution.close();
        S_Problem.close();
      }

      };

      /* Questa funzione controlla che i simboli di maggiore e minore tra la soluzione
      *  ed il problema siano gli stessi ritornando falso in caso contrario
      */
      bool resolver::checkIfSymbolsAreCorrect(string _Solution_line,string _Problem_line){
        string save_for_solution;
        for(int i=0;i<_Solution_line.length();i++){
            if(_Solution_line.at(i)== '>' || _Solution_line.at(i)=='<')
              save_for_solution+=_Solution_line.at(i);
            }
          if (_Problem_line != save_for_solution)
            return false;
          return true;
      }
      /* Questa funzione effettua vari controlli sui numeri inseriti nella soluzione:
      - Controlla che il massimo numero nella soluzione sia uguale al numero di elementi presenti.
        viene infatti richiesto di controllare che il massimo numero presente sia il numero di numeri
        contenuti nel file di soluzione
      - Controlla se l' insieme dei numeri presenti nella soluzione è effettivamente una permutazione
        dell' insieme di numero che va da 1..N, in caso contrario ritorna falso */
      bool resolver::checkIfAllNumbersAreUsed(string _Solution_line){
        int i=0,read=0,element;
        vector<int> Permutation_vector,One_to_N;
        size_t sz;
        /* Estrapolazione dei Numeri contenuti all' interno del file soluzione ed inseriemento di
        questi ultimi in un vettore */
        while(read<_Solution_line.length()){
            element = (stoi(_Solution_line.substr(read),&sz,10));
            Permutation_vector.push_back(element);
            read+=sz+1;
        }
        /* Creazione del vettore contente la sequenza di numeri da 1...N basandosi sulla
        lunghezza del vettore contente i numeri estratti dal file soluzione */
        for(i=0;i<Permutation_vector.size();i++){
          One_to_N.push_back(i+1);
        }

         if(max_element(Permutation_vector) != Permutation_vector.size())
            return false;

        if(!CheckIfPermutation(Permutation_vector,One_to_N))
            return false;

            return true;
      }

      /* Questa funzione controlla le relazioni esistenti tra 2 elementi numerici all' interno del
      file di soluzione (es.3>2) andando a ritornare falso nel caso in cui anche solo una di queste
      non sia rispettata.*/
      bool resolver::checkLogic(string _Solution_line,string _Problem_line){
            int i=0,val1,val2,read=0;
            size_t sz;
            val1 = stoi(_Solution_line.substr(0),&sz,10);
            /* Utilizzando la chiamata stoi() che restituisce in sz un puntatore al numero di
            caratteri letti possiamo utilizzare una variabile per tenere conto di tutti i numeri
            già letti e creare sottostringhe spiazzate di questa quantità più un carattere per
            far puntare al prossimo elemento numerico.
            Es. Leggo 10 => sz=2 => read+=2 = <||>, +1 = Prossimo elemento numerico => ripeti */
            while(i<_Problem_line.length()){
              read+=sz+1;
              val2 = stoi(_Solution_line.substr(read),&sz,10);
              if((_Problem_line.at(i) == '>' && val1 > val2) || 
                (_Problem_line.at(i) == '<' && val1<val2)){
                val1 = val2;
                i++;
                continue;}
              return false;
            }

           return true;
      }