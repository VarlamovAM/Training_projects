#ifndef NODE_H
#define NODE_H


class node
{
    public:
        /** Default constructor */
        node();
        /** Custom constructor */
        node(int, int);
        /** Default destructor */
        virtual ~node();

        void build_doughter_nodes();


        int f_team_player; //!< Member variable "f_com_player"
        int s_team_player; //!< Member variable "s_com_player"
        double prob_to_win; //!< Member variable "prob_to_win"
        node* left_node = nullptr; //!< Member variable "left_node"
        node* right_node = nullptr; //!< Member variable "right_node"
        node* mother_node = nullptr; //!< Member variable "mother_node"

    protected:

    private:

};

#endif // NODE_H
