class Implemetation;

class Interface
{
public:
	Interface(int);
	void setValue(int);
	int getValue() const;
	~Interface();

private:
	Implemetation *ptr;
};
