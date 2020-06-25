#ifndef CSET_H
#define CSET_H

class cset {
private:
	char* elements;
	int count;
public:
	cset() : count(0), elements(nullptr) { }
	cset(const cset&);
	~cset();
	inline bool empty() const { return count == 0; }
	inline char getChar(int position) const { return elements[position]; }
	inline int size() const { return count; }
	void push(const char);
	void print(const char*);
	void input(int size);
	bool subchar(const char);
	bool isEqual(const cset&);

	cset& operator+=(const char);
	cset& operator+=(const cset&);
	cset& operator=(const cset&);
	bool operator==(const cset&);
	friend cset operator+(const char, const cset&);
	friend cset operator+(const cset&, const cset&);
};

#endif // !CSET