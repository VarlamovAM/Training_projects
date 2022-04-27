#include "node.h"
#include <iostream>

node::node()
{
    //ctor
}

node::node(int ft_player, int st_player)
{
    f_team_player = ft_player;
    s_team_player = st_player;
}

node::~node()
{
    //dtor
}

void node::build_doughter_nodes()
{
    if (this->mother_node == nullptr){
        if (s_team_player > 1){
            right_node = new node(f_team_player, s_team_player - 1);
            right_node->mother_node = this;
            right_node->build_doughter_nodes();
        }
        if (f_team_player > 1){
            left_node = new node(f_team_player - 1, s_team_player);
            left_node->mother_node = this;
            left_node->build_doughter_nodes();
        }
    } else {
        if (s_team_player > 1){
            right_node = new node(f_team_player, s_team_player - 1);
            if ((this->mother_node->left_node) == this){
                this->mother_node->right_node->left_node = this->right_node;
                //this->mother_node->right_node->left_node->mother_node =
                  //                              this->mother_node->right_node;
            }
            right_node->build_doughter_nodes();
        }
        if (f_team_player > 1 && left_node == nullptr){
            left_node = new node(f_team_player - 1, s_team_player);
            left_node->mother_node = this;
            left_node->build_doughter_nodes();
        }
    }
    /*if (f_team_player > 1){
        if (this->mother_node == nullptr){
            left_node = new node(f_team_player - 1, s_team_player);
            left_node->mother_node = this;
            left_node->build_doughter_nodes();
        } else {
            left_node = (((this->mother_node)->left_node)->right_node);
        }
        //left_node->build_doughter_nodes();
    }
    if (s_team_player > 1){
        right_node = new node(f_team_player, s_team_player - 1);
        right_node->build_doughter_nodes();
    }*/
}
