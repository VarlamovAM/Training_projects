#ifndef COMPETITION_TREE_H
#define COMPETITION_TREE_H
#include <vector>
#include <node.h>


class competition_tree
{
    public:
        /** Default constructor */
        competition_tree();
        /** Custom constructor */
        competition_tree(std::vector<int>,
                         std::vector<int>);
        /** Default destructor */
        virtual ~competition_tree();

        /** Method, which is used to print tree */
        void print_tree_data();

        /** Method, which is used to build all probability tree */
        void build_tree();

    protected:

    private:
        node root_node;
        unsigned int depth = 1;
};

#endif // COMPETITION_TREE_H
