#include <iostream>
#include <iomanip>

template<class T>
class hke_vector
{
    private:
        T* ptr_data;
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

        void push_back(T el) {
            // Gibt es das Array schon?
            if (nullptr==ptr_data) {
                // Das Array gibt es noch nicht! Lege es an! ...
                ptr_data = (T*) malloc(1 * sizeof(T));

                // ... und merke dir, dass wir ein 1. Element haben        
                counter = 1;
                //ptr_data = number;
            } else {
                // Das Array gibt es schon!
                counter++;

                // Mache das Array um ein Element größer
                ptr_data = (T*) realloc(ptr_data, counter * sizeof(T));               
            }

            // Speichere die nächste Zahl
            ptr_data[counter-1] = el;
        }

        void print() {

            for (int i=0; i<counter; i++)
            {
                std::cout << ptr_data[i] << " ";
            }
            std::cout << "\n";
        }

        T at(int index)
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
                ptr_data = (T*) realloc(ptr_data, counter * sizeof(T)); 
            }
        }        
    
};



int main()
{    
    hke_vector<float> v;
    v.push_back(12.4f);
    v.push_back(14.434f);
    v.push_back(-7.4f);
    v.push_back(37.30123456f);
    v.push_back(39.3f);
    v.push_back(42.84f);


    v.print();

    std::cout << std::fixed << std::setprecision(8) <<
                 "Element bei Index 3: " << v.at(3) << "\n";

    std::cout << std::fixed << std::setprecision(2);

    v.erase(3);

    v.print();
    
}