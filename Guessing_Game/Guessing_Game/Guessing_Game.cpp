#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>

void save_score(int guess_count)
{
    std::ifstream input("best_score.txt");
    if (!input.is_open())
    {
        std::cout << "Unable to read file\n";
        return;
    }
    int best_score;
    input >> best_score;

    std::ofstream output("best_score.txt");
    if (!output.is_open())
    {
        std::cout << "Unable to read file\n";
        return;
    }
    if (guess_count < best_score)
    {
        output << guess_count;
    }
    else
    {
        output << best_score;
    }
}
void print_vector(std::vector<int> vector)
{
    for (int i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i] << "\t";
    }
    std::cout << "\n"; 
}
void play_game() 
{
    std::vector<int> guesses;

    int random = rand() % 251;
    std::cout << random << std::endl; 
    std::cout << "Guess a Number: ";
    while (true) 
    {
        int guess;
        std::cin >> guess;
        guesses.size();

        guesses.push_back(guess);

        if (guess == random) 
        {
            std::cout << "You Win!\n";
            break;
        }
        else if (guess < random) 
        {
            std::cout << "Too low\n";
        }
        else 
        {
            std::cout << "Too high\n";
        }
    }
    save_score(guesses.size());
    print_vector(guesses);

}
int main()
{
    srand(time(NULL));
    int choice;

    do 
    {
        std::cout << "0. Quit\n1.Play Game\n";
        std::cin >> choice;

        switch (choice)
        {
        case 0:
            std::cout << "Thanks for Playing!\n";
            return 0;;
        case 1:
            play_game();
            break;
        }
    } 
    while (choice != 0);

    
}


