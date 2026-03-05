#include <cstdlib>
#include <ctime>

extern "C" {

int play(int userChoice) {

    static bool seeded = false;
    if(!seeded){
        srand(time(0));
        seeded = true;
    }

    int computer = rand() % 3;

    int result;

    // 0 = draw
    // 1 = user win
    // -1 = user lose

    if(userChoice == computer)
        result = 0;
    else if(
        (userChoice == 0 && computer == 2) ||
        (userChoice == 1 && computer == 0) ||
        (userChoice == 2 && computer == 1)
    )
        result = 1;
    else
        result = -1;

    // Encode result and computer choice together
    // computerChoice * 10 + result

    return computer * 10 + (result + 1);
}

}