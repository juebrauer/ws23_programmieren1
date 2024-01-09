#include <iostream>

class hke_vector
{
    private:
        int* ptr_data;
        int counter;

    public:

        hke_vector() {
            std::cout << "Konstruktor für hke_vector wird aufgerufen!\n";
            ptr_data = nullptr;
            counter = 0;
        }

        ~hke_vector() {
            std::cout << "Reservierter Speicher für den hke_vector wird wieder freigegeben!\n";
            free(ptr_data);

        }

        void push_back(int number) {
            // Gibt es das Array schon?
            if (nullptr==ptr_data) {
                // Das Array gibt es noch nicht! Lege es an! ...
                ptr_data = (int*) malloc(1 * sizeof(int));

                // ... und merke dir, dass wir ein 1. Element haben        
                counter = 1;
                //ptr_data = number;
            } else {
                // Das Array gibt es schon!
                counter++;

                // Mache das Array um ein Element größer
                ptr_data = (int*) realloc(ptr_data, counter * sizeof(int));               
            }

            // Speichere die nächste Zahl
            ptr_data[counter-1] = number;
        }

        void print() {

            for (int i=0; i<counter; i++)
            {
                std::cout << ptr_data[i] << " ";
            }
            std::cout << "\n";
        }

        int at(int index)
        {
            if ((index>=0) && (index<counter))
                return ptr_data[index];
            else {
                std::cout << "index sollte im Range [0," << counter-1 << "] sein!\n";
                return 0;
            }
        }

        void erase(int index)
        {
            if ((index>=0) && (index<counter))
            {
                // 1. Verschieben der Elemente
                for (int i=index; i<counter-1; i++) {
                    std::cout << "verschiebe "; 
                    ptr_data[i] = ptr_data[i+1];
                }

                // 2. Das Array um ein Element kleiner machen
                counter--;
                ptr_data = (int*) realloc(ptr_data, counter * sizeof(int)); 
            }
        }        
    
};

hke_vector* v;

int main()
{    
    v = new hke_vector();
    v->push_back(12);
    v->push_back(14);
    v->push_back(-7);
    v->push_back(37);
    v->push_back(39);
    v->push_back(42);

    //  0  1  2  3  4 
    // 12 14 37 39 42 

    v->print();

    std::cout << "Element bei Index 3: " << v->at(3) << "\n";

    v->erase(5);

    v->print();

    delete v;


}