#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <set>

using namespace std;

#define SHOW_VAR(var) cout << #var" = " << var << endl

class Item_base
{
  public:
    Item_base(const string &book = "", double sales_price = 0.0)
        : isbn(book), price(sales_price) {cout << book << " - " << sales_price << endl;}
    string book() const {return isbn;}
    virtual ~Item_base() {}

    virtual Item_base *clone() const
        {return new Item_base(*this);}
    virtual double net_price(size_t n) const
        {return n * price;}

  protected:
    double price;

  private:
    string isbn;
};

class Disc_item : public Item_base
{
  public:
    Disc_item(const string &book = "", const double sales_price = 0.0,
              const int mq = 0, const double disc_rate = 0.0)
        : Item_base(book, sales_price), quantity(mq), discount(disc_rate) {}
    double net_price(size_t n) const = 0;

  protected:
    size_t quantity;
    double discount;
};

class Bulk_item : public Disc_item
{
  public:
    Bulk_item(const string &book = "", const double sales_price = 0.0,
              const int mq = 0, const double disc_rate = 0.0)
        : Disc_item(book, sales_price, mq, disc_rate) {}

    virtual Bulk_item *clone() const
        {return new Bulk_item(*this);}

    double net_price(size_t n) const
        {return n >= quantity ? n *(1 - discount) * price
                              : n * price;}

    using Item_base::book;
    string book(int) const {return "isbn";}
};

class Sales_item
{
  public:
    Sales_item(): p(NULL), use(new size_t(1)) {}
    Sales_item(const Item_base &item)
        : p(item.clone()), use(new size_t(1)) {}
    Sales_item(const Sales_item &i)
        : p(i.p), use(i.use) {++*use;}
    ~Sales_item() {decr_use();}

    Sales_item &operator=(const Sales_item &rhs)
    {
        ++*rhs.use;
        decr_use();
        p = rhs.p;
        use = rhs.use;
        return *this;
    }
    const Item_base *operator->() const
    {
        if (p)
            return p;
        else
            throw logic_error("unbound Sales_item");
    }
    const Item_base &operator*() const
    {
        if (p)
            return *p;
        else
            throw logic_error("unbound Sales_item");
    }

  private:
    Item_base *p;
    size_t *use;

    void decr_use()
    {
        if (--*use == 0)
        {
            delete p;
            delete use;
        }
    }
};

inline bool compare(const Sales_item &lhs, const Sales_item &rhs)
    {return lhs->book() < rhs->book();}

class Basket
{
    typedef bool (*Comp)(const Sales_item &, const Sales_item &);
  public:
    typedef multiset<Sales_item, Comp> set_type;
    typedef set_type::size_type size_type;
    typedef set_type::const_iterator const_iter;
    Basket(): items(compare) {}

    void add_item(const Sales_item &item)
        {items.insert(item);}
    size_type size(const Sales_item &i) const
        {return items.count(i);}
    double totle() const;

  private:
    multiset<Sales_item, Comp> items;
};

double Basket::totle() const
{
    double sum = 0.0;

    for (const_iter iter = items.begin(); iter != items.end(); ++iter)
        sum += (*iter)->net_price(items.count(*iter));

    return sum;
}

int main()
{
    Item_base ib("lx", 55);
    Item_base *p = &ib;
    SHOW_VAR(sizeof(Item_base));
    SHOW_VAR(sizeof(*p));
    SHOW_VAR(p->book());
    SHOW_VAR(p->net_price(5));
    Bulk_item bi("xjj", 35, 3, 0.7);
    p = &bi;
    SHOW_VAR(sizeof(Bulk_item));
    SHOW_VAR(sizeof(*p));
    SHOW_VAR(p->book());
    SHOW_VAR(p->net_price(5));
    SHOW_VAR(bi.book());
    SHOW_VAR(bi.book(1));

    Sales_item si1(ib);
    Sales_item si2(bi);
    SHOW_VAR((*si1).book());
    SHOW_VAR(si2->book());

    return EXIT_SUCCESS;
}
