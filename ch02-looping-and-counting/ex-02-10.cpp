/*
Explain each of the uses of std:: in the following program:

Ans:
int main() {
    int k = 0;
    while (k != n) {

        using std::cout; 
        // singals that cout is to be located in the std namespace for this block



        
        cout << "*";
        ++k;
    }

    std::cout << std::endl;
    // std identifies the namespace of these functions.
    // Required here on std::endl, obviously.
    // Required on std::cout since using std::cout was evaluated in a separate block



    return 0;
}
*/
