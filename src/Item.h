
#ifndef ITEM_H
#define ITEM_H

class Item
{
    public:
        Item();
        virtual ~Item();
        virtual void PickUp() const = 0;
    protected:

    private:
};


#endif // ITEM_H
