#include "competition_tree.h"
#include <iostream>
#include <vector>

competition_tree::competition_tree()
{
}

competition_tree::competition_tree(std::vector<int> first_team,
                                   std::vector<int> second_team){
    root_node = node(first_team[0], second_team[0]);
}

competition_tree::~competition_tree()
{
}

void competition_tree::print_tree_data()
{
    std::vector<std::vector<node>> layers;
    std::vector<node> first_layer = {root_node};
    layers.push_back(first_layer);

    for (unsigned int i = 0; i < layers.size(); i++){
        std::vector<node> current_layer;
        for (unsigned int j = 0; j < layers[i].size(); j++){
            if (layers[i][j].left_node != nullptr && j == 0){
                current_layer.push_back(*(layers[i][j].left_node));
            }
            if (layers[i][j].right_node != nullptr){
                current_layer.push_back(*(layers[i][j].right_node));
            }
        }
        if (current_layer.size() != 0){
            layers.push_back(current_layer);
            depth++;
        }
    }

    if (depth > 20){
        std::cout
        << "Graph too large to print! You can try decrease size and retry!"
        << std::endl;
        return;
    }

    /*for (unsigned int i = 0; i < layers.size(); i++){
        for (unsigned int j = 0; j < layers[i].size(); j++){
            std::cout << '(' << (layers[i][j]).left_node <<
                           "; " << (layers[i][j]).right_node <<
                           ')';
        }
        std::cout << std::endl;
    }*/
    for (unsigned int i = 0; i < layers.size(); i++){
        for (int k = 0; k < abs(depth/2 - i) + 1; k++){
            std::cout << "   ";
        }
        for (unsigned int j = 0; j < layers[i].size(); j++){
            std::cout << '(' << (layers[i][j]).f_team_player <<
                           "; " << (layers[i][j]).s_team_player <<
                           ')';
        }
        std::cout << std::endl;

        if (root_node.f_team_player == root_node.s_team_player){
                for (int k = 0; k < abs(depth/2 - i) + 1; k++){
                std::cout << "   ";
            }
            if (i < depth/2){
                std::cout << " / ";
                for (unsigned l = 0; l < layers[i].size() - 1; l++){
                    std::cout << " \\  / ";
                }
                std::cout << " \\";
            } else {
                if (i != layers.size() - 1){
                    std::cout << "   " << " \\ ";
                    for (unsigned l = 0; l < layers[i].size() - 2; l++){
                        std::cout << " /  \\ ";
                    }
                    std::cout << " /";
                }
            }
            std::cout << std::endl;
        }
    }
    return;
}

void competition_tree::build_tree()
{
    root_node.build_doughter_nodes();
    return;
}
