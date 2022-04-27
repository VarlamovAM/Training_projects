#include <iostream>
#include <vector>
#include <competition_tree.h>

using namespace std;

int main(int argc, char* argv[])
{

    int number_of_players;
    if (argc < 2){
        number_of_players = 5;
    } else {
        number_of_players = atoi(argv[1]);
    }

    vector<int> first_team;
    vector<int> second_team;


    for (int i = 0; i < number_of_players; i++){
        first_team.push_back(number_of_players - i);
        second_team.push_back(number_of_players - i);
        //second_team.push_back(i + 1);
    }

    competition_tree MyTree = competition_tree(first_team,
                                               second_team);

    MyTree.build_tree();
    MyTree.print_tree_data();

    return 0;
}
